#include "mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QStandardItemModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupMode();
    setupView();
    fileMenu = menuBar()->addMenu(tr("文件"));
    openFileAct = new QAction(tr("打开"),this);
    connect(openFileAct,SIGNAL(triggered()),this,SLOT(slotOpenFile()));
    fileMenu->addAction(openFileAct);
    setWindowTitle(tr("Delegate Example"));
    setCentralWidget(tableView);
    resize(800,400);

}

MainWindow::~MainWindow()
{

}

void MainWindow::setupMode()
{
     itemModel = new QStandardItemModel(4,4,this);
     itemModel->setHeaderData(0,Qt::Horizontal,tr("Name"));
     itemModel->setHeaderData(1,Qt::Horizontal,tr("Birthday"));
     itemModel->setHeaderData(2,Qt::Horizontal,tr("Job"));
     itemModel->setHeaderData(3,Qt::Horizontal,tr("Income"));
}

void MainWindow::setupView()
{
    tableView = new QTableView;
    tableView->setModel(itemModel);
    QItemSelectionModel *selectionModel = new QItemSelectionModel(itemModel);
    tableView->setSelectionModel(selectionModel);
    dateDelegate = new DateDelegate;
    tableView->setItemDelegateForColumn(1,dateDelegate);
    comboBoxDelegate = new ComboBoxDelegate;
    tableView->setItemDelegateForColumn(2,comboBoxDelegate);
    spinBoxDelegate = new SpinBoxDelegate;
    tableView->setItemDelegateForColumn(3,spinBoxDelegate);
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            tableView,SLOT(selectionChanged(QItemSelection,QItemSelection)));
}

void MainWindow::slotOpenFile()
{
    QString fileName;
//    fileName = QFileDialog::getOpenFileName(this,tr("打开"),"/","files(*.txt)");
    fileName = QFileDialog::getOpenFileName(this,"打开","/","histogram files(*.txt)");
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if(file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream stream(&file);
            QString line;
            itemModel->removeRows(0,itemModel->rowCount(QModelIndex()),QModelIndex());
            int row = 0;
            do
            {
                line = stream.readLine();
                if(!line.isEmpty())
                {
                    itemModel->insertRows(row,1,QModelIndex());
                    QStringList pieces = line.split(",",QString::SkipEmptyParts);
                    itemModel->setData(itemModel->index(row,0,QModelIndex()),pieces.value(0));
                    itemModel->setData(itemModel->index(row,1,QModelIndex()),pieces.value(1));
                    itemModel->setData(itemModel->index(row,2,QModelIndex()),pieces.value(2));
                    itemModel->setData(itemModel->index(row,3,QModelIndex()),pieces.value(3));
                    qDebug()<<line;
                    row++;
                }
            } while(!line.isEmpty());
            file.close();
        }
     }
}













