/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *connToServerBtn;
    QLabel *serverIPLabel;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *serverPortLineEdit;
    QLineEdit *serverIPLineEdit;
    QLabel *serverPortLabel;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *disconnToServerBtn;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *recordTextEdit;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *messageTextEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sendDataBtn;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(800, 600);
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        connToServerBtn = new QPushButton(widget);
        connToServerBtn->setObjectName(QString::fromUtf8("connToServerBtn"));

        gridLayout->addWidget(connToServerBtn, 0, 3, 1, 1);

        serverIPLabel = new QLabel(widget);
        serverIPLabel->setObjectName(QString::fromUtf8("serverIPLabel"));

        gridLayout->addWidget(serverIPLabel, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        serverPortLineEdit = new QLineEdit(widget);
        serverPortLineEdit->setObjectName(QString::fromUtf8("serverPortLineEdit"));

        gridLayout->addWidget(serverPortLineEdit, 1, 1, 1, 1);

        serverIPLineEdit = new QLineEdit(widget);
        serverIPLineEdit->setObjectName(QString::fromUtf8("serverIPLineEdit"));

        gridLayout->addWidget(serverIPLineEdit, 0, 1, 1, 1);

        serverPortLabel = new QLabel(widget);
        serverPortLabel->setObjectName(QString::fromUtf8("serverPortLabel"));

        gridLayout->addWidget(serverPortLabel, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        disconnToServerBtn = new QPushButton(widget);
        disconnToServerBtn->setObjectName(QString::fromUtf8("disconnToServerBtn"));

        gridLayout->addWidget(disconnToServerBtn, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 4, 1, 1);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        recordTextEdit = new QTextEdit(groupBox);
        recordTextEdit->setObjectName(QString::fromUtf8("recordTextEdit"));

        verticalLayout_4->addWidget(recordTextEdit);


        verticalLayout_2->addWidget(groupBox);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_2 = new QGroupBox(widget_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        messageTextEdit = new QTextEdit(groupBox_2);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));

        verticalLayout_5->addWidget(messageTextEdit);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        sendDataBtn = new QPushButton(widget_4);
        sendDataBtn->setObjectName(QString::fromUtf8("sendDataBtn"));

        horizontalLayout_2->addWidget(sendDataBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_4);

        Client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        Client->setMenuBar(menubar);
        statusbar = new QStatusBar(Client);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Client->setStatusBar(statusbar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "TCP - \345\256\242\346\210\267\347\253\257", nullptr));
        connToServerBtn->setText(QCoreApplication::translate("Client", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        serverIPLabel->setText(QCoreApplication::translate("Client", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        serverPortLineEdit->setPlaceholderText(QCoreApplication::translate("Client", "\350\257\267\350\276\223\345\205\245\350\246\201\345\220\257\345\212\250\347\232\204\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        serverIPLineEdit->setPlaceholderText(QCoreApplication::translate("Client", "\350\257\267\350\276\223\345\205\245\350\246\201\345\220\257\345\212\250\347\232\204\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        serverPortLabel->setText(QCoreApplication::translate("Client", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        disconnToServerBtn->setText(QCoreApplication::translate("Client", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Client", "\351\200\232\344\277\241\350\256\260\345\275\225", nullptr));
        recordTextEdit->setPlaceholderText(QCoreApplication::translate("Client", "\345\260\206\344\274\232\346\230\276\347\244\272\351\200\232\344\277\241\350\256\260\345\275\225...", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Client", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        messageTextEdit->setPlaceholderText(QCoreApplication::translate("Client", "\350\257\267\350\276\223\345\205\245\350\246\201\345\217\221\351\200\201\347\232\204\346\266\210\346\201\257...", nullptr));
        sendDataBtn->setText(QCoreApplication::translate("Client", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
