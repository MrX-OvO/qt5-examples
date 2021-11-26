#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QObject>
#include <QVector>

class QuickSort : public QObject {
  Q_OBJECT
 public:
  explicit QuickSort(QObject* parent = nullptr);

  void work(QVector<int> data);

 signals:
  void sendSortedData(QVector<int> data);

 private:
  void quickSort(QVector<int>& data, int start, int end);
};

#endif  // QUICKSORT_H
