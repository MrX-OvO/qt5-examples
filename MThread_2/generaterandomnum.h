#ifndef GENERATERANDOMNUM_H
#define GENERATERANDOMNUM_H

#include <QObject>
#include <QVector>

class GenerateRandomNum : public QObject {
  Q_OBJECT
 public:
  explicit GenerateRandomNum(QObject *parent = nullptr);

  void work(int nums);

 signals:
  void sendData(QVector<int> data);
};

#endif  // GENERATERANDOMNUM_H
