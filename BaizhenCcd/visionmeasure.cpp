#include "visionmeasure.h"
#include <complex>
#include<QTransform>
#include<iomanip>

VisionMeasure::VisionMeasure()
{
    // loadtemplate();
    ifsave=false;
    mytoola=this;
    connect(this,&VisionMeasure::SigDeliverMessStatic,this,&VisionMeasure::SlotDeliverMessStatic);//关联内部信号与槽


}
bool VisionMeasure::if_return_1=false;
bool VisionMeasure::if_return_2=false;
bool VisionMeasure::if_return_3=false;
bool VisionMeasure::if_return_4=false;
bool VisionMeasure::if_return_5=false;
bool VisionMeasure::if_return_6=false;
bool VisionMeasure::if_return_7=false;
bool VisionMeasure::if_return_8=false;
bool VisionMeasure::if_return_33=false;
bool VisionMeasure::if_return_44=false;
bool VisionMeasure::if_return_55=false;
int VisionMeasure::model_id_1=-1;
int VisionMeasure::model_id_2=-1;
int VisionMeasure::model_id_3=-1;
int VisionMeasure::model_id_4=-1;
int VisionMeasure::model_id_5=-1;
int VisionMeasure::model_id_6=-1;
float VisionMeasure::A=0;
float VisionMeasure::B=0;
float VisionMeasure::C=0;
float VisionMeasure::D=0;
float VisionMeasure::E=0;
float VisionMeasure::F=0;
VisionMeasure *VisionMeasure::mytoola = nullptr;
String VisionMeasure::modelpath_1="/model/model1.bmp";
String VisionMeasure::modelpath_2="/model/model6.bmp";
String VisionMeasure::modelpath_6="/model/model6.bmp";
double VisionMeasure::cam1_findlinearray[6][21]={0};
double VisionMeasure::cam2_findlinearray[6][18]={0};
double VisionMeasure::cam3_findlinearray[6][18]={0};
double VisionMeasure::cam4_findlinearray[6][18]={0};
double VisionMeasure::cam5_findlinearray[6][18]={0};
double VisionMeasure::cam6_findlinearray[6][18]={0};
double VisionMeasure::cam7_findlinearray[6][21]={0};
double VisionMeasure::cam8_findlinearray[6][21]={0};
double VisionMeasure::cam_threshold[8][6]={0};
QMutex VisionMeasure::g_mutex;
QWaitCondition VisionMeasure::g_waitcondition;
bool VisionMeasure::ifauto=false;

//String VisionMeasure::modelpath_1="C:/Users/ZF/Desktop/model.bmp";
void VisionMeasure::loadtemplate(int num)
{
    init_mwwz();
    //起始角度
    double angle_start = -180;
    //终止角度
    double angle_extent = 360;

    double angle_step = 0;
    double scale_step = 0;

    int contrast_low = 16;
    int contrast_high = 50;
    int min_cont_len = 3;
    int min_contrast = 5;
    int contrast[4] = { contrast_low,contrast_high,min_cont_len ,min_contrast };
    int contrast2[4] = {12,15,min_cont_len ,min_contrast };
    int num_levels = 0;
    int use_polarity = 1;

    //读取模板图像
    // cout<<VisionMeasure::modelpath_1<<endl;
    //Mat model = imread(QApplication::applicationDirPath().toStdString()+"/model/model1.png", IMREAD_GRAYSCALE);




    if(num==0){
        Mat model = imread(QApplication::applicationDirPath().toStdString()+VisionMeasure::modelpath_1, IMREAD_GRAYSCALE);

        if (model.empty())
        {
            std::cout << "model1 empty" << endl;

        }

        // imshow("model", model);
        Mat model2 = imread(QApplication::applicationDirPath().toStdString()+VisionMeasure::modelpath_2, IMREAD_GRAYSCALE);
        if (model2.empty())
        {
            std::cout << "model2 empty" << endl;

        }

        Mat model6 = imread(QApplication::applicationDirPath().toStdString()+VisionMeasure::modelpath_6, IMREAD_GRAYSCALE);
        if (model6.empty())
        {
            std::cout << "model6 empty" << endl;

        }
        //创建模型
        int err = create_shape_model(model.ptr<uchar>(0), model.cols, model.rows, num_levels, angle_start, angle_extent, angle_step, use_polarity, contrast2, NULL, model_id_1);
        int err2 = create_shape_model(model2.ptr<uchar>(0), model2.cols, model2.rows, num_levels, angle_start, angle_extent, angle_step, use_polarity, contrast2, NULL, model_id_2);
        int err3 = create_shape_model(model6.ptr<uchar>(0), model6.cols, model6.rows, num_levels, angle_start, angle_extent, angle_step, use_polarity, contrast2, NULL, model_id_6);



        //create model failed
        if (model_id_1 < 0)
        {
            std::cout << "形状模型创建Fail" << endl;

        }
        if (model_id_2 < 0)
        {
            std::cout << "形状模型创建Fail" << endl;

        }
        if (model_id_6 < 0)
        {
            std::cout << "形状模型创建Fail" << endl;

        }

        //显示模板特征点
        //   Mat modelRgb;
        // cvtColor(model, modelRgb, COLOR_GRAY2RGB);
        /* duixiang->feature_show(modelRgb, model_id_1)*/;
        //imshow("features", modelRgb);
        //imwrite("C:/Users/35843/Desktop/test/test4/1.bmp", modelRgb);


        //保存模板
        string modelPath = "shape_model.bin1";
        int bSuccess = write_shape_model(model_id_1, modelPath.c_str());
        if (bSuccess == 0)
        {
            std::cout << "model1 succed" << endl;
        }

        string modelPath2 = "shape_model2.bin";
        int bSuccess2 = write_shape_model(model_id_2, modelPath2.c_str());
        if (bSuccess2 == 0)
        {
            std::cout << "model2 succed" << endl;
        }

        string modelPath6 = "shape_model3.bin3";
        int bSuccess6 = write_shape_model(model_id_6, modelPath6.c_str());
        if (bSuccess6 == 0)
        {
            std::cout << "model6 succed" << endl;
        }
    }else if(num==1){
        Mat model = imread(QApplication::applicationDirPath().toStdString()+VisionMeasure::modelpath_1, IMREAD_GRAYSCALE);
        if (model.empty())
        {
            std::cout << "111model1 empty" << endl;

        }

        int err = create_shape_model(model.ptr<uchar>(0), model.cols, model.rows, num_levels, angle_start, angle_extent, angle_step, use_polarity, contrast2, NULL, model_id_1);
        //create model failed
        if (model_id_1 < 0)
        {
            std::cout << "形状模型创建Fail" << endl;

        }else{

        }
        //保存模板
        string modelPath = "shape_model.bin1";
        int bSuccess = write_shape_model(model_id_1, modelPath.c_str());
        if (bSuccess == 0)
        {
            std::cout << "1111model1 succed" << endl;

        }
        if (model_id_1 < 0)
        {
            std::cout << "形状模型创建Fail" << endl;
            emit mytoola->SigDeliverMessStatic(1,0);
        }else{
            emit mytoola->SigDeliverMessStatic(1,1);
        }

    }else if(num==2){
        // imshow("model", model);
        Mat model2 = imread(QApplication::applicationDirPath().toStdString()+VisionMeasure::modelpath_2, IMREAD_GRAYSCALE);
        if (model2.empty())
        {
            std::cout << "model2 empty" << endl;

        }
        int err2 = create_shape_model(model2.ptr<uchar>(0), model2.cols, model2.rows, num_levels, angle_start, angle_extent, angle_step, use_polarity, contrast2, NULL, model_id_2);
        if (model_id_2 < 0)
        {
            std::cout << "形状模型创建Fail" << endl;

        }
        string modelPath2 = "shape_model2.bin";
        int bSuccess2 = write_shape_model(model_id_2, modelPath2.c_str());
        if (bSuccess2 == 0)
        {
            std::cout << "2222model2 succed" << endl;
        }
        if (model_id_2 < 0)
        {
            std::cout << "形状模型创建Fail" << endl;
            emit mytoola->SigDeliverMessStatic(2,0);
        }else{
            emit mytoola->SigDeliverMessStatic(2,1);
        }

    }











}



