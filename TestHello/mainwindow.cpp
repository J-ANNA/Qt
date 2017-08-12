#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(ui->pushButton_2->text() == "中国")
    {
        qDebug()<<"china"<<endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
