#include "threaddlog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThreadDlog w;
    w.show();

    return a.exec();
}
