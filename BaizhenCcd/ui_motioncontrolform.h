/********************************************************************************
** Form generated from reading UI file 'motioncontrolform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTIONCONTROLFORM_H
#define UI_MOTIONCONTROLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotionControlForm
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_163;
    QLineEdit *lineEdit_command_location_2;
    QLineEdit *lineEdit_actual_position_2;
    QLineEdit *lineEdit_command_speed_2;
    QPushButton *btn_axis_gohome_2;
    QPushButton *btn_axis_stop_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_167;
    QLineEdit *lineEdit_command_location_6;
    QLineEdit *lineEdit_actual_position_6;
    QLineEdit *lineEdit_command_speed_6;
    QPushButton *btn_axis_gohome_6;
    QPushButton *btn_axis_stop_6;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_58;
    QPushButton *btn_axis_increase_1;
    QPushButton *btn_axis_decrease_1;
    QVBoxLayout *verticalLayout_63;
    QLabel *label_134;
    QLabel *label_135;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEdit_axis_relative_distance_1;
    QLineEdit *lineEdit_axis_relative_time_1;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_60;
    QPushButton *btn_axis_increase_2;
    QPushButton *btn_axis_decrease_2;
    QVBoxLayout *verticalLayout_66;
    QLabel *label_136;
    QLabel *label_137;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *lineEdit_axis_relative_distance_2;
    QLineEdit *lineEdit_axis_relative_time_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_144;
    QLabel *label_145;
    QLabel *label_146;
    QLabel *label_147;
    QLabel *label_148;
    QLabel *label_149;
    QLabel *label_150;
    QLabel *label_152;
    QLabel *label_151;
    QVBoxLayout *verticalLayout_14;
    QComboBox *comboBox_axis_choose;
    QLineEdit *lineEdit_info_channel;
    QLineEdit *lineEdit_info_sensor_name;
    QLineEdit *lineEdit_info_fractional_number;
    QLineEdit *lineEdit_info_range_up;
    QLineEdit *lineEdit_info_range_down;
    QLineEdit *lineEdit_info_sensor_unit;
    QComboBox *comboBox_info_filtering_choose;
    QLineEdit *lineEdit_info_filtering_number;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_info_set;
    QSpacerItem *horizontalSpacer_18;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QTableWidget *tableWidget;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_91;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLCDNumber *lcd_coor_2;
    QVBoxLayout *verticalLayout_51;
    QPushButton *btn_AxisEnable_2;
    QPushButton *btn_AxisStatus_2;
    QHBoxLayout *horizontalLayout_92;
    QHBoxLayout *horizontalLayout_87;
    QLabel *label_128;
    QLCDNumber *lcd_coor_6;
    QVBoxLayout *verticalLayout_52;
    QPushButton *btn_AxisEnable_6;
    QPushButton *btn_AxisStatus_6;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_power_off;
    QPushButton *pushButton_clear_error_all;
    QPushButton *pushButton_disable_all;
    QPushButton *pushButton_load;
    QPushButton *pushButton_enable_all;
    QPushButton *pushButton_power_on_off;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_142;
    QLabel *label_143;
    QLabel *label_power_onoff;
    QLabel *label_196;
    QLabel *label_197;
    QLabel *label_load;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_116;
    QVBoxLayout *verticalLayout_64;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_198;
    QLineEdit *lineEdit_axis_allmove_time;
    QLabel *label_206;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_176;
    QLineEdit *lineEdit_axis_move_distance_1;
    QCheckBox *checkBox_axis_move_distance_1;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_181;
    QLineEdit *lineEdit_axis_move_distance_2;
    QCheckBox *checkBox_axis_move_distance_2;
    QVBoxLayout *verticalLayout_65;
    QPushButton *pushButton_allaxis_move;
    QPushButton *pushButton_allaxis_stop;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MotionControlForm)
    {
        if (MotionControlForm->objectName().isEmpty())
            MotionControlForm->setObjectName(QString::fromUtf8("MotionControlForm"));
        MotionControlForm->resize(1141, 726);
        centralwidget = new QWidget(MotionControlForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 580, 1121, 111));
        layoutWidget1 = new QWidget(groupBox_8);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 1101, 84));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_163 = new QLabel(layoutWidget1);
        label_163->setObjectName(QString::fromUtf8("label_163"));
        label_163->setMinimumSize(QSize(100, 36));
        label_163->setMaximumSize(QSize(100, 36));
        label_163->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_163);

        lineEdit_command_location_2 = new QLineEdit(layoutWidget1);
        lineEdit_command_location_2->setObjectName(QString::fromUtf8("lineEdit_command_location_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_command_location_2->sizePolicy().hasHeightForWidth());
        lineEdit_command_location_2->setSizePolicy(sizePolicy);
        lineEdit_command_location_2->setMinimumSize(QSize(160, 36));
        lineEdit_command_location_2->setMaximumSize(QSize(160, 36));

        horizontalLayout_2->addWidget(lineEdit_command_location_2);

        lineEdit_actual_position_2 = new QLineEdit(layoutWidget1);
        lineEdit_actual_position_2->setObjectName(QString::fromUtf8("lineEdit_actual_position_2"));
        sizePolicy.setHeightForWidth(lineEdit_actual_position_2->sizePolicy().hasHeightForWidth());
        lineEdit_actual_position_2->setSizePolicy(sizePolicy);
        lineEdit_actual_position_2->setMinimumSize(QSize(160, 36));
        lineEdit_actual_position_2->setMaximumSize(QSize(160, 36));

        horizontalLayout_2->addWidget(lineEdit_actual_position_2);

        lineEdit_command_speed_2 = new QLineEdit(layoutWidget1);
        lineEdit_command_speed_2->setObjectName(QString::fromUtf8("lineEdit_command_speed_2"));
        sizePolicy.setHeightForWidth(lineEdit_command_speed_2->sizePolicy().hasHeightForWidth());
        lineEdit_command_speed_2->setSizePolicy(sizePolicy);
        lineEdit_command_speed_2->setMinimumSize(QSize(160, 36));
        lineEdit_command_speed_2->setMaximumSize(QSize(160, 36));

        horizontalLayout_2->addWidget(lineEdit_command_speed_2);

        btn_axis_gohome_2 = new QPushButton(layoutWidget1);
        btn_axis_gohome_2->setObjectName(QString::fromUtf8("btn_axis_gohome_2"));
        btn_axis_gohome_2->setMinimumSize(QSize(100, 36));
        btn_axis_gohome_2->setMaximumSize(QSize(100, 36));

        horizontalLayout_2->addWidget(btn_axis_gohome_2);

        btn_axis_stop_2 = new QPushButton(layoutWidget1);
        btn_axis_stop_2->setObjectName(QString::fromUtf8("btn_axis_stop_2"));
        btn_axis_stop_2->setMinimumSize(QSize(100, 36));
        btn_axis_stop_2->setMaximumSize(QSize(100, 36));

        horizontalLayout_2->addWidget(btn_axis_stop_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_167 = new QLabel(layoutWidget1);
        label_167->setObjectName(QString::fromUtf8("label_167"));
        label_167->setMinimumSize(QSize(100, 36));
        label_167->setMaximumSize(QSize(100, 36));
        label_167->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_167);

        lineEdit_command_location_6 = new QLineEdit(layoutWidget1);
        lineEdit_command_location_6->setObjectName(QString::fromUtf8("lineEdit_command_location_6"));
        sizePolicy.setHeightForWidth(lineEdit_command_location_6->sizePolicy().hasHeightForWidth());
        lineEdit_command_location_6->setSizePolicy(sizePolicy);
        lineEdit_command_location_6->setMinimumSize(QSize(160, 36));
        lineEdit_command_location_6->setMaximumSize(QSize(160, 36));

        horizontalLayout_4->addWidget(lineEdit_command_location_6);

        lineEdit_actual_position_6 = new QLineEdit(layoutWidget1);
        lineEdit_actual_position_6->setObjectName(QString::fromUtf8("lineEdit_actual_position_6"));
        sizePolicy.setHeightForWidth(lineEdit_actual_position_6->sizePolicy().hasHeightForWidth());
        lineEdit_actual_position_6->setSizePolicy(sizePolicy);
        lineEdit_actual_position_6->setMinimumSize(QSize(160, 36));
        lineEdit_actual_position_6->setMaximumSize(QSize(160, 36));

        horizontalLayout_4->addWidget(lineEdit_actual_position_6);

        lineEdit_command_speed_6 = new QLineEdit(layoutWidget1);
        lineEdit_command_speed_6->setObjectName(QString::fromUtf8("lineEdit_command_speed_6"));
        sizePolicy.setHeightForWidth(lineEdit_command_speed_6->sizePolicy().hasHeightForWidth());
        lineEdit_command_speed_6->setSizePolicy(sizePolicy);
        lineEdit_command_speed_6->setMinimumSize(QSize(160, 36));
        lineEdit_command_speed_6->setMaximumSize(QSize(160, 36));

        horizontalLayout_4->addWidget(lineEdit_command_speed_6);

        btn_axis_gohome_6 = new QPushButton(layoutWidget1);
        btn_axis_gohome_6->setObjectName(QString::fromUtf8("btn_axis_gohome_6"));
        btn_axis_gohome_6->setMinimumSize(QSize(100, 36));
        btn_axis_gohome_6->setMaximumSize(QSize(100, 36));

        horizontalLayout_4->addWidget(btn_axis_gohome_6);

        btn_axis_stop_6 = new QPushButton(layoutWidget1);
        btn_axis_stop_6->setObjectName(QString::fromUtf8("btn_axis_stop_6"));
        btn_axis_stop_6->setMinimumSize(QSize(100, 36));
        btn_axis_stop_6->setMaximumSize(QSize(100, 36));

        horizontalLayout_4->addWidget(btn_axis_stop_6);


        verticalLayout_3->addLayout(horizontalLayout_4);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(410, 11, 721, 561));
        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 341, 112));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_58 = new QVBoxLayout();
        verticalLayout_58->setObjectName(QString::fromUtf8("verticalLayout_58"));
        btn_axis_increase_1 = new QPushButton(groupBox);
        btn_axis_increase_1->setObjectName(QString::fromUtf8("btn_axis_increase_1"));
        btn_axis_increase_1->setMinimumSize(QSize(80, 36));
        btn_axis_increase_1->setMaximumSize(QSize(80, 36));

        verticalLayout_58->addWidget(btn_axis_increase_1);

        btn_axis_decrease_1 = new QPushButton(groupBox);
        btn_axis_decrease_1->setObjectName(QString::fromUtf8("btn_axis_decrease_1"));
        btn_axis_decrease_1->setMinimumSize(QSize(80, 36));
        btn_axis_decrease_1->setMaximumSize(QSize(80, 36));

        verticalLayout_58->addWidget(btn_axis_decrease_1);


        gridLayout_2->addLayout(verticalLayout_58, 0, 0, 1, 1);

        verticalLayout_63 = new QVBoxLayout();
        verticalLayout_63->setObjectName(QString::fromUtf8("verticalLayout_63"));
        label_134 = new QLabel(groupBox);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        label_134->setMinimumSize(QSize(100, 36));
        label_134->setMaximumSize(QSize(100, 36));
        label_134->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_63->addWidget(label_134);

        label_135 = new QLabel(groupBox);
        label_135->setObjectName(QString::fromUtf8("label_135"));
        label_135->setMinimumSize(QSize(0, 36));
        label_135->setMaximumSize(QSize(16777215, 36));
        label_135->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_63->addWidget(label_135);


        gridLayout_2->addLayout(verticalLayout_63, 0, 1, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lineEdit_axis_relative_distance_1 = new QLineEdit(groupBox);
        lineEdit_axis_relative_distance_1->setObjectName(QString::fromUtf8("lineEdit_axis_relative_distance_1"));
        sizePolicy.setHeightForWidth(lineEdit_axis_relative_distance_1->sizePolicy().hasHeightForWidth());
        lineEdit_axis_relative_distance_1->setSizePolicy(sizePolicy);
        lineEdit_axis_relative_distance_1->setMinimumSize(QSize(120, 36));
        lineEdit_axis_relative_distance_1->setMaximumSize(QSize(120, 36));

        verticalLayout_9->addWidget(lineEdit_axis_relative_distance_1);

        lineEdit_axis_relative_time_1 = new QLineEdit(groupBox);
        lineEdit_axis_relative_time_1->setObjectName(QString::fromUtf8("lineEdit_axis_relative_time_1"));
        sizePolicy.setHeightForWidth(lineEdit_axis_relative_time_1->sizePolicy().hasHeightForWidth());
        lineEdit_axis_relative_time_1->setSizePolicy(sizePolicy);
        lineEdit_axis_relative_time_1->setMinimumSize(QSize(120, 36));
        lineEdit_axis_relative_time_1->setMaximumSize(QSize(120, 36));

        verticalLayout_9->addWidget(lineEdit_axis_relative_time_1);


        gridLayout_2->addLayout(verticalLayout_9, 0, 2, 1, 1);

        groupBox_12 = new QGroupBox(groupBox_4);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(370, 20, 338, 112));
        gridLayout = new QGridLayout(groupBox_12);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_60 = new QVBoxLayout();
        verticalLayout_60->setObjectName(QString::fromUtf8("verticalLayout_60"));
        btn_axis_increase_2 = new QPushButton(groupBox_12);
        btn_axis_increase_2->setObjectName(QString::fromUtf8("btn_axis_increase_2"));
        btn_axis_increase_2->setMinimumSize(QSize(80, 36));
        btn_axis_increase_2->setMaximumSize(QSize(80, 36));

        verticalLayout_60->addWidget(btn_axis_increase_2);

        btn_axis_decrease_2 = new QPushButton(groupBox_12);
        btn_axis_decrease_2->setObjectName(QString::fromUtf8("btn_axis_decrease_2"));
        btn_axis_decrease_2->setMinimumSize(QSize(80, 36));
        btn_axis_decrease_2->setMaximumSize(QSize(80, 36));

        verticalLayout_60->addWidget(btn_axis_decrease_2);


        gridLayout->addLayout(verticalLayout_60, 0, 0, 1, 1);

        verticalLayout_66 = new QVBoxLayout();
        verticalLayout_66->setObjectName(QString::fromUtf8("verticalLayout_66"));
        label_136 = new QLabel(groupBox_12);
        label_136->setObjectName(QString::fromUtf8("label_136"));
        label_136->setMinimumSize(QSize(100, 36));
        label_136->setMaximumSize(QSize(100, 36));
        label_136->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_66->addWidget(label_136);

        label_137 = new QLabel(groupBox_12);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        label_137->setMinimumSize(QSize(0, 36));
        label_137->setMaximumSize(QSize(16777215, 36));
        label_137->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_66->addWidget(label_137);


        gridLayout->addLayout(verticalLayout_66, 0, 1, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        lineEdit_axis_relative_distance_2 = new QLineEdit(groupBox_12);
        lineEdit_axis_relative_distance_2->setObjectName(QString::fromUtf8("lineEdit_axis_relative_distance_2"));
        sizePolicy.setHeightForWidth(lineEdit_axis_relative_distance_2->sizePolicy().hasHeightForWidth());
        lineEdit_axis_relative_distance_2->setSizePolicy(sizePolicy);
        lineEdit_axis_relative_distance_2->setMinimumSize(QSize(120, 36));
        lineEdit_axis_relative_distance_2->setMaximumSize(QSize(120, 36));

        verticalLayout_10->addWidget(lineEdit_axis_relative_distance_2);

        lineEdit_axis_relative_time_2 = new QLineEdit(groupBox_12);
        lineEdit_axis_relative_time_2->setObjectName(QString::fromUtf8("lineEdit_axis_relative_time_2"));
        sizePolicy.setHeightForWidth(lineEdit_axis_relative_time_2->sizePolicy().hasHeightForWidth());
        lineEdit_axis_relative_time_2->setSizePolicy(sizePolicy);
        lineEdit_axis_relative_time_2->setMinimumSize(QSize(120, 36));
        lineEdit_axis_relative_time_2->setMaximumSize(QSize(120, 36));

        verticalLayout_10->addWidget(lineEdit_axis_relative_time_2);


        gridLayout->addLayout(verticalLayout_10, 0, 2, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 150, 341, 401));
        gridLayout_7 = new QGridLayout(groupBox_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_144 = new QLabel(groupBox_6);
        label_144->setObjectName(QString::fromUtf8("label_144"));
        label_144->setMinimumSize(QSize(80, 36));
        label_144->setMaximumSize(QSize(16777215, 36));
        label_144->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_144);

        label_145 = new QLabel(groupBox_6);
        label_145->setObjectName(QString::fromUtf8("label_145"));
        label_145->setMinimumSize(QSize(0, 36));
        label_145->setMaximumSize(QSize(16777215, 36));
        label_145->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_145);

        label_146 = new QLabel(groupBox_6);
        label_146->setObjectName(QString::fromUtf8("label_146"));
        label_146->setMinimumSize(QSize(0, 36));
        label_146->setMaximumSize(QSize(16777215, 36));
        label_146->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_146);

        label_147 = new QLabel(groupBox_6);
        label_147->setObjectName(QString::fromUtf8("label_147"));
        label_147->setMinimumSize(QSize(0, 36));
        label_147->setMaximumSize(QSize(16777215, 36));
        label_147->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_147);

        label_148 = new QLabel(groupBox_6);
        label_148->setObjectName(QString::fromUtf8("label_148"));
        label_148->setMinimumSize(QSize(0, 36));
        label_148->setMaximumSize(QSize(16777215, 36));
        label_148->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_148);

        label_149 = new QLabel(groupBox_6);
        label_149->setObjectName(QString::fromUtf8("label_149"));
        label_149->setMinimumSize(QSize(0, 36));
        label_149->setMaximumSize(QSize(16777215, 36));
        label_149->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_149);

        label_150 = new QLabel(groupBox_6);
        label_150->setObjectName(QString::fromUtf8("label_150"));
        label_150->setMinimumSize(QSize(0, 36));
        label_150->setMaximumSize(QSize(16777215, 36));
        label_150->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_150);

        label_152 = new QLabel(groupBox_6);
        label_152->setObjectName(QString::fromUtf8("label_152"));
        label_152->setMinimumSize(QSize(0, 36));
        label_152->setMaximumSize(QSize(16777215, 36));
        label_152->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_152);

        label_151 = new QLabel(groupBox_6);
        label_151->setObjectName(QString::fromUtf8("label_151"));
        label_151->setMinimumSize(QSize(0, 36));
        label_151->setMaximumSize(QSize(16777215, 36));
        label_151->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(label_151);


        horizontalLayout_8->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        comboBox_axis_choose = new QComboBox(groupBox_6);
        comboBox_axis_choose->addItem(QString());
        comboBox_axis_choose->addItem(QString());
        comboBox_axis_choose->setObjectName(QString::fromUtf8("comboBox_axis_choose"));
        comboBox_axis_choose->setMinimumSize(QSize(200, 36));
        comboBox_axis_choose->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(comboBox_axis_choose);

        lineEdit_info_channel = new QLineEdit(groupBox_6);
        lineEdit_info_channel->setObjectName(QString::fromUtf8("lineEdit_info_channel"));
        sizePolicy.setHeightForWidth(lineEdit_info_channel->sizePolicy().hasHeightForWidth());
        lineEdit_info_channel->setSizePolicy(sizePolicy);
        lineEdit_info_channel->setMinimumSize(QSize(0, 36));
        lineEdit_info_channel->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(lineEdit_info_channel);

        lineEdit_info_sensor_name = new QLineEdit(groupBox_6);
        lineEdit_info_sensor_name->setObjectName(QString::fromUtf8("lineEdit_info_sensor_name"));
        sizePolicy.setHeightForWidth(lineEdit_info_sensor_name->sizePolicy().hasHeightForWidth());
        lineEdit_info_sensor_name->setSizePolicy(sizePolicy);
        lineEdit_info_sensor_name->setMinimumSize(QSize(0, 36));
        lineEdit_info_sensor_name->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(lineEdit_info_sensor_name);

        lineEdit_info_fractional_number = new QLineEdit(groupBox_6);
        lineEdit_info_fractional_number->setObjectName(QString::fromUtf8("lineEdit_info_fractional_number"));
        sizePolicy.setHeightForWidth(lineEdit_info_fractional_number->sizePolicy().hasHeightForWidth());
        lineEdit_info_fractional_number->setSizePolicy(sizePolicy);
        lineEdit_info_fractional_number->setMinimumSize(QSize(0, 36));
        lineEdit_info_fractional_number->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(lineEdit_info_fractional_number);

        lineEdit_info_range_up = new QLineEdit(groupBox_6);
        lineEdit_info_range_up->setObjectName(QString::fromUtf8("lineEdit_info_range_up"));
        sizePolicy.setHeightForWidth(lineEdit_info_range_up->sizePolicy().hasHeightForWidth());
        lineEdit_info_range_up->setSizePolicy(sizePolicy);
        lineEdit_info_range_up->setMinimumSize(QSize(0, 36));
        lineEdit_info_range_up->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(lineEdit_info_range_up);

        lineEdit_info_range_down = new QLineEdit(groupBox_6);
        lineEdit_info_range_down->setObjectName(QString::fromUtf8("lineEdit_info_range_down"));
        sizePolicy.setHeightForWidth(lineEdit_info_range_down->sizePolicy().hasHeightForWidth());
        lineEdit_info_range_down->setSizePolicy(sizePolicy);
        lineEdit_info_range_down->setMinimumSize(QSize(0, 36));
        lineEdit_info_range_down->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(lineEdit_info_range_down);

        lineEdit_info_sensor_unit = new QLineEdit(groupBox_6);
        lineEdit_info_sensor_unit->setObjectName(QString::fromUtf8("lineEdit_info_sensor_unit"));
        sizePolicy.setHeightForWidth(lineEdit_info_sensor_unit->sizePolicy().hasHeightForWidth());
        lineEdit_info_sensor_unit->setSizePolicy(sizePolicy);
        lineEdit_info_sensor_unit->setMinimumSize(QSize(0, 36));
        lineEdit_info_sensor_unit->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(lineEdit_info_sensor_unit);

        comboBox_info_filtering_choose = new QComboBox(groupBox_6);
        comboBox_info_filtering_choose->setObjectName(QString::fromUtf8("comboBox_info_filtering_choose"));
        comboBox_info_filtering_choose->setMinimumSize(QSize(0, 36));
        comboBox_info_filtering_choose->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(comboBox_info_filtering_choose);

        lineEdit_info_filtering_number = new QLineEdit(groupBox_6);
        lineEdit_info_filtering_number->setObjectName(QString::fromUtf8("lineEdit_info_filtering_number"));
        sizePolicy.setHeightForWidth(lineEdit_info_filtering_number->sizePolicy().hasHeightForWidth());
        lineEdit_info_filtering_number->setSizePolicy(sizePolicy);
        lineEdit_info_filtering_number->setMinimumSize(QSize(0, 36));
        lineEdit_info_filtering_number->setMaximumSize(QSize(16777215, 36));

        verticalLayout_14->addWidget(lineEdit_info_filtering_number);


        horizontalLayout_8->addLayout(verticalLayout_14);

        horizontalLayout_8->setStretch(0, 2);
        horizontalLayout_8->setStretch(1, 20);

        verticalLayout_12->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        pushButton_info_set = new QPushButton(groupBox_6);
        pushButton_info_set->setObjectName(QString::fromUtf8("pushButton_info_set"));
        pushButton_info_set->setMinimumSize(QSize(100, 36));
        pushButton_info_set->setMaximumSize(QSize(100, 36));

        horizontalLayout_9->addWidget(pushButton_info_set);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_18);


        verticalLayout_12->addLayout(horizontalLayout_9);


        gridLayout_7->addLayout(verticalLayout_12, 0, 0, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(370, 150, 341, 401));
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableWidget = new QTableWidget(groupBox_7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_6->addWidget(tableWidget, 0, 0, 1, 1);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 12, 391, 561));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, 5, 5);
        groupBox_2 = new QGroupBox(layoutWidget3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget4 = new QWidget(groupBox_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 10, 361, 172));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_91 = new QHBoxLayout();
        horizontalLayout_91->setObjectName(QString::fromUtf8("horizontalLayout_91"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(100, 48));
        label_2->setMaximumSize(QSize(100, 48));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        lcd_coor_2 = new QLCDNumber(layoutWidget4);
        lcd_coor_2->setObjectName(QString::fromUtf8("lcd_coor_2"));
        lcd_coor_2->setMinimumSize(QSize(120, 48));
        lcd_coor_2->setMaximumSize(QSize(16777215, 48));
        lcd_coor_2->setFocusPolicy(Qt::NoFocus);
        lcd_coor_2->setLayoutDirection(Qt::LeftToRight);
        lcd_coor_2->setFrameShape(QFrame::WinPanel);
        lcd_coor_2->setFrameShadow(QFrame::Sunken);
        lcd_coor_2->setDigitCount(10);
        lcd_coor_2->setProperty("value", QVariant(0.000000000000000));

        horizontalLayout_3->addWidget(lcd_coor_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);

        horizontalLayout_91->addLayout(horizontalLayout_3);

        verticalLayout_51 = new QVBoxLayout();
        verticalLayout_51->setObjectName(QString::fromUtf8("verticalLayout_51"));
        btn_AxisEnable_2 = new QPushButton(layoutWidget4);
        btn_AxisEnable_2->setObjectName(QString::fromUtf8("btn_AxisEnable_2"));
        btn_AxisEnable_2->setMinimumSize(QSize(24, 24));
        btn_AxisEnable_2->setMaximumSize(QSize(24, 24));
        btn_AxisEnable_2->setCheckable(true);

        verticalLayout_51->addWidget(btn_AxisEnable_2);

        btn_AxisStatus_2 = new QPushButton(layoutWidget4);
        btn_AxisStatus_2->setObjectName(QString::fromUtf8("btn_AxisStatus_2"));
        btn_AxisStatus_2->setMinimumSize(QSize(24, 24));
        btn_AxisStatus_2->setMaximumSize(QSize(24, 24));

        verticalLayout_51->addWidget(btn_AxisStatus_2);


        horizontalLayout_91->addLayout(verticalLayout_51);

        horizontalLayout_91->setStretch(0, 100);
        horizontalLayout_91->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_91);

        horizontalLayout_92 = new QHBoxLayout();
        horizontalLayout_92->setObjectName(QString::fromUtf8("horizontalLayout_92"));
        horizontalLayout_87 = new QHBoxLayout();
        horizontalLayout_87->setObjectName(QString::fromUtf8("horizontalLayout_87"));
        label_128 = new QLabel(layoutWidget4);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        label_128->setMinimumSize(QSize(100, 48));
        label_128->setMaximumSize(QSize(100, 48));
        label_128->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_87->addWidget(label_128);

        lcd_coor_6 = new QLCDNumber(layoutWidget4);
        lcd_coor_6->setObjectName(QString::fromUtf8("lcd_coor_6"));
        lcd_coor_6->setMinimumSize(QSize(120, 48));
        lcd_coor_6->setMaximumSize(QSize(16777215, 48));
        lcd_coor_6->setFrameShape(QFrame::WinPanel);
        lcd_coor_6->setFrameShadow(QFrame::Sunken);
        lcd_coor_6->setDigitCount(10);
        lcd_coor_6->setProperty("value", QVariant(0.000000000000000));

        horizontalLayout_87->addWidget(lcd_coor_6);


        horizontalLayout_92->addLayout(horizontalLayout_87);

        verticalLayout_52 = new QVBoxLayout();
        verticalLayout_52->setObjectName(QString::fromUtf8("verticalLayout_52"));
        btn_AxisEnable_6 = new QPushButton(layoutWidget4);
        btn_AxisEnable_6->setObjectName(QString::fromUtf8("btn_AxisEnable_6"));
        btn_AxisEnable_6->setMinimumSize(QSize(24, 24));
        btn_AxisEnable_6->setMaximumSize(QSize(24, 24));
        btn_AxisEnable_6->setCheckable(true);

        verticalLayout_52->addWidget(btn_AxisEnable_6);

        btn_AxisStatus_6 = new QPushButton(layoutWidget4);
        btn_AxisStatus_6->setObjectName(QString::fromUtf8("btn_AxisStatus_6"));
        btn_AxisStatus_6->setMinimumSize(QSize(24, 24));
        btn_AxisStatus_6->setMaximumSize(QSize(24, 24));

        verticalLayout_52->addWidget(btn_AxisStatus_6);


        horizontalLayout_92->addLayout(verticalLayout_52);

        horizontalLayout_92->setStretch(0, 100);
        horizontalLayout_92->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_92);


        verticalLayout_6->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        pushButton_power_off = new QPushButton(groupBox_3);
        pushButton_power_off->setObjectName(QString::fromUtf8("pushButton_power_off"));
        pushButton_power_off->setGeometry(QRect(34, 78, 100, 40));
        pushButton_power_off->setMinimumSize(QSize(100, 40));
        pushButton_power_off->setMaximumSize(QSize(200, 40));
        pushButton_power_off->setCheckable(false);
        pushButton_clear_error_all = new QPushButton(groupBox_3);
        pushButton_clear_error_all->setObjectName(QString::fromUtf8("pushButton_clear_error_all"));
        pushButton_clear_error_all->setGeometry(QRect(140, 78, 100, 40));
        pushButton_clear_error_all->setMinimumSize(QSize(100, 40));
        pushButton_clear_error_all->setMaximumSize(QSize(200, 40));
        pushButton_disable_all = new QPushButton(groupBox_3);
        pushButton_disable_all->setObjectName(QString::fromUtf8("pushButton_disable_all"));
        pushButton_disable_all->setGeometry(QRect(246, 78, 100, 40));
        pushButton_disable_all->setMinimumSize(QSize(100, 40));
        pushButton_disable_all->setMaximumSize(QSize(200, 40));
        pushButton_disable_all->setCheckable(false);
        pushButton_load = new QPushButton(groupBox_3);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setGeometry(QRect(140, 30, 100, 40));
        pushButton_load->setMinimumSize(QSize(100, 40));
        pushButton_load->setMaximumSize(QSize(200, 40));
        pushButton_enable_all = new QPushButton(groupBox_3);
        pushButton_enable_all->setObjectName(QString::fromUtf8("pushButton_enable_all"));
        pushButton_enable_all->setGeometry(QRect(246, 30, 100, 40));
        pushButton_enable_all->setMinimumSize(QSize(100, 40));
        pushButton_enable_all->setMaximumSize(QSize(200, 40));
        pushButton_enable_all->setCheckable(false);
        pushButton_power_on_off = new QPushButton(groupBox_3);
        pushButton_power_on_off->setObjectName(QString::fromUtf8("pushButton_power_on_off"));
        pushButton_power_on_off->setGeometry(QRect(34, 30, 100, 40));
        pushButton_power_on_off->setMinimumSize(QSize(100, 40));
        pushButton_power_on_off->setMaximumSize(QSize(200, 40));
        pushButton_power_on_off->setCheckable(false);
        layoutWidget_3 = new QWidget(groupBox_3);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(40, 140, 307, 38));
        horizontalLayout_142 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_142->setObjectName(QString::fromUtf8("horizontalLayout_142"));
        horizontalLayout_142->setContentsMargins(0, 0, 0, 0);
        label_143 = new QLabel(layoutWidget_3);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        label_143->setMinimumSize(QSize(100, 36));
        label_143->setMaximumSize(QSize(100, 36));
        label_143->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_142->addWidget(label_143);

        label_power_onoff = new QLabel(layoutWidget_3);
        label_power_onoff->setObjectName(QString::fromUtf8("label_power_onoff"));
        label_power_onoff->setMinimumSize(QSize(36, 36));
        label_power_onoff->setMaximumSize(QSize(36, 36));
        label_power_onoff->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout_142->addWidget(label_power_onoff);

        label_196 = new QLabel(layoutWidget_3);
        label_196->setObjectName(QString::fromUtf8("label_196"));
        label_196->setMinimumSize(QSize(0, 36));
        label_196->setMaximumSize(QSize(16777215, 36));

        horizontalLayout_142->addWidget(label_196);

        label_197 = new QLabel(layoutWidget_3);
        label_197->setObjectName(QString::fromUtf8("label_197"));
        label_197->setMinimumSize(QSize(100, 36));
        label_197->setMaximumSize(QSize(100, 36));
        label_197->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_142->addWidget(label_197);

        label_load = new QLabel(layoutWidget_3);
        label_load->setObjectName(QString::fromUtf8("label_load"));
        label_load->setMinimumSize(QSize(36, 36));
        label_load->setMaximumSize(QSize(36, 36));
        label_load->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout_142->addWidget(label_load);


        verticalLayout_6->addWidget(groupBox_3);

        verticalLayout_6->setStretch(0, 10);
        verticalLayout_6->setStretch(1, 11);

        verticalLayout_5->addLayout(verticalLayout_6);

        groupBox_5 = new QGroupBox(layoutWidget3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_116 = new QHBoxLayout();
        horizontalLayout_116->setObjectName(QString::fromUtf8("horizontalLayout_116"));
        verticalLayout_64 = new QVBoxLayout();
        verticalLayout_64->setObjectName(QString::fromUtf8("verticalLayout_64"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_198 = new QLabel(groupBox_5);
        label_198->setObjectName(QString::fromUtf8("label_198"));
        label_198->setMinimumSize(QSize(88, 36));
        label_198->setMaximumSize(QSize(16777215, 36));
        label_198->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_198);

        lineEdit_axis_allmove_time = new QLineEdit(groupBox_5);
        lineEdit_axis_allmove_time->setObjectName(QString::fromUtf8("lineEdit_axis_allmove_time"));
        sizePolicy.setHeightForWidth(lineEdit_axis_allmove_time->sizePolicy().hasHeightForWidth());
        lineEdit_axis_allmove_time->setSizePolicy(sizePolicy);
        lineEdit_axis_allmove_time->setMinimumSize(QSize(120, 36));
        lineEdit_axis_allmove_time->setMaximumSize(QSize(120, 36));

        horizontalLayout_11->addWidget(lineEdit_axis_allmove_time);

        label_206 = new QLabel(groupBox_5);
        label_206->setObjectName(QString::fromUtf8("label_206"));
        label_206->setMinimumSize(QSize(16, 16));
        label_206->setMaximumSize(QSize(16, 16));

        horizontalLayout_11->addWidget(label_206);


        verticalLayout_64->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_176 = new QLabel(groupBox_5);
        label_176->setObjectName(QString::fromUtf8("label_176"));
        label_176->setMinimumSize(QSize(88, 36));
        label_176->setMaximumSize(QSize(16777215, 36));
        label_176->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label_176);

        lineEdit_axis_move_distance_1 = new QLineEdit(groupBox_5);
        lineEdit_axis_move_distance_1->setObjectName(QString::fromUtf8("lineEdit_axis_move_distance_1"));
        sizePolicy.setHeightForWidth(lineEdit_axis_move_distance_1->sizePolicy().hasHeightForWidth());
        lineEdit_axis_move_distance_1->setSizePolicy(sizePolicy);
        lineEdit_axis_move_distance_1->setMinimumSize(QSize(120, 36));
        lineEdit_axis_move_distance_1->setMaximumSize(QSize(120, 36));

        horizontalLayout_12->addWidget(lineEdit_axis_move_distance_1);

        checkBox_axis_move_distance_1 = new QCheckBox(groupBox_5);
        checkBox_axis_move_distance_1->setObjectName(QString::fromUtf8("checkBox_axis_move_distance_1"));

        horizontalLayout_12->addWidget(checkBox_axis_move_distance_1);


        verticalLayout_64->addLayout(horizontalLayout_12);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_181 = new QLabel(groupBox_5);
        label_181->setObjectName(QString::fromUtf8("label_181"));
        label_181->setMinimumSize(QSize(88, 36));
        label_181->setMaximumSize(QSize(16777215, 36));
        label_181->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(label_181);

        lineEdit_axis_move_distance_2 = new QLineEdit(groupBox_5);
        lineEdit_axis_move_distance_2->setObjectName(QString::fromUtf8("lineEdit_axis_move_distance_2"));
        sizePolicy.setHeightForWidth(lineEdit_axis_move_distance_2->sizePolicy().hasHeightForWidth());
        lineEdit_axis_move_distance_2->setSizePolicy(sizePolicy);
        lineEdit_axis_move_distance_2->setMinimumSize(QSize(120, 36));
        lineEdit_axis_move_distance_2->setMaximumSize(QSize(120, 36));

        horizontalLayout_19->addWidget(lineEdit_axis_move_distance_2);

        checkBox_axis_move_distance_2 = new QCheckBox(groupBox_5);
        checkBox_axis_move_distance_2->setObjectName(QString::fromUtf8("checkBox_axis_move_distance_2"));

        horizontalLayout_19->addWidget(checkBox_axis_move_distance_2);


        verticalLayout_64->addLayout(horizontalLayout_19);


        horizontalLayout_116->addLayout(verticalLayout_64);

        verticalLayout_65 = new QVBoxLayout();
        verticalLayout_65->setObjectName(QString::fromUtf8("verticalLayout_65"));
        pushButton_allaxis_move = new QPushButton(groupBox_5);
        pushButton_allaxis_move->setObjectName(QString::fromUtf8("pushButton_allaxis_move"));
        pushButton_allaxis_move->setMinimumSize(QSize(100, 36));
        pushButton_allaxis_move->setMaximumSize(QSize(100, 36));

        verticalLayout_65->addWidget(pushButton_allaxis_move);

        pushButton_allaxis_stop = new QPushButton(groupBox_5);
        pushButton_allaxis_stop->setObjectName(QString::fromUtf8("pushButton_allaxis_stop"));
        pushButton_allaxis_stop->setMinimumSize(QSize(100, 36));
        pushButton_allaxis_stop->setMaximumSize(QSize(100, 36));

        verticalLayout_65->addWidget(pushButton_allaxis_stop);


        horizontalLayout_116->addLayout(verticalLayout_65);

        horizontalLayout_116->setStretch(0, 1);
        horizontalLayout_116->setStretch(1, 100);

        gridLayout_3->addLayout(horizontalLayout_116, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_5);

        MotionControlForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MotionControlForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1141, 23));
        MotionControlForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MotionControlForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MotionControlForm->setStatusBar(statusbar);

        retranslateUi(MotionControlForm);

        QMetaObject::connectSlotsByName(MotionControlForm);
    } // setupUi

    void retranslateUi(QMainWindow *MotionControlForm)
    {
        MotionControlForm->setWindowTitle(QCoreApplication::translate("MotionControlForm", "MainWindow", nullptr));
        groupBox_8->setTitle(QString());
        label_163->setText(QCoreApplication::translate("MotionControlForm", "\350\275\2641", nullptr));
        btn_axis_gohome_2->setText(QCoreApplication::translate("MotionControlForm", "\345\233\236\345\216\237\347\202\271", nullptr));
        btn_axis_stop_2->setText(QCoreApplication::translate("MotionControlForm", "\345\201\234\346\255\242", nullptr));
        label_167->setText(QCoreApplication::translate("MotionControlForm", "\350\275\2642", nullptr));
        btn_axis_gohome_6->setText(QCoreApplication::translate("MotionControlForm", "\345\233\236\345\216\237\347\202\271", nullptr));
        btn_axis_stop_6->setText(QCoreApplication::translate("MotionControlForm", "\345\201\234\346\255\242", nullptr));
        groupBox_4->setTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("MotionControlForm", "\350\275\2641", nullptr));
        btn_axis_increase_1->setText(QCoreApplication::translate("MotionControlForm", "\345\242\236\345\212\240", nullptr));
        btn_axis_decrease_1->setText(QCoreApplication::translate("MotionControlForm", "\345\207\217\345\260\217", nullptr));
        label_134->setText(QCoreApplication::translate("MotionControlForm", "\345\217\230\351\207\217(mm):", nullptr));
        label_135->setText(QCoreApplication::translate("MotionControlForm", "\346\227\266\351\227\264(s) :", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MotionControlForm", "\350\275\2642", nullptr));
        btn_axis_increase_2->setText(QCoreApplication::translate("MotionControlForm", "\345\242\236\345\212\240", nullptr));
        btn_axis_decrease_2->setText(QCoreApplication::translate("MotionControlForm", "\345\207\217\345\260\217", nullptr));
        label_136->setText(QCoreApplication::translate("MotionControlForm", "\345\217\230\351\207\217(mm):", nullptr));
        label_137->setText(QCoreApplication::translate("MotionControlForm", "\346\227\266\351\227\264(s) :", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MotionControlForm", "\344\274\240\346\204\237\345\231\250\344\277\241\346\201\257", nullptr));
        label_144->setText(QCoreApplication::translate("MotionControlForm", "\344\274\240\346\204\237\345\231\250\351\200\211\346\213\251", nullptr));
        label_145->setText(QCoreApplication::translate("MotionControlForm", "\351\207\207\346\240\267\351\200\232\351\201\223", nullptr));
        label_146->setText(QCoreApplication::translate("MotionControlForm", "\344\274\240\346\204\237\345\231\250\345\220\215\347\247\260", nullptr));
        label_147->setText(QCoreApplication::translate("MotionControlForm", "\345\260\217\346\225\260\344\275\215\346\225\260", nullptr));
        label_148->setText(QCoreApplication::translate("MotionControlForm", "\344\274\240\346\204\237\345\231\250\344\270\212\351\207\217\347\250\213", nullptr));
        label_149->setText(QCoreApplication::translate("MotionControlForm", "\344\274\240\346\204\237\345\231\250\344\270\213\351\207\217\347\250\213", nullptr));
        label_150->setText(QCoreApplication::translate("MotionControlForm", "\344\274\240\346\204\237\345\231\250\345\215\225\344\275\215", nullptr));
        label_152->setText(QCoreApplication::translate("MotionControlForm", "\346\273\244\346\263\242\346\226\271\345\274\217\351\200\211\346\213\251", nullptr));
        label_151->setText(QCoreApplication::translate("MotionControlForm", "\346\273\244\346\263\242\347\202\271\346\225\260", nullptr));
        comboBox_axis_choose->setItemText(0, QCoreApplication::translate("MotionControlForm", "Axis1", nullptr));
        comboBox_axis_choose->setItemText(1, QCoreApplication::translate("MotionControlForm", "Axis2", nullptr));

        pushButton_info_set->setText(QCoreApplication::translate("MotionControlForm", "\350\256\276\347\275\256", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MotionControlForm", "\344\274\240\346\204\237\345\231\250\347\263\273\346\225\260", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MotionControlForm", "Z1(mm)\357\274\232", nullptr));
        btn_AxisEnable_2->setText(QString());
        btn_AxisStatus_2->setText(QString());
        label_128->setText(QCoreApplication::translate("MotionControlForm", "Z2(mm)\357\274\232", nullptr));
        btn_AxisEnable_6->setText(QString());
        btn_AxisStatus_6->setText(QString());
        groupBox_3->setTitle(QString());
        pushButton_power_off->setText(QCoreApplication::translate("MotionControlForm", "\346\226\255\347\224\265", nullptr));
        pushButton_clear_error_all->setText(QCoreApplication::translate("MotionControlForm", "\351\224\231\350\257\257\346\270\205\347\251\272", nullptr));
        pushButton_disable_all->setText(QCoreApplication::translate("MotionControlForm", "\344\270\200\351\224\256\345\244\261\350\203\275", nullptr));
        pushButton_load->setText(QCoreApplication::translate("MotionControlForm", "\345\212\240\350\275\275", nullptr));
        pushButton_enable_all->setText(QCoreApplication::translate("MotionControlForm", "\344\270\200\351\224\256\344\275\277\350\203\275", nullptr));
        pushButton_power_on_off->setText(QCoreApplication::translate("MotionControlForm", "\344\270\212\347\224\265", nullptr));
        label_143->setText(QCoreApplication::translate("MotionControlForm", "\347\224\265\346\272\220\347\201\257  :", nullptr));
        label_power_onoff->setText(QString());
        label_196->setText(QString());
        label_197->setText(QCoreApplication::translate("MotionControlForm", "\345\212\240\350\275\275\346\214\207\347\244\272\347\201\257  :", nullptr));
        label_load->setText(QString());
        groupBox_5->setTitle(QString());
        label_198->setText(QCoreApplication::translate("MotionControlForm", "\346\227\266\351\227\264(s)", nullptr));
        label_206->setText(QString());
        label_176->setText(QCoreApplication::translate("MotionControlForm", "\350\275\2641(mm)", nullptr));
        checkBox_axis_move_distance_1->setText(QString());
        label_181->setText(QCoreApplication::translate("MotionControlForm", "\350\275\2642(mm)", nullptr));
        checkBox_axis_move_distance_2->setText(QString());
        pushButton_allaxis_move->setText(QCoreApplication::translate("MotionControlForm", "\350\257\225\350\277\220\350\241\214", nullptr));
        pushButton_allaxis_stop->setText(QCoreApplication::translate("MotionControlForm", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MotionControlForm: public Ui_MotionControlForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTIONCONTROLFORM_H
