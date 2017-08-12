#ifndef SVGWIDGET_H
#define SVGWIDGET_H

#include <QSvgWidget>
#include <QtSvg>
#include <QSvgRenderer>


class SVGWidget : public QSvgWidget
{
    Q_OBJECT
public:
    SVGWidget(QWidget *parent =0);
    void wheelEvent(QWheelEvent *);
private:
    QSvgRenderer *render;
};

#endif // SVGWIDGET_H
