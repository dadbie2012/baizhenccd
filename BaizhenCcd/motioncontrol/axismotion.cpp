#include "axismotion.h"

axis *axis_1 = new axis();//轴
axis *axis_2 = new axis();

#define  DEVICEDESCRIPTION1730  L"PCI-1730,BID#0"
#define  DEVICEDESCRIPTION1203 "PCI-1203-06AE (M0)"
#define  NUMAXIS 2

axismotion::axismotion(QObject *parent) : QObject(parent)
{
    axis_1->checkConfig(APP::ConfigName1);
    axis_2->checkConfig(APP::ConfigName2);

    m_InstantDoCtrl = InstantDoCtrl::Create();
    DeviceInformation devInfo(DEVICEDESCRIPTION1730);
    m_InstantDoCtrl->setSelectedDevice(devInfo);

    m_Device=new axisfunction();

    m_DevNum=0;
    m_AxisCount=0;
    m_DevHand=0;
    for (int i=0;i<32;i++) {
        m_AxisHand[i]=0;
    }

    //mPosTime.clear();
}

axismotion::~axismotion()
{
    delete axis_1;
    delete axis_2;
}

bool axismotion::DeviceOpen()
{
    U32 m_ret=0;

    ULONG deviceNumber=0;
    //搜索设备
    m_ret = m_Device->GetAvailableDevs(m_avaDevs,32,&deviceNumber);
    if(m_ret!=SUCCESS)
    {
        return false;
    }
    m_DevNum=m_avaDevs[0].dwDeviceNum;

    if(m_avaDevs[0].szDeviceName!=DEVICEDESCRIPTION1203)
    {
        return false;
    }
//    qDebug()<<m_DevNum;
//    qDebug()<<m_avaDevs[0].szDeviceName;
//    qDebug()<<m_avaDevs[0].nNumOfSubdevices;


//    m_Device->GetDevNum(Adv_PCI1203,1,&m_DevNum);
//    if(m_ret!=SUCCESS)
//    {
//        return false;
//    }

    m_ret = m_Device->DevOpen(m_DevNum,&m_DevHand);
    if(m_ret!=SUCCESS)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void axismotion::DeviceClose()
{
    USHORT usAxisState[64];
    uint AxisNum;

    for (AxisNum=0;AxisNum<m_AxisCount;AxisNum++)
    {
        m_Device->AxGetState(m_AxisHand[AxisNum], &usAxisState[AxisNum]);
        if(usAxisState[AxisNum]==STA_AX_ERROR_STOP)
        {
            m_Device->AxResetError(m_AxisHand[AxisNum]);
        }
        m_Device->AxStopDec(m_AxisHand[AxisNum]);
    }
    for(AxisNum=0;AxisNum<m_AxisCount;AxisNum++)
    {
        m_Device->AxSetSvOn(m_AxisHand[AxisNum],0);
    }
    for(AxisNum=0;AxisNum<m_AxisCount;AxisNum++)
    {
        m_Device->AxClose(&m_AxisHand[AxisNum]);
    }
    m_Device->DevClose(&m_DevHand);
}

bool axismotion::DevicePowerOn()
{
    U32 m_ret=0;
    if(!DevicePowerState())
    {
        m_ret = m_InstantDoCtrl->Write(0,0xff);
        Sleep(100);
        m_ret = m_InstantDoCtrl->Write(1,0x07);
        Sleep(100);
    }

    if(DevicePowerState())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void axismotion::DevicePowerOff()
{
    m_InstantDoCtrl->Write(0,0x00);
    Sleep(100);
    m_InstantDoCtrl->Write(1,0x00);
    Sleep(100);
}

bool axismotion::DevicePowerState()
{
    U32 m_ret=0;
    U8 byte0=0;
    U8 byte1=0;

    m_ret = m_InstantDoCtrl->Read(0,byte0);
    if(m_ret==SUCCESS)
    {
        if(byte0!=0xff)
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    m_ret = m_InstantDoCtrl->Read(1,byte1);
    if(m_ret==SUCCESS)
    {
        if(byte1!=0x07)
        {
            return false;
        }

    }
    else
    {
        return false;
    }
    return true;
}

bool axismotion::AxisOpen()
{
    U32 m_ret=0;
    ULONG retry = 0;
    ULONG slaveonring1 = 0;
    bool rescan = false;
    uint axisopencount = 0;
    //打开设备
    do
    {
        m_ret = m_Device->GetU32Property(m_DevHand,FT_MasCyclicCnt_R0,&m_AxisCount);
        m_ret = m_Device->GetU32Property(m_DevHand,FT_MasCyclicCnt_R1,&slaveonring1);
        qDebug()<<"轴数量:"<<m_AxisCount;

        if(m_AxisCount!=NUMAXIS)
        {
            m_Device->DevReOpen(m_DevHand);
            m_Device->DevClose(&m_DevHand);
            Sleep(100);
            m_ret = m_Device->DevOpen(m_DevNum,&m_DevHand);
            rescan=true;
        }
        else
        {
            rescan=false;
        }

        if(++retry > 10)
        {
            rescan=true;
            return false;
        }
        Sleep(100);
    }
    while(rescan);

    if(rescan==false)
    {
        for(uint AxisNumber=0;AxisNumber<m_AxisCount;AxisNumber++)
        {
            m_ret = m_Device->AxOpen(m_DevHand,(USHORT)AxisNumber,&m_AxisHand[AxisNumber]);
            Sleep(100);
            if(m_ret!=SUCCESS)
            {
                continue;
            }
            else
            {
                axisopencount++;
                qDebug()<<"已打开轴数:"<<axisopencount;
            }
        }
    }

    if(axisopencount!=NUMAXIS)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool axismotion::AxisEnable(ulong axhand)
{
    U32 m_ret=0;
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    m_ret = m_Device->AxSetSvOn(m_AxisHand[axhand],1);
    if(m_ret!=SUCCESS)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool axismotion::AxisDisable(ulong axhand)
{
    U32 m_ret=0;
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    m_ret = m_Device->AxSetSvOn(m_AxisHand[axhand],0);
    if(m_ret!=SUCCESS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool axismotion::AxisErrorClear(ulong axhand)
{
    U32 m_ret=0;
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    m_ret = m_Device->AxResetError(m_AxisHand[axhand]);
    if(m_ret!=SUCCESS)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void axismotion::AxisErrorAllClear()
{
    for(int i=0;i<NUMAXIS;i++)
    {
        AxisErrorClear(i);
        Sleep(100);
    }
}

void axismotion::AxisStop(ulong axhand)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    m_Device->AxStopDec(m_AxisHand[axhand]);
}

void axismotion::AxisAllStop()
{
    for(int i=0;i<NUMAXIS;i++)
    {
        AxisStop(i);
        Sleep(100);
    }
}

void axismotion::AxisGohome(ulong axhand, double VelLow, double VelHigh, double acceleration, U32 mode)
{
//    qDebug()<<axhand;
//    qDebug()<<VelLow;
//    qDebug()<<VelHigh;
//    qDebug()<<acceleration;
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    if(AxisGetState(axhand)!=STA_AX_READY)
    {
        qDebug()<<"正在运动";
        return;
    }
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxHomeVelLow,VelLow);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxHomeVelHigh,VelHigh);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxHomeAcc,acceleration);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxHomeDec,acceleration);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxHomeJerk,0);
    m_Device->SetF64Property(m_AxisHand[axhand], PAR_AxHomeCrossDistance, 8388608*5);
    m_Device->AxMoveHome(m_AxisHand[axhand], mode, 0);
}

void axismotion::AxisMoveToZero(ulong axhand, double VelLow, double VelHigh, double acceleration)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    if(AxisGetState(axhand)!=STA_AX_READY)
    {
       // qDebug()<<"正在运动";
        return;
    }
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxVelLow,VelLow);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxVelHigh,VelHigh);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxAcc,acceleration);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxDec,acceleration);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxJerk,0);
    m_Device->AxMoveAbs(m_AxisHand[axhand],0);
}

