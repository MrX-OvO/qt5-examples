#include "mainwindow.h"

#include <QVector>

#include "./ui_mainwindow.h"
#include "bubblesort.h"
#include "generaterandomnum.h"
#include "quicksort.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // 1. 创建生成随机数、冒泡排序和快速排序3个子线程
  GenerateRandomNum* gen = new GenerateRandomNum;
  BubbleSort* bSort = new BubbleSort;
  QuickSort* qSort = new QuickSort;

  // 2.点击开始生成随机数，并显示生成的随机数
  connect(this, &MainWindow::sendNums, gen, &GenerateRandomNum::recvNums);
  connect(ui->startBtn, &QPushButton::clicked, this, [=]() {
    emit sendNums(ui->lineEdit->text().toInt());
    gen->start();
  });

  connect(gen, &GenerateRandomNum::sendData, bSort, &BubbleSort::recvData);
  connect(gen, &GenerateRandomNum::sendData, qSort, &QuickSort::recvData);
  connect(gen, &GenerateRandomNum::sendData, this,
          [=](QVector<int> data) {
            if (ui->randList->count()) {
              ui->randList->clear();
            }
            for (decltype(data.size()) i = 0; i < data.size(); ++i) {
              ui->randList->addItem(QString("%1").arg(i + 1, 3) + ".\t" +
                                    QString::number(data.at(i)));
            }
            ui->randList->addItem("");
            ui->randList->addItem("Max:\t" +
                                  QString::number(*std::max_element(
                                      std::begin(data), std::end(data))));
            ui->randList->addItem("Min:\t" +
                                  QString::number(*std::min_element(
                                      std::begin(data), std::end(data))));

            // 启动排序线程
            bSort->start();
            qSort->start();
          }

  );

  // 3.进行排序，并显示排序后的结果
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

  // 4.释放资源
  connect(this, &MainWindow::destroyed, this, [=]() {
    gen->quit();
    gen->wait();
    gen->deleteLater();

    bSort->quit();
    bSort->wait();
    bSort->deleteLater();

    qSort->quit();
    qSort->wait();
    qSort->deleteLater();
  });
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_closeBtn_clicked() { this->close(); }
