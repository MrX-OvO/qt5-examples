#include "bubblesort.h"

#include <QDebug>
#include <QElapsedTimer>

BubbleSort::BubbleSort(QObject* parent) : QThread(parent) {}

void BubbleSort::run() {
  qDebug() << "冒泡排序线程的线程地址是 " << QThread::currentThread();
  QElapsedTimer timer;
  timer.start();
  for (decltype(m_data.size()) i = 0; i < m_data.size() - 1; ++i) {
    for (decltype(m_data.size()) j = 0; j < m_data.size() - i - 1; ++j) {
      if (m_data[j] > m_data[j + 1]) {
        //        auto tmp = m_data[j];
        //        m_data[j] = m_data[j + 1];
        //        m_data[j + 1] = tmp;
        std::swap(m_data[j], m_data[j + 1]);
      }
    }
  }
  int ms = timer.elapsed();
  qDebug() << "对" << m_data.size() << "个随机数进行冒泡排序用时 " << ms
           << "毫秒。";
  emit sendSortedData(m_data);
}

void BubbleSort::recvData(QVector<int> data) { m_data = data; }
