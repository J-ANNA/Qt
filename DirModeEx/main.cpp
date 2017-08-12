#include "mainwindow.h"
#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    //模型
    QDirModel dirMode;                  //电脑文件目录
    //三种不同的视图方式显示
    QTreeView treeView;
    QListView listView;
    QTableView tableView;
    treeView.setModel(&dirMode);
    listView.setModel(&dirMode);
    tableView.setModel(&dirMode);

    treeView.setSelectionMode(QAbstractItemView::MultiSelection);
    listView.setSelectionModel(treeView.selectionModel());
    tableView.setSelectionModel(treeView.selectionModel());
    QObject::connect(&treeView,SIGNAL(doubleClicked(QModelIndex)),&listView,SLOT(setRootIndex(QModelIndex)));
    QObject::connect(&treeView,SIGNAL(doubleClicked(QModelIndex)),&tableView,SLOT(setRootIndex(QModelIndex)));
    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&treeView);
    splitter->addWidget(&listView);
    splitter->addWidget(&tableView);
    splitter->setWindowTitle(QObject::tr("Model/View"));
    splitter->show();


    return a.exec();
}
