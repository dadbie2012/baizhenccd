
#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose, false);
    this->setWindowIcon(QIcon(":/image/image/caomei.png"));
    mSocket = new QTcpSocket(this);
    setWindowTitle("Client");
    ui->spinBox->setRange(0,10000);
    QSettings settings("./Control Parameter.ini",QSettings::IniFormat);
    //读取组件状态信息
    //设置QLineEdit内容
    ip_ = settings.value("ip","").toString();
    port =quint16(settings.value("port","").toString().toUInt());
    ui->lineEdit_ip->setText(ip_);
    ui->spinBox->setValue(port);
    connect(&m_timer, &QTimer::timeout, this, &Client::slotTimeout);
    connect(mSocket, SIGNAL(disconnected()), this, SLOT(reconnect()));
    QObject::connect(mSocket,&QTcpSocket::connected,this,[&](){
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">Client connect successed</font>");
        //使能发送按钮和发送输入框
        m_timer.stop();
        if_first=true;
        ui->lineEdit_send->setEnabled(true);
        ui->pushButton_2->setEnabled(true);

        vector<int>res=camerastat();
        dateprocess("CAM#STAT",res);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM#STAT");
        mSocket->write(resultarr);

        //禁止ip 端口号和连接按钮
        ui->lineEdit_ip->setEnabled(false);
        ui->spinBox->setEnabled(false);
        ui->pushButton->setEnabled(false);



        //连接readyRead信号和槽
        QObject::connect(mSocket,&QTcpSocket::readyRead,this,[&](){
            //接收数据
            QByteArray arr_1 = mSocket->readAll();
            QString str;
            uchar char1[2048]={0};
            for(int i=0;i<arr_1.size();i++){
                char1[i]=arr_1.at(i);
            }
            int count=0;
            count=arr_1.size()/3;
          //  str=QString(char1[0])+QString(char1[1])+QString(char1[2])+QString(char1[3])+QString(char1[4])+QString(char1[5])+QString(char1[6])+QString(char1[7])+QString(char1[8])+QString(char1[9])+QString(char1[10])+QString(char1[11]);
            //cout<<"start time:"<< QDateTime::currentDateTime().toString("hh-mm-ss-zzz").toStdString()<<endl;
            if(moshi){
                for(int i=0;i<count;i++){
                      str=QString(char1[13*i+0])+QString(char1[13*i+1])+QString(char1[13*i+2])+QString(char1[13*i+3])+QString(char1[13*i+4])+QString(char1[13*i+5])+QString(char1[13*i+6])+QString(char1[13*i+7])+QString(char1[13*i+8])+QString(char1[13*i+9])+QString(char1[13*i+10])+QString(char1[13*i+11]);
                      QString str2=str.mid(3,8);
                    instructionprocessing(str);
                }


            }else{
                instructionprocessing_tiaoshi(str);
            }

            //显示
            ui->textBrowser->insertPlainText("rcv:"+str+"\n");
        });
    });

    connect(mSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, [&](){
        if(if_first){
            reconnect();
            if_first=false;
            emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Client connect failed</font>");

        }
        //emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">Client connect failed</font>");
    });
    //连接回车发送的信号和槽
    QObject::connect(ui->lineEdit_send,&QLineEdit::returnPressed,this,&Client::on_pushButton_2_clicked);
}

Client::~Client()
{
    delete ui;
}

