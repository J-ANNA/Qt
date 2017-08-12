#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "svgwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createMenu();

public slots:
    void openFile();

private:
    SVGWindow *svgWindow;

};

#endif // MAINWINDOW_H
