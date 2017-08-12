#include <QCoreApplication>
#include <QStringList>
#include <QDir>
#include <QDebug>

qint64 du(const QString &path)
{
    QDir dir(path);
    qint64 size =0;
    foreach (QFileInfo fileInfo, dir.entryInfoList(QDir::Files)) {
        size +=fileInfo.size();                                    //根目录大小
    }
    foreach (QString subDir, dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot)) {
        size += du(path+QDir::separator()+subDir);                 //二级子目录大小
    }
    char unit = 'B';
    qint64 cursize = size;
    if(cursize>1024)
    {
        cursize /=1024;
        unit = 'K';
        if(cursize>1024)
        {
            cursize /=1024;
            unit = 'M';
            if(cursize>1024)
            {
                cursize /=1024;
                unit ='G';
            }
        }
    }
    qDebug()<<cursize<<unit<<"\t"<<qPrintable(path)<<endl;
    return size;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList args = a.arguments();
    QString path;
    if(args.count()>1)
    {
        path =args[1];
        qDebug()<<"args[1]"<<endl;
    }
    else
    {
        path = QDir::currentPath();                //path
        qDebug()<<"currentPath"<<endl;
    }
    qDebug()<<path<<endl;
    du(path);


    return a.exec();
}