void Client::instructionprocessing(QString str)
{

    QString result=str.mid(3,8);
  //  cout<<"ssss"<<str.toStdString()<<endl;
    if(result=="CAM#STAT"){
       // cout<<"CAM#STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat();
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);

    }else if(result=="CAM1STAT"){
       // cout<<"CAM1STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM2STAT"){
      //  cout<<"CAM2STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM3STAT"){
       // cout<<"CAM3STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM4STAT"){
       // cout<<"CAM4STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM5STAT"){
       // cout<<"CAM5STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM5STAT"){
      //  cout<<"CAM5STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM6STAT"){
       cout<<"CAM6STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM7STAT"){
      //  cout<<"CAM5STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM8STAT"){
      //  cout<<"CAM5STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM1ACT1"){
      //  cout<<"CAM1ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        if_action_1=true;
        emit instruction(result);
    }else if(result=="CAM2ACT1"){
        if_action_2=true;
      //  cout<<"CAM2ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM3ACT1"){
        if_action_3=true;
     //   cout<<"CAM3ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM4ACT1"){
        if_action_4=true;
      //  cout<<"CAM4ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM5ACT1"){
        if_action_5=true;
      //  cout<<"CAM5ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM6ACT1"){
        if_action_6=true;
      //  cout<<"CAM6ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM7ACT1"){
        //if_action_7=true;
      //  cout<<"CAM7ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM8ACT1"){
       // if_action_8=true;
      //  cout<<"CAM8ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM1ACT2"){
        if_action_1=true;
        if_finish_1=false;
       // cout<<"CAM1ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM2ACT2"){
        if_action_2=true;
        if_finish_2=false;
      //  cout<<"CAM2ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM3ACT2"){
        if_action_3=true;
        if_finish_3=false;
      //  cout<<"CAM3ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM3ACT3"){
        if_action_3=true;
        if_finish_3=false;
      //  cout<<"CAM3ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM4ACT2"){
        if_action_4=true;
        if_finish_4=false;
      //  cout<<"CAM4ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM4ACT3"){
        if_action_4=true;
        if_finish_4=false;
      //  cout<<"CAM3ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM5ACT2"){
        if_action_5=true;
        if_finish_5=false;
       // cout<<"CAM5ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM5ACT3"){
        if_action_5=true;
        if_finish_5=false;
       // cout<<"CAM5ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM6ACT2"){
        if_action_6=true;
        if_finish_6=false;
      //  cout<<"CAM6ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM7ACT2"){
       // if_action_7=true;
       // if_finish_7=false;
      //  cout<<"CAM7ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM7DATA"){

      //  cout<<"CAM7DATA" <<endl;
         emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
        getdate(str);
    }else if(result=="CAM8ACT2"){
       // if_action_8=true;
       // if_finish_8=false;
      //  cout<<"CAM8ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        emit instruction(result);
    }else if(result=="CAM#PATH"){
      //  cout<<"CAM#PATH" <<endl;
    }else if(result=="CAM#SHOW"){
     //   cout<<"CAM#SHOW" <<endl;
    }else if(result=="CAM#HIDE"){
       // cout<<"CAM#HIDE" <<endl;
    }else if(result=="CAM#EXIT"){
      //  cout<<"CAM#EXIT" <<endl;
    }
}



vector<int> Client::camerastat()
{

    int position_1=if_exception_1==true?1:0;
    int position_2=if_exception_2==true?2:0;
    int position_3=if_exception_3==true?4:0;
    int position_4=if_exception_4==true?8:0;
    int position_5=if_exception_5==true?16:0;
    int position_6=if_exception_6==true?32:0;
   // int position_7=if_exception_7==true?64:0;
   // int position_8=if_exception_8==true?128:0;


    int position_9 =if_action_1==true?1:0;
    int position_10=if_action_2==true?2:0;
    int position_11=if_action_3==true?4:0;
    int position_12=if_action_4==true?8:0;
    int position_13=if_action_5==true?16:0;
    int position_14=if_action_6==true?32:0;
  //  int position_15=if_action_7==true?64:0;
   // int position_16=if_action_8==true?128:0;

    int all_2=position_1+position_2+position_3+position_4+position_5+position_6;
    int all_1=position_9+position_10+position_11+position_12+position_13+position_14;
  //  cout<<"aaa"<<all_2<<endl;
    //QString strRes_1 = QByteArray::fromHex(QByteArray::number(all_1,16));
    //QString strRes_2 = QByteArray::fromHex(QByteArray::number(all_2,16));


    vector<int> res;
    res.push_back(all_2);
    res.push_back(all_1);
    return res;
}

vector<int> Client::camerastat_2(QString name)
{
    int position_1;
    int position_2;
    int position_3;
    int position_4;
    int position_5;
    int position_6;

    name=name.mid(0,4);
    if(name=="CAM1"){
        position_1=if_exception_1==true?1:0;
        position_2=if_action_1==true?4:0;
        position_3=if_finish_1==true?2:0;
    }else if(name=="CAM2"){
        position_1=if_exception_2==true?1:0;
        position_2=if_action_2==true?4:0;
        position_3=if_finish_2==true?2:0;
    }else if(name=="CAM3"){
        position_1=if_exception_3==true?1:0;
        position_2=if_action_3==true?4:0;
        position_3=if_finish_3==true?2:0;
    }else if(name=="CAM4"){
        position_1=if_exception_4==true?1:0;
        position_2=if_action_4==true?4:0;
        position_3=if_finish_4==true?2:0;
    }else if(name=="CAM5"){
        position_1=if_exception_5==true?1:0;
        position_2=if_action_5==true?4:0;
        position_3=if_finish_5==true?2:0;
    }else if(name=="CAM6"){
        position_1=if_exception_6==true?1:0;
        position_2=if_action_6==true?4:0;
        position_3=if_finish_6==true?2:0;
    }else if(name=="CAM7"){
//        position_1=if_exception_7==true?1:0;
//        position_2=if_action_7==true?4:0;
//        position_3=if_finish_7==true?2:0;
    }else if(name=="CAM8"){
//        position_1=if_exception_8==true?1:0;
//        position_2=if_action_8==true?4:0;
//        position_3=if_finish_8==true?2:0;
    }
    int all_1=position_1+position_2+position_3;
    vector<int> res;
    res.push_back(all_1);
    return res;
}

