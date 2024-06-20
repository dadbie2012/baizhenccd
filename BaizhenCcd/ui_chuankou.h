/********************************************************************************
** Form generated from reading UI file 'chuankou.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHUANKOU_H
#define UI_CHUANKOU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChuanKou
{
public:
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_2;
    QPushButton *openlight;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QTextBrowser *Log;

    void setupUi(QWidget *ChuanKou)
    {
        if (ChuanKou->objectName().isEmpty())
            ChuanKou->setObjectName(QString::fromUtf8("ChuanKou"));
        ChuanKou->resize(590, 304);
        ChuanKou->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        groupBox = new QGroupBox(ChuanKou);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 181, 131));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(90, 50, 69, 21));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 90, 75, 23));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 55, 75, 23));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 20, 75, 23));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        groupBox_2 = new QGroupBox(ChuanKou);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 160, 181, 131));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 50, 69, 21));
        openlight = new QPushButton(groupBox_2);
        openlight->setObjectName(QString::fromUtf8("openlight"));
        openlight->setGeometry(QRect(10, 20, 75, 23));
        openlight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 90, 75, 23));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        groupBox_3 = new QGroupBox(ChuanKou);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(220, 10, 361, 281));
        Log = new QTextBrowser(groupBox_3);
        Log->setObjectName(QString::fromUtf8("Log"));
        Log->setGeometry(QRect(10, 20, 341, 251));

        retranslateUi(ChuanKou);

        QMetaObject::connectSlotsByName(ChuanKou);
    } // setupUi

    void retranslateUi(QWidget *ChuanKou)
    {
        ChuanKou->setWindowTitle(QCoreApplication::translate("ChuanKou", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ChuanKou", "\344\270\262\345\217\243\346\216\247\345\210\266", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ChuanKou", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ChuanKou", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ChuanKou", "3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("ChuanKou", "4", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("ChuanKou", "5", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("ChuanKou", "6", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("ChuanKou", "7", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("ChuanKou", "8", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("ChuanKou", "9", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("ChuanKou", "10", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("ChuanKou", "11", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("ChuanKou", "12", nullptr));

        pushButton_2->setText(QCoreApplication::translate("ChuanKou", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
        pushButton->setText(QCoreApplication::translate("ChuanKou", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        pushButton_5->setText(QCoreApplication::translate("ChuanKou", "\344\270\262\345\217\243\344\277\241\346\201\257", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ChuanKou", "\347\201\257\345\205\211\346\216\247\345\210\266", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("ChuanKou", "1", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("ChuanKou", "2", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("ChuanKou", "3", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("ChuanKou", "4", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("ChuanKou", "5", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("ChuanKou", "6", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("ChuanKou", "7", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("ChuanKou", "8", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("ChuanKou", "9", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("ChuanKou", "10", nullptr));
        comboBox_2->setItemText(10, QCoreApplication::translate("ChuanKou", "11", nullptr));
        comboBox_2->setItemText(11, QCoreApplication::translate("ChuanKou", "12", nullptr));
        comboBox_2->setItemText(12, QCoreApplication::translate("ChuanKou", "13", nullptr));
        comboBox_2->setItemText(13, QCoreApplication::translate("ChuanKou", "14", nullptr));
        comboBox_2->setItemText(14, QCoreApplication::translate("ChuanKou", "15", nullptr));
        comboBox_2->setItemText(15, QCoreApplication::translate("ChuanKou", "16", nullptr));

        openlight->setText(QCoreApplication::translate("ChuanKou", "\345\274\200\347\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ChuanKou", "\345\205\263\347\201\257", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ChuanKou", "\350\276\223\345\207\272\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChuanKou: public Ui_ChuanKou {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHUANKOU_H
