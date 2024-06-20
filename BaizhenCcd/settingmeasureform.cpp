#include "settingmeasureform.h"
#include "ui_settingmeasureform.h"

SettingMeasureForm::SettingMeasureForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingMeasureForm)
{
    ui->setupUi(this);
    ui->imageLabel->installEventFilter(this);
    measure=new VisionMeasure;
    findlineform=new FinelineForm;
    settingform=new SetParameter;
    settingform->getini();
    // connect(measure,SIGNAL(createmodellog(int)),this,SLOT(getcreatemodellog(int)));
    ui->spinBox->setRange(0,255);
    ui->spinBox_2->setRange(0,255);
    ui->spinBox_3->setRange(0,255);
    connect(measure,&VisionMeasure::createmodellog,this,&SettingMeasureForm::getcreatemodellog);//关联ToolA的信号和Ma
    //相机1找线组

    QButtonGroup *buttonGroup= new QButtonGroup();
    buttonGroup->addButton(ui->line_1_1,1);
    buttonGroup->addButton(ui->line_1_2,2);
    buttonGroup->addButton(ui->line_1_3,3);
    buttonGroup->addButton(ui->line_1_4,4);
    buttonGroup->addButton(ui->line_1_5,5);
    buttonGroup->addButton(ui->line_1_8,6);
    buttonGroup->addButton(ui->line_1_9,7);
    buttonGroup->addButton(ui->line_1_10,8);
    buttonGroup->addButton(ui->line_1_11,9);
    buttonGroup->addButton(ui->line_1_12,10);
    connect(buttonGroup, SIGNAL(buttonToggled(int,bool)), this, SLOT(cam1_linebutton(int,bool)));
    ui->Log->moveCursor(QTextCursor::End);
    QFont font;
    font.setPointSize(12);//字体大小
    ui->Log->setFont(font);
    ui->groupBox->setStyleSheet("border: 1px solid black;background-color: rgb(243, 250, 250);"
                                );
    width=ui->imageLabel->width();
    height=ui->imageLabel->height();



}

SettingMeasureForm::~SettingMeasureForm()
{
    delete ui;
}
bool SettingMeasureForm::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->imageLabel){
        if(event->type() == QEvent::MouseButtonPress){
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton){
                isModify = true;

                //                            QPoint pos;
                //                            pos.setX(x+88);
                //                            pos.setY(y+85);
                //                            QCursor::setPos(pos);

                QPoint pos = QCursor::pos();//获得相对于屏幕的坐标
                QPoint sPoint1 = mouseEvent->globalPos();//获得相对于屏幕的坐标
                QPoint pos2= ui->imageLabel->mapFromGlobal(pos);//获得相对于控件的坐标

                //qDebug()<<"移动后:"<<"x:"<<pos2.x()<<"y:"<<pos2.y();

                x1 = pos2.x();
                y1 = pos2.y();

                return  true;
            }else{
                return false;
            }
        }else if(event->type() == QEvent::MouseMove){
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->buttons() == Qt::LeftButton){
                QPoint pos = QCursor::pos();//获得相对于屏幕的坐标
                //QPoint sPoint1 = mouseEvent->globalPos();//获得相对于屏幕的坐标
                //sPoint1
                QPoint pos2 = ui->imageLabel->mapFromGlobal(pos);//获得相对于控件的坐标
                x2 = pos2.x();
                y2 = pos2.y();

                QPainter painter;
                QImage tempImg = tempTestImg;
                painter.begin(&tempImg);
                painter.setPen(QPen(Qt::red, 2, Qt::DashDotLine, Qt::RoundCap));
                painter.drawRect(x1, y1, x2 - x1, y2 - y1);
                painter.end();
                ui->imageLabel->setPixmap(QPixmap::fromImage(tempImg));
                ifmove=true;

            }else{
                return false;
            }
        }else if(event->type() == QEvent::MouseButtonRelease){
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton){
                QPoint pos = QCursor::pos();//获得相对于屏幕的坐标
                //QPoint sPoint1 = mouseEvent->globalPos();//获得相对于屏幕的坐标
                QPoint pos2= ui->imageLabel->mapFromGlobal(pos);//获得相对于控件的坐标
                x2 = pos2.x();
                y2 = pos2.y();

                QPainter painter;
                QImage tempImg = tempTestImg;
                painter.begin(&tempImg);
                //颜色、线宽、画笔风格、画笔端点风格、画笔连接风格
                painter.setPen(QPen(Qt::red, 2, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));
                painter.drawRect(x1, y1, x2 - x1, y2 - y1);
                painter.end();
                ui->imageLabel->setPixmap(QPixmap::fromImage(tempImg));
                //                cout<<"剪裁后x1:"<<x1<<endl;
                //                cout<<"剪裁后y1:"<<y1<<endl;
                //                cout<<"剪裁后x2:"<<x2<<endl;
                //                cout<<"剪裁后y2:"<<y2<<endl;

                //本地裁剪
                QImage testImg = tempTestImg.copy(x1, y1, x2 - x1, y2 - y1);
                QPixmap resImage = QPixmap::fromImage(testImg);
                // resImage.scaled(ui->imageLabel->size(), Qt::IgnoreAspectRatio);
                ui->imageLabel->setScaledContents(true);
                QSize size;
                size.setWidth(ui->imageLabel->width());
                size.setHeight(ui->imageLabel->height());
                ui->imageLabel->resize(size);
                ui->imageLabel->setPixmap(resImage);

                if(ifmove){
                    QImage test=tempqimage.copy(double(sourceimage.cols)/double(ui->imageLabel->width())*(double)x1,double(sourceimage.rows)/double(ui->imageLabel->height())*double(y1),double(sourceimage.cols)/double(ui->imageLabel->width())*double(x2-x1),double(sourceimage.rows)/double(ui->imageLabel->height())*double(y2-y1));
                    double rate=double(test.width())/double(test.height());
                    if(test.width()>test.height()){
                        QSize size;
                        size.setWidth(180);
                        size.setHeight(180/rate);
                        ui->setlabel_1->resize(size);
                    }else{
                        QSize size;
                        size.setWidth(100*rate);
                        size.setHeight(100);
                        ui->setlabel_1->resize(size);
                    }

                    QPixmap pixmap = QPixmap::fromImage(test);
                    ui->setlabel_1->setPixmap(pixmap);
                    ui->setlabel_1->setScaledContents(true);
                    ifmove=false;
                    //                                        resimage=resImage.copy();
                    //                                        ui->setlabel_1->setPixmap(resimage);
                    //                                         ui->setlabel_1->setScaledContents(true);
                    //                                        ifmove=false;
                }



            }else{
                return false;
            }
        }else{
            return false;
        }
    }else {
        return  QWidget::eventFilter(obj, event);
    }
}