void Client::dateprocess(QString name, vector<int> date)
{
    QByteArray result;
    result.append("@");
    result.append("S");
    result.append("C");
    result.append(name);
    // result.append(QByteArray::fromHex(QByteArray::number(date.size(),16)));
    result.append(QByteArray::fromHex(QByteArray::number((date.size())/256,16)));
    result.append(QByteArray::fromHex(QByteArray::number((date.size())%256,16)));
    for(int i=0;i<date.size();i++){
        result.append(QByteArray::fromHex(QByteArray::number(date[i],16)));


    }
    result.append(char(13));
    resultarr=result;
    /* qInfo()<<resultarr[resultarr.size()-1]<<resultarr<<QString(resultarr);
    qInfo()<<resultarr.toHex();*/
    // return result;

}



void Client::on_pushButton_clicked()
{


    mSocket->connectToHost(ui->lineEdit_ip->text(),ui->spinBox->value());


}

void Client::on_pushButton_2_clicked()
{

    //获取发送的数据
    QString str = ui->lineEdit_send->text();
    //转换成QByteArray
    QByteArray arr;
    arr.append(str);

    //发送
    mSocket->write(arr);
    //显示发送的内容
    ui->textBrowser->insertPlainText("send:"+str+"\n");
    //情况lineEdit
    ui->lineEdit_send->clear();
}

void Client::getresult(QString name, QByteArray result,bool check)
{

    if(name=="CAM1ACT2"){
      //  cout<<"ENDMAINCAM1ACT2" <<endl;

        if_action_1=false;
        QByteArray result2=dateprocess_2(name,result,check);
        mSocket->write(result2);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
        if_finish_1=true;
    }else if(name=="CAM2ACT2"){
        if_action_2=false;
      //  cout<<"ENDMAINCAM2ACT2" <<endl;
        QByteArray result2=dateprocess_2(name,result,check);

        mSocket->write(result2);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
        if_finish_2=true;

    }else if(name=="CAM3ACT2"){

        if_action_3=false;
     //   cout<<"ENDMAINCAM3ACT2" <<endl;
        QByteArray result2=dateprocess_2(name,result,check);
        mSocket->write(result2);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
        if_finish_3=true;

    }else if(name=="CAM4ACT2"){
        if_action_4=false;
      //  cout<<"ENDMAINCAM4ACT2" <<endl;
        QByteArray result2= dateprocess_2(name,result,check);
        mSocket->write(result2);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
        if_finish_4=true;

    }else if(name=="CAM5ACT2"){
        if_action_5=false;
      //  cout<<"ENDMAINCAM5ACT2" <<endl;
        QByteArray result2= dateprocess_2(name,result,check);
        mSocket->write(result2);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
        if_finish_5=true;

    }else if(name=="CAM6ACT2"){
       
        if_action_6=false;
      //  cout<<"ENDMAINCAM6ACT2" <<endl;
        QByteArray result2= dateprocess_2(name,result,check);
        mSocket->write(result2);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
        if_finish_6=true;

    }else if(name=="CAM7ACT2"){
       // if_action_7=false;
      //  cout<<"ENDMAINCAM7ACT2" <<endl;
        QByteArray result2= dateprocess_2(name,result,check);
        mSocket->write(result2);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
      //  if_finish_7=true;

    }else if(name=="CAM8ACT2"){
      //  if_action_8=false;
      //  cout<<"ENDMAINCAM8ACT2" <<endl;
        QByteArray result2= dateprocess_2(name,result,check);
        mSocket->write(result2);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
     //   if_finish_8=true;

    }else if(name=="CAM8ACT2"){
        //  if_action_8=false;
        //  cout<<"ENDMAINCAM8ACT2" <<endl;
          QByteArray result2= dateprocess_2(name,result,check);
          mSocket->write(result2);
          emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
       //   if_finish_8=true;

      }else if(name=="CAM3ACT3"){
        //  if_action_8=false;
        //  cout<<"ENDMAINCAM8ACT2" <<endl;
          QByteArray result2= dateprocess_2(name,result,check);
          mSocket->write(result2);
          emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
       //   if_finish_8=true;

      }else if(name=="CAM4ACT3"){
        //  if_action_8=false;
        //  cout<<"ENDMAINCAM8ACT2" <<endl;
          QByteArray result2= dateprocess_2(name,result,check);
          mSocket->write(result2);
          emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
       //   if_finish_8=true;

      }else if(name=="CAM5ACT3"){
        //  if_action_8=false;
        //  cout<<"ENDMAINCAM8ACT2" <<endl;
          QByteArray result2= dateprocess_2(name,result,check);
          mSocket->write(result2);
          emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+name);
       //   if_finish_8=true;

      }


}
QByteArray Client::dateprocess_2(QString name, QByteArray date,bool check)
{
    QByteArray result;
    result.append("@");
    result.append("S");
    result.append("C");

   // cout<<"DDD"<<result.size()<<endl;
    result.append(name);
    // cout<<"EEE"<<result.size()<<endl;
      result.append(QByteArray::fromHex(QByteArray::number(date.size(),16)));
/*    result.append(QByteArray::fromHex(QByteArray::number(date.size()/256,16)));
    result.append(QByteArray::fromHex(QByteArray::number(date.size()%256,16)))*/;
    // cout<<"TTT"<<result.size()<<endl;
    result.append(date);
    // cout<<"FFF"<<result.size()<<endl;
    result.append(char(13));
    //  cout<<"KKK:"<<result.size()<<endl;
    return result;
    //qInfo()<<resultarr_2[resultarr_2.size()-1]<<resultarr_2<<QString(resultarr_2);
    //qInfo()<<resultarr_2.toHex();



}

