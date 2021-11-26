#include "bubblesort.h"

#include <QDebug>
#include <QElapsedTimer>
#include <QThread>

BubbleSort::BubbleSort(QObject* parent) : QObject(parent) {}

void BubbleSort::work(QVector<int> data) {
  qDebug() << "冒泡排序线程的线程地址是 " << QThread::currentThread();
  QElapsedTimer timer;
  timer.start();
  for (decltype(data.size()) i = 0; i < data.size() - 1; ++i) {
    for (decltype(data.size()) j = 0; j < data.size() - i - 1; ++j) {
      if (data[j] > data[j + 1]) {
        //        auto tmp = data[j];
        //        data[j] = data[j + 1];
        //        data[j + 1] = tmp;
        std::swap(data[j], data[j + 1]);
      }
    }
  }
  int ms = timer.elapsed();
  qDebug() << "对" << data.size() << "个随机数进行冒泡排序用时 " << ms
           << "毫秒。";
  emit sendSortedData(data);
}
