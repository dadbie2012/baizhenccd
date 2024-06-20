#include "myqgraphicsview.h"
#include <iostream>

myqgraphicsview::myqgraphicsview(QWidget *parent):QGraphicsView(parent)
{
    m_scaled=1;
    setRenderHint(QPainter::Antialiasing);
    centerOn(0, 0);
    setDragMode(ScrollHandDrag);
     this->setWindowFlags(Qt::Widget);
    viewport()->setCursor(Qt::ArrowCursor);
}

void myqgraphicsview::wheelEvent(QWheelEvent *event)
{
    // 当前放缩倍数;
    int wheelDeltaValue = event->delta();
    // 向上滚动，放大;
    if (wheelDeltaValue > 0)
    {
        this->scale(1.05, 1.05);
        m_scaled*=1.05;
    }
    // 向下滚动，缩小;
    else
    {
        this->scale(1/1.05, 1/1.05);
        m_scaled/=1.05;
    }
   // std::cout<<m_scaled<<std::endl;

}

void myqgraphicsview::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}


void myqgraphicsview::mouseMoveEvent(QMouseEvent *event)
{

    QGraphicsView::mouseMoveEvent(event);
}

void myqgraphicsview::mouseReleaseEvent(QMouseEvent *event)
{
    viewport()->setCursor(Qt::ArrowCursor);
    QGraphicsView::mouseReleaseEvent(event);
    viewport()->setCursor(Qt::ArrowCursor);
}

