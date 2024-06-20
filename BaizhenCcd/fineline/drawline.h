#ifndef DRAWLINE_H
#define DRAWLINE_H
#include <QRect>
#include <QPainter>
#include <QPolygon>
#include <QList>
#include <QDebug>
#include <cmath>
#include <iostream>
#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>


class drawline:public QObject,public QGraphicsItem
{
public:
    drawline(QWidget *parent);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // DRAWLINE_H
