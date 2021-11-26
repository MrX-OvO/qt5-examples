/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *serverIPLabel;
    QLineEdit *serverIPLineEdit;
    QLabel *serverPortlabel;
    QLineEdit *serverPortLineEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *connToServerBtn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *filePathLineEdit;
    QPushButton *selectFileBtn;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *progressLabel;
    QProgressBar *progressBar;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *sendFileBtn;
    QSpacerItem *horizontalSpacer_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        serverIPLabel = new QLabel(widget);
        serverIPLabel->setObjectName(QString::fromUtf8("serverIPLabel"));

        gridLayout->addWidget(serverIPLabel, 0, 0, 1, 1);

        serverIPLineEdit = new QLineEdit(widget);
        serverIPLineEdit->setObjectName(QString::fromUtf8("serverIPLineEdit"));

        gridLayout->addWidget(serverIPLineEdit, 0, 1, 1, 1);

        serverPortlabel = new QLabel(widget);
        serverPortlabel->setObjectName(QString::fromUtf8("serverPortlabel"));

        gridLayout->addWidget(serverPortlabel, 1, 0, 1, 1);

        serverPortLineEdit = new QLineEdit(widget);
        serverPortLineEdit->setObjectName(QString::fromUtf8("serverPortLineEdit"));

        gridLayout->addWidget(serverPortLineEdit, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        horizontalLayout->addWidget(widget);

        connToServerBtn = new QPushButton(widget_2);
        connToServerBtn->setObjectName(QString::fromUtf8("connToServerBtn"));

        horizontalLayout->addWidget(connToServerBtn);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        filePathLineEdit = new QLineEdit(widget_3);
        filePathLineEdit->setObjectName(QString::fromUtf8("filePathLineEdit"));

        horizontalLayout_2->addWidget(filePathLineEdit);

        selectFileBtn = new QPushButton(widget_3);
        selectFileBtn->setObjectName(QString::fromUtf8("selectFileBtn"));

        horizontalLayout_2->addWidget(selectFileBtn);


        verticalLayout->addWidget(widget_3);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        progressLabel = new QLabel(widget_5);
        progressLabel->setObjectName(QString::fromUtf8("progressLabel"));

        horizontalLayout_4->addWidget(progressLabel);

        progressBar = new QProgressBar(widget_5);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_4->addWidget(progressBar);


        verticalLayout->addWidget(widget_5);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        sendFileBtn = new QPushButton(widget_4);
        sendFileBtn->setObjectName(QString::fromUtf8("sendFileBtn"));

        horizontalLayout_3->addWidget(sendFileBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257", nullptr));
        serverIPLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        serverIPLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\234\215\345\212\241\345\231\250IP", nullptr));
        serverPortlabel->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        serverPortLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267", nullptr));
        connToServerBtn->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        filePathLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\267\262\351\200\211\346\213\251\347\232\204\346\226\207\344\273\266", nullptr));
        selectFileBtn->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        progressLabel->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\350\277\233\345\272\246", nullptr));
        sendFileBtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
