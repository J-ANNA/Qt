#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("多线程时间服务器"));
    monitorPortLabel = new QLabel(tr("服务器端口"));
    requestNumlabel = new QLabel;
    quitBtn = new QPushButton(tr("退出"));
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch(1);
    btnLayout->addWidget(quitBtn);
    btnLayout->addStretch(1);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(monitorPortLabel);
    mainLayout->addWidget(requestNumlabel);
    mainLayout->addLayout(btnLayout);
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));

    count =0;
    timeServer = new TimeServer(this);
    if(!timeServer->listen())
    {
        QMessageBox::critical(this,tr("多线程时间服务器"),tr("无法启动服务器：1%.").arg(timeServer->errorString()));
        close();
        return;
    }
    monitorPortLabel->setText(tr("服务器端口：%1").arg(timeServer->serverPort()));        //服务端口每次也会变化 56541
}

void Dialog::slotShow()
{
    requestNumlabel->setText(tr("第%1次请求完毕.").arg(++count));
}


Dialog::~Dialog()
{

}