bool VisionMeasure::camera_measure_1(Mat src,VisionMeasure *duixiang)
{
    Mat dst=src.clone();
    Mat dst2=src.clone();
    Mat imageroi(src, Rect(900,650,600,750));
   // src=imageroi;

    //        if(src.channels()!=3){
    //            cout<<"channels:"<<src.channels()<<endl;
    //            cvtColor(dst, dst, COLOR_GRAY2RGB);
    //            cvtColor(src,src,COLOR_BGR2RGB);
    //        }


    //        threshold(src,src,190,255,THRESH_BINARY_INV);
    //        namedWindow("aa",cv::WINDOW_NORMAL);
    //        imshow("aa",src);
    //        waitKey(0);


    bool if_exception=true;

    //起始角度
    double angle_start = -180;
    //终止角度
    double angle_extent = 360;
    int subpixel = 1;
    double scale_min = 1;
    double scale_max = 1;
    double minScore = 0.4;
    double maxOverLap = 0;
    double greedness = 0.9;
    int numMatches = 4;

    if (scale_max < scale_min)
    {
        std::cout << "scale min < max" << endl;

    }
    int numLevels[2] = { 6 };
    int mem_id = 0;
    int nFound = 0;
    Match* pMatches = NULL;

    //模型查找
    if (abs(scale_min - 1) < DBL_EPSILON && abs(scale_max - 1) < DBL_EPSILON)
    {
        mem_id = find_shape_model(dst.ptr<uchar>(0), dst.cols, dst.rows, VisionMeasure::model_id_1, angle_start, angle_extent, minScore, numMatches, maxOverLap, subpixel, numLevels, greedness, pMatches, nFound);
    }
    else
    {
        mem_id = find_scaled_shape_model(dst.ptr<uchar>(0), dst.cols, dst.rows, VisionMeasure::model_id_1, angle_start, angle_extent, scale_min, scale_max, minScore, numMatches, maxOverLap, subpixel, numLevels, greedness, pMatches, nFound);
    }
    cout<<"hhhh3"<<endl;
    if (mem_id < 0)
    {
        std::cout << "find shape model failed" << endl;
        if_exception=false;
        return false;

    }
    else
    {
         Mat srcRgb;
         cvtColor(dst, srcRgb, COLOR_GRAY2RGB);
        std::cout << "find shape model success" << endl;


        duixiang->match_show(srcRgb, VisionMeasure::model_id_1, 0, 0, pMatches, nFound, subpixel);
        clear_mems(mem_id);
        //imshow("result", srcRgb);
    }
    //cout<<"count:"<<nFound<<endl;
    cout<<"  dx: " <<duixiang->camera_dx_1<<"  dy: "<<duixiang->camera_dy_1<<"  angle: "<<duixiang->camera_angle_1<<"  score: "<<duixiang->camera_score_1<<endl;
    // clear_shape_model(model_id_1);

    duixiang->camera_dx_1=duixiang->camera_dx_1;
    duixiang->camera_dy_1=duixiang->camera_dy_1;
    cvtColor(dst,dst,COLOR_BGR2RGB);
    if(duixiang->camera_score_1==0){
        QByteArray result;
        result.append("F");
        result.append(",");
        result.append("0.0");
        result.append(",");
        result.append("0.0");
        result.append(",");
        result.append("0.0");
        result.append(",");
        result.append(QString::number(0, 10,4));
        result.append(",");
        result.append(QString::number(0, 10,4));
        result.append(",");
        result.append(QString::number(0, 10,4));
        if(if_return_1){
            emit  duixiang->informationwrite(1,false);
            emit duixiang->sendclientresult("CAM1ACT2",result,false);
            if_return_1=false;

        }
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_1 detection failed</font>");
        cv::putText(dst,"Detection failed",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(255,0,0),14,LINE_8);
        duixiang->result.clear();
        if(duixiang->ifauto){
            duixiang->ifauto=false;
            emit duixiang->sendresult_to_form7(dst,duixiang->result);
        }else{
            emit duixiang->sendresult(dst,duixiang->result);
        }
        qDebug()<<"camera_2 detection failed";

        return false;
    }
    //图像格式转换
    QImage  image = QImage((const uchar*)(dst2.data), dst2.cols, dst2.rows, dst2.cols * dst2.channels(), QImage::Format_Indexed8);
    image = image.convertToFormat(QImage::Format_RGB888);
    Mat srcImage = Mat(image.height(),
                       image.width(),
                       CV_8UC(3),
                       image.bits(),
                       image.bytesPerLine());


    //真实坐标变换
    vector<QPoint>real_cotransline_1=duixiang->real_coordinatetransformation(cam1_findlinearray[0][0],cam1_findlinearray[0][1],cam1_findlinearray[0][2],cam1_findlinearray[0][3],cam1_findlinearray[0][4],cam1_findlinearray[0][5],cam1_findlinearray[0][6],cam1_findlinearray[0][7],cam1_findlinearray[0][8],cam1_findlinearray[0][9],cam1_findlinearray[0][10],cam1_findlinearray[0][11],cam1_findlinearray[0][12],cam1_findlinearray[0][13],cam1_findlinearray[0][14]);
    vector<QPoint>real_cotransline_2= duixiang->real_coordinatetransformation(cam1_findlinearray[1][0],cam1_findlinearray[1][1],cam1_findlinearray[1][2],cam1_findlinearray[1][3],cam1_findlinearray[1][4],cam1_findlinearray[1][5],cam1_findlinearray[1][6],cam1_findlinearray[1][7],cam1_findlinearray[1][8],cam1_findlinearray[1][9],cam1_findlinearray[1][10],cam1_findlinearray[1][11],cam1_findlinearray[1][12],cam1_findlinearray[1][13],cam1_findlinearray[1][14]);
    vector<QPoint>real_cotransline_3=duixiang->real_coordinatetransformation(cam1_findlinearray[2][0],cam1_findlinearray[2][1],cam1_findlinearray[2][2],cam1_findlinearray[2][3],cam1_findlinearray[2][4],cam1_findlinearray[2][5],cam1_findlinearray[2][6],cam1_findlinearray[2][7],cam1_findlinearray[2][8],cam1_findlinearray[2][9],cam1_findlinearray[2][10],cam1_findlinearray[2][11],cam1_findlinearray[2][12],cam1_findlinearray[2][13],cam1_findlinearray[2][14]);
    vector<QPoint>real_cotransline_4= duixiang->real_coordinatetransformation(cam1_findlinearray[3][0],cam1_findlinearray[3][1],cam1_findlinearray[3][2],cam1_findlinearray[3][3],cam1_findlinearray[3][4],cam1_findlinearray[3][5],cam1_findlinearray[3][6],cam1_findlinearray[3][7],cam1_findlinearray[3][8],cam1_findlinearray[3][9],cam1_findlinearray[3][10],cam1_findlinearray[3][11],cam1_findlinearray[3][12],cam1_findlinearray[3][13],cam1_findlinearray[3][14]);
    vector<QPoint>real_cotransline_5= duixiang->real_coordinatetransformation(cam1_findlinearray[4][0],cam1_findlinearray[4][1],cam1_findlinearray[4][2],cam1_findlinearray[4][3],cam1_findlinearray[4][4],cam1_findlinearray[4][5],cam1_findlinearray[4][6],cam1_findlinearray[4][7],cam1_findlinearray[4][8],cam1_findlinearray[4][9],cam1_findlinearray[4][10],cam1_findlinearray[4][11],cam1_findlinearray[4][12],cam1_findlinearray[4][13],cam1_findlinearray[4][14]);
    vector<QPoint>real_cotransline_6= duixiang->real_coordinatetransformation(cam1_findlinearray[5][0],cam1_findlinearray[5][1],cam1_findlinearray[5][2],cam1_findlinearray[5][3],cam1_findlinearray[5][4],cam1_findlinearray[5][5],cam1_findlinearray[5][6],cam1_findlinearray[5][7],cam1_findlinearray[5][8],cam1_findlinearray[5][9],cam1_findlinearray[5][10],cam1_findlinearray[5][11],cam1_findlinearray[5][12],cam1_findlinearray[5][13],cam1_findlinearray[5][14]);
    //坐标变换
    vector<QPoint>cotransline_1= duixiang->coordinatetransformation(duixiang->camera_dx_1,duixiang->camera_dy_1,duixiang->camera_angle_1,real_cotransline_1[0].x(),real_cotransline_1[0].y(),real_cotransline_1[1].x(),real_cotransline_1[1].y(),real_cotransline_1[2].x(),real_cotransline_1[2].y(),real_cotransline_1[3].x(),real_cotransline_1[3].y(),real_cotransline_1[4].x(),real_cotransline_1[4].y(),real_cotransline_1[5].x(),real_cotransline_1[5].y());
    vector<QPoint>cotransline_2= duixiang->coordinatetransformation(duixiang->camera_dx_1,duixiang->camera_dy_1,duixiang->camera_angle_1,real_cotransline_2[0].x(),real_cotransline_2[0].y(),real_cotransline_2[1].x(),real_cotransline_2[1].y(),real_cotransline_2[2].x(),real_cotransline_2[2].y(),real_cotransline_2[3].x(),real_cotransline_2[3].y(),real_cotransline_2[4].x(),real_cotransline_2[4].y(),real_cotransline_2[5].x(),real_cotransline_2[5].y());
    QRectF bound_1=duixiang->boundingRect(cotransline_1);
    QRectF bound_2=duixiang->boundingRect(cotransline_2);
    vector<QPoint>cotransline_3= duixiang->coordinatetransformation(duixiang->camera_dx_1,duixiang->camera_dy_1,duixiang->camera_angle_1,real_cotransline_3[0].x(),real_cotransline_3[0].y(),real_cotransline_3[1].x(),real_cotransline_3[1].y(),real_cotransline_3[2].x(),real_cotransline_3[2].y(),real_cotransline_3[3].x(),real_cotransline_3[3].y(),real_cotransline_3[4].x(),real_cotransline_3[4].y(),real_cotransline_3[5].x(),real_cotransline_3[5].y());
    vector<QPoint>cotransline_4= duixiang->coordinatetransformation(duixiang->camera_dx_1,duixiang->camera_dy_1,duixiang->camera_angle_1,real_cotransline_4[0].x(),real_cotransline_4[0].y(),real_cotransline_4[1].x(),real_cotransline_4[1].y(),real_cotransline_4[2].x(),real_cotransline_4[2].y(),real_cotransline_4[3].x(),real_cotransline_4[3].y(),real_cotransline_4[4].x(),real_cotransline_4[4].y(),real_cotransline_4[5].x(),real_cotransline_4[5].y());
    QRectF bound_3=duixiang->boundingRect(cotransline_3);
    QRectF bound_4=duixiang->boundingRect(cotransline_4);
    vector<QPoint>cotransline_5= duixiang->coordinatetransformation(duixiang->camera_dx_1,duixiang->camera_dy_1,duixiang->camera_angle_1,real_cotransline_5[0].x(),real_cotransline_5[0].y(),real_cotransline_5[1].x(),real_cotransline_5[1].y(),real_cotransline_5[2].x(),real_cotransline_5[2].y(),real_cotransline_5[3].x(),real_cotransline_5[3].y(),real_cotransline_5[4].x(),real_cotransline_5[4].y(),real_cotransline_5[5].x(),real_cotransline_5[5].y());
    vector<QPoint>cotransline_6= duixiang->coordinatetransformation(duixiang->camera_dx_1,duixiang->camera_dy_1,duixiang->camera_angle_1,real_cotransline_6[0].x(),real_cotransline_6[0].y(),real_cotransline_6[1].x(),real_cotransline_6[1].y(),real_cotransline_6[2].x(),real_cotransline_6[2].y(),real_cotransline_6[3].x(),real_cotransline_6[3].y(),real_cotransline_6[4].x(),real_cotransline_6[4].y(),real_cotransline_6[5].x(),real_cotransline_6[5].y());
    QRectF bound_5=duixiang->boundingRect(cotransline_5);
    QRectF bound_6=duixiang->boundingRect(cotransline_6);
    //    //找线
    //    vector<Point>line_1= duixiang->findline(cotransline_1[0],cotransline_1[1],image,srcImage,169,bound_1,30,7.7,0,1,15);
    vector<Point>line_1= duixiang->findline(cotransline_1[0],cotransline_1[1],image,srcImage,cam1_findlinearray[0][15],bound_1,cam1_findlinearray[0][16],cam1_findlinearray[0][17],cam1_findlinearray[0][18],cam1_findlinearray[0][19],cam1_findlinearray[0][20]);
    vector<Point>line_2= duixiang->findline(cotransline_2[0],cotransline_2[1],image,srcImage,cam1_findlinearray[1][15],bound_2,cam1_findlinearray[1][16],cam1_findlinearray[1][17],cam1_findlinearray[1][18],cam1_findlinearray[1][19],cam1_findlinearray[1][20]);
    //    vector<Point>line_3= duixiang->findline(cotransline_3[0],cotransline_3[1],image,srcImage,cam1_findlinearray[2][15],bound_3,cam1_findlinearray[2][16],cam1_findlinearray[2][17],cam1_findlinearray[2][18],cam1_findlinearray[2][19],cam1_findlinearray[2][20]);
    //    vector<Point>line_4= duixiang->findline(cotransline_4[0],cotransline_4[1],image,srcImage,cam1_findlinearray[3][15],bound_4,cam1_findlinearray[3][16],cam1_findlinearray[3][17],cam1_findlinearray[3][18],cam1_findlinearray[3][19],cam1_findlinearray[3][20]);
    //    vector<Point>line_5= duixiang->findline(cotransline_5[0],cotransline_5[1],image,srcImage,cam1_findlinearray[4][15],bound_5,cam1_findlinearray[4][16],cam1_findlinearray[4][17],cam1_findlinearray[4][18],cam1_findlinearray[4][19],cam1_findlinearray[4][20]);
    //    vector<Point>line_6= duixiang->findline(cotransline_6[0],cotransline_6[1],image,srcImage,cam1_findlinearray[5][15],bound_6,cam1_findlinearray[5][16],cam1_findlinearray[5][17],cam1_findlinearray[5][18],cam1_findlinearray[5][19],cam1_findlinearray[5][20]);
    //  double distance_p2l_1=duixiang->getDist_P2L(line_1[1],line_2[0],line_2[1]);
    //   cout<<"distance_p2l"<<distance_p2l_1*1.703392<<endl;
    //        vector<Point> point_foot_1;
    //        point_foot_1.push_back(line_1[1]);
    //        point_foot_1.push_back(line_2[0]);
    //        point_foot_1.push_back(line_2[1]);
    //        Point foot_1= duixiang->calculate_foot_point(point_foot_1);
    //        cout<<"foot"<<foot_1.x<<"-"<<foot_1.y<<endl;

    cv::line(dst, line_1[0], line_1[1], cv::Scalar(125, 255, 0), 3, 8, 0);
    cv::line(dst, line_2[0], line_2[1], cv::Scalar(125, 255, 0), 3, 8, 0);
    //    cv::line(dst, line_3[0], line_3[1], cv::Scalar(125, 255, 0), 3, 8, 0);
    //    cv::line(dst, line_4[0], line_4[1], cv::Scalar(125, 255, 0), 3, 8, 0);
    //    cv::line(dst, line_5[0], line_5[1], cv::Scalar(125, 255, 0), 3, 8, 0);
    //    cv::line(dst, line_6[0], line_6[1], cv::Scalar(125, 255, 0), 3, 8, 0);

    //            cv::line(dst, line_2[1], foot_1, cv::Scalar(125, 255, 0), 3, 8, 0);
    //            cv::line(dst, line_1[1], foot_1, cv::Scalar(125, 255, 0), 3, 8, 0);
    //            cv::line(dst, line_2[0], line_2[1], cv::Scalar(125, 255, 0), 3, 8, 0);
    //        cv::line(dst, line_3[0], line_3[1], cv::Scalar(125, 255, 0), 3, 8, 0);
    //        cv::line(dst, line_4[0], line_4[1], cv::Scalar(125, 255, 0), 3, 8, 0);
    cv::circle(dst,Point(duixiang->camera_dx_1,duixiang->camera_dy_1),12,cv::Scalar(228, 10,43),-1);


    //        double distance_p2p_1= duixiang->getDistance(foot_1,line_1[1]);
    //        cout<<"distance_p2p"<<distance_p2p_1<<endl;
    double angle=duixiang->measureangle(line_1[0],line_1[1],Point(0,0),Point(1,0));
    cout<<"angle:" << angle<<endl;
    //        cout<<"aaaaa:" << line_1[0].x<<","<<line_1[0].y<<endl;
    //        cout<<"aaaaa:" << line_1[1].x<<","<<line_1[1].y<<endl;
    //        cout<<"bbbb:" << line_2[0].x<<","<<line_2[0].y<<endl;
    //        cout<<"bbbb:" << line_2[1].x<<","<<line_2[1].y<<endl;
    //    if(line_1[0].x>line_1[1].x){
    //        angle= angle+180;
    //    }
    double mm=1/579.7;
    duixiang->camera_dx_1=(1224-duixiang->camera_dx_1)*mm;
    duixiang->camera_dy_1=(1024-duixiang->camera_dy_1)*mm;
    duixiang->result.clear();
    //duixiang->result.push_back(duixiang->camera_angle_1);
    duixiang->result.push_back(DateVar::autofocusscore);
    duixiang->result.push_back(DateVar::autofocusposition);
    duixiang->result.push_back(duixiang->camera_dx_1);
    duixiang->result.push_back(duixiang->camera_dy_1);
    duixiang->result.push_back(-angle);
    // duixiang->result.push_back(-angle);
    //  duixiang->result.push_back(distance_p2p_1*1.7326);
    cout<<"sss:"<<abs(angle)<<endl;
    if(abs(angle)>cam_threshold[0][0]){
        QByteArray result;
        result.append("F");
        result.append(",");
        result.append("0.0");
        result.append(",");
        result.append("0.0");
        result.append(",");
        result.append("0.0");
        result.append(",");
        result.append(QString::number(0, 10,4));
        result.append(",");
        result.append(QString::number(0, 10,4));
        result.append(",");
        result.append(QString::number(0, 10,4));
        if(if_return_1){
            emit  duixiang->informationwrite(1,false);
            emit duixiang->sendclientresult("CAM1ACT2",result,false);
            if_return_1=false;

        }
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_1 detection failed</font>");
        cv::putText(dst,"Detection failed",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(255,0,0),14,LINE_8);
        duixiang->result.clear();
        if(duixiang->ifauto){
            duixiang->ifauto=false;
            emit duixiang->sendresult_to_form7(dst,duixiang->result);
        }else{
            emit duixiang->sendresult(dst,duixiang->result);
        }
        qDebug()<<"camera_2 detection failed";

        return false;
    }

    for(int i=0;i<duixiang->result.size();i++){
        string a="date"+to_string(i)+":";
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << duixiang->result[i];
        std::string strNum = oss.str();
        strNum=a+strNum;
        cv::putText(dst,strNum,Point(50,i*120+120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(49,217,217),14,LINE_8);
    }

    emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">camera_1 detection successful</font>");
    cv::putText(dst,"Detection successful",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(0,255,0),14,LINE_8);

    QByteArray result;
    result.append("T");
    result.append(",");
    result.append("0.0");
    result.append(",");
    result.append("0.0");
    result.append(",");
    result.append("0.0");
    result.append(",");
    result.append(QString::number(duixiang->camera_dx_1, 10,4));
    result.append(",");
    result.append(QString::number(duixiang->camera_dy_1, 10,4));
    result.append(",");
    result.append(QString::number(duixiang->result[4], 10,4));
    if(if_return_1){
        emit  duixiang->informationwrite(1,true);
        emit duixiang->sendclientresult("CAM1ACT2",result,true);
        if_return_1=false;

    }

    if(duixiang->ifauto){
        duixiang->ifauto=false;
        emit duixiang->sendresult_to_form7(dst,duixiang->result);
    }else{
        emit duixiang->sendresult(dst,duixiang->result);
    }

    qDebug()<<"camera_1 detection successful";
    qDebug()<<"dx:"<<duixiang->camera_dx_1<<"dy:"<<duixiang->camera_dy_1<<"angle:"<<duixiang->result[4]<<"score:"<<duixiang->camera_score_1;
    return true;





}

