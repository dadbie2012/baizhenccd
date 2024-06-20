#include "visiondahengcamera.h"
#pragma execution_character_set("utf-8")

VisionDaHengCamera::VisionDaHengCamera(GxIAPICPP::gxstring strSN_,int num)
{
    count=0;
    zhenlv_count=0;
    autufocus=false;
    Num=num;
    ifsaveimage=0;
    isOpenCam = false;
    isOpenStream = false;
    isopenstream_=false;
    isOffline = false;
    isTrigger = false;
    exposeTime = 20000;
    m_hDeviceOffline = NULL;
    pCaptureEventHandler;
    m_firmName = "";
    m_modelName = "";
    m_serialNumName = "";
    m_ipName = "";
    m_maskName = "";
    m_macName = "";
    m_width = 0;
    m_height = 0;
    m_bitDepth = "";
    m_triggerMode = "";
    m_triggerSource = "Software";
    software=true;
    Autofocus_status=false;
    ifmeasure=0;
    ifsave=false;
    ExposureTime=20000;
    counttest=0;
    strSN=strSN_;
    measure=new VisionMeasure;
    pDeviceOfflineEventHandler=NULL;
    //初始化库
    try
    {
        IGXFactory::GetInstance().Init();//GxIAPICPPEx库在使用之前必须执行初始化
    }
    catch (CGalaxyException& e)
    {
        qDebug()<< "初始化错误码: " << e.GetErrorCode();
        qDebug()<< "初始化错误描述信息: " << e.what();
    }



}

VisionDaHengCamera::~VisionDaHengCamera()
{
    if (pCaptureEventHandler != NULL)
    {
        delete pCaptureEventHandler;
        pCaptureEventHandler = NULL;
    }
    if (pDeviceOfflineEventHandler != NULL)
    {
        delete pDeviceOfflineEventHandler;
        pDeviceOfflineEventHandler = NULL;
    }
    delete timer;
    timer=NULL;
}


// 用户继承掉线事件处理类
class CSampleDeviceOfflineEventHandler : public IDeviceOfflineEventHandler
{
public :
    void DoOnDeviceOfflineEvent(void* pUserParam)
    {
        qDebug()<<"DEVICE OFFLINE!";

    }
};

