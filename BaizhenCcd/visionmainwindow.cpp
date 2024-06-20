#include "visionmainwindow.h"
#include "ui_visionmainwindow.h"
#pragma execution_character_set("utf-8")

//VisionDaHengCamera *camera_1=new VisionDaHengCamera(GxIAPICPP::gxstring("WL0220030034"),1);
VisionDaHengCamera *camera_1=new VisionDaHengCamera(GxIAPICPP::gxstring("FCB23081203"),1);
//VisionDaHengCamera *camera_2=new VisionDaHengCamera(GxIAPICPP::gxstring("FBF23120694"),2);
VisionDaHengCamera *camera_2=new VisionDaHengCamera(GxIAPICPP::gxstring("FCB23081204"),2);
VisionDaHengCamera *camera_3=new VisionDaHengCamera(GxIAPICPP::gxstring("FBB23090007"),3);
VisionDaHengCamera *camera_4=new VisionDaHengCamera(GxIAPICPP::gxstring("FBB23090006"),4);
VisionDaHengCamera *camera_5=new VisionDaHengCamera(GxIAPICPP::gxstring("FBK24030141"),5);
//VisionDaHengCamera *camera_5=new VisionDaHengCamera(GxIAPICPP::gxstring("WL0220030034"),5);
VisionDaHengCamera *camera_6=new VisionDaHengCamera(GxIAPICPP::gxstring("FBF23120695"),6);
VisionDaHengCamera *camera_7=new VisionDaHengCamera(GxIAPICPP::gxstring("FBB23090131"),7);
VisionDaHengCamera *camera_8=new VisionDaHengCamera(GxIAPICPP::gxstring("FBB23090130"),8);
VisionDaHengCamera *camera_9=new VisionDaHengCamera(GxIAPICPP::gxstring("FBF23120693"),9);



BOOL IsMainWindow(HWND handle);
BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam);
HWND FindMainWindow(unsigned long process_id);//通过进程id号获取主窗口句柄
BOOL IsMainWindow(HWND handle)
{
    return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
}

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
{
    handle_data& data = *(handle_data*)lParam;
    unsigned long process_id = 0;
    GetWindowThreadProcessId(handle, &process_id);
    if (data.process_id != process_id || !IsMainWindow(handle)) {
        return TRUE;
    }
    data.best_handle = handle;
    return FALSE;
}


//通过进程id号获取主窗口句柄
HWND FindMainWindow(unsigned long process_id)
{
    handle_data data;
    data.process_id = process_id;
    data.best_handle = 0;
    EnumWindows(EnumWindowsCallback, (LPARAM)&data);
    return data.best_handle;
}
VisionMainWindow::VisionMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VisionMainWindow)
{
    ui->setupUi(this);
    cout<<"mainthread:"<<QThread::currentThreadId()<<endl;
    init();
    on_start_clicked();


}

VisionMainWindow::~VisionMainWindow()
{


    qDebug()<<"Pogopin stop!!!";
    if(camera_1->isOpenCam){
        emit closecamera_1();

    }
    if(camera_2->isOpenCam){
        emit closecamera_2();

    }
    if(camera_3->isOpenCam){
        emit closecamera_3();

    }
    if(camera_4->isOpenCam){
        emit closecamera_4();

    }
    if(camera_5->isOpenCam){
        emit closecamera_5();

    }
    if(camera_6->isOpenCam){
        emit closecamera_6();

    }
    if(camera_7->isOpenCam){
        emit closecamera_7();

    } if(camera_8->isOpenCam){
        emit closecamera_8();

    }
    delete ui;
    delete chuankou;
}







void VisionMainWindow::timeupdate()
{
    QDateTime time=QDateTime::currentDateTime();
    QString time_str=time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->time->setText(time_str);


}




void VisionMainWindow::getLog(QString log)
{
    ui->Log->append(log);
}



void VisionMainWindow::on_software_1_clicked()
{

}

void VisionMainWindow::on_start_clicked()
{

    ui->start->setEnabled(false);
    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd");
    folderPath =QApplication::applicationDirPath()+"//image//"+time;
    folderPath_1 =QApplication::applicationDirPath()+"//image//"+time+"//image_1_success";
    folderPath_2 =QApplication::applicationDirPath()+"//image//"+time+"//image_2_success";
    folderPath_3 =QApplication::applicationDirPath()+"//image//"+time+"//image_3_success";
    folderPath_4 =QApplication::applicationDirPath()+"//image//"+time+"//image_4_success";
    folderPath_5 =QApplication::applicationDirPath()+"//image//"+time+"//image_5_success";
    folderPath_6 =QApplication::applicationDirPath()+"//image//"+time+"//image_6_success";
    folderPath_7 =QApplication::applicationDirPath()+"//image//"+time+"//image_7_success";
    folderPath_8 =QApplication::applicationDirPath()+"//image//"+time+"//image_8_success";
    folderPath_9 =QApplication::applicationDirPath()+"//image//"+time+"//image_1_fail";
    folderPath_10 =QApplication::applicationDirPath()+"//image//"+time+"//image_2_fail";
    folderPath_11 =QApplication::applicationDirPath()+"//image//"+time+"//image_3_fail";
    folderPath_12 =QApplication::applicationDirPath()+"//image//"+time+"//image_4_fail";
    folderPath_13 =QApplication::applicationDirPath()+"//image//"+time+"//image_5_fail";
    folderPath_14 =QApplication::applicationDirPath()+"//image//"+time+"//image_6_fail";
    folderPath_15 =QApplication::applicationDirPath()+"//image//"+time+"//image_7_fail";
    folderPath_16 =QApplication::applicationDirPath()+"//image//"+time+"//image_8_fail";
    QDir dir(folderPath);
    QDir dir_1(folderPath_1);
    QDir dir_2(folderPath_2);
    QDir dir_3(folderPath_3);
    QDir dir_4(folderPath_4);
    QDir dir_5(folderPath_5);
    QDir dir_6(folderPath_6);
    QDir dir_7(folderPath_7);
    QDir dir_8(folderPath_8);
    QDir dir_9(folderPath_9);
    QDir dir_10(folderPath_10);
    QDir dir_11(folderPath_11);
    QDir dir_12(folderPath_12);
    QDir dir_13(folderPath_13);
    QDir dir_14(folderPath_14);
    QDir dir_15(folderPath_15);
    QDir dir_16(folderPath_16);
    camera_1->folderPath_success=folderPath_1;
    camera_2->folderPath_success=folderPath_2;
    camera_3->folderPath_success=folderPath_3;
    camera_4->folderPath_success=folderPath_4;
    camera_5->folderPath_success=folderPath_5;
    camera_6->folderPath_success=folderPath_6;
    camera_7->folderPath_success=folderPath_7;
    camera_8->folderPath_success=folderPath_8;
    camera_1->folderPath_fail=folderPath_9;
    camera_2->folderPath_fail=folderPath_10;
    camera_3->folderPath_fail=folderPath_11;
    camera_4->folderPath_fail=folderPath_12;
    camera_5->folderPath_fail=folderPath_13;
    camera_6->folderPath_fail=folderPath_14;
    camera_7->folderPath_fail=folderPath_15;
    camera_8->folderPath_fail=folderPath_16;


    if(!dir.exists())
    {
        dir.mkdir(folderPath);

        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images");

    }

    if(!dir_1.exists())
    {
        dir_1.mkdir(folderPath_1);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_1");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_1");

    }
    if(!dir_2.exists())
    {
        dir_2.mkdir(folderPath_2);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_2");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_2");

    }
    if(!dir_3.exists())
    {
        dir_3.mkdir(folderPath_3);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_3");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_3");

    }
    if(!dir_4.exists())
    {
        dir_4.mkdir(folderPath_4);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_4");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_4");

    }
    if(!dir_5.exists())
    {
        dir_5.mkdir(folderPath_5);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_5");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_5");

    }
    if(!dir_6.exists())
    {
        dir_6.mkdir(folderPath_6);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_6");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_6");

    }
    if(!dir_7.exists())
    {
        dir_7.mkdir(folderPath_7);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_7");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_7");

    }
    if(!dir_8.exists())
    {
        dir_8.mkdir(folderPath_8);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_8");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_8");

    }
    if(!dir_9.exists())
    {
        dir_9.mkdir(folderPath_9);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_9");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_9");

    }
    if(!dir_10.exists())
    {
        dir_10.mkdir(folderPath_10);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_10");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_10");

    }
    if(!dir_11.exists())
    {
        dir_11.mkdir(folderPath_11);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_11");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_11");

    }
    if(!dir_12.exists())
    {
        dir_12.mkdir(folderPath_12);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_12");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_12");

    }
    if(!dir_13.exists())
    {
        dir_13.mkdir(folderPath_13);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_13");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_13");

    }
    if(!dir_14.exists())
    {
        dir_14.mkdir(folderPath_14);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_14");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_14");

    }
    if(!dir_15.exists())
    {
        dir_15.mkdir(folderPath_15);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_15");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_15");

    }
    if(!dir_16.exists())
    {
        dir_16.mkdir(folderPath_16);
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Successfully created today's image save folder_16");
    }else{
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"There is already a folder for saving today's images_16");

    }
    ui->form_1->id=1;
    ui->form_2->id=2;
    ui->form_3->id=3;
    ui->form_4->id=4;
    ui->form_5->id=5;
    ui->form_6->id=6;
    ui->form_7->id=7;
    ui->form_8->id=8;
    DateVar::setdate();

    //打开服务端
    server->on_pushButton_start_clicked();
    //打开全部灯光
    //    chuankou->on_pushButton_clicked();
    //    chuankou->openlight_all();
    //加载模板
    VisionMeasure::loadtemplate(0);
    //tcp连接
    client->on_pushButton_clicked();
    //    //打开相机
        camera_1->opencamera();
        camera_2->opencamera();
        camera_3->opencamera();
        camera_4->opencamera();
        camera_5->opencamera();
        Sleep(2000);
        camera_1->startcapture();
        camera_2->startcapture();

    //算法参数加载
    VisionMeasure::getmeasurecanshu();
    detectionresultform->getini();
    motionform->on_pushButton_load_clicked();

}