bool VisionMeasure::camera_measure_2(Mat src2,VisionMeasure *duixiang)
{


    bool if_exception=true;
    Rect roi(DateVar::autofocusroi_2_start_x,DateVar::autofocusroi_2_start_y,DateVar::autofocusroi_2_width,DateVar::autofocusroi_2_height);

    Mat src(src2,roi);
    cvtColor(src,src,COLOR_BGR2RGB);
    threshold(src,src,150,255,THRESH_BINARY);
    Mat img8bit = Mat::zeros(Size(src.cols, src.rows), CV_8UC1);
    for (int i = 0; i < src.rows; i++)
    {
        uchar* data = src.ptr<uchar>(i);
        for (int j = 0; j < src.cols * 3; j = j + 3)
        {
            img8bit.at<uchar>(i, j / 3) = data[j];
        }
    }



    //imshow("a",src);
    // waitKey(0);
    RNG rng(10086);
    Mat out,stats,centroids;
    int number=connectedComponentsWithStats(img8bit,out,stats,centroids,8,CV_16U);
    cout<<"number:"<<number<<endl;
    vector<Vec3b>colors;
    for(int i=0;i<number;i++){
        Vec3b vec3=Vec3b(rng.uniform(0,256),rng.uniform(0,256),rng.uniform(0,256));
        colors.push_back(vec3);

    }
    Mat result2=Mat::zeros(src.size(),src.type());
    int w=result2.cols;
    int h=result2.rows;
    int centerx=0;
    int centery=0;
    Rect rect;
    duixiang->result.clear();
    for(int i=1;i<number;i++){
        int center_x=centroids.at<double>(i,0);
        int center_y=centroids.at<double>(i,1);
        int x=stats.at<int>(i,CC_STAT_LEFT);
        int y=stats.at<int>(i,CC_STAT_TOP);
        int w=stats.at<int>(i,CC_STAT_WIDTH);
        int h=stats.at<int>(i,CC_STAT_HEIGHT);
        int area=stats.at<int>(i,CC_STAT_AREA);

        circle(src,Point(center_x,center_y),2,Scalar(255,255,0),2,8,0);
        rect.x=roi.x+x;
        rect.y=roi.y+y;
        rect.width=w;
        rect.height=h;

        // rectangle(src,rect,RGB(255,255,0),1,8,0);
        putText(src,format("%d",i),Point(center_x,center_y),FONT_HERSHEY_SIMPLEX,0.5,Scalar(0,110,110),1);
        cout<<"number:"<<i<<",x:"<<x<<",y:"<<y<<",width:"<<w<<",height"<<h<<",area:"<<area<<endl;
        if(area>cam_threshold[1][0]&&area<cam_threshold[1][1]){
            cout<<"aaa"<<cam_threshold[1][0]<<endl;
            duixiang->result.push_back(DateVar::autofocusscore);
            duixiang->result.push_back(DateVar::autofocusposition);
            duixiang->result.push_back(x+roi.x);
            duixiang->result.push_back(y+roi.y);
            duixiang->result.push_back(w);
            duixiang->result.push_back(h);
            duixiang->result.push_back(area);
            centerx=center_x+roi.x;
            centery=center_y+roi.y;



        }
        cout<<"number2:"<<i<<",x:"<<x<<",y:"<<y<<",width:"<<w<<",height"<<h<<",area:"<<area<<endl;
    }

    //   cout<<"*******************************"<<DateVar::autofocusposition<<"********************************"<<endl;
    //cout<<"aaaaaaaaa:"<<endl;
    cvtColor(src2, src2, COLOR_GRAY2BGR);
    rectangle(src2,rect,RGB(255,255,0),2,8,0);
    circle(src2,Point(centerx,centery), 3, RGB(255,255,0), -1);
    src=src2;
    for(int i=0;i<duixiang->result.size();i++){
        string a="date"+to_string(i)+":";
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(3) << duixiang->result[i];
        std::string strNum = oss.str();
        strNum=a+strNum;
        cv::putText(src,strNum,Point(50,i*120+120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(49,217,217),14,LINE_8);
    }
    //cout<<"bbbbb:"<<endl;
    QByteArray result;
    bool return_bool;
    if(duixiang->result.size()==7){
        cout<<"ccccc:"<<endl;
        qDebug()<<"camera_2 detection successful";
        //qDebug()<<"tanzhen_w:"<<duixiang->result[4]<<"tanzhen_h:"<<duixiang->result[5]<<"tanzhen_area:"<<duixiang->result[6];
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">camera_2 detection successful</font>");
        cv::putText(src,"Detection successful",Point(src.cols-1050,80),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(0,255,0),14,LINE_8);
        result.append("T");
        result.append(",");
        result.append("1.0");
        result.append(",");
        result.append("2.0");
        emit duixiang->informationwrite(2,true);
        return_bool=true;
    }else{

        qDebug()<<"camera_2 detection failed";
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_2 detection failed</font>");
        cv::putText(src,"Detection failed",Point(src.cols-1050,80),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(255,0,0),14,LINE_8);
        result.append("F");
        result.append(",");
        result.append("0.0");
        result.append(",");
        result.append("0.0");
        emit duixiang->informationwrite(2,false);
        return_bool=false;

    }







    if(if_return_2){
        emit duixiang->sendclientresult("CAM2ACT2",result,true);
        if_return_2=false;

    }
    if(duixiang->ifauto){
        duixiang->ifauto=false;
        emit duixiang->sendresult_to_form8(src,duixiang->result);
    }else{
        emit duixiang->sendresult(src,duixiang->result);
    }

    return return_bool;

}

bool VisionMeasure::camera_measure_3_2(Mat src,VisionMeasure *duixiang)
{
    //统计像素
    int count=0;
    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){
            if(src.at<uchar>(i,j)<10){
                count++;

            }
        }

    }
    // cout<<"xiangsu:"<<count<<endl;
    bool if_exception=true;
    Mat dst=src.clone();
    //图像格式转换
    QImage  image = QImage((const uchar*)(src.data), src.cols, src.rows, src.cols * src.channels(), QImage::Format_Indexed8);
    image = image.convertToFormat(QImage::Format_RGB888);
    Mat srcImage = Mat(image.height(),
                       image.width(),
                       CV_8UC(3),
                       image.bits(),
                       image.bytesPerLine());



    //    for (int i = 0; i < sizeof(cam3_findlinearray) / sizeof(cam3_findlinearray[0]); ++i) {
    //        for (int j = 0; j < sizeof(cam3_findlinearray[0]) / sizeof(cam3_findlinearray[0][0]); ++j) {
    //            std::cout<<i+1<<"******"<<j+1<<"*******"<<cam3_findlinearray[i][j]<<std::endl;
    //        }
    //        std::cout<<std::endl;
    //    }
    vector<QPoint> findlinezuobiao;
    findlinezuobiao.push_back(QPoint(cam3_findlinearray[0][0],cam3_findlinearray[0][1]));
    findlinezuobiao.push_back(QPoint(cam3_findlinearray[0][2],cam3_findlinearray[0][3]));
    findlinezuobiao.push_back(QPoint(cam3_findlinearray[0][4],cam3_findlinearray[0][5]));
    findlinezuobiao.push_back(QPoint(cam3_findlinearray[0][6],cam3_findlinearray[0][7]));
    findlinezuobiao.push_back(QPoint(cam3_findlinearray[0][8],cam3_findlinearray[0][9]));
    findlinezuobiao.push_back(QPoint(cam3_findlinearray[0][10],cam3_findlinearray[0][11]));

    vector<QPoint> findlinezuobiao2;
    findlinezuobiao2.push_back(QPoint(cam3_findlinearray[1][0],cam3_findlinearray[1][1]));
    findlinezuobiao2.push_back(QPoint(cam3_findlinearray[1][2],cam3_findlinearray[1][3]));
    findlinezuobiao2.push_back(QPoint(cam3_findlinearray[1][4],cam3_findlinearray[1][5]));
    findlinezuobiao2.push_back(QPoint(cam3_findlinearray[1][6],cam3_findlinearray[1][7]));
    findlinezuobiao2.push_back(QPoint(cam3_findlinearray[1][8],cam3_findlinearray[1][9]));
    findlinezuobiao2.push_back(QPoint(cam3_findlinearray[1][10],cam3_findlinearray[1][11]));




    vector<QPoint>cotransline_1=findlinezuobiao;
    vector<QPoint>cotransline_2=findlinezuobiao2;
    QRectF bound_11=duixiang->boundingRect(cotransline_1);
    QRectF bound_22=duixiang->boundingRect(cotransline_2);
    //    //找线
    vector<Point>line_1= duixiang->findline(cotransline_1[0],cotransline_1[1],image,srcImage,cam3_findlinearray[0][12],bound_11,cam3_findlinearray[0][13],cam3_findlinearray[0][14],cam3_findlinearray[0][15],cam3_findlinearray[0][16],cam3_findlinearray[0][17]);
    vector<Point>line_2= duixiang->findline(cotransline_2[0],cotransline_2[1],image,srcImage,cam3_findlinearray[1][12],bound_22,cam3_findlinearray[1][13],cam3_findlinearray[1][14],cam3_findlinearray[1][15],cam3_findlinearray[1][16],cam3_findlinearray[1][17]);
    cvtColor(dst,dst,COLOR_BGR2RGB);

    Point2f a1;
    Point2f a2;
    Point2f b1;
    Point2f b2;
    a1.x=line_1[0].x;
    a1.y=line_1[0].y;
    a2.x=line_1[1].x;
    a2.y=line_1[1].y;
    b1.x=line_2[0].x;
    b1.y=line_2[0].y;
    b2.x=line_2[1].x;
    b2.y=line_2[1].y;

    Point2f mid1;
    Point2f mid2;
    mid1.x=(a1.x+b1.x)/2;
    mid1.y=(a1.y+b1.y)/2;
    mid2.x=(a2.x+b2.x)/2;
    mid2.y=(a2.y+b2.y)/2;

    cv::line(dst, a1,a2, cv::Scalar(0, 250, 0), 3, 8, 0);
    cv::line(dst, b1, b2, cv::Scalar(0, 255, 0), 3, 8, 0);
    cv::line(dst, mid1, mid2, cv::Scalar(125, 255, 0), 3, 8, 0);
    cv::line(dst, Point(0,1420), Point(5496,1420), cv::Scalar(255,125,125), 3, 8, 0);
    cv::line(dst, Point(2748,0), Point(2748,3672), cv::Scalar(0,0,255), 3, 8, 0);

    Point2f jiaodian= duixiang->getCrossPoint(mid1,mid2,Point2f(double(0.0),double(3220.5)),Point2f(double(5496.0),double(3220.5)));
    cv::circle(dst,jiaodian,10,cv::Scalar(38, 255, 255),-1);

    double distance_p2l_1=duixiang->getDist_P2L(jiaodian,Point(2748,0),Point(2748,3672));

    Point2f jiaodian2= duixiang->getCrossPoint( Point(2748,0),Point(2748,3672),Point2f(double(0.0),double(3220.5)),Point2f(double(5496.0),double(3220.5)));
    cv::circle(dst,jiaodian2,10,cv::Scalar(38, 255,255),-1);
    double distance_p2p_1= duixiang->getDistance(jiaodian,jiaodian2);

    cv::arrowedLine(dst, jiaodian, jiaodian2, cv::Scalar(0,255,0), 3, 8, 0,0.1);
    cv::arrowedLine(dst, jiaodian2, jiaodian, cv::Scalar(0,255,0), 3, 8, 0,0.1);
    //    // cv::intersect(line1, line2, intersection);
    // imwrite("C:/Users/User/Desktop/test3_1.png",dst);
    if(jiaodian.x>2748){
        distance_p2p_1=-distance_p2p_1;
    }

    duixiang->result.clear();
    //duixiang->result.push_back(duixiang->camera_angle_1);
    duixiang->result.push_back(distance_p2p_1/2500);



    for(int i=0;i<duixiang->result.size();i++){
        string a="date"+to_string(i)+":";
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << duixiang->result[i];
        std::string strNum = oss.str();
        strNum=a+strNum;
        cv::putText(dst,strNum,Point(50,i*120+120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(49,217,217),14,LINE_8);
    }

    emit duixiang->sendresult(dst,duixiang->result);
    QByteArray result;
    bool return_bool;
      if(count>cam_threshold[5][0]){

        result.append("T");
        result.append(",");
        result.append(QString::number(distance_p2p_1/2500, 10,4));
        emit  duixiang->informationwrite(6,true);
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">camera_3 detection successful</font>");
        cv::putText(dst,"Detection successful",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(0,255,0),14,LINE_8);
        qDebug()<<"camera_3(夹爪) detection successful";
        qDebug()<<"pianyi:"<<distance_p2p_1/2500;
        return_bool=true;
    }else{
        result.append("F");
        result.append(",");
        result.append("0");
        emit  duixiang->informationwrite(6,false);
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_3 detection failed</font>");
        cv::putText(dst,"Detection failed",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(255,0,0),14,LINE_8);
        qDebug()<<"camera_3(夹爪) detection failed";
        return_bool=false;
    }


    emit duixiang->sendresult(dst,duixiang->result);
    if(if_return_33){
        emit duixiang->sendclientresult("CAM3ACT3",result,true);
        if_return_33=false;

    }


    return return_bool;


}

