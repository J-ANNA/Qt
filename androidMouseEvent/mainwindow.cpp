#include "mainwindow.h"
#include <QScrollBar>
#include <QGesture>
#include <QPinchGesture>
#include <QTapGesture>
#include <QPanGesture>
#include <QSwipeGesture>
#include <QEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("androidMouseEvent"));
    printPage = new QFrame;
    scrollArea = new QScrollArea;
    scrollArea->showMaximized();
    printPage->resize(scrollArea->size());
    scrollArea->setWidget(printPage);
    setCentralWidget(scrollArea);

    printPage->grabGesture(Qt::PanGesture);
    printPage->grabGesture(Qt::SwipeGesture);
    printPage->grabGesture(Qt::PinchGesture);
    printPage->grabGesture(Qt::TapGesture);

    printPage->installEventFilter(this);
    printPagePixmap = new QPixmap;
    paintPrintPagePixmap();


}

MainWindow::~MainWindow()
{

}

void MainWindow::paintPrintPagePixmap()
{
    printPagePixmap->load(":/new/down.png");
    QPixmap *pix;
    if(printPage->width() == 0)
        pix = new QPixmap(500,500);
    else
        pix = new QPixmap(printPage->size());
    QPainter painter;
    painter.begin(pix);
    painter.drawPixmap(0,0,pix->width(),pix->height(),*printPagePixmap);
    painter.end();
    printPagePixmap = pix;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if((object == printPage) && (event->type() == QEvent::Gesture))
    {
        return gestureEvent(static_cast<QGestureEvent*>(event));
    }

    else if((object == printPage) && (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseMove))
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        switch (mouseEvent->type())
        {
        case QMouseEvent::MouseButtonPress:
        {
            lastMousePos = mouseEvent->pos();
            lastScrollBarValuesOnMousePos.rx() = scrollArea->horizontalScrollBar()->value();
            lastScrollBarValuesOnMousePos.ry() = scrollArea->verticalScrollBar()->value();
            mouseEvent->accept();
        }
            break;
        case QMouseEvent::MouseMove:
        {
            int horizontalValue,verticalValue;
            horizontalValue = lastScrollBarValuesOnMousePos.x() - mouseEvent->pos().x() + lastMousePos.x();
            verticalValue = lastScrollBarValuesOnMousePos.y() - mouseEvent->pos().y() + lastMousePos.y();
            scrollArea->horizontalScrollBar()->setValue(horizontalValue);
            scrollArea->verticalScrollBar()->setValue(verticalValue);
            scrollArea->horizontalScrollBar()->update();
            scrollArea->verticalScrollBar()->update();
            mouseEvent->accept();
        }
            break;
        default:
            break;
        }
    }

    if((event->type() == QEvent::Paint) && (object == printPage))
    {
        QPainter painter(printPage);
        painter.drawPixmap(QPoint(0,0),*printPagePixmap);
    }

    return QMainWindow::eventFilter(object, event);
}

bool MainWindow::gestureEvent(QGestureEvent *event)
{
    if(QGesture * pan = event->gesture(Qt::PanGesture))
        return panTriggered(static_cast<QPanGesture *>(pan));

    else if(QGesture * pinch = event->gesture(Qt::PinchGesture))
        return pinchTriggered(static_cast<QPinchGesture *>(pinch));

    else if(QGesture * tap = event->gesture(Qt::TapGesture))
        return tapTriggered(static_cast<QTapGesture *>(tap));

    else if(QGesture *swipe = event->gesture(Qt::SwipeGesture))
        return swipeTriggered(static_cast<QSwipeGesture *>(swipe));
    return true;

}

bool MainWindow::panTriggered(QPanGesture *panGesture)
{
    return true;
}

bool MainWindow::pinchTriggered(QPinchGesture *pinchGesture)
{
    QPinchGesture::ChangeFlags changeFlags = pinchGesture->changeFlags();
    if (changeFlags & QPinchGesture::ScaleFactorChanged)
    {
        qreal factor = pinchGesture->scaleFactor();
        if(factor > 1.10 || factor < 0.90)
            factor = (factor > 1.10) ? 1.10 : 0.90;
        qreal newWidth,newHeight;
        newWidth = printPage->width() * factor;
        newHeight = newWidth * 1.414;
        printPage->resize(newWidth,newHeight);
        paintPrintPagePixmap();
    }
    return true;
}

bool MainWindow::tapTriggered(QTapGesture *tapGesture)
{
    return true;
}

bool MainWindow::swipeTriggered(QSwipeGesture *swipeGesture)
{
    return true;
}

