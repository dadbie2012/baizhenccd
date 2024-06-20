#include "finelineform.h"
#include "ui_finelineform.h"

FinelineForm::FinelineForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinelineForm),
    state_flag_maindow(CHOOSE_NULL)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/image/caomei.png"));
    fileName = nullptr;
    my_caliberline = nullptr;
    lineitem = nullptr;
    qgraphicsScene = new QGraphicsScene();
    qgraphicsScene->setBackgroundBrush(Qt::white);
    qgraphicsScene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->graphicsView->raise();
    ui->graphicsView->show();
    m_plineCaliperGUI = new CLineCaliperGUI();
    ui->spinBox_caliper_number->setValue(10);

    match=new shapematch;

}
double FinelineForm::start_x=0;
double FinelineForm::start_y=0;
double FinelineForm::end_x=0;
double FinelineForm::end_y=0;
double FinelineForm::pp_1_x=0;
double FinelineForm::pp_1_y=0;
double FinelineForm::pp_2_x=0;
double FinelineForm::pp_2_y=0;
double FinelineForm::pp_3_x=0;
double FinelineForm::pp_3_y=0;
double FinelineForm::pp_4_x=0;
double FinelineForm::pp_4_y=0;
double FinelineForm::lenght=0;
double FinelineForm::scale_1=0;
double FinelineForm::scale_2=0;
double FinelineForm::threshold=0;
double FinelineForm::polarity=0;
double FinelineForm::num=0;

FinelineForm::~FinelineForm()
{  delete match;
    delete ui;
}
void FinelineForm::on_pushButton_choose_picture_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,QStringLiteral("选择图片"),"C:/Users/35843/Desktop/test/test4",QStringLiteral("图片文件(*png *jpg *jpeg *bmp)"));
    if(fileName == nullptr)
        return;

    QFile file(fileName);
    //以只读方式打开文件，用于载入文件
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();

    this->qgraphicsScene->clear();
    lineitem = nullptr;
    ImageItem = new QGraphicsPixmapItem();
    QImage img = QImage::fromData(data);
    QImage gray = img.convertToFormat(QImage::Format_Grayscale8);
    ImageItem->setPixmap(QPixmap::fromImage(gray));
    int nImgWidth = ImageItem->pixmap().width();
    int nImgHeight = ImageItem->pixmap().height();
    int nwidth = ui->graphicsView->width();
    int nheight = ui->graphicsView->height();
    //qreal 类似double类型
    qreal temp1 = nwidth*1.0/nImgWidth;
    qreal temp2 = nheight*1.0/nImgHeight;
    qreal m_scale;
    m_scale = std::min(temp1,temp2);


    ImageItem->setScale(m_scale);
    ImageItem->setFlag(QGraphicsItem::ItemIsMovable);
    state_flag_maindow = CHOOSE_PICTURE;
    this->qgraphicsScene->addItem(ImageItem);
    ui->graphicsView->setScene(qgraphicsScene);
    ui->graphicsView->centerOn(ImageItem->pixmap().width()*m_scale/2,ImageItem->pixmap().height()*m_scale/2);
   // cout << ImageItem->pixmap().width()*m_scale/2 <<"aa"<<ImageItem->pixmap().height()*m_scale/2<<endl;
    QString str = tr("imagesize=(%1,%2)").arg(ImageItem->pixmap().width()).arg(ImageItem->pixmap().height());
    ui->label_string->setText(str);




}

void FinelineForm::on_pushButton_caliberline_clicked()
{

    if(state_flag_maindow != CHOOSE_PICTURE)
        return;  //若已生成ROI则无变化
    else
    {
        state_flag_maindow = CALIBERLINE;
        my_caliberline = new CCaliberLine();
        my_caliberline->setcalibernumber(ui->spinBox_caliper_number->value()+1);
        my_caliberline->setpixmapwidth(ImageItem->pixmap().width()*ImageItem->scale());
        my_caliberline->setpixmapheight(ImageItem->pixmap().height()*ImageItem->scale());

        this->qgraphicsScene->addItem(my_caliberline);

        ui->graphicsView->setScene(this->qgraphicsScene);

        /* my_caliberline_2= new CCaliberLine();
        my_caliberline_2->setcalibernumber(ui->spinBox_caliper_number->value()+1);
        my_caliberline_2->setpixmapwidth(ImageItem->pixmap().width()*ImageItem->scale());
        my_caliberline_2->setpixmapheight(ImageItem->pixmap().height()*ImageItem->scale());
        this->qgraphicsScene->addItem(my_caliberline_2);
        ui->graphicsView->setScene(this->qgraphicsScene);*/
    }

}

