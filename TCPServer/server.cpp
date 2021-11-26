#include "server.h"

#include "./ui_server.h"

Server::Server(QWidget* parent) : QMainWindow(parent), ui(new Ui::Server) {
  ui->setupUi(this);

  // 1.创建QTcpServer实例对象，即监听的服务器对象
  m_tcpServer = new QTcpServer(this);

  // 2.启动监听
  connect(ui->startServerBtn, &QPushButton::clicked, this, [=]() {
    // 将输入框中的内容转为短整型
    auto port = ui->portLineEdit->text().toUShort();

    // 绑定本地IP地址并监听客户端连接请求
    m_tcpServer->listen(QHostAddress::Any, port);

    // 开启监听后让按钮失效
    ui->startServerBtn->setDisabled(true);
  });

  // 3.等待客户端连接请求
  // 只有m_tcpSocket被实例化之后，有关m_tcpSocket的connect操作才能正确完成
  // 故要在coonect操作里再写connect操作
  connect(m_tcpServer, &QTcpServer::newConnection, this, [=]() {
    // 4.获取通信套接字对象
    m_tcpSocket = m_tcpServer->nextPendingConnection();

    // 将状态栏图标设置为连接成功状态
    m_statuLabel->setPixmap(QPixmap(":/connected.png").scaled(20, 20));

    // 往通信记录框中添加客户端连接成功信息
    ui->recordTextEdit->append("server connected to client successed...");

    // 5.检测是否可以接收数据
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, [=]() {
      // 获取客户端发送的数据
      auto data = m_tcpSocket->readAll();

      // 显示到通信记录框中
      ui->recordTextEdit->append("receive data from client...");
      ui->recordTextEdit->append("client send: " + data);
    });

    // 6.客户端发送关闭连接请求
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, [=]() {
      // 关闭套接字
      m_tcpSocket->close();

      // 不等到m_tcpServer释放时释放m_tcpSocket，手动释放m_tcpSocket
      // m_tcpSocket->deleteLater();

      // 将状态栏图标设置为连接失败状态
      m_statuLabel->setPixmap(QPixmap(":/disconnected.png").scaled(20, 20));

      // 往通信记录框中添加客户端断开连接信息
      ui->recordTextEdit->append("client has disconnected to server...");
    });
  });

  // 给客户端发送消息
  connect(ui->sendDataBtn, &QPushButton::clicked, this, [=]() {
    // 获取发送消息框的内容
    auto context = ui->messageTextEdit->toPlainText();

    // 发送消息并添加到通信记录框中
    m_tcpSocket->write(context.toUtf8());
    ui->recordTextEdit->append("server send: " + context);
  });

  // 给状态栏添加动作
  // 将label对象设置到状态栏对象中，则状态栏对象就是该label对象的父对象
  // 当状态栏对象析构时会先析构该label对象
  ui->statusbar->addWidget(new QLabel("连接状态:"));

  // 默认未连接状态
  m_statuLabel = new QLabel;
  m_statuLabel->setPixmap(QPixmap(":/disconnected.png").scaled(20, 20));
  ui->statusbar->addWidget(m_statuLabel);
}

Server::~Server() { delete ui; }
