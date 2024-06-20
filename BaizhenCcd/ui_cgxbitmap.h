/********************************************************************************
** Form generated from reading UI file 'cgxbitmap.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGXBITMAP_H
#define UI_CGXBITMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGXBitmap
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *CGXBitmap)
    {
        if (CGXBitmap->objectName().isEmpty())
            CGXBitmap->setObjectName(QString::fromUtf8("CGXBitmap"));
        CGXBitmap->resize(1643, 1234);
        pushButton_3 = new QPushButton(CGXBitmap);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 1180, 80, 20));
        pushButton_4 = new QPushButton(CGXBitmap);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(500, 1190, 80, 20));
        pushButton = new QPushButton(CGXBitmap);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 1180, 80, 20));
        pushButton_2 = new QPushButton(CGXBitmap);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 1170, 80, 20));

        retranslateUi(CGXBitmap);

        QMetaObject::connectSlotsByName(CGXBitmap);
    } // setupUi

    void retranslateUi(QWidget *CGXBitmap)
    {
        CGXBitmap->setWindowTitle(QCoreApplication::translate("CGXBitmap", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CGXBitmap", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CGXBitmap", "\345\205\263\351\227\255\351\207\207\351\233\206", nullptr));
        pushButton->setText(QCoreApplication::translate("CGXBitmap", "\346\211\223\345\274\200", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CGXBitmap", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGXBitmap: public Ui_CGXBitmap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGXBITMAP_H