void SettingMeasureForm::init_1()
{
    if(cam_biaoji==1){
        Mat model_1=imread(QApplication::applicationDirPath().toStdString()+VisionMeasure::modelpath_1,0);
        QImage  imgForDisplay = QImage((const uchar*)(model_1.data), model_1.cols, model_1.rows, model_1.cols * model_1.channels(), QImage::Format_Indexed8);
        double rate=double(imgForDisplay.width())/double(imgForDisplay.height());
        if(imgForDisplay.width()>imgForDisplay.height()){
            QSize size;
            size.setWidth(180);
            size.setHeight(180/rate);
            ui->modellabel->resize(size);
        }else{
            QSize size;
            size.setWidth(100*rate);
            size.setHeight(100);
            ui->modellabel->resize(size);
        }
        QPixmap pixmap =QPixmap::fromImage(imgForDisplay);
        ui->modellabel->setPixmap(pixmap);
        ui->modellabel->setScaledContents(true);
    }else if(cam_biaoji==4){
        Mat model_1=imread(QApplication::applicationDirPath().toStdString()+VisionMeasure::modelpath_2,0);
        QImage  imgForDisplay = QImage((const uchar*)(model_1.data), model_1.cols, model_1.rows, model_1.cols * model_1.channels(), QImage::Format_Indexed8);
        double rate=double(imgForDisplay.width())/double(imgForDisplay.height());
        if(imgForDisplay.width()>imgForDisplay.height()){
            QSize size;
            size.setWidth(180);
            size.setHeight(180/rate);
            ui->modellabel->resize(size);
        }else{
            QSize size;
            size.setWidth(100*rate);
            size.setHeight(100);
            ui->modellabel->resize(size);
        }
        QPixmap pixmap =QPixmap::fromImage(imgForDisplay);
        ui->modellabel->setPixmap(pixmap);
        ui->modellabel->setScaledContents(true);
    }else{

        ui->modellabel->clear();
        ui->modellabel->resize(221,151);
        ui->setlabel_1->clear();
        ui->setlabel_1->resize(221,151);
    }

    if(imageData_1.isNull()){
        QMessageBox::critical(this,"critical","image is empty!");
    }else{
        tempqimage=imageData_1.copy();
        imageData_1 =  imageData_1.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QPixmap resImage = QPixmap::fromImage(imageData_1);
        ui->imageLabel->setScaledContents(true);
        QSize size;
        size.setWidth(resImage.width());
        size.setHeight(resImage.height());
        ui->imageLabel->resize(size);
        ui->imageLabel->move((width-resImage.width())/2+10,(height-resImage.height())/2+10);

        ui->imageLabel->setPixmap(resImage);
        tempTestImg = imageData_1;
    }


}

int SettingMeasureForm::feature_show(Mat &Insp, int model_id)
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

int SettingMeasureForm::match_show(Mat &Insp, int model_id, int x0, int y0, Match *pMatches, int count, int subpixel)
{

    camera_angle_1=0;
    camera_dx_1=0;
    camera_dy_1=0;
    camera_score_1= 0;



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


                    camera_angle_1=pMatches[i].angle*M_PI/180;
                    camera_dx_1=cx;
                    camera_dy_1=cy;
                    camera_score_1= pMatches[i].score;



                    if (subpixel > 0)
                        printf("i=%3d, x=%8.3f, y=%8.3f, 角度=%8.3f, 尺度x=%8.3f, 尺度y=%8.3f, 得分=%5.3f\n", i + 1, cx, cy, pMatches[i].angle, pMatches[i].scale, pMatches[i].scale2, pMatches[i].score);
                    else
                        printf("i=%3d, x=%4d, y= %4d, 角度=%8.3f, 尺度x=%8.3f, 尺度y=%8.3f, 得分=%5.3f\n", i + 1, pMatches[i].x, pMatches[i].y, pMatches[i].angle, pMatches[i].scale, pMatches[i].scale2, pMatches[i].score);
                }
                clear_mems(templ.mem_id);
            }
        }
    } catch (...) {

        camera_angle_1=0;
        camera_dx_1=0;
        camera_dy_1=0;
        camera_score_1= 0;
    }
    return 0;
}

