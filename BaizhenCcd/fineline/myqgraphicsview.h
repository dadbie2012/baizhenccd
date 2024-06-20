#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

#include <QWidget>
class myqgraphicsview:public QGraphicsView
{
public:
    myqgraphicsview(QWidget *parent);
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    qreal m_scaled;
};

#endif // MYQGRAPHICSVIEW_H
