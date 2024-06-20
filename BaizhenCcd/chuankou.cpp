#include "chuankou.h"
#include "ui_chuankou.h"

ChuanKou::ChuanKou(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChuanKou)
{
    ui->setupUi(this);
      port=new QSerialPort;
      setWindowTitle("串口设置");
      this->setAttribute(Qt::WA_QuitOnClose, false);
      this->setWindowIcon(QIcon(":/image/image/caomei.png"));
      //this->setIconSize(QSize(400,300));
}

ChuanKou::~ChuanKou()
{
    delete ui;
}

void ChuanKou::openlight_all()
{
    for(int i=1;i<13;i++){

        openlight(i);
    }
}
void ChuanKou::closelight_all()
{
    for(int i=1;i<13;i++){

        closelight(i);
    }
}

void ChuanKou::on_pushButton_clicked()
{



    if(port->isOpen()){
       ui->Log->append("已经打开串口!");
      return;
    }
    QList<QSerialPortInfo> comlist=QSerialPortInfo::availablePorts();
    QSerialPortInfo portinfo=comlist.at(ui->comboBox->currentIndex());
     ui->Log->append("正在打开串口名称:"+portinfo.portName());
    port->setPort(portinfo);
    port->setBaudRate(9600);
    port->setDataBits(QSerialPort::DataBits(8));
    port->setStopBits(QSerialPort::StopBits(1));
    port->setParity(QSerialPort::Parity(0));
    if(port->open(QIODevice::ReadWrite)){
         ui->Log->append("打开串口成功!");
    }else{
        ui->Log->append("打开串口失败!");
    }

}

void ChuanKou::on_pushButton_5_clicked()
{
    ui->Log->append("串口信息:");
    foreach(QSerialPortInfo portinfo,QSerialPortInfo::availablePorts()){

         ui->Log->append(portinfo.portName()+"--"+portinfo.description());
        // ui->textEdit->append(portinfo.description());
    }
}

void ChuanKou::on_pushButton_2_clicked()
{
    if(port->isOpen()){
        port->close();
        ui->Log->append("已经关闭串口!");
    }
}

void ChuanKou::getinformation()
{
    QByteArray all=port->readAll();
    QString str(all);
    ui->Log->append(str);
}

void ChuanKou::on_openlight_clicked()
{
   openlight(ui->comboBox_2->currentIndex()+1);
  // std::cout<<ui->comboBox_2->currentIndex()<<std::endl;
}

void ChuanKou::on_pushButton_4_clicked()
{
  closelight(ui->comboBox_2->currentIndex()+1);
}

void ChuanKou::closelight(int num)
{
    switch (num) {
    case 1:{
        QByteArray result;
        result.append("$210381C");
        port->write(result);
        lightsituation_1=false;
        emit sendlightchange("close",1);
        break;
    }
    case 2:{
        QByteArray result;
        result.append("$220381F");
        port->write(result);
        lightsituation_2=false;
         emit sendlightchange("close",2);
        break;
    }
    case 3:{
        QByteArray result;
        result.append("$230381E");
        port->write(result);
        lightsituation_3=false;
         emit sendlightchange("close",3);
        break;
    }
    case 4:{
        QByteArray result;
        result.append("$2403819");
        port->write(result);
        lightsituation_4=false;
         emit sendlightchange("close",4);
        break;
    }
    case 5:{
        QByteArray result;
        result.append("$2503818");
        port->write(result);
        lightsituation_5=false;
         emit sendlightchange("close",5);
        break;
    }
    case 6:{
        QByteArray result;
        result.append("$260381B");
        port->write(result);
        lightsituation_6=false;
         emit sendlightchange("close",6);
        break;
    }
    case 7:{
        QByteArray result;
        result.append("$270381A");
        port->write(result);
        lightsituation_7=false;
         emit sendlightchange("close",7);
        break;
    }
    case 8:{
        QByteArray result;
        result.append("$2803815");
        port->write(result);
        lightsituation_8=false;
         emit sendlightchange("close",8);
        break;
    }
    case 9:{
        QByteArray result;
        result.append("$2903814");
        port->write(result);
        lightsituation_9=false;
         emit sendlightchange("close",9);
        break;
    }
    case 10:{
        QByteArray result;
        result.append("$2A0386C");
        port->write(result);
        lightsituation_10=false;
         emit sendlightchange("close",10);
        break;
    }
    case 11:{
        QByteArray result;
        result.append("$2b0384F");
        port->write(result);
        lightsituation_11=false;
         emit sendlightchange("close",11);
        break;
    }
    case 12:{
        QByteArray result;
        result.append("$2C0386E");
        port->write(result);
        lightsituation_12=false;
         emit sendlightchange("close",12);
        break;
    }
    case 13:{
        QByteArray result;
        result.append("$2d03849");
        port->write(result);
        lightsituation_13=false;
         emit sendlightchange("close",13);
        break;
    }
    case 14:{
        QByteArray result;
        result.append("$2E03868");
        port->write(result);
        lightsituation_14=false;
         emit sendlightchange("close",14);
        break;
    }
    case 15:{
        QByteArray result;
        result.append("$2F0386B");
        port->write(result);
        lightsituation_15=false;
         emit sendlightchange("close",15);
        break;
    }
    case 16:{
        QByteArray result;
        result.append("$2G0386A");
        port->write(result);
        lightsituation_16=false;
         emit sendlightchange("close",16);
        break;
    }
    default:
        std::cout<<"fault!!!"<<std::endl;
    }
}

