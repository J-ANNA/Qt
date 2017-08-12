#include "timethread.h"

TimeThread::TimeThread(int socketDescriptor, QObject *parent):QThread(parent),socketDescriptor(socketDescriptor)
{

}

void TimeThread::run()
{
    QTcpSocket tcpSocket;
    if(!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        emit error(tcpSocket.error());
        return;
    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_4_3);             //使用此函数来修改所使用的DataStream序列化格式
    uint time2u = QDateTime::currentDateTime().toTime_t();  //类结构无法直接在网络间传输，此时需要将它转化为一个标准的数据类型
    out<<time2u;
    tcpSocket.write(block);
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}
