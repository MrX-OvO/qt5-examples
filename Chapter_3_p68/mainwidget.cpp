#include "mainwidget.h"

#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget) {
  ui->setupUi(this);

  // 左侧listwidget
  ui->listWidget->insertItem(0, tr("基本信息"));
  ui->listWidget->insertItem(1, tr("联系方式"));
  ui->listWidget->insertItem(2, tr("详细资料"));

  // 右上方stackwidget
  baseInfo = new BaseInfo();
  contact = new Contact();
  detail = new Detail();
  ui->stackedWidget->insertWidget(0, baseInfo);
  ui->stackedWidget->insertWidget(1, contact);
  ui->stackedWidget->insertWidget(2, detail);
  ui->stackedWidget->setCurrentIndex(2);

  connect(ui->listWidget, &QListWidget::currentRowChanged, ui->stackedWidget,
          &QStackedWidget::setCurrentIndex);
}

MainWidget::~MainWidget() { delete ui; }
