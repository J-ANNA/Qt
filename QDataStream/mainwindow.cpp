#include "mainwindow.h"
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fileFun();
}

MainWindow::~MainWindow()
{

}

void MainWindow::fileFun()
{
    QFile  file("binary.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);   //保存在build中
    QDataStream out(&file);
    out<<QString(tr("周何军："));
    out<<QDate::fromString("95/09/25","yy/MM/dd");
    out<<(qint32)19;
    file.close();

    QFile file2;
    file2.setFileName("binary.dat");
    file2.open(QIODevice::ReadOnly);                     //两者皆可
//    if(!file2.open(QIODevice::ReadOnly))              //必须保留,打开文件
//    {
//        qDebug()<<"error!"<<endl;
//        return;
//    }
    QDataStream in(&file2);
    QString name;
    QDate birthday;
    qint32 age;
    in>>name>>birthday>>age;
    qDebug()<<name<<birthday<<age<<endl;           //按保存的数据格式输出
    file2.close();


}


