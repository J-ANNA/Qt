#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include <QTextStream>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "datedelegate.h"
#include "comboboxdelegate.h"
#include "spinboxdelegate.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void slotOpenFile();
private:
    QStandardItemModel *itemModel;
    QTableView *tableView;
    DateDelegate *dateDelegate;
    ComboBoxDelegate *comboBoxDelegate;
    SpinBoxDelegate *spinBoxDelegate;
    QMenu *fileMenu;
    QAction *openFileAct;


    void setupMode();
    void setupView();




};

#endif // MAINWINDOW_H
