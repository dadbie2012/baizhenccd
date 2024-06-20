/********************************************************************************
** Form generated from reading UI file 'finelineform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINELINEFORM_H
#define UI_FINELINEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "myqgraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_FinelineForm
{
public:
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout2;
    QLabel *label_2;
    QComboBox *comboBox_edge_polarity;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox_edge_threshold;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBox_filter_size;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *spinBox_caliper_number;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_choose_picture;
    QPushButton *pushButton_refresh;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_caliberline;
    QPushButton *pushButton_findline;
    QPushButton *pushButton_3;
    QLabel *label_string;
    QGroupBox *groupBox_2;
    myqgraphicsview *graphicsView;

    void setupUi(QWidget *FinelineForm)
    {
        if (FinelineForm->objectName().isEmpty())
            FinelineForm->setObjectName(QString::fromUtf8("FinelineForm"));
        FinelineForm->resize(1088, 654);
        groupBox = new QGroupBox(FinelineForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(49, 20, 271, 601));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 221, 61));
        horizontalLayout2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout2->setObjectName(QString::fromUtf8("horizontalLayout2"));
        horizontalLayout2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        horizontalLayout2->addWidget(label_2);

        comboBox_edge_polarity = new QComboBox(horizontalLayoutWidget);
        comboBox_edge_polarity->addItem(QString());
        comboBox_edge_polarity->addItem(QString());
        comboBox_edge_polarity->setObjectName(QString::fromUtf8("comboBox_edge_polarity"));
        sizePolicy.setHeightForWidth(comboBox_edge_polarity->sizePolicy().hasHeightForWidth());
        comboBox_edge_polarity->setSizePolicy(sizePolicy);
        comboBox_edge_polarity->setFont(font);
        comboBox_edge_polarity->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout2->addWidget(comboBox_edge_polarity);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 130, 221, 61));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        spinBox_edge_threshold = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_edge_threshold->setObjectName(QString::fromUtf8("spinBox_edge_threshold"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_edge_threshold->sizePolicy().hasHeightForWidth());
        spinBox_edge_threshold->setSizePolicy(sizePolicy1);
        spinBox_edge_threshold->setFont(font);

        horizontalLayout_3->addWidget(spinBox_edge_threshold);

        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 220, 221, 61));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        spinBox_filter_size = new QSpinBox(horizontalLayoutWidget_3);
        spinBox_filter_size->setObjectName(QString::fromUtf8("spinBox_filter_size"));
        sizePolicy1.setHeightForWidth(spinBox_filter_size->sizePolicy().hasHeightForWidth());
        spinBox_filter_size->setSizePolicy(sizePolicy1);
        spinBox_filter_size->setFont(font);

        horizontalLayout_4->addWidget(spinBox_filter_size);

        horizontalLayoutWidget_4 = new QWidget(groupBox);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(20, 310, 221, 61));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        spinBox_caliper_number = new QSpinBox(horizontalLayoutWidget_4);
        spinBox_caliper_number->setObjectName(QString::fromUtf8("spinBox_caliper_number"));
        sizePolicy1.setHeightForWidth(spinBox_caliper_number->sizePolicy().hasHeightForWidth());
        spinBox_caliper_number->setSizePolicy(sizePolicy1);
        spinBox_caliper_number->setFont(font);

        horizontalLayout_5->addWidget(spinBox_caliper_number);

        horizontalLayoutWidget_5 = new QWidget(groupBox);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(20, 400, 221, 71));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        pushButton_choose_picture = new QPushButton(horizontalLayoutWidget_5);
        pushButton_choose_picture->setObjectName(QString::fromUtf8("pushButton_choose_picture"));
        sizePolicy1.setHeightForWidth(pushButton_choose_picture->sizePolicy().hasHeightForWidth());
        pushButton_choose_picture->setSizePolicy(sizePolicy1);
        pushButton_choose_picture->setFont(font);
        pushButton_choose_picture->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(pushButton_choose_picture);

        pushButton_refresh = new QPushButton(horizontalLayoutWidget_5);
        pushButton_refresh->setObjectName(QString::fromUtf8("pushButton_refresh"));
        sizePolicy1.setHeightForWidth(pushButton_refresh->sizePolicy().hasHeightForWidth());
        pushButton_refresh->setSizePolicy(sizePolicy1);
        pushButton_refresh->setFont(font);
        pushButton_refresh->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(pushButton_refresh);

        horizontalLayoutWidget_6 = new QWidget(groupBox);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(20, 500, 221, 71));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton_caliberline = new QPushButton(horizontalLayoutWidget_6);
        pushButton_caliberline->setObjectName(QString::fromUtf8("pushButton_caliberline"));
        sizePolicy1.setHeightForWidth(pushButton_caliberline->sizePolicy().hasHeightForWidth());
        pushButton_caliberline->setSizePolicy(sizePolicy1);
        pushButton_caliberline->setFont(font);
        pushButton_caliberline->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(pushButton_caliberline);

        pushButton_findline = new QPushButton(horizontalLayoutWidget_6);
        pushButton_findline->setObjectName(QString::fromUtf8("pushButton_findline"));
        sizePolicy1.setHeightForWidth(pushButton_findline->sizePolicy().hasHeightForWidth());
        pushButton_findline->setSizePolicy(sizePolicy1);
        pushButton_findline->setFont(font);
        pushButton_findline->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(pushButton_findline);

        pushButton_3 = new QPushButton(FinelineForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 510, 121, 111));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 158);\n"
"color: rgb(255, 255, 255);"));
        label_string = new QLabel(FinelineForm);
        label_string->setObjectName(QString::fromUtf8("label_string"));
        label_string->setGeometry(QRect(480, 500, 561, 121));
        QFont font2;
        font2.setPointSize(13);
        label_string->setFont(font2);
        label_string->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 255, 205);"));
        groupBox_2 = new QGroupBox(FinelineForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 20, 721, 481));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        groupBox_2->setFont(font3);
        graphicsView = new myqgraphicsview(groupBox_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 30, 701, 441));

        retranslateUi(FinelineForm);

        QMetaObject::connectSlotsByName(FinelineForm);
    } // setupUi

    void retranslateUi(QWidget *FinelineForm)
    {
        FinelineForm->setWindowTitle(QCoreApplication::translate("FinelineForm", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FinelineForm", "\345\215\241\345\260\272\345\217\202\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("FinelineForm", "\350\276\271\347\274\230\346\236\201\346\200\247", nullptr));
        comboBox_edge_polarity->setItemText(0, QCoreApplication::translate("FinelineForm", "\346\230\216\345\210\260\346\232\227", nullptr));
        comboBox_edge_polarity->setItemText(1, QCoreApplication::translate("FinelineForm", "\346\232\227\345\210\260\346\230\216", nullptr));

        label_3->setText(QCoreApplication::translate("FinelineForm", "\350\276\271\347\274\230\351\230\210\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("FinelineForm", "\346\273\244\346\263\242\345\260\272\345\257\270", nullptr));
        label_5->setText(QCoreApplication::translate("FinelineForm", "\345\215\241\345\260\272\346\225\260\351\207\217", nullptr));
        pushButton_choose_picture->setText(QCoreApplication::translate("FinelineForm", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        pushButton_refresh->setText(QCoreApplication::translate("FinelineForm", "\346\233\264\346\226\260", nullptr));
        pushButton_caliberline->setText(QCoreApplication::translate("FinelineForm", "\345\215\241\345\260\272\345\267\245\345\205\267", nullptr));
        pushButton_findline->setText(QCoreApplication::translate("FinelineForm", "\346\213\237\345\220\210\347\233\264\347\272\277", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FinelineForm", "\346\230\276\347\244\272\345\233\276\345\203\217", nullptr));
        label_string->setText(QCoreApplication::translate("FinelineForm", "Log", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FinelineForm", "\345\233\276\345\203\217", nullptr));
#if QT_CONFIG(whatsthis)
        graphicsView->setWhatsThis(QCoreApplication::translate("FinelineForm", "<html><head/><body><p>aaa</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class FinelineForm: public Ui_FinelineForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINELINEFORM_H
