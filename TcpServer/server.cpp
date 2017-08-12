#include "server.h"

Server::Server(QObject *parent, int port) :QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

void Server::slotUpdateClients(QString msg, int length)
{
    emit signalUpdateServer(msg,length);                  //发出signalUpdateServer信号，用来通知服务器对话框更新相应的显示状态
    foreach(QTcpSocket *item,tcpClientSocketList)
    {
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }
}

void Server::slotDisconnected(int descriptor)
{
   for(int i=0;i<tcpClientSocketList.count();i++)
   {
       QTcpSocket *item = tcpClientSocketList.at(i);
       if(item->socketDescriptor()==descriptor)
       {
           tcpClientSocketList.removeAt(i);
           return;
       }
   }
   return;
}

void Server::incomingConnection(int socketDescriptor)
{
    TcpClientSocket *tcpClientSocket = new TcpClientSocket(this);
    connect(tcpClientSocket,SIGNAL(signalUpdateClients(QString,int)),this,SLOT(slotUpdateClients(QString,int)));
    connect(tcpClientSocket,SIGNAL(signalDisconnected(int)),this,SLOT(slotDisconnected(int)));
    tcpClientSocket->setSocketDescriptor(socketDescriptor);
    tcpClientSocketList.append(tcpClientSocket);
}