void VisionDaHengCamera::openDevice_clicked()
{
    //cout<<QThread::currentThreadId()<<endl;

    try
    {
        if (!isOpenCam)
        {
            //初始化
            IGXFactory::GetInstance().Init();
            //枚举设备
            gxdeviceinfo_vector vectorDeviceInfo;
            IGXFactory::GetInstance().UpdateDeviceList(1000, vectorDeviceInfo);

            //            if (0 == vectorDeviceInfo.size())
            //            {


            //                emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Camera failure connected--serial number:"+ QString::number(this->Num)+"</font>");

            //                return;
            //            }
            //打开设备
            m_objDevicePtr = IGXFactory::GetInstance().OpenDeviceBySN(strSN, GX_ACCESS_EXCLUSIVE);
            isOpenCam = true;
            //获取属性控制器
            m_objRemoteFeatureControlPtr = m_objDevicePtr->GetRemoteFeatureControl();
            //设置采集模式为连续采集
            // m_objFeatureControlPtr->GetEnumFeature("AcquisitionMode")->SetValue("Continuous");
            //设置触发模式为关
            m_objFeatureControlPtr = m_objDevicePtr->GetRemoteFeatureControl();
            m_objFeatureControlPtr->GetEnumFeature("TriggerMode")->SetValue("Off");
            m_objFeatureControlPtr = m_objDevicePtr->GetFeatureControl();
            CImageProcessConfigPointer objImageProcessConfigPtr =  m_objDevicePtr->CreateImageProcessConfig();
            // cout<<"33333"<<endl;
            //采集模式
            m_objRemoteFeatureControlPtr->GetEnumFeature("AcquisitionMode")->SetValue("Continuous");
            //触发模式
            // m_objRemoteFeatureControlPtr->GetEnumFeature("TriggerSelector")->SetValue("FrameStart");
            m_objRemoteFeatureControlPtr->GetEnumFeature("TriggerMode")->SetValue("Off");

            if(this->Num==2){

                m_objRemoteFeatureControlPtr->GetBoolFeature("GammaEnable")->SetValue(true);
                m_objRemoteFeatureControlPtr->GetEnumFeature("GammaMode")->SetValue("User");
                m_objRemoteFeatureControlPtr->GetFloatFeature("Gamma")->SetValue(4.000);
                cout<<"bbb:"<<objImageProcessConfigPtr->GetGammaParam()<<endl;
            }
            m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(ExposureTime);
            // 设备信息获取
            m_deviceInfo = m_objDevicePtr->GetDeviceInfo();
            m_firmName = m_deviceInfo.GetVendorName();
            m_modelName = m_deviceInfo.GetModelName();
            m_serialNumName = m_deviceInfo.GetSN();
            m_ipName = m_deviceInfo.GetIP();
            m_maskName = m_deviceInfo.GetSubnetMask();
            m_macName = m_deviceInfo.GetMAC();
            m_width = m_objRemoteFeatureControlPtr->GetIntFeature("Width")->GetValue();
            m_height = m_objRemoteFeatureControlPtr->GetIntFeature("Height")->GetValue();
            m_bitDepth = m_objRemoteFeatureControlPtr->GetEnumFeature("PixelSize")->GetValue();
            qDebug()<<"Camera successfully connected--serial number:"+ QString::number(this->Num);
            emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">Camera successfully connected--serial number:"+ QString::number(this->Num)+"</font>");
            emit sendLog("Camera Name:"+m_firmName);
            emit sendLog("Camera IP:"+m_ipName);
            emit sendLog("Image width:"+QString::number(m_width, 10));
            emit sendLog("Image length:"+QString::number(m_height, 10));
            emit sendLog("serialNumName:"+m_serialNumName);


#ifdef _DEBUG
            //设置心跳超时时间 6s
            m_objRemoteFeatureControlPtr->GetIntFeature("GevHeartbeatTimeout")->SetValue(6000);
#endif
            //设备初始设置
            objDeviceClass = m_objDevicePtr->GetDeviceInfo().GetDeviceClass();
            if (objDeviceClass == GX_DEVICE_CLASS_GEV)
            {
                // ui->log->append("开始采集图像-3--"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                //提高网络相机的采集性
                if (true == m_objFeatureControlPtr->IsImplemented("GevSCPSPacketSize"))		//判断设备是否支持流通道数据包功能
                {
                    //获取当前网络环境的最优包长值
                    int nPacketSize = m_objStreamPtr->GetOptimalPacketSize();
                    //将最优包长值设置为当前设备的流通道包长值
                    m_objRemoteFeatureControlPtr->GetIntFeature("GevSCPSPacketSize")->SetValue(nPacketSize);
                }
                //注册掉线事件
                pDeviceOfflineEventHandler=new CSampleDeviceOfflineEventHandler();
                m_hDeviceOffline = m_objDevicePtr->RegisterDeviceOfflineCallback(pDeviceOfflineEventHandler,this);
            }

            __IsSupportColor(m_objDevicePtr, color);
            emit ifopencamera(this->Num,1);

        }
    }
    catch (CGalaxyException& e)
    {
        cout << "开启相机错误码: " << e.GetErrorCode() << endl;
        cout << "开启相机错误描述信息: " << e.what() << endl;
        qDebug()<<"开启相机错误码: " << e.GetErrorCode();
       qDebug()<< "开启相机错误描述信息: " << e.what();
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Camera Open Failed--serial number:"+ QString::number(this->Num)+"</font>");
    }
    catch (std::exception& e)
    {
        cout << "开启相机错误描述信息: " << e.what() << endl;
        qDebug()<< "开启相机错误描述信息: " << e.what();
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Camera Open Failed--serial number:"+ QString::number(this->Num)+"</font>");
    }
}
void VisionDaHengCamera::closeDevice_clicked()
{
    if(!isOpenCam){
        return;
    }
    try {

        if (isOpenCam)
        {

            if (isOpenStream)
            {

                //发送停采命令
                m_objRemoteFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
                m_objStreamPtr->StopGrab();
                m_objStreamPtr->UnregisterCaptureCallback();//注销采集回调

            }
            if (objDeviceClass == GX_DEVICE_CLASS_GEV)
            {
                m_objDevicePtr->UnregisterDeviceOfflineCallback(m_hDeviceOffline);
            }

            isOpenStream = false;


            // IGXFactory::GetInstance().Uninit(); //释放GxIAPICPPEx申请的所有资源
            isOpenCam = false;

        }
    }  catch (exception& e) {
        cout << "abcdef" << e.what() << endl;
    }
    catch (CGalaxyException& e)
    {
        cout << "开启相机错误码: " << e.GetErrorCode() << endl;
        cout << "开启相机错误描述信息: " << e.what() << endl;
        //emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+":opencamerafault");
    }
    try
    {
        //关闭流对象
        m_objStreamPtr->Close();
    }
    catch (CGalaxyException)
    {
        //do noting
    }

    try
    {
        //关闭设备
        m_objDevicePtr->Close();
    }
    catch (CGalaxyException)
    {
        //do noting
    }
    emit ifopencamera(this->Num,0);
    emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Camera Closed--serial number:"+ QString::number(this->Num));
}



