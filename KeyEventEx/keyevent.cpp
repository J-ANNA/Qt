#include "keyevent.h"
#include <QPalette>
#include <QPainter>
#include <QPen>
#include <QPoint>

KeyEvent::KeyEvent(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("键盘事件"));
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);
    setMinimumSize(512,256);
    setMaximumSize(512,256);
    width = size().width();
    height = size().height();
    pix = new QPixmap(width,height);
    pix->fill(Qt::white);
    img.load(":/pic/8cm.jpg");
    startX = 100;
    startY = 100;
    step =20;
    drawPix();
    resize(512,256);

}

KeyEvent::~KeyEvent()
{

}

void KeyEvent::drawPix()
{
    pix->fill(Qt::white);
    QPainter *painter = new QPainter;
    QPen pen;
    pen.setStyle(Qt::DotLine);
    for(int i=step;i<width;i=i+step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        painter->end();
    }
    for(int j=step;j<height;j=j+step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(width,j));
        painter->end();
    }
    painter->begin(pix);
    painter->drawImage(QPoint(startX,startY),img);
    painter->end();


}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier)         //修饰键 ctrl
    {
        if(event->key()==Qt::Key_Left)
        {
            startX=(startX-1<0)?startX:startX-1;
        }
        else if(event->key()==Qt::Key_Right)
        {
            startX=(startX+1+img.width()>width)?startX:startX+1;
        }
        else if(event->key()==Qt::Key_Up)
        {
            startY=(startY-1<0)?startY:startY-1;
        }
        else if(event->key()==Qt::Key_Down)
        {
            startY=(startY+1+img.height()>height)?startY:startY+1;
        }
     }
    else
    {
        startX = startX-startX%step;          //调节图标左上顶点的位置至网格的顶点
        startY = startY-startY%step;
        if(event->key()==Qt::Key_Left)
        {
            startX=(startX-step<0)?startX:startX-step;
        }
        else if(event->key()==Qt::Key_Right)
        {
            startX=(startX+step+img.width()>width)?startX:startX+step;
        }
        else if(event->key()==Qt::Key_Up)
        {
            startY=(startY-step<0)?startY:startY-step;
        }
        else if(event->key()==Qt::Key_Down)
        {
            startY=(startY+step+img.height()>height)?startY:startY+step;
        }
        else if(event->key()==Qt::Key_Home)
        {
            startX = 0;
            startY = 0;
        }
        else if(event->key()==Qt::Key_End)
        {
            startX = width-img.width();
            startY = height-img.height();
        }
        else if(event->key()==Qt::Key_W)                    //W键
        {
            startY=(startY-step<0)?startY:startY-step;
        }

    }
    drawPix();
    update();
}



void KeyEvent::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}


