/********************************************************************************
** Form generated from reading UI file 'exposetimesetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPOSETIMESETTING_H
#define UI_EXPOSETIMESETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exposetimesetting
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *exposetimesetting)
    {
        if (exposetimesetting->objectName().isEmpty())
            exposetimesetting->setObjectName(QString::fromUtf8("exposetimesetting"));
        exposetimesetting->resize(238, 115);
        centralwidget = new QWidget(exposetimesetting);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 40, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 101, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 91, 20));
        exposetimesetting->setCentralWidget(centralwidget);
        menubar = new QMenuBar(exposetimesetting);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 238, 22));
        exposetimesetting->setMenuBar(menubar);
        statusbar = new QStatusBar(exposetimesetting);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        exposetimesetting->setStatusBar(statusbar);

        retranslateUi(exposetimesetting);

        QMetaObject::connectSlotsByName(exposetimesetting);
    } // setupUi

    void retranslateUi(QMainWindow *exposetimesetting)
    {
        exposetimesetting->setWindowTitle(QCoreApplication::translate("exposetimesetting", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("exposetimesetting", "\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("exposetimesetting", "\346\233\235\345\205\211\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exposetimesetting: public Ui_exposetimesetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPOSETIMESETTING_H
