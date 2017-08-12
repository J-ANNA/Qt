#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile data("data.txt");
    if(data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out<<QObject::tr("score:")<<qSetPadChar('a')<<qSetFieldWidth(6)<<left<<90<<endl;
    }

    QString str;
    QTextStream stream(&str);
    stream<<QObject::tr("test")<<qSetFieldWidth(10)<<center<<qSetPadChar('1')<<endl;
    qDebug()<<str<<endl;


    return a.exec();
}
