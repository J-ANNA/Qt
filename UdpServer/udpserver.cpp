#include "udpserver.h"
#include <QVBoxLayout>
#include <QHostAddress>
#include <QDebug>

UdpServer::UdpServer(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UDP Server"));
    timeLabel = new QLabel(tr("计时器"));
    textLineEdit = new QLineEdit;
    startBtn = new QPushButton(tr("开始"));

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(10);
//    mainLayout->setAlignment(Qt::AlignRight);   //是设置自身，此函数不实现包含控件的对齐方式
    mainLayout->addWidget(timeLabel);
    timeLabel->setAlignment(Qt::AlignLeft);    //设置控件自身居中显示
    mainLayout->addWidget(textLineEdit);
    mainLayout->addWidget(startBtn);

    connect(startBtn,SIGNAL(clicked()),this,SLOT(slotStartBtn()));
    port = 5555;
    isStarted = false;
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);

    //定时发送广播信息
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimeout()));
}

UdpServer::~UdpServer()
{

}

void UdpServer::slotStartBtn()
{
    /*如果isStarted条件不成立(false),则执行...
      这里isStarted为false,即条件不成立*/
    if(!isStarted)                                      //等价于 if(isStarted == false)
    {
//        qDebug()<<!isStarted<<endl;
        startBtn->setText(tr("停止"));
        timer->start(1000);
        isStarted = true;
    }
    else
    {
        startBtn->setText(tr("开始"));
        isStarted = false;
        timer->stop();
    }
}

void UdpServer::slotTimeout()
{
    QString msg = textLineEdit->text();
    int length = 0;
    if(msg == "")
    {
        return;
    }
    /*msg.toLatin1(); --------单字节编码，向下兼容ASCII*/
    if((length = udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port)) != msg.length())
    {
        return;
    }
}









