#ifndef COMPUTERINFOTHREAD_H
#define COMPUTERINFOTHREAD_H
#include<QThread>
#include<iostream>
#include<QTimer>
#include<QDateTime>
#include<vector>
#include<QSerialPort>
#include<QSerialPortInfo>
#include<QList>
#include<QByteArray>
#include<QWindow>
#include<Windows.h>
#include <QProcess>
#include <QWindow>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include<QLabel>
#include<Windows.h>
#include<QDebug>
#include<QHostInfo>
#include"datevar.h"
using namespace std;

#define MB (1024*1024)

class computerinfothread:public QThread
{
     Q_OBJECT
public:
    computerinfothread();
    void run()override;
    quint64 getDiskSpace(QString iDriver, bool flag);
signals:
    void sendinfo(QString info);
};

#endif // COMPUTERINFOTHREAD_H
