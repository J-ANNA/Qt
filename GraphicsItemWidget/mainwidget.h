#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QFrame>
#include <QPixmap>
#include "pixitem.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void createControlFrame();
private:
    int angle;
    qreal scaleValue;
    qreal shearValue;
    qreal translateValue;
    QFrame *ctrlFrame;
    QGraphicsView *view;
    QPixmap *pixmap;
    PixItem *pixItem;

private slots:
    void slotRotate(int);
    void slotScale(int);
    void slotShear(int);
    void slotTranslate(int);


};

#endif // MAINWIDGET_H
