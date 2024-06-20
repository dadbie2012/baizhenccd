#ifndef AUTOFOCUSTHREAD_H
#define AUTOFOCUSTHREAD_H
#include<QPixmap>
#include<windows.h>
#include<vector>
#include<mutex>
#include<QMutexLocker>
#include<QReadWriteLock>
#include<queue>
#include "GalaxyIncludes.h"
#include<QDateTime>
#include "GalaxyIncludes.h"
#include<opencv2/opencv.hpp>
#include<QThread>
#include<datevar.h>
using namespace std;
using namespace cv;

class AutofocusThread:public QThread
{    
    Q_OBJECT
public:
    AutofocusThread(int num);
    void run() override;
    std::vector<cv::Mat> Autofocus_image;
    std::vector<double> Autofocus_image_definition;
    std::vector<QDateTime> Autofocus_time;
    queue<CImageDataPointer>buffer;
    double ImageDefinitionBrenner(cv::Mat &image);
    double ImageDefinitionxiangsu(cv::Mat &image);
     double ImageDefinitionconnect(cv::Mat &image);
    int count=0;
    bool autorun;
    Rect imageroi;
    int biaoji;
signals:
    void finsinlly();

public slots:
    void getautodate(QDateTime time,CImageDataPointer & objImageDataPointer);
    void getautofocusroirect(Rect roi);
};

#endif // AUTOFOCUSTHREAD_H