bool VisionMeasure::camera_measure_3(Mat src, VisionMeasure *duixiang)
{

    bool if_exception=true;
    emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">camera_1 detection successful</font>");
    cv::putText(src,"Detection successful",Point(src.cols-1050,50),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(0,255,0),14,LINE_8);


    QByteArray result;
    result.append("T");

    if(if_return_3){
        emit  duixiang->informationwrite(3,true);
        emit duixiang->sendclientresult("CAM3ACT2",result,true);
        if_return_3=false;

    }
    emit duixiang->sendresult(src,duixiang->result);
    return true;

}

bool VisionMeasure::camera_measure_4_2(Mat src,VisionMeasure *duixiang)
{


    //统计像素
    int count=0;
    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){
            if(src.at<uchar>(i,j)<10){
                count++;

            }
        }

    }
    cout<<"xiangsu:"<<count<<endl;
    bool if_exception=true;
    Mat dst=src.clone();
    //图像格式转换
    QImage  image = QImage((const uchar*)(src.data), src.cols, src.rows, src.cols * src.channels(), QImage::Format_Indexed8);
    image = image.convertToFormat(QImage::Format_RGB888);
    Mat srcImage = Mat(image.height(),
                       image.width(),
                       CV_8UC(3),
                       image.bits(),
                       image.bytesPerLine());


    //    for (int i = 0; i < sizeof(cam4_findlinearray) / sizeof(cam4_findlinearray[0]); ++i) {
    //        for (int j = 0; j < sizeof(cam4_findlinearray[0]) / sizeof(cam4_findlinearray[0][0]); ++j) {
    //            std::cout<<i+1<<"******"<<j+1<<"*******"<<cam4_findlinearray[i][j]<<std::endl;
    //        }
    //        std::cout<<std::endl;
    //    }

    vector<QPoint> findlinezuobiao;
    findlinezuobiao.push_back(QPoint(cam4_findlinearray[0][0],cam4_findlinearray[0][1]));
    findlinezuobiao.push_back(QPoint(cam4_findlinearray[0][2],cam4_findlinearray[0][3]));
    findlinezuobiao.push_back(QPoint(cam4_findlinearray[0][4],cam4_findlinearray[0][5]));
    findlinezuobiao.push_back(QPoint(cam4_findlinearray[0][6],cam4_findlinearray[0][7]));
    findlinezuobiao.push_back(QPoint(cam4_findlinearray[0][8],cam4_findlinearray[0][9]));
    findlinezuobiao.push_back(QPoint(cam4_findlinearray[0][10],cam4_findlinearray[0][11]));

    vector<QPoint> findlinezuobiao2;
    findlinezuobiao2.push_back(QPoint(cam4_findlinearray[1][0],cam4_findlinearray[1][1]));
    findlinezuobiao2.push_back(QPoint(cam4_findlinearray[1][2],cam4_findlinearray[1][3]));
    findlinezuobiao2.push_back(QPoint(cam4_findlinearray[1][4],cam4_findlinearray[1][5]));
    findlinezuobiao2.push_back(QPoint(cam4_findlinearray[1][6],cam4_findlinearray[1][7]));
    findlinezuobiao2.push_back(QPoint(cam4_findlinearray[1][8],cam4_findlinearray[1][9]));
    findlinezuobiao2.push_back(QPoint(cam4_findlinearray[1][10],cam4_findlinearray[1][11]));




    vector<QPoint>cotransline_1=findlinezuobiao;
    vector<QPoint>cotransline_2=findlinezuobiao2;
    QRectF bound_11=duixiang->boundingRect(cotransline_1);
    QRectF bound_22=duixiang->boundingRect(cotransline_2);
    //    //找线
    vector<Point>line_1= duixiang->findline(cotransline_1[0],cotransline_1[1],image,srcImage,cam4_findlinearray[0][12],bound_11,cam4_findlinearray[0][13],cam4_findlinearray[0][14],cam4_findlinearray[0][15],cam4_findlinearray[0][16],cam4_findlinearray[0][17]);
    vector<Point>line_2= duixiang->findline(cotransline_2[0],cotransline_2[1],image,srcImage,cam4_findlinearray[1][12],bound_22,cam4_findlinearray[1][13],cam4_findlinearray[1][14],cam4_findlinearray[1][15],cam4_findlinearray[1][16],cam4_findlinearray[1][17]);
    cvtColor(dst,dst,COLOR_BGR2RGB);

    Point2f a1;
    Point2f a2;
    Point2f b1;
    Point2f b2;
    a1.x=line_1[0].x;
    a1.y=line_1[0].y;
    a2.x=line_1[1].x;
    a2.y=line_1[1].y;
    b1.x=line_2[0].x;
    b1.y=line_2[0].y;
    b2.x=line_2[1].x;
    b2.y=line_2[1].y;

    Point2f mid1;
    Point2f mid2;
    mid1.x=(a1.x+b1.x)/2;
    mid1.y=(a1.y+b1.y)/2;
    mid2.x=(a2.x+b2.x)/2;
    mid2.y=(a2.y+b2.y)/2;

    cv::line(dst, a1,a2, cv::Scalar(0, 250, 0), 3, 8, 0);
    cv::line(dst, b1, b2, cv::Scalar(0, 255, 0), 3, 8, 0);
    cv::line(dst, mid1, mid2, cv::Scalar(125, 255, 0), 3, 8, 0);
    cv::line(dst, Point(0,1420), Point(5496,1420), cv::Scalar(255,125,125), 3, 8, 0);
    cv::line(dst, Point(2748,0), Point(2748,3672), cv::Scalar(0,0,255), 3, 8, 0);

    Point2f jiaodian= duixiang->getCrossPoint(mid1,mid2,Point2f(double(0.0),double(3220.5)),Point2f(double(5496.0),double(3220.5)));
    cv::circle(dst,jiaodian,10,cv::Scalar(38, 255, 255),-1);

    double distance_p2l_1=duixiang->getDist_P2L(jiaodian,Point(2748,0),Point(2748,3672));

    Point2f jiaodian2= duixiang->getCrossPoint( Point(2748,0),Point(2748,3672),Point2f(double(0.0),double(3220.5)),Point2f(double(5496.0),double(3220.5)));
    cv::circle(dst,jiaodian2,10,cv::Scalar(38, 255,255),-1);
    double distance_p2p_1= duixiang->getDistance(jiaodian,jiaodian2);

    cv::arrowedLine(dst, jiaodian, jiaodian2, cv::Scalar(0,255,0), 3, 8, 0,0.1);
    cv::arrowedLine(dst, jiaodian2, jiaodian, cv::Scalar(0,255,0), 3, 8, 0,0.1);
    //    // cv::intersect(line1, line2, intersection);
    // imwrite("C:/Users/User/Desktop/test3_1.png",dst);
    if(jiaodian.x>2748){
        distance_p2p_1=-distance_p2p_1;
    }

    duixiang->result.clear();
    //duixiang->result.push_back(duixiang->camera_angle_1);
    duixiang->result.push_back(distance_p2p_1/2500);



    for(int i=0;i<duixiang->result.size();i++){
        string a="date"+to_string(i)+":";
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << duixiang->result[i];
        std::string strNum = oss.str();
        strNum=a+strNum;
        cv::putText(dst,strNum,Point(50,i*120+120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(49,217,217),14,LINE_8);
    }

    emit duixiang->sendresult(dst,duixiang->result);


    bool return_bool;
    QByteArray result;
    if(count>cam_threshold[6][0]){

        result.append("T");
        result.append(",");
        result.append(QString::number(distance_p2p_1/2500, 10,4));
        emit  duixiang->informationwrite(7,true);
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">camera_4 detection successful</font>");
        cv::putText(dst,"Detection successful",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(0,255,0),14,LINE_8);
        qDebug()<<"camera_4(夹爪) detection successful";
        qDebug()<<"pianyi:"<<distance_p2p_1/2500;
        return_bool =true;
    }else{
        result.append("F");
        result.append(",");
        result.append("0");
        emit  duixiang->informationwrite(7,false);
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_4 detection failed</font>");
        cv::putText(dst,"Detection failed",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(255,0,0),14,LINE_8);
        qDebug()<<"camera_4(夹爪) detection failed";
        return_bool=false;
    }


    emit duixiang->sendresult(dst,duixiang->result);
    if(if_return_44){
        emit duixiang->sendclientresult("CAM4ACT3",result,true);
        if_return_44=false;

    }
    return return_bool;





}

