#include "axisfunction.h"

axisfunction::axisfunction(QObject *parent) : QObject(parent)
{

}

axisfunction::~axisfunction()
{

}

BOOL axisfunction::GetErrorMessage(U32 ErrorCode, PI8 lpszError, U32 nMaxError)
{
    return Acm_GetErrorMessage(ErrorCode,lpszError,nMaxError);
}

ULONG axisfunction::GetAvailableDevs(DEVLIST *DeviceList, ULONG MaxEntries, ULONG *OutEntries)
{
    return Acm_GetAvailableDevs (DeviceList,MaxEntries,OutEntries);
}

ULONG axisfunction::GetDevNum(ULONG DevType, ULONG BoardID, ULONG *DeviceNumber)
{
    return Acm_GetDevNum (DevType,BoardID,DeviceNumber);
}

ULONG axisfunction::DevOpen(ULONG DeviceNumber, UINT_PTR *DeviceHandle)
{
     return Acm_DevOpen (DeviceNumber,DeviceHandle);
}

ULONG axisfunction::DevClose(UINT_PTR *DeviceHandle)
{
    return Acm_DevClose (DeviceHandle);
}

ULONG axisfunction::DevReOpen(UINT_PTR DeviceHandle)
{
    return Acm_DevReOpen (DeviceHandle);
}

ULONG axisfunction::DevLoadConfig(UINT_PTR DeviceHandle, CHAR *ConfigPath)
{
    return Acm_DevLoadConfig (DeviceHandle, ConfigPath);
}

ULONG axisfunction::GetU32Property(UINT_PTR Handle, ULONG ProperyID, ULONG *Value)
{
    return Acm_GetU32Property (Handle, ProperyID,Value);
}

ULONG axisfunction::GetI32Property(UINT_PTR Handle, ULONG ProperyID, LONG *Value)
{
    return Acm_GetI32Property (Handle, ProperyID,Value);
}

ULONG axisfunction::SetU32Property(UINT_PTR Handle, ULONG ProperyID, ULONG Value)
{
    return Acm_SetU32Property (Handle, ProperyID,Value);
}

ULONG axisfunction::SetI32Property(UINT_PTR Handle, ULONG ProperyID, LONG Value)
{
    return Acm_SetI32Property (Handle, ProperyID,Value);
}

ULONG axisfunction::GetF64Property(UINT_PTR Handle, ULONG ProperyID, DOUBLE *Value)
{
    return Acm_GetF64Property(Handle,ProperyID,Value);
}

ULONG axisfunction::SetF64Property(UINT_PTR Handle, ULONG ProperyID, DOUBLE Value)
{
    return Acm_SetF64Property(Handle,ProperyID,Value);
}

ULONG axisfunction::DaqDiGetByte(UINT_PTR DeviceHandle, USHORT DiPort, UCHAR *ByteData)
{
    return Acm_DaqDiGetByte(DeviceHandle,DiPort,ByteData);
}

ULONG axisfunction::DaqDoSetByte(UINT_PTR DeviceHandle, USHORT DoPort, UCHAR ByteData)
{
    return Acm_DaqDoSetByte(DeviceHandle,DoPort,ByteData);
}

ULONG axisfunction::DaqDoSetBit(UINT_PTR DeviceHandle, USHORT DoChannel, UCHAR BitData)
{
    return Acm_DaqDoSetBit(DeviceHandle,DoChannel,BitData);
}

ULONG axisfunction::DaqDoGetByte(UINT_PTR DeviceHandle, USHORT DoPort, UCHAR *ByteData)
{
    return Acm_DaqDoGetByte(DeviceHandle,DoPort,ByteData);
}

ULONG axisfunction::DaqDoGetBit(UINT_PTR DeviceHandle, USHORT DoChannel, UCHAR *BitData)
{
    return Acm_DaqDoGetBit(DeviceHandle,DoChannel,BitData);
}

ULONG axisfunction::AxOpen(UINT_PTR DeviceHandle, USHORT PhyAxis, UINT_PTR *AxisHandle)
{
    return Acm_AxOpen(DeviceHandle,PhyAxis,AxisHandle);
}

ULONG axisfunction::AxOpenbyID(UINT_PTR DeviceHandle, USHORT SlaveID, UCHAR SubID, UINT_PTR *AxisHandle)
{
    return Acm_AxOpenbyID(DeviceHandle,SlaveID,SubID,AxisHandle);
}

ULONG axisfunction::AxClose(UINT_PTR *AxisHandle)
{
    return Acm_AxClose(AxisHandle);
}

