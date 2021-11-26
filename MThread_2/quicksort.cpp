#include "quicksort.h"

#include <QDebug>
#include <QElapsedTimer>
#include <QThread>

QuickSort::QuickSort(QObject* parent) : QObject(parent) {}

void QuickSort::work(QVector<int> data) {
  qDebug() << "快速排序的线程的线程地址是 " << QThread::currentThread();
  QElapsedTimer timer;
  timer.start();
  quickSort(data, 0, data.size() - 1);
  int ms = timer.elapsed();
  qDebug() << "对" << data.size() << "个随机数进行快速排序用时 " << ms
           << "毫秒。";
  emit sendSortedData(data);
}

void QuickSort::quickSort(QVector<int>& data, int start, int end) {
  auto i = start, j = end;
  if (i < j) {
    auto tmp = data[i];
    while (i != j) {
      while (j > i && data[j] >= tmp) --j;
      if (j > i) data[i++] = data[j];
      while (i < j && data[i] < tmp) ++i;
      if (i < j) data[j--] = data[i];
    }
    data[i] = tmp;
    quickSort(data, start, i - 1);
    quickSort(data, i + 1, end);
  }
}
