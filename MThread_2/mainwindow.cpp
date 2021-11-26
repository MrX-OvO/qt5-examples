#include "mainwindow.h"

#include <QThread>
#include <QVector>

#include "./ui_mainwindow.h"
#include "bubblesort.h"
#include "generaterandomnum.h"
#include "quicksort.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // 1.创建子线程对象
  QThread* t1 = new QThread;
  QThread* t2 = new QThread;
  QThread* t3 = new QThread;

  // 2.创建任务类对象
  // 不能添加父对象，否则报错：Cannot move objects with a parent
  GenerateRandomNum* gen = new GenerateRandomNum;
  BubbleSort* bSort = new BubbleSort;
  QuickSort* qSort = new QuickSort;

  // 3.将任务类对象移动到对应子线程中
  gen->moveToThread(t1);
  bSort->moveToThread(t2);
  qSort->moveToThread(t3);

  // 4.点击按钮生成随机数并显示
  connect(this, &MainWindow::sendNums, gen, &GenerateRandomNum::work);
  connect(ui->startBtn, &QPushButton::clicked, this, [=]() {
    emit sendNums(ui->lineEdit->text().toInt());
    t1->start();
  });

  connect(gen, &GenerateRandomNum::sendData, bSort, &BubbleSort::work);
  connect(gen, &GenerateRandomNum::sendData, qSort, &QuickSort::work);
  connect(gen, &GenerateRandomNum::sendData, this, [=](QVector<int> data) {
    if (ui->randList->count()) {
      ui->randList->clear();
    }
    for (decltype(data.size()) i = 0; i < data.size(); ++i) {
      ui->randList->addItem(QString("%1").arg(i + 1, 3) + ".\t" +
                            QString::number(data.at(i)));
    }
    ui->randList->addItem("");
    ui->randList->addItem("Max:\t" + QString::number(*std::max_element(
                                         std::begin(data), std::end(data))));
    ui->randList->addItem("Min:\t" + QString::number(*std::min_element(
                                         std::begin(data), std::end(data))));

    // 启动排序线程
    t2->start();
    t3->start();
  });

  // 5.进行排序，并显示排序后的结果
  connect(
      bSort, &BubbleSort::sendSortedData, this, [=](QVector<int> sortedData) {
        if (ui->bubbleList->count()) {
          ui->bubbleList->clear();
        }
        for (decltype(sortedData.size()) i = 0; i < sortedData.size(); ++i) {
          ui->bubbleList->addItem(QString("%1").arg(i + 1, 3) + ".\t" +
                                  QString::number(sortedData.at(i)));
        }
        ui->bubbleList->addItem("");
        ui->bubbleList->addItem(
            "Max:\t" + QString::number(*std::max_element(
                           std::begin(sortedData), std::end(sortedData))));
        ui->bubbleList->addItem(
            "Min:\t" + QString::number(*std::min_element(
                           std::begin(sortedData), std::end(sortedData))));
      });
  connect(
      qSort, &QuickSort::sendSortedData, this, [=](QVector<int> sortedData) {
        if (ui->quickList->count()) {
          ui->quickList->clear();
        }
        for (decltype(sortedData.size()) i = 0; i < sortedData.size(); ++i) {
          ui->quickList->addItem(QString("%1").arg(i + 1, 3) + ".\t" +
                                 QString::number(sortedData.at(i)));
        }
        ui->quickList->addItem("");
        ui->quickList->addItem(
            "Max:\t" + QString::number(*std::max_element(
                           std::begin(sortedData), std::end(sortedData))));
        ui->quickList->addItem(
            "Min:\t" + QString::number(*std::min_element(
                           std::begin(sortedData), std::end(sortedData))));
      });

  // 6.释放资源
  connect(this, &MainWindow::destroyed, this, [=]() {
    t1->quit();
    t1->wait();
    t1->deleteLater();

    t2->quit();
    t2->wait();
    t2->deleteLater();

    t3->quit();
    t3->wait();
    t3->deleteLater();

    gen->deleteLater();
    bSort->deleteLater();
    qSort->deleteLater();
  });
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_closeBtn_clicked() { this->close(); }
