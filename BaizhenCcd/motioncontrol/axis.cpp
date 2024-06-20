#include "axis.h"

axis::axis(QObject *parent) : QObject(parent)
{

}

axis::~axis()
{

}

double axis::get_axvellow()
{
    return axvellow;
}

double axis::get_axvelhigh()
{
    return axvelhigh;
}

double axis::get_axacc()
{
    return axacc;
}

double axis::get_axdec()
{
    return axdec;
}

double axis::get_axjerk()
{
    return axjerk;
}

int axis::get_sen_fra_num()
{
    return sen_fra_num;
}

float axis::get_sen_range_up()
{
    return sen_range_up;
}

float axis::get_sen_range_down()
{
    return sen_range_down;
}

QString axis::get_sensor_units()
{
    return sen_units;
}

QString axis::get_sen_name()
{
    return sen_name;
}

bool axis::get_isrange(float num)
{
    if(num>=sen_range_down&&num<=sen_range_up){

        return true;

    }
    else
    {

        return false;
    }
}

void axis::set_sensor_all_par(int fra, float up, float down, QString units)
{
    sen_fra_num=fra;
    sen_range_up=up;
    sen_range_down=down;
    sen_units=units;
}

void axis::set_axacc(double acc)
{
    axacc=acc;
}

void axis::set_data_point(double x, double y)
{
    axis_data.insert(x,y);
}

void axis::clear_data_point()
{
    axis_data.clear();
}

/*
#根据两点码值和两点实际值求随机码值的实际值
@x:实际码值
@y:实际数值
@x1:标定码值下量程
@y1:标定数值下量程
@x2:标定码值上量程
@y2:标定数值上量程
*/
double axis::get_actual_value(double y)
{
    if(axis_data.count()<2)
    {
        throw QString("data number error");
    }

    double x=0;
    double x1=0;
    double y1=0;
    double x2=0;
    double y2=0;
    QMap<double,double>::Iterator it=axis_data.begin();

    if(y<=axis_data.begin().value())
    {
        x1=(it).key();
        y1=(it).value();
        x2=(it+1).key();
        y2=(it+1).value();
        x=x1+((y-y1)*(x2-x1))/(y2-y1);
    }
    else if(y>=(axis_data.end()-1).value())
    {
        x1=(it+axis_data.size()-2).key();
        y1=(it+axis_data.size()-2).value();
        x2=(it+axis_data.size()-1).key();
        y2=(it+axis_data.size()-1).value();
        x=x1+((y-y1)*(x2-x1))/(y2-y1);
    }
    else if(y>axis_data.begin().value()&&y<(axis_data.end()-1).value())
    {
        int left=0;
        int right=axis_data.size()-1;
        while (left<right) {
            int mid=(left+right)/2;
            if(y==(it+mid).value())
            {
                left=mid;
                break;
            }
            else if(y>(it+mid).value())
            {
                left=mid;
                if(y<(it+mid+1).value())
                {
                    break;
                }

            }
            else if(y<(it+mid).value())
            {
                right=mid;
                if(y>(it+mid-1).value())
                {
                    left=mid-1;
                    break;
                }
            }
        }
        x1=(it+left).key();
        y1=(it+left).value();
        x2=(it+left+1).key();
        y2=(it+left+1).value();
        x=x1+((y-y1)*(x2-x1))/(y2-y1);

    }
    return x;


}
/*
#根据两点码值和两点实际值求随机实际值的码值
@x:实际码值
@y:实际数值
@x1:标定码值下量程
@y1:标定数值下量程
@x2:标定码值上量程
@y2:标定数值上量程
*/
double axis::get_code_value(double x)
{
    if(axis_data.count()<2)
    {
        throw QString("data number error");
    }

    double y=0;
    double x1=0;
    double y1=0;
    double x2=0;
    double y2=0;
    QMap<double,double>::Iterator it=axis_data.begin();

    if(x<=axis_data.begin().key())
    {
        x1=(it).key();
        y1=(it).value();
        x2=(it+1).key();
        y2=(it+1).value();
        y=y1+((x-x1)*(y2-y1))/(x2-x1);
    }
    else if(x>=(axis_data.end()-1).key())
    {
        x1=(it+axis_data.size()-2).key();
        y1=(it+axis_data.size()-2).value();
        x2=(it+axis_data.size()-1).key();
        y2=(it+axis_data.size()-1).value();
        y=y1+((x-x1)*(y2-y1))/(x2-x1);
    }
    else if(x>axis_data.begin().key()&&x<(axis_data.end()-1).key())
    {
        int left=0;
        int right=axis_data.size()-1;
        while (left<right) {
            int mid=(left+right)/2;
            if(x==(it+mid).key())
            {
                left=mid;
                break;
            }
            else if(x>(it+mid).key())
            {
                left=mid;
                if(x<(it+mid+1).key())
                {
                    break;
                }

            }
            else if(x<(it+mid).key())
            {
                right=mid;
                if(x>(it+mid-1).key())
                {
                    left=mid-1;
                    break;
                }
            }
        }
        x1=(it+left).key();
        y1=(it+left).value();
        x2=(it+left+1).key();
        y2=(it+left+1).value();
        y=y1+((x-x1)*(y2-y1))/(x2-x1);

    }
    return y;
}