bool VisionMeasure::camera_measure_4(Mat src, VisionMeasure *duixiang)
{
    cout<<"aaaa"<<endl;
    bool if_exception=true;
    emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">camera_4 detection successful</font>");
    cv::putText(src,"Detection successful",Point(src.cols-1050,50),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(0,255,0),14,LINE_8);
    QByteArray result;
    result.append("T");
    if(if_return_4){
        emit  duixiang->informationwrite(4,true);
        emit duixiang->sendclientresult("CAM4ACT2",result,true);
        if_return_4=false;

    }
    emit duixiang->sendresult(src,duixiang->result);
    return true;
}
bool VisionMeasure::camera_measure_5_2(Mat src,VisionMeasure *duixiang)
{


    bool if_exception=true;
    Mat dst=src.clone();
    //图像格式转换
    QImage  image = QImage((const uchar*)(src.data), src.cols, src.rows, src.cols * src.channels(), QImage::Format_Indexed8);
    image = image.convertToFormat(QImage::Format_RGB888);
    Mat srcImage = Mat(image.height(),
                       image.width(),
                       CV_8UC(3),
                       image.bits(),
                       image.bytesPerLine());

    vector<QPoint> findlinezuobiao;
    findlinezuobiao.push_back(QPoint(cam5_findlinearray[0][0],cam5_findlinearray[0][1]));
    findlinezuobiao.push_back(QPoint(cam5_findlinearray[0][2],cam5_findlinearray[0][3]));
    findlinezuobiao.push_back(QPoint(cam5_findlinearray[0][4],cam5_findlinearray[0][5]));
    findlinezuobiao.push_back(QPoint(cam5_findlinearray[0][6],cam5_findlinearray[0][7]));
    findlinezuobiao.push_back(QPoint(cam5_findlinearray[0][8],cam5_findlinearray[0][9]));
    findlinezuobiao.push_back(QPoint(cam5_findlinearray[0][10],cam5_findlinearray[0][11]));

    vector<QPoint>cotransline_1=findlinezuobiao;
    QRectF bound_11=duixiang->boundingRect(cotransline_1);
    //    //找线
    vector<Point>line_1= duixiang->findline(cotransline_1[0],cotransline_1[1],image,srcImage,cam5_findlinearray[0][12],bound_11,cam5_findlinearray[0][13],cam5_findlinearray[0][14],cam5_findlinearray[0][15],cam5_findlinearray[0][16],cam5_findlinearray[0][17]);

    vector<QPoint> findlinezuobiao2;
    findlinezuobiao2.push_back(QPoint(cam5_findlinearray[1][0],cam5_findlinearray[1][1]));
    findlinezuobiao2.push_back(QPoint(cam5_findlinearray[1][2],cam5_findlinearray[1][3]));
    findlinezuobiao2.push_back(QPoint(cam5_findlinearray[1][4],cam5_findlinearray[1][5]));
    findlinezuobiao2.push_back(QPoint(cam5_findlinearray[1][6],cam5_findlinearray[1][7]));
    findlinezuobiao2.push_back(QPoint(cam5_findlinearray[1][8],cam5_findlinearray[1][9]));
    findlinezuobiao2.push_back(QPoint(cam5_findlinearray[1][10],cam5_findlinearray[1][11]));
    vector<QPoint>cotransline_2=findlinezuobiao2;
    QRectF bound_22=duixiang->boundingRect(cotransline_2);
    //    //找线
    vector<Point>line_2= duixiang->findline(cotransline_2[0],cotransline_2[1],image,srcImage,cam5_findlinearray[1][12],bound_22,cam5_findlinearray[1][13],cam5_findlinearray[1][14],cam5_findlinearray[1][15],cam5_findlinearray[1][16],cam5_findlinearray[1][17]);

    vector<QPoint> findlinezuobiao3;
    findlinezuobiao3.push_back(QPoint(cam5_findlinearray[2][0],cam5_findlinearray[2][1]));
    findlinezuobiao3.push_back(QPoint(cam5_findlinearray[2][2],cam5_findlinearray[2][3]));
    findlinezuobiao3.push_back(QPoint(cam5_findlinearray[2][4],cam5_findlinearray[2][5]));
    findlinezuobiao3.push_back(QPoint(cam5_findlinearray[2][6],cam5_findlinearray[2][7]));
    findlinezuobiao3.push_back(QPoint(cam5_findlinearray[2][8],cam5_findlinearray[2][9]));
    findlinezuobiao3.push_back(QPoint(cam5_findlinearray[2][10],cam5_findlinearray[2][11]));
    vector<QPoint>cotransline_3=findlinezuobiao3;
    QRectF bound_33=duixiang->boundingRect(cotransline_3);
    //    //找线
    vector<Point>line_3= duixiang->findline(cotransline_3[0],cotransline_3[1],image,srcImage,cam5_findlinearray[2][12],bound_33,cam5_findlinearray[2][13],cam5_findlinearray[2][14],cam5_findlinearray[2][15],cam5_findlinearray[2][16],cam5_findlinearray[2][17]);

    vector<QPoint> findlinezuobiao4;
    findlinezuobiao4.push_back(QPoint(cam5_findlinearray[3][0],cam5_findlinearray[3][1]));
    findlinezuobiao4.push_back(QPoint(cam5_findlinearray[3][2],cam5_findlinearray[3][3]));
    findlinezuobiao4.push_back(QPoint(cam5_findlinearray[3][4],cam5_findlinearray[3][5]));
    findlinezuobiao4.push_back(QPoint(cam5_findlinearray[3][6],cam5_findlinearray[3][7]));
    findlinezuobiao4.push_back(QPoint(cam5_findlinearray[3][8],cam5_findlinearray[3][9]));
    findlinezuobiao4.push_back(QPoint(cam5_findlinearray[3][10],cam5_findlinearray[3][11]));
    vector<QPoint>cotransline_4=findlinezuobiao4;
    QRectF bound_44=duixiang->boundingRect(cotransline_4);
    //    //找线
    vector<Point>line_4= duixiang->findline(cotransline_4[0],cotransline_4[1],image,srcImage,cam5_findlinearray[3][12],bound_44,cam5_findlinearray[3][13],cam5_findlinearray[3][14],cam5_findlinearray[3][15],cam5_findlinearray[3][16],cam5_findlinearray[3][17]);



    cvtColor(dst,dst,COLOR_BGR2RGB);

    Point2f a1;
    Point2f a2;
    a1.x=line_1[0].x;
    a1.y=line_1[0].y;
    a2.x=line_1[1].x;
    a2.y=line_1[1].y;

    Point2f a3;
    Point2f a4;
    a3.x=line_2[0].x;
    a3.y=line_2[0].y;
    a4.x=line_2[1].x;
    a4.y=line_2[1].y;

    Point2f a5;
    Point2f a6;
    a5.x=line_3[0].x;
    a5.y=line_3[0].y;
    a6.x=line_3[1].x;
    a6.y=line_3[1].y;

    Point2f a7;
    Point2f a8;
    a7.x=line_4[0].x;
    a7.y=line_4[0].y;
    a8.x=line_4[1].x;
    a8.y=line_4[1].y;




    cv::line(dst, a1,a2, cv::Scalar(0, 250, 0), 3, 8, 0);

    cv::line(dst, a3,a4, cv::Scalar(0, 250, 0), 3, 8, 0);

    cv::line(dst, a5,a6, cv::Scalar(0, 250, 0), 3, 8, 0);

    cv::line(dst, a7,a8, cv::Scalar(0, 250, 0), 3, 8, 0);
    cv::line(dst, (a1+a5)/2, (a2+a6)/2, cv::Scalar(0, 0, 250), 3, 8, 0);

    cv::line(dst,  (a3+a7)/2, (a4+a8)/2, cv::Scalar(0, 0, 250), 3, 8, 0);

    cv::line(dst,  Point(700,0), Point(700,5496), cv::Scalar(0, 0, 250), 3, 8, 0);
    cv::line(dst,  Point(2900,0), Point(2900,5496), cv::Scalar(0, 0, 250), 3, 8, 0);

    Point2f jiaodian_1= duixiang->getCrossPoint((a1+a5)/2,(a2+a6)/2,Point2f(double(700.0),double(0.0)),Point2f(double(700.0),double(5496.0)));
    cv::circle(dst,jiaodian_1,10,cv::Scalar(38, 255, 255),-1);
    Point2f jiaodian_2= duixiang->getCrossPoint( (a3+a7)/2,(a4+a8)/2,Point2f(double(2900.0),double(0.0)),Point2f(double(2900.0),double(5496.0)));
    cv::circle(dst,jiaodian_2,10,cv::Scalar(38, 255, 255),-1);
    duixiang->result.clear();
    //duixiang->result.push_back(duixiang->camera_angle_1);
    duixiang->result.push_back(1);

    // duixiang->result.push_back(distance_p2l_1)

    double pianyi=abs(jiaodian_1.y-jiaodian_2.y);
    for(int i=0;i<duixiang->result.size();i++){
        string a="date"+to_string(i)+":";
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << pianyi;
        std::string strNum = oss.str();
        strNum=a+strNum;
        cv::putText(dst,strNum,Point(50,i*120+120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(49,217,217),14,LINE_8);
    }

    emit duixiang->sendresult(dst,duixiang->result);

    bool return_bool;
    cout<<"pianyi:"<<pianyi<<endl;
    QByteArray result;
    //    if(pianyi>cam_threshold[4][0]&&pianyi<cam_threshold[4][1]){
    if(pianyi!=100){
        result.append("T");
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">camera_5 detection successful</font>");
        cv::putText(dst,"Detection successful",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(0,255,0),14,LINE_8);
        emit  duixiang->informationwrite(5,true);
        qDebug()<<"camera_5(横梁) detection successful";
        qDebug()<<"pianyi:"<<pianyi;
        return_bool=true;
    }else{
        result.append("F");
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_5 detection failed</font>");
        cv::putText(dst,"Detection failed",Point(dst.cols-1050,120),cv::FONT_HERSHEY_SIMPLEX,3,cv::Scalar(255,0,0),14,LINE_8);
        emit  duixiang->informationwrite(5,false);
        qDebug()<<"camera_5(横梁) detection failed";
        qDebug()<<"pianyi:"<<pianyi;
        return_bool=false;
    }


    if(if_return_55){

        emit duixiang->sendclientresult("CAM5ACT2",result,true);
        if_return_55=false;

    }

    emit duixiang->sendresult(dst,duixiang->result);
    return return_bool;

}

bool VisionMeasure::camera_measure_5(Mat src, VisionMeasure *duixiang)
{
    return true;
}
bool VisionMeasure::camera_measure_6(Mat src,VisionMeasure *duixiang)
{

    //统计像素
    Mat ROI_img(src, Rect(150,85,70,125));
    // Mat ROI_img=src;

    bool if_exception=true;
    Mat dst=src.clone();

    //统计像素
    int count=1;
    for(int i=0;i<ROI_img.rows;i++){
        for(int j=0;j<ROI_img.cols;j++){
            if(ROI_img.at<uchar>(i,j)<50){
                count++;

            }
        }

    }
      cout<<"xiangsu:"<<count<<endl;

    cvtColor(dst, dst, COLOR_GRAY2RGB);

    cv::rectangle(dst,Point(150,85),Point(220,210),cv::Scalar(0,255,0),4,LINE_8);
    QByteArray result;
        if(count>cam_threshold[7][0]){
        emit  duixiang->informationwrite(8,true);
        result.append("T");
        emit duixiang->sendclientresult("CAM6ACT2",result,true);
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">camera_6 detection successful</font>");
        cv::putText(dst,"Detection successful",Point(dst.cols-350,30),cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(0,255,0),2,LINE_8);
        qDebug()<<"camera_6 detection successful";
    }else{
        emit  duixiang->informationwrite(8,false);
        result.append("F");
        emit duixiang->sendclientresult("CAM6ACT2",result,true);
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">camera_6 detection failed</font>");
        cv::putText(dst,"Detection failed",Point(dst.cols-350,30),cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(255,0,0),2,LINE_8);
        qDebug()<<"camera_6 detection failed";
    }
    if(if_return_6){

        emit duixiang->sendclientresult("CAM6ACT2",result,true);
        if_return_6=false;

    }

    emit duixiang->sendresult(dst,duixiang->result);

    return true;
}