void Client::getdate(QString str)
{

    int countToRemove = 13; // 需要移除的字符数量

   // cout<<"11111"<<date.toStdString()<<endl;
    date = date.mid(countToRemove);
    //cout<<"2222"<<date.toStdString()<<endl;
    date = date.left(date.size()-1);
  //  cout<<"3333"<<date.toStdString()<<endl;
    QStringList list = date.split(",");
    emit senddate(list);

    //  cout<<"3333"<<date.toStdString()<<endl;
   // cout<<"size"<<list.size()<<endl;
    QString str2 = list.join(",");
  //  cout<<"sdsdsd"<<list[list.size()-1].toStdString()<<endl;

    QByteArray date;
    date.append("T");
    date.append(",");
    date.append(list[0]);
    date.append(",");
    date.append(list[1]);
    date.append(",");
    date.append(list[2]);
    date.append(",");
    date.append(list[list.size()-2]);
    date.append(",");
    date.append(list[list.size()-1]);
   // cout<<"sdsdsd"<<str2.toStdString()<<endl;
    QByteArray result2=dateprocess_2("CAM7DATA", date,true);
    mSocket->write(result2);
    emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM7DATA");






}

void Client::on_pushButton_3_clicked()
{
    mSocket->disconnectFromHost();
    mSocket->close();
    //cout<<"disconnect"<<endl;
    //禁止ip 端口号和连接按钮
    ui->lineEdit_ip->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->pushButton->setEnabled(true);

}
void Client::instructionprocessing_tiaoshi(QString str)
{
    QString result=str.mid(3,8);


    if(result=="CAM#STAT"){
       // cout<<"CAM#STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat();
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);

    }else if(result=="CAM1STAT"){
      //  cout<<"CAM1STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM2STAT"){
      //  cout<<"CAM2STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM3STAT"){
      //  cout<<"CAM3STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM4STAT"){
       // cout<<"CAM4STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM5STAT"){
       // cout<<"CAM5STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM6STAT"){
      //  cout<<"CAM6STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM6STAT"){
      //  cout<<"CAM6STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM7STAT"){
      //  cout<<"CAM7STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM8STAT"){
      //  cout<<"CAM8STAT" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        vector<int>res=camerastat_2(result);
        dateprocess(result,res);
        mSocket->write(resultarr);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+result);
    }else if(result=="CAM8ACT1"){
     //   cout<<"CAM1ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);


    }else if(result=="CAM2ACT1"){

       // cout<<"CAM2ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);

    }else if(result=="CAM3ACT1"){

      //  cout<<"CAM3ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);

    }else if(result=="CAM4ACT1"){

      //  cout<<"CAM4ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);

    }else if(result=="CAM5ACT1"){

      //  cout<<"CAM5ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);

    }else if(result=="CAM6ACT1"){

      //  cout<<"CAM6ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);

    }else if(result=="CAM7ACT1"){

      //  cout<<"CAM7ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);

    }else if(result=="CAM8ACT1"){

      //  cout<<"CAM8ACT1" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);

    }else if(result=="CAM1ACT2"){

      //  cout<<"CAM1ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        QByteArray result2;
        result2.append("T");
        result2.append(",");
        result2.append(QString::number(1.0, 10,4));
        result2.append(",");
        result2.append(QString::number(1.0, 10,4));
        result2.append(",");
        result2.append(QString::number(1.0, 10,4));
        QByteArray result3=   dateprocess_2(result, result2,true);
        mSocket->write(result3);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM1ACT2");

    }else if(result=="CAM2ACT2"){

      //  cout<<"CAM2ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        QByteArray result2;
        result2.append("T");
        result2.append(",");
        result2.append(QString::number(2.0, 10,4));
        dateprocess_2(result, result2,true);
        QByteArray result3=   dateprocess_2(result, result2,true);
        mSocket->write(result3);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM2ACT2");
    }else if(result=="CAM3ACT2"){

      //  cout<<"CAM3ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        QByteArray result2;
        result2.append("T");
        result2.append(",");
        result2.append(QString::number(3.0, 10,4));
        dateprocess_2(result, result2,true);
        QByteArray result3=   dateprocess_2(result, result2,true);
        mSocket->write(result3);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM3ACT2");
    }else if(result=="CAM4ACT2"){

      //  cout<<"CAM4ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        QByteArray result2;
        result2.append("T");
        result2.append(",");
        result2.append(QString::number(4.0, 10,4));
        result2.append(",");
        result2.append(QString::number(4.0, 10,4));
        result2.append(",");
        result2.append(QString::number(4.0, 10,4));
        dateprocess_2(result, result2,true);
        QByteArray result3=   dateprocess_2(result, result2,true);
        mSocket->write(result3);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM4ACT2");
    }else if(result=="CAM5ACT2"){

      //  cout<<"CAM5ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        QByteArray result2;
        result2.append("T");
        result2.append(",");
        result2.append(QString::number(5.0, 10,4));
        dateprocess_2(result, result2,true);
        QByteArray result3=   dateprocess_2(result, result2,true);
        mSocket->write(result3);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM5ACT2");
    }else if(result=="CAM6ACT2"){

      //  cout<<"CAM6ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        QByteArray result2;
        result2.append("T");
        result2.append(",");
        result2.append(QString::number(6.0, 10,4));
        dateprocess_2(result, result2,true);
        QByteArray result3=   dateprocess_2(result, result2,true);
        mSocket->write(result3);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM6ACT2");
    }else if(result=="CAM7ACT2"){

      //  cout<<"CAM7ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);


    }else if(result=="CAM7DATA"){

      //  cout<<"CAM7DATA" <<endl;
        getdate(str);
    }else if(result=="CAM8ACT2"){

      //  cout<<"CAM8ACT2" <<endl;
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"getinstruction:"+result);
        QByteArray result2;
        result2.append("T");
        dateprocess_2(result, result2,true);
        QByteArray result3=   dateprocess_2(result, result2,true);
        mSocket->write(result3);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"sendinstruction:"+"CAM8ACT2");
    }else if(result=="CAM#PATH"){
     //   cout<<"CAM#PATH" <<endl;
    }else if(result=="CAM#SHOW"){
     //   cout<<"CAM#SHOW" <<endl;
    }else if(result=="CAM#HIDE"){
      //  cout<<"CAM#HIDE" <<endl;
    }else if(result=="CAM#EXIT"){
      //  cout<<"CAM#EXIT" <<endl;
    }
}
void Client::reconnect()
{
    m_timer.start(2000);








}

void Client::slotTimeout()
{

    emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Disconnected from server, try to reconnect...</font>");
    qDebug() <<"Disconnected from server, try to reconnect...";
    mSocket->connectToHost(ip_,port);
}

