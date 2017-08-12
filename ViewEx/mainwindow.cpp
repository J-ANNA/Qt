#include "mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createAction();
    createMenu();
    setupMode();
    setupView();
    setWindowTitle(tr("View Example"));

    splitter = new QSplitter;
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(tableView);
    splitter->addWidget(histogramView);
    setCentralWidget(splitter);

    resize(600,600);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createAction()
{
    openAct = new QAction(tr("打开"),this);
    connect(openAct,SIGNAL(triggered()),this,SLOT(slotOpenFile()));

}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openAct);
}

void MainWindow::setupMode()
{
    model = new QStandardItemModel(4,4,this);
    model->setHeaderData(0,Qt::Horizontal,tr("部门"));
    model->setHeaderData(1,Qt::Horizontal,tr("男"));
    model->setHeaderData(2,Qt::Horizontal,tr("女"));
    model->setHeaderData(3,Qt::Horizontal,tr("退休"));
}

void MainWindow::setupView()
{
    tableView = new QTableView;
    tableView->setModel(model);
    QItemSelectionModel *selectionModel = new QItemSelectionModel(model);
    tableView->setSelectionModel(selectionModel);
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            tableView,SLOT(selectionChanged(QItemSelection,QItemSelection)));

    histogramView = new HistogramView;
    histogramView->setModel(model);
    histogramView->setSelectionModel(selectionModel);
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            histogramView,SLOT(selectionChanged(QItemSelection,QItemSelection)));

}

void MainWindow::openFile(QString path)
{
    if(!path.isEmpty())
    {
        QFile file(path);
        if(file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream stream(&file);
            QString line;
            model->removeRows(0,model->rowCount(QModelIndex()),QModelIndex());
            int row = 0;
            do
            {
                line = stream.readLine();
                if(!line.isEmpty())
                {
                    model->insertRows(row,1,QModelIndex());
                    QStringList pieces = line.split(",",QString::SkipEmptyParts);
                    model->setData(model->index(row,0,QModelIndex()),pieces.value(0));
                    model->setData(model->index(row,1,QModelIndex()),pieces.value(1));
                    model->setData(model->index(row,2,QModelIndex()),pieces.value(2));
                    model->setData(model->index(row,3,QModelIndex()),pieces.value(3));
                    row++;
                }
            }
            while (!line.isEmpty());
            file.close();
        }
    }
}

void MainWindow::slotOpenFile()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,"打开","/","histogram files(*.txt)");
    if(!fileName.isEmpty())
    {
        openFile(fileName);
    }
}

















