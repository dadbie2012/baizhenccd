#ifndef MOTIONCONTROLFORM_H
#define MOTIONCONTROLFORM_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include "motioncontrol/axisthreadone.h"
#include "motioncontrol/axisthreadtwo.h"
#include "motioncontrol/axisthreadthree.h"
#include "motioncontrol/axis_status.h"

namespace Ui {
class MotionControlForm;
}

class MotionControlForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MotionControlForm(QWidget *parent = nullptr);
    ~MotionControlForm();

    void init_SensorConfigTable();

    void ax_updata_data(axis *a,QString path);

    void ui_limit();
signals:
    void sigAxisGetRealData();

    void sigDeviceOpen();//加载
    void sigAxisEnable(QVector<int> index);//使能信号
    void sigAxisDisable(QVector<int> index);//失能信号
    void sigAxisPowerOn();//上电
    void sigAxisPowerOff();//断电
    void sigAxisErrorAllClear();//错误清除
    void sigAxisAllStop();//轴全部停止
    void sigAxisStop(ulong index);//轴全部停止
    void sigAxisReset(ulong index);//轴复位
    void sigAxisGohome(ulong index);//轴回原点

    void sigAxisMoveRelPT(int index,double acceleration,double distance,double time);
    void sigAxisMoveAbsPT(int index,double acceleration,double distance,double time);
    void sigAxisGroupMoveAbsPT(QVector<ulong> index,QVector<double> acceleration,QVector<double> distance,QVector<double> time);

public slots:
    void on_btn_AxisStatus_2_clicked();

    void on_btn_AxisStatus_6_clicked();

    void on_comboBox_axis_choose_currentIndexChanged(int index);

    void Updata_UI_Axis();

    void Updata_UI_Axis_label(AxisRelData *sta,QPushButton *btn);

    void on_pushButton_info_set_clicked();

    void on_pushButton_power_on_off_clicked();

    void on_pushButton_power_off_clicked();

    void on_pushButton_load_clicked();

    void on_pushButton_clear_error_all_clicked();

    void on_pushButton_enable_all_clicked();

    void on_pushButton_disable_all_clicked();

    void on_btn_axis_increase_1_clicked();

    void on_btn_axis_increase_2_clicked();

    void on_btn_axis_decrease_1_clicked();

    void on_btn_axis_decrease_2_clicked();

    void on_pushButton_allaxis_move_clicked();

    void on_pushButton_allaxis_stop_clicked();

    void on_btn_axis_gohome_2_clicked();

    void on_btn_axis_gohome_6_clicked();

//    void on_btn_axis_resetting_2_clicked();

//    void on_btn_axis_resetting_6_clicked();

    void on_btn_axis_stop_2_clicked();

    void on_btn_axis_stop_6_clicked();

    void on_btn_AxisEnable_2_clicked(bool checked);

    void on_btn_AxisEnable_6_clicked(bool checked);

    void initialization_1();
    void initialization_2();
    void initialization_3();

private:
    Ui::MotionControlForm *ui;

    axis_status *axis_status_1;//八个轴状态信息显示界面
    axis_status *axis_status_2;

    axisThreadOne* AxisWorkOne;//轴运动
    QThread* AxisThreadOne;//轴运动
    axisThreadTwo* AxisWorkTwo;//轴运动
    QThread* AxisThreadTwo;//轴运动
    axisThreadThree* AxisWorkThree;//轴运动
    QThread* AxisThreadThree;//轴运动

    QTimer *timer_AxisRelData;//轴实时数据

};

#endif // MOTIONCONTROLFORM_H