void VisionMainWindow::on_chuankou_clicked()
{
    chuankou->show();

}

void VisionMainWindow::on_TCP_clicked()
{
    client->show();

}

void VisionMainWindow::on_setparameter_clicked()
{
    // setparameter->show();
    detectionresultform->show();
    //    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/image",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
    //    if(fileName == nullptr)
    //        return;
    //    Mat mat=imread(fileName.toStdString(),0);
    //    camera_1->image_measure(1,mat);

}


void VisionMainWindow::on_measure_clicked()
{

    //图像格式转换
    //findlineform->show();

    settingmeasure->show();

}
void VisionMainWindow::getlightsituation(QString situation, int num)
{
    QString a="toolButton_light_1";
    if(situation=="open"){
        switch (num) {
        case 1:{
            ui->toolButton_light_1->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 2:{
            ui->toolButton_light_2->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 3:{
            ui->toolButton_light_3->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 4:{
            ui->toolButton_light_4->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 5:{
            ui->toolButton_light_5->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 6:{
            ui->toolButton_light_6->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 7:{
            ui->toolButton_light_7->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 8:{
            ui->toolButton_light_8->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 9:{
            ui->toolButton_light_9->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 10:{
            ui->toolButton_light_10->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 11:{
            ui->toolButton_light_11->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }
        case 12:{
            ui->toolButton_light_12->setIcon(QIcon(":/image/image/light1.png"));
            break;
        }

        }
    }else{
        switch (num) {
        case 1:{
            ui->toolButton_light_1->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 2:{
            ui->toolButton_light_2->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 3:{
            ui->toolButton_light_3->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 4:{
            ui->toolButton_light_4->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 5:{
            ui->toolButton_light_5->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 6:{
            ui->toolButton_light_6->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 7:{
            ui->toolButton_light_7->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 8:{
            ui->toolButton_light_8->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 9:{
            ui->toolButton_light_9->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 10:{
            ui->toolButton_light_10->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 11:{
            ui->toolButton_light_11->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }
        case 12:{
            ui->toolButton_light_12->setIcon(QIcon(":/image/image/light2.png"));
            break;
        }

        }

    }
}
void VisionMainWindow::getinstruction(QString name)
{
    if(name=="CAM1ACT1"){
        // cout<<"MAINCAM1ACT1" <<endl;
        camera_1->m_triggerMode= ui->triggermode_1->currentText();
        emit softmode_1();
        client->if_action_1=false;
    }else if(name=="CAM2ACT1"){
        // cout<<"MAINCAM2ACT1" <<endl;
        camera_2->m_triggerMode= ui->triggermode_2->currentText();
        emit softmode_2();
        client->if_action_2=false;
    }else if(name=="CAM3ACT1"){
        // cout<<"MAINCAM3ACT1" <<endl;
        camera_3->m_triggerMode= ui->triggermode_3->currentText();
        emit softmode_3();
        client->if_action_3=false;
    }else if(name=="CAM4ACT1"){
        // cout<<"MAINCAM4ACT1" <<endl;
        camera_4->m_triggerMode= ui->triggermode_4->currentText();
        emit softmode_4();
        client->if_action_4=false;
    }else if(name=="CAM5ACT1"){
        // cout<<"MAINCAM5ACT1" <<endl;
        camera_5->m_triggerMode= ui->triggermode_5->currentText();
        emit softmode_5();
        client->if_action_5=false;
    }else if(name=="CAM6ACT1"){
        // cout<<"MAINCAM6ACT1" <<endl;
        camera_6->m_triggerMode= ui->triggermode_6->currentText();
        emit softmode_6();
        client->if_action_6=false;
    }else if(name=="CAM7ACT1"){
        // cout<<"MAINCAM7ACT1" <<endl;
        // camera_7->m_triggerMode= ui->triggermode_7->currentText();
        // emit softmode_7();
        // client->if_action_7=false;
    }else if(name=="CAM8ACT1"){
        // cout<<"MAINCAM8ACT1" <<endl;
        // camera_8->m_triggerMode= ui->triggermode_8->currentText();
        // emit softmode_8();
        // client->if_action_8=false;
    }else if(name=="CAM1ACT2"){
        //cout<<"MAINCAM1ACT2" <<endl;
        if(ui->triggermode_1->currentText()=="OFF"){
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_1 Soft trigger mode not turned on</font>");
            return;
        }
        
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_1 start");

        camera_1->ifmeasure=1;
        camera_1->m_triggerMode= ui->triggermode_1->currentText();
        emit softmode_1();

    }else if(name=="CAM2ACT2"){
        // cout<<"MAINCAM2ACT2" <<endl;
        if(ui->triggermode_2->currentText()=="OFF"){
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_2 Soft trigger mode not turned on</font>");
            return;
        }

        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_2 start");
        camera_2->ifmeasure=2;
        camera_2->m_triggerMode= ui->triggermode_2->currentText();
        emit softmode_2();

    }else if(name=="CAM3ACT2"){
        // cout<<"MAINCAM3ACT2" <<endl;
        if(ui->triggermode_3->currentText()=="OFF"){
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_3 Soft trigger mode not turned on</font>");
            return;
        }

        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_3 start");
        camera_3->ifmeasure=3;
        camera_3->m_triggerMode= ui->triggermode_3->currentText();
        emit softmode_3();

    }else if(name=="CAM4ACT2"){
        //  cout<<"MAINCAM4ACT2" <<endl;
        if(ui->triggermode_4->currentText()=="OFF"){
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_4 Soft trigger mode not turned on</font>");
            return;
        }

        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_4 start");
        camera_4->ifmeasure=4;
        camera_4->m_triggerMode= ui->triggermode_4->currentText();
        emit softmode_4();

    }else if(name=="CAM5ACT2"){
        //  cout<<"MAINCAM5ACT2" <<endl;
        if(ui->triggermode_5->currentText()=="OFF"){
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_5 Soft trigger mode not turned on</font>");
            return;
        }

        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_5 start");
        camera_5->ifmeasure=5;
        camera_5->m_triggerMode= ui->triggermode_5->currentText();
        emit softmode_5();

    }else if(name=="CAM6ACT2"){
        //  cout<<"MAINCAM6ACT2" <<endl;
        if(ui->triggermode_6->currentText()=="OFF"){
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_6 Soft trigger mode not turned on</font>");
            return;
        }

        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_6 start");
        camera_6->ifmeasure=6;
        camera_6->m_triggerMode= ui->triggermode_6->currentText();
        emit softmode_6();

    }else if(name=="CAM7ACT2"){
        // cout<<"MAINCAM7ACT2" <<endl;
        //        if(ui->triggermode_7->currentText()=="OFF"){
        //            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_7 Soft trigger mode not turned on</font>");
        //            return;
        //        }

        //        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_7 start");
        //        camera_7->ifmeasure=7;
        //        camera_7->m_triggerMode= ui->triggermode_7->currentText();
        //        emit softmode_7();
        //        VisionMeasure::loadtemplate();
        //        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        //        if(fileName == nullptr)
        //            return;
        //        Mat a=imread(fileName.toStdString());
        //        camera_7->image_measure(7,a);

    }else if(name=="CAM8ACT2"){
        //  cout<<"MAINCAM8ACT2" <<endl;
        //        if(ui->triggermode_8->currentText()=="OFF"){
        //            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_8 Soft trigger mode not turned on</font>");
        //            return;
        //        }

        //        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_8 start");
        //        camera_8->ifmeasure=8;
        //        camera_8->m_triggerMode= ui->triggermode_8->currentText();
        //        emit softmode_8();

    }

}



void VisionMainWindow::on_pushButton_clicked()
{
    chuankou->openlight_all();
}

void VisionMainWindow::on_pushButton_2_clicked()
{
    chuankou->closelight_all();
}

void VisionMainWindow::on_Log_textChanged()
{
    ui->Log->moveCursor(QTextCursor::End);
}

void VisionMainWindow::updatesettingmeasure(int num)
{

    switch (num) {
    case 1:
        if(!camera_1->imgForDisplay.isNull()){
            QImage qimage=camera_1->imgForDisplay.copy();
            settingmeasure->imageData_1=qimage;
            settingmeasure->sourceimage = camera_1->image.clone();

            settingmeasure->init_1();

            QMessageBox::information(settingmeasure,"info","update image succeed!");

        }else{
            QMessageBox::critical(settingmeasure,"critical","image is empty!");
        }

        break;
    case 2:
        if(!camera_2->imgForDisplay.isNull()){
            QImage qimage=camera_2->imgForDisplay.copy();
            settingmeasure->imageData_1=qimage;
            settingmeasure->sourceimage = camera_2->image.clone();
            settingmeasure->init_1();
            QMessageBox::information(settingmeasure,"info","update image succeed!");
        }else{
            QMessageBox::critical(settingmeasure,"critical","image is empty!");
        }

        break;
    case 3:
        if(!camera_3->imgForDisplay.isNull()){
            QImage qimage=camera_3->imgForDisplay.copy();
            settingmeasure->imageData_1=qimage;
            settingmeasure->sourceimage = camera_3->image.clone();

            settingmeasure->init_1();
            QMessageBox::information(settingmeasure,"info","update image succeed!");
        }else{
            QMessageBox::critical(settingmeasure,"critical","image is empty!");
        }

        break;
    case 4:
        if(!camera_4->imgForDisplay.isNull()){
            QImage qimage=camera_4->imgForDisplay.copy();
            settingmeasure->imageData_1=qimage;
            settingmeasure->sourceimage = camera_4->image.clone();

            settingmeasure->init_1();
            QMessageBox::information(settingmeasure,"info","update image succeed!");
        }else{
            QMessageBox::critical(settingmeasure,"critical","image is empty!");
        }

        break;
    case 5:
        if(!camera_5->imgForDisplay.isNull()){
            QImage qimage=camera_5->imgForDisplay.copy();
            settingmeasure->imageData_1=qimage;
            settingmeasure->sourceimage = camera_5->image.clone();

            settingmeasure->init_1();
            QMessageBox::information(settingmeasure,"info","update image succeed!");
        }else{
            QMessageBox::critical(settingmeasure,"critical","image is empty!");
        }

        break;
    case 6:
        if(!camera_6->imgForDisplay.isNull()){
            QImage qimage=camera_6->imgForDisplay.copy();
            settingmeasure->imageData_1=qimage;
            settingmeasure->sourceimage = camera_6->image.clone();

            settingmeasure->init_1();
            QMessageBox::information(settingmeasure,"info","update image succeed!");
        }else{
            QMessageBox::critical(settingmeasure,"critical","image is empty!");
        }

        break;
    case 7:
        if(!camera_7->imgForDisplay.isNull()){
            QImage qimage=camera_7->imgForDisplay.copy();
            settingmeasure->imageData_1=qimage;
            settingmeasure->sourceimage =camera_7->image.clone();

            settingmeasure->init_1();
            QMessageBox::information(settingmeasure,"info","update image succeed!");
        }else{
            QMessageBox::critical(settingmeasure,"critical","image is empty!");
        }

        break;
    case 8:
        if(!camera_8->imgForDisplay.isNull()){
            QImage qimage=camera_8->imgForDisplay.copy();
            settingmeasure->imageData_1=qimage;
            settingmeasure->sourceimage = camera_8->image.clone();

            settingmeasure->init_1();
            QMessageBox::information(settingmeasure,"info","update image succeed!");
        }else{
            QMessageBox::critical(settingmeasure,"critical","image is empty!");
        }

        break;
    default:
        break;
    }
}

void VisionMainWindow::on_stop_clicked()
{
    if(ui->stop->text()=="正常模式"){
        client->moshi=false;
        ui->stop->setText("调试模式");
    }else{
        client->moshi=true;
        ui->stop->setText("正常模式");
    }
}

void VisionMainWindow::saveimage(CImageDataPointer &objImageDataPointer, string path)
{
    cout<<"ccccc"<<endl;
    bitmap_1->SaveBmp(objImageDataPointer,path);
}

void VisionMainWindow::ifopencamera(int num, int num2)
{
    switch (num) {
    case 1:
        if(num2==1){
            ui->camera_1->setIcon(QIcon(":/image/image/camera_open.png"));
            ui->camera_1->setIconSize(QSize(32,32));


        }else{
            ui->camera_1->setIcon(QIcon(":/image/image/camera.png"));
            ui->camera_1->setIconSize(QSize(32,32));

        }
        break;
    case 2:
        if(num2==1){
            ui->camera_2->setIcon(QIcon(":/image/image/camera_open.png"));
            ui->camera_2->setIconSize(QSize(32,32));


        }else{
            ui->camera_2->setIcon(QIcon(":/image/image/camera.png"));
            ui->camera_2->setIconSize(QSize(32,32));

        }
        break;
    case 3:
        if(num2==1){
            ui->camera_3->setIcon(QIcon(":/image/image/camera_open.png"));
            ui->camera_3->setIconSize(QSize(32,32));


        }else{
            ui->camera_3->setIcon(QIcon(":/image/image/camera.png"));
            ui->camera_3->setIconSize(QSize(32,32));

        }
        break;
    case 4:
        if(num2==1){
            ui->camera_4->setIcon(QIcon(":/image/image/camera_open.png"));
            ui->camera_4->setIconSize(QSize(32,32));


        }else{
            ui->camera_4->setIcon(QIcon(":/image/image/camera.png"));
            ui->camera_4->setIconSize(QSize(32,32));

        }
        break;
    case 5:
        if(num2==1){
            ui->camera_5->setIcon(QIcon(":/image/image/camera_open.png"));
            ui->camera_5->setIconSize(QSize(32,32));


        }else{
            ui->camera_5->setIcon(QIcon(":/image/image/camera.png"));
            ui->camera_5->setIconSize(QSize(32,32));

        }
        break;
    case 6:
        if(num2==1){
            ui->camera_6->setIcon(QIcon(":/image/image/camera_open.png"));
            ui->camera_6->setIconSize(QSize(32,32));

        }else{
            ui->camera_6->setIcon(QIcon(":/image/image/camera.png"));
            ui->camera_6->setIconSize(QSize(32,32));

        }
        break;
        //    case 7:
        //        if(num2==1){
        //            ui->camera_7->setIcon(QIcon(":/image/image/camera_open.png"));
        //            ui->camera_7->setIconSize(QSize(32,32));

        //        }else{
        //            ui->camera_7->setIcon(QIcon(":/image/image/camera.png"));
        //            ui->camera_7->setIconSize(QSize(32,32));

        //        }
        //        break;
        //    case 8:
        //        if(num2==1){
        //            ui->camera_8->setIcon(QIcon(":/image/image/camera_open.png"));
        //            ui->camera_8->setIconSize(QSize(32,32));


        //        }else{
        //            ui->camera_8->setIcon(QIcon(":/image/image/camera.png"));
        //            ui->camera_8->setIconSize(QSize(32,32));

        //        }
        //        break;
    default:
        break;
    }
}

void VisionMainWindow::getcomputerinfo(QString info)
{
    labCellIndex->setText(info);
}

void VisionMainWindow::init()
{
    qDebug()<<"Pogopin start!!!";

    ui->Log->moveCursor(QTextCursor::End);
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&VisionMainWindow::timeupdate);//[this]表示信号是传给本身的
    timer->start(1000);
    QTimer *timerres = new QTimer(this);
    cominfo=new computerinfothread;
    cominfo->start();


    //ui风格设计
    ui->groupBox_camera_1->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_camera_2->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_camera_3->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_camera_4->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_camera_5->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_camera_6->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_camera_7->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_camera_8->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_camera_9->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                         );
    ui->groupBox_1->setStyleSheet("border: 1px solid black;background-color: rgb(243, 254, 255);"
                                  );
    ui->groupBox_2->setStyleSheet("border: 1px solid black;"
                                  );
    ui->groupBox_3->setStyleSheet("border: 1px solid black;background-color: rgb(255, 248, 252);"
                                  );
    ui->groupBox_4->setStyleSheet("border: 1px solid black;background-color: rgb(255, 248, 252);"
                                  );
    ui->groupBox_5->setStyleSheet("border: 1px solid black;background-color: rgb(255, 248, 252);"
                                  );
    // 初始化状态栏
    labCellIndex = new QLabel("",this);
    QFont ft;
    ft.setPointSize (14);
    labCellIndex->setFont(ft);
    labCellIndex->setMinimumWidth(350);
    ui->statusBar->addWidget(labCellIndex);

    QImage img;
    img.load(":/image/image/tubiao.png");

    QImage imgScaled;
    imgScaled = img.scaled(ui->tubiao->size(), Qt::KeepAspectRatio);//默认保持原图的宽高比  以label大小为大小
    ui->tubiao->setPixmap(QPixmap::fromImage(imgScaled));
    setWindowTitle("Pogopin-CCD");
    this->setWindowIcon(QIcon(":/image/image/apple.png"));
    this->setIconSize(QSize(400,300));

    //QToolButton *toolButton = new QToolButton(ui->toolButton_2);
    // 设置按钮的图标和文本

    ui->start->setIcon(QIcon(":/image/image/start.png"));
    ui->start->setIconSize(QSize(40,40));
    ui->start->setText("Start");
    // 设置按钮的布局方式为文字在下方
    ui->start->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->start->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->stop->setIcon(QIcon(":/image/image/stop.png"));
    ui->stop->setIconSize(QSize(40,40));
    ui->stop->setText(("正常模式"));
    // 设置按钮的布局方式为文字在下方
    ui->stop->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->stop->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);



    ui->setparameter->setIcon(QIcon(":/image/image/qa.png"));
    ui->setparameter->setIconSize(QSize(40,40));
    ui->setparameter->setText("QA情况");
    // 设置按钮的布局方式为文字在下方
    ui->setparameter->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->setparameter->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->motioncontrol->setIcon(QIcon(":/image/image/motioncontrol.png"));
    ui->motioncontrol->setIconSize(QSize(75,75));
    ui->motioncontrol->setText("运动控制");
    // 设置按钮的布局方式为文字在下方
    ui->motioncontrol->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->motioncontrol->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->autofocus->setIcon(QIcon(":/image/image/autofocus.png"));
    ui->autofocus->setIconSize(QSize(75,75));
    ui->autofocus->setText("自动对焦");
    // 设置按钮的布局方式为文字在下方
    ui->autofocus->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->autofocus->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->chuankou->setIcon(QIcon(":/image/image/canshu.png"));
    ui->chuankou->setIconSize(QSize(75,75));
    ui->chuankou->setText("串口");
    // 设置按钮的布局方式为文字在下方
    ui->chuankou->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->chuankou->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->TCP->setIcon(QIcon(":/image/image/tongxin.png"));
    ui->TCP->setIconSize(QSize(75,75));
    ui->TCP->setText("通信");
    // 设置按钮的布局方式为文字在下方
    ui->TCP->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->TCP->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->measure->setIcon(QIcon(":/image/image/celiang.png"));
    ui->measure->setIconSize(QSize(75,75));
    ui->measure->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->measure->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->measure->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_1->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_1->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_2->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_2->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_3->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_3->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_4->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_4->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_5->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_5->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_6->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_6->setIconSize(QSize(75,75));
    //  ui->toolButton_ligh_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_7->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_7->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_8->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_8->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_8->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_9->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_9->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_9->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_10->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_10->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_10->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_10->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_11->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_11->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_11->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_11->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->toolButton_light_12->setIcon(QIcon(":/image/image/light2.png"));
    ui->toolButton_light_12->setIconSize(QSize(75,75));
    //  ui->toolButton_light_1->setText("测量");
    // 设置按钮的布局方式为文字在下方
    ui->toolButton_light_12->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // 设置按钮大小调整为内容适应
    ui->toolButton_light_12->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);



    //设置log和字体大小
    ui->Log->moveCursor(QTextCursor::End);
    QFont font;
    font.setPointSize(12);//字体大小
    ui->Log->setFont(font);

    QMenu *menu_1 = new QMenu(this);
    QMenu *menu_2 = new QMenu(this);
    QMenu *menu_3 = new QMenu(this);
    QMenu *menu_4 = new QMenu(this);
    QMenu *menu_5 = new QMenu(this);
    QMenu *menu_6 = new QMenu(this);
    QMenu *menu_7 = new QMenu(this);
    QMenu *menu_8 = new QMenu(this);
    QMenu *menu_9 = new QMenu(this);
    QAction *action_1_1=menu_1->addAction("open camera");
    QAction *action_1_2=menu_1->addAction("close camera");
    QAction *action_1_3=menu_1->addAction("start capture");
    QAction *action_1_4=menu_1->addAction("stop capture");
    QAction *action_1_5=menu_1->addAction("load image");
    QAction *action_1_6=menu_1->addAction("Manual detection");
    QAction *action_2_1=menu_2->addAction("open camera");
    QAction *action_2_2=menu_2->addAction("close camera");
    QAction *action_2_3=menu_2->addAction("start capture");
    QAction *action_2_4=menu_2->addAction("stop capture");
    QAction *action_2_5=menu_2->addAction("load image");
    QAction *action_2_6=menu_2->addAction("Manual detection");
    QAction *action_3_1=menu_3->addAction("open camera");
    QAction *action_3_2=menu_3->addAction("close camera");
    QAction *action_3_3=menu_3->addAction("start capture");
    QAction *action_3_4=menu_3->addAction("stop capture");
    QAction *action_3_5=menu_3->addAction("load image");
    QAction *action_3_6=menu_3->addAction("Manual detection");
    QAction *action_4_1=menu_4->addAction("open camera");
    QAction *action_4_2=menu_4->addAction("close camera");
    QAction *action_4_3=menu_4->addAction("start capture");
    QAction *action_4_4=menu_4->addAction("stop capture");
    QAction *action_4_5=menu_4->addAction("load image");
    QAction *action_4_6=menu_4->addAction("Manual detection");
    QAction *action_5_1=menu_5->addAction("open camera");
    QAction *action_5_2=menu_5->addAction("close camera");
    QAction *action_5_3=menu_5->addAction("start capture");
    QAction *action_5_4=menu_5->addAction("stop capture");
    QAction *action_5_5=menu_5->addAction("load image");
    QAction *action_5_6=menu_5->addAction("Manual detection");
    QAction *action_6_1=menu_6->addAction("open camera");
    QAction *action_6_2=menu_6->addAction("close camera");
    QAction *action_6_3=menu_6->addAction("start capture");
    QAction *action_6_4=menu_6->addAction("stop capture");
    QAction *action_6_5=menu_6->addAction("load image");
    QAction *action_6_6=menu_6->addAction("Manual detection");

    QAction *action_7_1=menu_7->addAction("open camera");
    QAction *action_7_2=menu_7->addAction("close camera");
    QAction *action_7_3=menu_7->addAction("start capture");
    QAction *action_7_4=menu_7->addAction("stop capture");
    QAction *action_7_5=menu_7->addAction("load image");
    QAction *action_7_6=menu_7->addAction("Manual detection");

    QAction *action_8_1=menu_8->addAction("open camera");
    QAction *action_8_2=menu_8->addAction("close camera");
    QAction *action_8_3=menu_8->addAction("start capture");
    QAction *action_8_4=menu_8->addAction("stop capture");
    QAction *action_8_5=menu_8->addAction("load image");
    QAction *action_8_6=menu_8->addAction("Manual detection");

    QAction *action_9_1=menu_9->addAction("open camera");
    QAction *action_9_2=menu_9->addAction("close camera");
    QAction *action_9_3=menu_9->addAction("start capture");
    QAction *action_9_4=menu_9->addAction("stop capture");
    QAction *action_9_5=menu_9->addAction("load image");
    QAction *action_9_6=menu_9->addAction("Manual detection");
    ui->camera_1->setPopupMode(QToolButton::MenuButtonPopup);
    ui->camera_1->setAutoRaise(true);
    ui->camera_1->setMenu(menu_1);
    ui->camera_2->setPopupMode(QToolButton::MenuButtonPopup);
    ui->camera_2->setAutoRaise(true);
    ui->camera_2->setMenu(menu_2);
    ui->camera_3->setPopupMode(QToolButton::MenuButtonPopup);
    ui->camera_3->setAutoRaise(true);
    ui->camera_3->setMenu(menu_3);
    ui->camera_4->setPopupMode(QToolButton::MenuButtonPopup);
    ui->camera_4->setAutoRaise(true);
    ui->camera_4->setMenu(menu_4);
    ui->camera_5->setPopupMode(QToolButton::MenuButtonPopup);
    ui->camera_5->setAutoRaise(true);
    ui->camera_5->setMenu(menu_5);
    ui->camera_6->setPopupMode(QToolButton::MenuButtonPopup);
    ui->camera_6->setAutoRaise(true);
    ui->camera_6->setMenu(menu_6);
    //    ui->camera_7->setPopupMode(QToolButton::MenuButtonPopup);
    //    ui->camera_7->setAutoRaise(true);
    //    ui->camera_7->setMenu(menu_7);
    //    ui->camera_8->setPopupMode(QToolButton::MenuButtonPopup);
    //    ui->camera_8->setAutoRaise(true);
    //    ui->camera_8->setMenu(menu_8);
      QMenu *menu_10 = new QMenu(this);
      QAction *action_10_1=menu_10->addAction("TCP Client");
      QAction *action_10_2=menu_10->addAction("TCP Server");
      ui->TCP->setPopupMode(QToolButton::MenuButtonPopup);
      ui->TCP->setAutoRaise(true);
       ui->TCP->setMenu(menu_10);

       connect(action_10_1,&QAction::triggered,this,[&](){
          client->show();
       }); connect(action_10_2,&QAction::triggered,this,[&](){

          server->show();
       });

    connect(action_1_1,&QAction::triggered,this,[&](){


        emit opencamera_1();




    });
    connect(action_2_1,&QAction::triggered,this,[&](){

        emit opencamera_2();



    });
    connect(action_3_1,&QAction::triggered,this,[&](){

        emit opencamera_3();


    });
    connect(action_4_1,&QAction::triggered,this,[&](){





        emit opencamera_4();


    });
    connect(action_5_1,&QAction::triggered,this,[&](){

        emit opencamera_5();

    });
    connect(action_6_1,&QAction::triggered,this,[&](){

        emit opencamera_6();

    });
    connect(action_7_1,&QAction::triggered,this,[&](){

        emit opencamera_7();


    });
    connect(action_8_1,&QAction::triggered,this,[&](){

        emit opencamera_8();

    });
    //关闭相机
    connect(action_1_2,&QAction::triggered,this,[&](){
        //camera_1->closecamera();

        emit closecamera_1();


    });
    connect(action_2_2,&QAction::triggered,this,[&](){
        emit closecamera_2();
        //camera_2->closecamera();

    });
    connect(action_3_2,&QAction::triggered,this,[&](){
        emit closecamera_3();
        //camera_3->closecamera();

    });
    connect(action_4_2,&QAction::triggered,this,[&](){
        // camera_4->closecamera();
        emit closecamera_4();

    });
    connect(action_5_2,&QAction::triggered,this,[&](){
        // camera_5->closecamera();
        emit closecamera_5();

    });
    connect(action_6_2,&QAction::triggered,this,[&](){
        // camera_6->closecamera();
        emit closecamera_6();

    });
    connect(action_7_2,&QAction::triggered,this,[&](){
        //camera_7->closecamera();
        emit closecamera_7();


    });
    connect(action_8_2,&QAction::triggered,this,[&](){
        // camera_8->closecamera();
        emit closecamera_8();

    });
    //开始采集
    connect(action_1_3,&QAction::triggered,this,[&](){

        Sleep(600);
        if(camera_1->isOpenCam){
            bitmap_1->addDevicePtr(camera_1->m_objDevicePtr);
        }

        emit startcapture_1();

    });
    connect(action_2_3,&QAction::triggered,this,[&](){
        Sleep(600);
        if(camera_2->isOpenCam){
            bitmap_2->addDevicePtr(camera_2->m_objDevicePtr);
        }
        emit startcapture_2();
    });
    connect(action_3_3,&QAction::triggered,this,[&](){
        Sleep(600);
        if(camera_3->isOpenCam){
            bitmap_3->addDevicePtr(camera_3->m_objDevicePtr);
        }
        emit startcapture_3();
    });
    connect(action_4_3,&QAction::triggered,this,[&](){
        Sleep(600);
        if(camera_4->isOpenCam){
            bitmap_4->addDevicePtr(camera_4->m_objDevicePtr);
        }
        emit startcapture_4();;
    });
    connect(action_5_3,&QAction::triggered,this,[&](){
        Sleep(600);
        if(camera_5->isOpenCam){
            bitmap_5->addDevicePtr(camera_5->m_objDevicePtr);
        }
        emit startcapture_5();
    });
    connect(action_6_3,&QAction::triggered,this,[&](){
        Sleep(600);
        if(camera_6->isOpenCam){
            bitmap_6->addDevicePtr(camera_6->m_objDevicePtr);
        }
        emit startcapture_6();
    });
    connect(action_7_3,&QAction::triggered,this,[&](){
        Sleep(600);
        if(camera_7->isOpenCam){
            bitmap_7->addDevicePtr(camera_7->m_objDevicePtr);
        }
        emit startcapture_7();;
    });
    connect(action_8_3,&QAction::triggered,this,[&](){
        Sleep(600);
        if(camera_8->isOpenCam){
            bitmap_8->addDevicePtr(camera_8->m_objDevicePtr);
        }
        emit startcapture_8();
    });
    //停止采集
    connect(action_1_4,&QAction::triggered,this,[&](){

        emit stopcapture_1();

    });
    connect(action_2_4,&QAction::triggered,this,[&](){

        emit stopcapture_2();
    });
    connect(action_3_4,&QAction::triggered,this,[&](){

        emit stopcapture_3();
    });
    connect(action_4_4,&QAction::triggered,this,[&](){

        emit stopcapture_4();
    });
    connect(action_5_4,&QAction::triggered,this,[&](){

        emit stopcapture_5();
    });
    connect(action_6_4,&QAction::triggered,this,[&](){

        emit stopcapture_6();
    });
    connect(action_7_4,&QAction::triggered,this,[&](){

        emit stopcapture_7();
    });
    connect(action_8_4,&QAction::triggered,this,[&](){

        emit stopcapture_8();
    });
    //加载图像
    connect(action_1_5,&QAction::triggered,this,[&](){

        //QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/ZF/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        if(fileName == nullptr)
            return;
        imagemeasure_1=imread(fileName.toStdString(),0);
        // measure->measureyuzhi(mat);
        emit sendloadimage_1(imagemeasure_1);

    });
    connect(action_2_5,&QAction::triggered,this,[&](){

        //QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/ZF/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        if(fileName == nullptr)
            return;
        imagemeasure_2=imread(fileName.toStdString(),0);
        emit sendloadimage_2(imagemeasure_2);

    });
    connect(action_3_5,&QAction::triggered,this,[&](){

        //QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/ZF/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        if(fileName == nullptr)
            return;
        imagemeasure_3=imread(fileName.toStdString(),0);
        emit sendloadimage_3(imagemeasure_3);

    });
    connect(action_4_5,&QAction::triggered,this,[&](){

        //QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/ZF/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        if(fileName == nullptr)
            return;
        imagemeasure_4=imread(fileName.toStdString(),0);
        emit sendloadimage_4(imagemeasure_4);

    });
    connect(action_5_5,&QAction::triggered,this,[&](){

        //QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/ZF/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        if(fileName == nullptr)
            return;
        imagemeasure_5=imread(fileName.toStdString(),0);
        emit sendloadimage_5(imagemeasure_5);

    });
    connect(action_6_5,&QAction::triggered,this,[&](){

        //QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/ZF/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        if(fileName == nullptr)
            return;
        imagemeasure_6=imread(fileName.toStdString(),0);
        emit sendloadimage_6(imagemeasure_6);

    });
    connect(action_7_5,&QAction::triggered,this,[&](){

        //QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/ZF/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        if(fileName == nullptr)
            return;
        imagemeasure_7=imread(fileName.toStdString(),0);
        emit sendloadimage_7(imagemeasure_7);

    });
    connect(action_8_5,&QAction::triggered,this,[&](){

        //QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/ZF/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/pogppinimage",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
        if(fileName == nullptr)
            return;
        imagemeasure_8=imread(fileName.toStdString(),0);
        emit sendloadimage_8(imagemeasure_8);

    });
    connect(action_1_6,&QAction::triggered,this,[&](){
        if(!imagemeasure_1.data){
            QMessageBox::critical(this,"critical","image is empty!");
            return;
        }else{
            // camera_1->measure->measureyuzhi(imagemeasure_1);
            camera_1->measure->camera_measure_1(imagemeasure_1,camera_1->measure);
        }


    });
    connect(action_2_6,&QAction::triggered,this,[&](){
        if(!imagemeasure_2.data){
            QMessageBox::critical(this,"critical","image is empty!");
            return;
        }else{
            camera_2->measure->camera_measure_2(imagemeasure_2,camera_2->measure);
        }


    });
    connect(action_3_6,&QAction::triggered,this,[&](){
        if(!imagemeasure_3.data){
            QMessageBox::critical(this,"critical","image is empty!");
            return;
        }else{
            camera_3->measure->camera_measure_3_2(imagemeasure_3,camera_3->measure);
        }


    });
    connect(action_4_6,&QAction::triggered,this,[&](){

        if(!imagemeasure_4.data){
            QMessageBox::critical(this,"critical","image is empty!");
            return;
        }else{
            camera_4->measure->camera_measure_4_2(imagemeasure_4,camera_4->measure);
        }

    });
    connect(action_5_6,&QAction::triggered,this,[&](){
        if(!imagemeasure_5.data){
            QMessageBox::critical(this,"critical","image is empty!");
            return;
        }else{
            camera_5->measure->camera_measure_5_2(imagemeasure_5,camera_5->measure);
        }

    });
    connect(action_6_6,&QAction::triggered,this,[&](){
        if(!imagemeasure_1.data){
            QMessageBox::critical(this,"critical","image is empty!");
            return;
        }else{
            camera_6->measure->camera_measure_6(imagemeasure_6,camera_6->measure);
        }


    });
    //    connect(action_7_6,&QAction::triggered,this,[&](){
    //        if(!imagemeasure_1.data){
    //            QMessageBox::critical(this,"critical","image is empty!");
    //            return;
    //        }else{
    //            camera_7->measure->camera_measure_7(imagemeasure_7,camera_7->measure);
    //        }


    //    });
    //    connect(action_8_6,&QAction::triggered,this,[&](){


    //    });
    //软触发
    connect(ui->software_1,&QToolButton::clicked,this,[=](){
        camera_1->m_triggerMode= ui->triggermode_1->currentText();
        emit softmode_1();
    });
    connect(ui->software_2,&QToolButton::clicked,this,[=](){
        camera_2->m_triggerMode= ui->triggermode_2->currentText();
        emit softmode_2();
    });
    connect(ui->software_3,&QToolButton::clicked,this,[=](){
        camera_3->m_triggerMode= ui->triggermode_3->currentText();
        emit softmode_3();
    });
    connect(ui->software_4,&QToolButton::clicked,this,[=](){
        camera_4->m_triggerMode= ui->triggermode_4->currentText();
        emit softmode_4();
    });
    connect(ui->software_5,&QToolButton::clicked,this,[=](){
        camera_5->m_triggerMode= ui->triggermode_5->currentText();
        emit softmode_5();
    });
    connect(ui->software_6,&QToolButton::clicked,this,[=](){
        camera_6->m_triggerMode= ui->triggermode_6->currentText();
        emit softmode_6();
    });
    //    connect(ui->software_7,&QToolButton::clicked,this,[=](){
    //        camera_7->m_triggerMode= ui->triggermode_7->currentText();
    //        emit softmode_7();
    //    });
    //    connect(ui->software_8,&QToolButton::clicked,this,[=](){
    //        camera_8->m_triggerMode= ui->triggermode_8->currentText();
    //        emit softmode_8();
    //    });
    //存图
    connect(ui->saveimage_1, &QRadioButton::toggled, [=](bool isChecked){
        if (isChecked == true){
            camera_1->ifsave=true;

            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera1_save");

        }
        else if (isChecked == false){
            camera_1->ifsave=false;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera1_no_save");
        }
    });
    connect(ui->saveimage_2, &QRadioButton::toggled, [=](bool isChecked){
        if (isChecked == true){
            camera_2->ifsave=true;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera2_save");

        }
        else if (isChecked == false){
            camera_2->ifsave=false;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera2_no_save");
        }
    });

    connect(ui->saveimage_3, &QRadioButton::toggled, [=](bool isChecked){
        if (isChecked == true){
            camera_3->ifsave=true;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera3_save");

        }
        else if (isChecked == false){
            camera_3->ifsave=false;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera3_no_save");
        }
    });
    connect(ui->saveimage_4, &QRadioButton::toggled, [=](bool isChecked){
        if (isChecked == true){
            camera_4->ifsave=true;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera4_save");

        }
        else if (isChecked == false){
            camera_4->ifsave=false;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera4_no_save");
        }
    });
    connect(ui->saveimage_5, &QRadioButton::toggled, [=](bool isChecked){
        if (isChecked == true){
            camera_5->ifsave=true;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera5_save");

        }
        else if (isChecked == false){
            camera_5->ifsave=false;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera5_no_save");
        }
    });


    connect(ui->saveimage_6, &QRadioButton::toggled, [=](bool isChecked){
        if (isChecked == true){
            camera_6->ifsave=true;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera6_save");

        }
        else if (isChecked == false){
            camera_6->ifsave=false;
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera6_no_save");
        }
    });
    //    connect(ui->saveimage_7, &QRadioButton::toggled, [=](bool isChecked){
    //        if (isChecked == true){
    //            camera_7->ifsave=true;
    //            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera7_save");

    //        }
    //        else if (isChecked == false){
    //            camera_7->ifsave=false;
    //            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera7_no_save");
    //        }
    //    });
    //    connect(ui->saveimage_8, &QRadioButton::toggled, [=](bool isChecked){
    //        if (isChecked == true){
    //            camera_8->ifsave=true;
    //            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera8_save");

    //        }
    //        else if (isChecked == false){
    //            camera_8->ifsave=false;
    //            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera8_no_save");
    //        }
    //    });




    //        // GxIAPICPP::gxstring strSN1="FBF23120692";
    //        GxIAPICPP::gxstring strSN1="WL0220030034";
    //        //   GxIAPICPP::gxstring strSN1="FBB23090005";

    //        GxIAPICPP::gxstring strSN6="FBF23120695";
    //        GxIAPICPP::gxstring strSN5="FBF23120690";
    //        GxIAPICPP::gxstring strSN4="FBF23120693";
    //        // GxIAPICPP::gxstring strSN4="WL0220030033";
    //        GxIAPICPP::gxstring strSN2="FBF23120694";
    //        GxIAPICPP::gxstring strSN3="FBF23120691";
    //        GxIAPICPP::gxstring strSN7="FBB23090131";
    //        // GxIAPICPP::gxstring strSN7="WL0220030034";
    //        GxIAPICPP::gxstring strSN8="FBB23090130";
    //        GxIAPICPP::gxstring strSN9="FBF23120693";
    //        camera_1=new VisionDaHengCamera(strSN1,1) ;
    //        camera_2=new VisionDaHengCamera(strSN2,2);
    //        camera_3=new VisionDaHengCamera(strSN3,3);
    //        camera_4=new VisionDaHengCamera(strSN4,4);
    //        camera_5=new VisionDaHengCamera(strSN5,5);
    //        camera_6=new VisionDaHengCamera(strSN6,6);
    //        camera_7=new VisionDaHengCamera(strSN7,7);
    //        camera_8=new VisionDaHengCamera(strSN8,8);
    //        camera_9=new VisionDaHengCamera(strSN9,9);


    bitmap_1=new CGXBitmap2();
    bitmap_2=new CGXBitmap2();
    bitmap_3=new CGXBitmap2();
    bitmap_4=new CGXBitmap2();
    bitmap_5=new CGXBitmap2();
    bitmap_6=new CGXBitmap2();
    bitmap_7=new CGXBitmap2();
    bitmap_8=new CGXBitmap2();
    camerathread_1=new QThread();
    camera_1->moveToThread(camerathread_1);
    connect(camerathread_1, &QThread::finished, camera_1, &QObject::deleteLater);
    camerathread_1->start();
    camerathread_2=new QThread();
    camera_2->moveToThread(camerathread_2);
    connect(camerathread_2, &QThread::finished, camera_2, &QObject::deleteLater);
    camerathread_2->start();
    camerathread_3=new QThread();
    camera_3->moveToThread(camerathread_3);
    connect(camerathread_3, &QThread::finished, camera_3, &QObject::deleteLater);
    camerathread_3->start();
    camerathread_4=new QThread();
    camera_4->moveToThread(camerathread_4);
    connect(camerathread_4, &QThread::finished, camera_4, &QObject::deleteLater);
    camerathread_4->start();
    camerathread_5=new QThread();
    camera_5->moveToThread(camerathread_5);
    connect(camerathread_5, &QThread::finished, camera_5, &QObject::deleteLater);
    camerathread_5->start();
    camerathread_6=new QThread();
    camera_6->moveToThread(camerathread_6);
    connect(camerathread_6, &QThread::finished, camera_6, &QObject::deleteLater);
    camerathread_6->start();
    camerathread_7=new QThread();
    camera_7->moveToThread(camerathread_7);
    connect(camerathread_7, &QThread::finished, camera_7, &QObject::deleteLater);
    camerathread_7->start();
    camerathread_8=new QThread();
    camera_8->moveToThread(camerathread_8);
    connect(camerathread_8, &QThread::finished, camera_8, &QObject::deleteLater);
    camerathread_8->start();


    bitmapthread_1=new QThread();
    bitmap_1->moveToThread(bitmapthread_1);
    connect(bitmapthread_1, &QThread::finished, bitmap_1, &QObject::deleteLater);
    bitmapthread_1->start();
    bitmapthread_2=new QThread();
    bitmap_2->moveToThread(bitmapthread_2);
    connect(bitmapthread_2, &QThread::finished, bitmap_2, &QObject::deleteLater);
    bitmapthread_2->start();
    bitmapthread_3=new QThread();
    bitmap_3->moveToThread(bitmapthread_3);
    connect(bitmapthread_3, &QThread::finished, bitmap_3, &QObject::deleteLater);
    bitmapthread_3->start();
    bitmapthread_4=new QThread();
    bitmap_4->moveToThread(bitmapthread_4);
    connect(bitmapthread_4, &QThread::finished, bitmap_4, &QObject::deleteLater);
    bitmapthread_4->start();
    bitmapthread_5=new QThread();
    bitmap_5->moveToThread(bitmapthread_5);
    connect(bitmapthread_5, &QThread::finished, bitmap_5, &QObject::deleteLater);
    bitmapthread_5->start();
    bitmapthread_6=new QThread();
    bitmap_6->moveToThread(bitmapthread_6);
    connect(bitmapthread_6, &QThread::finished, bitmap_6, &QObject::deleteLater);
    bitmapthread_6->start();

    bitmapthread_8=new QThread();
    bitmap_8->moveToThread(bitmapthread_8);
    connect(bitmapthread_8, &QThread::finished, bitmap_8, &QObject::deleteLater);
    bitmapthread_8->start();
    ui->form_1->num=1;
    chuankou=new ChuanKou;
    client=new Client;
    server=new TcpServer;
    setparameter=new SetParameter;
    detectionresultform=new DetectionResultForm;
    expandform=new ExpandForm;
    findlineform=new FinelineForm;
    settingmeasure=new SettingMeasureForm;
    measure=new VisionMeasure;
    autofocusform=new AutofocusForm;
    motionform=new MotionControlForm;
    measurefuntionthread=new QThread;
    functionn =new MeasureFunction;
    functionn->moveToThread(measurefuntionthread);
    connect(measurefuntionthread, &QThread::finished, functionn, &QObject::deleteLater);
    measurefuntionthread->start();
    qRegisterMetaType<Mat>("Mat");
    qRegisterMetaType<VisionDaHengCamera*>("VisionDaHengCamera &");
    qRegisterMetaType<QQueue<QPixmap>>("QQueue<QPixmap> &");
    qRegisterMetaType<CImageDataPointer>("CImageDataPointer &");
    qRegisterMetaType<vector<double>>("vector<double>");
    //输出串口日志
    connect(chuankou,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    //获取tcp孔位坐标
    connect(client,SIGNAL(senddate(QStringList)),camera_7->measure,SLOT(getdate(QStringList)));
    //输出tcp日志
    connect(client,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    //输出相机日志
    connect(camera_1,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    connect(camera_2,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    connect(camera_3,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    connect(camera_4,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    connect(camera_5,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    connect(camera_6,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    connect(camera_7,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    connect(camera_8,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    connect(camera_9,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));

    connect(camera_1->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
    connect(camera_2->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
    connect(camera_3->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
    connect(camera_4->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
    connect(camera_5->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
    connect(camera_6->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
    connect(camera_7->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
    connect(camera_8->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
     connect(server->measure,SIGNAL(sendlog(QString)),this,SLOT(getLog(QString)));
    // connect(camera_9,SIGNAL(sendLog(QString)),this,SLOT(getLog(QString)));
    //相机操作
    connect(this,SIGNAL(opencamera_1()),camera_1,SLOT(opencamera()));
    connect(this,SIGNAL(opencamera_2()),camera_2,SLOT(opencamera()));
    connect(this,SIGNAL(opencamera_3()),camera_3,SLOT(opencamera()));
    connect(this,SIGNAL(opencamera_4()),camera_4,SLOT(opencamera()));
    connect(this,SIGNAL(opencamera_5()),camera_5,SLOT(opencamera()));
    connect(this,SIGNAL(opencamera_6()),camera_6,SLOT(opencamera()));
    connect(this,SIGNAL(opencamera_7()),camera_7,SLOT(opencamera()));
    connect(this,SIGNAL(opencamera_8()),camera_8,SLOT(opencamera()));
    connect(this,SIGNAL(closecamera_1()),camera_1,SLOT(closecamera()));
    connect(this,SIGNAL(closecamera_2()),camera_2,SLOT(closecamera()));
    connect(this,SIGNAL(closecamera_3()),camera_3,SLOT(closecamera()));
    connect(this,SIGNAL(closecamera_4()),camera_4,SLOT(closecamera()));
    connect(this,SIGNAL(closecamera_5()),camera_5,SLOT(closecamera()));
    connect(this,SIGNAL(closecamera_6()),camera_6,SLOT(closecamera()));
    connect(this,SIGNAL(closecamera_7()),camera_7,SLOT(closecamera()));
    connect(this,SIGNAL(closecamera_8()),camera_8,SLOT(closecamera()));
    connect(this,SIGNAL(startcapture_1()),camera_1,SLOT(startcapture()));
    connect(this,SIGNAL(startcapture_2()),camera_2,SLOT(startcapture()));
    connect(this,SIGNAL(startcapture_3()),camera_3,SLOT(startcapture()));
    connect(this,SIGNAL(startcapture_4()),camera_4,SLOT(startcapture()));
    connect(this,SIGNAL(startcapture_5()),camera_5,SLOT(startcapture()));
    connect(this,SIGNAL(startcapture_6()),camera_6,SLOT(startcapture()));
    connect(this,SIGNAL(startcapture_7()),camera_7,SLOT(startcapture()));
    connect(this,SIGNAL(startcapture_8()),camera_8,SLOT(startcapture()));
    connect(this,SIGNAL(stopcapture_1()),camera_1,SLOT(stopcapture()));
    connect(this,SIGNAL(stopcapture_2()),camera_2,SLOT(stopcapture()));
    connect(this,SIGNAL(stopcapture_3()),camera_3,SLOT(stopcapture()));
    connect(this,SIGNAL(stopcapture_4()),camera_4,SLOT(stopcapture()));
    connect(this,SIGNAL(stopcapture_5()),camera_5,SLOT(stopcapture()));
    connect(this,SIGNAL(stopcapture_6()),camera_6,SLOT(stopcapture()));
    connect(this,SIGNAL(stopcapture_7()),camera_7,SLOT(stopcapture()));
    connect(this,SIGNAL(stopcapture_8()),camera_8,SLOT(stopcapture()));
    connect(this,SIGNAL(softmode_1()),camera_1,SLOT(Software()));
    connect(this,SIGNAL(softmode_2()),camera_2,SLOT(Software()));
    connect(this,SIGNAL(softmode_3()),camera_3,SLOT(Software()));
    connect(this,SIGNAL(softmode_4()),camera_4,SLOT(Software()));
    connect(this,SIGNAL(softmode_5()),camera_5,SLOT(Software()));
    connect(this,SIGNAL(softmode_6()),camera_6,SLOT(Software()));
    connect(this,SIGNAL(softmode_7()),camera_7,SLOT(Software()));
    connect(this,SIGNAL(softmode_8()),camera_8,SLOT(Software()));

    connect(functionn,SIGNAL(softmode_1()),camera_1,SLOT(Software()));
    connect(functionn,SIGNAL(softmode_2()),camera_2,SLOT(Software()));
    connect(functionn,SIGNAL(softmode_3()),camera_3,SLOT(Software()));
    connect(functionn,SIGNAL(softmode_4()),camera_4,SLOT(Software()));
    connect(functionn,SIGNAL(softmode_5()),camera_5,SLOT(Software()));
    connect(functionn,SIGNAL(softmode_6()),camera_6,SLOT(Software()));
    connect(functionn,SIGNAL(softmode_7()),camera_7,SLOT(Software()));
    connect(functionn,SIGNAL(softmode_8()),camera_8,SLOT(Software()));
    //相机帧显示到界面

    //相机帧显示到界面

    connect(camera_1,SIGNAL(sendimage(CImageDataPointer &)),bitmap_1,SLOT(getimage(CImageDataPointer &)));
    connect(bitmap_1,SIGNAL(sendqimage(QImage,QMutex*)),ui->form_1,SLOT(getqimage(QImage,QMutex*)));
    connect(camera_2,SIGNAL(sendimage(CImageDataPointer &)),bitmap_2,SLOT(getimage(CImageDataPointer &)));
    connect(bitmap_2,SIGNAL(sendqimage(QImage,QMutex*)),ui->form_2,SLOT(getqimage(QImage,QMutex*)));
    connect(camera_3,SIGNAL(sendimage(CImageDataPointer &)),bitmap_3,SLOT(getimage(CImageDataPointer &)));
    connect(bitmap_3,SIGNAL(sendqimage(QImage,QMutex*)),ui->form_3,SLOT(getqimage(QImage,QMutex*)));
    connect(camera_4,SIGNAL(sendimage(CImageDataPointer &)),bitmap_4,SLOT(getimage(CImageDataPointer &)));
    connect(bitmap_4,SIGNAL(sendqimage(QImage,QMutex*)),ui->form_4,SLOT(getqimage(QImage,QMutex*)));
    connect(camera_5,SIGNAL(sendimage(CImageDataPointer &)),bitmap_5,SLOT(getimage(CImageDataPointer &)));
    connect(bitmap_5,SIGNAL(sendqimage(QImage,QMutex*)),ui->form_5,SLOT(getqimage(QImage,QMutex*)));
    connect(camera_6,SIGNAL(sendimage(CImageDataPointer &)),bitmap_6,SLOT(getimage(CImageDataPointer &)));
    connect(bitmap_6,SIGNAL(sendqimage(QImage,QMutex*)),ui->form_6,SLOT(getqimage(QImage,QMutex*)));
    connect(camera_7,SIGNAL(sendimage(CImageDataPointer &)),bitmap_7,SLOT(getimage(CImageDataPointer &)));
    connect(bitmap_7,SIGNAL(sendqimage(QImage,QMutex*)),ui->form_7,SLOT(getqimage(QImage,QMutex*)));
    connect(camera_8,SIGNAL(sendimage(CImageDataPointer &)),bitmap_8,SLOT(getimage(CImageDataPointer &)));
    connect(bitmap_8,SIGNAL(sendqimage(QImage,QMutex*)),ui->form_8,SLOT(getqimage(QImage,QMutex*)));
    //显示到放大界面
    connect(bitmap_1,SIGNAL(sendexpandqimage(QImage,QMutex*)),expandform,SLOT(getqimage(QImage,QMutex*)));
    connect(bitmap_2,SIGNAL(sendexpandqimage(QImage,QMutex*)),expandform,SLOT(getqimage(QImage,QMutex*)));
    connect(bitmap_3,SIGNAL(sendexpandqimage(QImage,QMutex*)),expandform,SLOT(getqimage(QImage,QMutex*)));
    connect(bitmap_4,SIGNAL(sendexpandqimage(QImage,QMutex*)),expandform,SLOT(getqimage(QImage,QMutex*)));
    connect(bitmap_5,SIGNAL(sendexpandqimage(QImage,QMutex*)),expandform,SLOT(getqimage(QImage,QMutex*)));
    connect(bitmap_6,SIGNAL(sendexpandqimage(QImage,QMutex*)),expandform,SLOT(getqimage(QImage,QMutex*)));
    connect(bitmap_7,SIGNAL(sendexpandqimage(QImage,QMutex*)),expandform,SLOT(getqimage(QImage,QMutex*)));
    connect(bitmap_8,SIGNAL(sendexpandqimage(QImage,QMutex*)),expandform,SLOT(getqimage(QImage,QMutex*)));
    //单帧采集显示界面
    connect(camera_1,SIGNAL(sendimage(QPixmap)),ui->form_1,SLOT(gettriggerimage(QPixmap)));
    connect(camera_2,SIGNAL(sendimage(QPixmap)),ui->form_2,SLOT(gettriggerimage(QPixmap)));
    connect(camera_3,SIGNAL(sendimage(QPixmap)),ui->form_3,SLOT(gettriggerimage(QPixmap)));
    connect(camera_4,SIGNAL(sendimage(QPixmap)),ui->form_4,SLOT(gettriggerimage(QPixmap)));
    connect(camera_5,SIGNAL(sendimage(QPixmap)),ui->form_5,SLOT(gettriggerimage(QPixmap)));
    connect(camera_6,SIGNAL(sendimage(QPixmap)),ui->form_6,SLOT(gettriggerimage(QPixmap)));
    connect(camera_7,SIGNAL(sendimage(QPixmap)),ui->form_7,SLOT(gettriggerimage(QPixmap)));
    connect(camera_8,SIGNAL(sendimage(QPixmap)),ui->form_8,SLOT(gettriggerimage(QPixmap)));
    //加载图像显示
    connect(this,SIGNAL(sendloadimage_1(Mat)),ui->form_1,SLOT(getimage2(Mat)));
    connect(this,SIGNAL(sendloadimage_2(Mat)),ui->form_2,SLOT(getimage2(Mat)));
    connect(this,SIGNAL(sendloadimage_3(Mat)),ui->form_3,SLOT(getimage2(Mat)));
    connect(this,SIGNAL(sendloadimage_4(Mat)),ui->form_4,SLOT(getimage2(Mat)));
    connect(this,SIGNAL(sendloadimage_5(Mat)),ui->form_5,SLOT(getimage2(Mat)));
    connect(this,SIGNAL(sendloadimage_6(Mat)),ui->form_6,SLOT(getimage2(Mat)));
    connect(this,SIGNAL(sendloadimage_7(Mat)),ui->form_7,SLOT(getimage2(Mat)));
    connect(this,SIGNAL(sendloadimage_8(Mat)),ui->form_8,SLOT(getimage2(Mat)));
    //灯光控制
    connect(this,SIGNAL(openlight(int)),chuankou,SLOT(openlight(int)));
    connect(chuankou,SIGNAL(sendlightchange(QString,int)),this,SLOT(getlightsituation(QString,int)));
    //tcp通信
    connect(client,SIGNAL(instruction(QString)),functionn,SLOT(GetInstruction(QString)));
    //tcp返回数据clent
    connect(camera_1->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));
    connect(camera_2->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));
    connect(camera_3->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));
    connect(camera_4->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));
    connect(camera_5->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));
    connect(camera_6->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));
    connect(camera_7->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));
    connect(camera_8->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));

    connect(server->measure,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));


    connect(camera_1->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_1,SLOT(getresult(Mat,vector<double>)));
    connect(camera_2->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_2,SLOT(getresult(Mat,vector<double>)));
    connect(camera_3->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_3,SLOT(getresult(Mat,vector<double>)));
    connect(camera_4->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_4,SLOT(getresult(Mat,vector<double>)));
    connect(camera_5->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_5,SLOT(getresult(Mat,vector<double>)));
    connect(camera_6->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_6,SLOT(getresult(Mat,vector<double>)));
    connect(camera_7->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_7,SLOT(getresult(Mat,vector<double>)));
    connect(camera_8->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_8,SLOT(getresult(Mat,vector<double>)));
      connect(server->measure,SIGNAL(sendresult(Mat,vector<double>)),ui->form_9,SLOT(getresult(Mat,vector<double>)));

    connect(camera_1->measure,SIGNAL(sendresult_to_form7(Mat,vector<double>)),ui->form_7,SLOT(getresult(Mat,vector<double>)));
    connect(camera_2->measure,SIGNAL(sendresult_to_form8(Mat,vector<double>)),ui->form_8,SLOT(getresult(Mat,vector<double>)));
    //视觉界面与主界面
    connect(camera_1->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));
    connect(camera_2->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));
    connect(camera_3->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));
    connect(camera_4->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));
    connect(camera_5->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));
    connect(camera_6->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));
    connect(camera_7->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));
    connect(camera_8->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));

     connect(server->measure,SIGNAL(informationwrite(int, bool)),detectionresultform,SLOT(informationwrite(int, bool)));
    //QA结果显示
    //算法界面获取相机图像
    connect(settingmeasure,SIGNAL(sendupdateimage(int )),this,SLOT(updatesettingmeasure(int)));
    //视觉界面获取创造模板信息
    //connect(settingmeasure->measure,SIGNAL(createmodellog(int)),settingmeasure,SLOT(getcreatemodellog(int)));
    connect(camera_1,SIGNAL(saveimage(CImageDataPointer &,string)),this,SLOT(saveimage(CImageDataPointer &,string)));

    //开启相机图标
    connect(camera_1,SIGNAL(ifopencamera(int,int)),this,SLOT(ifopencamera(int,int)));
    connect(camera_2,SIGNAL(ifopencamera(int,int)),this,SLOT(ifopencamera(int,int)));
    connect(camera_3,SIGNAL(ifopencamera(int,int)),this,SLOT(ifopencamera(int,int)));
    connect(camera_4,SIGNAL(ifopencamera(int,int)),this,SLOT(ifopencamera(int,int)));
    connect(camera_5,SIGNAL(ifopencamera(int,int)),this,SLOT(ifopencamera(int,int)));
    connect(camera_6,SIGNAL(ifopencamera(int,int)),this,SLOT(ifopencamera(int,int)));
    connect(camera_7,SIGNAL(ifopencamera(int,int)),this,SLOT(ifopencamera(int,int)));
    connect(camera_8,SIGNAL(ifopencamera(int,int)),this,SLOT(ifopencamera(int,int)));
    connect(cominfo,SIGNAL(sendinfo(QString)),this,SLOT(getcomputerinfo(QString)));

    connect(functionn,SIGNAL(cam6act2()),this,SLOT(getcam6act2()));

    connect(server,SIGNAL(sendclientresult(QString,QByteArray,bool )),client,SLOT(getresult(QString,QByteArray,bool)));




    //点击放大界面
    connect(ui->pushButton_FPS_1,&QPushButton::clicked,this,[&](){
        if((bitmap_1->ifexpand==false)&&(expand==false)){
            bitmap_1->ifexpand=true;
            expand=true;
            ui->pushButton_FPS_1->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(255, 0, 0);");
            expandform->show();
        }else if((bitmap_1->ifexpand==false)&&(expand==true)){
            QMessageBox::warning(this,tr("警告信息"),tr("请关闭已经打开的放大界面..."));

        }else{
            bitmap_1->ifexpand=false;
            expand=false;
            ui->pushButton_FPS_1->setStyleSheet("background-color: rgb(0,170,255);color: rgb(255, 255, 255);");
            expandform->close();
        }

    });
    connect(ui->pushButton_FPS_2,&QPushButton::clicked,this,[&](){
        if((bitmap_2->ifexpand==false)&&(expand==false)){
            bitmap_2->ifexpand=true;
            expand=true;
            ui->pushButton_FPS_2->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(255, 0, 0);");
            expandform->show();
        }else if((bitmap_2->ifexpand==false)&&(expand==true)){
            QMessageBox::warning(this,tr("警告信息"),tr("请关闭以打开的放大窗口!"));

        }else{
            bitmap_2->ifexpand=false;
            expand=false;
            ui->pushButton_FPS_2->setStyleSheet("background-color: rgb(0,170,255);color: rgb(255, 255, 255);");
            expandform->close();
        }


    });
    connect(ui->pushButton_FPS_3,&QPushButton::clicked,this,[&](){
        if((bitmap_3->ifexpand==false)&&(expand==false)){
            bitmap_3->ifexpand=true;
            expand=true;
            ui->pushButton_FPS_3->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(255, 0, 0);");
            expandform->show();
        }else if((bitmap_3->ifexpand==false)&&(expand==true)){
            QMessageBox::warning(this,tr("警告信息"),tr("请关闭以打开的放大窗口!"));

        }else{
            bitmap_3->ifexpand=false;
            expand=false;
            ui->pushButton_FPS_3->setStyleSheet("background-color: rgb(0,170,255);color: rgb(255, 255, 255);");
            expandform->close();
        }


    });
    connect(ui->pushButton_FPS_4,&QPushButton::clicked,this,[&](){
        if((bitmap_4->ifexpand==false)&&(expand==false)){
            bitmap_4->ifexpand=true;
            expand=true;
            ui->pushButton_FPS_4->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(255, 0, 0);");
            expandform->show();
        }else if((bitmap_4->ifexpand==false)&&(expand==true)){
            QMessageBox::warning(this,tr("警告信息"),tr("请关闭以打开的放大窗口!"));

        }else{
            bitmap_4->ifexpand=false;
            expand=false;
            ui->pushButton_FPS_4->setStyleSheet("background-color: rgb(0,170,255);color: rgb(255, 255, 255);");
            expandform->close();
        }


    });
    connect(ui->pushButton_FPS_5,&QPushButton::clicked,this,[&](){
        if((bitmap_5->ifexpand==false)&&(expand==false)){
            bitmap_5->ifexpand=true;
            expand=true;
            ui->pushButton_FPS_5->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(255, 0, 0);");
            expandform->show();
        }else if((bitmap_5->ifexpand==false)&&(expand==true)){
            QMessageBox::warning(this,tr("警告信息"),tr("请关闭以打开的放大窗口!"));

        }else{
            bitmap_5->ifexpand=false;
            expand=false;
            ui->pushButton_FPS_5->setStyleSheet("background-color: rgb(0,170,255);color: rgb(255, 255, 255);");
            expandform->close();
        }


    });

    connect(ui->pushButton_FPS_6,&QPushButton::clicked,this,[&](){
        if((bitmap_6->ifexpand==false)&&(expand==false)){
            bitmap_6->ifexpand=true;
            expand=true;
            ui->pushButton_FPS_6->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(255, 0, 0);");
            expandform->show();
        }else if((bitmap_6->ifexpand==false)&&(expand==true)){
            QMessageBox::warning(this,tr("警告信息"),tr("请关闭以打开的放大窗口!"));

        }else{
            bitmap_6->ifexpand=false;
            expand=false;
            ui->pushButton_FPS_6->setStyleSheet("background-color: rgb(0,170,255);color: rgb(255, 255, 255);");
            expandform->close();
        }


    });
    //    connect(ui->pushButton_FPS_7,&QPushButton::clicked,this,[&](){
    //        if((bitmap_7->ifexpand==false)&&(expand==false)){
    //            bitmap_7->ifexpand=true;
    //            expand=true;
    //            ui->pushButton_FPS_7->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(255, 0, 0);");
    //            expandform->show();
    //        }else if((bitmap_7->ifexpand==false)&&(expand==true)){
    //            QMessageBox::warning(this,tr("警告信息"),tr("请关闭以打开的放大窗口!"));

    //        }else{
    //            bitmap_7->ifexpand=false;
    //            expand=false;
    //            ui->pushButton_FPS_7->setStyleSheet("background-color: rgb(0,170,255);color: rgb(255, 255, 255);");
    //            expandform->close();
    //        }


    //    });
    //    connect(ui->pushButton_FPS_8,&QPushButton::clicked,this,[&](){
    //        if((bitmap_8->ifexpand==false)&&(expand==false)){
    //            bitmap_8->ifexpand=true;
    //            expand=true;
    //            ui->pushButton_FPS_8->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(255, 0, 0);");
    //            expandform->show();
    //        }else if((bitmap_8->ifexpand==false)&&(expand==true)){
    //            QMessageBox::warning(this,tr("警告信息"),tr("请关闭以打开的放大窗口!"));

    //        }else{
    //            bitmap_8->ifexpand=false;
    //            expand=false;
    //            ui->pushButton_FPS_8->setStyleSheet("background-color: rgb(0,170,255);color: rgb(255, 255, 255);");
    //            expandform->close();
    //        }


    //    });
}


void VisionMainWindow::on_motioncontrol_clicked()
{

    motionform->show();
}

void VisionMainWindow::on_autofocus_clicked()
{
    autofocusform->show();
}

void VisionMainWindow::getcam6act2()
{

    server->on_pushButton_send_clicked();
}

void VisionMainWindow::on_triggermode_5_currentIndexChanged(int index)
{
   ui->form_5->drawrect_id=index;
}
