#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include <QRunnable>
#include <QVector>

class BubbleSort : public QObject, public QRunnable {
  Q_OBJECT
 public:
  explicit BubbleSort(QObject *parent = nullptr);

  void run() override;

 signals:
  void sendSortedData(QVector<int> data);

 public slots:
  void recvData(QVector<int> data);

 private:
  QVector<int> m_data;
};

#endif  // BUBBLESORT_H
