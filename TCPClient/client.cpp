#include "client.h"

#include <QHostAddress>

#include "./ui_client.h"

Client::Client(QWidget *parent) : QMainWindow(parent), ui(new Ui::Client) {
  ui->setupUi(this);

  // 先将"断开连接"按钮失效
  ui->disconnToServerBtn->setDisabled(true);

  // 1.创建通信套接字对象
  m_tcpSocket = new QTcpSocket(this);

  // 2.连接服务器
  connect(ui->connToServerBtn, &QPushButton::clicked, this, [=]() {
    // 获取服务器IP和端口号
    auto ip = ui->serverIPLineEdit->text();
    auto port = ui->serverPortLineEdit->text().toUShort();

    // 连接服务器
    m_tcpSocket->connectToHost(QHostAddress(ip), port);
  });

  // 3.连接服务器成功
  connect(m_tcpSocket, &QTcpSocket::connected, this, [=]() {
    // 让"连接服务器"按钮失效
    ui->connToServerBtn->setDisabled(true);

    // 让"断开连接"按钮生效
    ui->disconnToServerBtn->setEnabled(true);

    // 将状态栏图标设置为连接成功状态
    m_statuLabel->setPixmap(QPixmap(":/connected.png").scaled(20, 20));

    // 往通信记录框中添加成功连接服务器信息
    ui->recordTextEdit->append("client connect to server successed...");
  });

  // 4.发送数据到服务器
  connect(ui->sendDataBtn, &QPushButton::clicked, this, [=]() {
    // 获取发送消息框的内容
    auto context = ui->messageTextEdit->toPlainText();

    // 发送消息并添加到通信记录框中
    m_tcpSocket->write(context.toUtf8());
    ui->recordTextEdit->append("client send: " + context);
  });

  // 5.检测是否可以接收数据
  connect(m_tcpSocket, &QTcpSocket::readyRead, this, [=]() {
    // 获取服务器端发送的数据
    auto data = m_tcpSocket->readAll();

    // 显示到通信记录框中
    ui->recordTextEdit->append("receive data from server...");
    ui->recordTextEdit->append("server send: " + data);
  });

  // 6.服务器端主动断开连接
  connect(m_tcpSocket, &QTcpSocket::disconnected, this, [=]() {
    // 关闭套接字
    m_tcpSocket->close();

    // 手动释放m_tcpSocket
    // m_tcpSocket->deleteLater();

    // 将状态栏图标设置为连接失败状态
    m_statuLabel->setPixmap(QPixmap(":/disconnected.png").scaled(20, 20));

    // 往通信记录框中添加服务器断开连接信息
    ui->recordTextEdit->append("server has disconnected to client...");
  });

  // 7.客户端主动断开连接
  connect(ui->disconnToServerBtn, &QPushButton::clicked, this, [=]() {
    //关闭套接字
    m_tcpSocket->close();

    // 让"连接服务器"按钮生效
    ui->connToServerBtn->setEnabled(true);

    // 让"断开连接"按钮失效
    ui->disconnToServerBtn->setDisabled(true);

    // 往通信记录框中添加客户端断开连接信息
    ui->recordTextEdit->append("client has disconnected to server...");
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

Client::~Client() { delete ui; }
