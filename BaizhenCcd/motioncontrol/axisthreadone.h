#ifndef AXISTHREADONE_H
#define AXISTHREADONE_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QDateTime>
#include <QVector>
#include "axismotion.h"
#include<datevar.h>


struct DEVICESTATE //设备状态
{
    bool isPowerOn;                  //上电
    bool isDeviceAxisInit;           //设备和轴初始化 加载
};

struct AxisRelData
{
    QString AxisRealData;            //实时位置

    uchar AxisState;                 //状态
    ulong AxisMotionState;           //运动状态
    ulong AxisMotionIOState;         //运动io状态

    double AxisCmdPos;               //命令位置
    double AxisActPos;               //实际位置
    double AxisCmdSpeed;             //命令速度

    bool isAxisServoOn;              //使能
};

struct AxisUiData//ui
{
    AxisRelData AxisRel_1;
    AxisRelData AxisRel_2;
};

class axisThreadOne : public QObject
{
    Q_OBJECT
public:
    explicit axisThreadOne(QObject *parent = nullptr);
    ~ axisThreadOne();

signals:

public slots:
    void slotAxisMoveRelPT(int index,double acceleration,double distance,double time);
    void slotAxisMoveAbsPT(int index,double acceleration,double distance,double time);
    void slotAxisGroupMoveAbsPT(QVector<ulong> index,QVector<double> acceleration,QVector<double> distance,QVector<double> time);


};

#endif // AXISTHREADONE_H
