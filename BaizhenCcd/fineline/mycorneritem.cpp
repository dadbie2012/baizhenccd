﻿#include "mycorneritem.h"

mycorneritem::mycorneritem(QGraphicsItem * parent,
                           QPointF point,
                           CornerDirction dir
                           )
    :QAbstractGraphicsShapeItem(parent)
    , m_point(point)
    ,m_Dir(dir)
{
    setAcceptHoverEvents(true);
    m_scaleFactor = 1;
    m_bSelect = false;
    m_brush = QBrush(Qt::white);
}

void mycorneritem::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    m_scaleFactor = painter->matrix().m11();
    painter->save();
    QPen pen;
    pen.setWidth(0);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    painter->setBrush(m_brush);
    painter->setRenderHint(QPainter::Antialiasing, false);

    painter->drawEllipse(m_point, CORNER_SIZE/ m_scaleFactor,
                         CORNER_SIZE/ m_scaleFactor);
    painter->restore();
}

bool mycorneritem::hitTest(const QPointF & point)
{
    return boundingRect().contains(point);
}

void mycorneritem::setState(SelectionHandleState state)
{
    if (state == m_State)
        return;
    switch (state) {
    case SelectionHandleOff:
        hide();
        break;
    case SelectionHandleInactive:
    case SelectionHandleActive:
        show();
        break;
    }
    m_State = state;
}

void mycorneritem::move(QPointF point)
{
    if (point == m_point)
        return;
    //moveBy(0, 0);
    m_point = point;
    update();
}

void mycorneritem::cornerTranslate(QPointF point)
{
    QPointF local = point + boundingRect().topLeft();
    QRectF delta = QRectF(local, boundingRect().size());
    prepareGeometryChange();
    m_point = delta.center();
    update();
}

QRectF mycorneritem::boundingRect() const
{
    double centerX = m_point.x() - CORNER_SIZE * 2 / m_scaleFactor / 2;
    double centerY = m_point.y() - CORNER_SIZE * 2 / m_scaleFactor / 2;

    return QRectF(centerX, centerY, CORNER_SIZE * 2 / m_scaleFactor,
                  CORNER_SIZE * 2 / m_scaleFactor);
}

qreal mycorneritem::getboundingrectwidth()
{
    return (CORNER_SIZE * 2 / m_scaleFactor)*(CORNER_SIZE * 2 / m_scaleFactor);
}

void mycorneritem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_ptPress = event->scenePos();
        m_ptMove = event->scenePos();
        m_bSelect = true;
    }
    QGraphicsItem::mousePressEvent(event);
}

void mycorneritem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons()&Qt::LeftButton)
    {
        m_ptMove = event->scenePos();
        QPointF pt = mapFromScene(m_ptMove) - mapFromScene(m_ptPress);
        m_ptPress = event->scenePos();
        cornerTranslate(pt);
    }
    QGraphicsItem::mouseMoveEvent(event);

}

void mycorneritem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    Q_UNUSED(event)
}

void mycorneritem::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    switch (m_Dir)
    {
    case LeftTop:
    case RightBottom:
        setCursor(Qt::SizeFDiagCursor);
        break;
    case LeftBottom:
    case RightTop:
        setCursor(Qt::SizeBDiagCursor);
        break;
    case Top:
    case Bottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case Left:
    case Right:
        setCursor(Qt::SizeHorCursor);
        break;
    case Rotation:
        setCursor(Qt::SizeHorCursor);
        break;
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
    m_brush = QBrush(Qt::green);
    update();
    QGraphicsItem::hoverEnterEvent(event);
}

void mycorneritem::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
    switch (m_Dir)
    {
    case LeftTop:
    case RightBottom:
        setCursor(Qt::SizeFDiagCursor);
        break;
    case LeftBottom:
    case RightTop:
        setCursor(Qt::SizeBDiagCursor);
        break;
    case Top:
    case Bottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case Left:
    case Right:
        setCursor(Qt::SizeHorCursor);
        break;
    case Rotation:
        setCursor(Qt::SizeHorCursor);
        break;
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
    m_brush = QBrush(Qt::green);
    update();
    QGraphicsItem::hoverEnterEvent(event);
}

void mycorneritem::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
    m_bSelect = false;
    m_brush = QBrush(Qt::white);
    update();
    QGraphicsItem::hoverLeaveEvent(event);
}
