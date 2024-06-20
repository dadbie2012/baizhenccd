#ifndef FORM_H
#define FORM_H

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
#include<datevar.h>
#include<exposetimesetting.h>
#include<QSettings>
QT_BEGIN_NAMESPACE
using namespace cv;
#include<QDateTime>
#define short_tanzhen 1
#define mid_tanzhen 2
#define long_tanzhen 3

namespace Ui {
class Form;
}
QT_END_NAMESPACE
class Form : public QFrame
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    Ui::Form *ui;
    Q_DISABLE_COPY(Form)
    QPixmap pixmap_;
    QPixmap pixmap_1;
    QPixmap pixmap_2;
    QPixmap pixmap_3;
    QPixmap pixmap_4;
    QPixmap pixmap_5;
    Mat sourceimage;
    QImage imageee;
    int num=0;
    // QQueue<QPixmap>ImageQueue;
    int id;
    int drawrect_id=0;
    exposetimesetting *exposetimeset;
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
    QMenu *m_pMenu;
    QAction *setstraightline;
    QAction *setline;
    QAction *setcircle;
    QAction *setrect;
    QAction *deletestraightline;
    QAction *deleteline;
    QAction *deletecircle;
    QAction *deleterect;
    QAction *deleteall;
    QAction *imageoperation;
    QAction *exposetime;

    QVector<int> _shape;                //全部容器
    QVector<QRect> _allShape;           //所有图形
    QVector<QVector<QPoint> > _pen;     //铅笔线容器
    QVector<QRect> _line;               //直线容器
    QVector<QRect> _straight_line;
    QVector<QRect> _ellipse;            //椭圆容器
    QVector<QRect> _rects;              //矩形容器

    int _width;                         //当前线宽
    QVector<int> _widths;               //线宽容器
    QVector<QColor> _colors;            //画笔颜色容器
    QVector<QColor> _fillcolors;        //填充色容器
    QVector<int> _isfills;              //填充标志容器
    int _isfill;                        //当前填充标志
    QColor _color;                      //当前画笔颜色
    QColor _fillcolor;                  //当前填充颜色

    QPoint _begin;                      //开始坐标
    bool _lpress = false;                        //鼠标按下标志
    int _drag = 0;
    int circle_drag = 0; //拖拽标志
    int _drawType = 0;                      //当前绘画类型标志
    QVector<QPoint> start;
    QVector<QPoint> end;

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
    bool ifimageoperation=false;
    void createMenu();
public slots:
    void getimage(QQueue<QPixmap>ImageQueue,VisionDaHengCamera*camera);
    void getimage2(Mat image);
    void getresult(Mat image,vector<double> result);

    void OnZoomInImage();       //图片放大
    void OnZoomOutImage();      //图片缩小
    void OnPresetImage();       //图片还原
    void getzhenlv(double zhenlv);
    void gettriggerimage(QPixmap pixmap);
     void getqimage(QImage image,QMutex *mutex);

signals:
    void SigColor(int, int, int);



};

#endif
