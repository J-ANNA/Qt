#include "mainwindow.h"
#include <QVBoxLayout>
#include <QTableView>
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,400);
    QTableView *view = new QTableView;
    view->resize(200,200);


}

MainWindow::~MainWindow()
{

}
















