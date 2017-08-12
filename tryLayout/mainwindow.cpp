#include "mainwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    QLabel *label1 = new QLabel(tr("Label1"));
    QLabel *label2 = new QLabel(tr("Label2"));

    layout->addWidget(label1);
    layout->addWidget(label2);



}

MainWindow::~MainWindow()
{

}
