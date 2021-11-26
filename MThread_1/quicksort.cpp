#include "quicksort.h"

#include <QDebug>
#include <QElapsedTimer>

QuickSort::QuickSort(QObject* parent) : QThread(parent) {}

void QuickSort::run() {
  qDebug() << "快速排序的线程的线程地址是 " << QThread::currentThread();
  QElapsedTimer timer;
  timer.start();
  quickSort(m_data, 0, m_data.size() - 1);
  int ms = timer.elapsed();
  qDebug() << "对" << m_data.size() << "个随机数进行快速排序用时 " << ms
           << "毫秒。";
  emit sendSortedData(m_data);
}

void QuickSort::recvData(QVector<int> data) { m_data = data; }

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
