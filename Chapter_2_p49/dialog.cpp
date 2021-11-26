#include "dialog.h"
#include "ui_dialog.h"

#include <QRegExp>
#include<QRegExpValidator>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->inputLineEdit->setValidator(new QRegExpValidator(regExp,this));
}


Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_okPushButton_clicked()
{
    this->accept();
}


void Dialog::on_cancelPushButton_clicked()
{
    this->close();
}


void Dialog::on_inputLineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->okPushButton->setEnabled(ui->inputLineEdit->hasAcceptableInput());
}

