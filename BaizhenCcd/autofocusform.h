#ifndef AUTOFOCUSFORM_H
#define AUTOFOCUSFORM_H

#include <QMainWindow>
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
#include<fineline/finelineform.h>
#include<QSettings>
#include<setparameter.h>
#include<visiondahengcamera.h>
static double angle(Point pt1, Point pt2, Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1 * dy2) / sqrt((dx1*dx1 + dy1 * dy1)*(dx2*dx2 + dy2 * dy2) + 1e-10);
}
namespace Ui {
class AutofocusForm;
}

class AutofocusForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutofocusForm(QWidget *parent = nullptr);
    ~AutofocusForm();
    int cam_biaoji=1;
    int autofunction=1;
    int positioncankao=0;
    QButtonGroup *buttonGroup;
    Mat Sourceimage;

    void init();
      void initstatic();

private slots:
   void on_save_clicked();
   void on_camerachoose_currentIndexChanged(int index);
   void cam1_linebutton(int num,bool bo);
   void on_function_choose_currentIndexChanged(int index);
   void on_showimage_clicked();

   void on_showroi_clicked();

   void on_pushButton_clicked();

private:
    Ui::AutofocusForm *ui;
};

#endif // AUTOFOCUSFORM_H