ULONG axisfunction::AxResetError(UINT_PTR AxisHandle)
{
    return Acm_AxResetError(AxisHandle);
}

ULONG axisfunction::AxSetSvOn(UINT_PTR AxisHandle, ULONG OnOff)
{
    return Acm_AxSetSvOn(AxisHandle,OnOff);
}

ULONG axisfunction::AxGetMotionIO(UINT_PTR AxisHandle, ULONG *Status)
{
    return Acm_AxGetMotionIO(AxisHandle,Status);
}

ULONG axisfunction::AxGetMotionStatus(UINT_PTR AxisHandle, ULONG *Status)
{
    return Acm_AxGetMotionStatus(AxisHandle,Status);
}

ULONG axisfunction::AxGetState(UINT_PTR AxisHandle, USHORT *State)
{
    return Acm_AxGetState(AxisHandle,State);
}

ULONG axisfunction::AxGetMachPosition(UINT_PTR AxisHandle, DOUBLE *Position)
{
    return Acm_AxGetMachPosition(AxisHandle,Position);
}

ULONG axisfunction::AxMoveVel(UINT_PTR AxisHandle, USHORT Direction)
{
    return Acm_AxMoveVel(AxisHandle,Direction);
}

ULONG axisfunction::AxChangeVel(UINT_PTR AxisHandle, DOUBLE NewVelocity)
{
    return Acm_AxChangeVel(AxisHandle,NewVelocity);
}

ULONG axisfunction::AxChangeVelEx(UINT_PTR AxisHandle, DOUBLE NewVelocity, DOUBLE NewAcc, DOUBLE NewDec)
{
    return Acm_AxChangeVelEx(AxisHandle,NewVelocity,NewAcc,NewDec);
}

ULONG axisfunction::AxChangeVelExByRate(UINT_PTR AxisHandle, ULONG Rate, DOUBLE NewAcc, DOUBLE NewDec)
{
    return Acm_AxChangeVelExByRate(AxisHandle,Rate,NewAcc,NewDec);
}

ULONG axisfunction::AxChangeVelByRate(UINT_PTR AxisHandle, ULONG Rate)
{
    return Acm_AxChangeVelByRate(AxisHandle,Rate);
}

ULONG axisfunction::AxGetCmdVelocity(UINT_PTR AxisHandle, DOUBLE *Velocity)
{
    return Acm_AxGetCmdVelocity(AxisHandle,Velocity);
}

ULONG axisfunction::AxMoveRel(UINT_PTR AxisHandle, DOUBLE Distance)
{
    return Acm_AxMoveRel(AxisHandle,Distance);
}

ULONG axisfunction::AxMoveAbs(UINT_PTR AxisHandle, DOUBLE Position)
{
    return Acm_AxMoveAbs(AxisHandle,Position);
}

ULONG axisfunction::AxChangePos(UINT_PTR AxisHandle, DOUBLE NewDistance)
{
    return Acm_AxChangePos(AxisHandle,NewDistance);
}

ULONG axisfunction::AxMoveImpose(UINT_PTR AxisHandle, DOUBLE Position, DOUBLE NewVel)
{
    return Acm_AxMoveImpose(AxisHandle,Position,NewVel);
}

ULONG axisfunction::AxSimStartSuspendAbs(UINT_PTR AxisHandle, DOUBLE EndPoint)
{
    return Acm_AxSimStartSuspendAbs(AxisHandle,EndPoint);
}

ULONG axisfunction::AxSimStartSuspendRel(UINT_PTR AxisHandle, DOUBLE Distance)
{
    return Acm_AxSimStartSuspendRel(AxisHandle,Distance);
}

ULONG axisfunction::AxSimStartSuspendVel(UINT_PTR AxisHandle, USHORT DriDir)
{
    return Acm_AxSimStartSuspendVel(AxisHandle,DriDir);
}

ULONG axisfunction::AxSimStart(UINT_PTR AxisHandle)
{
    return Acm_AxSimStart(AxisHandle);
}

ULONG axisfunction::AxSimStop(UINT_PTR AxisHandle)
{
    return Acm_AxSimStop(AxisHandle);
}

ULONG axisfunction::AxHome(UINT_PTR AxisHandle, ULONG HomeMode, ULONG Dir)
{
    return Acm_AxHome(AxisHandle,HomeMode,Dir);
}

