#include "measurefunction.h"
extern VisionDaHengCamera *camera_1;
extern VisionDaHengCamera *camera_2;
extern VisionDaHengCamera *camera_3;
extern VisionDaHengCamera *camera_4;
extern VisionDaHengCamera *camera_5;
extern VisionDaHengCamera *camera_6;

extern axis *axis_1;//轴
extern axis *axis_2;
extern AxisUiData Axis_UI_Data;
extern DEVICESTATE Ax_State;


MeasureFunction::MeasureFunction()
{
    AxisRel_camera_1=Axis_UI_Data.AxisRel_1;
     AxisRel_camera_2=Axis_UI_Data.AxisRel_2;
    DEVICE = new axismotion();

    AxisWorkOne = new axisThreadOne();
    AxisThreadOne = new QThread();
    AxisWorkOne ->moveToThread(AxisThreadOne);
    connect(AxisThreadOne, &QThread::finished, AxisWorkOne, &QObject::deleteLater);
    AxisThreadOne ->start();

    AxisWorkTwo = new axisThreadTwo();
    AxisThreadTwo = new QThread();
    AxisWorkTwo ->moveToThread(AxisThreadTwo);
    connect(AxisThreadTwo, &QThread::finished, AxisWorkTwo, &QObject::deleteLater);
    AxisThreadTwo ->start();

    AxisWorkThree = new axisThreadThree();
    AxisThreadThree = new QThread();
    AxisWorkThree ->moveToThread(AxisThreadThree);
    connect(AxisThreadThree, &QThread::finished, AxisWorkThree, &QObject::deleteLater);
    AxisThreadThree ->start();

    autothread_1=new AutofocusThread(0);
    autothread_2=new AutofocusThread(0);

    connect(this, SIGNAL(sigAxisMoveRelPT(int ,double ,double ,double )), AxisWorkOne, SLOT(slotAxisMoveRelPT(int ,double ,double ,double )));
    connect(this, SIGNAL(sigAxisMoveAbsPT(int ,double ,double ,double )), AxisWorkOne, SLOT(slotAxisMoveAbsPT(int ,double ,double ,double )));
    connect(this, SIGNAL(sigstartmove(int, axis *)), AxisWorkTwo, SLOT(slot_getDistanceTime(int, axis *)));
    //自动对焦收集
    connect(camera_1,SIGNAL(sendautoimage(QDateTime,CImageDataPointer & )),autothread_1,SLOT(getautodate(QDateTime ,CImageDataPointer &)));
    connect(camera_2,SIGNAL(sendautoimage(QDateTime,CImageDataPointer & )),autothread_2,SLOT(getautodate(QDateTime ,CImageDataPointer &)));
    //connect(camera_2,SIGNAL(sendautoimage(QDateTime,CImageDataPointer & )),this->autothread2,SLOT(getautodate(QDateTime ,CImageDataPointer &)));
    //获取流中的一帧图像
     connect(camera_1,SIGNAL(sendoneimage(CImageDataPointer&)),this,SLOT(getoneimage(CImageDataPointer&)));
     //图像检测
     // connect(this,SIGNAL(sendoneimage(CImageDataPointer&)),this,SLOT(getoneimage(CImageDataPointer&)));
}

void MeasureFunction::Camera1ACT2()
{

}

