#include "form.h"
#include "ui_form.h"


Form::Form(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Form)

{
    ui->setupUi(this);
    setMouseTracking(true);
    this->installEventFilter(this);
    //this->resize(1550,367);
    //  this->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    // hide();
    //thread=new QThread;
    //    mythread->moveToThread(thread);
    autofocusrect.setLeft(50);//设置左上角x坐标
    autofocusrect.setTop(50); //设置左上角y坐标
    autofocusrect.setWidth(100); //设置 宽
    autofocusrect.setHeight(100);
    autofocus=false;
    zhenlv=0;
    exposetimeset=new exposetimesetting;
    createMenu();

}

Form::~Form()
{

    delete ui;
}
void Form::getqimage(QImage image,QMutex *mutex)
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
void Form::gettriggerimage(QPixmap pixmap)
{

    pixmap_=pixmap.copy();
    src_w_h_ratio_ = static_cast<double>(pixmap_.width()) / static_cast<double>(pixmap_.height());
    update();
}

void Form::getimage(QQueue<QPixmap>ImageQueue,VisionDaHengCamera*camera)
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
void Form::getimage2(Mat image)
{
    Mat image2;
    image.copyTo(sourceimage);
    // QImage  imgForDisplay = QImage((const uchar*)(sourceimage.data), sourceimage.cols, sourceimage.rows, sourceimage.cols * sourceimage.channels(), QImage::Format_RGB888);
    QImage  imgForDisplay = QImage((const uchar*)(sourceimage.data), sourceimage.cols, sourceimage.rows, sourceimage.cols * sourceimage.channels(), QImage::Format_Indexed8);
    QPixmap pixmap =QPixmap::fromImage(imgForDisplay);
    pixmap_=pixmap.copy();
    update();
}




void Form::getresult(Mat image,vector<double> result)
{

    Mat image2;
    image.copyTo(image2);
    QImage  imgForDisplay;
    if(image.channels()==1){
           imgForDisplay = QImage((const uchar*)(image2.data), image2.cols, image2.rows, image2.cols * image2.channels(), QImage::Format_Indexed8);
    }else{
           imgForDisplay = QImage((const uchar*)(image2.data), image2.cols, image2.rows, image2.cols * image2.channels(), QImage::Format_RGB888);
    }

    //  d8);
    QPixmap pixmap =QPixmap::fromImage(imgForDisplay);
    pixmap_=pixmap.copy();

    update();



}




