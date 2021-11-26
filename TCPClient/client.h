#ifndef CLIENT_H
#define CLIENT_H

#include <QLabel>
#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Client;
}
QT_END_NAMESPACE

class Client : public QMainWindow {
  Q_OBJECT

 public:
  Client(QWidget* parent = nullptr);
  ~Client();

 private:
  Ui::Client* ui;
  QTcpSocket* m_tcpSocket;
  QLabel* m_statuLabel;
};
#endif  // CLIENT_H
