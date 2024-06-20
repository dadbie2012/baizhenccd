#include "detectionresultform.h"
#include "ui_detectionresultform.h"

DetectionResultForm::DetectionResultForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectionResultForm)
{
    ui->setupUi(this);
      this->setWindowIcon(QIcon(":/image/image/caomei.png"));
    this->setAttribute(Qt::WA_QuitOnClose, false);

}

DetectionResultForm::~DetectionResultForm()
{
    delete ui;
}
void DetectionResultForm::setini2zero()
{
    QSettings settings("./QA.ini",QSettings::IniFormat);
    //将QLineEdit组件信息写入.ini
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_1","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_2","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_3","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_4","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_5","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_6","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_7","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_8","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_9","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_10","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_11","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_12","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_13","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_14","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_15","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_16","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_17","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_18","0");

    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_19","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_20","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_21","0");

    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_22","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_23","0");
    //获取QLineEdit的文本内容
    settings.setValue("lcdNumber_24","0");

}



void DetectionResultForm::getini()
{
    QSettings settings("./QA.ini",QSettings::IniFormat);
    //读取组件状态信息
    //设置QLineEdit内容
    QString text = settings.value("lcdNumber_1","").toString();
    ui->lcdNumber_1->display(text.toDouble());
    text = settings.value("lcdNumber_2","").toString();
    ui->lcdNumber_2->display(text.toDouble());
    text = settings.value("lcdNumber_3","").toString();
    ui->lcdNumber_3->display(text.toDouble());
    text = settings.value("lcdNumber_4","").toString();
    ui->lcdNumber_4->display(text.toDouble());
    text = settings.value("lcdNumber_5","").toString();
    ui->lcdNumber_5->display(text.toDouble());
    text = settings.value("lcdNumber_6","").toString();
    ui->lcdNumber_6->display(text.toDouble());
    text = settings.value("lcdNumber_7","").toString();
    ui->lcdNumber_7->display(text.toDouble());
    text = settings.value("lcdNumber_8","").toString();
    ui->lcdNumber_8->display(text.toDouble());
    text = settings.value("lcdNumber_9","").toString();
    ui->lcdNumber_9->display(text.toDouble());
    text = settings.value("lcdNumber_10","").toString();
    ui->lcdNumber_10->display(text.toDouble());
    text = settings.value("lcdNumber_11","").toString();
    ui->lcdNumber_11->display(text.toDouble());
    text = settings.value("lcdNumber_12","").toString();
    ui->lcdNumber_12->display(text.toDouble());
    text = settings.value("lcdNumber_13","").toString();
    ui->lcdNumber_13->display(text.toDouble());
    text = settings.value("lcdNumber_14","").toString();
    ui->lcdNumber_14->display(text.toDouble());
    text = settings.value("lcdNumber_15","").toString();
    ui->lcdNumber_15->display(text.toDouble());


    text = settings.value("lcdNumber_16","").toString();
    ui->lcdNumber_16->display(text.toDouble());
    text = settings.value("lcdNumber_17","").toString();
    ui->lcdNumber_17->display(text.toDouble());
    text = settings.value("lcdNumber_18","").toString();
    ui->lcdNumber_18->display(text.toDouble());
    text = settings.value("lcdNumber_19","").toString();
    ui->lcdNumber_19->display(text.toDouble());
    text = settings.value("lcdNumber_20","").toString();
    ui->lcdNumber_20->display(text.toDouble());
    text = settings.value("lcdNumber_21","").toString();
    ui->lcdNumber_21->display(text.toDouble());
    text = settings.value("lcdNumber_22","").toString();
    ui->lcdNumber_22->display(text.toDouble());
    text = settings.value("lcdNumber_23","").toString();
    ui->lcdNumber_23->display(text.toDouble());
    text = settings.value("lcdNumber_24","").toString();
    ui->lcdNumber_24->display(text.toDouble());


}