void Form::paintEvent(QPaintEvent *) {

    QPainter painter(this);
    QPen pen;
    QFont font;
    font.setBold(true);
    font.setPixelSize(14);
    painter.setFont(font);
    int ipen = 0, irect = 0, iellipse = 0, iline = 0;  //工具索引

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
        if(num==1){
            QPen pen;
            pen.setColor(QColor(58, 58, 255));
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawRect(-40,-50,80,100);
        }
        if(drawrect_id==short_tanzhen){

            pen.setColor(QColor(58, 58, 255));
            pen.setWidth(0.5);
            painter.setPen(pen);
            painter.drawLine(-width / 2,0,width/2,0);
            painter.drawLine(0,-height/2 ,0,height/2);
            pen.setColor(QColor(255, 58, 255));
            pen.setWidth(0.5);
            painter.setPen(pen);
            painter.drawRect(QRect(-50,-2,100,4));
        }else if(drawrect_id==mid_tanzhen){
            pen.setColor(QColor(58, 58, 255));
            pen.setWidth(0.5);
            painter.setPen(pen);
            painter.drawLine(-width / 2,0,width/2,0);
            painter.drawLine(0,-height/2 ,0,height/2);
            pen.setColor(QColor(255, 58, 255));
            pen.setWidth(0.5);
            painter.setPen(pen);
            painter.drawRect(QRect(-81,-2,162,4));
        }else if(drawrect_id==long_tanzhen){
            pen.setColor(QColor(58, 58, 255));
            pen.setWidth(0.5);
            painter.setPen(pen);
            painter.drawLine(-width / 2,0,width/2,0);
            painter.drawLine(0,-height/2 ,0,height/2);
            pen.setColor(QColor(255, 58, 255));
            pen.setWidth(0.5);
            painter.setPen(pen);
            painter.drawRect(QRect(-110,-2,220,4));
        }
//        for (int c = 0; c <_shape.size(); ++c)  //循环重绘容器内所有项
//        {
//            QPen pen(QColor(_colors.at(c)));  //每次循环设置画笔
//            pen.setWidth(_widths.at(c));      //线宽
//            if (_isfills.at(c))               //填充
//            {
//                QBrush brush(QColor(_fillcolors.at(c)));
//                painter.setBrush(brush);
//            }
//            else
//            {
//                painter.setBrush(QBrush(Qt::NoBrush));
//            }
//            painter.setPen(pen);

//            if (_shape[c] == 1)  //铅笔线
//            {

//                const QVector<QPoint>& line = _pen.at(ipen++);  //分段绘制铅笔线
//                for (int j = 0; j < line.size() - 1; ++j) { painter.drawLine(QPoint(line.at(j).x()-this->width()/2,line.at(j).y()-this->height()/2), QPoint(line.at(j+1).x()-this->width()/2,line.at(j+1).y()-this->height()/2)); }
//            }  else if (_shape[c] == 2)  //矩形
//            {
//                painter.drawRect(_rects.at(irect));
//                irect++;
//            }else if (_shape[c] == 3)  //椭圆
//            {
//                painter.drawEllipse(_ellipse.at(iellipse));
//                iellipse++;
//            }   else if (_shape[c] == 4)  //直线
//            {
//                painter.drawLine(_line.at(iline).topLeft(), _line.at(iline).bottomRight());
//                double distance;
//                distance=double(sqrt(double(double(start.at(iline).x())-double(end.at(iline).x()))*(start.at(iline).x()-end.at(iline).x())+double((start.at(iline).y()-end.at(iline).y())*(start.at(iline).y()-end.at(iline).y()))));
//                distance=distance*(double(pixmap_.width())/double(width));
//                cout<<"aaa"<<start.at(iline).x()<<endl;
//                cout<<"bbb"<<start.at(iline).y()<<endl;
//                 cout<<"ccc"<<end.at(iline).x()<<endl;
//                 cout<<"ddd"<<end.at(iline).y()<<endl;
//                painter.drawText(QPoint((_line.at(iline).topLeft().x()+_line.at(iline).bottomRight().x())/2,(_line.at(iline).topLeft().y()+_line.at(iline).bottomRight().y())/2),QString::number(distance,10,1));
//                iline++;
//            }









//    }


}

}

void Form::SetVideoPixmap(QPixmap &pixmap) {
    /*  pixmap_ = pixmap;
    src_w_h_ratio_ = static_cast<double>(pixmap_.width()) / static_cast<double>(pixmap_.height());
    update();*/
}

//图片放大
void Form::OnZoomInImage()
{
    if(ifimageoperation){


        ZoomValue += 0.25;

    }
    update();
}

//图片缩小
void Form::OnZoomOutImage()
{
    if(ifimageoperation){
        ZoomValue -= 0.25;
        if (ZoomValue <= 0)
        {
            ZoomValue = 0.05;
            return;
        }
    }
    update();
}

//图片还原
void Form::OnPresetImage()
{
    if(ifimageoperation){
        ZoomValue = 1.0;
        XPtInterval = 0;
        YPtInterval = 0;
    }
    update();
}

void Form::getzhenlv(double zhenlv)
{
    this->zhenlv=zhenlv;
}



void Form::keyPressEvent(QKeyEvent *event)
{
    if(ifimageoperation){
        if (event->key() == Qt::Key_Control)
        {
            setZoom(true);
        }
    }
}
void  Form::keyReleaseEvent(QKeyEvent *event)
{
    if(ifimageoperation){
        if (event->key() == Qt::Key_Control)
        {
            setZoom(false);
        }
    }
}


//鼠标滚轮滚动
void Form::wheelEvent(QWheelEvent *event)
{ if(ifimageoperation){
        if (!m_bZoom)
            return;
        int value = event->delta();
        if (value > 0)  //放大
            OnZoomInImage();
        else            //缩小
            OnZoomOutImage();
    }
    update();
}

//鼠标双击还原图片大小事件
void Form::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(ifimageoperation){
        OnPresetImage();
    }
}