void VisionDaHengCamera::startCapture_clicked()
{   ///<采集回调对象
    try {



        if (isOpenCam)
        {
            emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Start Capture--serial number:"+ QString::number(this->Num));
            uint32_t nStreamNum = m_objDevicePtr->GetStreamCount();


            if ((nStreamNum > 0) && (!isOpenStream))
            {
                m_objStreamPtr = m_objDevicePtr->OpenStream(0);
                isOpenStream = true;


            }
            isopenstream_=true;
            pCaptureEventHandler = new CSampleCaptureEventHandler();
            m_objStreamPtr->RegisterCaptureCallback( pCaptureEventHandler ,this);
            m_objStreamPtr->StartGrab();
            m_objRemoteFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();
            m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(ExposureTime);
            CGXBitmap2::cameraopennum++;

        }else{
            emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera--serial number:"+ QString::number(this->Num)+" no open");
        }
    }  catch (exception& e) {
        cout << "abcdef" << e.what() << endl;
    }

}

void VisionDaHengCamera::stopCapture_clicked()
{
    if (isOpenStream)
    {
        cout <<"aa停止采集" << endl;
        //发送停采命令
        m_objRemoteFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
        m_objStreamPtr->StopGrab();
        //m_objStreamPtr->Close();
       //isOpenStream = false;
        isopenstream_=false;
       // isOpenStream=false;
        m_objStreamPtr->UnregisterCaptureCallback();//注销采集回调
    }
    emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"Stop Capture--serial number:"+ QString::number(this->Num));
}

void VisionDaHengCamera::TriggerSoftware_clicked()
{



    try
    {
        do
        {


            if ( (m_triggerSource == "Software"))
            {
                uint32_t nStreamNum = m_objDevicePtr->GetStreamCount();
                if ((nStreamNum > 0) && (!isOpenStream))
                {
                    cout<<"ssss"<<endl;

                    m_objStreamPtr = m_objDevicePtr->OpenStream(0);

                    isOpenStream = true;
                }

                cout<<"sssssss"<<endl;
                m_objStreamPtr->StartGrab();
                m_objRemoteFeatureControlPtr->GetCommandFeature("AcquisitionStart")->Execute();
                CImageDataPointer objImageDataPtr = m_objStreamPtr->GetImage(500);//超时时间使用500ms，用户可以自行设定

                if (objImageDataPtr->GetStatus() == GX_FRAME_STATUS_SUCCESS)
                {

                    //                     void* pRGB24Buffer = objImageDataPtr->ConvertToRGB24(GX_BIT_0_7,GX_RAW2RGB_NEIGHBOUR,true);
                    //                     memcpy(image.data, pRGB24Buffer, objImageDataPtr->GetWidth() *  objImageDataPtr->GetHeight()*3);
                    //                     image = cv::Mat::zeros(cv::Size(objImageDataPtr->GetWidth(), objImageDataPtr->GetHeight()), CV_8UC3);
                    void* pRGB24Buffer = objImageDataPtr->ConvertToRaw8(GX_BIT_0_7);
                    image = cv::Mat::zeros(cv::Size(objImageDataPtr->GetWidth(), objImageDataPtr->GetHeight()), CV_8UC1);
                    memcpy(image.data, pRGB24Buffer, objImageDataPtr->GetWidth() *  objImageDataPtr->GetHeight());




                    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                    //cv::line(image, Point(0,1024), Point(2448,1024), cv::Scalar(125, 255, 0), 3, 8, 0);
                    //   cv::line(image, Point(0,1024-1000/1.727), Point(2448,1024-1000/1.727), cv::Scalar(125, 255, 0), 3, 8, 0);
                    //                    if((Num==2)||(Num==3)||(Num==6)||(Num==5)){
                    //                        transpose(image,image);
                    //                        flip(image,image,1);
                    //                        //                        QMatrix matrix;
                    //                        //                        matrix.rotate(90.0);
                    //                        //                        imgForDisplay=imgForDisplay.transformed(matrix,Qt::FastTransformation);
                    //                    }
                    //                    if(Num==7){
                    //                        transpose(image,image);
                    //                        flip(image,image,0);
                    //                        transpose(image,image);
                    //                        flip(image,image,-1);
                    //                        flip(image,image,2);
                    //                    }

                    imgForDisplay = QImage((const uchar*)(image.data), image.cols, image.rows, image.cols * image.channels(), QImage::Format_Indexed8);


                    QPixmap pixmap_ =QPixmap::fromImage(imgForDisplay);
                    triggerimage=image;
                    emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">Collection successful(software)</font>");
                    emit sendimage(pixmap_);

                    cout<<"aaaaa"<<endl;
                    if(ifmeasure!=0){

                        image_measure(image);

                        ifmeasure=0;
                    }

                    if(ifsave&&DateVar::usage_rate_c<95){
                        Mat ROI_img(image, Rect(1170,833,200,200));
                        if(dection){
                            string path=folderPath_success.toStdString()+"//"+QDateTime::currentDateTime().toString("hh-mm-ss-zzz").toStdString()+".bmp";
                            imwrite(path,image);
                        }else{
                            string path=folderPath_fail.toStdString()+"//"+QDateTime::currentDateTime().toString("hh-mm-ss-zzz").toStdString()+".bmp";
                            emit  saveimage(objImageDataPtr,path);
                            imwrite(path,image);
                        }

                    }

                }
                else{
                    emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Collection failed(software)<font color=\"#FF0000\">");

                }

                m_objRemoteFeatureControlPtr->GetCommandFeature("AcquisitionStop")->Execute();
                m_objStreamPtr->StopGrab();


            }
        } while (0);
    }
    catch (CGalaxyException& e)
    {
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">"+e.what()+"<font color=\"#FF0000\">");
        cout << "软触发错误码: " << e.GetErrorCode() << endl;

        cout << "软触发错误描述信息: " << e.what() << endl;
    }
}
void VisionDaHengCamera::DoOnDeviceOfflineEvent(void* pUserParam)
{
    isOffline = true;
    IGXFactory::GetInstance().Uninit(); //释放GxIAPICPPEx申请的所有资源
    cout << "设备掉线请检查并重新连接" << endl;
}