void MeasureFunction::GetInstruction(QString name)
{
      // cout<<"start:::"<<QDateTime::currentDateTime().toString("hh:mm:ss:zzz").toStdString()<<endl;
    // cout<<QThread::currentThreadId()<<endl;
    //AutoFocus();
    //cout<<"MAINCAM1ACT1"<<name.toStdString() <<endl;
    if(name=="CAM1ACT1"){
       cout<<"MAINCAM1ACT1" <<endl;
       camera_1->TriggerSoftware_clicked();

    }else if(name=="CAM2ACT1"){
        // cout<<"MAINCAM2ACT1" <<endl;
        camera_2->TriggerSoftware_clicked();


    }else if(name=="CAM3ACT1"){
        // cout<<"MAINCAM3ACT1" <<endl;
        camera_3->TriggerSoftware_clicked();


    }else if(name=="CAM4ACT1"){
        // cout<<"MAINCAM4ACT1" <<endl;
        camera_4->TriggerSoftware_clicked();


    }else if(name=="CAM5ACT1"){
        // cout<<"MAINCAM5ACT1" <<endl;
        camera_5->TriggerSoftware_clicked();


    }else if(name=="CAM6ACT1"){
        // cout<<"MAINCAM6ACT1" <<endl;
        camera_6->TriggerSoftware_clicked();


    }else if(name=="CAM1ACT2"){
        //cout<<"MAINCAM1ACT2" <<endl;
        //  void AutoFocus(VisionDaHengCamera *camera,AutofocusThread *autothread,axis *axis,AxisRelData AxisRel,int axis_num,double upmovedistance,double upmovetime,double downmovedistance,double downmovetime,double endmovetime);
        autothread_1->biaoji=DateVar::autofocusfunction_1;
        autothread_1->getautofocusroirect(Rect(DateVar::autofocusroi_1_start_x,DateVar::autofocusroi_1_start_y,DateVar::autofocusroi_1_width,DateVar::autofocusroi_1_height));
        AutoFocus(camera_1,autothread_1,axis_1,AxisRel_camera_1,0,-DateVar::autofocusupdistance_1,DateVar::autofocusuptime_1,DateVar::autofocusdowndistance_1,DateVar::autofocusdowntime_1,DateVar::autofocusreturntime_1,1);
        //AutoFocus(camera_1,autothread_1,axis_1,AxisRel_camera_1,0,-0.5,2,1,2,0.3);

    }else if(name=="CAM2ACT2"){
        // cout<<"MAINCAM2ACT2" <<endl;
        autothread_2->biaoji=DateVar::autofocusfunction_2;
        autothread_2->getautofocusroirect(Rect(DateVar::autofocusroi_2_start_x,DateVar::autofocusroi_2_start_y,DateVar::autofocusroi_2_width,DateVar::autofocusroi_2_height));
        AutoFocus(camera_2,autothread_2,axis_2,AxisRel_camera_2,1,-DateVar::autofocusupdistance_2,DateVar::autofocusuptime_2,DateVar::autofocusdowndistance_2,DateVar::autofocusdowntime_2,DateVar::autofocusreturntime_2,2);


    }else if(name=="CAM3ACT2"){
        // cout<<"MAINCAM3ACT2" <<endl;

        //ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_3 start");
        camera_3->ifmeasure=3;
        camera_3->camearmeasurenum=3;
        emit softmode_3();




    }else if(name=="CAM4ACT2"){
        //  cout<<"MAINCAM4ACT2" <<endl;
        camera_4->ifmeasure=4;
         camera_4->camearmeasurenum=4;
        emit softmode_4();

    }else if(name=="CAM5ACT2"){
        //  cout<<"MAINCAM5ACT2" <<endl;
        camera_5->camearmeasurenum=55;
        camera_5->ifmeasure=5;
        emit softmode_5();

    }else if(name=="CAM6ACT2"){
        //  cout<<"MAINCAM6ACT2" <<endl;
      // server->on_pushButton_send_clicked();
        emit cam6act2();

    }else if(name=="CAM3ACT3"){
        //  cout<<"MAINCAM6ACT2" <<endl;
        cout<<"bbbbb"<<endl;
        camera_3->ifmeasure=3;
         camera_3->camearmeasurenum=33;
        emit softmode_3();

    }else if(name=="CAM4ACT3"){
        //  cout<<"MAINCAM6ACT2" <<endl;
        camera_4->ifmeasure=4;
        camera_4->camearmeasurenum=44;
        emit softmode_4();

    }else if(name=="CAM5ACT3"){
        //  cout<<"MAINCAM6ACT2" <<endl;
         camera_5->camearmeasurenum=55;
        camera_5->ifmeasure=55 ;
        emit softmode_5();

    }

}

void MeasureFunction::getoneimage(CImageDataPointer &objImageDataPointer)
{
    DateVar::automutex_1.lock();
    DateVar::autowaitcondition_1.wakeOne();
    void* pRGB24Buffer = objImageDataPointer->ConvertToRaw8(GX_BIT_0_7);
    image = cv::Mat::zeros(cv::Size(objImageDataPointer->GetWidth(), objImageDataPointer->GetHeight()), CV_8UC1);
    memcpy(image.data, pRGB24Buffer, objImageDataPointer->GetWidth() *  objImageDataPointer->GetHeight());
    DateVar::automutex_1.unlock();
}


