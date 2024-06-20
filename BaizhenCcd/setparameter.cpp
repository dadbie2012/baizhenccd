#include "setparameter.h"
#include "ui_setparameter.h"
#include <QRegularExpressionValidator>
#include<QRegExp>

SetParameter::SetParameter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetParameter)
{
    ui->setupUi(this);
      this->setWindowIcon(QIcon(":/image/image/caomei.png"));
    this->setAttribute(Qt::WA_QuitOnClose, false);
    setWindowTitle("Parameter Setting");
    ui->lineEdit_1_1->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_1_2->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_1_3->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_1_4->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_1_5->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_1_6->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));

    ui->lineEdit_2_1->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_2_2->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_2_3->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_2_4->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_2_5->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_2_6->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));

    ui->lineEdit_3_1->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_3_2->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_3_3->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_3_4->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_3_5->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_3_6->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));

    ui->lineEdit_4_1->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_4_2->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_4_3->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_4_4->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_4_5->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_4_6->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));

    ui->lineEdit_5_1->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_5_2->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_5_3->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_5_4->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_5_5->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_5_6->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));

    ui->lineEdit_6_1->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_6_2->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_6_3->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_6_4->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_6_5->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_6_6->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));

    ui->lineEdit_7_1->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_7_2->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_7_3->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_7_4->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_7_5->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_7_6->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));

    ui->lineEdit_8_1->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_8_2->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_8_3->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_8_4->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_8_5->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));
    ui->lineEdit_8_6->setValidator(new QRegExpValidator(QRegExp("[0-9\\.-]+$")));







}

SetParameter::~SetParameter()
{
    delete ui;
}