QImage FinelineForm::Mat2QImage(const cv::Mat& InputMat)
{
    if (InputMat.type() == CV_8UC1)
    {
        QImage image(InputMat.cols, InputMat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = InputMat.data;
        for (int row = 0; row < InputMat.rows; row++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, InputMat.cols);
            pSrc += InputMat.step;
        }
        return image;
    }
    else if (InputMat.type() == CV_8UC3)
    {
        const uchar *pSrc = (const uchar*)InputMat.data;
        QImage image(pSrc, InputMat.cols, InputMat.rows, InputMat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if (InputMat.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)InputMat.data;
        QImage image(pSrc, InputMat.cols, InputMat.rows, InputMat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }
}


cv::Rect get_IOU(cv::Rect rect1, cv::Rect rect2)
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

void FinelineForm::on_spinBox_caliper_number_valueChanged(int num)
{
    if(my_caliberline != nullptr)
    {
        my_caliberline->setcalibernumber(num+1);
        my_caliberline->setlinsize();
    }
}

QList<QPointF> get_intersection(QPointF pt1,QPointF pt2,QPointF begin,QPointF end)
{
    qreal k1;
    qreal b1;
    qreal k2;
    qreal b2;
    qreal k3;
    qreal b3;

    qreal x1;
    qreal y1;
    qreal x2;
    qreal y2;
    if((pt1.x()-pt2.x()) != 0)
    {
        k1=(pt1.y()-pt2.y())/(pt1.x()-pt2.x());
        b1= -k1*pt1.x()+pt1.y();
        k2= -1/k1;
        k3= -1/k1;
        b2= -k2*begin.x()+begin.y();
        b3= -k3*end.x()+end.y();

        x1 = (b2-b1)/(k1-k2);
        y1 = k1*x1+b1;
        x2 = (b3-b1)/(k1-k3);
        y2 = k1*x2+b1;
    }
    else if(pt1.y() != pt2.y())
    {
        x1=x2=pt1.x();
        y1=begin.y();
        y2=end.y();
    }else
    {
        x1=x2=y1=y2=0;
    }

    QList<QPointF> result;
    result.push_back(QPointF(x1,y1));
    result.push_back(QPointF(x2,y2));

    return result;
}

void FinelineForm::on_pushButton_findline_clicked()
{
    this->on_pushButton_refresh_clicked();
    //耗时100
    QImage image = ImageItem->pixmap().toImage();
    image = image.convertToFormat(QImage::Format_RGB888);
    Mat srcImage = Mat(image.height(),
                       image.width(),
                       CV_8UC(3),
                       image.bits(),

                       image.bytesPerLine());
    double time_1 = 0;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);

    if (srcImage.empty())
    {
        qDebug() << "Fail to load the image";
        return;
    }
    /*if(ImageItem == nullptr || my_caliberline == nullptr)
        {

            return;
        }*/


    QPointF pt_begin = my_caliberline->mapToItem(ImageItem,my_caliberline->getbeginpoint());





    cout << "开始点:"<< pt_begin.x()<<"-"<<pt_begin.y()<<endl;
    QPointF pt_end = my_caliberline->mapToItem(ImageItem,my_caliberline->getendpoint());

    cout << "结束:"<< pt_end.x()<<"-"<<pt_end.y()<<endl;
    qreal length_new = sqrt((pt_begin.x()-pt_end.x())*(pt_begin.x()-pt_end.x()) +
                            (pt_begin.y()-pt_end.y())*(pt_begin.y()-pt_end.y()));


    qreal scale = length_new/my_caliberline->getlength();

   // cout << "my_caliberline->getlength():"<< my_caliberline->getlength()<<endl;
    cv::Point pt_begin_cv = cv::Point(pt_begin.x(),pt_begin.y());
    cv::Point pt_end_cv = cv::Point(pt_end.x(),pt_end.y());
    QPointF pp_1=my_caliberline->pp[0];
    QPointF pp_2=my_caliberline->pp[1];
    QPointF pp_3=my_caliberline->pp[2];
    QPointF pp_4=my_caliberline->pp[3];
    QPointF pp[4];
    pp[0] = my_caliberline->mapToItem(ImageItem,pp_1);
    pp[1] = my_caliberline->mapToItem(ImageItem,pp_2);
    pp[2] = my_caliberline->mapToItem(ImageItem,pp_3);
    pp[3] = my_caliberline->mapToItem(ImageItem,pp_4);
   // cout<<"pp_1_x"<<pp[0].x()<<endl;
  //  cout<<"pp_1_y"<<pp[0].y()<<endl;
   // cout<<"pp_2_x"<<pp[1].x()<<endl;
   // cout<<"pp_2_y"<<pp[1].y()<<endl;
   // cout<<"pp_3_x"<<pp[2].x()<<endl;
   // cout<<"pp_3_y"<<pp[2].y()<<endl;
   // cout<<"pp_4_x"<<pp[3].x()<<endl;
    //cout<<"pp_4_y"<<pp[3].y()<<endl;
    QRectF bounding = my_caliberline->mapToItem(ImageItem,my_caliberline->boundingRect()).boundingRect();


    cv::Rect bound_caliber(bounding.topLeft().x(),
                           bounding.topLeft().y(),
                           bounding.width(),bounding.height());

   // cout << "bounding:"<< bounding.topLeft().x()<<endl;
   // cout << "bounding:"<< bounding.topLeft().y()<<endl;
   // cout << "bounding:"<< bounding.width()<<endl;
   // cout << "bounding:"<< bounding.height()<<endl;
    cv::Rect bound_src(0,0,image.width(),image.height());
    cv::Rect roi = get_IOU(bound_caliber,bound_src);

    Mat src = srcImage(roi).clone();
    cv::Point pt_begin_cv2 = pt_begin_cv - roi.tl();
    cv::Point pt_end_cv2 = pt_end_cv - roi.tl();

    m_plineCaliperGUI->createLineKaChi(src, pt_begin_cv2, pt_end_cv2,
                                       my_caliberline->getheight()*scale,
                                       my_caliberline->getwidth()*scale,
                                       nSigma, ui->spinBox_edge_threshold->value(),
                                       ui->comboBox_edge_polarity->currentIndex(),
                                       ui->spinBox_caliper_number->value());
   // cout << " my_caliberline->getheight()"<<  my_caliberline->getheight()<<endl;
   // cout << "my_caliberline->getwidth()"<<  my_caliberline->getwidth()<<endl;
    start_x=pt_begin.x();
    start_y=pt_begin.y();
    end_x=pt_end.x();
    end_y=pt_end.y();
    lenght= my_caliberline->getlength();
    pp_1_x=pp[0].x();
    pp_1_y=pp[0].y();
    pp_2_x=pp[1].x();
    pp_2_y=pp[1].y();
    pp_3_x=pp[2].x();
    pp_3_y=pp[2].y();
    pp_4_x=pp[3].x();
    pp_4_y=pp[3].y();
    scale_1=my_caliberline->getheight();
    scale_2=my_caliberline->getwidth();
    threshold=ui->spinBox_edge_threshold->value();
    polarity= ui->comboBox_edge_polarity->currentIndex();
    num=ui->spinBox_caliper_number->value();

    Point2d pdLineStart(0, 0), pdLineEnd(0, 0);
    double dAngle = 0;
    m_plineCaliperGUI->lineEdgePointSetsFit(pdLineStart, pdLineEnd, dAngle);


    lineitem = new CControlLine();


    QPointF linestart = lineitem->mapFromItem(ImageItem,
                                              QPointF(pdLineStart.x + roi.tl().x,
                                                      pdLineStart.y + roi.tl().y));
    QPointF lineend = lineitem->mapFromItem(ImageItem,
                                            QPointF(pdLineEnd.x + roi.tl().x,
                                                    pdLineEnd.y + roi.tl().y));

    qDebug()<<linestart<<lineend;
    QPointF pt_begin_line = lineitem->mapFromItem(ImageItem,pt_begin);
    QPointF pt_end_line = lineitem->mapFromItem(ImageItem,pt_end);

    QList<QPointF> result = get_intersection(linestart,lineend,pt_begin_line,pt_end_line);

    lineitem->setline(result[0],result[1]);


    vector<Point2d> edgepoints = m_plineCaliperGUI->getEdgePoints();
    vector<Point2d> edgeexpectpoints = m_plineCaliperGUI->getExcepetEdgePoints();  //边缘点的信息
    for(size_t i=0;i<edgepoints.size();i++)
    {
        QPointF pt = lineitem->mapFromItem(ImageItem,QPointF(edgepoints[i].x + roi.tl().x,
                                                             edgepoints[i].y + roi.tl().y));
        lineitem->addedgepoints(pt);

    }

    for(size_t j=0;j<edgeexpectpoints.size();j++)
    {
        QPointF pt = lineitem->mapFromItem(ImageItem,
                                           QPointF(edgeexpectpoints[j].x + roi.tl().x,
                                                   edgeexpectpoints[j].y + roi.tl().y));
        lineitem->addedgeexpectpoints(pt);
    }
    qgraphicsScene->addItem(lineitem);
    qgraphicsScene->update();

    QPointF center = QPointF(pdLineStart.x,pdLineStart.y)/2 + QPointF(pdLineEnd.x,pdLineEnd.y)/2;
    qreal angle = atan2(pdLineStart.y - pdLineEnd.y, pdLineStart.x - pdLineEnd.x)*180/M_PI;

    QString str ="center_x:";
    str.append(QString::number( center.x(),10,4));
    str.append(" center_y:");
    str.append(QString::number( center.y(),10,4));
    str.append(" angle:");
    str.append(QString::number(angle));


    ui->label_string->setText(str);
    /*  QPointF start;
        start.setX(pdLineStart.x);
        start.setY(pdLineStart.y);
        QPointF end;
        end.setX(pdLineEnd.x);
        end.setY(pdLineEnd.y);

        QPointF start2 = lineitem->mapToItem(ImageItem,start);
        QPointF end2 = lineitem->mapToItem(ImageItem,end);
        cout << "start:"<< start2.x()<<"-"<<start2.y()<<endl;
        cout << "end:"<< end2.x()<<"-"<<end2.y()<<endl;*/
//    cout<<"start_x"<<pdLineStart.x + roi.tl().x<<endl;
//    cout<<"start_y"<<pdLineStart.y + roi.tl().y<<endl;
//    cout<<"end_x"<<pdLineEnd.x + roi.tl().x<<endl;
//    cout<<"end_y"<<pdLineEnd.y + roi.tl().y<<endl;
    /*Mat image2= imread("C:/Users/35843/Desktop/test/test4/1.bmp",IMREAD_GRAYSCALE);
        cv::Point point1, point2;
        point1.x = pdLineStart.x + roi.tl().x;
        point1.y = pdLineStart.y + roi.tl().y;
        point2.x=pdLineEnd.x + roi.tl().x;
        point2.y=pdLineEnd.y + roi.tl().y;
        cv::line(image2, point1, point2, cv::Scalar(0, 255, 0), 2, 8, 0);
        imwrite( "C:/Users/35843/Desktop/1.jpg", image2);*/


    QueryPerformanceCounter(&nEndTime);//停止计时
    time_1 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s*/
    //cout << "The run time is:" << time_1 * 1000 << "ms" << endl;




    /*if(ImageItem == nullptr || my_caliberline == nullptr)
    {

        return;
    }*/


    //  QPointF pt_begin = my_caliberline->mapToItem(ImageItem,my_caliberline->getbeginpoint());
    //    QPointF pt_begin=linestart;
    //    // pt_begin.setX(1957.3);
    //    // pt_begin.setY(697.101);


    //    cout << "开始点:"<< pt_begin.x()<<"-"<<pt_begin.y()<<endl;
    //    //QPointF pt_end = my_caliberline->mapToItem(ImageItem,my_caliberline->getendpoint());
    //    QPointF pt_end=lineend;
    //    // pt_end.setX(1374.66);
    //    // pt_end.setY(636.101);
    //    cout << "结束:"<< pt_end.x()<<"-"<<pt_end.y()<<endl;
    //    qreal length_new = sqrt((pt_begin.x()-pt_end.x())*(pt_begin.x()-pt_end.x()) +
    //                            (pt_begin.y()-pt_end.y())*(pt_begin.y()-pt_end.y()));


    //    //qreal scale = length_new/my_caliberline->getlength();
    //    qreal scale = length_new/56;
    //    // cout << "my_caliberline->getlength():"<< my_caliberline->getlength()<<endl;
    //    cv::Point pt_begin_cv = cv::Point(pt_begin.x(),pt_begin.y());
    //    cv::Point pt_end_cv = cv::Point(pt_end.x(),pt_end.y());




    //    //  QRectF bounding = my_caliberline->mapToItem(ImageItem,my_caliberline->boundingRect()).boundingRect();


    //    cv::Rect bound_caliber(bound.topLeft().x(),
    //                           bound.topLeft().y(),
    //                           bound.width(),bound.height());
    // //   cv::Rect bound_caliber(bound.x(),bound.y(),425.057,300.811);

    //    /*cout << "bounding:"<< bounding.topLeft().x()<<endl;
    // cout << "bounding:"<< bounding.topLeft().y()<<endl;
    // cout << "bounding:"<< bounding.width()<<endl;
    // cout << "bounding:"<< bounding.height()<<endl;*/
    //    cv::Rect bound_src(0,0,image.width(),image.height());

    //    cv::Rect roi = get_IOU(bound_caliber,bound_src);

    //    Mat src = srcImage(roi).clone();
    //    cv::Point pt_begin_cv2 = pt_begin_cv - roi.tl();
    //    cv::Point pt_end_cv2 = pt_end_cv - roi.tl();

    //    /* m_plineCaliperGUI->createLineKaChi(src, pt_begin_cv2, pt_end_cv2,
    //                                       my_caliberline->getheight()*scale,
    //                                       my_caliberline->getwidth()*scale,
    //                                       nSigma, ui->spinBox_edge_threshold->value(),
    //                                       ui->comboBox_edge_polarity->currentIndex(),
    //                                       ui->spinBox_caliper_number->value());*/
    //    // cout << " my_caliberline->getheight()"<<  my_caliberline->getheight()<<endl;
    //    // cout << "my_caliberline->getwidth()"<<  my_caliberline->getwidth()<<endl;
    //    m_plineCaliperGUI->createLineKaChi(src, pt_begin_cv2, pt_end_cv2,
    //                                       3.51*scale,
    //                                       1.61*scale,
    //                                       nSigma, ui->spinBox_edge_threshold->value(),
    //                                       ui->comboBox_edge_polarity->currentIndex(),
    //                                       15);
    //    Point2d pdLineStart(0, 0), pdLineEnd(0, 0);
    //    double dAngle = 0;
    //    m_plineCaliperGUI->lineEdgePointSetsFit(pdLineStart, pdLineEnd, dAngle);

    //    lineitem = new CControlLine();

    //    QPointF linestart = lineitem->mapFromItem(ImageItem,
    //                                              QPointF(pdLineStart.x + roi.tl().x,
    //                                                      pdLineStart.y + roi.tl().y));
    //    QPointF lineend = lineitem->mapFromItem(ImageItem,
    //                                            QPointF(pdLineEnd.x + roi.tl().x,
    //                                                    pdLineEnd.y + roi.tl().y));
    //    qDebug()<<linestart<<lineend;
    //    QPointF pt_begin_line = lineitem->mapFromItem(ImageItem,pt_begin);
    //    QPointF pt_end_line = lineitem->mapFromItem(ImageItem,pt_end);

    //    QList<QPointF> result = get_intersection(linestart,lineend,pt_begin_line,pt_end_line);

    //    lineitem->setline(result[0],result[1]);

    //    vector<Point2d> edgepoints = m_plineCaliperGUI->getEdgePoints();
    //    vector<Point2d> edgeexpectpoints = m_plineCaliperGUI->getExcepetEdgePoints();  //边缘点的信息
    //    for(size_t i=0;i<edgepoints.size();i++)
    //    {
    //        QPointF pt = lineitem->mapFromItem(ImageItem,QPointF(edgepoints[i].x + roi.tl().x,
    //                                                             edgepoints[i].y + roi.tl().y));
    //        lineitem->addedgepoints(pt);
    //    }

    //    for(size_t j=0;j<edgeexpectpoints.size();j++)
    //    {
    //        QPointF pt = lineitem->mapFromItem(ImageItem,
    //                                           QPointF(edgeexpectpoints[j].x + roi.tl().x,
    //                                                   edgeexpectpoints[j].y + roi.tl().y));
    //        lineitem->addedgeexpectpoints(pt);
    //    }
    //    qgraphicsScene->addItem(lineitem);
    //    qgraphicsScene->update();

    //    QPointF center = QPointF(pdLineStart.x,pdLineStart.y)/2 + QPointF(pdLineEnd.x,pdLineEnd.y)/2;
    //    qreal angle = atan2(pdLineStart.y - pdLineEnd.y, pdLineStart.x - pdLineEnd.x)*180/M_PI;
    //    cout <<"jiaodu"<<angle<<endl;
    //    QString str = tr("图像尺寸1=(%1,%2),直线中心=(%3,%4),角度=%5").
    //            arg(ImageItem->pixmap().width()).
    //            arg(ImageItem->pixmap().height()).
    //            arg(center.x()).arg(center.y()).
    //            arg(angle);

    //    ui->label_string->setText(str);

    //*********************************************************************

    //    //QPointF pt_begin = my_caliberline->mapToItem(ImageItem,my_caliberline->getbeginpoint());

    //    QPointF pt_begin2;
    //    pt_begin2.setX(1087.89);
    //    pt_begin2.setY(2940.23);


    //   cout << "开始点:"<< pt_begin2.x()<<"-"<<pt_begin2.y()<<endl;
    //   //QPointF pt_end = my_caliberline->mapToItem(ImageItem,my_caliberline->getendpoint());
    //   QPointF pt_end2;
    //   pt_end2.setX(1841.53);
    //   pt_end2.setY(3006.43);
    //   cout << "结束:"<< pt_end2.x()<<"-"<<pt_end2.y()<<endl;
    //   qreal length_new2 = sqrt((pt_begin2.x()-pt_end2.x())*(pt_begin2.x()-pt_end2.x()) +
    //                           (pt_begin2.y()-pt_end2.y())*(pt_begin2.y()-pt_end2.y()));


    //   //qreal scale = length_new/my_caliberline->getlength();
    //   qreal scale2 = length_new2/82.7293;
    //  // cout << "my_caliberline->getlength():"<< my_caliberline->getlength()<<endl;
    //   cv::Point pt_begin_cv3 = cv::Point(pt_begin2.x(),pt_begin2.y());
    //   cv::Point pt_end_cv3 = cv::Point(pt_end2.x(),pt_end2.y());




    // //  QRectF bounding = my_caliberline->mapToItem(ImageItem,my_caliberline->boundingRect()).boundingRect();


    //  /*cv::Rect bound_caliber(bounding.topLeft().x(),
    //                          bounding.topLeft().y(),
    //                          bounding.width(),bounding.height());*/
    //   cv::Rect bound_caliber2(1042.17,2868.99,845.085,183.16);

    ///*cout << "bounding:"<< bounding.topLeft().x()<<endl;
    //cout << "bounding:"<< bounding.topLeft().y()<<endl;
    //cout << "bounding:"<< bounding.width()<<endl;
    //cout << "bounding:"<< bounding.height()<<endl;*/
    //   cv::Rect bound_src2(0,0,image.width(),image.height());
    //   cv::Rect roi2 = get_IOU(bound_caliber2,bound_src2);

    //   Mat src2 = srcImage(roi).clone();
    //   cv::Point pt_begin_cv4 = pt_begin_cv3 - roi2.tl();
    //   cv::Point pt_end_cv4 = pt_end_cv3 - roi2.tl();

    //  /* m_plineCaliperGUI->createLineKaChi(src, pt_begin_cv2, pt_end_cv2,
    //                                      my_caliberline->getheight()*scale,
    //                                      my_caliberline->getwidth()*scale,
    //                                      nSigma, ui->spinBox_edge_threshold->value(),
    //                                      ui->comboBox_edge_polarity->currentIndex(),
    //                                      ui->spinBox_caliper_number->value());*/
    //  // cout << " my_caliberline->getheight()"<<  my_caliberline->getheight()<<endl;
    //   // cout << "my_caliberline->getwidth()"<<  my_caliberline->getwidth()<<endl;
    //   m_plineCaliperGUI->createLineKaChi(src2, pt_begin_cv4, pt_end_cv4,
    //                                         6.36379*scale,
    //                                          6.36379*scale,
    //                                          nSigma, ui->spinBox_edge_threshold->value(),
    //                                          1,
    //                                          ui->spinBox_caliper_number->value());
    //   Point2d pdLineStart2(0, 0), pdLineEnd2(0, 0);
    //   double dAngle2 = 0;
    //   m_plineCaliperGUI->lineEdgePointSetsFit(pdLineStart2, pdLineEnd2, dAngle2);

    //   lineitem = new CControlLine();
    //   lineitem2 = new CControlLine();

    //   QPointF linestart2 = lineitem2->mapFromItem(ImageItem,
    //                                             QPointF(pdLineStart2.x + roi2.tl().x,
    //                                                     pdLineStart2.y + roi2.tl().y));
    //   QPointF lineend2 = lineitem2->mapFromItem(ImageItem,
    //                                           QPointF(pdLineEnd2.x + roi2.tl().x,
    //                                                   pdLineEnd2.y + roi2.tl().y));
    //   qDebug()<<linestart2<<lineend2;
    //   QPointF pt_begin_line2 = lineitem2->mapFromItem(ImageItem,pt_begin2);
    //   QPointF pt_end_line2 = lineitem2->mapFromItem(ImageItem,pt_end2);

    //   QList<QPointF> result2 = get_intersection(linestart2,lineend2,pt_begin_line2,pt_end_line2);

    //   lineitem2->setline(result2[0],result2[1]);

    //   vector<Point2d> edgepoints2 = m_plineCaliperGUI->getEdgePoints();
    //   vector<Point2d> edgeexpectpoints2 = m_plineCaliperGUI->getExcepetEdgePoints();  //边缘点的信息
    //   for(size_t i=0;i<edgepoints2.size();i++)
    //   {
    //       QPointF pt = lineitem2->mapFromItem(ImageItem,QPointF(edgepoints2[i].x + roi2.tl().x,
    //                                                            edgepoints2[i].y + roi2.tl().y));
    //       lineitem2->addedgepoints(pt);
    //   }

    //   for(size_t j=0;j<edgeexpectpoints2.size();j++)
    //   {
    //       QPointF pt = lineitem2->mapFromItem(ImageItem,
    //                                          QPointF(edgeexpectpoints2[j].x + roi2.tl().x,
    //                                                  edgeexpectpoints2[j].y + roi2.tl().y));
    //       lineitem2->addedgeexpectpoints(pt);
    //   }
    //   qgraphicsScene->addItem(lineitem2);
    //   qgraphicsScene->update();

    //   QPointF center2 = QPointF(pdLineStart2.x,pdLineStart2.y)/2 + QPointF(pdLineEnd2.x,pdLineEnd2.y)/2;
    //   qreal angle2 = atan2(pdLineStart2.y - pdLineEnd2.y, pdLineStart2.x - pdLineEnd2.x)*180/M_PI;
    //   cout <<"jiaodu"<<angle2<<endl;
    //   QString str2 = tr("图像尺寸1=(%1,%2),直线中心=(%3,%4),角度=%5").
    //           arg(ImageItem->pixmap().width()).
    //           arg(ImageItem->pixmap().height()).
    //           arg(center2.x()).arg(center2.y()).
    //           arg(angle2);

    //   ui->label_string->setText(str2);



}

void FinelineForm::on_pushButton_refresh_clicked()
{
    if(lineitem == nullptr)
        return;

    qgraphicsScene->removeItem(lineitem);
}





//void FinelineForm::on_pushButton_clicked()
//{

//    match->test();
//    //cout<<"aaaa"<<match->dx<<endl;
//    this->dx=match->dx;

//    this->dy=match->dy;
//    this->angle=match->angle*M_PI/180;

////    ui->Log->append("模板dx:"+QString::number(this->dx,10,6));
////    ui->Log->append("模板dy:"+QString::number(this->dy,10,6));
////    ui->Log->append("模板角度:"+QString::number(this->angle,10,6));




//}

//void FinelineForm::on_pushButton_2_clicked()
//{

//    QTransform t(1,0,0,0,1,0,0,0,1);
//    QTransform t2(1,0,dy,0,1,dx,0,0,1);
//    QTransform t3=Transformchengfa(t2,t);
////    cout <<"平移后坐标"<<endl;
////    cout<<t3.m11()<<endl;
////    cout<<t3.m12()<<endl;
////    cout<<t3.m13()<<endl;
////    cout<<t3.m21()<<endl;
////    cout<<t3.m22()<<endl;
////    cout<<t3.m23()<<endl;
////    cout<<t3.m31()<<endl;
////    cout<<t3.m32()<<endl;
////    cout<<t3.m33()<<endl;
////    cout <<"*********"<<endl;
//    QTransform t4(1,0,-dy,0,1,-dx,0,0,1);
//    QTransform t5=Transformchengfa(t4,t3);
////    cout <<"旋转步骤一"<<endl;
////    cout<<t5.m11()<<endl;
////    cout<<t5.m12()<<endl;
////    cout<<t5.m13()<<endl;
////    cout<<t5.m21()<<endl;
////    cout<<t5.m22()<<endl;
////    cout<<t5.m23()<<endl;
////    cout<<t5.m31()<<endl;
////    cout<<t5.m32()<<endl;
////    cout<<t5.m33()<<endl;
////    cout <<"*********"<<endl;
//    QTransform t6(cos(angle),-sin(angle),0,sin(angle),cos(angle),0,0,0,1);
//    QTransform t7=Transformchengfa(t6,t5);
////    cout <<"旋转步骤二"<<endl;
////    cout<<t7.m11()<<endl;
////    cout<<t7.m12()<<endl;
////    cout<<t7.m13()<<endl;
////    cout<<t7.m21()<<endl;
////    cout<<t7.m22()<<endl;
////    cout<<t7.m23()<<endl;
////    cout<<t7.m31()<<endl;
////    cout<<t7.m32()<<endl;
////    cout<<t7.m33()<<endl;
////    cout <<"*********"<<endl;
//    QTransform t8(1,0,dy,0,1,dx,0,0,1);
//    QTransform t9=Transformchengfa(t8,t7);
////    cout <<"旋转步骤三"<<endl;
////    cout<<t9.m11()<<endl;
////    cout<<t9.m12()<<endl;
////    cout<<t9.m13()<<endl;
////    cout<<t9.m21()<<endl;
////    cout<<t9.m22()<<endl;
////    cout<<t9.m23()<<endl;
////    cout<<t9.m31()<<endl;
////    cout<<t9.m32()<<endl;
////    cout<<t9.m33()<<endl;
////    cout <<"*********"<<endl;
//    QTransform t10(t9.m11(),t9.m21(),t9.m31(),t9.m12(),t9.m22(),t9.m32(),t9.m13(),t9.m23(),t9.m33());
//    QPoint linestart_=t10.map(QPoint(1101,253));
//    QPoint lineend_=t10.map(QPoint(26,157));
//    QPoint bound_1=t10.map(QPoint(-4,-137));
//    QPoint bound_2=t10.map(QPoint(-4,-129));
//    QPoint bound_3=t10.map(QPoint(16,-130));
//    QPoint bound_4=t10.map(QPoint(15,-139));

//    linestart.setX(linestart_.y());
//    linestart.setY(linestart_.x());
//    lineend.setX(lineend_.y());
//    lineend.setY(lineend_.x());
//    PP[0].setX(bound_1.y());
//    PP[0].setY(bound_1.x());
//    PP[1].setX(bound_2.y());
//    PP[1].setY(bound_2.x());
//    PP[2].setX(bound_3.y());
//    PP[2].setY(bound_3.x());
//    PP[3].setX(bound_4.y());
//    PP[3].setY(bound_4.x());
//    bound=boundingRect();


//    qDebug()<<"linestart_x:"<<linestart.x()<<endl;
//    qDebug()<<"linestart_y:"<<linestart.y()<<endl;
//    qDebug()<<"lineend_x:"<<lineend.x()<<endl;
//    qDebug()<<"lineend_y:"<<lineend.y()<<endl;
//    /*qDebug()<<"bound_x:"<<bound.x()<<endl;
//       qDebug()<<"bound_y:"<<bound.y()<<endl;*/

//    QTransform t11(1,0,-dy,0,1,-dx,0,0,1);
//    QTransform t12(cos(angle),sin(angle),0,-sin(angle),cos(angle),0,0,0,1);
//    QTransform t13=Transformchengfa(t12,t11);
////    cout <<"2222"<<endl;
////    cout<<t13.m11()<<endl;
////    cout<<t13.m12()<<endl;
////    cout<<t13.m13()<<endl;
////    cout<<t13.m21()<<endl;
////    cout<<t13.m22()<<endl;
////    cout<<t13.m23()<<endl;
////    cout<<t13.m31()<<endl;
////    cout<<t13.m32()<<endl;
////    cout<<t13.m33()<<endl;
//    //  QTransform t14(0.7932,0.608,-1772.68,-0.608,0.7932,667.0309,0,0,1);
//    QTransform t15(t13.m11(),t13.m21(),t13.m31(),t13.m12(),t13.m22(),t13.m32(),t13.m13(),t13.m23(),t13.m33());
//    QPoint linestart_22=t15.map(QPoint(853,620));
////    cout <<"3333"<<endl;
////    cout<<linestart_22.x()<<endl;
////    cout<<linestart_22.y()<<endl;




//}




QRectF FinelineForm::boundingRect()
{

    QVector<QPointF> vpt;
    vpt.append(linestart);
    vpt.append(PP[0]);
    vpt.append(PP[1]);
    vpt.append(lineend);
    vpt.append(PP[2]);
    vpt.append(PP[3]);
    vpt.append(linestart);

    QRectF re = QPolygonF(vpt).boundingRect();
    return QRectF(re.topLeft().x()-5,
                  re.topLeft().y()-5,
                  re.width()+10,
                  re.height()+10);

}


QTransform  FinelineForm::Transformchengfa(QTransform t1, QTransform t2)
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





void FinelineForm::on_pushButton_3_clicked()
{

    if(!sourceimage.data){
        QMessageBox::critical(this,"critical","image is empty!");
        return;
    }
    imageData_1 = QImage((const uchar*)(sourceimage.data), sourceimage.cols, sourceimage.rows, sourceimage.cols * sourceimage.channels(), QImage::Format_Indexed8);
    this->qgraphicsScene->clear();
    lineitem = nullptr;
    ImageItem = new QGraphicsPixmapItem();

    //QImage gray = img.convertToFormat(QImage::Format_Grayscale8);
    ImageItem->setPixmap(QPixmap::fromImage(imageData_1));

    int nImgWidth = ImageItem->pixmap().width();
    int nImgHeight = ImageItem->pixmap().height();
    int nwidth = ui->graphicsView->width();
    int nheight = ui->graphicsView->height();
    //qreal 类似double类型
    //  cout<<"ccc"<<endl;
    qreal temp1 = nwidth*1.0/nImgWidth;
    qreal temp2 = nheight*1.0/nImgHeight;
    qreal m_scale;
    m_scale = std::min(temp1,temp2);


    ImageItem->setScale(m_scale);
    ImageItem->setFlag(QGraphicsItem::ItemIsMovable);
    state_flag_maindow = CHOOSE_PICTURE;
    this->qgraphicsScene->addItem(ImageItem);

    ui->graphicsView->setScene(qgraphicsScene);
    ui->graphicsView->centerOn(ImageItem->pixmap().width()*m_scale/2,ImageItem->pixmap().height()*m_scale/2);

   // cout << ImageItem->pixmap().width()*m_scale/2 <<"aa"<<ImageItem->pixmap().height()*m_scale/2<<endl;
    QString str = tr("imagesize=(%1,%2)").arg(ImageItem->pixmap().width()).arg(ImageItem->pixmap().height());
    ui->label_string->setText(str);


}