ULONG axisfunction::AxMoveHome(UINT_PTR AxisHandle, ULONG HomeMode, ULONG DirMode)
{
    return Acm_AxMoveHome(AxisHandle,HomeMode,DirMode);
}

ULONG axisfunction::AxSetCmdPosition(UINT_PTR AxisHandle, DOUBLE Position)
{
    return Acm_AxSetCmdPosition(AxisHandle,Position);
}

ULONG axisfunction::AxGetCmdPosition(UINT_PTR AxisHandle, DOUBLE *Position)
{
    return Acm_AxGetCmdPosition(AxisHandle,Position);
}

ULONG axisfunction::AxSetActualPosition(UINT_PTR AxisHandle, DOUBLE Position)
{
    return Acm_AxSetActualPosition(AxisHandle,Position);
}

ULONG axisfunction::AxGetActualPosition(UINT_PTR AxisHandle, DOUBLE *Position)
{
    return Acm_AxGetActualPosition(AxisHandle,Position);
}

ULONG axisfunction::AxStopDec(UINT_PTR AxisHandle)
{
    return Acm_AxStopDec(AxisHandle);
}

ULONG axisfunction::AxStopEmg(UINT_PTR AxisHandle)
{
    return Acm_AxStopEmg(AxisHandle);
}

ULONG axisfunction::AxStopDecEx(UINT_PTR AxisHandle, DOUBLE NewDec)
{
    return Acm_AxStopDecEx(AxisHandle,NewDec);
}

ULONG axisfunction::GpAddAxis(UINT_PTR *GpHandle, UINT_PTR AxHandle)
{
    return Acm_GpAddAxis(GpHandle,AxHandle);
}

ULONG axisfunction::GpRemAxis(UINT_PTR GpHandle, UINT_PTR AxHandle)
{
    return Acm_GpRemAxis(GpHandle,AxHandle);
}

ULONG axisfunction::GpClose(UINT_PTR *pGroupHandle)
{
    return Acm_GpClose(pGroupHandle);
}

ULONG axisfunction::GpResetError(UINT_PTR GroupHandle)
{
    return Acm_GpResetError(GroupHandle);
}

ULONG axisfunction::GpGetState(UINT_PTR GroupHandle, USHORT *pState)
{
    return Acm_GpGetState(GroupHandle,pState);
}

ULONG axisfunction::GpGetCmdVel(UINT_PTR GroupHandle, DOUBLE *CmdVel)
{
    return Acm_GpGetCmdVel(GroupHandle,CmdVel);
}

ULONG axisfunction::GpStopDec(UINT_PTR GroupHandle)
{
    return Acm_GpStopDec(GroupHandle);
}

ULONG axisfunction::GpStopEmg(UINT_PTR GroupHandle)
{
    return Acm_GpStopEmg(GroupHandle);
}

ULONG axisfunction::GpMoveLinearRel(UINT_PTR GroupHandle, DOUBLE *DistanceArray, ULONG *pArrayElements)
{
    return Acm_GpMoveLinearRel(GroupHandle,DistanceArray,pArrayElements);
}

ULONG axisfunction::GpMoveLinearAbs(UINT_PTR GroupHandle, DOUBLE *PositionArray, ULONG *pArrayElements)
{
    return Acm_GpMoveLinearAbs(GroupHandle,PositionArray,pArrayElements);
}

ULONG axisfunction::GpMoveDirectRel(UINT_PTR GroupHandle, DOUBLE *DistanceArray, ULONG *ArrayElements)
{
    return Acm_GpMoveDirectRel(GroupHandle,DistanceArray,ArrayElements);
}

ULONG axisfunction::GpMoveDirectAbs(UINT_PTR GroupHandle, DOUBLE *PositionArray, ULONG *ArrayElements)
{
    return Acm_GpMoveDirectAbs(GroupHandle,PositionArray,ArrayElements);
}

ULONG axisfunction::GpChangeVel(UINT_PTR GroupHandle, DOUBLE NewVelocity)
{
    return Acm_GpChangeVel(GroupHandle,NewVelocity);
}

ULONG axisfunction::GpChangeVelByRate(UINT_PTR GroupHandle, ULONG Rate)
{
    return Acm_GpChangeVelByRate(GroupHandle,Rate);
}

ULONG axisfunction::GpPauseMotion(UINT_PTR GroupHandle)
{
    return Acm_GpPauseMotion(GroupHandle);
}

ULONG axisfunction::GpResumeMotion(UINT_PTR GroupHandle)
{
    return Acm_GpResumeMotion(GroupHandle);
}

