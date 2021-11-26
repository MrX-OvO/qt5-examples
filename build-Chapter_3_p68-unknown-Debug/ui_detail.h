/********************************************************************************
** Form generated from reading UI file 'detail.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAIL_H
#define UI_DETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Detail
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QTextEdit *textEdit;

    void setupUi(QWidget *Detail)
    {
        if (Detail->objectName().isEmpty())
            Detail->setObjectName(QString::fromUtf8("Detail"));
        Detail->resize(400, 300);
        gridLayout = new QGridLayout(Detail);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(Detail);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        comboBox = new QComboBox(Detail);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(Detail);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(Detail);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(Detail);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 0, 1, 1);

        lineEdit_4 = new QLineEdit(Detail);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 1, 1, 1);

        lineEdit_5 = new QLineEdit(Detail);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 3, 0, 1, 1);

        textEdit = new QTextEdit(Detail);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 3, 1, 1, 1);


        retranslateUi(Detail);

        QMetaObject::connectSlotsByName(Detail);
    } // setupUi

    void retranslateUi(QWidget *Detail)
    {
        Detail->setWindowTitle(QCoreApplication::translate("Detail", "Detail", nullptr));
        lineEdit->setText(QCoreApplication::translate("Detail", "\345\233\275\345\256\266/\345\234\260\345\214\272", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Detail", "\344\270\255\345\233\275", nullptr));

        lineEdit_2->setText(QCoreApplication::translate("Detail", "\347\234\201\344\273\275", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Detail", "\345\237\216\345\270\202", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("Detail", "\344\270\252\344\272\272\350\257\264\346\230\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Detail: public Ui_Detail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAIL_H
