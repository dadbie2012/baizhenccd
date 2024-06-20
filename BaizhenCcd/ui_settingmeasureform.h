/********************************************************************************
** Form generated from reading UI file 'settingmeasureform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGMEASUREFORM_H
#define UI_SETTINGMEASUREFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <form.h>

QT_BEGIN_NAMESPACE

class Ui_SettingMeasureForm
{
public:
    QLabel *label_3;
    QPushButton *setting;
    QGroupBox *groupBox;
    QTabWidget *tabWidget_2;
    QWidget *tab_9;
    QLabel *imageLabel;
    QWidget *tab_10;
    Form *resultimage_1;
    QWidget *tab_2;
    Form *resultimage_3;
    QWidget *tab_3;
    Form *resultimage_4;
    QWidget *tab;
    Form *resultimage_2;
    QGroupBox *groupBox_2;
    QLabel *modellabel;
    QLabel *setlabel_1;
    QPushButton *loadmodel_1;
    QPushButton *setmodel_1;
    QPushButton *savemodel_1;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QComboBox *camera_choose;
    QPushButton *updateimage_1;
    QPushButton *loadimage_1;
    QGroupBox *groupBox_4;
    QPushButton *trainmodel;
    QPushButton *modelmatch_1;
    QGroupBox *groupBox_5;
    QSpinBox *spinBox;
    QPushButton *erzhihua;
    QComboBox *comboBox;
    QSpinBox *spinBox_3;
    QGroupBox *groupBox_6;
    QPushButton *lineset_1;
    QPushButton *findline;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *line_1_1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *line_1_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *line_1_3;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *line_1_4;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *line_1_5;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *line_1_8;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *line_1_9;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *line_1_10;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *line_1_11;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *line_1_12;
    QGroupBox *groupBox_7;
    QPushButton *blob;
    QCheckBox *checkBox;
    QLabel *label_5;
    QLineEdit *blobmin;
    QLabel *label_6;
    QLineEdit *blobmax;
    QGroupBox *groupBox_8;
    QCheckBox *checkBox_2;
    QSpinBox *spinBox_2;
    QPushButton *pixel;
    QGroupBox *groupBox_9;
    QTextBrowser *Log;
    QPushButton *xihua;
    QPushButton *zhixiandu;
    QCheckBox *checkBox_3;
    QComboBox *comboBox_2;

    void setupUi(QWidget *SettingMeasureForm)
    {
        if (SettingMeasureForm->objectName().isEmpty())
            SettingMeasureForm->setObjectName(QString::fromUtf8("SettingMeasureForm"));
        SettingMeasureForm->resize(1430, 781);
        label_3 = new QLabel(SettingMeasureForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 490, 54, 12));
        setting = new QPushButton(SettingMeasureForm);
        setting->setObjectName(QString::fromUtf8("setting"));
        setting->setGeometry(QRect(1030, 540, 131, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        setting->setFont(font);
        setting->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 158);\n"
"color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(SettingMeasureForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 661, 531));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        tabWidget_2 = new QTabWidget(groupBox);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 20, 641, 501));
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        imageLabel = new QLabel(tab_9);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(10, 10, 621, 451));
        imageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        tabWidget_2->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        resultimage_1 = new Form(tab_10);
        resultimage_1->setObjectName(QString::fromUtf8("resultimage_1"));
        resultimage_1->setGeometry(QRect(10, 10, 621, 451));
        resultimage_1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        resultimage_1->setFrameShape(QFrame::StyledPanel);
        resultimage_1->setFrameShadow(QFrame::Raised);
        tabWidget_2->addTab(tab_10, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        resultimage_3 = new Form(tab_2);
        resultimage_3->setObjectName(QString::fromUtf8("resultimage_3"));
        resultimage_3->setGeometry(QRect(10, 10, 621, 451));
        resultimage_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        resultimage_3->setFrameShape(QFrame::StyledPanel);
        resultimage_3->setFrameShadow(QFrame::Raised);
        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        resultimage_4 = new Form(tab_3);
        resultimage_4->setObjectName(QString::fromUtf8("resultimage_4"));
        resultimage_4->setGeometry(QRect(9, 9, 621, 451));
        resultimage_4->setFrameShape(QFrame::StyledPanel);
        resultimage_4->setFrameShadow(QFrame::Raised);
        tabWidget_2->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        resultimage_2 = new Form(tab);
        resultimage_2->setObjectName(QString::fromUtf8("resultimage_2"));
        resultimage_2->setGeometry(QRect(10, 10, 621, 451));
        resultimage_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        resultimage_2->setFrameShape(QFrame::StyledPanel);
        resultimage_2->setFrameShadow(QFrame::Raised);
        tabWidget_2->addTab(tab, QString());
        groupBox_2 = new QGroupBox(SettingMeasureForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 550, 661, 211));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        groupBox_2->setFont(font2);
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        modellabel = new QLabel(groupBox_2);
        modellabel->setObjectName(QString::fromUtf8("modellabel"));
        modellabel->setGeometry(QRect(20, 30, 221, 151));
        modellabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        setlabel_1 = new QLabel(groupBox_2);
        setlabel_1->setObjectName(QString::fromUtf8("setlabel_1"));
        setlabel_1->setGeometry(QRect(420, 30, 221, 151));
        setlabel_1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        loadmodel_1 = new QPushButton(groupBox_2);
        loadmodel_1->setObjectName(QString::fromUtf8("loadmodel_1"));
        loadmodel_1->setGeometry(QRect(280, 30, 101, 41));
        loadmodel_1->setFont(font2);
        loadmodel_1->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88);\n"
"color: rgb(255, 255, 255);"));
        setmodel_1 = new QPushButton(groupBox_2);
        setmodel_1->setObjectName(QString::fromUtf8("setmodel_1"));
        setmodel_1->setGeometry(QRect(280, 80, 101, 41));
        setmodel_1->setFont(font2);
        setmodel_1->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88);\n"
"color: rgb(255, 255, 255);"));
        savemodel_1 = new QPushButton(groupBox_2);
        savemodel_1->setObjectName(QString::fromUtf8("savemodel_1"));
        savemodel_1->setGeometry(QRect(280, 130, 101, 41));
        savemodel_1->setFont(font2);
        savemodel_1->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 190, 54, 12));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(500, 190, 54, 12));
        label_2->setFont(font3);
        groupBox_3 = new QGroupBox(SettingMeasureForm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(680, 20, 141, 261));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 121, 31));
        QFont font4;
        font4.setPointSize(15);
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(162, 207, 255);"));
        camera_choose = new QComboBox(groupBox_3);
        camera_choose->addItem(QString());
        camera_choose->addItem(QString());
        camera_choose->addItem(QString());
        camera_choose->addItem(QString());
        camera_choose->addItem(QString());
        camera_choose->addItem(QString());
        camera_choose->addItem(QString());
        camera_choose->addItem(QString());
        camera_choose->setObjectName(QString::fromUtf8("camera_choose"));
        camera_choose->setGeometry(QRect(20, 80, 101, 41));
        camera_choose->setFont(font1);
        camera_choose->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        updateimage_1 = new QPushButton(groupBox_3);
        updateimage_1->setObjectName(QString::fromUtf8("updateimage_1"));
        updateimage_1->setGeometry(QRect(20, 140, 101, 41));
        updateimage_1->setFont(font1);
        updateimage_1->setStyleSheet(QString::fromUtf8("background-color: rgb(182, 189, 174);\n"
"border-color: rgb(0, 0, 0);\n"
"\n"
"color: rgb(255, 255, 255);"));
        loadimage_1 = new QPushButton(groupBox_3);
        loadimage_1->setObjectName(QString::fromUtf8("loadimage_1"));
        loadimage_1->setGeometry(QRect(20, 200, 101, 41));
        loadimage_1->setFont(font1);
        loadimage_1->setStyleSheet(QString::fromUtf8("background-color: rgb(182, 189, 174);\n"
"\n"
"color: rgb(255, 255, 255);"));
        groupBox_4 = new QGroupBox(SettingMeasureForm);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(680, 300, 141, 161));
        trainmodel = new QPushButton(groupBox_4);
        trainmodel->setObjectName(QString::fromUtf8("trainmodel"));
        trainmodel->setGeometry(QRect(20, 40, 101, 41));
        trainmodel->setFont(font1);
        trainmodel->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 98);\n"
"color: rgb(255, 255, 255);"));
        modelmatch_1 = new QPushButton(groupBox_4);
        modelmatch_1->setObjectName(QString::fromUtf8("modelmatch_1"));
        modelmatch_1->setGeometry(QRect(20, 100, 101, 41));
        modelmatch_1->setFont(font1);
        modelmatch_1->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 98);\n"
"color: rgb(255, 255, 255);"));
        groupBox_5 = new QGroupBox(SettingMeasureForm);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(680, 490, 141, 231));
        spinBox = new QSpinBox(groupBox_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 60, 101, 41));
        spinBox->setFont(font1);
        erzhihua = new QPushButton(groupBox_5);
        erzhihua->setObjectName(QString::fromUtf8("erzhihua"));
        erzhihua->setGeometry(QRect(20, 170, 101, 41));
        erzhihua->setFont(font1);
        erzhihua->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 108);\n"
"color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(groupBox_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 20, 101, 22));
        spinBox_3 = new QSpinBox(groupBox_5);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(20, 120, 101, 41));
        spinBox_3->setFont(font1);
        groupBox_6 = new QGroupBox(SettingMeasureForm);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(850, 20, 161, 631));
        lineset_1 = new QPushButton(groupBox_6);
        lineset_1->setObjectName(QString::fromUtf8("lineset_1"));
        lineset_1->setGeometry(QRect(30, 580, 101, 41));
        lineset_1->setFont(font1);
        lineset_1->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88,118);\n"
"color: rgb(255, 255, 255);"));
        findline = new QPushButton(groupBox_6);
        findline->setObjectName(QString::fromUtf8("findline"));
        findline->setGeometry(QRect(30, 30, 101, 41));
        findline->setFont(font1);
        findline->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 118);\n"
"color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(groupBox_6);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 90, 121, 471));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        line_1_1 = new QRadioButton(layoutWidget);
        line_1_1->setObjectName(QString::fromUtf8("line_1_1"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line_1_1->sizePolicy().hasHeightForWidth());
        line_1_1->setSizePolicy(sizePolicy);
        line_1_1->setFont(font2);

        horizontalLayout->addWidget(line_1_1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        line_1_2 = new QRadioButton(layoutWidget);
        line_1_2->setObjectName(QString::fromUtf8("line_1_2"));
        sizePolicy.setHeightForWidth(line_1_2->sizePolicy().hasHeightForWidth());
        line_1_2->setSizePolicy(sizePolicy);
        line_1_2->setFont(font2);

        horizontalLayout_2->addWidget(line_1_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        line_1_3 = new QRadioButton(layoutWidget);
        line_1_3->setObjectName(QString::fromUtf8("line_1_3"));
        sizePolicy.setHeightForWidth(line_1_3->sizePolicy().hasHeightForWidth());
        line_1_3->setSizePolicy(sizePolicy);
        line_1_3->setFont(font2);

        horizontalLayout_3->addWidget(line_1_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        line_1_4 = new QRadioButton(layoutWidget);
        line_1_4->setObjectName(QString::fromUtf8("line_1_4"));
        sizePolicy.setHeightForWidth(line_1_4->sizePolicy().hasHeightForWidth());
        line_1_4->setSizePolicy(sizePolicy);
        line_1_4->setFont(font2);

        horizontalLayout_4->addWidget(line_1_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        line_1_5 = new QRadioButton(layoutWidget);
        line_1_5->setObjectName(QString::fromUtf8("line_1_5"));
        sizePolicy.setHeightForWidth(line_1_5->sizePolicy().hasHeightForWidth());
        line_1_5->setSizePolicy(sizePolicy);
        line_1_5->setFont(font2);

        horizontalLayout_5->addWidget(line_1_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        line_1_8 = new QRadioButton(layoutWidget);
        line_1_8->setObjectName(QString::fromUtf8("line_1_8"));
        sizePolicy.setHeightForWidth(line_1_8->sizePolicy().hasHeightForWidth());
        line_1_8->setSizePolicy(sizePolicy);
        line_1_8->setFont(font2);

        horizontalLayout_8->addWidget(line_1_8);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        line_1_9 = new QRadioButton(layoutWidget);
        line_1_9->setObjectName(QString::fromUtf8("line_1_9"));
        sizePolicy.setHeightForWidth(line_1_9->sizePolicy().hasHeightForWidth());
        line_1_9->setSizePolicy(sizePolicy);
        line_1_9->setFont(font2);

        horizontalLayout_9->addWidget(line_1_9);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        line_1_10 = new QRadioButton(layoutWidget);
        line_1_10->setObjectName(QString::fromUtf8("line_1_10"));
        sizePolicy.setHeightForWidth(line_1_10->sizePolicy().hasHeightForWidth());
        line_1_10->setSizePolicy(sizePolicy);
        line_1_10->setFont(font2);

        horizontalLayout_10->addWidget(line_1_10);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        line_1_11 = new QRadioButton(layoutWidget);
        line_1_11->setObjectName(QString::fromUtf8("line_1_11"));
        sizePolicy.setHeightForWidth(line_1_11->sizePolicy().hasHeightForWidth());
        line_1_11->setSizePolicy(sizePolicy);
        line_1_11->setFont(font2);

        horizontalLayout_11->addWidget(line_1_11);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        line_1_12 = new QRadioButton(layoutWidget);
        line_1_12->setObjectName(QString::fromUtf8("line_1_12"));
        sizePolicy.setHeightForWidth(line_1_12->sizePolicy().hasHeightForWidth());
        line_1_12->setSizePolicy(sizePolicy);
        line_1_12->setFont(font2);

        horizontalLayout_12->addWidget(line_1_12);


        verticalLayout->addLayout(horizontalLayout_12);

        groupBox_7 = new QGroupBox(SettingMeasureForm);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(1020, 20, 141, 221));
        groupBox_7->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        blob = new QPushButton(groupBox_7);
        blob->setObjectName(QString::fromUtf8("blob"));
        blob->setGeometry(QRect(20, 160, 101, 41));
        blob->setFont(font1);
        blob->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 138);\n"
"color: rgb(255, 255, 255);"));
        checkBox = new QCheckBox(groupBox_7);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 30, 101, 41));
        checkBox->setFont(font2);
        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 80, 34, 16));
        label_5->setFont(font2);
        blobmin = new QLineEdit(groupBox_7);
        blobmin->setObjectName(QString::fromUtf8("blobmin"));
        blobmin->setGeometry(QRect(40, 70, 91, 35));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(blobmin->sizePolicy().hasHeightForWidth());
        blobmin->setSizePolicy(sizePolicy1);
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 120, 34, 16));
        label_6->setFont(font2);
        blobmax = new QLineEdit(groupBox_7);
        blobmax->setObjectName(QString::fromUtf8("blobmax"));
        blobmax->setGeometry(QRect(40, 110, 91, 34));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(blobmax->sizePolicy().hasHeightForWidth());
        blobmax->setSizePolicy(sizePolicy2);
        groupBox_8 = new QGroupBox(SettingMeasureForm);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(1020, 280, 141, 191));
        checkBox_2 = new QCheckBox(groupBox_8);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 30, 111, 41));
        checkBox_2->setFont(font2);
        spinBox_2 = new QSpinBox(groupBox_8);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(20, 70, 101, 41));
        spinBox_2->setFont(font1);
        pixel = new QPushButton(groupBox_8);
        pixel->setObjectName(QString::fromUtf8("pixel"));
        pixel->setGeometry(QRect(20, 130, 101, 41));
        pixel->setFont(font1);
        pixel->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 148);\n"
"color: rgb(255, 255, 255);"));
        groupBox_9 = new QGroupBox(SettingMeasureForm);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(1190, 20, 211, 741));
        Log = new QTextBrowser(groupBox_9);
        Log->setObjectName(QString::fromUtf8("Log"));
        Log->setGeometry(QRect(10, 30, 191, 701));
        xihua = new QPushButton(SettingMeasureForm);
        xihua->setObjectName(QString::fromUtf8("xihua"));
        xihua->setGeometry(QRect(850, 700, 101, 41));
        xihua->setFont(font1);
        xihua->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 108);\n"
"color: rgb(255, 255, 255);"));
        zhixiandu = new QPushButton(SettingMeasureForm);
        zhixiandu->setObjectName(QString::fromUtf8("zhixiandu"));
        zhixiandu->setGeometry(QRect(1050, 700, 101, 41));
        zhixiandu->setFont(font1);
        zhixiandu->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 108);\n"
"color: rgb(255, 255, 255);"));
        checkBox_3 = new QCheckBox(SettingMeasureForm);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(970, 710, 71, 16));
        comboBox_2 = new QComboBox(SettingMeasureForm);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(860, 670, 101, 22));

        retranslateUi(SettingMeasureForm);

        tabWidget_2->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(SettingMeasureForm);
    } // setupUi

    void retranslateUi(QWidget *SettingMeasureForm)
    {
        SettingMeasureForm->setWindowTitle(QCoreApplication::translate("SettingMeasureForm", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("SettingMeasureForm", "MODEL", nullptr));
        setting->setText(QCoreApplication::translate("SettingMeasureForm", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingMeasureForm", "\345\233\276\345\203\217\346\230\276\347\244\272", nullptr));
        imageLabel->setText(QCoreApplication::translate("SettingMeasureForm", "TextLabel", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QCoreApplication::translate("SettingMeasureForm", "\346\272\220\345\233\276\345\203\217", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QCoreApplication::translate("SettingMeasureForm", "\345\214\271\351\205\215\345\233\276\345\203\217", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("SettingMeasureForm", "Blob\345\233\276\345\203\217", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("SettingMeasureForm", " \347\273\206\345\214\226\345\233\276\345\203\217", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QCoreApplication::translate("SettingMeasureForm", "\344\272\214\345\200\274\345\214\226\345\233\276\345\203\217", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingMeasureForm", "\346\250\241\346\235\277\345\233\276\345\203\217", nullptr));
        modellabel->setText(QCoreApplication::translate("SettingMeasureForm", "TextLabel", nullptr));
        setlabel_1->setText(QCoreApplication::translate("SettingMeasureForm", "TextLabel", nullptr));
        loadmodel_1->setText(QCoreApplication::translate("SettingMeasureForm", "\345\212\240\350\275\275\346\250\241\346\235\277", nullptr));
        setmodel_1->setText(QCoreApplication::translate("SettingMeasureForm", "\350\256\276\347\275\256\346\250\241\346\235\277", nullptr));
        savemodel_1->setText(QCoreApplication::translate("SettingMeasureForm", "\344\277\235\345\255\230\346\250\241\346\235\277", nullptr));
        label->setText(QCoreApplication::translate("SettingMeasureForm", "\345\275\223\345\211\215\346\250\241\346\235\277", nullptr));
        label_2->setText(QCoreApplication::translate("SettingMeasureForm", "\351\242\204\345\244\207\346\250\241\346\235\277", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SettingMeasureForm", "module-1", nullptr));
        label_4->setText(QCoreApplication::translate("SettingMeasureForm", "\351\200\211\346\213\251\347\233\270\346\234\272\345\233\276\345\203\217", nullptr));
        camera_choose->setItemText(0, QCoreApplication::translate("SettingMeasureForm", "1", nullptr));
        camera_choose->setItemText(1, QCoreApplication::translate("SettingMeasureForm", "2", nullptr));
        camera_choose->setItemText(2, QCoreApplication::translate("SettingMeasureForm", "3", nullptr));
        camera_choose->setItemText(3, QCoreApplication::translate("SettingMeasureForm", "4", nullptr));
        camera_choose->setItemText(4, QCoreApplication::translate("SettingMeasureForm", "5", nullptr));
        camera_choose->setItemText(5, QCoreApplication::translate("SettingMeasureForm", "6", nullptr));
        camera_choose->setItemText(6, QCoreApplication::translate("SettingMeasureForm", "7", nullptr));
        camera_choose->setItemText(7, QCoreApplication::translate("SettingMeasureForm", "8", nullptr));

        updateimage_1->setText(QCoreApplication::translate("SettingMeasureForm", "\346\233\264\346\226\260", nullptr));
        loadimage_1->setText(QCoreApplication::translate("SettingMeasureForm", "\345\212\240\350\275\275\345\233\276\345\203\217", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("SettingMeasureForm", "module-2", nullptr));
        trainmodel->setText(QCoreApplication::translate("SettingMeasureForm", "\350\256\255\347\273\203\346\250\241\346\235\277", nullptr));
        modelmatch_1->setText(QCoreApplication::translate("SettingMeasureForm", "\346\250\241\346\235\277\345\214\271\351\205\215", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("SettingMeasureForm", "module-3", nullptr));
        erzhihua->setText(QCoreApplication::translate("SettingMeasureForm", "\344\272\214\345\200\274\345\214\226", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SettingMeasureForm", "THRESH_BINARY", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SettingMeasureForm", "THRESH_BINARY_INV", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SettingMeasureForm", "THRESH_TRUNC", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("SettingMeasureForm", "THRESH_TOZERO", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("SettingMeasureForm", "THRESH_TOZERO_INV", nullptr));

        groupBox_6->setTitle(QCoreApplication::translate("SettingMeasureForm", "module-4", nullptr));
        lineset_1->setText(QCoreApplication::translate("SettingMeasureForm", "\350\256\276\347\275\256", nullptr));
        findline->setText(QCoreApplication::translate("SettingMeasureForm", "\346\211\276\347\272\277\345\267\245\345\205\267", nullptr));
        line_1_1->setText(QCoreApplication::translate("SettingMeasureForm", "  line_1", nullptr));
        line_1_2->setText(QCoreApplication::translate("SettingMeasureForm", "  line_2", nullptr));
        line_1_3->setText(QCoreApplication::translate("SettingMeasureForm", "  line_3", nullptr));
        line_1_4->setText(QCoreApplication::translate("SettingMeasureForm", "  line_4", nullptr));
        line_1_5->setText(QCoreApplication::translate("SettingMeasureForm", "  line_5", nullptr));
        line_1_8->setText(QCoreApplication::translate("SettingMeasureForm", "  line_6", nullptr));
        line_1_9->setText(QCoreApplication::translate("SettingMeasureForm", "  line_7", nullptr));
        line_1_10->setText(QCoreApplication::translate("SettingMeasureForm", "  line_8", nullptr));
        line_1_11->setText(QCoreApplication::translate("SettingMeasureForm", "  line_9", nullptr));
        line_1_12->setText(QCoreApplication::translate("SettingMeasureForm", "  line_10", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("SettingMeasureForm", "module-5", nullptr));
        blob->setText(QCoreApplication::translate("SettingMeasureForm", "Blob", nullptr));
        checkBox->setText(QCoreApplication::translate("SettingMeasureForm", "\344\272\214\345\200\274\345\214\226\345\233\276\345\203\217", nullptr));
        label_5->setText(QCoreApplication::translate("SettingMeasureForm", "MIN:", nullptr));
        label_6->setText(QCoreApplication::translate("SettingMeasureForm", "MAX:", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("SettingMeasureForm", "module-6", nullptr));
        checkBox_2->setText(QCoreApplication::translate("SettingMeasureForm", "\346\210\252\345\217\226\345\233\276\345\203\217", nullptr));
        pixel->setText(QCoreApplication::translate("SettingMeasureForm", "\345\203\217\347\264\240\347\273\237\350\256\241", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("SettingMeasureForm", "Log", nullptr));
        xihua->setText(QCoreApplication::translate("SettingMeasureForm", " \345\233\276\345\203\217\347\273\206\345\214\226", nullptr));
        zhixiandu->setText(QCoreApplication::translate("SettingMeasureForm", "\347\233\264\347\272\277\345\272\246", nullptr));
        checkBox_3->setText(QCoreApplication::translate("SettingMeasureForm", "\346\230\276\347\244\272\345\216\237\345\233\276", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("SettingMeasureForm", "THRESH_BINARY", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("SettingMeasureForm", "THRESH_BINARY_INV", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SettingMeasureForm: public Ui_SettingMeasureForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGMEASUREFORM_H
