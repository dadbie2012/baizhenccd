#ifndef AXISMOTION_H
#define AXISMOTION_H

#include <QObject>
#include <QDateTime>
#include "axisfunction.h"
#include "../inc/bdaqctrl.h"
#include "axis.h"
#include "app.h"
#include<iostream>
#include<datevar.h>
using namespace std;

using namespace Automation::BDaq;

class axismotion : public QObject
{
    Q_OBJECT
public:
    explicit axismotion(QObject *parent = nullptr);
    ~axismotion();

    bool DeviceOpen();                                                                               //打开设备
    void DeviceClose();                                                                              //关闭设备、轴
    bool DevicePowerOn();                                                                            //上电
    void DevicePowerOff();                                                                           //断电
    bool DevicePowerState();                                                                         //获取电源状态

    bool AxisOpen();                                                                                 //扫描轴打开轴
    bool AxisEnable(ulong axhand);                                                                    //使能
    bool AxisDisable(ulong axhand);                                                                   //失能
    bool AxisErrorClear(ulong axhand);                                                                //清除错误
    void AxisErrorAllClear();                                                                        //一键清除错误
    void AxisStop(ulong axhand);                                                                      //轴停止
    void AxisAllStop();                                                                              //一键轴停止
    void AxisGohome(ulong axhand,double VelLow,double VelHigh,double acceleration,U32 mode);    //回原点
    void AxisMoveToZero(ulong axhand, double VelLow, double VelHigh, double acceleration);            //回零点
    void AxisReset(ulong axhand);                                                                     //轴复位
    void AxisMoveRel(ulong axhand,double distance);                                                   //相对运动
    void AxisMoveAbs(ulong axhand,double distance);                                                   //绝对运动
    void AxisMoveRelPT(ulong axhand,double acceleration,double distance,double time);                 //相对运动
    void AxisMoveAbsPT(ulong axhand,double acceleration,double distance,double time);                 //绝对运动
    void AxisGroupMoveAbsPT(QVector<ulong> &hand,QVector<double> &acceleration,QVector<double> &distance,QVector<double> &time);//群组运动

    F64 AxisGetCmdPosition(ulong axhand);                                                             //获取轴的理论位置
    F64 AxisGetActualPosition(ulong axhand);                                                          //获取轴的实际位置
    F64 AxisGetCmdVelocity(ulong axhand);                                                             //获取轴的速度
    U16 AxisGetState(ulong axhand);                                                                   //获取轴的状态
    ULONG AxisGetMotionStatus(ulong axhand);                                                          //获取轴的运动状态
    ULONG AxisGetMotionIO(ulong axhand);                                                              //获取轴的IO状态

    ULONG getAxisNum();                                                                              //获取轴数量
signals:

private:

    InstantDoCtrl *m_InstantDoCtrl;
    axisfunction *m_Device;//设备
    ulong m_DevNum;
    ulong m_AxisCount;

    HAND m_DevHand;
    HAND m_AxisHand[32];

    DEVLIST	m_avaDevs[32];


    //QMap<int,QString> mPosTime;//位置和时间
};

#endif // AXISMOTION_H