void ChuanKou::openlight(int num)
{
    switch (num) {
    case 1:{
        QByteArray result;
        result.append("$110381F");
        port->write(result);
        lightsituation_1=true;
        emit sendlightchange("open",1);
        break;
    }
    case 2:{
        QByteArray result;
        result.append("$120381C");
        port->write(result);
         lightsituation_2=true;
          emit sendlightchange("open",2);
        break;
    }
    case 3:{
        QByteArray result;
        result.append("$130381D");
        port->write(result);
         lightsituation_3=true;
          emit sendlightchange("open",3);
        break;
    }
    case 4:{
        QByteArray result;
        result.append("$140381A");
        port->write(result);
         lightsituation_4=true;
          emit sendlightchange("open",4);
        break;
    }
    case 5:{
        QByteArray result;
        result.append("$150381B");
        port->write(result);
         lightsituation_5=true;
          emit sendlightchange("open",5);
        break;
    }
    case 6:{
        QByteArray result;
        result.append("$1603818");
        port->write(result);
         lightsituation_6=true;
          emit sendlightchange("open",6);
        break;
    }
    case 7:{
        QByteArray result;
        result.append("$1703819");
        port->write(result);
         lightsituation_7=true;
          emit sendlightchange("open",7);
        break;
    }
    case 8:{
        QByteArray result;
        result.append("$1803816");
        port->write(result);
         lightsituation_8=true;
          emit sendlightchange("open",8);
        break;
    }
    case 9:{
        QByteArray result;
        result.append("$1903817");
        port->write(result);
         lightsituation_9=true;
          emit sendlightchange("open",9);
        break;
    }
    case 10:{
        QByteArray result;
        result.append("$1A0386F");
        port->write(result);
         lightsituation_10=true;
          emit sendlightchange("open",10);
        break;
    }
    case 11:{
        QByteArray result;
        result.append("$1b0384C");
        port->write(result);
         lightsituation_11=true;
          emit sendlightchange("open",11);
        break;
    }
    case 12:{
        QByteArray result;
        result.append("$1C0386D");
        port->write(result);
         lightsituation_12=true;
          emit sendlightchange("open",12);
        break;
    }
    case 13:{
        QByteArray result;
        result.append("$1d0384A");
        port->write(result);
         lightsituation_13=true;
          emit sendlightchange("open",13);
        break;
    }
    case 14:{
        QByteArray result;
        result.append("$1E0386B");
        port->write(result);
         lightsituation_14=true;
          emit sendlightchange("open",14);
        break;
    }
    case 15:{
        QByteArray result;
        result.append("$1F03868");
        port->write(result);
         lightsituation_15=true;
          emit sendlightchange("open",15);
        break;
    }
    case 16:{
        QByteArray result;
        result.append("$1G03869");
        port->write(result);
         lightsituation_16=true;
          emit sendlightchange("open",16);
        break;
    }
    default:
        std::cout<<"fault!!!"<<std::endl;
    }
}
