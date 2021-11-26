#ifndef RECIEVEFILE_H
#define RECIEVEFILE_H

#include <QTcpSocket>
#include <QThread>

class RecieveFile : public QThread {
  Q_OBJECT
 public:
  explicit RecieveFile(QObject* parent = nullptr);
  explicit RecieveFile(QTcpSocket* tcpSocket, QObject* parent = nullptr);
  explicit RecieveFile(qintptr socketDescriptor, QObject* parent = nullptr);

 protected:
  void run() override;

 signals:
  void recievedFile();
  void disconnected();

 private:
  QTcpSocket* m_tcpSocket;
};

#endif  // RECIEVEFILE_H
