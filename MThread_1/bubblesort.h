#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QThread>
#include <QVector>

class BubbleSort : public QThread {
  Q_OBJECT
 public:
  explicit BubbleSort(QObject *parent = nullptr);

 protected:
  void run() override;

 signals:
  void sendSortedData(QVector<int> data);

 public slots:
  void recvData(QVector<int> data);

 private:
  QVector<int> m_data;
};

#endif  // BUBBLESORT_H
