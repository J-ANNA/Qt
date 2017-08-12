#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("MouseEvent"));
    statusLabel = new QLabel;
    statusLabel->setText(tr("当前位置："));
    statusLabel->setFixedWidth(100);
    mousePosLabel = new QLabel;
    mousePosLabel->setText(tr(""));
    mousePosLabel->setFixedWidth(100);
    statusBar()->addPermanentWidget(statusLabel);         //statusBar():右对齐，得设置添加部件的固定宽度
    statusBar()->addPermanentWidget(mousePosLabel);
    this->setMouseTracking(true);          //设置窗体追踪鼠标.默认为false,按下鼠标时才相应鼠标移动事件
    resize(400,200);
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QString str = "("+QString::number(event->x())+","+QString::number(event->y())+")";
    if(event->button()==Qt::LeftButton)
    {
        statusBar()->showMessage(tr("左键：")+str);
    }
    else if(event->button()==Qt::RightButton)
    {
        statusBar()->showMessage(tr("右键：")+str);
    }
    else if(event->button()==Qt::MidButton)
    {
        statusBar()->showMessage(tr("中键：")+str);
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    mousePosLabel->setText("("+QString::number(event->x())+","+QString::number(event->y())+")");
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QString str = "("+QString::number(event->x())+","+QString::number(event->y())+")";
    statusBar()->showMessage(tr("释放在：")+str,3000);

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)         //原理和mousePressEvent()一样
{
//    QString str = "("+QString::number(event->x())+","+QString::number(event->y())+")";
//    if(event->button()==Qt::LeftButton)
//    {
//        statusBar()->showMessage(tr("左键：")+str);
//    }
//    else if(event->button()==Qt::RightButton)
//    {
//        statusBar()->showMessage(tr("右键：")+str);
//    }
//    else if(event->button()==Qt::MidButton)
//    {
//        statusBar()->showMessage(tr("中键：")+str);
//    }

}
