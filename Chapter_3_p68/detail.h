#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>

namespace Ui {
class Detail;
}

class Detail : public QWidget
{
    Q_OBJECT

public:
    explicit Detail(QWidget *parent = nullptr);
    ~Detail();

private:
    Ui::Detail *ui;
};

#endif // DETAIL_H