void axismotion::AxisReset(ulong axhand)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    if(AxisGetState(axhand)!=STA_AX_READY)
    {
       // qDebug()<<"正在运动";
        return;
    }
    m_Device->AxSetCmdPosition(m_AxisHand[axhand], 0);
    m_Device->AxSetActualPosition(m_AxisHand[axhand], 0);
}

void axismotion::AxisMoveRel(ulong axhand, double distance)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }

    if(AxisGetState(axhand)!=STA_AX_READY)
    {
        //qDebug()<<"正在运动";
        return;
    }
    m_Device->AxMoveRel(m_AxisHand[axhand],distance);
}

void axismotion::AxisMoveAbs(ulong axhand, double distance)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }

    if(AxisGetState(axhand)!=STA_AX_READY)
    {
       // qDebug()<<"正在运动";
        return;
    }
    m_Device->AxMoveAbs(m_AxisHand[axhand],distance);
}

void axismotion::AxisMoveRelPT(ulong axhand, double acceleration, double distance, double time)
{
    if(axhand>=m_AxisCount||time<0.05)
    {
        throw "error";
    }
    if(AxisGetState(axhand)!=STA_AX_READY)
    {
       // qDebug()<<"正在运动";
        return;
    }

    DOUBLE CmdPos=0;
    m_Device->AxGetCmdPosition(m_AxisHand[axhand],&CmdPos);

    double acc=std::abs((distance)/(0.1*(time-0.1)));
    double acctime=0.1;
    //double time_vel=std::sqrt((std::abs(2*distance)/acceleration)+((time*time)/4.0))-(time/2.0);
    //double time_acc=(time-time_vel)/2.0;

    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxVelLow,0);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxVelHigh,acc*acctime);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxAcc,acc);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxDec,acc);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxJerk,0);

    m_Device->AxMoveAbs(m_AxisHand[axhand],CmdPos+distance);

