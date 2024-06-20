#ifndef CHUANKOU_H
#define CHUANKOU_H

#include <QWidget>
#include<QSerialPort>
#include<QSerialPortInfo>
#include<QList>
#include<QByteArray>
#include<QDateTime>
#include<iostream>

namespace Ui {
class ChuanKou;
}

class ChuanKou : public QWidget
{
    Q_OBJECT

public:
    explicit ChuanKou(QWidget *parent = nullptr);
    ~ChuanKou();
    bool lightsituation_1=false;
    bool lightsituation_2=false;
    bool lightsituation_3=false;
    bool lightsituation_4=false;
    bool lightsituation_5=false;
    bool lightsituation_6=false;
    bool lightsituation_7=false;
    bool lightsituation_8=false;
    bool lightsituation_9=false;
    bool lightsituation_10=false;
    bool lightsituation_11=false;
    bool lightsituation_12=false;
    bool lightsituation_13=false;
    bool lightsituation_14=false;
    bool lightsituation_15=false;
    bool lightsituation_16=false;
    bool lightsituation_17=false;
    bool lightsituation_18=false;
    void openlight_all();
    void closelight_all();
signals:
     void sendLog(QString log);
     void sendlightchange(QString situation,int num);
public slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void getinformation();
    void on_openlight_clicked();
    void on_pushButton_4_clicked();
    void openlight(int num);
    void closelight(int num);

private:
    Ui::ChuanKou *ui;
    QSerialPort *port;
};

#endif // CHUANKOU_H
