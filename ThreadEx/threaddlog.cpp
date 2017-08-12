#include "threaddlog.h"
#include <QHBoxLayout>

ThreadDlog::ThreadDlog(QWidget *parent)
    : QDialog(parent)
{
    startBtn = new QPushButton(tr("开始"));
    startBtn->setEnabled(true);
    stopBtn = new QPushButton(tr("停止"));
    stopBtn->setEnabled(false);
    exitBtn = new QPushButton(tr("退出"));
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(20);
    mainLayout->addWidget(startBtn);
    mainLayout->addWidget(stopBtn);
    mainLayout->addWidget(exitBtn);
    setWindowTitle(tr("线程"));
    connect(startBtn,SIGNAL(clicked()),this,SLOT(slotStart()));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(slotStop()));
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(close()));

}

ThreadDlog::~ThreadDlog()
{

}

void ThreadDlog::slotStart()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i] = new WorkThread;
    }
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i]->start();
    }
    startBtn->setEnabled(false);
    stopBtn->setEnabled(true);

}

void ThreadDlog::slotStop()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i]->terminate();           //线程终止，具体何时终止取决于操作系统的调度策略
        workThread[i]->wait();               //紧接着调用wait(),使线程阻塞等待直到退出或超时
    }
    startBtn->setEnabled(true);
    stopBtn->setEnabled(false);
}






