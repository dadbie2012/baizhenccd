#ifndef MEASUREFUNCTION_H
#define MEASUREFUNCTION_H
#include<QThread>
#include<math.h>
#include<QApplication>
#include<QMessageBox>
#include<QSettings>
#include <QMutex>
#include <QWaitCondition>
#include<iostream>
#include <visiondahengcamera.h>
#include<motioncontrolform.h>
#include<autofocusthread.h>
#include<datevar.h>
#include "GalaxyIncludes.h"
using namespace std;


class MeasureFunction:public QObject
{
    Q_OBJECT
public:
    MeasureFunction();
    void Camera1ACT2();

    void AutoFocus(VisionDaHengCamera *camera,AutofocusThread *autothread,axis *axis,AxisRelData AxisRel,int axis_num,double upmovedistance,double upmovetime,double downmovedistance,double downmovetime,double endmovetime,int measurenum);
    axismotion *DEVICE;
    axisThreadOne* AxisWorkOne;//轴运动
    QThread* AxisThreadOne;//轴运动

    axisThreadTwo* AxisWorkTwo;//轴运动
    QThread* AxisThreadTwo;//轴运动

    axisThreadThree* AxisWorkThree;//轴运动
    QThread* AxisThreadThree;//轴运动
    AutofocusThread *autothread_1;
     AutofocusThread *autothread_2;
    Mat image;
    AxisRelData AxisRel_camera_1;
    AxisRelData AxisRel_camera_2;
    vector<double>autoendcanshu;
    double maxqingxidu(AutofocusThread *autothread);

public slots:
    void GetInstruction(QString str);
    void getoneimage(CImageDataPointer & objImageDataPointer);
signals:
    void sigAxisMoveRelPT(int index,double acceleration,double distance,double time);
    void sigAxisMoveAbsPT(int index,double acceleration,double distance,double time);
    void sigstartmove(int axhand, axis *axis);
    void image_measure(int num,Mat image);
    void softmode_1();
    void softmode_2();
    void softmode_3();
    void softmode_4();
    void softmode_5();
    void softmode_6();
    void softmode_7();
    void softmode_8();
    void cam6act2();
};

#endif // MEASUREFUNCTION_H
