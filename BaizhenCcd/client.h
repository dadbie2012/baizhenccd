#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QtNetwork>
#include<iostream>
#include<QDateTime>
#include <QMetaEnum>
using namespace std;

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    void instructionprocessing(QString str);
    void instructionprocessing_tiaoshi(QString str);
    vector<int> camerastat();
    vector<int> camerastat_2(QString name);
    void dateprocess(QString name,vector<int> date);
    QByteArray dateprocess_2(QString name,QByteArray date,bool check);
    void getdate(QString str);
    QString date;
    bool if_exception_1=false;
    bool if_exception_2=false;
    bool if_exception_3=false;
    bool if_exception_4=false;
    bool if_exception_5=false;
    bool if_exception_6=false;

    bool if_action_1=true;
    bool if_action_2=true;
    bool if_action_3=true;
    bool if_action_4=true;
    bool if_action_5=true;
    bool if_action_6=true;

    bool if_finish_1=true;
    bool if_finish_2=true;
    bool if_finish_3=true;
    bool if_finish_4=true;
    bool if_finish_5=true;
    bool if_finish_6=true;

    bool moshi=true;
    QByteArray resultarr;
    QByteArray resultarr_2;
     QString ip_;
    quint16 port;
    QTimer m_timer;
    bool if_first=true;




public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void getresult(QString name,QByteArray result,bool check);
    void on_pushButton_3_clicked();
    void reconnect(); //重新连接函数
     void slotTimeout();  //处理timeou信号

signals:
    void instruction(QString instruction);
     void sendLog(QString log);
     void senddate( QStringList list);
private:
    Ui::Client *ui;
    QTcpSocket *mSocket;
};



#endif // CLIENT_H
