#ifndef AXISTHREADTWO_H
#define AXISTHREADTWO_H

#include <QObject>
#include "axisthreadone.h"
#include <vector>
#include<datevar.h>
using namespace std;

class axisThreadTwo : public QObject
{
    Q_OBJECT
public:
    explicit axisThreadTwo(QObject *parent = nullptr);
    ~ axisThreadTwo();

public slots:
    void slot_getDistanceTime(int axhand, axis *axis);
    void slot_getDistanceTime2(int axhand, axis *axis);
    void slot_getDistanceTime3(int axhand, axis *axis);
    void slot_getDistanceTime4(int axhand, axis *axis);

signals:
    void sigendmove();
    void sigendmove2();
    void sigendmove3();
    void sigendmove4();
    void sigendmove_2_1();
    void sigendmove_2_2();
    void sigendmove_2_3();
    void sigendmove_2_4();
public:

    vector<QDateTime>time;
    vector<double> position;

};

#endif // AXISTHREADTWO_H
