#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(slotDataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

void TcpClientSocket::slotDataReceived()
{
    while(bytesAvailable()>0)
    {
        int length = bytesAvailable();
        char buff[1024];
        read(buff,length);
        QString msg =buff;
        emit signalUpdateClients(msg,length);
    }
}

void TcpClientSocket::slotDisconnected()
{
    emit signalDisconnected(this->socketDescriptor());
}
