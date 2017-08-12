#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <stdio.h>


const int dataSize = 1000;
const int bufferSize = 80;
int buffer[bufferSize];                 //每个int字长被看成一个资源
QSemaphore freeBytes(bufferSize);      //一开始有bufferSize个缓冲区可被填充
QSemaphore usedBytes(0);               //一开始缓冲区中没有数据可供读取

class Producer :public QThread
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
        freeBytes.acquire();                         //获取一个空闲单元
                                                     //acquire(n);用于获取n个资源
                                                     //tryAcquire(n);在没有足够的资源时，该函数会立即返回
        buffer[i%bufferSize] = (i%bufferSize);       //填写缓存单元
        usedBytes.release();                          //释放资源（将可用资源加1）
                                                      //release(n);用于释放n个资源

    }
}

class Consumer :public QThread
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
    for(int i=0;i<dataSize;i++)
    {
        usedBytes.acquire();                           //获取可被读取单元
        fprintf(stderr,"%d",buffer[i%bufferSize]);      //打印单元内容
        if(i%16==0&&i!=0)
        {
            fprintf(stderr,"\n");   //换行
        }
        freeBytes.release();                      //释放单元，单元变为空闲，可供下次填充
    }
    fprintf(stderr,"\n");         //换行
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
    return a.exec();


    return a.exec();
}

