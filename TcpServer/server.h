#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include "tcpclientsocket.h"
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent=0,int port=0);
    QList<TcpClientSocket *> tcpClientSocketList;        //用来保存与每一个客户端连接的TcpClientSocket
signals:
    void signalUpdateServer(QString,int);
public slots:
    void slotUpdateClients(QString,int);
    void slotDisconnected(int);
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