void DetectionResultForm::informationwrite(int cameranum, bool check)
{
    QSettings settings("./QA.ini",QSettings::IniFormat);
    //将QLineEdit组件信息写入.ini
    //获取QLineEdit的文本内容
   // cout<<"sssssssssssssssssssssssssssss"<<endl;
    switch (cameranum) {
    case 1:{
        if(check){
            ui->lcdNumber_1->display( ui->lcdNumber_1->value()+1);
            settings.setValue("lcdNumber_1",ui->lcdNumber_1->value());
            ui->lcdNumber_3->display( ui->lcdNumber_1->value()/(ui->lcdNumber_1->value()+ui->lcdNumber_2->value())*100);
            settings.setValue("lcdNumber_3",ui->lcdNumber_3->value());
        }else{
            ui->lcdNumber_2->display( ui->lcdNumber_2->value()+1);
            settings.setValue("lcdNumber_2",ui->lcdNumber_2->value());
            ui->lcdNumber_3->display( ui->lcdNumber_1->value()/(ui->lcdNumber_1->value()+ui->lcdNumber_2->value())*100);
            settings.setValue("lcdNumber_3",ui->lcdNumber_3->value());
        }


        break;
    }
    case 2:{
        if(check){
            ui->lcdNumber_4->display( ui->lcdNumber_4->value()+1);
            settings.setValue("lcdNumber_4",ui->lcdNumber_4->value());
            ui->lcdNumber_6->display( ui->lcdNumber_4->value()/(ui->lcdNumber_4->value()+ui->lcdNumber_5->value())*100);
            settings.setValue("lcdNumber_6",ui->lcdNumber_6->value());
        }else{
            ui->lcdNumber_5->display( ui->lcdNumber_5->value()+1);
            settings.setValue("lcdNumber_5",ui->lcdNumber_5->value());
            ui->lcdNumber_6->display( ui->lcdNumber_4->value()/(ui->lcdNumber_4->value()+ui->lcdNumber_5->value())*100);
            settings.setValue("lcdNumber_6",ui->lcdNumber_6->value());
        }

        break;
    }
    case 3:{
        if(check){
            ui->lcdNumber_7->display( ui->lcdNumber_7->value()+1);
            settings.setValue("lcdNumber_7",ui->lcdNumber_7->value());
            ui->lcdNumber_9->display( ui->lcdNumber_7->value()/(ui->lcdNumber_7->value()+ui->lcdNumber_8->value())*100);
            settings.setValue("lcdNumber_9",ui->lcdNumber_9->value());
        }else{
            ui->lcdNumber_8->display( ui->lcdNumber_8->value()+1);
            settings.setValue("lcdNumber_8",ui->lcdNumber_8->value());
            ui->lcdNumber_9->display( ui->lcdNumber_7->value()/(ui->lcdNumber_7->value()+ui->lcdNumber_8->value())*100);
            settings.setValue("lcdNumber_9",ui->lcdNumber_9->value());
        }

        break;
    }
    case 4:{
        if(check){
            ui->lcdNumber_10->display( ui->lcdNumber_10->value()+1);
            settings.setValue("lcdNumber_10",ui->lcdNumber_10->value());
            ui->lcdNumber_12->display( ui->lcdNumber_10->value()/(ui->lcdNumber_10->value()+ui->lcdNumber_11->value())*100);
            settings.setValue("lcdNumber_12",ui->lcdNumber_12->value());
        }else{
            ui->lcdNumber_11->display( ui->lcdNumber_11->value()+1);
            settings.setValue("lcdNumber_11",ui->lcdNumber_11->value());
            ui->lcdNumber_12->display( ui->lcdNumber_10->value()/(ui->lcdNumber_10->value()+ui->lcdNumber_11->value())*100);
            settings.setValue("lcdNumber_12",ui->lcdNumber_12->value());
        }

        break;
    }
    case 5:{
        if(check){
            ui->lcdNumber_13->display( ui->lcdNumber_13->value()+1);
            settings.setValue("lcdNumber_13",ui->lcdNumber_13->value());
            ui->lcdNumber_15->display( ui->lcdNumber_13->value()/(ui->lcdNumber_13->value()+ui->lcdNumber_14->value())*100);
            settings.setValue("lcdNumber_15",ui->lcdNumber_15->value());
        }else{
            ui->lcdNumber_14->display( ui->lcdNumber_14->value()+1);
            settings.setValue("lcdNumber_14",ui->lcdNumber_14->value());
            ui->lcdNumber_15->display( ui->lcdNumber_13->value()/(ui->lcdNumber_13->value()+ui->lcdNumber_14->value())*100);
            settings.setValue("lcdNumber_15",ui->lcdNumber_15->value());
        }

        break;
    }
    case 6:{
        if(check){
            ui->lcdNumber_16->display( ui->lcdNumber_16->value()+1);
            settings.setValue("lcdNumber_16",ui->lcdNumber_16->value());
            ui->lcdNumber_18->display( ui->lcdNumber_16->value()/(ui->lcdNumber_16->value()+ui->lcdNumber_17->value())*100);
            settings.setValue("lcdNumber_18",ui->lcdNumber_18->value());
        }else{
            ui->lcdNumber_17->display( ui->lcdNumber_17->value()+1);
            settings.setValue("lcdNumber_17",ui->lcdNumber_17->value());
            ui->lcdNumber_18->display( ui->lcdNumber_16->value()/(ui->lcdNumber_16->value()+ui->lcdNumber_17->value())*100);
            settings.setValue("lcdNumber_18",ui->lcdNumber_18->value());
        }

        break;
    }
    case 7:{
        if(check){
            ui->lcdNumber_19->display( ui->lcdNumber_19->value()+1);
            settings.setValue("lcdNumber_19",ui->lcdNumber_19->value());
            ui->lcdNumber_21->display( ui->lcdNumber_19->value()/(ui->lcdNumber_19->value()+ui->lcdNumber_20->value())*100);
            settings.setValue("lcdNumber_21",ui->lcdNumber_21->value());
        }else{
            ui->lcdNumber_20->display( ui->lcdNumber_20->value()+1);
            settings.setValue("lcdNumber_20",ui->lcdNumber_20->value());
            ui->lcdNumber_21->display( ui->lcdNumber_19->value()/(ui->lcdNumber_19->value()+ui->lcdNumber_20->value())*100);
            settings.setValue("lcdNumber_21",ui->lcdNumber_21->value());
        }

        break;
    }
    case 8:{
        if(check){
            ui->lcdNumber_22->display( ui->lcdNumber_22->value()+1);
            settings.setValue("lcdNumber_22",ui->lcdNumber_22->value());
            ui->lcdNumber_24->display( ui->lcdNumber_22->value()/(ui->lcdNumber_22->value()+ui->lcdNumber_23->value())*100);
            settings.setValue("lcdNumber_24",ui->lcdNumber_24->value());
        }else{
            ui->lcdNumber_23->display( ui->lcdNumber_23->value()+1);
            settings.setValue("lcdNumber_23",ui->lcdNumber_23->value());
            ui->lcdNumber_24->display( ui->lcdNumber_22->value()/(ui->lcdNumber_22->value()+ui->lcdNumber_23->value())*100);
            settings.setValue("lcdNumber_24",ui->lcdNumber_24->value());
        }

        break;
    }

    }
}




void DetectionResultForm::on_read_clicked()
{
    QString dlgTitle = "Question";
    QString strLabel = "Are you sure to read it";
    QMessageBox::StandardButtons result;
    result = QMessageBox::question(this, dlgTitle, strLabel, QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,
                                   QMessageBox::NoButton);
    QString str;
    if (QMessageBox::Yes == result) {
        str = "Yes";
        getini();

    }
    else if (QMessageBox::No== result) {
        str = "No";

    }
    else if (QMessageBox::Cancel == result) {
        str = "Cancel";


    }
   // cout <<str.toStdString()<<endl;
}

void DetectionResultForm::on_dateclear_clicked()
{
    QString dlgTitle = "Question";
    QString strLabel = "Are you sure to clear it";
    QMessageBox::StandardButtons result;
    result = QMessageBox::question(this, dlgTitle, strLabel, QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,
                                   QMessageBox::NoButton);
    QString str;
    if (QMessageBox::Yes == result) {
        str = "Yes";
        setini2zero();
        getini();

    }
    else if (QMessageBox::No== result) {
        str = "No";
        getini();
    }
    else if (QMessageBox::Cancel == result) {
        str = "Cancel";
        getini();

    }
   // cout <<str.toStdString()<<endl;
}
