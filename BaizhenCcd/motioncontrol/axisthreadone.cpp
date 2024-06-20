#include "axisthreadone.h"

axismotion *DEVICE = new axismotion();
extern axis *axis_1;//轴
extern axis *axis_2;

AxisUiData Axis_UI_Data;
DEVICESTATE Ax_State;

axisThreadOne::axisThreadOne(QObject *parent) : QObject(parent)
{
    Ax_State.isPowerOn = false;
    Ax_State.isDeviceAxisInit = false;

}

axisThreadOne::~axisThreadOne()
{
    delete DEVICE;
}

void axisThreadOne::slotAxisMoveRelPT(int index, double acceleration, double distance, double time)
{
    try {
        //qDebug()<<index<<acceleration<<distance<<time;
        DEVICE->AxisMoveRelPT(index,acceleration,distance,time);
    } catch (...) {

    }
}

void axisThreadOne::slotAxisMoveAbsPT(int index, double acceleration, double distance, double time)
{
    try {
        //qDebug()<<index<<acceleration<<distance<<time;
        DEVICE->AxisMoveAbsPT(index,acceleration,distance,time);
    } catch (...) {

    }

}

void axisThreadOne::slotAxisGroupMoveAbsPT(QVector<ulong> index, QVector<double> acceleration, QVector<double> distance, QVector<double> time)
{
    try {
        DEVICE->AxisGroupMoveAbsPT(index,acceleration,distance,time);
    } catch (...) {

    }
}

