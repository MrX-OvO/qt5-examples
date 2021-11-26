#include "mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QThread>

#include "./ui_mainwindow.h"
#include "sendfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // 打印客户端主线程相关信息
  qDebug() << "客户端主线程:" << QThread::currentThread();

  // 初始化进度条
  ui->progressBar->setRange(0, 100);
  ui->progressBar->setValue(0);

  // 创建线程对象
  QThread *t = new QThread;

  // 创建任务类对象
  SendFile *sendFile = new SendFile;

  // 将任务类对象移动到线程对象中
  sendFile->moveToThread(t);

  // 启动子线程
  t->start();

  // 点击”连接服务器“按钮
  connect(ui->connToServerBtn, &QPushButton::clicked, this, [=]() {
    // 获取服务器IP和端口号
    auto ip = ui->serverIPLineEdit->text();
    auto port = ui->serverPortLineEdit->text().toUShort();
    emit connToServer(ip, port);
  });

  // 点击”选择文件“按钮
  connect(ui->selectFileBtn, &QPushButton::clicked, this, [=]() {
    auto filePath = QFileDialog::getOpenFileName();
    if (filePath.isEmpty()) {
      QMessageBox::warning(this, "打开文件", "所选文件路径为空，请重新选择!!!");
      return;
    }
    ui->filePathLineEdit->setText(filePath);
  });

  // 点击”发送文件“按钮
  connect(ui->sendFileBtn, &QPushButton::clicked, this, [=]() {
    // 获取文件路经
    auto filePath = ui->filePathLineEdit->text();
    emit sendFileToServer(filePath);
  });

  // 让子线程执行连接服务器任务
  connect(this, &MainWindow::connToServer, sendFile, &SendFile::connToServer);

  // 让子线程执行发送文件任务
  connect(this, &MainWindow::sendFileToServer, sendFile,
          &SendFile::sendFileToServer);

  // 处理子线程发送的信号
  connect(sendFile, &SendFile::connOK, this, [=]() {
    qDebug() << "已成功连接到服务器!!!";

    // 设置”连接服务器“按钮不可用
    ui->connToServerBtn->setDisabled(true);

    QMessageBox::information(this, "连接服务器", "恭喜，已成功连接到服务器!!!");
  });
  connect(sendFile, &SendFile::disconnected, this, [=]() {
    qDebug() << "与服务器断开连接!!!";

    // 设置”连接服务器“按钮可用
    ui->connToServerBtn->setEnabled(true);

    // 资源释放
    sendFile->deleteLater();
    t->quit();
    t->wait();
    t->deleteLater();
  });
  connect(sendFile, &SendFile::curProgressBarPercent, ui->progressBar,
          &QProgressBar::setValue);
}

MainWindow::~MainWindow() { delete ui; }
