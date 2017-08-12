#ifndef SVGWINDOW_H
#define SVGWINDOW_H

#include <QScrollArea>
#include "svgwidget.h"

class SVGWindow : public QScrollArea
{
    Q_OBJECT
public:
    SVGWindow(QWidget *parent = 0);
    void setFile(QString);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private:
    SVGWidget *svgWidget;
    QPoint mousePressPos;
    QPoint scrollBarValuesOnMousePress;

};

#endif // SVGWINDOW_H
