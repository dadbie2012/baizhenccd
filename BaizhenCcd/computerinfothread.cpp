#include "computerinfothread.h"


computerinfothread::computerinfothread()
{

}

void computerinfothread::run()
{

    while(true){

        QString localHostName=QHostInfo::localHostName();   //获取主机名
        QHostInfo hostInfo=QHostInfo::fromName(localHostName);
        // cout<<hostInfo.addresses().first().toString().toStdString()<<endl;

        MEMORYSTATUSEX statex;
        statex.dwLength = sizeof (statex);
        GlobalMemoryStatusEx (&statex);
        //qDebug() << QStringLiteral("物理内存使用率:") << statex.dwMemoryLoad;
        QFileInfoList list = QDir::drives();
        QStringList diskNameList(NULL);
        QString text="";
        for (int i=0; i<list.count(); i++)
        {

            QString str = list.at(i).absoluteDir().absolutePath();
            diskNameList.append(str);
        }
        foreach(QString str, diskNameList)
        {
            if (str.isEmpty())
            {
                continue;
            }
            quint64 totalDiskSpace = getDiskSpace(str, true);
            quint64 freeDiskSpace = getDiskSpace(str, false);
          //  text.append("Disk  ");
            text.append(str+" ");
            text.append("Usage rate:");
            double result=static_cast<double>(totalDiskSpace-freeDiskSpace)/static_cast<double>(totalDiskSpace)*100;
            text.append(QString::number(result,10,2)+"%");
            text.append("   ");
            if(str=="C:/"){
                DateVar::usage_rate_c=result;

            }else if(str=="D:/"){
                DateVar::usage_rate_d=result;

            }
            // cout<<str.toStdString()<<"---"<<result<<"---"<<result<<endl;
        }
        text.append("   Memory usage rate:");
        text.append(QString::number( statex.dwMemoryLoad,10,1)+"%");
        text.append("    IP: "+hostInfo.addresses().first().toString());
        emit sendinfo(text);
   }
}
quint64 computerinfothread::getDiskSpace(QString iDriver, bool flag)
{
    //iDriver为盘符(例如"C\"),flag为true则求磁盘总容量，为false则求磁盘剩余容量
    LPCWSTR strDriver=(LPCWSTR)iDriver.utf16();
    ULARGE_INTEGER freeDiskSpaceAvailable, totalDiskSpace, totalFreeDiskSpace;

    //调用函数获取磁盘参数(单位为字节Byte),转化为GB，需要除以(1024*1024*1024)
    GetDiskFreeSpaceEx( strDriver, &freeDiskSpaceAvailable, &totalDiskSpace, &totalFreeDiskSpace) ;
    if(flag)
    {
        return (quint64) totalDiskSpace.QuadPart/MB;
    }
    else
    {
        return (quint64) totalFreeDiskSpace.QuadPart/MB;
    }
}

