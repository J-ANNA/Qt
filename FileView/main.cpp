#include "mainwindow.h"
#include <QApplication>
#include "fileview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    FileView fw;
    fw.show();


    return a.exec();
}
