/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QTextBrowser *textBrowser;
    QSpinBox *spinBox;
    QPushButton *pushButton_start;
    QLineEdit *lineEdit;
    QPushButton *pushButton_send;
    QLabel *label;

    void setupUi(QWidget *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QString::fromUtf8("TcpServer"));
        TcpServer->resize(717, 454);
        textBrowser = new QTextBrowser(TcpServer);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 80, 431, 271));
        spinBox = new QSpinBox(TcpServer);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(260, 20, 91, 51));
        pushButton_start = new QPushButton(TcpServer);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(540, 20, 111, 61));
        lineEdit = new QLineEdit(TcpServer);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 380, 431, 61));
        pushButton_send = new QPushButton(TcpServer);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(520, 380, 141, 61));
        label = new QLabel(TcpServer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 10, 91, 61));

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QWidget *TcpServer)
    {
        TcpServer->setWindowTitle(QCoreApplication::translate("TcpServer", "Form", nullptr));
        pushButton_start->setText(QCoreApplication::translate("TcpServer", "start", nullptr));
        pushButton_send->setText(QCoreApplication::translate("TcpServer", "send", nullptr));
        label->setText(QCoreApplication::translate("TcpServer", "\346\234\215\345\212\241\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
