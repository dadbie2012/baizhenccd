﻿#ifndef CALIBERLINE_H
#define CALIBERLINE_H

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
#include "fineline/mycorneritem.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include<QtMath>


enum STATE_FLAG_ONELINE{
    DEFAULT_FLAG_OL=0,

    MOV_RECT_PT,
    MOV_ALL,
    MOV_LINE_BEGIN,
    MOV_LINE_END

};

class CCaliberLine:public QObject,public QGraphicsItem
{
public:
    CCaliberLine(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void setlinsize();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setpixmapwidth(qreal width){pixmap_width = width;}
    void setpixmapheight(qreal height){pixmap_height = height;}
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void setcalibernumber(int n){this->n = n;}
    qreal getwidth(){return width;}
    qreal getheight(){return height;}
    qreal getlength(){return length;}
    QPointF getbeginpoint(){return pt_begin;}
    QPointF getendpoint(){return pt_end;}
    QPointF pp[4]; //旋转后端点


private:
    qreal pixmap_width;
    qreal pixmap_height;
    QList<mycorneritem*> m_HandlesList_line;  //直线端点
    QList<mycorneritem*> m_HandlesList_refct; //可调控矩形端点
    bool if_create = false;
    bool if_create_move = false;
    bool if_handleslist_create = false;
    QRectF  first_rect; //可调控矩形
    QPolygonF first_poly; //可调控矩形旋转后
    QPointF first_center;
    QPointF pt[4]; //矩形端点

    QPointF m_startPos;
    STATE_FLAG_ONELINE m_StateFlag;
    bool if_hover = false;
    QPointF pt_begin; //直线起点
    QPointF pt_end;  //直线终点
    QPointF first_center_top; //pp[0] 与 pp[1]终点
    QPointF first_center_bottom; // pp[2] 与 pp[3]终点
    qreal width; //矩形宽度
    qreal height; //矩形高度
    qreal k; //直线斜率
    qreal length;
    int n;  //矩形个数

};

#endif // CALIBERLINE_H
