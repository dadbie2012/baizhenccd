#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QWidget>
#include <QtNetwork>
#include<iostream>

#include<opencv2/opencv.hpp>
#include<visionmeasure.h>
using namespace std;
using namespace cv;

namespace Ui {
class TcpServer;
}

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = nullptr);
    ~TcpServer();
 VisionMeasure *measure;
public slots:
    void on_pushButton_start_clicked();

    void on_pushButton_send_clicked();
signals:
     void sendclientresult(QString name,QByteArray str,bool check);
     void sendcamera_6_image(Mat image);
private:
    Ui::TcpServer *ui;
    //TCP服务器
       QTcpServer *mServer;
       QTcpSocket *mSocket;

};

#endif // TCPSERVER_H
