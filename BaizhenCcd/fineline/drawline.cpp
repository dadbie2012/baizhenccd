#include "drawline.h"

drawline::drawline(QWidget *parent)
{

}
void drawline::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen mPen(Qt::red);
    mPen.setWidth(0);
    painter->setPen(mPen);
    painter->drawLine(1618.25,1767.73,2935.47,1673.49);


    scene()->update();
}

