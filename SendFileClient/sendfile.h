#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QTcpSocket>

class SendFile : public QObject {
  Q_OBJECT
 public:
  explicit SendFile(QObject *parent = nullptr);

  // 连接服务器任务
  void connToServer(QString ip, unsigned short port);

  // 发送文件任务
  void sendFileToServer(QString filePath);

 signals:
  void connOK();
  void disconnected();
  void curProgressBarPercent(int percent);

 private:
  QTcpSocket *m_tcpSocket;
};

#endif  // SENDFILE_H
