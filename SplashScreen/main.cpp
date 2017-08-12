#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pix(":/new/prefix1/picture/8cm.jpg");
    QSplashScreen splash(pix);
    splash.show();
    a.processEvents();
    MainWindow w;

    QTime reachTime = QTime::currentTime().addMSecs(2000);
    while (QTime::currentTime() < reachTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }


    splash.finish(&w);
    w.show();
    return a.exec();
}
