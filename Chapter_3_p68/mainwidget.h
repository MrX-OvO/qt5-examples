#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include "baseinfo.h"
#include "contact.h"
#include "detail.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget {
  Q_OBJECT

 public:
  MainWidget(QWidget* parent = nullptr);
  ~MainWidget();

 private:
  Ui::MainWidget* ui;
  BaseInfo* baseInfo;
  Contact* contact;
  Detail* detail;
};
#endif  // MAINWIDGET_H