bool VisionMeasure::camera_measure_7(Mat src,VisionMeasure *duixiang)
{


    Mat dst=src.clone();
    if(src.channels()!=3){
        cout<<"channels:"<<src.channels()<<endl;
        cvtColor(dst, dst, COLOR_GRAY2RGB);
        cvtColor(src,src,COLOR_BGR2RGB);
    }


    threshold(src,src,cam_threshold[6][0],255,cam_threshold[6][1]);


    Mat img8bit = Mat::zeros(Size(src.cols, src.rows), CV_8UC1);
    for (int i = 0; i < src.rows; i++)
    {
        uchar* data = src.ptr<uchar>(i);
        for (int j = 0; j < src.cols * 3; j = j + 3)
        {
            img8bit.at<uchar>(i, j / 3) = data[j];
        }
    }

    RNG rng(10086);
    Mat out,stats,centroids;
    int number=connectedComponentsWithStats(img8bit,out,stats,centroids,8,CV_16U);
    cout<<"number:"<<number<<endl;
    vector<Vec3b>colors;
    for(int i=0;i<number;i++){
        Vec3b vec3=Vec3b(rng.uniform(0,256),rng.uniform(0,256),rng.uniform(0,256));
        colors.push_back(vec3);

    }
    Mat result2=Mat::zeros(src.size(),src.type());
    int w=result2.cols;
    int h=result2.rows;
    int centerx=0;
    int centery=0;
    duixiang->date.clear();
    for(int i=1;i<number;i++){
        int center_x=centroids.at<double>(i,0);
        int center_y=centroids.at<double>(i,1);
        double x=stats.at<int>(i,CC_STAT_LEFT);
        double y=stats.at<int>(i,CC_STAT_TOP);
        int w=stats.at<int>(i,CC_STAT_WIDTH);
        int h=stats.at<int>(i,CC_STAT_HEIGHT);
        int area=stats.at<int>(i,CC_STAT_AREA);


        if(area>cam_threshold[6][2]&&area<cam_threshold[6][3]){

            circle(dst,Point(center_x,center_y),2,Scalar(0,255,0),2,8,0);
            Rect rect(x,y,w,h);
            rectangle(dst,rect,colors[i],3,8,0);
            putText(dst,format("%d",i),Point(center_x,center_y),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,255),1);

            cout<<"number:"<<i<<",x:"<<x<<",y:"<<y<<",width:"<<w<<",height"<<h<<",area:"<<area<<endl;
            //            vector<float> datee;
            //            datee.push_back(x);
            //            datee.push_back(y);
            //            datee.push_back(area);
            //            date.push_back(datee);
            vector<float> datee;
            datee.push_back(x+w/2);
            datee.push_back(y+h/2);
            datee.push_back(1);
            duixiang->date.push_back(datee);
        }

    }
    cout<<"count1:"<<duixiang->date.size()<<endl;
    cout<<"count2:"<<(duixiang->zuobiaolist.size()-1)/2<<endl;
    if(duixiang->date.size()<2||(duixiang->date.size()>(duixiang->zuobiaolist.size()-1)/2)){
        QByteArray result;
        result.append("F");
        result.append(",");
        result.append(QString::number((duixiang->zuobiaolist.size()-1)/2,10));
        result.append(",");
        for(int i=0;i<(duixiang->zuobiaolist.size()-1);i++){
            result.append(QString::number(0));
            //  cout<<i<<"--"<<QString::number(pianyi[i],10,4).toStdString()<<endl;
            if(i<(duixiang->zuobiaolist.size()-1)-1){
                result.append(",");
            }
        }

        if(if_return_7){
            emit  duixiang->informationwrite(7,false);
            emit duixiang->sendclientresult("CAM7ACT2",result,false);
            if_return_7=false;
        }
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Detection failed-Incorrect detection quantity!</font>");

        emit duixiang->sendresult(dst,duixiang->result);
        duixiang->date.clear();
        return false;

    }
    //对点进行排序
    vector<vector<float>>sort_date=duixiang->sort_datee(duixiang->date);
    vector<vector<float>>sort_date_biaozhun=sort_date;
    for(int i=0;i<sort_date.size();i++){
        sort_date_biaozhun[i][0]= (sort_date[i][0]-2748)*2.4/1000;
        sort_date_biaozhun[i][1]= (1836-sort_date[i][1])*2.4/1000;
        //cout<<sort_date_biaozhun[i][0]<<endl;
        //cout<<sort_date_biaozhun[i][1]<<endl;
        //  cout<<getRobotPosition(sort_date_biaozhun[i][0],sort_date_biaozhun[i][1]).second<<endl;
    }



    for(int i=0;i<sort_date.size();i++){
        cv::circle(dst,Point(sort_date[i][0],sort_date[i][1]),15,cv::Scalar(255, 0,0),-1);
        String text="(";
        text.append(to_string(i));
        text.append(")");
        cv::putText(dst,text,Point(sort_date[i][0]-110,sort_date[i][1]-95),cv::FONT_HERSHEY_PLAIN,3,cv::Scalar(0,0,255),8,LINE_8);


    }
    emit duixiang->sendresult(dst,duixiang->result);



    vector<float>pianyi;

    //判断首尾在不在
    double distance_detcetion=sqrt((sort_date_biaozhun[0][0]-sort_date_biaozhun[sort_date_biaozhun.size()-1][0])*(sort_date_biaozhun[0][0]-sort_date_biaozhun[sort_date_biaozhun.size()-1][0])+(sort_date_biaozhun[0][1]-sort_date_biaozhun[sort_date_biaozhun.size()-1][1])*(sort_date_biaozhun[0][1]-sort_date_biaozhun[sort_date_biaozhun.size()-1][1]));
    double distance_biaozhun=sqrt((duixiang->zuobiaolist[1].toDouble()-duixiang->zuobiaolist[duixiang->zuobiaolist.size()-2].toDouble())*(duixiang->zuobiaolist[1].toDouble()-duixiang->zuobiaolist[duixiang->zuobiaolist.size()-2].toDouble())+(duixiang->zuobiaolist[2].toDouble()-duixiang->zuobiaolist[duixiang->zuobiaolist.size()-1].toDouble())*(duixiang->zuobiaolist[2].toDouble()-duixiang->zuobiaolist[duixiang->zuobiaolist.size()-1].toDouble()));
    cout<<"distance1"<<distance_detcetion<<endl;
    cout<<"distance1"<<distance_biaozhun<<endl;
    if(abs(distance_detcetion-distance_biaozhun)<0.2){
        sort_date_biaozhun[0][0]= (sort_date[0][0]-2748)*2.4/1000;
        sort_date_biaozhun[0][1]= (1836-sort_date[0][1])*2.4/1000;
        double pianyi_x=-(sort_date_biaozhun[0][0]-duixiang->zuobiaolist[1].toDouble());
        double pianyi_y=-(sort_date_biaozhun[0][1]-duixiang->zuobiaolist[2].toDouble());
        int count=0;
        for(int i=0;i<(duixiang->zuobiaolist.size()-1)/2;i++){
            sort_date_biaozhun[count][0]= (sort_date[count][0]-2748)*2.4/1000;
            sort_date_biaozhun[count][1]= (1836-sort_date[count][1])*2.4/1000;

            if(abs(pianyi_x-(-(sort_date_biaozhun[count][0]-duixiang->zuobiaolist[i*2+1].toDouble())))>0.2||abs(pianyi_y-(-(sort_date_biaozhun[count][1]-duixiang->zuobiaolist[i*2+2].toDouble())))>0.2){
                pianyi.push_back(0);
                pianyi.push_back(0);
                // cout<<i<<"bbbbb"<<endl;

            }else{
                pianyi.push_back(duixiang->zuobiaolist[i*2+1].toDouble()-sort_date_biaozhun[count][0]);
                pianyi.push_back(duixiang->zuobiaolist[i*2+2].toDouble()-sort_date_biaozhun[count][1]);
                //                pianyi.push_back(-(sort_date_biaozhun[count][0]-duixiang->zuobiaolist[i*2+1].toDouble()));
                //                pianyi.push_back(-(sort_date_biaozhun[count][1]-duixiang->zuobiaolist[i*2+2].toDouble()));
                // cout<<i<<"aaaaa"<<endl;
                count++;
            }

        }
        //  cout<<"aaa"<<count<<endl;
        // cout<<"aaa"<<(duixiang->zuobiaolist.size()-1)/2<<endl;
        if((duixiang->zuobiaolist.size()-1)/2!=count){
            QByteArray result;
            result.append("F");
            result.append(",");
            result.append(QString::number(pianyi.size()/2,10));
            result.append(",");
            for(int i=0;i<pianyi.size();i++){
                result.append(QString::number(pianyi[i],10,4));
                cout<<i<<"--"<<QString::number(pianyi[i],10,4).toStdString()<<endl;
                if(i<pianyi.size()-1){
                    result.append(",");
                }
            }

            if(if_return_7){
                emit  duixiang->informationwrite(7,false);
                emit duixiang->sendclientresult("CAM7ACT2",result,false);
                if_return_7=false;

            }
            emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Detection successful-Incomplete number of detections!</font>");
            // qDebug() <<"Detection successful-Incomplete number of detections!";
            duixiang->date.clear();
            return false;
        }else{
            QByteArray result;
            result.append("T");
            result.append(",");
            result.append(QString::number(pianyi.size()/2,10));
            result.append(",");
            for(int i=0;i<pianyi.size();i++){
                result.append(QString::number(pianyi[i],10,4));
                cout<<i<<"--"<<QString::number(pianyi[i],10,4).toStdString()<<endl;
                if(i<pianyi.size()-1){
                    result.append(",");
                }
            }

            if(if_return_7){
                emit  duixiang->informationwrite(7,true);
                emit duixiang->sendclientresult("CAM7ACT2",result,true);
                if_return_7=false;

            }
            //  qDebug() <<"Detection successful-Complete number of detections!";
            emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">Detection successful-Complete number of detections!</font>");
            duixiang->date.clear();
            return true;
        }
    }else{

        QByteArray result;
        result.append("F");
        result.append(",");
        result.append(QString::number((duixiang->zuobiaolist.size()-1)/2,10));
        result.append(",");
        for(int i=0;i<(duixiang->zuobiaolist.size()-1);i++){
            result.append(QString::number(0));
            //  cout<<i<<"--"<<QString::number(pianyi[i],10,4).toStdString()<<endl;
            if(i<(duixiang->zuobiaolist.size()-1)-1){
                result.append(",");
            }
        }

        if(if_return_7){
            emit  duixiang->informationwrite(7,false);
            emit duixiang->sendclientresult("CAM7ACT2",result,false);
            if_return_7=false;
        }
        // qDebug() <<"Detection failed-The position of the first and last points is incorrect!";
        emit duixiang->sendlog("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">Detection failed-The position of the first and last points is incorrect!</font>");
        emit duixiang->sendresult(dst,duixiang->result);
        duixiang->date.clear();
        return false;


    }


}
bool VisionMeasure::camera_measure_8()
{
    return true;
}

QPair<float, float> VisionMeasure::getRobotPosition(float x, float y)
{
    QPair<float, float> pair;
    pair.first=(A*x)+B*y+C;
    pair.second=(D*x)+E*y+F;
    return pair;
}





QRectF VisionMeasure::boundingRect(vector<QPoint> result)
{

    QVector<QPointF> vpt;
    vpt.append(result[0]);
    vpt.append(result[2]);
    vpt.append(result[3]);
    vpt.append(result[1]);
    vpt.append(result[4]);
    vpt.append(result[5]);
    vpt.append(result[0]);

    QRectF re = QPolygonF(vpt).boundingRect();
    return QRectF(re.topLeft().x()-5,
                  re.topLeft().y()-5,
                  re.width()+10,
                  re.height()+10);

}

int VisionMeasure::feature_show(cv::Mat& Insp, int model_id)
{
    int cw = 5;
    int cx = Insp.cols / 2;
    int cy = Insp.rows / 2;

    float angle = 0;
    float scale = 1;
    TemplateI templ = get_model_transform(model_id, angle, scale, 1);
    FeatureI* features = templ.features;
    for (int j = 0; j < templ.num_features; j++)
    {
        int r0 = cy + features[j].y;
        int c0 = cx + features[j].x;
        if (r0 >= 0 && c0 >= 0 && r0 < Insp.rows && c0 < Insp.cols)
        {
            int c = 0;
            float x = features[j].x;
            float y = features[j].y;
            Insp.at<cv::Vec3b>(r0, c0) = cv::Vec3b(0, 255, 0);
        }

    }
    clear_mems(templ.mem_id);
    return 0;
}

int VisionMeasure::match_show(Mat& Insp, int model_id, int x0, int y0, Match* pMatches, int count, int subpixel )
{
    cout<<count<<"count"<<endl;
    camera_angle_1=0;
    camera_dx_1=0;
    camera_dy_1=0;
    camera_score_1= 0;
    if(date.size()>0){
        date.clear();
    }


    try {



        if (count > 0)
        {
            int p = 0;
            int cw = 5;
            for (int i = 0; i < count; i++)
            {

                float angle = pMatches[i].angle;
                float scale = pMatches[i].scale;
                float scale2 = pMatches[i].scale2;
                TemplateI templ = get_model_transform_s(model_id, angle, scale, scale2, 1);
                int tl_x = templ.tl_x;
                int tl_y = templ.tl_y;
                FeatureI* features = templ.features;
                float cy = pMatches[i].y + pMatches[i].dy;
                float cx = pMatches[i].x + pMatches[i].dx;

                for (int j = 0; j < templ.num_features; j++)
                {
                    int r0 = round(cy + features[j].y + y0);
                    int c0 = round(cx + features[j].x + x0);
                    if (r0 >= 0 && c0 >= 0 && r0 < Insp.rows && c0 < Insp.cols)
                        Insp.at<Vec3b>(r0, c0) = Vec3b(0, 255, 0);
                }

                int r0 = round(cy + y0);
                int c0 = round(cx + x0);
                if (r0 >= 0 && c0 >= 0 && r0 < Insp.rows && c0 < Insp.cols)
                {
                    line(Insp, Point(c0 - cw, r0), Point(c0 + cw, r0), Scalar(0, 0, 255), 1);
                    line(Insp, Point(c0, r0 - cw), Point(c0, r0 + cw), Scalar(0, 0, 255), 1);
                    //Insp.at<Vec3b>(r0, c0) = Vec3b(0, 255, 0);

                    string str_score = format("%.3f", pMatches[i].score);
                    cv::putText(Insp, str_score,Point(pMatches[i].x + x0 + tl_x + 10, pMatches[i].y + y0 + tl_y), FONT_HERSHEY_TRIPLEX, 1, cv::Scalar(0, 0, 255));
                    if((cx>900&&cx<1500)&&(cy>650&&cy<1400)){
                        camera_angle_1=pMatches[i].angle*M_PI/180;
                        camera_dx_1=cx;
                        camera_dy_1=cy;
                        camera_score_1= pMatches[i].score;
                    }

                    if (subpixel > 0)
                        printf("i=%3d, x=%8.3f, y=%8.3f, 角度=%8.3f, 尺度x=%8.3f, 尺度y=%8.3f, 得分=%5.3f\n", i + 1, cx, cy, pMatches[i].angle, pMatches[i].scale, pMatches[i].scale2, pMatches[i].score);
                    else
                        printf("i=%3d, x=%4d, y= %4d, 角度=%8.3f, 尺度x=%8.3f, 尺度y=%8.3f, 得分=%5.3f\n", i + 1, pMatches[i].x, pMatches[i].y, pMatches[i].angle, pMatches[i].scale, pMatches[i].scale2, pMatches[i].score);
                }
                clear_mems(templ.mem_id);
            }
        }
    } catch (...) {
        cout<<"fault!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        camera_angle_1=0;
        camera_dx_1=0;
        camera_dy_1=0;
        camera_score_1= 0;
    }
    return 0;
}
vector<QPoint> VisionMeasure::coordinatetransformation(double dx, double dy, double angle,double x1,double y1,double x2,double y2,double a1,double b1,double a2,double b2,double a3,double b3,double a4,double b4)
{
    QTransform t(1,0,0,0,1,0,0,0,1);
    QTransform t2(1,0,dy,0,1,dx,0,0,1);
    QTransform t3=Transformchengfa(t2,t);
    /* cout<<"after translation"<<endl;
    cout<<t3.m11()<<endl;
    cout<<t3.m12()<<endl;
    cout<<t3.m13()<<endl;
    cout<<t3.m21()<<endl;
    cout<<t3.m22()<<endl;
    cout<<t3.m23()<<endl;
    cout<<t3.m31()<<endl;
    cout<<t3.m32()<<endl;
    cout<<t3.m33()<<endl;
    cout <<"*********"<<endl;*/
    QTransform t4(1,0,-dy,0,1,-dx,0,0,1);
    QTransform t5=Transformchengfa(t4,t3);
    /*cout <<"rotate 1"<<endl;
    cout<<t5.m11()<<endl;
    cout<<t5.m12()<<endl;
    cout<<t5.m13()<<endl;
    cout<<t5.m21()<<endl;
    cout<<t5.m22()<<endl;
    cout<<t5.m23()<<endl;
    cout<<t5.m31()<<endl;
    cout<<t5.m32()<<endl;
    cout<<t5.m33()<<endl;
    cout <<"*********"<<endl;*/
    QTransform t6(cos(angle),-sin(angle),0,sin(angle),cos(angle),0,0,0,1);
    QTransform t7=Transformchengfa(t6,t5);
    /*cout <<"rotate 2"<<endl;
    cout<<t7.m11()<<endl;
    cout<<t7.m12()<<endl;
    cout<<t7.m13()<<endl;
    cout<<t7.m21()<<endl;
    cout<<t7.m22()<<endl;
    cout<<t7.m23()<<endl;
    cout<<t7.m31()<<endl;
    cout<<t7.m32()<<endl;
    cout<<t7.m33()<<endl;
    cout <<"*********"<<endl;*/
    QTransform t8(1,0,dy,0,1,dx,0,0,1);
    QTransform t9=Transformchengfa(t8,t7);
    /*cout <<"rotate 3"<<endl;
    cout<<t9.m11()<<endl;
    cout<<t9.m12()<<endl;
    cout<<t9.m13()<<endl;
    cout<<t9.m21()<<endl;
    cout<<t9.m22()<<endl;
    cout<<t9.m23()<<endl;
    cout<<t9.m31()<<endl;
    cout<<t9.m32()<<endl;
    cout<<t9.m33()<<endl;
    cout <<"*********"<<endl;*/
    QTransform t10(t9.m11(),t9.m21(),t9.m31(),t9.m12(),t9.m22(),t9.m32(),t9.m13(),t9.m23(),t9.m33());
    QPoint linestart_=t10.map(QPoint(x1,y1));
    QPoint lineend_=t10.map(QPoint(x2,y2));
    QPoint bound_1_=t10.map(QPoint(a1,b1));
    QPoint bound_2_=t10.map(QPoint(a2,b2));
    QPoint bound_3_=t10.map(QPoint(a3,b3));
    QPoint bound_4_=t10.map(QPoint(a4,b4));

    QPoint linestart;
    QPoint lineend;
    QPoint bound_1;
    QPoint bound_2;
    QPoint bound_3;
    QPoint bound_4;

    linestart.setX(linestart_.y());
    linestart.setY(linestart_.x());
    lineend.setX(lineend_.y());
    lineend.setY(lineend_.x());
    bound_1.setX(bound_1_.y());
    bound_1.setY(bound_1_.x());
    bound_2.setX(bound_2_.y());
    bound_2.setY(bound_2_.x());
    bound_3.setX(bound_3_.y());
    bound_3.setY(bound_3_.x());
    bound_4.setX(bound_4_.y());
    bound_4.setY(bound_4_.x());
    //    cout<<"linestart_x:"<<linestart.x()<<endl;
    //    cout<<"linestart_y:"<<linestart.y()<<endl;
    //    cout<<"lineend_x:"<<lineend.x()<<endl;
    //    cout<<"lineend_y:"<<lineend.y()<<endl;
    vector<QPoint> findlinezuobiao;
    findlinezuobiao.push_back(linestart);
    findlinezuobiao.push_back(lineend);
    findlinezuobiao.push_back(bound_1);
    findlinezuobiao.push_back(bound_2);
    findlinezuobiao.push_back(bound_3);
    findlinezuobiao.push_back(bound_4);
    return findlinezuobiao;


}

