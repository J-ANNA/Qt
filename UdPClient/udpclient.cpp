#include "udpclient.h"
#include <QVBoxLayout>
#include <QMessageBox>

UdpClient::UdpClient(QWidget *parent)
    : QDialog(parent)
{
    receivedTextEdit = new QTextEdit;
    closeBtn = new QPushButton(tr("Close"));
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(receivedTextEdit);
    mainLayout->addWidget(closeBtn);
    port =5555;
    udpSocket = new QUdpSocket(this);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(slotDataReceived()));
    connect(closeBtn,SIGNAL(clicked()),this,SLOT(slotCloseBtn()));

    bool result = udpSocket->bind(port);

    if(!result)
    {
        QMessageBox::information(this,tr("Error"),tr("udp socket create error!"));
        return;
    }

}

UdpClient::~UdpClient()
{

}

void UdpClient::slotCloseBtn()
{
    close();
}

void UdpClient::slotDataReceived()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg = datagram.data();
        receivedTextEdit->append(msg);
    }
}





















