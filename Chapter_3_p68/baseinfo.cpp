#include "baseinfo.h"
#include "ui_baseinfo.h"

BaseInfo::BaseInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseInfo)
{
    ui->setupUi(this);
}

BaseInfo::~BaseInfo()
{
    delete ui;
}
