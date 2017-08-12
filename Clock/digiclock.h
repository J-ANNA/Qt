#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QLCDNumber>
#include <QMouseEvent>
#include <QPoint>
#include <QLabel>


class DigiClock : public QLCDNumber
{
    Q_OBJECT
public:
    DigiClock(QWidget *parent=0);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
public slots:
    void showTime();
private:
    QPoint dragposition;  //保存鼠标点相对电子时钟窗体左上角的偏移值
    bool showColon;       //用于显示时间时是否显示":"
    QLabel *timeLabel;
};

#endif // DIGICLOCK_H
