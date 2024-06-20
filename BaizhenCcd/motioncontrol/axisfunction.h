#ifndef AXISFUNCTION_H
#define AXISFUNCTION_H

#include <QObject>
#include <QDebug>
#include "../inc/AdvMotApi.h"
#include "../inc/AdvMotPropID.h"
#include<datevar.h>
#pragma execution_character_set("utf-8")//解决中文乱码

class axisfunction : public QObject
{
    Q_OBJECT
public:
    explicit axisfunction(QObject *parent = nullptr);
    ~axisfunction();

/*2错误信息************************************************************************/
    BOOL GetErrorMessage (U32 ErrorCode, PI8 lpszError, U32 nMaxError);
/*2和3设备************************************************************************/
    U32 GetAvailableDevs (DEVLIST *DeviceList, U32 MaxEntries, PU32 OutEntries);
    U32 GetDevNum(U32 DevType, U32 BoardID, PU32 DeviceNumber);
    U32 DevOpen (U32 DeviceNumber, PHAND DeviceHandle);
    U32 DevClose (PHAND DeviceHandle);
    U32 DevReOpen(HAND DeviceHandle);
    U32 DevLoadConfig (HAND DeviceHandle, PI8 ConfigPath);
/*3属性************************************************************************/
    U32 GetU32Property(HAND Handle, U32 ProperyID, PU32 Value);
    U32 GetI32Property(HAND Handle, U32 ProperyID, PI32 Value);
    U32 SetU32Property(HAND Handle, U32 ProperyID, U32 Value);
    U32 SetI32Property(HAND Handle, U32 ProperyID,I32 Value);
    U32 GetF64Property(HAND Handle, U32 ProperyID, PF64 Value);
    U32 SetF64Property(HAND Handle, U32 ProperyID,F64 Value);
/*4DAQ************************************************************************/
    U32 DaqDiGetByte (HAND DeviceHandle, U16 DiPort, PU8 ByteData);

    U32 DaqDoSetByte (HAND DeviceHandle, U16 DoPort, U8 ByteData);
    U32 DaqDoSetBit (HAND DeviceHandle, U16 DoChannel, U8 BitData);
    U32 DaqDoGetByte(HAND DeviceHandle, U16 DoPort,PU8 ByteData);
    U32 DaqDoGetBit (HAND DeviceHandle, U16 DoChannel, PU8 BitData);
/*5.1轴-系统************************************************************************/
    U32 AxOpen (HAND DeviceHandle, U16 PhyAxis, PHAND AxisHandle);
    U32 AxOpenbyID(HAND DeviceHandle, U16 SlaveID, U8 SubID, PHAND AxisHandle);
    U32 AxClose (PHAND AxisHandle);
    U32 AxResetError (HAND AxisHandle);
/*5.2轴-运行IO************************************************************************/
    U32 AxSetSvOn (HAND AxisHandle, U32 OnOff);
    U32 AxGetMotionIO (HAND AxisHandle, PU32 Status);
/*5.3轴-运行状态************************************************************************/
    U32 AxGetMotionStatus (HAND AxisHandle, PU32 Status);
    U32 AxGetState (HAND AxisHandle, PU16 State);
    U32 AxGetMachPosition(HAND AxisHandle, PF64 Position);
/*5.4轴-速度运动************************************************************************/
    U32 AxMoveVel (HAND AxisHandle, U16 Direction);
    U32 AxChangeVel (HAND AxisHandle, F64 NewVelocity);
    U32 AxChangeVelEx (HAND AxisHandle, F64 NewVelocity, F64 NewAcc, F64 NewDec);
    U32 AxChangeVelExByRate (HAND AxisHandle, U32 Rate, F64 NewAcc, F64 NewDec);
    U32 AxChangeVelByRate (HAND AxisHandle, U32 Rate);
    U32 AxGetCmdVelocity (HAND AxisHandle, PF64 Velocity);
/*5.5轴-点到点运动************************************************************************/
    U32 AxMoveRel (HAND AxisHandle, F64 Distance);
    U32 AxMoveAbs (HAND AxisHandle, F64 Position);
    U32 AxChangePos (HAND AxisHandle, F64 NewDistance);
    U32 AxMoveImpose (HAND AxisHandle, F64 Position, F64 NewVel);
/*5.6轴-同步启停运动************************************************************************/
    U32 AxSimStartSuspendAbs (HAND AxisHandle, F64 EndPoint);
    U32 AxSimStartSuspendRel (HAND AxisHandle, F64 Distance);
    U32 AxSimStartSuspendVel (HAND AxisHandle, U16 DriDir);
    U32 AxSimStart (HAND AxisHandle);
    U32 AxSimStop (HAND AxisHandle);
/*5.7轴-回原点************************************************************************/
    U32 AxHome (HAND AxisHandle, U32 HomeMode, U32 Dir);
    U32 AxMoveHome(HAND AxisHandle, U32 HomeMode, U32 DirMode);
/*5.8轴-位置/计数器************************************************************************/
    U32 AxSetCmdPosition (HAND AxisHandle, F64 Position);
    U32 AxGetCmdPosition (HAND AxisHandle, PF64 Position);
    U32 AxSetActualPosition (HAND AxisHandle, F64 Position);
    U32 AxGetActualPosition (HAND AxisHandle, PF64 Position);
/*5.17轴-停止运动************************************************************************/
    U32 AxStopDec (HAND AxisHandle);
    U32 AxStopEmg (HAND AxisHandle);
    U32 AxStopDecEx (HAND AxisHandle, F64 NewDec);
/*6.1群组-系统************************************************************************/
    U32 GpAddAxis (PHAND GpHandle, HAND AxHandle);
    U32 GpRemAxis (HAND GpHandle, HAND AxHandle);
    U32 GpClose (PHAND pGroupHandle);
    U32 GpResetError (HAND GroupHandle);
/*6.2群组-运动状态及速度************************************************************************/
    U32 GpGetState (HAND GroupHandle, PU16 pState);
    U32 GpGetCmdVel(HAND GroupHandle, PF64 CmdVel);
/*6.3群组-停止运动************************************************************************/
    U32 GpStopDec (HAND GroupHandle);
    U32 GpStopEmg( HAND GroupHandle);
/*6.4群组-插补运动************************************************************************/
    U32 GpMoveLinearRel( HAND GroupHandle, PF64 DistanceArray, PU32 pArrayElements);
    U32 GpMoveLinearAbs (HAND GroupHandle, PF64 PositionArray, PU32 pArrayElements);
    U32 GpMoveDirectRel (HAND GroupHandle, PF64 DistanceArray, PU32 ArrayElements);
    U32 GpMoveDirectAbs (HAND GroupHandle, PF64 PositionArray, PU32 ArrayElements);
    U32 GpChangeVel (HAND GroupHandle, F64 NewVelocity);
    U32 GpChangeVelByRate(HAND GroupHandle, U32 Rate);
/*6.6群组-暂停和恢复************************************************************************/
    U32 GpPauseMotion(HAND GroupHandle);
    U32 GpResumeMotion(HAND GroupHandle);

};

#endif // AXISFUNCTION_H
