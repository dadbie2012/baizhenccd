#ifndef VISIONMAINWINDOW_H
#define VISIONMAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<QTimer>
#include<QDateTime>
#include<visiondahengcamera.h>
#include<vector>
#include<chuankou.h>
#include<QSerialPort>
#include<QSerialPortInfo>
#include<QList>
#include<QByteArray>
#include<client.h>
#include<setparameter.h>
#include<detectionresultform.h>
#include<expandform.h>
#include<fineline/finelineform.h>
#include<cgxbitmap2.h>
#include<visionmeasure.h>
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
#include<settingmeasureform.h>
#include<QImage>
#include<datevar.h>
#include <qsysinfo.h>
#include<computerinfothread.h>
#include<motioncontrolform.h>
#include<measurefunction.h>
#include<autofocusform.h>
#include<tcpserver.h>

#pragma comment(lib,"user32")
using namespace std;

#define MB (1024*1024)

QT_BEGIN_NAMESPACE
namespace Ui { class VisionMainWindow; }
QT_END_NAMESPACE
struct handle_data {
    unsigned long process_id;
    HWND best_handle;
};
class VisionMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    VisionMainWindow(QWidget *parent = nullptr);
    ~VisionMainWindow();
    //灯光状态
    bool lightstate_1=true;
    bool lightstate_2=true;
    QString folderPath;
    QString folderPath_1;
    QString folderPath_2;
    QString folderPath_3;
    QString folderPath_4;
    QString folderPath_5;
    QString folderPath_6;
    QString folderPath_7;
    QString folderPath_8;
    QString folderPath_9;
    QString folderPath_10;
    QString folderPath_11;
    QString folderPath_12;
    QString folderPath_13;
    QString folderPath_14;
    QString folderPath_15;
    QString folderPath_16;
    Mat imagemeasure_1;
    Mat imagemeasure_2;
    Mat imagemeasure_3;
    Mat imagemeasure_4;
    Mat imagemeasure_5;
    Mat imagemeasure_6;
    Mat imagemeasure_7;
    Mat imagemeasure_8;
    QLabel *labCellIndex;

    qint64 id=0;


    bool expand=false;

private slots:
    void timeupdate();
    void getLog(QString log);
    void on_software_1_clicked();
    void on_start_clicked();
    void on_chuankou_clicked();
    void on_TCP_clicked();
    void on_setparameter_clicked();
    void on_measure_clicked();
    void getinstruction(QString name);
    void getlightsituation(QString situation,int num);    
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_Log_textChanged();
    void updatesettingmeasure(int num);
    void on_stop_clicked();
    void saveimage(CImageDataPointer & objImageDataPointer,string path);
    void ifopencamera(int num,int num2);
    void getcomputerinfo(QString info);
    void on_motioncontrol_clicked();

    void on_autofocus_clicked();
    void getcam6act2();

    void on_triggermode_5_currentIndexChanged(int index);

signals:
    void opencamera_1();
    void opencamera_2();
    void opencamera_3();
    void opencamera_4();
    void opencamera_5();
    void opencamera_6();
    void opencamera_7();
    void opencamera_8();
    void closecamera_1();
    void closecamera_2();
    void closecamera_3();
    void closecamera_4();
    void closecamera_5();
    void closecamera_6();
    void closecamera_7();
    void closecamera_8();
    void startcapture_1();
    void startcapture_2();
    void startcapture_3();
    void startcapture_4();
    void startcapture_5();
    void startcapture_6();
    void startcapture_7();
    void startcapture_8();
    void stopcapture_1();
    void stopcapture_2();
    void stopcapture_3();
    void stopcapture_4();
    void stopcapture_5();
    void stopcapture_6();
    void stopcapture_7();
    void stopcapture_8();
    void softmode_1();
    void softmode_2();
    void softmode_3();
    void softmode_4();
    void softmode_5();
    void softmode_6();
    void softmode_7();
    void softmode_8();
    void sendloadimage_1(Mat);
    void sendloadimage_2(Mat);
    void sendloadimage_3(Mat);
    void sendloadimage_4(Mat);
    void sendloadimage_5(Mat);
    void sendloadimage_6(Mat);
    void sendloadimage_7(Mat);
    void sendloadimage_8(Mat);
    void openlight(int);
    void closelight(int);


private:
    Ui::VisionMainWindow *ui;
    void init();

    //相机

    QThread *camerathread_1;
    QThread *camerathread_2;
    QThread *camerathread_3;
    QThread *camerathread_4;
    QThread *camerathread_5;
    QThread *camerathread_6;
    QThread *camerathread_7;
    QThread *camerathread_8;
    QThread *bitmapthread_1;
    QThread *bitmapthread_2;
    QThread *bitmapthread_3;
    QThread *bitmapthread_4;
    QThread *bitmapthread_5;
    QThread *bitmapthread_6;
    QThread *bitmapthread_7;
    QThread *bitmapthread_8;
     QThread *measurefuntionthread;
     MeasureFunction *functionn;
    CGXBitmap2 *bitmap_1;
    CGXBitmap2 *bitmap_2;
    CGXBitmap2 *bitmap_3;
    CGXBitmap2 *bitmap_4;
    CGXBitmap2 *bitmap_5;
    CGXBitmap2 *bitmap_6;
    CGXBitmap2 *bitmap_7;
    CGXBitmap2 *bitmap_8;
    ChuanKou *chuankou;
    Client *client;
    TcpServer *server;
    SetParameter *setparameter;
    DetectionResultForm *detectionresultform;
    ExpandForm *expandform;
    FinelineForm *findlineform;
    VisionMeasure *measure;
    QProcess* m_process;
    QWindow* m_window;
    SettingMeasureForm *settingmeasure;
    computerinfothread *cominfo;
    MotionControlForm *motionform;
    AutofocusForm *autofocusform;


};
#endif // VISIONMAINWINDOW_H
