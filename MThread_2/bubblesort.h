#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include <QVector>

class BubbleSort : public QObject {
  Q_OBJECT
 public:
  explicit BubbleSort(QObject *parent = nullptr);

  void work(QVector<int> data);

 signals:
  void sendSortedData(QVector<int> data);
};

#endif  // BUBBLESORT_H
