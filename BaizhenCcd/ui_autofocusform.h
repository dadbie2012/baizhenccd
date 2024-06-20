/********************************************************************************
** Form generated from reading UI file 'autofocusform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOFOCUSFORM_H
#define UI_AUTOFOCUSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutofocusForm
{
public:
    QWidget *centralwidget;
    QComboBox *camerachoose;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ROI_width;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *ROI_start_y;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *ROI_height;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ROI_start_x;
    QPushButton *showroi;
    QGroupBox *groupBox_2;
    QPushButton *save;
    QLabel *label_18;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_19;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *startposition;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *updistance;
    QLabel *label_20;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *uptime;
    QLabel *label_21;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *downdistance;
    QLabel *label_22;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *downtime;
    QLabel *label_23;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLineEdit *returntime;
    QLabel *label_24;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QLineEdit *jixiebuchang;
    QLabel *label_25;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_26;
    QLineEdit *fenshuyuzhi;
    QCheckBox *hanshunihe;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *function_choose;
    QPushButton *showimage;
    QLabel *form;
    QMenuBar *menubar;

    void setupUi(QMainWindow *AutofocusForm)
    {
        if (AutofocusForm->objectName().isEmpty())
            AutofocusForm->setObjectName(QString::fromUtf8("AutofocusForm"));
        AutofocusForm->resize(923, 443);
        centralwidget = new QWidget(AutofocusForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        camerachoose = new QComboBox(centralwidget);
        camerachoose->addItem(QString());
        camerachoose->addItem(QString());
        camerachoose->setObjectName(QString::fromUtf8("camerachoose"));
        camerachoose->setGeometry(QRect(610, 10, 81, 22));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(580, 40, 331, 121));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 131, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ROI_width = new QLineEdit(layoutWidget);
        ROI_width->setObjectName(QString::fromUtf8("ROI_width"));

        horizontalLayout_2->addWidget(ROI_width);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(170, 20, 131, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        ROI_start_y = new QLineEdit(layoutWidget_2);
        ROI_start_y->setObjectName(QString::fromUtf8("ROI_start_y"));

        horizontalLayout_3->addWidget(ROI_start_y);

        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(170, 50, 131, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        ROI_height = new QLineEdit(layoutWidget_3);
        ROI_height->setObjectName(QString::fromUtf8("ROI_height"));

        horizontalLayout_4->addWidget(ROI_height);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 131, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        ROI_start_x = new QLineEdit(layoutWidget1);
        ROI_start_x->setObjectName(QString::fromUtf8("ROI_start_x"));

        horizontalLayout->addWidget(ROI_start_x);

        showroi = new QPushButton(groupBox);
        showroi->setObjectName(QString::fromUtf8("showroi"));
        showroi->setGeometry(QRect(110, 80, 75, 23));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(580, 180, 331, 221));
        save = new QPushButton(groupBox_2);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(110, 190, 91, 23));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 20, 54, 12));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(80, 20, 89, 16));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(170, 18, 89, 16));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(305, 43, 54, 12));
        QFont font;
        font.setPointSize(11);
        label_19->setFont(font);
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(170, 40, 131, 24));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        startposition = new QLineEdit(layoutWidget2);
        startposition->setObjectName(QString::fromUtf8("startposition"));

        horizontalLayout_6->addWidget(startposition);

        layoutWidget_4 = new QWidget(groupBox_2);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 70, 131, 24));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        updistance = new QLineEdit(layoutWidget_4);
        updistance->setObjectName(QString::fromUtf8("updistance"));

        horizontalLayout_8->addWidget(updistance);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(145, 70, 21, 16));
        label_20->setFont(font);
        layoutWidget_5 = new QWidget(groupBox_2);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(170, 70, 131, 24));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        uptime = new QLineEdit(layoutWidget_5);
        uptime->setObjectName(QString::fromUtf8("uptime"));

        horizontalLayout_9->addWidget(uptime);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(305, 70, 21, 16));
        label_21->setFont(font);
        layoutWidget_6 = new QWidget(groupBox_2);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 100, 131, 24));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        downdistance = new QLineEdit(layoutWidget_6);
        downdistance->setObjectName(QString::fromUtf8("downdistance"));

        horizontalLayout_10->addWidget(downdistance);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(145, 100, 21, 16));
        label_22->setFont(font);
        layoutWidget_7 = new QWidget(groupBox_2);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(170, 100, 131, 24));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_11->addWidget(label_11);

        downtime = new QLineEdit(layoutWidget_7);
        downtime->setObjectName(QString::fromUtf8("downtime"));

        horizontalLayout_11->addWidget(downtime);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(305, 100, 21, 16));
        label_23->setFont(font);
        layoutWidget_8 = new QWidget(groupBox_2);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 130, 131, 24));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_8);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_12->addWidget(label_12);

        returntime = new QLineEdit(layoutWidget_8);
        returntime->setObjectName(QString::fromUtf8("returntime"));

        horizontalLayout_12->addWidget(returntime);

        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(145, 130, 21, 16));
        label_24->setFont(font);
        layoutWidget_9 = new QWidget(groupBox_2);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(170, 130, 131, 24));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget_9);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_14->addWidget(label_17);

        jixiebuchang = new QLineEdit(layoutWidget_9);
        jixiebuchang->setObjectName(QString::fromUtf8("jixiebuchang"));

        horizontalLayout_14->addWidget(jixiebuchang);

        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(305, 130, 21, 16));
        label_25->setFont(font);
        layoutWidget_10 = new QWidget(groupBox_2);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(10, 160, 131, 24));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_26 = new QLabel(layoutWidget_10);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_15->addWidget(label_26);

        fenshuyuzhi = new QLineEdit(layoutWidget_10);
        fenshuyuzhi->setObjectName(QString::fromUtf8("fenshuyuzhi"));

        horizontalLayout_15->addWidget(fenshuyuzhi);

        hanshunihe = new QCheckBox(groupBox_2);
        hanshunihe->setObjectName(QString::fromUtf8("hanshunihe"));
        hanshunihe->setGeometry(QRect(170, 165, 71, 16));
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 40, 131, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        function_choose = new QComboBox(layoutWidget3);
        function_choose->addItem(QString());
        function_choose->addItem(QString());
        function_choose->addItem(QString());
        function_choose->setObjectName(QString::fromUtf8("function_choose"));

        horizontalLayout_5->addWidget(function_choose);

        showimage = new QPushButton(centralwidget);
        showimage->setObjectName(QString::fromUtf8("showimage"));
        showimage->setGeometry(QRect(780, 10, 75, 23));
        form = new QLabel(centralwidget);
        form->setObjectName(QString::fromUtf8("form"));
        form->setGeometry(QRect(10, 10, 561, 401));
        form->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        AutofocusForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AutofocusForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 923, 21));
        AutofocusForm->setMenuBar(menubar);

        retranslateUi(AutofocusForm);

        QMetaObject::connectSlotsByName(AutofocusForm);
    } // setupUi

    void retranslateUi(QMainWindow *AutofocusForm)
    {
        AutofocusForm->setWindowTitle(QCoreApplication::translate("AutofocusForm", "MainWindow", nullptr));
        camerachoose->setItemText(0, QCoreApplication::translate("AutofocusForm", "camera_1", nullptr));
        camerachoose->setItemText(1, QCoreApplication::translate("AutofocusForm", "camera_2", nullptr));

        groupBox->setTitle(QCoreApplication::translate("AutofocusForm", "ROI\345\217\202\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("AutofocusForm", "ROI\345\256\275\345\272\246  ", nullptr));
        label_3->setText(QCoreApplication::translate("AutofocusForm", "ROI\350\265\267\347\202\271Y", nullptr));
        label_4->setText(QCoreApplication::translate("AutofocusForm", "ROI\351\253\230\345\272\246 ", nullptr));
        label->setText(QCoreApplication::translate("AutofocusForm", "ROI\350\265\267\347\202\271X ", nullptr));
        showroi->setText(QCoreApplication::translate("AutofocusForm", "\346\230\276\347\244\272ROI", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("AutofocusForm", "\345\257\271\347\204\246\345\217\202\346\225\260", nullptr));
        save->setText(QCoreApplication::translate("AutofocusForm", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        label_18->setText(QCoreApplication::translate("AutofocusForm", "\344\275\215\347\275\256\345\217\202\350\200\203", nullptr));
        radioButton->setText(QCoreApplication::translate("AutofocusForm", "\345\275\223\345\211\215\347\202\271", nullptr));
        radioButton_2->setText(QCoreApplication::translate("AutofocusForm", "\351\233\266\347\202\271", nullptr));
        label_19->setText(QCoreApplication::translate("AutofocusForm", "mm", nullptr));
        label_6->setText(QCoreApplication::translate("AutofocusForm", "\350\265\267\345\247\213\344\275\215\347\275\256    ", nullptr));
        label_8->setText(QCoreApplication::translate("AutofocusForm", "\345\220\221\344\270\212\350\277\220\345\212\250\350\267\235\347\246\273", nullptr));
        label_20->setText(QCoreApplication::translate("AutofocusForm", "mm", nullptr));
        label_9->setText(QCoreApplication::translate("AutofocusForm", "\345\220\221\344\270\212\350\277\220\345\212\250\346\227\266\351\227\264", nullptr));
        label_21->setText(QCoreApplication::translate("AutofocusForm", "s", nullptr));
        label_10->setText(QCoreApplication::translate("AutofocusForm", "\345\220\221\344\270\213\350\277\220\345\212\250\350\267\235\347\246\273", nullptr));
        label_22->setText(QCoreApplication::translate("AutofocusForm", "mm", nullptr));
        label_11->setText(QCoreApplication::translate("AutofocusForm", "\345\220\221\344\270\213\350\277\220\345\212\250\346\227\266\351\227\264", nullptr));
        label_23->setText(QCoreApplication::translate("AutofocusForm", "s", nullptr));
        label_12->setText(QCoreApplication::translate("AutofocusForm", "\345\233\236\346\270\205\346\231\260\347\202\271\346\227\266\351\227\264", nullptr));
        label_24->setText(QCoreApplication::translate("AutofocusForm", "s", nullptr));
        label_17->setText(QCoreApplication::translate("AutofocusForm", "\346\234\272\346\242\260\350\241\245\345\201\277    ", nullptr));
        label_25->setText(QCoreApplication::translate("AutofocusForm", "mm", nullptr));
        label_26->setText(QCoreApplication::translate("AutofocusForm", "\345\210\206\346\225\260\351\230\210\345\200\274    ", nullptr));
        hanshunihe->setText(QCoreApplication::translate("AutofocusForm", "\345\207\275\346\225\260\346\213\237\345\220\210", nullptr));
        label_5->setText(QCoreApplication::translate("AutofocusForm", "\345\257\271\347\204\246\347\256\227\346\263\225", nullptr));
        function_choose->setItemText(0, QCoreApplication::translate("AutofocusForm", "Brenner", nullptr));
        function_choose->setItemText(1, QCoreApplication::translate("AutofocusForm", "2", nullptr));
        function_choose->setItemText(2, QCoreApplication::translate("AutofocusForm", "3", nullptr));

        showimage->setText(QCoreApplication::translate("AutofocusForm", "\346\230\276\347\244\272\345\233\276\345\203\217", nullptr));
        form->setText(QCoreApplication::translate("AutofocusForm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutofocusForm: public Ui_AutofocusForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOFOCUSFORM_H
