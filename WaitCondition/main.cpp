#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <stdio.h>
#include <QDebug>

const int dataSize = 1000;
const int bufferSize = 80;
int buffer[bufferSize];
QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;                  //使用互斥量保证对线程操作的原子性(不可再分性)
int numUsedBytes=0;            //表示存在多少"可用字节"
int rIndex = 0;                    //指示当前所读取缓冲区位置

class Producer : public QThread
{
public:
    Producer();
    void run();
};


Producer::Producer()
{

}

void Producer::run()
{
    for(int i=0;i<dataSize;i++)
    {
        mutex.lock();
        if(numUsedBytes==bufferSize)
        {
            bufferEmpty.wait(&mutex);
        }
        buffer[i%bufferSize]=numUsedBytes;
        ++numUsedBytes;
        bufferFull.wakeAll();   //在条件满足时唤醒所有等待线程； wakeOne()随进唤醒一个等待线程
        mutex.unlock();
    }
}


class Consumer : public QThread
{
public:
    Consumer();
    void run();
};


Consumer::Consumer()
{

}

void Consumer::run()
{
    forever
    {
        mutex.lock();
        if(numUsedBytes==0)
            bufferFull.wait(&mutex);
        printf("%lu::[%d]=%d\n",currentThreadId(),rIndex,buffer[rIndex]);
        rIndex =(++rIndex)%bufferSize;
        --numUsedBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
    printf("\n");
    printf("%d%s\n",buffer[11],"sss");
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Producer producer;
    Consumer consumerA;
    Consumer consumerB;
    producer.start();
    consumerA.start();
    consumerB.start();
    producer.wait();
    consumerA.wait();
    consumerB.wait();
    return a.exec();
}























