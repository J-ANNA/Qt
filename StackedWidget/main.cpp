#include "stackdlo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StackDlo w;
    w.show();

    return a.exec();
}
