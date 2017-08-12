#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    float *x;
    float *y;

    void change();
    void show2();

public slots:
    void showSlot();


};

#endif // MAINWINDOW_H
