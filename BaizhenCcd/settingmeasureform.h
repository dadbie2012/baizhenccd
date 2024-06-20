#ifndef SETTINGMEASUREFORM_H
#define SETTINGMEASUREFORM_H

#include <QWidget>
#include<visionmeasure.h>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include<QPainter>
#include<QDebug>
#include<QImage>
#include<QFileDialog>
#include<QMessageBox>
#include<iostream>
#include "high_shape_match.h"
#include<fineline/finelineform.h>
#include<QSettings>
#include<setparameter.h>
#pragma comment(lib, "high_shape_match.lib")
using namespace cv;
using namespace std;
using namespace mypr;
using namespace chrono;

using namespace std;
namespace Ui {
class SettingMeasureForm;
}

class SettingMeasureForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingMeasureForm(QWidget *parent = nullptr);
     bool eventFilter(QObject *obj, QEvent *event);//事件过滤器
    ~SettingMeasureForm();
    void init_1();
    int feature_show(cv::Mat& Insp, int model_id);
    int match_show(Mat& Insp, int model_id, int x0, int y0, Match* pMatches, int count, int subpixel = 0);
    void LineFitLeastSquares(float *data_x, float *data_y, int data_n);
    Mat thinImage(Mat  src);
    Mat blob(Mat src);
    bool isModify;
    double x1,y1,x2,y2;
    Mat sourceimage;
    Mat erzhihuamat;
    QImage tempTestImg;
     QPixmap tempsorcepixmap;;
    bool ifmove=false;
    QPixmap resimage;
    QImage imageData_1;
     QImage tempqimage;
    QPixmap model_1;
    VisionMeasure *measure;
    double camera_angle_1=0;
    double camera_dx_1=0;
    double camera_dy_1=0;
    double camera_score_1=0;
    FinelineForm *findlineform;
    SetParameter *settingform;
    int width;
    int height;

    int cam1_line_biaoji=0;
    int cam_biaoji=1;
    int ThresholdTypes=0;
    int ThinThresholdTypes=0;
    Mat xihuaimage;


private slots:

    void on_updateimage_1_clicked();
    void on_loadimage_1_clicked();
    void on_loadmodel_1_clicked();
    void on_savemodel_1_clicked();
    void on_setmodel_1_clicked();
    void on_trainmodel_clicked();
    void getcreatemodellog(int num1,int num2);
    void on_modelmatch_1_clicked();
    void on_findline_clicked();
    void cam1_linebutton(int num,bool boo);
    void on_lineset_1_clicked();

    void on_camera_choose_currentIndexChanged(int index);

  //  void on_pushButton_clicked();

    void on_erzhihua_clicked();

    void on_blob_clicked();

    void on_setting_clicked();

    void on_pixel_clicked();

    void on_comboBox_currentIndexChanged(int index);



    void on_xihua_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_zhixiandu_clicked();

signals:
    void sendupdateimage(int num);
private:
    Ui::SettingMeasureForm *ui;
};

#endif // SETTINGMEASUREFORM_H
