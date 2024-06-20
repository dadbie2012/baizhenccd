#ifndef CONTROLLINE_H
#define CONTROLLINE_H
#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QRect>
#include <QPainter>
#include <QPolygon>
#include <QList>
#include <QDebug>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


class CControlLine:public QObject,public QGraphicsItem
{
public:
    CControlLine(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void addedgepoints(QPointF pt);
    void addedgeexpectpoints(QPointF pt);
    void setline(QPointF pt1, QPointF pt2){linestart = pt1; lineend=pt2;}
~CControlLine()
    {
        qDebug() << "~one_line";
    }

private:
    QPointF linestart;
    QPointF lineend;
    QList<QPointF> edgepoints;
    bool draw_edge = false;
    QList<QPointF> edgeexpectpoints;
    bool draw_expect = false;
};

#endif
