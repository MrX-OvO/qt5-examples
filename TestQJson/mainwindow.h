#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QJsonArray>
#include <QJsonObject>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void writeJson();
  void readJson();

 private:
  void printQJsonArr(const QJsonArray &, unsigned *);
  void printQJsonObj(const QJsonObject &, unsigned *);

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