Mat SettingMeasureForm::thinImage(Mat src)
{

    threshold(src, src, 140, 1, ThinThresholdTypes);

    Mat dst;

    int width = src.cols;
    int height = src.rows;




    /*for (int i = 0; i < gujia2_x.size(); i++) {
            test.at<uchar>(gujia2_y[i], gujia2_x[i]) =1;

        }*/

    src.copyTo(dst);
    vector<uchar *> mFlag; //用于标记需要删除的点
    while (true)
    {
        //步骤一
        for (int i = 0; i < height; ++i)
        {
            uchar * p = dst.ptr<uchar>(i);
            for (int j = 0; j < width; ++j)
            {
                //获得九个点对象，注意边界问题
                uchar p1 = p[j];
                if (p1 != 1) continue;
                uchar p2 = (i == 0) ? 0 : *(p - dst.step + j);
                uchar p3 = (i == 0 || j == width - 1) ? 0 : *(p - dst.step + j + 1);
                uchar p4 = (j == width - 1) ? 0 : *(p + j + 1);
                uchar p5 = (i == height - 1 || j == width - 1) ? 0 : *(p + dst.step + j + 1);
                uchar p6 = (i == height - 1) ? 0 : *(p + dst.step + j);
                uchar p7 = (i == height - 1 || j == 0) ? 0 : *(p + dst.step + j - 1);
                uchar p8 = (j == 0) ? 0 : *(p + j - 1);
                uchar p9 = (i == 0 || j == 0) ? 0 : *(p - dst.step + j - 1);
                if ((p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) >= 2 && (p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) <= 6)//条件1判断
                {
                    //条件2计算
                    int ap = 0;
                    if (p2 == 0 && p3 == 1) ++ap;
                    if (p3 == 0 && p4 == 1) ++ap;
                    if (p4 == 0 && p5 == 1) ++ap;
                    if (p5 == 0 && p6 == 1) ++ap;
                    if (p6 == 0 && p7 == 1) ++ap;
                    if (p7 == 0 && p8 == 1) ++ap;
                    if (p8 == 0 && p9 == 1) ++ap;
                    if (p9 == 0 && p2 == 1) ++ap;
                    //条件2、3、4判断
                    int bp = 0;
                    bp += p2;
                    bp += p3 << 1;
                    bp += p4 << 2;
                    bp += p5 << 3;
                    bp += p6 << 4;
                    bp += p7 << 5;
                    bp += p8 << 6;
                    bp += p9 << 7;

                    if (ap == 1 || bp == 65 || bp == 5 || bp == 20 || bp == 80 || bp == 13 || bp == 22 || bp == 52 || bp == 133 || bp == 141 || bp == 54) {



                        if (p2 * p4 * p6 == 0 && p4 * p6 * p8 == 0)
                        {
                            mFlag.push_back(p + j);
                        }
                    }

                }
            }
        }
        //将标记的点删除
        for (vector<uchar *>::iterator i = mFlag.begin(); i != mFlag.end(); ++i)
        {
            **i = 0;
        }
        //直到没有点满足，算法结束
        if (mFlag.empty())
        {
            break;
        }
        else
        {
            mFlag.clear();//将mFlag清空
        }

        //步骤二，根据情况该步骤可以和步骤一封装在一起成为一个函数
        for (int i = 0; i < height; ++i)
        {
            uchar * p = dst.ptr<uchar>(i);
            for (int j = 0; j < width; ++j)
            {
                //如果满足四个条件，进行标记
                //  p9 p2 p3
                //  p8 p1 p4
                //  p7 p6 p5
                uchar p1 = p[j];
                if (p1 != 1) continue;
                uchar p2 = (i == 0) ? 0 : *(p - dst.step + j);
                uchar p3 = (i == 0 || j == width - 1) ? 0 : *(p - dst.step + j + 1);
                uchar p4 = (j == width - 1) ? 0 : *(p + j + 1);
                uchar p5 = (i == height - 1 || j == width - 1) ? 0 : *(p + dst.step + j + 1);
                uchar p6 = (i == height - 1) ? 0 : *(p + dst.step + j);
                uchar p7 = (i == height - 1 || j == 0) ? 0 : *(p + dst.step + j - 1);
                uchar p8 = (j == 0) ? 0 : *(p + j - 1);
                uchar p9 = (i == 0 || j == 0) ? 0 : *(p - dst.step + j - 1);
                if ((p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) >= 2 && (p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) <= 6)
                {
                    int ap = 0;
                    if (p2 == 0 && p3 == 1) ++ap;
                    if (p3 == 0 && p4 == 1) ++ap;
                    if (p4 == 0 && p5 == 1) ++ap;
                    if (p5 == 0 && p6 == 1) ++ap;
                    if (p6 == 0 && p7 == 1) ++ap;
                    if (p7 == 0 && p8 == 1) ++ap;
                    if (p8 == 0 && p9 == 1) ++ap;
                    if (p9 == 0 && p2 == 1) ++ap;

                    int bp = 0;
                    bp += p2;
                    bp += p3 << 1;
                    bp += p4 << 2;
                    bp += p5 << 3;
                    bp += p6 << 4;
                    bp += p7 << 5;
                    bp += p8 << 6;
                    bp += p9 << 7;
                    if (ap == 1 || bp == 65 || bp == 5 || bp == 20 || bp == 80 || bp == 13 || bp == 22 || bp == 52 || bp == 133 || bp == 141 || bp == 54) {
                        if (p2 * p4 * p8 == 0 && p2 * p6 * p8 == 0)
                        {
                            //标记
                            mFlag.push_back(p + j);
                        }
                    }
                }
            }
        }
        //将标记的点删除
        for (vector<uchar *>::iterator i = mFlag.begin(); i != mFlag.end(); ++i)
        {
            //printf("%d",**i);
            **i = 0;
        }
        //直到没有点满足，算法结束
        if (mFlag.empty())
        {
            break;
        }
        else
        {
            mFlag.clear();//将mFlag清空
        }
    }
    dst = dst * 255;
    bitwise_not(dst, dst);

    return dst;
}

Mat SettingMeasureForm::blob(Mat src)
{
    //    Mat dst=src.clone();
    if(src.channels()!=3){

        //        cvtColor(dst, dst, COLOR_GRAY2RGB);
        cvtColor(src,src,COLOR_BGR2RGB);
    }


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
    // cout<<"number:"<<number<<endl;
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
    ui->Log->append("<font color=\"#00FF00\">Blob成功结果:</font>");
    int count=0;
    for(int i=1;i<number;i++){
        int center_x=centroids.at<double>(i,0);
        int center_y=centroids.at<double>(i,1);
        double x=stats.at<int>(i,CC_STAT_LEFT);
        double y=stats.at<int>(i,CC_STAT_TOP);
        int w=stats.at<int>(i,CC_STAT_WIDTH);
        int h=stats.at<int>(i,CC_STAT_HEIGHT);
        int area=stats.at<int>(i,CC_STAT_AREA);


        if(area>ui->blobmin->text().toInt()&&area<ui->blobmax->text().toInt()){
            count++;
            circle(src,Point(center_x,center_y),2,Scalar(0,255,0),2,8,0);
            Rect rect(x,y,w,h);
            rectangle(src,rect,colors[i],3,8,0);
            putText(src,format("%d",i),Point(center_x,center_y),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,255),1);

            ui->Log->append("<font color=\"#00FF00\">number:"+QString::number(i)+",x:"+QString::number(x)+",y:"+QString::number(y)+",width:"+QString::number(w)+",height:"+QString::number(h)+",area:"+QString::number(area)+"</font>");


        }

        cout<<"number:"<<i<<",x:"<<x<<",y:"<<y<<",width:"<<w<<",height"<<h<<",area:"<<area<<endl;
    }
     ui->Log->append("<font color=\"#FF0000\">Blob失败结果:</font>");
    for(int i=1;i<number;i++){
        int center_x=centroids.at<double>(i,0);
        int center_y=centroids.at<double>(i,1);
        double x=stats.at<int>(i,CC_STAT_LEFT);
        double y=stats.at<int>(i,CC_STAT_TOP);
        int w=stats.at<int>(i,CC_STAT_WIDTH);
        int h=stats.at<int>(i,CC_STAT_HEIGHT);
        int area=stats.at<int>(i,CC_STAT_AREA);




        ui->Log->append("<font color=\"#FF0000\">number:"+QString::number(i)+",x:"+QString::number(x)+",y:"+QString::number(y)+",width:"+QString::number(w)+",height:"+QString::number(h)+",area:"+QString::number(area)+"</font>");





    }
    ui->Log->append("<font color=\"#0000FF\">Blob结果总数为:"+QString::number(count)+"</font>");
    return src;

}





