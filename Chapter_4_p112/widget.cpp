#include "widget.h"

#include <QMouseEvent>
#include <QTime>
#include <QTimer>

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QLCDNumber(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  QPalette p = palette();
  p.setColor(QPalette::Window, Qt::blue);
  setPalette(p);
  setWindowFlags(Qt::FramelessWindowHint);
  setWindowOpacity(0.5);
  QTimer *timer = new QTimer(this);
  timer->start(1000);
  showTime();
  // resize(300, 60);
  connect(timer, &QTimer::timeout, this, &Widget::showTime);
}

Widget::~Widget() { delete ui; }

void Widget::showTime() {
  QTime time = QTime::currentTime();
  QString text = time.toString("hh:mm:ss");
  display(text);
}

void Widget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    dragPos = event->globalPos() - frameGeometry().topLeft();
    event->accept();
  }
  if (event->button() == Qt::RightButton) {
    close();
  }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    move(event->globalPos() - dragPos);
    event->accept();
  }
}
