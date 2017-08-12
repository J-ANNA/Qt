#include "mainwindow.h"
#include <QApplication>
#include "modeex.h"
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    ModeEx modeEx;
    QTableView view;
    view.setModel(&modeEx);
    view.setWindowTitle(QObject::tr("modelEx"));
    view.resize(800,800);
    view.show();
    return a.exec();
}
