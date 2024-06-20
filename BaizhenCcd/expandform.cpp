#include "expandform.h"
#include "ui_expandform.h"

ExpandForm::ExpandForm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ExpandForm)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose, false);
    setMouseTracking(true);
    this->installEventFilter(this);
    this->setWindowIcon(QIcon(":/image/image/lizi.png"));
    //this->setAttribute(Qt::WA_DeleteOnClose);
    //this->resize(1550,367);
   //this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    this->resize(1000,800);
    zhenlv=0;
    ui->setupUi(this);
}

ExpandForm::~ExpandForm()
{
    delete ui;
}
void ExpandForm::getqimage(QImage image,QMutex *mutex)
{
        mutex->lock();
        imageee=image.copy();

    //    QMatrix matrix;
    //    matrix.rotate(90.0);
    //    qimage=qimage.transformed(matrix,Qt::FastTransformation);
        pixmap_ =QPixmap::fromImage(imageee);
        //delete image;
        mutex->unlock();
        update();




}
void ExpandForm::gettriggerimage(QPixmap pixmap)
{
    pixmap_=pixmap.copy();
   src_w_h_ratio_ = static_cast<double>(pixmap_.width()) / static_cast<double>(pixmap_.height());
   update();
}

void ExpandForm::getimage(QQueue<QPixmap>ImageQueue,VisionDaHengCamera*camera)
{


    if (!ImageQueue.empty())
        {
        //cout << "Received a frame of image"+QDateTime::currentDateTime().toString("hh-mm-ss-zzz").toStdString() << endl;



                camera->mutex.lock();
                QPixmap newImage = camera->ImageQueue.dequeue();
               pixmap_=newImage.copy();
               camera->mutex.unlock();



           src_w_h_ratio_ = static_cast<double>(pixmap_.width()) / static_cast<double>(pixmap_.height());

        }

    update();



}

void ExpandForm::acceptautofocussignal()
{
    //cout<<"kkkkkkkkkk"<<endl;
    if(autofocus==true){
        autofocus=false;
    }else{
        autofocus=true;
    }
    update();

}

void ExpandForm::getresult(Mat image, vector<double> result)
{
    this->result=result;
    Mat image2;
    image.copyTo(image2);
    QImage  imgForDisplay = QImage((const uchar*)(image2.data), image2.cols, image2.rows, image2.cols * image2.channels(), QImage::Format_RGB888);
   //   QImage  imgForDisplay = QImage((const uchar*)(image.data), image.cols, image.rows, image.cols * image.channels(), QImage::Format_Indexed8);
    QPixmap pixmap =QPixmap::fromImage(imgForDisplay);
    pixmap_=pixmap.copy();

    update();



}

void ExpandForm::getresult_autofocus(vector<double> result)
{
    this->result_autofocus=result;
    update();
    //  cout<<"kkkkkkkkkk"<<endl;
}

void ExpandForm::paintEvent(QPaintEvent *) {

    QPainter painter(this);
    QPen pen;
    QFont font;
    font.setBold(true);
    font.setPixelSize(14);
    painter.setFont(font);


    if(pixmap_.isNull()) {
        //cout<<"kkk"<<endl;
        painter.fillRect(this->rect(), QColor(40, 40, 40));
    } else {

        int width = qMin(pixmap_.width() , this->width());
        int height = (width * 1.0)/(pixmap_.width()*1.0 / pixmap_.height());
        height = qMin(height , this->height());

        width = height * 1.0 *(pixmap_.width() *1.0 / pixmap_.height());
        // 平移
        painter.translate(this->width() / 2 +  XPtInterval, this->height() /2 +  YPtInterval);     // int X_move , Y_move ; x y 轴平移的距离
        // 缩放
        painter.scale(ZoomValue , ZoomValue);                                                        //qreal ZoomValue ；鼠标缩放位置
        // 绘制图像
        QRect pecRect(-width / 2 , -height /2 , width , height);

        width_=width;
        height_=height;
        //画显示框  前两个参数是坐标原地(0，0 在label 中心) 后两个天参数是长宽


        if(this->width()>width){
            QRect pecRect_2(-this->width() / 2 , -this->height() /2 , this->width()/2-width/2 , height);
            QRect pecRect_3(width/2 , -this->height() /2 , this->width()/2-width/2 , height);
            painter.fillRect(pecRect_2, QColor(40, 40, 40));
            painter.fillRect(pecRect_3, QColor(40, 40, 40));
        }
        if(this->height()>height){
            QRect pecRect_4(-this->width() / 2 , -this->height() /2 , width, this->height()/2-height/2);
            QRect pecRect_5(-this->width() /2  , height /2 , width, this->height()/2-height/2);
            painter.fillRect(pecRect_4, QColor(40, 40, 40));
            painter.fillRect(pecRect_5, QColor(40, 40, 40));
        }

        painter.drawPixmap(pecRect , pixmap_);



    }


}



