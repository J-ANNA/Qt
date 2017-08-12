#include "butterfly.h"
#include <math.h>
const static double PI=3.1416;

//: QObject(parent),QGraphicsItem()
Butterfly::Butterfly(QObject *parent)
{
    up = true;
    pix_up.load(":/butterfly/picture/up.png");
    pix_down.load(":/butterfly/picture/down.png");
    startTimer(100);
}

void Butterfly::timerEvent(QTimerEvent *)
{
    //边界控制
    qreal edgeX = scene()->sceneRect().right() + boundingRect().width()/2;                 //右边界
    qreal edgeTop = scene()->sceneRect().top() + boundingRect().height()/2;                //上边界
    qreal edgeBottom = scene()->sceneRect().bottom() + boundingRect().height()/2;          //下边界
    if(pos().x()>=edgeX)
    {
        setPos(scene()->sceneRect().left(),pos().y());

    }
    else if(pos().y()<=edgeTop)
    {
        setPos(pos().x(),scene()->sceneRect().bottom());
    }
    else if(pos().y()>=edgeBottom)
    {
        setPos(pos().x(),scene()->sceneRect().top());
    }
    angle +=(qrand()%10)/20.0;
    qreal dx=fabs(sin(angle*PI)*10.0);
    qreal dy=(qrand()%20)-10.0;
    setPos(mapToParent(dx,dy));    //完成蝴蝶随机飞行的路径
//    update();

}

QRectF Butterfly::boundingRect() const          //此范围以图元自身的坐标系为基础设定的
{
    qreal adjust = 2;
    return QRectF(-pix_up.width()/2-adjust,-pix_up.height()/2-adjust,
                  pix_up.width()+adjust*2,pix_up.height()+adjust*2);

}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(up)
    {
        painter->drawPixmap(boundingRect().topLeft(),pix_up);
        up = !up;
    }
    else
    {
        painter->drawPixmap(boundingRect().topLeft(),pix_down);
        up = !up;
    }
}

