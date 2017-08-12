#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QPixmap>
#include <QGestureEvent>
#include <QPoint>
#include <QPainter>
#include <QScrollArea>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool eventFilter(QObject *object, QEvent *event);
private:
    QScrollArea * scrollArea;
    QFrame * printPage;
    QPixmap *printPagePixmap;

    QPoint lastMousePos;
    QPoint lastScrollBarValuesOnMousePos;
    QVector<QPoint> mouseMovePos;

    QPoint lastScrollBarPoint;
    bool gestureEvent(QGestureEvent *event);
    bool panTriggered(QPanGesture *panGesture);
    bool pinchTriggered(QPinchGesture *pinchGesture);
    bool tapTriggered(QTapGesture *tapGesture);
    bool swipeTriggered(QSwipeGesture *swipeGesture);

    void paintPrintPagePixmap();

};

#endif // MAINWINDOW_H