void VisionDaHengCamera::image_measure(Mat image)
{
    cout<<"camearmeasurenum:"<<camearmeasurenum<<endl;
    switch (camearmeasurenum) {
    case 1:{
        measure->if_return_1=true;
        bool check=VisionMeasure::camera_measure_1(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_1 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }

        camearmeasurenum=0;
        break;
    }
    case 2:{
        measure->if_return_2=true;
        bool check=VisionMeasure::camera_measure_2(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_2 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }
        camearmeasurenum=0;
        break;
    }
    case 3:{
        measure->if_return_3=true;
        bool check=VisionMeasure::camera_measure_3(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_3 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }
        camearmeasurenum=0;
        break;
    }
    case 4:{
        measure->if_return_4=true;
        bool check=VisionMeasure::camera_measure_4(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_4 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }
        camearmeasurenum=0;
        break;
    }
    case 5:{
        measure->if_return_5=true;
        bool check=VisionMeasure::camera_measure_5(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_5 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }
        camearmeasurenum=0;
        break;
    }
    case 6:{
        measure->if_return_6=true;
        bool check=VisionMeasure::camera_measure_6(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_6 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }
        camearmeasurenum=0;
        break;
    }
    case 33:{
        measure->if_return_33=true;
        bool check=VisionMeasure::camera_measure_3_2(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_3_2 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }
        camearmeasurenum=0;
        break;
    }
    case 44:{
        measure->if_return_44=true;
        bool check=VisionMeasure::camera_measure_4_2(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_4_2 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }
        camearmeasurenum=0;
        break;

    }
    case 55:{
        measure->if_return_55=true;
        bool check=VisionMeasure::camera_measure_5_2(image,measure);
        emit sendLog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"camera measure_5_2 stop");

        if(check){
            dection=true;
        }else{
            dection=false;
        }
        camearmeasurenum=0;
        break;

    }
    }

}



void VisionDaHengCamera::opencamera()
{

    openDevice_clicked();

}

void VisionDaHengCamera::closecamera()
{
    closeDevice_clicked();

}

void VisionDaHengCamera::startcapture()
{
    startCapture_clicked();

}

void VisionDaHengCamera::stopcapture()
{
    stopCapture_clicked();
}

void VisionDaHengCamera::Software()
{
    TriggerSoftware_clicked();

}