//鼠标摁下
void Form::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        m_pMenu->exec(QCursor::pos());
    }else{
        if(ifimageoperation){
            OldPos = event->pos();
            Pressed = true;
        }
    }
    if (event->button() == Qt::LeftButton)  //左键按下
    {  //铅笔
        if (_drawType == 1) {
            _lpress = true;  //按下标志为真
            QVector<QPoint> line;  //新铅笔线写入容器
            _pen.append(line);
            QVector<QPoint>& lastLine = _pen.last();
            lastLine.append(event->pos());  //新线条的开始坐标
            _colors.append(Qt::green);  //记录各种状态
            _fillcolors.append(Qt::red);
            _isfills.append(0);
            _widths.append(2);
            _shape.append(1);


        } else if (_drawType == 2)  //矩形
        {
            _lpress = true;
            if (!_drag)  //非拖拽
            {
                QRect rect;
                _rects.append(rect);
                QRect& lastRect = _rects.last();

                lastRect.setTopLeft(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));

                _colors.append(Qt::red);
                _fillcolors.append(Qt::red);
                _isfills.append(0);
                _widths.append(2);
                _shape.append(2);
             _allShape.append(_rects.last());
            }else if (_rects.last().contains(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2)))  //拖拽，鼠标在图形内部
            {
                _begin =QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2);  //记录起始的坐标
            }


    } else if (_drawType == 3)  //椭圆
        {
             _lpress = true;
            if (!circle_drag)
            {
                QRect rect;
                _ellipse.append(rect);
                QRect& lastEllipse = _ellipse.last();
                lastEllipse.setTopLeft( QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));
                _colors.append(Qt::blue);
                _fillcolors.append(Qt::red);
                _isfills.append(0);
                _widths.append(2);
                _shape.append(3);
                _allShape.append(_ellipse.last());
            }
            else if (_ellipse.last().contains(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2)))
            {
                _begin = QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2);
            }
        }else if (_drawType == 4)  //直线
        {
            _lpress = true;
            QRect rect;
            _line.append(rect);
            QRect& lastLine = _line.last();

            lastLine.setTopLeft( QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));
             start.push_back( QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));
            _colors.append(Qt::magenta);
            _fillcolors.append(Qt::magenta);
            _isfills.append(0);
            _widths.append(2);
            _shape.append(4);
            _allShape.append(_line.last());
        }


\




}

}

//鼠标松开
void Form::mouseMoveEvent(QMouseEvent *event)
{
    if(ifimageoperation){
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


    if (_lpress)
    {
        if (_drawType == 1)  //铅笔画线，下同
        {
            if (_pen.size() <= 0)  //容器非空
                return;

            QVector<QPoint>& lastLine = _pen.last();  //取得新线条
            lastLine.append(event->pos());                     //容器内存入线条轨迹

            update();                                      //更新画板
        }else if (_drawType == 2)  //矩形
        {
            if (_drag == 0)  //非拖拽
            {
                QRect& lastRect = _rects.last();
                lastRect.setBottomRight(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));  //更新右下角坐标
            }
            else  //拖拽
            {
                QRect& lastRect = _rects.last();
                if (lastRect.contains(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2)))  //在矩形的内部
                {
                    int dx = event->pos().x()-this->width()/2 - _begin.x();  //移动
                    int dy =event->pos().y()-this->height()/2 - _begin.y();
                    lastRect = lastRect.adjusted(dx, dy, dx, dy);  //更新位置
                    _begin =QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2);                        //刷新拖拽点起始坐标
                }
            }
            update();
        }else if (_drawType == 3)  //椭圆
        {
            if (circle_drag == 0)
            {
                QRect& lastEllipse = _ellipse.last();  //拿到椭圆
                lastEllipse.setBottomRight(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));       //更新椭圆右下角坐标
            }
            else
            {
                QRect& lastEllipse = _ellipse.last();
                if (lastEllipse.contains(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2)))
                {
                    int dx = event->pos().x()-this->width()/2 - _begin.x();  //移动
                    int dy =event->pos().y()-this->height()/2 - _begin.y();
                    lastEllipse = lastEllipse.adjusted(dx, dy, dx, dy);
                    _begin = QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2);
                }
            }
            update();
        } else if (_drawType == 4)  //直线
        {
            QRect& lastLine = _line.last();
            lastLine.setBottomRight( QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));
            if(end.size()<_line.size()){
               end.push_back( QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));
            }else{
            end[_line.size()-1]= QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2);
            }
            update();
        }




    }






}