vector<QPoint> VisionMeasure::real_coordinatetransformation(double dx, double dy, double angle, double x1, double y1, double x2, double y2, double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4)
{
    QTransform t1(1,0,-dy,0,1,-dx,0,0,1);
    QTransform t2(cos(angle),sin(angle),0,-sin(angle),cos(angle),0,0,0,1);
    QTransform t3=Transformchengfa(t2,t1);
    //    cout<<t3.m11()<<endl;
    //    cout<<t3.m12()<<endl;
    //    cout<<t3.m13()<<endl;
    //    cout<<t3.m21()<<endl;
    //    cout<<t3.m22()<<endl;
    //    cout<<t3.m23()<<endl;
    //    cout<<t3.m31()<<endl;
    //    cout<<t3.m32()<<endl;
    //    cout<<t3.m33()<<endl;
    //  QTransform t14(0.7932,0.608,-1772.68,-0.608,0.7932,667.0309,0,0,1);
    QTransform t5(t3.m11(),t3.m21(),t3.m31(),t3.m12(),t3.m22(),t3.m32(),t3.m13(),t3.m23(),t3.m33());
    QPoint linestart_=t5.map(QPoint(y1,x1));
    QPoint lineend_=t5.map(QPoint(y2,x2));
    QPoint bound_1_=t5.map(QPoint(b1,a1));
    QPoint bound_2_=t5.map(QPoint(b2,a2));
    QPoint bound_3_=t5.map(QPoint(b3,a3));
    QPoint bound_4_=t5.map(QPoint(b4,a4));

    QPoint linestart;
    QPoint lineend;
    QPoint bound_1;
    QPoint bound_2;
    QPoint bound_3;
    QPoint bound_4;

    /* linestart.setX(linestart_.y());
     linestart.setY(linestart_.x());
     lineend.setX(lineend_.y());
     lineend.setY(lineend_.x());
     bound_1.setX(bound_1_.y());
     bound_1.setY(bound_1_.x());
     bound_2.setX(bound_2_.y());
     bound_2.setY(bound_2_.x());
     bound_3.setX(bound_3_.y());
     bound_3.setY(bound_3_.x());
     bound_4.setX(bound_4_.y());
     bound_4.setY(bound_4_.x());*/
    //    cout<<"linestart_x:"<<linestart.x()<<endl;
    //    cout<<"linestart_y:"<<linestart.y()<<endl;
    //    cout<<"end_x:"<<lineend.x()<<endl;
    //    cout<<"end_y:"<<lineend.y()<<endl;

    vector<QPoint> findlinezuobiao;
    findlinezuobiao.push_back(linestart_);
    findlinezuobiao.push_back(lineend_);
    findlinezuobiao.push_back(bound_1_);
    findlinezuobiao.push_back(bound_2_);
    findlinezuobiao.push_back(bound_3_);
    findlinezuobiao.push_back(bound_4_);
    return findlinezuobiao;
}

QTransform VisionMeasure::Transformchengfa(QTransform t1, QTransform t2)
{


    double a11=t1.m11()*t2.m11()+t1.m12()*t2.m21()+t1.m13()*t2.m31();
    double a12=t1.m11()*t2.m12()+t1.m12()*t2.m22()+t1.m13()*t2.m32();
    double a13=t1.m11()*t2.m13()+t1.m12()*t2.m23()+t1.m13()*t2.m33();
    double a21=t1.m21()*t2.m11()+t1.m22()*t2.m21()+t1.m23()*t2.m31();
    double a22=t1.m21()*t2.m12()+t1.m22()*t2.m22()+t1.m23()*t2.m32();
    double a23=t1.m21()*t2.m13()+t1.m22()*t2.m23()+t1.m23()*t2.m33();
    double a31=t1.m31()*t2.m11()+t1.m32()*t2.m21()+t1.m33()*t2.m31();
    double a32=t1.m31()*t2.m12()+t1.m32()*t2.m22()+t1.m33()*t2.m32();
    double a33=t1.m31()*t2.m13()+t1.m32()*t2.m23()+t1.m33()*t2.m33();
    QTransform t(a11,a12,a13,a21,a22,a23,a31,a32,a33);



    return t;

}

vector<Point> VisionMeasure::findline(QPoint start, QPoint end, QImage image, Mat srcImage,double length,QRectF rect,double scale_parameter_1,double scale_parameter_2,int threshold,int polarity,int num)
{
    QPointF pt_begin=start;
    //   cout << "开始点:"<< pt_begin.x()<<"-"<<pt_begin.y()<<endl;
    QPointF pt_end=end;
 //     cout << "结束:"<< pt_end.x()<<"-"<<pt_end.y()<<endl;
    qreal length_new = sqrt((pt_begin.x()-pt_end.x())*(pt_begin.x()-pt_end.x()) +
                            (pt_begin.y()-pt_end.y())*(pt_begin.y()-pt_end.y()));
    qreal scale = length_new/length;
    cv::Point pt_begin_cv = cv::Point(pt_begin.x(),pt_begin.y());
    cv::Point pt_end_cv = cv::Point(pt_end.x(),pt_end.y());
    cv::Rect bound_caliber(rect.topLeft().x(),
                           rect.topLeft().y(),
                           rect.width(),rect.height());
    //  cv::Rect bound_caliber(start.x()+x1,start.y()+y1,x2,y2);
    cv::Rect bound_src(0,0,image.width(),image.height());
    cv::Rect roi = get_IOU(bound_caliber,bound_src);
    m_plineCaliperGUI = new CLineCaliperGUI();
    Mat src2= srcImage(roi).clone();
    cv::Point pt_begin_cv2 = pt_begin_cv - roi.tl();
    cv::Point pt_end_cv2 = pt_end_cv - roi.tl();


    m_plineCaliperGUI->createLineKaChi(src2, pt_begin_cv2, pt_end_cv2,
                                       scale_parameter_1*scale,
                                       scale_parameter_2*scale,
                                       1,threshold,
                                       polarity,
                                       num);
    Point2d pdLineStart(0, 0), pdLineEnd(0, 0);
    double dAngle = 0;
    m_plineCaliperGUI->lineEdgePointSetsFit(pdLineStart, pdLineEnd, dAngle);
    delete  m_plineCaliperGUI;
    cv::Point point1, point2;
    point1.x = pdLineStart.x + roi.tl().x;
    point1.y = pdLineStart.y + roi.tl().y;
    point2.x=pdLineEnd.x + roi.tl().x;
    point2.y=pdLineEnd.y + roi.tl().y;
    vector<Point>line;
    line.push_back(point1);
    line.push_back(point2);
    return line;

    /*  Mat image2= imread("C:/Users/35843/Desktop/test/test4/1.bmp",IMREAD_GRAYSCALE);
    cv::Point point1, point2;
    point1.x = pdLineStart.x + roi.tl().x;
    point1.y = pdLineStart.y + roi.tl().y;
    point2.x=pdLineEnd.x + roi.tl().x;
    point2.y=pdLineEnd.y + roi.tl().y;


    cout<<"start_x"<<pdLineStart.x + roi.tl().x<<endl;
    cout<<"start_y"<<pdLineStart.y + roi.tl().y<<endl;
    cout<<"end_x"<<pdLineEnd.x + roi.tl().x<<endl;
    cout<<"end_y"<<pdLineEnd.y + roi.tl().y<<endl;*/


}


Rect VisionMeasure::get_IOU(cv::Rect rect1, cv::Rect rect2)
{

    cv::Point center_rect1 = (rect1.tl()+rect1.br()) * 0.5;
    cv::Point center_rect2 = (rect2.tl()+rect2.br()) * 0.5;
    auto verti_dis = abs(center_rect1.x - center_rect2.x);
    auto horiz_dis = abs(center_rect1.y - center_rect2.y);

    auto half_w = (rect1.width + rect2.width) / 2;
    auto half_y = (rect1.height + rect2.height) / 2;


    if ( horiz_dis < half_y && verti_dis < half_w) {
        int x_tl , x_br, y_tl, y_br;

        if(rect1.tl().x > rect2.tl().x){
            if(rect1.br().x > rect2.br().x){
                x_tl = rect1.tl().x;
                x_br = rect2.br().x;
            } else{
                x_tl = rect1.tl().x;
                x_br = rect1.br().x;
            }
        } else{
            if(rect1.br().x > rect2.br().x){
                x_tl = rect2.tl().x;
                x_br = rect2.br().x;
            } else{
                x_tl = rect2.tl().x;
                x_br = rect1.br().x;
            }
        }


        if(rect1.tl().y > rect2.tl().y){
            if(rect1.br().y > rect2.br().y){
                y_tl = rect1.tl().y;
                y_br = rect2.br().y;
            } else{
                y_tl = rect1.tl().y;
                y_br = rect1.br().y;
            }
        } else{
            if(rect1.br().y > rect2.br().y){
                y_tl = rect2.tl().y;
                y_br = rect2.br().y;
            } else{
                y_tl = rect2.tl().y;
                y_br = rect1.br().y;
            }
        }

        cv::Point tl(x_tl, y_tl);
        cv::Point br(x_br, y_br);
        return cv::Rect(tl, br);

    }
    return cv::Rect(cv::Point(0,0),cv::Point(0,0) );

}
//两点的距离
double VisionMeasure::getDistance(Point2f pointO, Point2f pointA)
{
    double distance;
    distance = powf(double(pointO.x - pointA.x), 2) + powf(double(pointO.y - pointA.y), 2);
    distance = sqrtf(distance);
    return distance;
}
//点到直线的距离
double VisionMeasure::getDist_P2L(Point2f pointP, Point2f pointA, Point2f pointB)
{
    int A = 0, B = 0, C = 0;
    A = pointA.y - pointB.y;
    B = pointB.x - pointA.x;
    C = pointA.x*pointB.y - pointA.y*pointB.x;

    double distance = 0;
    distance = ((double)abs(A*pointP.x + B * pointP.y + C)) / ((double)sqrtf(A*A + B * B));
    return distance;
}
// 计算垂足的坐标
Point VisionMeasure::calculate_foot_point(vector<Point> ps)
{
    Point p(0, 0);                // 垂足
    if (ps[1].x == ps[2].x) // 线与x轴垂直
    {
        p.x = ps[1].x;
        p.y = ps[0].y;
    }
    else if (ps[1].y == ps[2].y) // 线与y轴垂直
    {
        p.x = ps[0].x;
        p.y = ps[1].y;
    }
    else // 线与x轴，y轴都不垂直
    {
        double a1 = -(double(ps[2].y) - double(ps[1].y));
        double b1 = double(ps[2].x) - double(ps[1].x);
        double c1 = (double(ps[2].y) - double(ps[1].y)) * double(ps[1].x) - (double(ps[2].x) - double(ps[1].x)) * double(ps[1].y);
        p.x = (b1 * b1 * ps[0].x - a1 * b1 * ps[0].y - a1 * c1) / (a1 * a1 + b1 * b1);
        p.y = (a1 * a1 * ps[0].y - a1 * b1 * ps[0].x - b1 * c1) / (a1 * a1 + b1 * b1);
    }
    return p;
}

