#include "mainwindow.h"

#include <QSqlDatabase>
#include <QtDebug>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  qDebug() << QSqlDatabase::drivers();
}

MainWindow::~MainWindow() { delete ui; }
