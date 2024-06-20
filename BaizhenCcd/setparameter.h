#ifndef SETPARAMETER_H
#define SETPARAMETER_H

#include <QWidget>
#include<QMessageBox>
#include<iostream>
#include <qsettings.h>
#include<QSettings>
#include<visionmeasure.h>
using namespace  std;


namespace Ui {
class SetParameter;
}

class SetParameter : public QWidget
{
    Q_OBJECT

public:
    explicit SetParameter(QWidget *parent = nullptr);
    ~SetParameter();
    void getini();
    void setini();

private slots:


    void on_set_1_clicked();


private:
    Ui::SetParameter *ui;
};

#endif // SETPARAMETER_H