void SetParameter::getini()
{

    QSettings settings("./Detection parameters.ini",QSettings::IniFormat);
    //读取组件状态信息
    //设置QLineEdit内容
    QString text;
    text = settings.value("lineEdit_1_1","").toString();
    ui->lineEdit_1_1->setText(text);
    VisionMeasure::cam_threshold[0][0]=text.toDouble();
    text = settings.value("lineEdit_1_2","").toString();
    ui->lineEdit_1_2->setText(text);
    VisionMeasure::cam_threshold[0][1]=text.toDouble();
    text = settings.value("lineEdit_1_3","").toString();
    ui->lineEdit_1_3->setText(text);
    VisionMeasure::cam_threshold[0][2]=text.toDouble();
    text = settings.value("lineEdit_1_4","").toString();
    ui->lineEdit_1_4->setText(text);
    VisionMeasure::cam_threshold[0][3]=text.toDouble();
    text = settings.value("lineEdit_1_5","").toString();
    ui->lineEdit_1_5->setText(text);
    VisionMeasure::cam_threshold[0][4]=text.toDouble();
    text = settings.value("lineEdit_1_6","").toString();
    ui->lineEdit_1_6->setText(text);
    VisionMeasure::cam_threshold[0][5]=text.toDouble();

    text = settings.value("lineEdit_2_1","").toString();
    ui->lineEdit_2_1->setText(text);
    VisionMeasure::cam_threshold[1][0]=text.toDouble();
    text = settings.value("lineEdit_2_2","").toString();
    ui->lineEdit_2_2->setText(text);
    VisionMeasure::cam_threshold[1][1]=text.toDouble();
    text = settings.value("lineEdit_2_3","").toString();
    ui->lineEdit_2_3->setText(text);
    VisionMeasure::cam_threshold[1][2]=text.toDouble();
    text = settings.value("lineEdit_2_4","").toString();
    ui->lineEdit_2_4->setText(text);
    VisionMeasure::cam_threshold[1][3]=text.toDouble();
    text = settings.value("lineEdit_2_5","").toString();
    ui->lineEdit_2_5->setText(text);
    VisionMeasure::cam_threshold[1][4]=text.toDouble();
    text = settings.value("lineEdit_2_6","").toString();
    ui->lineEdit_2_6->setText(text);
    VisionMeasure::cam_threshold[1][5]=text.toDouble();

    text = settings.value("lineEdit_3_1","").toString();
    ui->lineEdit_3_1->setText(text);
    VisionMeasure::cam_threshold[2][0]=text.toDouble();
    text = settings.value("lineEdit_3_2","").toString();
    ui->lineEdit_3_2->setText(text);
    VisionMeasure::cam_threshold[2][1]=text.toDouble();
    text = settings.value("lineEdit_3_3","").toString();
    ui->lineEdit_3_3->setText(text);
    VisionMeasure::cam_threshold[2][2]=text.toDouble();
    text = settings.value("lineEdit_3_4","").toString();
    ui->lineEdit_3_4->setText(text);
    VisionMeasure::cam_threshold[2][3]=text.toDouble();
    text = settings.value("lineEdit_3_5","").toString();
    ui->lineEdit_3_5->setText(text);
    VisionMeasure::cam_threshold[2][4]=text.toDouble();
    text = settings.value("lineEdit_3_6","").toString();
    ui->lineEdit_3_6->setText(text);
    VisionMeasure::cam_threshold[2][5]=text.toDouble();

    text = settings.value("lineEdit_4_1","").toString();
    ui->lineEdit_4_1->setText(text);
    VisionMeasure::cam_threshold[3][0]=text.toDouble();
    text = settings.value("lineEdit_4_2","").toString();
    ui->lineEdit_4_2->setText(text);
    VisionMeasure::cam_threshold[3][1]=text.toDouble();
    text = settings.value("lineEdit_4_3","").toString();
    ui->lineEdit_4_3->setText(text);
    VisionMeasure::cam_threshold[3][2]=text.toDouble();
    text = settings.value("lineEdit_4_4","").toString();
    ui->lineEdit_4_4->setText(text);
    VisionMeasure::cam_threshold[3][3]=text.toDouble();
    text = settings.value("lineEdit_4_5","").toString();
    ui->lineEdit_4_5->setText(text);
    VisionMeasure::cam_threshold[3][4]=text.toDouble();
    text = settings.value("lineEdit_4_6","").toString();
    ui->lineEdit_4_6->setText(text);
    VisionMeasure::cam_threshold[3][5]=text.toDouble();

    text = settings.value("lineEdit_5_1","").toString();
    ui->lineEdit_5_1->setText(text);
    VisionMeasure::cam_threshold[4][0]=text.toDouble();
    text = settings.value("lineEdit_5_2","").toString();
    ui->lineEdit_5_2->setText(text);
    VisionMeasure::cam_threshold[4][1]=text.toDouble();
    text = settings.value("lineEdit_5_3","").toString();
    ui->lineEdit_5_3->setText(text);
    VisionMeasure::cam_threshold[4][2]=text.toDouble();
    text = settings.value("lineEdit_5_4","").toString();
    ui->lineEdit_5_4->setText(text);
    VisionMeasure::cam_threshold[4][3]=text.toDouble();
    text = settings.value("lineEdit_5_5","").toString();
    ui->lineEdit_5_5->setText(text);
    VisionMeasure::cam_threshold[4][4]=text.toDouble();
    text = settings.value("lineEdit_5_6","").toString();
    ui->lineEdit_5_6->setText(text);
    VisionMeasure::cam_threshold[4][5]=text.toDouble();

    text = settings.value("lineEdit_6_1","").toString();
    ui->lineEdit_6_1->setText(text);
    VisionMeasure::cam_threshold[5][0]=text.toDouble();
    text = settings.value("lineEdit_6_2","").toString();
    ui->lineEdit_6_2->setText(text);
    VisionMeasure::cam_threshold[5][1]=text.toDouble();
    text = settings.value("lineEdit_6_3","").toString();
    ui->lineEdit_6_3->setText(text);
    VisionMeasure::cam_threshold[5][2]=text.toDouble();
    text = settings.value("lineEdit_6_4","").toString();
    ui->lineEdit_6_4->setText(text);
    VisionMeasure::cam_threshold[5][3]=text.toDouble();
    text = settings.value("lineEdit_6_5","").toString();
    ui->lineEdit_6_5->setText(text);
    VisionMeasure::cam_threshold[5][4]=text.toDouble();
    text = settings.value("lineEdit_6_6","").toString();
    ui->lineEdit_6_6->setText(text);
    VisionMeasure::cam_threshold[5][5]=text.toDouble();

    text = settings.value("lineEdit_7_1","").toString();
    ui->lineEdit_7_1->setText(text);
    VisionMeasure::cam_threshold[6][0]=text.toDouble();
    text = settings.value("lineEdit_7_2","").toString();
    ui->lineEdit_7_2->setText(text);
    VisionMeasure::cam_threshold[6][1]=text.toDouble();
    text = settings.value("lineEdit_7_3","").toString();
    ui->lineEdit_7_3->setText(text);
    VisionMeasure::cam_threshold[6][2]=text.toDouble();
    text = settings.value("lineEdit_7_4","").toString();
    ui->lineEdit_7_4->setText(text);
    VisionMeasure::cam_threshold[6][3]=text.toDouble();
    text = settings.value("lineEdit_7_5","").toString();
    ui->lineEdit_7_5->setText(text);
    VisionMeasure::cam_threshold[6][4]=text.toDouble();
    text = settings.value("lineEdit_7_6","").toString();
    ui->lineEdit_7_6->setText(text);
    VisionMeasure::cam_threshold[6][5]=text.toDouble();

    text = settings.value("lineEdit_8_1","").toString();
    ui->lineEdit_8_1->setText(text);
    VisionMeasure::cam_threshold[7][0]=text.toDouble();
    text = settings.value("lineEdit_8_2","").toString();
    ui->lineEdit_8_2->setText(text);
    VisionMeasure::cam_threshold[7][1]=text.toDouble();
    text = settings.value("lineEdit_8_3","").toString();
    ui->lineEdit_8_3->setText(text);
    VisionMeasure::cam_threshold[7][2]=text.toDouble();
    text = settings.value("lineEdit_8_4","").toString();
    ui->lineEdit_8_4->setText(text);
    VisionMeasure::cam_threshold[7][3]=text.toDouble();
    text = settings.value("lineEdit_8_5","").toString();
    ui->lineEdit_8_5->setText(text);
    VisionMeasure::cam_threshold[7][4]=text.toDouble();
    text = settings.value("lineEdit_8_6","").toString();
    ui->lineEdit_8_6->setText(text);
    VisionMeasure::cam_threshold[7][5]=text.toDouble();



}

