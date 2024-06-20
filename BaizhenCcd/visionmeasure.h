#ifndef VISIONMEASURE_H
#define VISIONMEASURE_H
#include <iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include "high_shape_match.h"
#include<windows.h>
#include <complex>
#include<QTransform>
#include<QImage>
#include<fineline/CCaliperGUI.h>
#include<vector>
#include<iomanip>
#include<QDateTime>
#include<QThread>
#include<math.h>
#include<QApplication>
#include<QMessageBox>
#include<QSettings>
#include <QMutex>
#include <QWaitCondition>
#include<QDateTime>
#include<datevar.h>
#include<QDebug>
#define M_PI (3.14159265358979323846)

#pragma comment(lib, "high_shape_match.lib")
using namespace cv;
using namespace std;
using namespace mypr;
using namespace chrono;

class VisionMeasure:public QObject
{
    Q_OBJECT
public:
    VisionMeasure();
    static void loadtemplate(int num);
    static bool camera_measure_1(Mat src,VisionMeasure *duixiang);
    static bool camera_measure_2(Mat src,VisionMeasure *duixiang);
    static bool camera_measure_3(Mat src,VisionMeasure *duixiang);
     static bool camera_measure_3_2(Mat src,VisionMeasure *duixiang);
    static bool camera_measure_4(Mat src,VisionMeasure *duixiang);
     static bool camera_measure_4_2(Mat src,VisionMeasure *duixiang);
    static bool camera_measure_5(Mat src,VisionMeasure *duixiang);
     static bool camera_measure_5_2(Mat src,VisionMeasure *duixiang);
    static bool camera_measure_6(Mat src,VisionMeasure *duixiang);
    static bool camera_measure_7(Mat src,VisionMeasure *duixiang);
    static bool camera_measure_8();
    static QPair<float,float>getRobotPosition(float x,float y);
    Mat gray2rainbow(const Mat& scaledGray);
    int feature_show(cv::Mat& Insp, int model_id);
    int match_show(Mat& Insp, int model_id, int x0, int y0, Match* pMatches, int count, int subpixel = 0);
    vector<QPoint> coordinatetransformation(double dx,double dy,double angle,double x1,double y1,double x2,double y2,double a1,double b1,double a2,double b2,double a3,double b3,double a4,double b4);
    vector<QPoint> real_coordinatetransformation(double dx,double dy,double angle,double x1,double y1,double x2,double y2,double a1,double b1,double a2,double b2,double a3,double b3,double a4,double b4);
    Rect get_IOU(cv::Rect rect1, cv::Rect rect2);
    QTransform Transformchengfa(QTransform t1,QTransform t2);
    vector<Point> findline(QPoint start,QPoint end,QImage image,Mat src,double length,QRectF rect,double scale_parameter_1,double scale_parameter_2,int threshold,int polarity,int num);
    double getDistance(Point2f pointO, Point2f pointA);
    double getDist_P2L(Point2f pointP, Point2f pointA, Point2f pointB);
    Point calculate_foot_point(vector<Point> ps);
    double measureangle(Point x1,Point y1,Point x2,Point y2);
    QRectF boundingRect(vector<QPoint> result);
    cv::Point2f getCrossPoint(cv::Point2f point_1, cv::Point2f point_2, cv::Point2f point_3, cv::Point2f point_4);
    void measureyuzhi(Mat src);
    static int model_id_1;
    static int model_id_2;
    static int model_id_3;
    static int model_id_4;
    static int model_id_5;
    static int model_id_6;
    static float A;
    static float B;
    static float C;
    static float D;
    static float E;
    static float F;
    double camera_angle_1;
    double camera_dx_1;
    double camera_dy_1;
    double camera_score_1;
    static bool ifauto;
    QPoint linestart_1;
    QPoint lineend_1;
    CLineCaliperGUI *m_plineCaliperGUI;
    vector<double> result;
    bool ifsave;
    QString camera_1_result;
    static bool if_return_1;
    static bool if_return_2;
    static bool if_return_3;
    static bool if_return_4;
    static bool if_return_5;
    static bool if_return_6;
    static bool if_return_7;
    static bool if_return_8;
    static bool if_return_33;
    static bool if_return_44;
    static bool if_return_55;
    QStringList zuobiaolist;
    Rect roirect;
    vector<vector<float>>date;
    vector<vector<float>> sort_datee(vector<vector<float>> date);
    static String modelpath_1;
    static String modelpath_2;
       static String modelpath_6;
    static VisionMeasure *mytoola;
    //找线数组参数
    static double cam1_findlinearray[6][21];
    static double cam2_findlinearray[6][18];
    static double cam3_findlinearray[6][18];
    static double cam4_findlinearray[6][18];
    static double cam5_findlinearray[6][18];
    static double cam6_findlinearray[6][18];
    static double cam7_findlinearray[6][21];
    static double cam8_findlinearray[6][21];
    static void getmeasurecanshu();
   static double cam_threshold[8][6];

    static QMutex g_mutex;
    static QWaitCondition g_waitcondition;
    int num=0;

signals:
    void sendresult(Mat image,vector<double> result);
    void sendresult_to_form7(Mat image,vector<double> result);
     void sendresult_to_form8(Mat image,vector<double> result);
    void sendresult_2(Mat image,vector<double> result);
    void sendresult_3(Mat image,vector<double> result);
    void sendresult_4(Mat image,vector<double> result);
    void sendresult_5(Mat image,vector<double> result);
    void sendroi(Rect rect);
    void sendroi2(Rect rect);
    void sendresult_1(QString name,QString str,bool check);
    void sendresult_2(QString name,QString str,bool check);
    void sendresult_3(QString name,QString str,bool check);
    void sendresult_4(QString name,QString str,bool check);
    void sendresult_5(QString name,QString str,bool check);
    void sendinformationwrite(int cameranum,bool check);
    void sendclientresult(QString name,QByteArray str,bool check);
    void sendlog(QString log);
    void SigDeliverMessStatic(int num,int num2);
    void createmodellog(int num,int num2);
    void informationwrite(int cameranum, bool check);
public slots:
    void getdate(QStringList list);
    void SlotDeliverMessStatic(int num,int num2);


};

#endif // VISIONMEASURE_H
