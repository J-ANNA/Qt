#include "mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("SVG Viewer"));
    createMenu();
    svgWindow = new SVGWindow;
    setCentralWidget(svgWindow);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("文件"));
    QAction *openFileAct = new QAction(tr("打开"),this);
    connect(openFileAct,SIGNAL(triggered()),this,SLOT(openFile()));
    fileMenu->addAction(openFileAct);
}

void MainWindow::openFile()
{
//    QString name = QFileDialog::getOpenFileName(this,"打开","/","svg files(*.svg)");
//    svgWindow->setFile(name);
    svgWindow->setFile("D:/QtStudy/SVGTest/svg/business140.svg");
}
