#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QThread>
#include <QVector>

class QuickSort : public QThread {
  Q_OBJECT
 public:
  explicit QuickSort(QObject* parent = nullptr);

 protected:
  void run() override;

 signals:
  void sendSortedData(QVector<int> data);

 public slots:
  void recvData(QVector<int> data);

 private:
  void quickSort(QVector<int>& data, int start, int end);

 private:
  QVector<int> m_data;
};

#endif  // QUICKSORT_H
