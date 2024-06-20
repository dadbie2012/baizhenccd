#ifndef DATEVAR_H
#define DATEVAR_H
#include<QSettings>
#include <QMutex>
#include <QWaitCondition>

class DateVar
{
public:
    DateVar();
    static void setdate();
    static int ExposeTime_1;
    static int ExposeTime_2;
    static int ExposeTime_3;
    static int ExposeTime_4;
    static int ExposeTime_5;
    static int ExposeTime_6;
    static int ExposeTime_7;
    static int ExposeTime_8;
    static QMutex automutex_1;
    static QWaitCondition autowaitcondition_1;
    //自动对焦参数
    static int autofocusroi_1_start_x;
    static int autofocusroi_1_start_y;
    static int autofocusroi_1_width;
    static int autofocusroi_1_height;
    static int autofocusfunction_1;
     static int autofocuspositioncankao_1;
    static double autofocusstartposition_1;
    static double autofocusupdistance_1;
    static double autofocusdowndistance_1;
    static double autofocusuptime_1;
    static double autofocusdowntime_1;
    static double autofocusreturntime_1;
    static double autofocusjixiebuchang_1;
    static double autofocusfenshuyuzhi_1;
    static int autofocusifnihe_1;

    static int autofocusroi_2_start_x;
    static int autofocusroi_2_start_y;
    static int autofocusroi_2_width;
    static int autofocusroi_2_height;
    static int autofocusfunction_2;
     static int autofocuspositioncankao_2;
    static double autofocusstartposition_2;
    static double autofocusupdistance_2;
    static double autofocusdowndistance_2;
    static double autofocusuptime_2;
    static double autofocusdowntime_2;
    static double autofocusreturntime_2;
    static double autofocusjixiebuchang_2;
    static double autofocusfenshuyuzhi_2;
    static int autofocusifnihe_2;

    static double autofocusscore;
    static double autofocusposition;
    static double autofocustime;
    static double usage_rate_c;
     static double usage_rate_d;




};

#endif // DATEVAR_H
