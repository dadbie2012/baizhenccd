#ifndef EXPANDFORM_H
#define EXPANDFORM_H

#include <QWidget>
#include<QFrame>
#include<windows.h>
#include<opencv2/opencv.hpp>
#include<QTimer>
#include "QPainter"
#include"iostream"
#include<QFile>
#include<QPainter>
#include <QMouseEvent>
#include <iostream>
#include<QMenuBar>
#include<QThread>
#include<QMutex>
#include<QQueue>
#include<visiondahengcamera.h>
QT_BEGIN_NAMESPACE
using namespace cv;
#include<QDateTime>

namespace Ui {
class ExpandForm;
}

class ExpandForm : public QFrame
{
    Q_OBJECT

public:
    explicit ExpandForm(QWidget *parent = nullptr);
    ~ExpandForm();
    Q_DISABLE_COPY(ExpandForm)
    QPixmap pixmap_;
    QPixmap pixmap_1;
    QPixmap pixmap_2;
    QPixmap pixmap_3;
    QPixmap pixmap_4;
    QPixmap pixmap_5;
   // QQueue<QPixmap>ImageQueue;
    int id;
    QImage imageee;

    double des_w_h_ratio_;
    double src_w_h_ratio_;
    int scale_w_;
    int scale_h_;
    int width_;
    int height_;
    QRect autofocusrect;
    Rect imageroirect;
    bool autofocus;
    QThread *thread;
    QMutex mutex;
    void paintEvent(QPaintEvent *) ;
    void SetVideoPixmap(QPixmap &pixmap);
    void setZoom(bool bZoom) { m_bZoom = bZoom; }//设置是否允许滚动缩放
    void wheelEvent(QWheelEvent *event) override;               //鼠标滚轮滚动
    void mouseDoubleClickEvent(QMouseEvent *event) override;    //鼠标双击还原图片大小事件
    void mousePressEvent(QMouseEvent *event) override;          //鼠标摁下
    void mouseMoveEvent(QMouseEvent *event) override;           //鼠标移动
    void mouseReleaseEvent(QMouseEvent *event) override;        //鼠标放开
    //键盘事件（按住ctrl 并滚动滚轮才可以放大或者缩小图片）
    void keyPressEvent(QKeyEvent *event);
    void  keyReleaseEvent(QKeyEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
private:
    QImage m_Image;           //原始图片
    QPixmap m_bTempPixmap; //当前画图展示的缩放移动后的图片
    QString m_strImagePath="";  //图片全路径名
    qreal ZoomValue = 1.0;  //鼠标缩放值
    int XPtInterval = 0;    //平移X轴的值
    int YPtInterval = 0;    //平移Y轴的值
    bool Pressed = false;   //鼠标是否被摁压
    bool m_bZoom = true; //是否按住滚动缩放
    QPoint OldPos;          //旧的鼠标位置
    QPoint m_nMovePos;
    int m_intPenWidth = 1;
    vector<double> result;
    vector<double> result_autofocus;
    double zhenlv;

public slots:
    void getimage(QQueue<QPixmap>ImageQueue,VisionDaHengCamera*camera);
    void acceptautofocussignal();
    void getresult(Mat image,vector<double> result);
    void getresult_autofocus(vector<double> result);
    void OnZoomInImage();       //图片放大
    void OnZoomOutImage();      //图片缩小
    void OnPresetImage();       //图片还原
    void getzhenlv(double zhenlv);
    void gettriggerimage(QPixmap pixmap);
  void getqimage(QImage image,QMutex *mutex);

signals:
    void SigColor(int, int, int);
    void autofocusroirect(Rect roi);
    void autofocusstart();


private:
    Ui::ExpandForm *ui;
};

#endif // EXPANDFORM_H
