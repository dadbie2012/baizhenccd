#ifndef VISIONDAHENGCAMERA_H
#define VISIONDAHENGCAMERA_H
#include <QtWidgets/QMainWindow>
#include <iostream>
#include "GalaxyIncludes.h"
#include "QDateTime"
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QRadioButton>
#include <QObject>
#include"iostream"
#include "QDebug"
#include "QDateTime"
#include <direct.h>
#include <iostream>
#include <QFileDialog>
#include"QDir"
#include<QMenuBar>
#include <QToolBar>
#include <QLabel>
#include<QRadioButton>
#include <qpainter.h>
#include  <QThread>
#include<QTimer>
#include<opencv2/opencv.hpp>
#include<QMutex>
#include<QQueue>
#include<chuankou.h>
#include<visionmeasure.h>
#include<datevar.h>
#include<cgxbitmap2.h>
using namespace std;
using namespace cv;
class VisionDaHengCamera:public QObject
{
    Q_OBJECT
    //用户继承采集事件处理类
    class CSampleCaptureEventHandler : public ICaptureEventHandler
    {
    public:
        //---------------------------------------------------------------------------------
        /**
            \brief   采集回调函数
            \param   objImageDataPointer      图像处理参数
            \param   pFrame                   用户参数
            \return  无
            */
        //----------------------------------------------------------------------------------
        void DoOnImageCaptured(CImageDataPointer&objImageDataPointer, void* pUserParam)
        {

            try
            {
                VisionDaHengCamera*  Camera = (VisionDaHengCamera*)pUserParam;
                Camera->exposeTimesetting();
                if(Camera->autofocus){

                    emit Camera->sendautoimage(QDateTime::currentDateTime(),objImageDataPointer);

                }
                if(Camera->getoneimage){

                    DateVar::automutex_1.lock();
                    DateVar::autowaitcondition_1.wakeOne();
                    cout<<"ppppp"<<endl;
                    // Camera->sendoneimage(objImageDataPointer);
                    Camera->pointtomat(objImageDataPointer);
                    //  cout<<"biaojo222"<<endl;
                    cout<<"qqqqq"<<endl;
                    Camera->getoneimage=false;
                    DateVar::automutex_1.unlock();
                }
                emit Camera->sendimage(objImageDataPointer);

            }
            catch (exception& e) {
                qDebug()<<"DoOnImageCaptured error";
            }
            catch (CGalaxyException)
            {
                qDebug()<<"DoOnImageCaptured error";
            }

        }
    };

public:
    VisionDaHengCamera(GxIAPICPP::gxstring strSN,int num);
    ~VisionDaHengCamera();
public:
    int Num;
    bool color;
    int count;
    int camearmeasurenum=0;
    CGXDevicePointer m_objDevicePtr; //设备指针，指向打开的相机
    CGXFeatureControlPointer m_objRemoteFeatureControlPtr; //（远端）设备属性控制器指针
    CGXFeatureControlPointer m_objFeatureControlPtr; //本地和流属性控制器
    CGXStreamPointer m_objStreamPtr; //流指针，指向相机打开的流
    GX_DEVICE_OFFLINE_CALLBACK_HANDLE m_hDeviceOffline; //掉线事件
    GX_DEVICE_CLASS_LIST objDeviceClass;//设备类型
    CGXDeviceInfo m_deviceInfo;//设备信息
    QString m_firmName;//厂商名称
    QString m_modelName;//设备型号
    QString m_serialNumName;//序列号
    QString m_ipName;//ip地址
    QString m_maskName;//掩码
    QString m_macName;//MAC地址
    int64_t m_width;
    int64_t m_height;
    QString m_bitDepth;
    cv::Mat capturedImg; //相机采集的图片
    int counttest;
    int ifmeasure;
    bool ifsave;
    std::vector<double> Autofocus_image_definition;
    std::vector<QDateTime> Autofocus_time;
    bool dection=true;
    bool autofocus=false;
    bool autufocus;
    //相机状态判断
    bool isOpenCam; //相机是否打开
    bool isOpenStream; //相机流是否打开
    bool isopenstream_;
    bool isOffline; //设备是否掉线
    bool isTrigger; //相机是否触发
    bool software;
    bool Autofocus_status;
    bool ifexpand=false;;
    bool getoneimage=false;
    int ifsaveimage;
    int exposeTime; //曝光时间
    QString m_triggerMode;
    QString m_triggerSource;
    ICaptureEventHandler* pCaptureEventHandler=nullptr;
    IDeviceOfflineEventHandler* pDeviceOfflineEventHandler = nullptr;
    QDateTime curDateTime;
    QTimer * timer;
    double zhenlv_count;
    int ExposureTime;
    QString test;
    VisionMeasure *measure;
    QImage  imgForDisplay;
    Mat image;
    //保存图像路径
    QString folderPath_success;
    QString folderPath_fail;
    Mat triggerimage;
    GxIAPICPP::gxstring strSN;
    QMutex mutex;
    QQueue<QPixmap>ImageQueue;
    // CImageDataPointer & objImage;
    // bool image_measure(int num,Mat image);
    int bmp_write(unsigned char *image, int xsize, int ysize, char *filename);
    void exposeTimesetting();  void DoOnImageCaptured(CImageDataPointer& objImageDataPointer);
    void DoOnDeviceOfflineEvent(void* pUserParam); //掉线事件回调函数
    void __IsSupportColor(CGXDevicePointer& objCGXDevicePointer, bool &bIsColorFilter);
    double ImageDefinitionBrenner(cv::Mat &image);
    int ImageDefinitionxiangsu(cv::Mat &image);
    void pointtomat(CImageDataPointer & objImageDataPointer);
signals:
    void sendData2(CImageDataPointer & objImageDataPointer);
    void sendautoimage(QDateTime time,CImageDataPointer & objImageDataPointer);
    void sendimage(QPixmap image);
    void sendLog(QString log);
    void sendzhenlv(double zhenlv);
    void sendresult(QString name,QString result,bool check);
    void sendinformationwrite(int num,bool check);
    void sendDate(QQueue<QPixmap>ImageQueue,VisionDaHengCamera*camera);
    void sendexpandDate(CImageDataPointer & objImageDataPointer);
    void sendimage(CImageDataPointer & objImageDataPointer);
    void saveimage(CImageDataPointer & objImageDataPointer,string  path);
    void ifopencamera(int num,int num2);
    void sendoneimage(CImageDataPointer & objImageDataPointer);


public slots:
    void openDevice_clicked();
    void closeDevice_clicked();
    void startCapture_clicked();
    void stopCapture_clicked();
    void TriggerSoftware_clicked();
    void opencamera();
    void closecamera();
    void startcapture();
    void stopcapture();
    void Software();
    void zhenlvcount();
    void image_measure(Mat image);


};

#endif // VISIONDAHENGCAMERA_H

