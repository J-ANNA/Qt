#include "mainwindow.h"
#include <QGridLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("信号与槽"));
    noneBtn = new QPushButton(tr("none"));
    IntBtn = new QPushButton(tr("Int"));
    IntIntBtn = new QPushButton(tr("IntInt"));
    noneLineEdit = new QLineEdit;
    IntLineEdit = new QLineEdit;
    IntIntLineEdit = new QLineEdit;
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(noneBtn,0,0);
    mainLayout->addWidget(noneLineEdit,0,1);
    mainLayout->addWidget(IntBtn,1,0);
    mainLayout->addWidget(IntLineEdit,1,1);
    mainLayout->addWidget(IntIntBtn,2,0);
    mainLayout->addWidget(IntIntLineEdit,2,1);
    connect(noneBtn,SIGNAL(clicked()),this,SLOT(slotNoneBtn()));
    connect(IntBtn,SIGNAL(clicked()),this,SLOT(slotIntBtn()));
    connect(IntIntBtn,SIGNAL(clicked()),this,SLOT(slotIntIntBtn()));
    connect(this,SIGNAL(signalNone()),this,SLOT(slotNone()));
    connect(this,SIGNAL(signalInt(int)),this,SLOT(slotInt(int)));
    connect(this,SIGNAL(signalIntInt(int,int)),this,SLOT(slotIntInt(int,int)));

    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

}

MainWindow::~MainWindow()
{

}

void MainWindow::slotNone()
{
    noneLineEdit->setText(tr("none"));
}

void MainWindow::slotInt(int a)
{
    IntLineEdit->setText(QString::number(a));
}

void MainWindow::slotIntInt(int a, int b)
{
    IntIntLineEdit->setText(QString::number(a) + "," + QString::number(b));
}

void MainWindow::slotNoneBtn()
{
    emit signalNone();
}

void MainWindow::slotIntBtn()
{
    emit signalInt(12);
}

void MainWindow::slotIntIntBtn()
{
    emit signalIntInt(23,45);
}
