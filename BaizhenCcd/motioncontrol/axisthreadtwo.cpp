#include "axisthreadtwo.h"

extern axismotion *DEVICE;

axisThreadTwo::axisThreadTwo(QObject *parent) : QObject(parent)
{

}

axisThreadTwo::~axisThreadTwo()
{

}

void axisThreadTwo::slot_getDistanceTime(int axhand, axis *axis)
{
    while (1) {
        Sleep(10);
        try {

            if(DEVICE->AxisGetState(axhand)!=STA_AX_READY)
            {

                double ActPos=DEVICE->AxisGetActualPosition(axhand);
                double RealData=axis->get_actual_value(ActPos);
                QDateTime ctime=QDateTime::currentDateTime();

                position.push_back(RealData);
                time.push_back(ctime);
                //qDebug()<<ctime.toString("yyyy-MM-dd hh:mm:ss:zzz");
            }
            else
            {


                    DateVar::automutex_1.lock();
                    DateVar::autowaitcondition_1.wakeOne();
                    DateVar::automutex_1.unlock();

                break;
            }


        } catch (...) {
            cout<<"check the shaft!"<<endl;

        }

    }


}

void axisThreadTwo::slot_getDistanceTime2(int axhand, axis *axis)
{
    while (1) {
        try {
            Sleep(10);
            if(DEVICE->AxisGetState(axhand)!=STA_AX_READY)
            {
                double ActPos=DEVICE->AxisGetActualPosition(axhand);
                double RealData=axis->get_actual_value(ActPos);
                QDateTime ctime=QDateTime::currentDateTime();

                position.push_back(RealData);
                time.push_back(ctime);
                //qDebug()<<ctime.toString("yyyy-MM-dd hh:mm:ss:zzz");
            }
            else
            {

                if(axhand==0){
                    emit sigendmove2();
                }else{
                    emit sigendmove_2_2();
                }
                break;
            }

        } catch (...) {

        }

    }
}

void axisThreadTwo::slot_getDistanceTime3(int axhand, axis *axis)
{
    while (1) {
        Sleep(10);
        try {
            if(DEVICE->AxisGetState(axhand)!=STA_AX_READY)
            {
                double ActPos=DEVICE->AxisGetActualPosition(axhand);
                double RealData=axis->get_actual_value(ActPos);
                QDateTime ctime=QDateTime::currentDateTime();

                position.push_back(RealData);
                time.push_back(ctime);
                //qDebug()<<ctime.toString("yyyy-MM-dd hh:mm:ss:zzz");
            }
            else
            {

                if(axhand==0){
                    emit sigendmove3();
                }else{
                    emit sigendmove_2_3();
                }
                break;
            }

        } catch (...) {

        }

    }
}

void axisThreadTwo::slot_getDistanceTime4(int axhand, axis *axis)
{
    while (1) {
        Sleep(10);
        try {
            if(DEVICE->AxisGetState(axhand)!=STA_AX_READY)
            {
                double ActPos=DEVICE->AxisGetActualPosition(axhand);
                double RealData=axis->get_actual_value(ActPos);
                QDateTime ctime=QDateTime::currentDateTime();

                //qDebug()<<ctime.toString("yyyy-MM-dd hh:mm:ss:zzz");
            }
            else
            {
                Sleep(350);
                if(axhand==0){
                    emit sigendmove4();
                }else{
                    emit sigendmove_2_4();
                }
                qDebug()<<"endtime"<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
                break;
            }

        } catch (...) {

        }

    }
}
