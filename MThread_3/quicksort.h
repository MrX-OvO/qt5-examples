#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QObject>
#include <QRunnable>
#include <QVector>

class QuickSort : public QObject, public QRunnable {
  Q_OBJECT
 public:
  explicit QuickSort(QObject* parent = nullptr);

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
