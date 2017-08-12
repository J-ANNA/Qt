#include "mainwindow.h"
#include "butterfly.h"
#include <QGraphicsScene>
#include <QGraphicsView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-200,-200,400,400));
    Butterfly *butterFly = new Butterfly;
    butterFly->setPos(-100,0);
    scene->addItem(butterFly);
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->resize(400,400);
    setCentralWidget(view);

}

MainWindow::~MainWindow()
{

}