int axis::get_data_map_count()
{
    return axis_data.count();
}

void axis::readConfig(QString a)
{
    QSettings  *setting = new QSettings(a, QSettings::IniFormat);

    setting->beginGroup("parameter");
    axvellow=setting->value("axvellow").toDouble();
    axvelhigh=setting->value("axvelhigh").toDouble();
    axacc=setting->value("axacc").toDouble();
    axdec=setting->value("axdec").toDouble();
    axjerk=setting->value("axjerk").toDouble();

    sen_fra_num=setting->value("sen_fra_num").toInt();
    sen_range_up=setting->value("sen_range_up").toDouble();
    sen_range_down=setting->value("sen_range_down").toDouble();
    sen_units=setting->value("sen_units").toString();
    sen_name=setting->value("sen_name").toString();
    setting->endGroup();

    QString key,val;
    int i=0;
    setting->beginGroup("arraypoint");
    axis_data_size=setting->value("data_size").toInt();
    for (i=0;i<axis_data_size;i++) {
        key="actual"+QString::number(i);
        val="code"+QString::number(i);
        axis_data.insert(setting->value(key).toDouble(),setting->value(val).toDouble());
    }
    setting->endGroup();
}

void axis::writeConfig(QString a)
{
    QSettings  *setting = new QSettings(a, QSettings::IniFormat);

    setting->beginGroup("parameter");
    setting->setValue("axvellow",axvellow);
    setting->setValue("axvelhigh",axvelhigh);
    setting->setValue("axacc",axacc);
    setting->setValue("axdec",axdec);
    setting->setValue("axjerk",axjerk);

    setting->setValue("sen_fra_num",sen_fra_num);
    setting->setValue("sen_range_up",sen_range_up);
    setting->setValue("sen_range_down",sen_range_down);
    setting->setValue("sen_units",sen_units);
    setting->setValue("sen_name",sen_name);
    setting->endGroup();

    QString key,val;
    int i=0;
    axis_data_size=0;
    QMap<double,double>::Iterator it=axis_data.begin();
    setting->beginGroup("arraypoint");
    while (it!=axis_data.end()) {
        key="actual"+QString::number(i);
        val="code"+QString::number(i);
        setting->setValue(key,it.key());
        setting->setValue(val,it.value());

        it++;
        axis_data_size++;
        i++;
    }
    setting->setValue("data_size",axis_data_size);
    setting->endGroup();
}

void axis::initConfig(QString path)
{
    QString axisname=path.right(9);
    axisname=axisname.left(5);
    //创建配置文件
    axvellow=2000;
    axvelhigh=8000;
    axacc=10000;
    axdec=10000;
    axjerk=0;

    sen_fra_num=2;
    sen_range_up=10;
    sen_range_down=0;
    sen_units="mm";
    sen_name=axisname;

    axis_data.insert(0,0);
    axis_data.insert(5,10000);
    axis_data_size=2;
}

void axis::checkConfig(QString path)
{
    QFile file(path);
    if (file.size() == 0) {
        initConfig(path);
        writeConfig(path);
    }
    else
    {
        readConfig(path);
    }
}