void SettingMeasureForm::on_updateimage_1_clicked()
{
    emit sendupdateimage(cam_biaoji);
}

void SettingMeasureForm::on_loadimage_1_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/35843/Desktop/test6",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
    //  cout<<fileName.toStdString()<<endl;
    sourceimage=imread(fileName.toStdString(),0);
    cout<<sourceimage.cols<<endl;
    //    if(mat.empty())
    //        QMessageBox::critical(this,"critical","image is empty!");
    //        return;

    imageData_1 = QImage((const uchar*)(sourceimage.data), sourceimage.cols, sourceimage.rows, sourceimage.cols * sourceimage.channels(), QImage::Format_Indexed8);
    QMessageBox::information(this,"info","load image succeed!");

    init_1();
    ui->tabWidget_2->setCurrentIndex(0);

}

void SettingMeasureForm::on_loadmodel_1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/Administrator/Desktop/image",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
    Mat model_1=imread(fileName.toStdString(),0);
    //    if(model_1.empty())
    //        QMessageBox::critical(this,"critical","image is empty!");
    //        return;

    QImage  imgForDisplay = QImage((const uchar*)(model_1.data), model_1.cols, model_1.rows, model_1.cols * model_1.channels(), QImage::Format_Indexed8);
    QPixmap pixmap =QPixmap::fromImage(imgForDisplay);
    ui->modellabel->setPixmap(pixmap);
    ui->modellabel->setScaledContents(true);
    QMessageBox::information(this,"info","load model succeed!");
}

void SettingMeasureForm::on_savemodel_1_clicked()
{

    if(cam_biaoji==1){
        if(ui->modellabel->pixmap()!=nullptr&&!ui->modellabel->pixmap()->isNull()){
            // ui->modellabel->pixmap()->save(QApplication::applicationDirPath()+QString::fromStdString(VisionMeasure::modelpath_1),"bmp",100);
            QPixmap pixmap=ui->modellabel->pixmap()->copy();
            QImage image= pixmap.toImage();
            image.save(QApplication::applicationDirPath()+QString::fromStdString(VisionMeasure::modelpath_1),"bmp",0);

            QMessageBox::information(this,"info","cam_1 save model succeed!");
        }else{
            QMessageBox::critical(this,"critical","model is empty!");
        }
    }else if(cam_biaoji==4){
        if(ui->modellabel->pixmap()!=nullptr&&!ui->modellabel->pixmap()->isNull()){
            QPixmap pixmap=ui->modellabel->pixmap()->copy();
            QImage image= pixmap.toImage();
            image.save(QApplication::applicationDirPath()+QString::fromStdString(VisionMeasure::modelpath_2),"bmp",0);
            QMessageBox::information(this,"info","cam_2 save model succeed!");
        }else{
            QMessageBox::critical(this,"critical","model is empty!");
        }
    }

}

void SettingMeasureForm::on_setmodel_1_clicked()
{

    if(ui->setlabel_1->pixmap()!=nullptr&&!ui->setlabel_1->pixmap()->isNull()){

        QSize size;
        size.setWidth(ui->setlabel_1->width());
        size.setHeight(ui->setlabel_1->height());
        ui->modellabel->resize(size);
        QPixmap pixmap=ui->setlabel_1->pixmap()->copy();
        ui->modellabel->setPixmap(pixmap);
        ui->modellabel->setScaledContents(true);
        QMessageBox::information(this,"info","set model succeed!");
    }else{
        QMessageBox::critical(this,"critical","setmodel is empty!");
    }
}

