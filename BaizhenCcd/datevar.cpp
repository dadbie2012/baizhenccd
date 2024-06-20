#include "datevar.h"

DateVar::DateVar()
{

}

void DateVar::setdate()
{
    QSettings settings("./Control Parameter.ini",QSettings::IniFormat);

    ExposeTime_1 = settings.value("exposetime_1","").toInt();
    ExposeTime_2 = settings.value("exposetime_2","").toInt();
    ExposeTime_3 = settings.value("exposetime_3","").toInt();
    ExposeTime_4 = settings.value("exposetime_4","").toInt();
    ExposeTime_5 = settings.value("exposetime_5","").toInt();
    ExposeTime_6 = settings.value("exposetime_6","").toInt();
    ExposeTime_7 = settings.value("exposetime_7","").toInt();
    ExposeTime_8 = settings.value("exposetime_8","").toInt();


}

int DateVar::ExposeTime_1=0;
int DateVar::ExposeTime_2=0;
int DateVar::ExposeTime_3=0;
int DateVar::ExposeTime_4=0;
int DateVar::ExposeTime_5=0;
int DateVar::ExposeTime_6=0;
int DateVar::ExposeTime_7=0;
int DateVar::ExposeTime_8=0;
QMutex DateVar::automutex_1;
QWaitCondition DateVar::autowaitcondition_1;
//自动对焦参数
int DateVar::autofocusroi_1_start_x=0;
int DateVar::autofocusroi_1_start_y=0;
int DateVar::autofocusroi_1_width=0;
int DateVar::autofocusroi_1_height=0;
int DateVar::autofocusfunction_1=0;
int DateVar::autofocuspositioncankao_1=0;
double DateVar::autofocusstartposition_1=0;
double DateVar::autofocusupdistance_1=0;
double DateVar::autofocusdowndistance_1=0;
double DateVar::autofocusuptime_1=0;
double DateVar::autofocusdowntime_1=0;
double DateVar::autofocusreturntime_1=0;
double DateVar::autofocusjixiebuchang_1=0;
double DateVar::autofocusfenshuyuzhi_1=0;
int DateVar::autofocusifnihe_1=0;

int DateVar::autofocusroi_2_start_x=0;
int DateVar::autofocusroi_2_start_y=0;
int DateVar::autofocusroi_2_width=0;
int DateVar::autofocusroi_2_height=0;
int DateVar::autofocusfunction_2=0;
int DateVar::autofocuspositioncankao_2=0;
double DateVar::autofocusstartposition_2=0;
double DateVar::autofocusupdistance_2=0;
double DateVar::autofocusdowndistance_2=0;
double DateVar::autofocusuptime_2=0;
double DateVar::autofocusdowntime_2=0;
double DateVar::autofocusreturntime_2=0;
double DateVar::autofocusjixiebuchang_2=0;
double DateVar::autofocusfenshuyuzhi_2=0;
int DateVar::autofocusifnihe_2=0;

double DateVar::autofocusscore=0;
double DateVar::autofocustime=0;
double DateVar::autofocusposition=0;
double DateVar::usage_rate_c=0;
double DateVar::usage_rate_d=0;

