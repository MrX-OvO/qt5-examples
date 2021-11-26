#ifndef GENERATERANDOMNUM_H
#define GENERATERANDOMNUM_H

#include <QThread>
#include <QVector>

class GenerateRandomNum : public QThread {
  Q_OBJECT
 public:
  explicit GenerateRandomNum(QObject *parent = nullptr);

 protected:
  void run() override;

 signals:
  void sendData(QVector<int> data);

 public slots:
  void recvNums(int nums);

 private:
  int m_nums;
};

#endif  // GENERATERANDOMNUM_H
