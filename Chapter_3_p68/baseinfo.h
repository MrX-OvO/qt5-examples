#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>

namespace Ui {
class BaseInfo;
}

class BaseInfo : public QWidget
{
    Q_OBJECT

public:
    explicit BaseInfo(QWidget *parent = nullptr);
    ~BaseInfo();

private:
    Ui::BaseInfo *ui;
};

#endif // BASEINFO_H
