#ifndef DETECTIONRESULTFORM_H
#define DETECTIONRESULTFORM_H

#include <QWidget>
#include<QMessageBox>
#include<iostream>
#include <qsettings.h>
#include<QSettings>
#include<QTimer>
#include<windows.h>
using namespace  std;
namespace Ui {
class DetectionResultForm;
}

class DetectionResultForm : public QWidget
{
    Q_OBJECT

public:
    explicit DetectionResultForm(QWidget *parent = nullptr);
    ~DetectionResultForm();
    void setini2zero();
    void getini();
   // void informationwrite(int cameranum, bool check);

private slots:

 void informationwrite(int cameranum, bool check);
    void on_read_clicked();

    void on_dateclear_clicked();

private:
    Ui::DetectionResultForm *ui;
};

#endif // DETECTIONRESULTFORM_H
