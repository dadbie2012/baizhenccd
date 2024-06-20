#ifndef AXISTHREADTHREE_H
#define AXISTHREADTHREE_H

#include <QObject>
#include "axisthreadone.h"
#include<datevar.h>
class axisThreadThree : public QObject
{
    Q_OBJECT
public:
    explicit axisThreadThree(QObject *parent = nullptr);
    ~ axisThreadThree();

    void AxisGetRealData(UINT_PTR axhand, axis *axis, AxisRelData *reldata);//获取单个轴数据

signals:
public slots:
    void AxisGetAllRealData();//获取所有轴数据

    void slotDeviceOpen();
    void slotDeviceClose();
    void slotAxisEnable(QVector<int> index);//使能信号
    void slotAxisDisable(QVector<int> index);//失能信号
    void slotAxisPowerOn();
    void slotAxisPowerOff();
    void slotAxisErrorAllClear();
    void slotAxisAllStop();
    void slotAxisStop(ulong index);//轴停止
    void slotAxisReset(ulong index);//轴复位
    void slotAxisGohome(ulong index);//轴回原点

private:



};

#endif // AXISTHREADTHREE_H
