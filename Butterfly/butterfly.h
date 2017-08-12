#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QRectF>

class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = 0);
    void timerEvent(QTimerEvent *);  //在定时器timerEvent()中对QgraphicsItem进行重绘
    QRectF boundingRect() const;      //为图元限定区域范围，所有继承自QGraphicsItem的自定义图元都必须实现此函数


signals:

public slots:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);  //重绘函数
private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;
    qreal angle;             //qreal 相当于 double
};

#endif // BUTTERFLY_H