void SettingMeasureForm::on_trainmodel_clicked()
{
    if(ui->modellabel->pixmap()!=nullptr&&!ui->modellabel->pixmap()->isNull()){

        if(cam_biaoji==1){
            VisionMeasure::loadtemplate(1);
        } else if(cam_biaoji==4){
            VisionMeasure::loadtemplate(2);
        }
    }else{
        QMessageBox::critical(this,"critical","model is empty!");
    }


}
void SettingMeasureForm::on_modelmatch_1_clicked()
{
    if(!sourceimage.data){
        QMessageBox::critical(this,"critical","match image is empty!");
        return;
    }


    Mat dst=sourceimage.clone();


    bool if_exception=true;

    //起始角度
    double angle_start = -180;
    //终止角度
    double angle_extent = 360;
    int subpixel = 1;
    double scale_min = 1;
    double scale_max = 1;
    double minScore = 0.2;
    double maxOverLap = 0;
    double greedness = 0.9;
    int numMatches = 1;

    if (scale_max < scale_min)
    {
        std::cout << "scale min < max" << endl;

    }
    int numLevels[2] = { 6 };
    int mem_id = 0;
    int nFound = 0;
    Match* pMatches = NULL;

    if(cam_biaoji==1){
        //模型查找
        if (abs(scale_min - 1) < DBL_EPSILON && abs(scale_max - 1) < DBL_EPSILON)
        {
            mem_id = find_shape_model(dst.ptr<uchar>(0), dst.cols, dst.rows, VisionMeasure::model_id_1, angle_start, angle_extent, minScore, numMatches, maxOverLap, subpixel, numLevels, greedness, pMatches, nFound);
        }
        else
        {
            mem_id = find_scaled_shape_model(dst.ptr<uchar>(0), dst.cols, dst.rows, VisionMeasure::model_id_1, angle_start, angle_extent, scale_min, scale_max, minScore, numMatches, maxOverLap, subpixel, numLevels, greedness, pMatches, nFound);
        }

        if (mem_id < 0)
        {
            std::cout << "find shape model failed" << endl;

            //   ui->Log->append("cam_1 find shape model failed");
            if_exception=false;
            // return;

        }


        Mat srcRgb;
        cvtColor(dst, srcRgb, COLOR_GRAY2RGB);
        std::cout << "find shape model success" << endl;


        // feature_show(srcRgb,VisionMeasure::model_id_1);
        match_show(srcRgb, VisionMeasure::model_id_1, 0, 0, pMatches, nFound, subpixel);

        vector<double> result2;
        ui->resultimage_1->getresult(srcRgb,result2);

        clear_mems(mem_id);
        cout<<"nFound"<<nFound<<endl;
        if(nFound!=0){
            QMessageBox::information(this,"info","cam_1 find shape model success!");

            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">CAM_1 find shape model success!</font>");
        }else{
            std::cout << "cam_1 find shape model failed" << endl;
            QMessageBox::critical(this,"critical","cam_1 find shape model failed");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">CAM_1 find shape model failed!</font>");
        }
        cout<<"  dx: " <<camera_dx_1<<"  dy: "<<camera_dy_1<<"  angle: "<<camera_angle_1<<"  score: "<<camera_score_1<<endl;
        ui->Log->append("camera_1:");
        ui->Log->append("dx:"+QString::number(camera_dx_1,10,3));
        ui->Log->append("dy:"+QString::number(camera_dy_1,10,3));
        ui->Log->append("angle:"+QString::number(camera_angle_1,10,3));
        ui->Log->append("score:"+QString::number(camera_score_1,10,3));

        //        namedWindow("result",WINDOW_NORMAL);
        //        imshow("result", srcRgb);
        //        waitKey(0);

    }else if(cam_biaoji==4){
        //模型查找
        if (abs(scale_min - 1) < DBL_EPSILON && abs(scale_max - 1) < DBL_EPSILON)
        {
            mem_id = find_shape_model(dst.ptr<uchar>(0), dst.cols, dst.rows, VisionMeasure::model_id_2, angle_start, angle_extent, minScore, numMatches, maxOverLap, subpixel, numLevels, greedness, pMatches, nFound);
        }
        else
        {
            mem_id = find_scaled_shape_model(dst.ptr<uchar>(0), dst.cols, dst.rows, VisionMeasure::model_id_2, angle_start, angle_extent, scale_min, scale_max, minScore, numMatches, maxOverLap, subpixel, numLevels, greedness, pMatches, nFound);
        }

        if (mem_id < 0)
        {
            std::cout << "find shape model failed" << endl;
            // QMessageBox::critical(this,"critical","find shape model failed");
            // ui->Log->append("cam_2 find shape model failed");
            if_exception=false;
            //  return;

        }

        Mat srcRgb;
        cvtColor(dst, srcRgb, COLOR_GRAY2RGB);
        std::cout << "find shape model success" << endl;
        // QMessageBox::information(this,"info","camera_2 find shape model success");

        ui->Log->append("cam_1 find shape model success");
        // feature_show(srcRgb,VisionMeasure::model_id_1);
        match_show(srcRgb, VisionMeasure::model_id_2, 0, 0, pMatches, nFound, subpixel);
        vector<double> result2;
        if(nFound!=0){
            QMessageBox::information(this,"info","cam_4 find shape model success!");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">CAM_4 find shape model success!</font>");
            ui->Log->append("cam_4 find shape model success");
        }else{
            std::cout << "cam_4 find shape model failed" << endl;
            QMessageBox::critical(this,"critical","cam_4 find shape model failed");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">CAM_4 find shape model failed!</font>");
        }
        ui->resultimage_1->getresult(srcRgb,result2);
        clear_mems(mem_id);
        cout<<"  dx: " <<camera_dx_1<<"  dy: "<<camera_dy_1<<"  angle: "<<camera_angle_1<<"  score: "<<camera_score_1<<endl;
        ui->Log->append("camera_2:");
        ui->Log->append("dx:"+QString::number(camera_dx_1,10,3));
        ui->Log->append("dy:"+QString::number(camera_dy_1,10,3));
        ui->Log->append("angle:"+QString::number(camera_angle_1,10,3));
        ui->Log->append("score:"+QString::number(camera_score_1,10,3));


        //        namedWindow("result",WINDOW_NORMAL);
        //        imshow("result", srcRgb);
        //        waitKey(0);

    }

    //clear_shape_model(VisionMeasure::model_id_1);


}

void SettingMeasureForm::getcreatemodellog(int num1, int num2)
{
  cout<<"aaa"<<endl;
    if(num1==1){
        if(num2==0){
            QMessageBox::critical(this,"critical","CAM_1 create model failed!");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">CAM_1 create model failed!</font>");
        }else{
            QMessageBox::information(this,"info","CAM_1 create model succeed!");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">CAM_1 create model succeed!</font>");
        }
    }else if(num1==2){
        if(num2==0){
            QMessageBox::critical(this,"critical","CAM_4 create model failed!");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#FF0000\">CAM_1 create model failed!</font>");
        }else{
            QMessageBox::information(this,"info","CAM_4 create model succeed!");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">CAM_4 create model succeed!</font>");
        }
    }
}


void SettingMeasureForm::on_findline_clicked()
{
    findlineform->sourceimage=sourceimage;

    findlineform->show();
}

void SettingMeasureForm::cam1_linebutton(int num, bool stat)
{
    cam1_line_biaoji=num;
}

