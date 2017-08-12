#include "paintarea.h"
#include <QPainter>
#include <QPoint>
#include <QPainterPath>

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setMinimumSize(400,400);
}

void PaintArea::setShape(Shape s)
{
    shape = s;
    update();
}

void PaintArea::setPen(QPen p)
{
    pen = p;
    update();
}

void PaintArea::setBrush(QBrush b)
{
    brush = b;
    update();
}

void PaintArea::setFillRule(Qt::FillRule rule)
{
    fillRule = rule;
    update();
}

void PaintArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    QRect rect(50,100,300,200);
    static const QPoint points[4] =
    {
        QPoint(150,100),
        QPoint(300,150),
        QPoint(350,250),
        QPoint(100,300)
     };
    int startAngle = 30*16;
    int spanAngle = 120*16;
    QPainterPath path;
    path.addRect(150,150,100,100);
    path.moveTo(100,100);
    path.cubicTo(300,100,200,200,300,300);
    path.cubicTo(100,300,200,200,100,100);
    path.setFillRule(fillRule);

    switch(shape)
    {
    case Line:
        painter.drawLine(rect.topLeft(),rect.bottomRight());
        break;
    case Rectangle:
        painter.drawRect(rect);
        break;
    case RoundRect:
        painter.drawRoundRect(rect);
        break;
    case Ellipse:
        painter.drawEllipse(rect);         //???
        break;
    case Polygon:
        painter.drawPolygon(points,4);
        break;
    case Polyline:
        painter.drawPolyline(points,4);
        break;
    case Points:
        painter.drawPoints(points,4);
        break;
    case Arc:
//        painter.drawArc(rect,startAngle,spanAngle);

        painter.drawArc(0,0,20,20,270*16,90*16);
        break;
    case Path:
        painter.drawPath(path);
        break;
    case Text:
        painter.drawText(rect,Qt::AlignCenter,tr("Hello Qt!"));
        break;
    case Pixmap:
        painter.drawPixmap(150,150,QPixmap(":/picture/picture/8cm.jpg"));
        break;
    default:
        break;

    }

}


