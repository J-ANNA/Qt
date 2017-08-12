#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "flashitem.h"
#include "staritem.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initScene();
    void createActions();
    void createMenus();
public slots:
    void slotNew();
    void slotClear();
    void slotAddEllipseItem();
    void slotAddPolygonItem();
    void slotAddTextItem();
    void slotAddRectItem();
    void slotAddAlphaItem();
    void slotAddFlashItem();
    void slotAddStarItem();
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QAction *newAct;
    QAction *clearAct;
    QAction *exitAct;
    QAction *addEllipseItemAct;
    QAction *addPolygonItemAct;
    QAction *addRectItemAct;
    QAction *addTextItemAct;
    QAction *addAlphaItemAct;
    QMenu *fileMenu;
    QMenu *itemsMenu;
    QAction *addFlashItemAct;
    QAction *addStarItemAct;
};

#endif // MAINWINDOW_H
