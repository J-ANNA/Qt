#include "timeserver.h"
#include "timethread.h"
#include "dialog.h"
#include <QDebug>

TimeServer::TimeServer(QObject *parent) :QTcpServer(parent)
{
    dlg = (Dialog *)parent;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
    TimeThread *thread = new TimeThread(socketDescriptor,0);    //接收的套接字符会变化968、1346、1436等类似
    connect(thread,SIGNAL(finished()),dlg,SLOT(slotShow()));   //线程结束，显示请求计数
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),Qt::DirectConnection);  //线程结束，结束线程
    thread->start();
    qDebug()<<socketDescriptor<<endl;

}
