#include "exposetimesetting.h"
#include "ui_exposetimesetting.h"

exposetimesetting::exposetimesetting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::exposetimesetting)
{
    ui->setupUi(this);
}

exposetimesetting::~exposetimesetting()
{
    delete ui;
}

void exposetimesetting::exposetimeget(int id)
{
    num=id;
    QSettings settings("./Control Parameter.ini",QSettings::IniFormat);
    switch (id) {
    case 1:
         ui->lineEdit->setText(QString::number(DateVar::ExposeTime_1));
        break;
    case 2:
         ui->lineEdit->setText(QString::number(DateVar::ExposeTime_2));
        break;
    case 3:
         ui->lineEdit->setText(QString::number(DateVar::ExposeTime_3));
        break;
    case 4:
         ui->lineEdit->setText(QString::number(DateVar::ExposeTime_4));
        break;
    case 5:
         ui->lineEdit->setText(QString::number(DateVar::ExposeTime_5));
        break;
    case 6:
         ui->lineEdit->setText(QString::number(DateVar::ExposeTime_6));
        break;
    case 7:
         ui->lineEdit->setText(QString::number(DateVar::ExposeTime_7));
        break;
    case 8:
         ui->lineEdit->setText(QString::number(DateVar::ExposeTime_8));
        break;


    default:
        break;
    }

}

void exposetimesetting::on_pushButton_clicked()
{
    QSettings settings("./Control Parameter.ini",QSettings::IniFormat);
     QString text;
    switch (num) {
    case 1:

        text = ui->lineEdit->text();    //获取QLineEdit的文本内容
        settings.setValue("exposetime_1",text);
        DateVar::ExposeTime_1=text.toInt();
        break;
    case 2:

        text = ui->lineEdit->text();    //获取QLineEdit的文本内容
        settings.setValue("exposetime_2",text);
        DateVar::ExposeTime_2=text.toInt();
        break;
    case 3:

        text = ui->lineEdit->text();    //获取QLineEdit的文本内容
        settings.setValue("exposetime_3",text);
        DateVar::ExposeTime_3=text.toInt();
        break;
    case 4:

        text = ui->lineEdit->text();    //获取QLineEdit的文本内容
        settings.setValue("exposetime_4",text);
        DateVar::ExposeTime_4=text.toInt();
        break;
    case 5:

        text = ui->lineEdit->text();    //获取QLineEdit的文本内容
        settings.setValue("exposetime_5",text);
        DateVar::ExposeTime_5=text.toInt();
        break;
    case 6:

        text = ui->lineEdit->text();    //获取QLineEdit的文本内容
        settings.setValue("exposetime_6",text);
        DateVar::ExposeTime_6=text.toInt();
        break;
    case 7:

        text = ui->lineEdit->text();    //获取QLineEdit的文本内容
        settings.setValue("exposetime_7",text);
        DateVar::ExposeTime_7=text.toInt();
        break;
    case 8:

        text = ui->lineEdit->text();    //获取QLineEdit的文本内容
        settings.setValue("exposetime_8",text);
        DateVar::ExposeTime_8=text.toInt();
        break;


    default:
        break;
    }
    QMessageBox::information(this,"info","setting succeed!");

}
