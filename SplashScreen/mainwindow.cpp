#include "mainwindow.h"
#include <QFont>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(400,400);
    QFont font = QFont("宋体",20);
    QLabel *label = new QLabel(this);
    label->setFont(font);
    label->setText(tr("saaaaaaaaaaaaaa"));



}

MainWindow::~MainWindow()
{

}
