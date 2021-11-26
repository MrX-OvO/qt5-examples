#ifndef GENERATERANDOMNUM_H
#define GENERATERANDOMNUM_H

#include <QObject>
#include <QRunnable>
#include <QVector>

class GenerateRandomNum : public QObject, public QRunnable {
  Q_OBJECT
 public:
  explicit GenerateRandomNum(QObject *parent = nullptr);

  void run() override;

 signals:
  void sendData(QVector<int> data);

 public slots:
  void recvNums(int nums);

 private:
  int m_nums;
};

#endif  // GENERATERANDOMNUM_H
