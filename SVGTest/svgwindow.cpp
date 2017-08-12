#include "svgwindow.h"

SVGWindow::SVGWindow(QWidget *parent) :QScrollArea(parent)
{
    svgWidget = new SVGWidget;
    setWidget(svgWidget);
}

void SVGWindow::setFile(QString fileName)
{
    svgWidget->load(fileName);
    QSvgRenderer *render = svgWidget->renderer();
    svgWidget->resize(render->defaultSize());

}

void SVGWindow::mousePressEvent(QMouseEvent *event)
{
    mousePressPos = event->pos();
    scrollBarValuesOnMousePress.rx() = horizontalScrollBar()->value();
    scrollBarValuesOnMousePress.ry() = verticalScrollBar()->value();
    event->accept();
}

void SVGWindow::mouseMoveEvent(QMouseEvent *event)
{
    horizontalScrollBar()->setValue(scrollBarValuesOnMousePress.x() - event->pos().x() + mousePressPos.x());
    verticalScrollBar()->setValue(scrollBarValuesOnMousePress.y() - event->pos().y() + mousePressPos.y());
    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    event->accept();
}

