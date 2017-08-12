#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QLinkedList"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   QMap<QString,QString> map;
   map.insert("beijing","111");
   map.insert("shanghai","113");
   QMutableMapIterator<QString,QString> i(map);
   if(i.findNext("111"))
       i.setValue("110");
   qDebug()<<i.key()<<":"<<i.value();

}

MainWindow::~MainWindow()
{
    delete ui;
}
