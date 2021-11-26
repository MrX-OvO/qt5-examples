#ifndef WIDGET_H
#define WIDGET_H

#include <QLCDNumber>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QLCDNumber {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);

 public slots:
  void showTime();

 private:
  Ui::Widget *ui;
  QPoint dragPos;
};
#endif  // WIDGET_H