void SettingMeasureForm::on_lineset_1_clicked()
{
    ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">设置相机"+QString::number(cam_biaoji)+"的第"+QString::number(cam1_line_biaoji)+"条直线</font>");
    QMessageBox::information(this,"info","The setting of the line is successful");
    if(cam_biaoji==1){
        double array[21]={camera_dx_1,camera_dy_1,camera_angle_1,FinelineForm::start_x,FinelineForm::start_y,FinelineForm::end_x,FinelineForm::end_y,FinelineForm::pp_1_x,
                          FinelineForm::pp_1_y,FinelineForm::pp_2_x,FinelineForm::pp_2_y,FinelineForm::pp_3_x,FinelineForm::pp_3_y,FinelineForm::pp_4_x,FinelineForm::pp_4_y,
                          FinelineForm::lenght,FinelineForm::scale_1,FinelineForm::scale_2,FinelineForm::threshold,FinelineForm::polarity,FinelineForm::num};
        QSettings settings("./measure.ini",QSettings::IniFormat);
        settings.setIniCodec("utf-8");
        switch (cam1_line_biaoji) {
        case 0:
            cout<<cam1_line_biaoji<<endl;
            QMessageBox::critical(this,"critical","please choose line");
            return;
        case 1:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam1_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 2:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam1_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 3:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam1_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 4:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam1_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 5:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam1_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 6:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam1_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 7:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam1_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 8:
            cout<<cam1_line_biaoji<<endl;
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.beginWriteArray("cam1_"+QString::number(j+1)+"_line");
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 9:
            cout<<cam1_line_biaoji<<endl;
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.beginWriteArray("cam1_"+QString::number(j+1)+"_line");
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 10:
            cout<<cam1_line_biaoji<<endl;
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                settings.beginWriteArray("cam1_"+QString::number(j+1)+"_line");
                settings.setArrayIndex(j);
                settings.setValue("cam1", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam1_findlinearray[0]) / sizeof(VisionMeasure::cam1_findlinearray[0][0]); ++j) {
                VisionMeasure::cam1_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        }
    }else if(cam_biaoji==2){
        double array[18]={FinelineForm::start_x,FinelineForm::start_y,FinelineForm::end_x,FinelineForm::end_y,FinelineForm::pp_1_x,
                          FinelineForm::pp_1_y,FinelineForm::pp_2_x,FinelineForm::pp_2_y,FinelineForm::pp_3_x,FinelineForm::pp_3_y,FinelineForm::pp_4_x,FinelineForm::pp_4_y,
                          FinelineForm::lenght,FinelineForm::scale_1,FinelineForm::scale_2,FinelineForm::threshold,FinelineForm::polarity,FinelineForm::num};
        QSettings settings("./measure.ini",QSettings::IniFormat);
        settings.setIniCodec("utf-8");
        switch (cam1_line_biaoji) {
        case 0:
            cout<<cam1_line_biaoji<<endl;
            QMessageBox::critical(this,"critical","please choose line");
            return;
        case 1:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam2_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam2", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                VisionMeasure::cam2_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 2:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam2_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam2", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                VisionMeasure::cam2_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 3:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam2_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam2", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                VisionMeasure::cam2_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 4:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam2_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam2", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                VisionMeasure::cam2_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 5:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam2_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam2", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                VisionMeasure::cam2_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 6:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam2_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam2", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                VisionMeasure::cam2_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 7:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam2_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam2", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                VisionMeasure::cam2_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 8:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam2_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam2", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam2_findlinearray[0]) / sizeof(VisionMeasure::cam2_findlinearray[0][0]); ++j) {
                VisionMeasure::cam2_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        }

        return;
    }else if(cam_biaoji==3){
        double array[18]={FinelineForm::start_x,FinelineForm::start_y,FinelineForm::end_x,FinelineForm::end_y,FinelineForm::pp_1_x,
                          FinelineForm::pp_1_y,FinelineForm::pp_2_x,FinelineForm::pp_2_y,FinelineForm::pp_3_x,FinelineForm::pp_3_y,FinelineForm::pp_4_x,FinelineForm::pp_4_y,
                          FinelineForm::lenght,FinelineForm::scale_1,FinelineForm::scale_2,FinelineForm::threshold,FinelineForm::polarity,FinelineForm::num};
        QSettings settings("./measure.ini",QSettings::IniFormat);
        settings.setIniCodec("utf-8");
        switch (cam1_line_biaoji) {
        case 0:
            cout<<cam1_line_biaoji<<endl;
            QMessageBox::critical(this,"critical","please choose line");
            return;
        case 1:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam3_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam3", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                VisionMeasure::cam3_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 2:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam3_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam3", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                VisionMeasure::cam3_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 3:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam3_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam3", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                VisionMeasure::cam3_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 4:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam3_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam3", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                VisionMeasure::cam3_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 5:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam3_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam3", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                VisionMeasure::cam3_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 6:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam3_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam3", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                VisionMeasure::cam3_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 7:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam3_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam3", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                VisionMeasure::cam3_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 8:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam3_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam3", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam3_findlinearray[0]) / sizeof(VisionMeasure::cam3_findlinearray[0][0]); ++j) {
                VisionMeasure::cam3_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        }        
           return;

    }else if(cam_biaoji==4){
        double array[18]={FinelineForm::start_x,FinelineForm::start_y,FinelineForm::end_x,FinelineForm::end_y,FinelineForm::pp_1_x,
                          FinelineForm::pp_1_y,FinelineForm::pp_2_x,FinelineForm::pp_2_y,FinelineForm::pp_3_x,FinelineForm::pp_3_y,FinelineForm::pp_4_x,FinelineForm::pp_4_y,
                          FinelineForm::lenght,FinelineForm::scale_1,FinelineForm::scale_2,FinelineForm::threshold,FinelineForm::polarity,FinelineForm::num};
        QSettings settings("./measure.ini",QSettings::IniFormat);
        settings.setIniCodec("utf-8");
        switch (cam1_line_biaoji) {
        case 0:
            cout<<cam1_line_biaoji<<endl;
            QMessageBox::critical(this,"critical","please choose line");
            return;
        case 1:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam4_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            return;
        case 2:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam4_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 3:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam4_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 4:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam4_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 5:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam4_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 6:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam4_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 7:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam4_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 8:
            cout<<cam1_line_biaoji<<endl;
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.beginWriteArray("cam4_"+QString::number(j+1)+"_line");
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 9:
            cout<<cam1_line_biaoji<<endl;
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.beginWriteArray("cam4_"+QString::number(j+1)+"_line");
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        case 10:
            cout<<cam1_line_biaoji<<endl;
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                settings.beginWriteArray("cam4_"+QString::number(j+1)+"_line");
                settings.setArrayIndex(j);
                settings.setValue("cam4", array[j]);

            }
            for (int j = 0; j < sizeof(VisionMeasure::cam4_findlinearray[0]) / sizeof(VisionMeasure::cam4_findlinearray[0][0]); ++j) {
                VisionMeasure::cam4_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
            settings.endArray();
            return;
        }
    }else if(cam_biaoji==5){
        double array[18]={FinelineForm::start_x,FinelineForm::start_y,FinelineForm::end_x,FinelineForm::end_y,FinelineForm::pp_1_x,
                          FinelineForm::pp_1_y,FinelineForm::pp_2_x,FinelineForm::pp_2_y,FinelineForm::pp_3_x,FinelineForm::pp_3_y,FinelineForm::pp_4_x,FinelineForm::pp_4_y,
                          FinelineForm::lenght,FinelineForm::scale_1,FinelineForm::scale_2,FinelineForm::threshold,FinelineForm::polarity,FinelineForm::num};
        QSettings settings("./measure.ini",QSettings::IniFormat);
        settings.setIniCodec("utf-8");
        switch (cam1_line_biaoji) {
        case 0:
            cout<<cam1_line_biaoji<<endl;
            QMessageBox::critical(this,"critical","please choose line");
            return;
        case 1:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam5_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam5", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                VisionMeasure::cam5_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        case 2:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam5_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam5", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                VisionMeasure::cam5_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        case 3:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam5_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam5", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                VisionMeasure::cam5_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        case 4:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam5_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam5", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                VisionMeasure::cam5_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        case 5:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam5_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam5", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                VisionMeasure::cam5_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        case 6:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam5_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam5", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                VisionMeasure::cam5_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        case 7:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam5_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam5", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                VisionMeasure::cam5_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        case 8:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam5_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam5", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam5_findlinearray[0]) / sizeof(VisionMeasure::cam5_findlinearray[0][0]); ++j) {
                VisionMeasure::cam5_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        }
        return;
    }else if(cam_biaoji==6){
        double array[18]={FinelineForm::start_x,FinelineForm::start_y,FinelineForm::end_x,FinelineForm::end_y,FinelineForm::pp_1_x,
                          FinelineForm::pp_1_y,FinelineForm::pp_2_x,FinelineForm::pp_2_y,FinelineForm::pp_3_x,FinelineForm::pp_3_y,FinelineForm::pp_4_x,FinelineForm::pp_4_y,
                          FinelineForm::lenght,FinelineForm::scale_1,FinelineForm::scale_2,FinelineForm::threshold,FinelineForm::polarity,FinelineForm::num};
        QSettings settings("./measure.ini",QSettings::IniFormat);
        settings.setIniCodec("utf-8");
        switch (cam1_line_biaoji) {
        case 0:
            cout<<cam1_line_biaoji<<endl;
            QMessageBox::critical(this,"critical","please choose line");
            return;
        case 1:
            cout<<cam1_line_biaoji<<endl;
            settings.beginWriteArray("cam6_"+QString::number(cam1_line_biaoji)+"_line");
            for (int j = 0; j < sizeof(VisionMeasure::cam6_findlinearray[0]) / sizeof(VisionMeasure::cam6_findlinearray[0][0]); ++j) {
                settings.setArrayIndex(j);
                settings.setValue("cam6", array[j]);

            }
            settings.endArray();
            for (int j = 0; j < sizeof(VisionMeasure::cam6_findlinearray[0]) / sizeof(VisionMeasure::cam6_findlinearray[0][0]); ++j) {
                VisionMeasure::cam6_findlinearray[cam1_line_biaoji-1][j]=array[j];
            }
        }
        return;
    }else if(cam_biaoji==7){

    }else if(cam_biaoji==8){

    }

}



