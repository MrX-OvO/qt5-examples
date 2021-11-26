/********************************************************************************
** Form generated from reading UI file 'baseinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEINFO_H
#define UI_BASEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaseInfo
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_8;
    QComboBox *comboBox;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *BaseInfo)
    {
        if (BaseInfo->objectName().isEmpty())
            BaseInfo->setObjectName(QString::fromUtf8("BaseInfo"));
        BaseInfo->resize(733, 506);
        horizontalLayout = new QHBoxLayout(BaseInfo);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(BaseInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 4, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 3, 1, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(BaseInfo);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        textEdit_2 = new QTextEdit(widget_4);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout_2->addWidget(textEdit_2);


        verticalLayout->addWidget(widget_4);


        horizontalLayout->addWidget(widget_2);


        retranslateUi(BaseInfo);

        QMetaObject::connectSlotsByName(BaseInfo);
    } // setupUi

    void retranslateUi(QWidget *BaseInfo)
    {
        BaseInfo->setWindowTitle(QCoreApplication::translate("BaseInfo", "BaseInfo", nullptr));
        label_4->setText(QCoreApplication::translate("BaseInfo", "\345\271\264\351\276\204", nullptr));
        label_2->setText(QCoreApplication::translate("BaseInfo", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("BaseInfo", "\351\203\250\351\227\250", nullptr));
        label->setText(QCoreApplication::translate("BaseInfo", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_8->setText(QCoreApplication::translate("BaseInfo", "\346\200\247\345\210\253", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("BaseInfo", "\347\224\267", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("BaseInfo", "\345\245\263", nullptr));

        label_5->setText(QCoreApplication::translate("BaseInfo", "\345\244\264\345\203\217", nullptr));
        label_6->setText(QCoreApplication::translate("BaseInfo", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("BaseInfo", "\346\233\264\346\226\260", nullptr));
        label_7->setText(QCoreApplication::translate("BaseInfo", "\344\270\252\344\272\272\350\257\264\346\230\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaseInfo: public Ui_BaseInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEINFO_H
