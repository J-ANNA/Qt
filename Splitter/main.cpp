#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    QFont font("Arial",12);
    a.setFont(font);
    //主分割窗口
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,0);
    QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"),splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);
    //右部分分割窗口
    QSplitter *splitterRight = new QSplitter(Qt::Vertical,splitterMain);
    splitterRight->setOpaqueResize(false);
    QTextEdit *textup = new QTextEdit(QObject::tr("Top Widget"),splitterRight);
    textup->setAlignment(Qt::AlignCenter);
    QTextEdit *textbottom = new QTextEdit(QObject::tr("Bottom Widget"),splitterRight);
    textbottom->setAlignment(Qt::AlignCenter);
    splitterMain->setStretchFactor(1,1);
    splitterMain->setStretchFactor(0,1);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    splitterMain->show();

    return a.exec();
}