void SettingMeasureForm::on_camera_choose_currentIndexChanged(int index)
{

    cam_biaoji=index+1;
    QMessageBox::information(this,"info","Switch to Camera "+QString::number(cam_biaoji));
    ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">切换相机"+QString::number(cam_biaoji)+"</font>");
    //   ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">二值化成功，阈值为"+QString::number(ui->spinBox->value())+"</font>");
    if(cam_biaoji==1||cam_biaoji==4){
        ui->modelmatch_1->setEnabled(true);
        ui->trainmodel->setEnabled(true);
        ui->loadmodel_1->setEnabled(true);
        ui->savemodel_1->setEnabled(true);
        ui->setmodel_1->setEnabled(true);

    }else{

        ui->modelmatch_1->setEnabled(false);
        ui->trainmodel->setEnabled(false);
        ui->loadmodel_1->setEnabled(false);
        ui->savemodel_1->setEnabled(false);
        ui->setmodel_1->setEnabled(false);
    }
    init_1();

}

//void SettingMeasureForm::on_pushButton_clicked()
//{
//    ui->modellabel->clear();
//}

void SettingMeasureForm::on_erzhihua_clicked()
{
    if(!sourceimage.data){
        QMessageBox::critical(this,"critical","image is empty!");
        return;
    }

    threshold(sourceimage,erzhihuamat,ui->spinBox->value(),ui->spinBox_3->value(),ThresholdTypes);
    //imageData_1 = QImage((const uchar*)(erzhihuamat.data), erzhihuamat.cols, erzhihuamat.rows, erzhihuamat.cols * erzhihuamat.channels(), QImage::Format_Indexed8);

    ui->resultimage_2->getimage2(erzhihuamat);
    QMessageBox::information(this,"info","Binarization succeed!");
    ui->tabWidget_2->setCurrentIndex(2);
    ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">二值化成功，阈值为"+QString::number(ui->spinBox->value())+"</font>");
    // imageData_1 = QImage((const uchar*)(sourceimage.data), sourceimage.cols, sourceimage.rows, sourceimage.cols * sourceimage.channels(), QImage::Format_Indexed8);

}
void SettingMeasureForm::on_comboBox_currentIndexChanged(int index)
{

    ThresholdTypes=index;
}

void SettingMeasureForm::on_blob_clicked()
{

    if(ui->checkBox->isChecked()==0){
        if(!sourceimage.data){
            QMessageBox::critical(this,"critical","image is empty!");
            return;
        }else{
            Mat blobimage= sourceimage.clone();
            blobimage=blob(blobimage);
            vector<double> result;
            ui->resultimage_3->getresult(blobimage,result);
            QMessageBox::information(this,"info","Blob succeed!");
            ui->tabWidget_2->setCurrentIndex(3);
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">Blob成功!</font>");
        }
    }else{
        if(!erzhihuamat.data){
            QMessageBox::critical(this,"critical","Binarization image is empty!");
            return;
        }else{
            Mat blobimage= erzhihuamat.clone();
            blobimage= blob(blobimage);
            vector<double> result;
            ui->resultimage_3->getresult(blobimage,result);
            QMessageBox::information(this,"info","Blob succeed!");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">Blob成功!</font>");
            ui->tabWidget_2->setCurrentIndex(3);
        }
    }
}

void SettingMeasureForm::on_setting_clicked()
{

    settingform->show();
}

