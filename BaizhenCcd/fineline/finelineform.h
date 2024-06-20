#ifndef FINELINEFORM_H
#define FINELINEFORM_H

#include <QWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QtWidgets>
#include "myqgraphicsview.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include "fineline/caliberline.h"
#include "fineline/CCaliperGUI.h"
#include "fineline/common.h"
#include "fineline/controlline.h"
#include<fineline/myqgraphicsview.h>
#include<fineline/drawline.h>
#include<fineline/shapematch.h>
#include<QMatrix>

namespace Ui {
class FinelineForm;
}

enum STATE_FLAG_MAINWINDOW{
    CHOOSE_NULL,
    CHOOSE_PICTURE,
    CALIBERLINE
};
class FinelineForm : public QWidget
{
    Q_OBJECT

public:
    explicit FinelineForm(QWidget *parent = nullptr);
    ~FinelineForm();
    QTransform  Transformchengfa(QTransform t1,QTransform t2);
    QRectF boundingRect();
    static double start_x;
    static double start_y;
    static double end_x;
    static double end_y;
    static double pp_1_x;
    static double pp_1_y;
    static double pp_2_x;
    static double pp_2_y;
    static double pp_3_x;
    static double pp_3_y;
    static double pp_4_x;
    static double pp_4_y;
    static double lenght;
    static double scale_1;
    static double scale_2;
    static double threshold;
    static double polarity;
    static double num;
    Mat sourceimage;
    QImage imageData_1;

private slots:
    void on_pushButton_choose_picture_clicked();

    void on_pushButton_caliberline_clicked();

    void on_spinBox_caliper_number_valueChanged(int arg1);

   void on_pushButton_findline_clicked();

    void on_pushButton_refresh_clicked();

    //void on_pushButton_clicked();

    // void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

private:
    Ui::FinelineForm *ui;
    QImage Mat2QImage(const cv::Mat& InputMat);
private:

    STATE_FLAG_MAINWINDOW state_flag_maindow;
    CCaliberLine *my_caliberline;
     CCaliberLine *my_caliberline_2;
    QGraphicsScene *qgraphicsScene;
    QGraphicsPixmapItem *ImageItem;
    QString fileName;
    CControlLine *lineitem;
     CControlLine *lineitem2;
    myqgraphicsview *myqview;
    drawline *drawline2;

    shapematch *match;
    QPoint linestart;
    QPoint lineend;
    QRectF bound;
    QPointF PP[4]; //旋转后端点
    QPoint bound_caliber_after;
    float dx;
    float dy;
    float angle;
    CLineCaliperGUI *m_plineCaliperGUI;
    int nSigma = 1;
    int nThreshold = 30;
    int nTranslation = 1;
    int nFindLine = 0;
    int nMeasureNums = 12;


};

#endif // FINELINEFORM_H
