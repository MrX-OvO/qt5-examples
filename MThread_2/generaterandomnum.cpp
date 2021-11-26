#include "generaterandomnum.h"

#include <QDebug>
#include <QElapsedTimer>
#include <QRandomGenerator>
#include <QThread>

GenerateRandomNum::GenerateRandomNum(QObject* parent) : QObject(parent) {}

void GenerateRandomNum::work(int nums) {
  qDebug() << "生成随机数的线程的线程地址是 " << QThread::currentThread();
  QVector<int> data;
  QElapsedTimer timer;
  timer.start();
  for (int i = 0; i < nums; ++i) {
    data.push_back(QRandomGenerator::global()->bounded(nums));
  }
  int ms = timer.elapsed();
  qDebug() << "生成" << nums << "个随机数用时 " << ms << "毫秒。";
  emit sendData(data);
}