void VisionDaHengCamera::zhenlvcount()
{
    double tem=0;
    if(isopenstream_){
        QTime time=QTime::currentTime();
        qsrand(time.msec()*1000);
        tem=(double)(qrand()%100)/1000;
    }
    emit sendzhenlv(zhenlv_count+tem);
    zhenlv_count=0;

}
int VisionDaHengCamera::bmp_write(unsigned char *image, int xsize, int ysize, char *filename)
{
    unsigned char header[54] = {
        0x42, 0x4d, 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0
    };

    long file_size = (long)xsize * (long)ysize * 3 + 54;
    header[2] = (unsigned char)(file_size &0x000000ff);
    header[3] = (file_size >> 8) & 0x000000ff;
    header[4] = (file_size >> 16) & 0x000000ff;
    header[5] = (file_size >> 24) & 0x000000ff;

    long width = xsize;
    header[18] = width & 0x000000ff;
    header[19] = (width >> 8) &0x000000ff;
    header[20] = (width >> 16) &0x000000ff;
    header[21] = (width >> 24) &0x000000ff;

    long height = ysize;
    header[22] = height &0x000000ff;
    header[23] = (height >> 8) &0x000000ff;
    header[24] = (height >> 16) &0x000000ff;
    header[25] = (height >> 24) &0x000000ff;

    char fname_bmp[128];
    sprintf(fname_bmp, "%s.bmp", filename);

    FILE *fp;
    if (!(fp = fopen(fname_bmp, "wb")))
        return -1;

    fwrite(header, sizeof(unsigned char), 54, fp);
    fwrite(image, sizeof(unsigned char), (size_t)(long)xsize * ysize * 3, fp);

    fclose(fp);
    return 0;

}

void VisionDaHengCamera::exposeTimesetting()
{
    switch (Num) {
    case 1:
        m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(DateVar::ExposeTime_1);
        break;
    case 2:
        m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(DateVar::ExposeTime_2);
        break;
    case 3:
        m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(DateVar::ExposeTime_3);
        break;
    case 4:
        m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(DateVar::ExposeTime_4);
        break;
    case 5:
        m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(DateVar::ExposeTime_5);
        break;
    case 6:
        m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(DateVar::ExposeTime_6);
        break;
    case 7:
        m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(DateVar::ExposeTime_7);
        break;
    case 8:
        m_objRemoteFeatureControlPtr->GetFloatFeature("ExposureTime")->SetValue(DateVar::ExposeTime_8);
        break;
    default:
        break;
    }
}
void VisionDaHengCamera::__IsSupportColor(CGXDevicePointer& objCGXDevicePointer, bool &bIsColorFilter)
{
    GX_STATUS emStatus = GX_STATUS_SUCCESS;
    bool      bIsImplemented = false;
    bool      bIsMono = false;
    gxstring  strPixelFormat = "";

    strPixelFormat = objCGXDevicePointer->GetRemoteFeatureControl()->GetEnumFeature("PixelFormat")->GetValue();
    strPixelFormat.substr(0, 4);

    if (0 == memcmp(strPixelFormat.c_str(), "Mono", 4))
    {
        bIsMono = true;
    }
    else
    {
        bIsMono = false;
    }

    bIsImplemented = objCGXDevicePointer->GetRemoteFeatureControl()->IsImplemented("PixelColorFilter");

    // 若当前为非黑白且支持PixelColorFilter则为彩色
    if ((!bIsMono) && (bIsImplemented))
    {

        bIsColorFilter = true;
    }
    else
    {

        bIsColorFilter = false;
    }
}

void VisionDaHengCamera::pointtomat(CImageDataPointer &objImageDataPointer)
{
    void* pRGB24Buffer = objImageDataPointer->ConvertToRaw8(GX_BIT_0_7);
    image = cv::Mat::zeros(cv::Size(objImageDataPointer->GetWidth(), objImageDataPointer->GetHeight()), CV_8UC1);
    memcpy(image.data, pRGB24Buffer, objImageDataPointer->GetWidth() *  objImageDataPointer->GetHeight());
    if(ifsave&&DateVar::usage_rate_c<95){
        if(dection){
            string path=folderPath_success.toStdString()+"//"+QDateTime::currentDateTime().toString("hh-mm-ss-zzz").toStdString()+".bmp";
            imwrite(path,image);

        }else{
            string path=folderPath_fail.toStdString()+"//"+QDateTime::currentDateTime().toString("hh-mm-ss-zzz").toStdString()+".bmp";

            imwrite(path,image);
        }
    }
    VisionMeasure::ifauto=true;
    image_measure(image);
}