void Form::mouseReleaseEvent(QMouseEvent *event)
{
    if(ifimageoperation){
        Pressed = false;
        setCursor(Qt::ArrowCursor);
    }
    if (_lpress)
    {
        if (_drawType == 1)  //铅笔线
        {
            QVector<QPoint>& lastLine = _pen.last();
            lastLine.append(event->pos());  //记录线条的结束坐标
            _lpress = false;       //标志左键释放
        } else if (_drawType == 2)  //矩形
        {
            QRect& lastRect = _rects.last();
            if (!_drag)  //非拖拽
            {
                lastRect.setBottomRight(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));  //更新右下角坐标

                this->cursor().setPos(this->cursor().pos().x() - lastRect.width() / 2,
                                      this->cursor().pos().y() - lastRect.height() / 2);  //光标置图形中心
                _drag = 1;                                                           //拖拽标志
            }
            _lpress = false;  //松开标志
        }  else if (_drawType == 3)  //椭圆
        {
            QRect& lastEllipse = _ellipse.last();
            if (!circle_drag)
            {
                lastEllipse.setBottomRight(QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));

                this->cursor().setPos(this->cursor().pos().x() - lastEllipse.width() / 2,
                                      this->cursor().pos().y() - lastEllipse.height() / 2);
               circle_drag = 1;
            }
            _lpress = false;
        }  else if (_drawType == 4)  //直线
        {
            QRect& lastLine = _line.last();
            lastLine.setBottomRight( QPoint(event->pos().x()-this->width()/2,event->pos().y()-this->height()/2));
            _lpress = false;
        }






    }
}

bool Form::eventFilter(QObject *watched, QEvent *event)
{
    if(watched ==this && event->type() == QEvent::Paint)
    {
        update();
    }
    return QWidget::eventFilter(watched,event);
}

void Form::createMenu()
{
    m_pMenu = new QMenu(this);
    imageoperation = m_pMenu->addAction(tr("image operation"));
     setstraightline = m_pMenu->addAction(tr("draw straight line"));
    setline = m_pMenu->addAction(tr("draw line"));
    setrect = m_pMenu->addAction(tr("draw rect"));
    setcircle = m_pMenu->addAction(tr("draw circle"));
     deletestraightline = m_pMenu->addAction(tr("delete straight line"));
    deleteline=m_pMenu->addAction(tr("delete line"));
    deleterect=m_pMenu->addAction(tr("delete rect"));
    deletecircle=m_pMenu->addAction(tr("delete cirle"));
    deleteall=m_pMenu->addAction(tr("delete all"));
    exposetime=m_pMenu->addAction(tr("ExposeTime"));
    m_pMenu->addSeparator();
    m_pMenu->setStyleSheet("QMenu {background-color: white;}");
    connect(imageoperation,&QAction::triggered,this,[&](){
        cout<<"imageoperation"<<endl;
        _drawType=0;
        ifimageoperation=true;
    });
    connect(setstraightline,&QAction::triggered,this,[&](){
        cout<<"setstraightline"<<endl;
        _drawType=4;
        ifimageoperation=false;
    });
    connect(setline,&QAction::triggered,this,[&](){
        cout<<"setline"<<endl;
        _drawType=1;
        ifimageoperation=false;
    });
    connect(setrect,&QAction::triggered,this,[&](){
        cout<<"setrect"<<endl;
        _drawType=2;
        ifimageoperation=false;
    });
    connect(setcircle,&QAction::triggered,this,[&](){
        cout<<"setcircle"<<endl;
        _drawType=3;
        ifimageoperation=false;
    });
    connect(deleteline,&QAction::triggered,this,[&](){
        cout<<"deleteline"<<endl;
        _drawType=0;
        _pen.clear();
        _shape.erase(std::remove(_shape.begin(), _shape.end(), 1), _shape.end());
        ifimageoperation=false;
    });
    connect(deleterect,&QAction::triggered,this,[&](){
        cout<<"deleterect"<<endl;
        _rects.clear();
        _shape.erase(std::remove(_shape.begin(), _shape.end(),2), _shape.end());
        _drag=0;
        ifimageoperation=false;
    });
    connect(deletecircle,&QAction::triggered,this,[&](){
        cout<<"deletecircle"<<endl;
        _ellipse.clear();
        _shape.erase(std::remove(_shape.begin(), _shape.end(),3), _shape.end());
        circle_drag=0;
        ifimageoperation=false;
    });
    connect(deletestraightline,&QAction::triggered,this,[&](){
        cout<<"deletestraightline"<<endl;
        _drawType=0;
        _line.clear();
        _shape.erase(std::remove(_shape.begin(), _shape.end(),4), _shape.end());
        ifimageoperation=false;

    });
    connect(deleteall,&QAction::triggered,this,[&](){
         _ellipse.clear();
         _line.clear();
         _rects.clear();
          _pen.clear();
          _shape.clear();
          _drag=0;
            circle_drag=0;
        cout<<"deleteall"<<endl;
    });
    connect(exposetime,&QAction::triggered,this,[&](){

        exposetimeset->exposetimeget(id);
        exposetimeset->show();

    });


}