void SettingMeasureForm::on_pixel_clicked()
{
    if(ui->checkBox_2->isChecked()==0){
        if(!sourceimage.data){
            QMessageBox::critical(this,"critical","image is empty!");
            return;
        }else{
            int count=0;
            for(int i=0;i<sourceimage.rows;i++){
                for(int j=0;j<sourceimage.cols;j++){
                    if(sourceimage.at<uchar>(i,j)<ui->spinBox_2->value()){
                        count++;

                    }
                }

            }
            QMessageBox::information(this,"info","像素统计成功!");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">像素统计结果为:"+QString::number(count)+"</font>");
        }
    }else{
        if(ui->setlabel_1->pixmap()!=nullptr&&!ui->setlabel_1->pixmap()->isNull()){
            QImage qimage=ui->setlabel_1->pixmap()->toImage();
            Mat mat = Mat(qimage.height(),
                          qimage.width(),
                          CV_8UC(1),
                          qimage.bits(),
                          qimage.bytesPerLine());
            int count=0;
            for(int i=0;i<mat.rows;i++){
                for(int j=0;j<mat.cols;j++){
                    if(mat.at<uchar>(i,j)<ui->spinBox_2->value()){
                        count++;

                    }
                }

            }
            QMessageBox::information(this,"info","像素统计成功!");
            ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">像素统计结果为:"+QString::number(count)+"</font>");
        }else{
            QMessageBox::critical(this,"critical","Partial image is empty!");
            return;
        }
    }
}





void SettingMeasureForm::on_xihua_clicked()
{
    if(!erzhihuamat.data){
        QMessageBox::critical(this,"critical","Binarization image is empty!");
        return;
    }else{
        Mat xihua= erzhihuamat.clone();
      //  Mat xihua2;
        xihuaimage= thinImage(xihua);

        if(ui->checkBox_3->isChecked()){
            Mat xihua3= sourceimage.clone();
            cvtColor(xihua3,xihua3,COLOR_BGR2RGB);
            vector<int>x;
            vector<int>y;
            for(int i=0;i<xihuaimage.rows;i++){
                for(int j=0;j<xihuaimage.cols;j++){
                    if(xihuaimage.at<uchar>(i,j)<50){
                        xihua3.at<Vec3b>(i, j)[0] = 0;
                        xihua3.at<Vec3b>(i, j)[1] = 255;
                        xihua3.at<Vec3b>(i, j)[2] = 0;


                    }
                }

            }
            vector<double> result;
            ui->resultimage_4->getresult(xihua3,result);
        }else{
            ui->resultimage_4->getimage2(xihuaimage);

        }
        QMessageBox::information(this,"info","thinImage succeed!");
        ui->Log->append("<font color=\"#C0C0C0\">["+QDateTime::currentDateTime().toString("hh:mm:ss:zzz")+"]</font>"+"<font color=\"#00FF00\">细化成功!</font>");
        ui->tabWidget_2->setCurrentIndex(4);
    }
}


void SettingMeasureForm::on_comboBox_2_currentIndexChanged(int index)
{
    ThinThresholdTypes=index;
}

void SettingMeasureForm::on_zhixiandu_clicked()
{
    float *zuobiao_x = new float[50000];
    float *zuobiao_y=new float[50000];
    int count=0;
    for (int row = 0; row <xihuaimage.rows; row++)
        {
            for (int col = 0; col <xihuaimage.cols; col++)
            {
                if (xihuaimage.at<uchar>(row, col)==0) {
                    zuobiao_x[count] = col;
                    zuobiao_y[count] = row;
                    //cout << "x:" << row << "y:" << col << endl;

                  //  point.push_back(Point2f(col,row));

                    count++;
                }




            }
        }
    LineFitLeastSquares(zuobiao_x,zuobiao_y,count);
    delete []zuobiao_x;
    delete []zuobiao_y;

}
void SettingMeasureForm::LineFitLeastSquares(float *data_x, float *data_y, int data_n)
{
    float A = 0.0;
    float B = 0.0;
    float C = 0.0;
    float D = 0.0;
    float E = 0.0;
    float F = 0.0;

    for (int i = 0; i < data_n; i++)
    {

        A += data_x[i] * data_x[i];
        B += data_x[i];
        C += data_x[i] * data_y[i];
        D += data_y[i];
        //cout << "i:" << i << endl;
    }

    // 计算斜率a和截距b
    float a, b, temp = 0;
    if ((temp =(data_n*A - B * B))!=0)// 判断分母不为0
    {
        a = (data_n*C - B * D) / temp;
        b = (A*D - B * C) / temp;
    }
    else
    {
        a = 1;
        b = 0;
    }
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;


    // 计算相关系数r
    float Xmean, Ymean;
    Xmean = B / data_n;
    Ymean = D / data_n;
    cout << "Xmean"<<Xmean << endl;
    cout << "Ymean" << Ymean << endl;

    float tempSumXX = 0.0, tempSumYY = 0.0;
    for (int i = 0; i < data_n; i++)
    {
        tempSumXX += (data_x[i] - Xmean) * (data_x[i] - Xmean);
        tempSumYY += (data_y[i] - Ymean) * (data_y[i] - Ymean);
        E += (data_x[i] - Xmean) * (data_y[i] - Ymean);
     // cout << "E1:" << E << endl;
      //cout << "E2:" << (data_x[i] - Xmean) * (data_y[i] - Ymean)<< endl;
      //cout << "E3:" << (data_x[i] - Xmean)  << endl;
     // cout << "E4:" << (data_y[i] - Ymean) << endl;
    }
    F = sqrt(tempSumXX) * sqrt(tempSumYY);

    float r;
    r = E / F;

    cout << "F:" << F << endl;
    cout << "r:" << r << endl;
    //计算点到直线的距离，将距离值存入一个向量中
//    vector<float> gaps(data_n);//！！！！！！！！！！！！！！！！！！
//    vector<float> y(data_n);//！！！！！！！！！！！！！！！！！
//    float countall = 0;
//    float count = 0;
//    for (int i = 0; i < data_n; i++) {
//        y[i] = a * data_x[i] + b;
//        gaps[i] = data_y[i] - y[i];
//        countall += abs(data_y[i] - y[i]);
//        count++;
//    }
//    float endd = countall / count;
//    //选出向量中最大最小值，做差取决对值返回
//    float max_gap = *max_element(gaps.begin(), gaps.end());//！！！！！！！！！！！！！！
//    float min_gap = *min_element(gaps.begin(), gaps.end());//！！！！！！！！！！！！！！！！！
//    float max_min_gap = abs(max_gap) + abs(min_gap);
//    cout << "max_gap:" << max_gap << endl;
//    cout << "min_gap:" << min_gap << endl;
//    cout << "max_min_gap:" << max_min_gap << endl;
//    cout << "endall:" << countall << endl;
//    cout << "count:" << count << endl;
//    cout << "end:" << endd << endl;

}
