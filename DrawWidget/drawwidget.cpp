#include "drawwidget.h"
#include <QPen>
#include <QPixmap>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    setMinimumSize(600,400);

}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
    startPos = e->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
    QPainter *painter = new QPainter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style);    //类型转换: style表示当前选择的线型是Qt::PenStyle枚举数据中的第几个元素
    pen.setWidth(weight);
    pen.setColor(color);
    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startPos,e->pos());
    painter->end();
    startPos = e->pos();
    update();
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);

    paintNum++;
    emit signalPaintNum(paintNum);
}

void DrawWidget::resizeEvent(QResizeEvent *event)
{
    if(height()> pix->height()||width() > pix->width())   //命名最好不要与Qt自带名称一致  线宽命名为 width时，此句编译有误
//    if(width() > pix->width())
    {
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}

void DrawWidget::setStyle(int s)
{
    style = s;
}

void DrawWidget::setWidth(int w)
{
    weight = w;
}

void DrawWidget::setColor(QColor c)
{
    color = c;
}

void DrawWidget::clear()
{
    QPixmap *clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();   //重绘绘制区窗体
}

