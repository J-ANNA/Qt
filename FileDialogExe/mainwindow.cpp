#include "mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("FIleDialog Exe"));
    btn = new QPushButton(tr("打开"));
    connect(btn,SIGNAL(clicked()),this,SLOT(slotBtn()));
    resize(800,600);
    setCentralWidget(btn);

}

MainWindow::~MainWindow()
{

}

void MainWindow::slotBtn()
{
    MyFile *fileDialog = new MyFile;
    fileDialog->resize(200,400);

    QString str = fileDialog->getOpenFileName(this,"打开","/","files(* )");
}

MyFile::MyFile(QWidget *parent) : QFileDialog(parent)
{

}

MyFile::~MyFile()
{

}

void MyFile::resize(int w, int h)
{
    resize(w,h);
}
