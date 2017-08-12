#include "staritem.h"


StarItem::StarItem(QObject *parent) : QObject(parent)
{
    pix.load(":/star/star.jpg");
}

QRectF StarItem::boundingRect() const
{
    return QRectF(-pix.width()/2,-pix.height()/2,pix.width(),pix.height());
}

void StarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().topLeft(),pix);
}

