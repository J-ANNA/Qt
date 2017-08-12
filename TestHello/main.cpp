#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator *translator = new QTranslator;
    translator->load("D:/QtStudy/TestHello/TestHello");
    a.installTranslator(translator);
    MainWindow w;
    w.show();

    return a.exec();
}
