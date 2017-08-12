#include "mainwindow.h"
#include "connectdlg.h"

#include <QApplication>
#include <QDialog>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConnectDlg connectDlg;
    if(connectDlg.exec() != QDialog::Accepted)
        return -1;
    QFile *carDetails = new QFile("D:/QtStudy/SQLAndXML/attribs.xml");
    MainWindow window("factory","cars",carDetails);
    window.show();
    return a.exec();
}