void SetParameter::setini()
{
    QSettings settings("./Detection parameters.ini",QSettings::IniFormat);
    //将QLineEdit组件信息写入.ini
    QString text;
    text = ui->lineEdit_1_1->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_1_1",text);
    VisionMeasure::cam_threshold[0][0]=text.toDouble();
    text = ui->lineEdit_1_2->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_1_2",text);
    VisionMeasure::cam_threshold[0][1]=text.toDouble();
    text = ui->lineEdit_1_3->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_1_3",text);
    VisionMeasure::cam_threshold[0][2]=text.toDouble();
    text = ui->lineEdit_1_4->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_1_4",text);
    VisionMeasure::cam_threshold[0][3]=text.toDouble();
    text = ui->lineEdit_1_5->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_1_5",text);
    VisionMeasure::cam_threshold[0][4]=text.toDouble();
    text = ui->lineEdit_1_6->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_1_6",text);
    VisionMeasure::cam_threshold[0][5]=text.toDouble();

    text = ui->lineEdit_2_1->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_2_1",text);
    VisionMeasure::cam_threshold[1][0]=text.toDouble();
    text = ui->lineEdit_2_2->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_2_2",text);
    VisionMeasure::cam_threshold[1][1]=text.toDouble();
    text = ui->lineEdit_2_3->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_2_3",text);
    VisionMeasure::cam_threshold[1][2]=text.toDouble();
    text = ui->lineEdit_2_4->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_2_4",text);
    VisionMeasure::cam_threshold[1][3]=text.toDouble();
    text = ui->lineEdit_2_5->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_2_5",text);
    VisionMeasure::cam_threshold[1][4]=text.toDouble();
    text = ui->lineEdit_2_6->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_2_6",text);
    VisionMeasure::cam_threshold[1][5]=text.toDouble();

    text = ui->lineEdit_3_1->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_3_1",text);
    VisionMeasure::cam_threshold[2][0]=text.toDouble();
    text = ui->lineEdit_3_2->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_3_2",text);
    VisionMeasure::cam_threshold[2][1]=text.toDouble();
    text = ui->lineEdit_3_3->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_3_3",text);
    VisionMeasure::cam_threshold[2][2]=text.toDouble();
    text = ui->lineEdit_3_4->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_3_4",text);
    VisionMeasure::cam_threshold[2][3]=text.toDouble();
    text = ui->lineEdit_3_5->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_3_5",text);
    VisionMeasure::cam_threshold[2][4]=text.toDouble();
    text = ui->lineEdit_3_6->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_3_6",text);
    VisionMeasure::cam_threshold[2][5]=text.toDouble();

    text = ui->lineEdit_4_1->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_4_1",text);
    VisionMeasure::cam_threshold[3][0]=text.toDouble();
    text = ui->lineEdit_4_2->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_4_2",text);
    VisionMeasure::cam_threshold[3][1]=text.toDouble();
    text = ui->lineEdit_4_3->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_4_3",text);
    VisionMeasure::cam_threshold[3][2]=text.toDouble();
    text = ui->lineEdit_4_4->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_4_4",text);
    VisionMeasure::cam_threshold[3][3]=text.toDouble();
    text = ui->lineEdit_4_5->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_4_5",text);
    VisionMeasure::cam_threshold[3][4]=text.toDouble();
    text = ui->lineEdit_4_6->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_4_6",text);
    VisionMeasure::cam_threshold[3][5]=text.toDouble();

    text = ui->lineEdit_5_1->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_5_1",text);
    VisionMeasure::cam_threshold[4][0]=text.toDouble();
    text = ui->lineEdit_5_2->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_5_2",text);
    VisionMeasure::cam_threshold[4][1]=text.toDouble();
    text = ui->lineEdit_5_3->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_5_3",text);
    VisionMeasure::cam_threshold[4][2]=text.toDouble();
    text = ui->lineEdit_5_4->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_5_4",text);
    VisionMeasure::cam_threshold[4][3]=text.toDouble();
    text = ui->lineEdit_5_5->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_5_5",text);
    VisionMeasure::cam_threshold[4][4]=text.toDouble();
    text = ui->lineEdit_5_6->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_5_6",text);
    VisionMeasure::cam_threshold[4][5]=text.toDouble();
    text = ui->lineEdit_6_1->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_6_1",text);
    VisionMeasure::cam_threshold[5][0]=text.toDouble();
    text = ui->lineEdit_6_2->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_6_2",text);
    VisionMeasure::cam_threshold[5][1]=text.toDouble();
    text = ui->lineEdit_6_3->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_6_3",text);
    VisionMeasure::cam_threshold[5][2]=text.toDouble();
    text = ui->lineEdit_6_4->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_6_4",text);
    VisionMeasure::cam_threshold[5][3]=text.toDouble();
    text = ui->lineEdit_6_5->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_6_5",text);
    VisionMeasure::cam_threshold[5][4]=text.toDouble();
    text = ui->lineEdit_6_6->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_6_6",text);
    VisionMeasure::cam_threshold[5][5]=text.toDouble();


    text = ui->lineEdit_7_1->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_7_1",text);
    VisionMeasure::cam_threshold[6][0]=text.toDouble();
    text = ui->lineEdit_7_2->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_7_2",text);
    VisionMeasure::cam_threshold[6][1]=text.toDouble();
    text = ui->lineEdit_7_3->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_7_3",text);
    VisionMeasure::cam_threshold[6][2]=text.toDouble();
    text = ui->lineEdit_7_4->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_7_4",text);
    VisionMeasure::cam_threshold[6][3]=text.toDouble();
    text = ui->lineEdit_7_5->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_7_5",text);
    VisionMeasure::cam_threshold[6][4]=text.toDouble();
    text = ui->lineEdit_7_6->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_7_6",text);
    VisionMeasure::cam_threshold[6][5]=text.toDouble();


    text = ui->lineEdit_8_1->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_8_1",text);
    VisionMeasure::cam_threshold[7][0]=text.toDouble();
    text = ui->lineEdit_8_2->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_8_2",text);
    VisionMeasure::cam_threshold[7][1]=text.toDouble();
    text = ui->lineEdit_8_3->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_8_3",text);
    VisionMeasure::cam_threshold[7][2]=text.toDouble();
    text = ui->lineEdit_8_4->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_8_4",text);
    VisionMeasure::cam_threshold[7][3]=text.toDouble();
    text = ui->lineEdit_8_5->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_8_5",text);
    VisionMeasure::cam_threshold[7][4]=text.toDouble();
    text = ui->lineEdit_8_6->text();    //获取QLineEdit的文本内容
    settings.setValue("lineEdit_8_6",text);
    VisionMeasure::cam_threshold[7][5]=text.toDouble();



}





void SetParameter::on_set_1_clicked()
{
    QString dlgTitle = "Question_1";
    QString strLabel = "Are you sure to modify it";
    QMessageBox::StandardButtons result;
    result = QMessageBox::question(this, dlgTitle, strLabel, QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,
                                   QMessageBox::NoButton);
    QString str;
    if (QMessageBox::Yes == result) {
        str = "Yes";
        setini();
    }
    else if (QMessageBox::No== result) {
        str = "No";
        getini();

    }
    else if (QMessageBox::Cancel == result) {
        str = "Cancel";
        getini();
    }
   // cout <<"2-"<<str.toStdString()<<endl;
}
