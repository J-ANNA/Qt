#include "imgprocessor.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("宋体",12);
    a.setFont(f);
    ImgProcessor w;
    w.show();

    return a.exec();
}
