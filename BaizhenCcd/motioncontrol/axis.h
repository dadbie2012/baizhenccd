#ifndef AXIS_H
#define AXIS_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QDebug>
#include <exception>
#include <iostream>
#include <stdio.h>
#include <QSettings>
#include <QFile>
#include<datevar.h>
#pragma execution_character_set("utf-8")//解决中文乱码

class axis : public QObject
{
    Q_OBJECT
public:
    explicit axis(QObject *parent = nullptr);
    ~axis();

    double get_axvellow();
    double get_axvelhigh();
    double get_axacc();
    double get_axdec();
    double get_axjerk();
    int get_sen_fra_num();//获取传感器小数位数
    float get_sen_range_up();//获取传感器上量程
    float get_sen_range_down();//获取传感器下量程
    QString get_sensor_units();//获取传感器单位
    QString get_sen_name();//获取传感器单位


    bool get_isrange(float num);//判断数据是否在量程范围内

    void set_sensor_all_par(int fra,float up,float down,QString units);//设置传感器所有参数
    void set_axacc(double acc);

    void set_data_point(double x,double y);//data_code_actual获取键和值
    void clear_data_point();//清除键与值
    double get_actual_value(double x);//求实际值
    double get_code_value(double y);//求码值
    int get_data_map_count();

    void readConfig(QString a);
    void writeConfig(QString a);
    void initConfig(QString axisname);
    void checkConfig(QString axisname);

signals:

private:
    double axvellow;
    double axvelhigh;
    double axacc;
    double axdec;
    double axjerk;

    int sen_fra_num;
    double sen_range_up;
    double sen_range_down;
    QString sen_units;
    QString sen_name;

    QMap<double,double> axis_data;
    int axis_data_size=0;

};

#endif // AXIS_H
