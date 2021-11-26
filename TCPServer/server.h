#ifndef SERVER_H
#define SERVER_H

#include <QLabel>
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Server;
}
QT_END_NAMESPACE

class Server : public QMainWindow {
  Q_OBJECT

 public:
  Server(QWidget *parent = nullptr);
  ~Server();

 private:
  Ui::Server *ui;
  QTcpServer *m_tcpServer;
  QTcpSocket *m_tcpSocket;
  QLabel *m_statuLabel;
};
#endif  // SERVER_H
