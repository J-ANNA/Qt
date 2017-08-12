#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <stdio.h>
#include <QtDebug>

void asd();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    asd();
    QString str;
    str = "HELLO WORLD!";
    QByteArray ba;
    ba = str.toUtf8();
    qDebug()<<ba;
    qDebug()<<str;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void asd()
{
    //10行5列
   int **p;
   p = new int *[10];
   for(int i = 0;i<5;i++)
   {
       p[i] = new int[5];
   }

   p[2][3] = 3;
   qDebug()<<p[2][3]<<endl;

   int *m = new int[4];
   m[2] = 5;
   qDebug()<<m[2]<<endl;

   int n =10;
   int *t;
   t= &n;
   qDebug()<<*t<<endl;
   (*t)++;
   qDebug()<<t<<endl;
   qDebug()<<*t<<endl;


  int *tt;
  int aa = 0;
  tt = new int[10];
  for(int i = 0;i<10;i++)
  {
      tt[i] = 20;
  }

  for(int y = 0;y<10;y++)
  {
      aa+= tt[y];
  }

  qDebug()<<"aa = " <<aa<<endl;

  qDebug()<<sizeof(char)<<endl;




}

