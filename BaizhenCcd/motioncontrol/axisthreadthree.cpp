#include "axisthreadthree.h"

#define  AXISSVON (16000)

extern axismotion *DEVICE;
extern AxisUiData Axis_UI_Data;
extern DEVICESTATE Ax_State;

extern axis *axis_1;//轴
extern axis *axis_2;

axisThreadThree::axisThreadThree(QObject *parent) : QObject(parent)
{

}

axisThreadThree::~axisThreadThree()
{

}

void axisThreadThree::AxisGetRealData(UINT_PTR axhand, axis *axis, AxisRelData *reldata)
{
    try {
        reldata->AxisCmdPos=DEVICE->AxisGetCmdPosition(axhand);
        reldata->AxisActPos=DEVICE->AxisGetActualPosition(axhand);
        reldata->AxisCmdSpeed=DEVICE->AxisGetCmdVelocity(axhand);
        reldata->AxisState=DEVICE->AxisGetState(axhand);
        reldata->AxisMotionState=DEVICE->AxisGetMotionStatus(axhand);
        reldata->AxisMotionIOState=DEVICE->AxisGetMotionIO(axhand);

        if(reldata->AxisMotionIOState>AXISSVON)
        {
           reldata->isAxisServoOn=true;
        }
        else
        {
            reldata->isAxisServoOn=false;
        }


        reldata->AxisRealData=QString::number(axis->get_actual_value(reldata->AxisActPos),'f',axis->get_sen_fra_num());

    } catch (...) {
    }
}

void axisThreadThree::AxisGetAllRealData()
{
    try {
        AxisGetRealData(0,axis_1,&Axis_UI_Data.AxisRel_1);
        AxisGetRealData(1,axis_2,&Axis_UI_Data.AxisRel_2);
    } catch (...) {

    }

    try {
        Ax_State.isPowerOn=DEVICE->DevicePowerState();
        //Ax_State.isPowerOn=true;
        //qDebug()<<"Ax_State.isPowerOn"<<Ax_State.isPowerOn;
    } catch (...) {

    }

}

void axisThreadThree::slotDeviceOpen()
{
    try {

        DEVICE->DeviceOpen();
        Sleep(100);
        Ax_State.isDeviceAxisInit=DEVICE->AxisOpen();
    } catch (...) {

    }

}

void axisThreadThree::slotDeviceClose()
{
    try {
        DEVICE->DeviceClose();
    } catch (...) {

    }

}

void axisThreadThree::slotAxisEnable(QVector<int> index)
{
    try {
        for(int i=0;i<index.size();i++)
        {
            DEVICE->AxisEnable(index[i]);
        }
    } catch (...) {

    }

}

void axisThreadThree::slotAxisDisable(QVector<int> index)
{
    try {
        for(int i=0;i<index.size();i++)
        {
            DEVICE->AxisDisable(index[i]);
        }
    } catch (...) {

    }

}

void axisThreadThree::slotAxisPowerOn()
{
    try {
        DEVICE->DevicePowerOn();

    } catch (...) {

    }

}

void axisThreadThree::slotAxisPowerOff()
{
    try {
        DEVICE->DeviceClose();
        Sleep(3000);
        DEVICE->DevicePowerOff();
    } catch (...) {

    }

}

void axisThreadThree::slotAxisErrorAllClear()
{
    try {
        DEVICE->AxisErrorAllClear();
    } catch (...) {

    }

}

void axisThreadThree::slotAxisAllStop()
{
    try {
        DEVICE->AxisAllStop();
    } catch (...) {

    }
}

void axisThreadThree::slotAxisStop(ulong index)
{
    try {
        DEVICE->AxisStop(index);
    } catch (...) {

    }
}

void axisThreadThree::slotAxisReset(ulong index)
{
    try {
        DEVICE->AxisReset(index);
    } catch (...) {

    }
}

void axisThreadThree::slotAxisGohome(ulong index)
{
    try {
        if(index==0)
        {
            DEVICE->AxisGohome(index,20000,20000,1000000,CiA402_MODE1);

        }
        else
        {
            DEVICE->AxisGohome(index,8388608,8388608,100000000,CiA402_MODE1);
        }


    } catch (...) {

    }
}
