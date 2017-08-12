#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QtNetwork/QTcpServer>
class Dialog;
class TimeServer : public QTcpServer
{
    Q_OBJECT
public:
    TimeServer(QObject *parent=0);
protected:
    /*重写此虚函数。这个函数在TCP服务器端有新的连接时被调用，其参数为所接收到新连接的套接字描述符（不需要自定义）*/
    void incomingConnection(int socketDescriptor);
private:
    /*用于记录创建这个TCP服务器端对象的父类，这里是界面指针，通过这个指针将线程发出的消息关联到界面的槽函数中，dlg为私有变量*/
    Dialog *dlg;
};

#endif // TIMESERVER_H