void MeasureFunction::AutoFocus(VisionDaHengCamera *camera,AutofocusThread *autothread,axis *Axis,AxisRelData AxisRel,int axis_num,double upmovedistance,double upmovetime,double downmovedistance,double downmovetime,double endmovetime,int measurenum)
{
    cout<<"aaaaaaaaaaaaaaa"<<endl;
    if(!camera->isOpenStream){
        cout<<"camera no start capture image"<<endl;
        return;

    }

        try {
            if(!Axis->get_isrange(Axis->get_actual_value(AxisRel.AxisCmdPos)))
            {
                //     qDebug()<<"超量程";
                return;
            }
            if(axis_num==0){

                   emit sigAxisMoveAbsPT(axis_num,2000000,Axis->get_code_value(DateVar::autofocusstartposition_1),0.2);
            }else if(axis_num==1){
                 emit sigAxisMoveAbsPT(axis_num,2000000,Axis->get_code_value(DateVar::autofocusstartposition_2),0.2);
            }

        } catch (...) {

        }
    Sleep(250);

    cout<<"bbbbbbbbbb"<<endl;
    autothread->Autofocus_time.clear();
    autothread->Autofocus_image_definition.clear();
    AxisWorkTwo->position.clear();
    AxisWorkTwo->time.clear();
    camera->autofocus=true;
    autothread->start();

    cout<<"cccccccccccc"<<endl;
    //先向上走
    try {
        if(!Axis->get_isrange(Axis->get_actual_value(AxisRel.AxisCmdPos)+0.5))
        {
            //qDebug()<<"超量程";
            return;
        }
        emit sigAxisMoveRelPT(axis_num,2000000,Axis->get_code_value(upmovedistance),upmovetime);
        emit sigstartmove(axis_num,Axis);
    } catch (...) {

    }

    cout<<"ddddddddddd"<<endl;
    //向下走
    DateVar::automutex_1.lock();
    DateVar::autowaitcondition_1.wait(&DateVar::automutex_1);
    try {
        if(!Axis->get_isrange(Axis->get_actual_value(AxisRel.AxisCmdPos)+0.5))
        {
            //qDebug()<<"超量程";
            return;
        }
        emit sigAxisMoveRelPT(axis_num,2000000,Axis->get_code_value(downmovedistance),downmovetime);
        emit sigstartmove(axis_num,Axis);
    } catch (...) {

    }

    cout<<"eeeeeeeeeee"<<endl;
    DateVar::automutex_1.unlock();
    //回到清晰的位置
    DateVar::automutex_1.lock();
    DateVar::autowaitcondition_1.wait(&DateVar::automutex_1);
    autothread->autorun=false;
    camera->autofocus=false;

    cout<<"ffffffffffff"<<endl;
    double position_=maxqingxidu(autothread);

    cout<<"ggggggggggggg"<<endl;
    try {
        if(!Axis->get_isrange(Axis->get_actual_value(AxisRel.AxisCmdPos)))
        {
            //     qDebug()<<"超量程";
            return;
        }
        emit sigAxisMoveAbsPT(axis_num,2000000,Axis->get_code_value(AxisWorkTwo->position[position_]),endmovetime);
        emit sigstartmove(axis_num,Axis);
    } catch (...) {

    }

    cout<<"hhhhhhhhhhhhhh"<<endl;
    DateVar::automutex_1.unlock();
//    //获取图像
    DateVar::automutex_1.lock();
    DateVar::autowaitcondition_1.wait(&DateVar::automutex_1);
     cout<<"ooooooo"<<endl;
    camera->getoneimage=true;
     cout<<"mmmmm"<<endl;
    camera->camearmeasurenum=measurenum;
     cout<<"llllll"<<endl;
    DateVar::automutex_1.unlock();
    //回到初始位置

    cout<<"kkkkkkkkkkkkkk"<<endl;
//    DateVar::automutex_1.lock();
//    DateVar::autowaitcondition_1.wait(&DateVar::automutex_1);
//    try {
//        if(!Axis->get_isrange(Axis->get_actual_value(AxisRel.AxisCmdPos)))
//        {
//            //     qDebug()<<"超量程";
//            return;
//        }
//        if(axis_num==0){

//               emit sigAxisMoveAbsPT(axis_num,2000000,Axis->get_code_value(DateVar::autofocusstartposition_1),0.3);
//        }else if(axis_num==1){
//             emit sigAxisMoveAbsPT(axis_num,2000000,Axis->get_code_value(DateVar::autofocusstartposition_2),0.3);
//        }

//    } catch (...) {

//    }
//      DateVar::automutex_1.unlock();



}

