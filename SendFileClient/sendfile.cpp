#include "sendfile.h"

#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QHostAddress>
#include <QThread>

SendFile::SendFile(QObject *parent) : QObject(parent) {}

void SendFile::connToServer(QString ip, unsigned short port) {
  qDebug() << "建立连接子线程:" << QThread::currentThread();

  // 创建通信套接字
  m_tcpSocket = new QTcpSocket(this);

  // 连接服务器
  m_tcpSocket->connectToHost(QHostAddress(ip), port);

  // 检测是否成功连接服务器
  connect(m_tcpSocket, &QTcpSocket::connected, this, &SendFile::connOK);

  // 检测服务器是否与客户端断开连接
  connect(m_tcpSocket, &QTcpSocket::disconnected, this, [=]() {
    // 关闭套接字
    m_tcpSocket->close();

    // 给主线程发送与服务器断开连接信号
    emit disconnected();
  });
}

void SendFile::sendFileToServer(QString filePath) {
  qDebug() << "发送文件子线程:" << QThread::currentThread();

  // 获取要发送的文件
  QFile file(filePath);

  // 获取要发送的文件大小
  QFileInfo fileInfo(filePath);
  int fileSize = fileInfo.size();

  // 打开并读取文件
  bool isOpen = file.open(QFile::ReadOnly);
  if (isOpen) {
    // 发送数据
    while (!file.atEnd()) {
      //第一次发送时把文件大小一并发送给服务器
      static int times = 0;
      if (times == 0) m_tcpSocket->write((char *)&fileSize, 4);

      // 发送文件内容到服务器
      auto line = file.readLine();
      m_tcpSocket->write(line);

      // 进度条百分比
      times += line.size();
      int percent = times * 100 / fileSize;
      emit curProgressBarPercent(percent);
    }

    // 读完后关闭文件
    file.close();

    qDebug() << "文件发送完毕!!!";
  }
}
