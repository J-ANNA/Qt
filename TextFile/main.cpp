#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("D:/QtStudy/TextFile/textWriteFile.txt");
    if(file.open(QFile::WriteOnly | QFile::Truncate))     //Truncate: 将原来文件内容清空
    {
        QTextStream out(&file);
        out<<QObject::tr("Score:")<<" "<<90<<qSetFieldWidth(10)<<left<<qSetPadChar('a')<<endl;
    }


    return a.exec();
}