double VisionMeasure::measureangle(Point x1, Point y1, Point x2, Point y2)
{
    if(x1.x==y1.x){
        return  90.0;
    }
    double k1 = (double(y1.y) - double(x1.y))/(double(y1.x) - double(x1.x));
    double k2 = (double(y2.y) - double(x2.y))/(double(y2.x) - double(x2.x));
    double k = (k2 - k1) / (1 + k1 * k2);


    double angle = atan(k) * 180 / M_PI;
    return angle;

}
Mat VisionMeasure::gray2rainbow(const Mat& scaledGray)
{
    Mat outputRainbow(scaledGray.size(), CV_8UC3);
    unsigned char grayValue;
    for (int y = 0; y < scaledGray.rows; y++)
        for (int x = 0; x < scaledGray.cols; x++)
        {
            grayValue = scaledGray.at<uchar>(y, x);
            Vec3b& pixel = outputRainbow.at<Vec3b>(y, x);
            //对灰度值进行分阶段处理，让色彩更丰富
            if (grayValue <= 51)
            {
                pixel[0] = 255;
                pixel[1] = grayValue * 5;
                pixel[2] = 0;
            }
            else if (grayValue <= 102)
            {
                grayValue -= 51;
                pixel[0] = 255 - grayValue * 5;
                pixel[1] = 255;
                pixel[2] = 0;
            }
            else if (grayValue <= 153)
            {
                grayValue -= 102;
                pixel[0] = 0;
                pixel[1] = 255;
                pixel[2] = grayValue * 5;
            }
            else if (grayValue <= 204)
            {
                grayValue -= 153;
                pixel[0] = 0;
                pixel[1] = 255 - static_cast<unsigned char>(grayValue * 128.0 / 51 + 0.5);
                pixel[2] = 255;
            }
            else if (grayValue <= 255)
            {
                grayValue -= 204;
                pixel[0] = 0;
                pixel[1] = 127 - static_cast<unsigned char>(grayValue * 127.0 / 51 + 0.5);
                pixel[2] = 255;
            }
        }

    return outputRainbow;
}
cv::Point2f VisionMeasure::getCrossPoint(cv::Point2f point_1, cv::Point2f point_2, cv::Point2f point_3, cv::Point2f point_4) {
    //计算点1，2形成直线与点3，4形成直线交点
    //如果平行或有无穷个交点就取点2和3的中间点
    double x, y;
    double X1 = point_1.x - point_2.x, Y1 = point_1.y - point_2.y, X2 = point_3.x - point_4.x, Y2 = point_3.y - point_4.y;
    // cout<<X1<<endl;
    //(点1.x-x)/（点1.y-y)=X1/Y1
    //（点1.x-x）Y1=X1(点1.y-y)
    //X1*y=(Y1*x+X1*点1.y-Y1*点1.x)
    //X2*y=(Y2*x+X2*点3.y-Y2*点3.x)
    if (X1*Y2 == X2*Y1)return cv::Point2f((point_2.x + point_3.x) / 2, (point_2.y + point_3.y) / 2);

    double A = X1*point_1.y - Y1*point_1.x, B = X2*point_3.y - Y2*point_3.x;
    //X1*y=(Y1*x+A)
    //X2*y=(Y2*x+B)
    y = (A*Y2 - B*Y1) / (X1*Y2 - X2*Y1);
    x = (B*X1 - A*X2) / (Y1*X2 - Y2*X1);
    //  cout<<x<<endl;
    return cv::Point2f(x, y);
}

void VisionMeasure::measureyuzhi(Mat src)
{
    Mat dx,dy,mag;
    Mat img_sobel=src.clone();
    Sobel(img_sobel,dx,CV_32F,1,0,3,0.25,0.0,BORDER_DEFAULT);
    Sobel(img_sobel,dy,CV_32F,1,0,3,0.25,0.0,BORDER_DEFAULT);
    cv::magnitude(dx,dy,mag);
    mag.convertTo(mag,CV_8UC1);
    Mat dst;
    double high=cv::threshold(mag,dst,0,255,cv::THRESH_OTSU|cv::THRESH_BINARY);
    double low=high*0.8;
    cout<<"high:"<<high<<endl;
    cout<<"high:"<<low<<endl;
}
vector<vector<float> > VisionMeasure::sort_datee(vector<vector<float> > date)
{



    vector<vector<float> > sort_date;
    vector<Point> posP;
    for(int i=0;i<date.size();i++){
        posP.push_back(Point(date[i][0],date[i][1]));
    }
    vector<vector<Point>> point_all;
    vector<Point> point_row;
    point_all.clear();
    point_row.clear();
    int IErr = 120;

    for(unsigned int i = 0; i < posP.size();i++)
    {
        for(unsigned int j =i+1;j<posP.size();j++)
        {
            if(abs( posP.at(i).y - posP.at(j).y)<= IErr )
            {
                point_row.push_back(posP.at(j));
                posP.erase(posP.begin()+j);
                j--;
            }
        }
        point_row.push_back(posP.at(i));//最后将比较的点放入Vector
        //cout << "size:" << point_row.size() << endl;
        int count=0;
        for(int i=0;i<point_row.size()-1;i++){
            for(int j=1;j<point_row.size()-count;j++){
                if(point_row[j-1].x>point_row[j].x){
                    Point mid=point_row[j-1];
                    point_row[j-1]=point_row[j];
                    point_row[j]=mid;

                }
            }
            count++;
        }
        // cout << point_row.at(k)<< endl;
        //将同一行的点位放入vector
        point_all.push_back(point_row);
        point_row.clear();	//清空，准备下一次排序


    }


    int count=0;
    for(int i=0;i<point_all.size()-1;i++){
        for(int j=1;j<point_all.size()-count;j++){
            if(point_all[j-1].at(0).y>point_all[j].at(0).y){
                vector<Point> mid=point_all[j-1];
                point_all[j-1]=point_all[j];
                point_all[j]=mid;

            }
        }
        count++;
    }
    //    int count2=1;
    //    for(int i=0;i<point_all.size()-1;i++){
    //        for(int j=0;j<point_all[i].size();j++){
    //            cout<<count2<<"--"<<point_all[i].at(j).x<<"--"<<point_all[i].at(j).y<<endl;

    //        }
    //        count2++;
    //    }


    for(int i=0;i<point_all.size();i++){
        for(int j=0;j<point_all[i].size();j++){
            vector<float> mid;
            mid.push_back(point_all[i].at(j).x);
            mid.push_back(point_all[i].at(j).y);
            sort_date.push_back(mid);
        }


    }

    return sort_date;

}

void VisionMeasure::getmeasurecanshu()
{

    QSettings settings("./measure.ini",QSettings::IniFormat);

    // int num =  settings.beginReadArray("aaaa");
    //相机一
    //   cout<<"**************"<<"cam1111111"<<"******************"<<endl;
    for (int i = 0; i <6; ++i) {
        int num =  settings.beginReadArray("cam1_"+QString::number(i+1)+"_line");
        for (int j = 0; j < 21; ++j) {
            settings.setArrayIndex(j);
            cam1_findlinearray[i][j]=settings.value("cam1", "0").toDouble();
            //std::cout<<"array[i][j]"<<settings.value("cam1", "0").toDouble()<<std::endl;
        }
        settings.endArray();
    }

    //    for (int i = 0; i < sizeof(cam1_findlinearray) / sizeof(cam1_findlinearray[0]); ++i) {
    //        for (int j = 0; j < sizeof(cam1_findlinearray[0]) / sizeof(cam1_findlinearray[0][0]); ++j) {
    //            std::cout<<i+1<<"******"<<j+1<<"*******"<<cam1_findlinearray[i][j]<<std::endl;
    //        }
    //        std::cout<<std::endl;
    //    }
    //相机2
    //   cout<<"**************"<<"cam22222222"<<"******************"<<endl;
    for (int i = 0; i <6; ++i) {
        int num =  settings.beginReadArray("cam2_"+QString::number(i+1)+"_line");
        for (int j = 0; j < 18; ++j) {
            settings.setArrayIndex(j);
            cam2_findlinearray[i][j]=settings.value("cam2", "0").toDouble();
            //std::cout<<"array[i][j]"<<settings.value("cam2", "0").toDouble()<<std::endl;
        }
        settings.endArray();
    }

    //    for (int i = 0; i < sizeof(cam2_findlinearray) / sizeof(cam2_findlinearray[0]); ++i) {
    //        for (int j = 0; j < sizeof(cam2_findlinearray[0]) / sizeof(cam2_findlinearray[0][0]); ++j) {
    //            std::cout<<i+1<<"******"<<j+1<<"*******"<<cam2_findlinearray[i][j]<<std::endl;
    //        }
    //        std::cout<<std::endl;
    //    }
    //    //相机3
    //    cout<<"**************"<<"cam333333333"<<"******************"<<endl;
    for (int i = 0; i <6; ++i) {
        int num =  settings.beginReadArray("cam3_"+QString::number(i+1)+"_line");
        for (int j = 0; j < 18; ++j) {
            settings.setArrayIndex(j);
            cam3_findlinearray[i][j]=settings.value("cam3", "0").toDouble();
            //std::cout<<"array[i][j]"<<settings.value("cam3", "0").toDouble()<<std::endl;
        }
        settings.endArray();
    }

    //    for (int i = 0; i < sizeof(cam3_findlinearray) / sizeof(cam3_findlinearray[0]); ++i) {
    //        for (int j = 0; j < sizeof(cam3_findlinearray[0]) / sizeof(cam3_findlinearray[0][0]); ++j) {
    //            std::cout<<i+1<<"******"<<j+1<<"*******"<<cam3_findlinearray[i][j]<<std::endl;
    //        }
    //        std::cout<<std::endl;
    //    }

    //    //相机四
    //    cout<<"**************"<<"cam4444444"<<"******************"<<endl;
    for (int i = 0; i <6; ++i) {
        int num =  settings.beginReadArray("cam4_"+QString::number(i+1)+"_line");
        for (int j = 0; j < 18; ++j) {
            settings.setArrayIndex(j);
            cam4_findlinearray[i][j]=settings.value("cam4", "0").toDouble();
            //std::cout<<"array[i][j]"<<settings.value("cam4", "0").toDouble()<<std::endl;
        }
        settings.endArray();
    }

    //    for (int i = 0; i < sizeof(cam4_findlinearray) / sizeof(cam4_findlinearray[0]); ++i) {
    //        for (int j = 0; j < sizeof(cam4_findlinearray[0]) / sizeof(cam4_findlinearray[0][0]); ++j) {
    //            std::cout<<i+1<<"******"<<j+1<<"*******"<<cam4_findlinearray[i][j]<<std::endl;
    //        }
    //        std::cout<<std::endl;
    //    }
    //    //相机5
    //    cout<<"**************"<<"cam5555555555"<<"******************"<<endl;
    for (int i = 0; i <6; ++i) {
        int num =  settings.beginReadArray("cam5_"+QString::number(i+1)+"_line");
        for (int j = 0; j < 18; ++j) {
            settings.setArrayIndex(j);
            cam5_findlinearray[i][j]=settings.value("cam5", "0").toDouble();
            //std::cout<<i<<"----"<<j<<"----"<<cam5_findlinearray[i][j]<<std::endl;
        }
        settings.endArray();
    }
    //   std::cout<<"----"<<"----"<<cam5_findlinearray[1][0]<<std::endl;

    //        for (int i = 0; i < sizeof(cam5_findlinearray) / sizeof(cam5_findlinearray[0]); ++i) {
    //            for (int j = 0; j < sizeof(cam5_findlinearray[0]) / sizeof(cam5_findlinearray[0][0]); ++j) {
    //                std::cout<<i+1<<"******"<<j+1<<"*******"<<cam5_findlinearray[i][j]<<std::endl;
    //            }
    //            std::cout<<std::endl;
    //        }

    //    //相机6
    //    cout<<"**************"<<"cam6666666666666"<<"******************"<<endl;
    for (int i = 0; i <1; ++i) {
        int num =  settings.beginReadArray("cam6_"+QString::number(i+1)+"_line");
        for (int j = 0; j < 18; ++j) {
            settings.setArrayIndex(j);
            cam6_findlinearray[i][j]=settings.value("cam6", "0").toDouble();
            //std::cout<<"array[i][j]"<<settings.value("cam6", "0").toDouble()<<std::endl;
        }
        settings.endArray();
    }
    //  std::cout<<"----"<<"----"<<cam5_findlinearray[1][0]<<std::endl;

    //    for (int i = 0; i < sizeof(cam6_findlinearray) / sizeof(cam6_findlinearray[0]); ++i) {
    //        for (int j = 0; j < sizeof(cam6_findlinearray[0]) / sizeof(cam6_findlinearray[0][0]); ++j) {
    //            std::cout<<i+1<<"******"<<j+1<<"*******"<<cam6_findlinearray[i][j]<<std::endl;
    //        }
    //        std::cout<<std::endl;
    //    }

    //     cout<<"**************"<<"canshu"<<"******************"<<endl;

    //    for (int i = 0; i < sizeof(cam_threshold) / sizeof(cam_threshold[0]); ++i) {
    //        for (int j = 0; j < sizeof(cam_threshold[0]) / sizeof(cam_threshold[0][0]); ++j) {
    //            std::cout<<i+1<<"******"<<j+1<<"*******"<<cam_threshold[i][j]<<std::endl;
    //        }
    //        std::cout<<std::endl;
    //    }

}

void VisionMeasure::getdate(QStringList list)
{

    zuobiaolist.clear();
    zuobiaolist=list;
    //cout<<"zuobiaolistsize:"<<zuobiaolist.size()<<endl;
}

void VisionMeasure::SlotDeliverMessStatic(int num1,int num2)
{
    emit createmodellog(num1,num2);
    cout<<"ssssssssssssss"<<endl;
}