double MeasureFunction::maxqingxidu(AutofocusThread *autothread)
{
    //最大值：

    int maxPosition=0;
    double maxthreeValue=0;
    cout<<"*****************************"<<endl;
 cout<<"22222222"<<endl;
    if(autothread->Autofocus_image_definition.size()>autothread->Autofocus_time.size()){
        int i=abs(autothread->Autofocus_image_definition.size()-autothread->Autofocus_time.size());

        while(i>0){

            autothread->Autofocus_image_definition.pop_back();
            i--;
        }
    }else if(autothread->Autofocus_image_definition.size()<autothread->Autofocus_time.size()){
        int i=abs(autothread->Autofocus_time.size()-autothread->Autofocus_image_definition.size());

        while(i>0){

            autothread->Autofocus_time.pop_back();
            i--;
        }
    }
    cout<<"size:"<<autothread->Autofocus_image_definition.size()<<endl;
    cout<<"size:"<<autothread->Autofocus_time.size()<<endl;
    cout<<"size:"<<AxisWorkTwo->time.size()<<endl;
    cout<<"size:"<<AxisWorkTwo->position.size()<<endl;

    for(int i=0;i<autothread->Autofocus_image_definition.size();i++){
        //cout<<i+1<<" "<<"Autofocus_image_definition:"<<autothread->Autofocus_image_definition[i]<<"  time:"<<autothread->Autofocus_time[i].toString("HH:mm:ss:zzz").toStdString()<<endl;

    }

    for(int i=0;i<AxisWorkTwo->time.size();i++){
       // cout<<"position:"<<AxisWorkTwo->position[i]<<"  time:"<<AxisWorkTwo->time[i].toString("HH:mm:ss:zzz").toStdString()<<endl;

    }
 cout<<"3333333"<<endl;
    for(int i=1;i<autothread->Autofocus_image_definition.size()-1;i++){
        if((autothread->Autofocus_image_definition[i-1]+autothread->Autofocus_image_definition[i]+autothread->Autofocus_image_definition[i+1])/3>maxthreeValue){
            maxthreeValue=(autothread->Autofocus_image_definition[i-1]+autothread->Autofocus_image_definition[i]+autothread->Autofocus_image_definition[i+1])/3;
            maxPosition=i;
        }

    }

   cout<<"maxPosition:"<<maxPosition<<endl;
 cout<<"444444"<<endl;
    double maxValue=autothread->Autofocus_image_definition[maxPosition];
    //cout<<"maxthreeValue:"<<maxValue<<endl;
    /*double maxValue = *max_element(autothread->Autofocus_image_definition.begin(),  autothread->Autofocus_image_definition.end());
    cout<<"55555555555555"<<endl;
   // 最大值下标索引：

int maxPosition = max_element(autothread->Autofocus_image_definition.begin(),  autothread->Autofocus_image_definition.end()) -autothread->Autofocus_image_definition.begin();*/
    // ui->Log->append("最大值:"+QString::number(maxValue,10,6)+"最大值索引"+QString::number(maxPosition,10,6));
     cout<<"55555555555555"<<endl;
    double time_min=100;
    int position_=0;
    for(int i=0;i<AxisWorkTwo->time.size();i++){
        if(abs(autothread->Autofocus_time[maxPosition].msecsTo(AxisWorkTwo->time[i]))<time_min){
            time_min=abs(autothread->Autofocus_time[maxPosition].msecsTo(AxisWorkTwo->time[i]));
            position_=i;

            //  biaozhi=i;
        }

    }
 cout<<"66666666666"<<endl;

    // cout<<"maxposition:"<<AxisWorkTwo->position[position_]<<endl;
    DateVar::autofocusscore=maxthreeValue;
    DateVar::autofocusposition=AxisWorkTwo->position[position_];
 cout<<"777777"<<endl;
    return position_;
    // ui->Log->append("清晰最好的位置"+QString::number(AxisWorkTwo->position[position_],10,6));
}