void ExpandForm::SetVideoPixmap(QPixmap &pixmap) {
    /*  pixmap_ = pixmap;
    src_w_h_ratio_ = static_cast<double>(pixmap_.width()) / static_cast<double>(pixmap_.height());
    update();*/
}

//图片放大
void ExpandForm::OnZoomInImage()
{
    ZoomValue += 0.25;
    update();
}

//图片缩小
void ExpandForm::OnZoomOutImage()
{
    ZoomValue -= 0.25;
    if (ZoomValue <= 0)
    {
        ZoomValue = 0.05;
        return;
    }

    update();
}

//图片还原
void ExpandForm::OnPresetImage()
{
    ZoomValue = 1.0;
    XPtInterval = 0;
    YPtInterval = 0;
    update();
}

void ExpandForm::getzhenlv(double zhenlv)
{
    this->zhenlv=zhenlv;
}



void ExpandForm::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control)
    {
        setZoom(true);
    }
}
void  ExpandForm::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Control)
    {
        setZoom(false);
    }
}


//鼠标滚轮滚动
void ExpandForm::wheelEvent(QWheelEvent *event)
{
    if (!m_bZoom)
        return;
    int value = event->delta();
    if (value > 0)  //放大
        OnZoomInImage();
    else            //缩小
        OnZoomOutImage();

    update();
}

//鼠标双击还原图片大小事件
void ExpandForm::mouseDoubleClickEvent(QMouseEvent *event)
{

    if(autofocus){
       // cout<<"aaa"<<endl;
        emit autofocusstart();

    }else{
        OnPresetImage();
    }
}



//鼠标摁下
void ExpandForm::mousePressEvent(QMouseEvent *event)
{

    OldPos = event->pos();
  //   cout<<OldPos.x()-width_/2-50<<"-"<<OldPos.y()-height_/2<<endl;

        Pressed = true;


}

//鼠标松开
void ExpandForm::mouseMoveEvent(QMouseEvent *event)
{
    if (!Pressed)//如果不是按下拖动，则显示实时坐标的rgb
    {
        QPoint pos = event->pos();

        // cout << pos.x()<<endl;
        //  cout << pos.y()<<endl;
        return QWidget::mouseMoveEvent(event);
    }




    this->setCursor(Qt::SizeAllCursor);
    QPoint pos = event->pos();

    int xPtInterval = pos.x() - OldPos.x();
    int yPtInterval = pos.y() - OldPos.y();

    XPtInterval += xPtInterval;
    YPtInterval += yPtInterval;

    OldPos = pos;
    update();



}




void ExpandForm::mouseReleaseEvent(QMouseEvent *event)
{
    Pressed = false;
    setCursor(Qt::ArrowCursor);
}

bool ExpandForm::eventFilter(QObject *watched, QEvent *event)
{
    if(watched ==this && event->type() == QEvent::Paint)
    {
        update();
    }
    return QWidget::eventFilter(watched,event);
}
