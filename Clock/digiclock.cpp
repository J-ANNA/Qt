#include "digiclock.h"
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QPalette>
#include <QString>
#include <QLabel>
#include <QDebug>

DigiClock::DigiClock(QWidget *parent) :QLCDNumber(parent)
{
    setAutoFillBackground(true);
    timeLabel = new QLabel(this);
    timeLabel->setAutoFillBackground(true);
    QPalette timePalette = timeLabel->palette();
    timePalette.setColor(QPalette::Window,Qt::yellow);
    timeLabel->setPalette(timePalette);

    QPalette timeTextPalette = timeLabel->palette();
    timeTextPalette.setColor(QPalette::WindowText,Qt::red);
    timeLabel->setPalette(timeTextPalette);

    QPalette p = palette();
    QPalette pText = palette();
    pText.setColor(QPalette::WindowText,Qt::yellow);
    p.setColor(QPalette::Window,Qt::blue);
    setPalette(pText);
    setPalette(p);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    showTime();
    resize(150,60);
    showColon = true;


}

void DigiClock::showTime()
{
    QTime time = QTime::currentTime();
    QString timeString = time.toString("hh:mm");
    if(showColon)
    {
        timeString[2] = ':';
        showColon = false;
    }
    else
    {
        timeString[2] = ' ';
        showColon = true;
    }
//    timeLabel->setText(timeString);

    display(timeString);
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragposition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    else if(event->button()==Qt::RightButton)
    {
        close();
    }
}

void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&&Qt::LeftButton)
    {
        move(event->globalPos()-dragposition);
        event->accept();
    }
}


















