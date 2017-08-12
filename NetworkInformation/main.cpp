#include "nerworkinformation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NerworkInformation w;
    w.show();

    return a.exec();
}