//    while (1) {
//        if(AxisGetState(axhand)!=STA_AX_READY)
//        {
//            qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
//        }
//        else
//        {
//            break;
//        }
//    }
}

void axismotion::AxisMoveAbsPT(ulong axhand, double acceleration, double distance, double time)
{

    if(axhand>=m_AxisCount||time<0.05)
    {
        throw "error";
    }

    if(AxisGetState(axhand)!=STA_AX_READY)
    {
       // qDebug()<<"正在运动";
        return;
    }
    DOUBLE CmdPos=0;
    m_Device->AxGetCmdPosition(m_AxisHand[axhand],&CmdPos);
    double m_distance=distance-CmdPos;
    //double time_vel=std::sqrt((std::abs(2*m_distance)/acceleration)+((time*time)/4.0))-(time/2.0);
    //double time_acc=(time-time_vel)/2.0;
    double acc=std::abs(m_distance/(0.1*(time-0.1)));
    double acctime=0.1;

    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxVelLow,0);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxVelHigh,acc*acctime);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxAcc,acc);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxDec,acc);
    m_Device->SetF64Property(m_AxisHand[axhand],PAR_AxJerk,0);

    m_Device->AxMoveAbs(m_AxisHand[axhand],distance);

}

void axismotion::AxisGroupMoveAbsPT(QVector<ulong> &hand, QVector<double> &acceleration, QVector<double> &distance, QVector<double> &time)
{
    for(int i=0;i<hand.size();i++)
    {
        if(hand[i]>=m_AxisCount)
        {
            throw "error";
        }

        AxisMoveAbsPT(hand[i],acceleration[i],distance[i],time[i]);
    }


}
DOUBLE axismotion::AxisGetCmdPosition(ulong axhand)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    DOUBLE value=0;
    m_Device->AxGetCmdPosition(m_AxisHand[axhand],&value);
    return value;
}

DOUBLE axismotion::AxisGetActualPosition(ulong axhand)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    DOUBLE value=0;
    m_Device->AxGetActualPosition(m_AxisHand[axhand],&value);
    return value;
}

DOUBLE axismotion::AxisGetCmdVelocity(ulong axhand)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    DOUBLE value=0;
    m_Device->AxGetCmdVelocity(m_AxisHand[axhand],&value);
    return value;
}

USHORT axismotion::AxisGetState(ulong axhand)
{

    if(axhand>=m_AxisCount)
    {

        throw "error";

    }
    USHORT value=0;

    m_Device->AxGetState(m_AxisHand[axhand],&value);

    return value;
}

ULONG axismotion::AxisGetMotionStatus(ulong axhand)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    ULONG value=0;
    m_Device->AxGetMotionStatus(m_AxisHand[axhand],&value);
    return value;
}

ULONG axismotion::AxisGetMotionIO(ulong axhand)
{
    if(axhand>=m_AxisCount)
    {
        throw "error";
    }
    ULONG value=0;
    m_Device->AxGetMotionIO(m_AxisHand[axhand],&value);
    //qDebug()<<"axhand"<<axhand<<"AxisMotionIOState"<<value;
    return value;
}

ULONG axismotion::getAxisNum()
{
    return m_AxisCount;
}
