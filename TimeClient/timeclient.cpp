#include "timeclient.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDataStream>
#include <QMessageBox>
#include <QDebug>

TimeClient::TimeClient(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("多线程时间服务客户端"));
    serverNameLabel = new QLabel(tr("服务器名："));
    serverNameLineEdit = new QLineEdit("Localhost");
    portLabel = new QLabel(tr("端口："));
    portLineEdit = new QLineEdit;
    dateTimeEdit = new QDateTimeEdit;
    stateLabel = new QLabel(tr("请先运行时间服务器"));
    getBtn = new QPushButton(tr("获取时间"));
    getBtn->setDefault(true);
    getBtn->setEnabled(false);
    quitBtn = new QPushButton(tr("退出"));
    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget(serverNameLabel,0,0);
    topLayout->addWidget(serverNameLineEdit,0,1);
    topLayout->addWidget(portLabel,1,0);
    topLayout->addWidget(portLineEdit,1,1);
    topLayout->addWidget(dateTimeEdit,2,0,1,2);
    topLayout->addWidget(stateLabel,3,0,1,2);
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch();
    btnLayout->addWidget(getBtn);
    btnLayout->addWidget(quitBtn);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(btnLayout);

    connect(serverNameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(enableGetBtn()));
    connect(portLineEdit,SIGNAL(textChanged(QString)),this,SLOT(enableGetBtn()));
    connect(getBtn,SIGNAL(clicked()),this,SLOT(getTime()));
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readTime()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(showError(QAbstractSocket::SocketError)));
    portLineEdit->setFocus();

}

TimeClient::~TimeClient()
{

}

void TimeClient::enableGetBtn()
{
    getBtn->setEnabled(!serverNameLineEdit->text().isEmpty()&&!portLineEdit->text().isEmpty());
}

void TimeClient::getTime()
{
    getBtn->setEnabled(false);
    time2u=0;
    tcpSocket->abort();                   //用于异常退出
    tcpSocket->connectToHost(serverNameLineEdit->text(),portLineEdit->text().toInt());
    qDebug()<<"getTime execute"<<endl;
}

void TimeClient::readTime()
{
    QDataStream in(tcpSocket);
//    in.setVersion(QDataStream::Qt_4_3);
    if(time2u==0)
    {
        if(tcpSocket->bytesAvailable()<(int)sizeof(uint))
            return;
        in>>time2u;
    }
    dateTimeEdit->setDateTime(QDateTime::fromTime_t(time2u));
    qDebug()<<time2u<<endl;
    getBtn->setEnabled(true);
    qDebug()<<"readTime execute"<<endl;
}

void TimeClient::showError(QAbstractSocket::SocketError socketError)
{
    switch(socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this,tr("时间服务客户端"),tr("主机不可达！"));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this,tr("时间服务客户端"),tr("连接被拒绝"));
        break;
    default:
        QMessageBox::information(this,tr("时间服务客户端"),tr("产生如下错误：%1.").arg(tcpSocket->errorString()));
        break;
    }
    getBtn->setEnabled(true);
}

















