#include "recievefile.h"

#include <QDebug>
#include <QFile>

RecieveFile::RecieveFile(QObject *parent) : QThread(parent) {}

RecieveFile::RecieveFile(QTcpSocket *tcpSocket, QObject *parent)
    : QThread(parent) {
  m_tcpSocket = tcpSocket;
}

RecieveFile::RecieveFile(qintptr socketDescriptor, QObject *parent) {
  m_tcpSocket = new QTcpSocket(this);
  m_tcpSocket->setSocketDescriptor(socketDescriptor);
}

void RecieveFile::run() {
  qDebug() << "接收文件子线程:" << QThread::currentThread();

  // 创建用于写入客户端发送来的文件内容的文件
  auto filePath = QString("recieve.txt");
  QFile *file = new QFile(filePath);

  // 打开文件并写入数据
  auto isOpen = file->open(QFile::WriteOnly);
  if (isOpen) {
    // 接收数据
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, [=]() {
      // 读取第一次传输的数据
      static int times = 0;
      static int fileSize = 0;
      if (times == 0) m_tcpSocket->read((char *)&fileSize, 4);

      // 读取剩余数据，写入文件
      auto data = m_tcpSocket->readAll();
      file->write(data);

      // 判断数据是否接收完毕
      times += data.size();
      if (times == fileSize) {
        // 释放资源
        m_tcpSocket->close();
        m_tcpSocket->deleteLater();
        file->close();
        file->deleteLater();

        emit recievedFile();

        qDebug() << "文件接收完毕!!!";
      }
    });
  }

  // 检测客户端是否断开连接
  connect(m_tcpSocket, &QTcpSocket::disconnected, this,
          &RecieveFile::disconnected);

  // 进入事件循环，防止子线程退出，子线程进入后台
  // 当有子线程中对应的事件触发了，对应的处理动作还是在子线程中处理
  exec();
}
