#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include <QStatusBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
//    void mouseGrabber();              //返回当前抓取鼠标输入的部件，如果没有任何部件正在抓取鼠标，则返回0
private:
    QLabel *statusLabel;
    QLabel *mousePosLabel;
};

#endif // MAINWINDOW_H
