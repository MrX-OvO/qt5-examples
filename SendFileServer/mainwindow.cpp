#include "mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QTcpSocket>

#include "./ui_mainwindow.h"
#include "mytcpserver.h"
#include "recievefile.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // 打印服务器主线程相关信息
  qDebug() << "服务器主线程:" << QThread::currentThread();

#if 0
  // 创建QTcpServer实例对象，即监听的服务器对象
  m_tcpServer = new QTcpServer(this);

  // 点击”启动服务器“按钮
  connect(ui->startServerBtn, &QPushButton::clicked, this, [=]() {
    // 设置按钮不可用
    ui->startServerBtn->setDisabled(true);

    // 获取服务器端口号
    auto port = ui->serverPorLineEdit->text().toUShort();

    // 设置监听
    bool isListen = m_tcpServer->listen(QHostAddress::Any, port);

    if (isListen) qDebug() << "启动服务器成功!!!";
  });

  // 等待客户端连接请求
  connect(m_tcpServer, &QTcpServer::newConnection, this, [=]() {
    qDebug() << "有新的客户端请求连接";

    // 创建通信套接字对象
    // 在子线程中进行通信
    QTcpSocket* tcpSocket = m_tcpServer->nextPendingConnection();

    // 创建子线程
    // 1.通过传参方式将 QTcpSocket* 传入子线程中
    RecieveFile* recvFile = new RecieveFile(tcpSocket);

    // 2.添加继承QTcpServer的类
    // 在添加的类中重写受保护的虚函数
    // void QTcpServer::incomingConnection(qintptr socketDescriptor)
    // 在该函数中发射通信套接字的文件描述符信号(socketDescriptor)，并让子线程接收
    // 然后在子线程中创建通信套接字并设置通信套接字的文件描述符，即
    // m_tcpSocket = new QTcpSocket(this);
    // m_tcpSocket->setSocketDescriptor(socketDescriptor)
    // 当有新连接时，Qt框架自动调用上方的虚函数

    // 让子线程工作
    recvFile->start();

    // 处理子线程发送的信号
    connect(recvFile, &RecieveFile::recievedFile, this, [=]() {

      // 释放资源
      recvFile->exit();
      recvFile->wait();
      recvFile->deleteLater();

      // 提示文件接收完毕
      QMessageBox::information(this, "文件接收", "文件接收完毕！！！");
    });
    connect(recvFile, &RecieveFile::disconnected, this, [=]() {
      // 设置按钮可用
      ui->startServerBtn->setEnabled(true);

      qDebug() << "客户端与服务器断开连接!!!";
    });
  });
#else
  // 创建QTcpServer实例对象，即监听的服务器对象
  MyTcpServer* myTcpServer = new MyTcpServer(this);

  // 点击”启动服务器“按钮
  connect(ui->startServerBtn, &QPushButton::clicked, this, [=]() {
    // 设置按钮不可用
    ui->startServerBtn->setDisabled(true);

    // 获取服务器端口号
    auto port = ui->serverPorLineEdit->text().toUShort();

    // 设置监听
    bool isListen = myTcpServer->listen(QHostAddress::Any, port);

    if (isListen) qDebug() << "启动服务器成功!!!";
  });

  // 等待客户端连接请求
  connect(myTcpServer, &MyTcpServer::newDescriptor, this,
          [=](qintptr socketDescriptor) {
            qDebug() << "有新的客户端请求连接";

            // 创建通信套接字对象

            // 创建子线程
            // 2.添加继承QTcpServer的类
            // 在添加的类中重写受保护的虚函数
            // void QTcpServer::incomingConnection(qintptr socketDescriptor)
            // 在该函数中发射通信套接字的文件描述符信号(socketDescriptor)，并让子线程接收
            // 然后在子线程中创建通信套接字并设置通信套接字的文件描述符，即
            // m_tcpSocket = new QTcpSocket(this);
            // m_tcpSocket->setSocketDescriptor(socketDescriptor)
            // 当有新连接时，Qt框架自动调用上方的虚函数
            RecieveFile* recvFile = new RecieveFile(socketDescriptor);

            // 让子线程工作
            recvFile->start();

            // 处理子线程发送的信号
            connect(recvFile, &RecieveFile::recievedFile, this, [=]() {
              // 释放资源
              recvFile->exit();
              recvFile->wait();
              recvFile->deleteLater();

              // 提示文件接收完毕
              QMessageBox::information(this, "文件接收", "文件接收完毕！！！");
            });
            connect(recvFile, &RecieveFile::disconnected, this, [=]() {
              // 设置按钮可用
              ui->startServerBtn->setEnabled(true);

              qDebug() << "客户端与服务器断开连接!!!";
            });
          });
#endif
}

MainWindow::~MainWindow() { delete ui; }
