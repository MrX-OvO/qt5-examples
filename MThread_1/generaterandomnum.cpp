#include "generaterandomnum.h"

#include <QDebug>
#include <QElapsedTimer>
#include <QRandomGenerator>

GenerateRandomNum::GenerateRandomNum(QObject* parent) : QThread(parent) {}

void GenerateRandomNum::run() {
  qDebug() << "生成随机数的线程的线程地址是 " << QThread::currentThread();
  QVector<int> data;
  QElapsedTimer timer;
  timer.start();
  for (int i = 0; i < m_nums; ++i) {
    data.push_back(QRandomGenerator::global()->bounded(m_nums));
  }
  int ms = timer.elapsed();
  qDebug() << "生成" << m_nums << "个随机数用时 " << ms << "毫秒。";
  emit sendData(data);
}

void GenerateRandomNum::recvNums(int nums) { m_nums = nums; }
