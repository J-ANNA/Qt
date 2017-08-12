#ifndef STARITEM_H
#define STARITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class StarItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit StarItem(QObject *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap pix;

signals:

public slots:
};

#endif // STARITEM_H
