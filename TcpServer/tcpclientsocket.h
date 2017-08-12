#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpClientSocket(QObject *parent=0);
signals:
    void signalUpdateClients(QString,int);
    void signalDisconnected(int);
protected slots:
    void slotDataReceived();
    void slotDisconnected();
};

#endif // TCPCLIENTSOCKET_H
