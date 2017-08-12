#include "mainwindow.h"
#include <QGridLayout>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>
#include "editdialog.h"

extern int uniqueCarId;
extern int uniqueFactoryId;

MainWindow::MainWindow(const QString &factoryTable, const QString &carTable, QFile *carDetails, QWidget *parent)
    : QMainWindow(parent)
{
    file = carDetails;
    readCarData();    //将XML文件里的车型信息读入QDomDocument类实例carData中
    carModel = new QSqlRelationalTableModel(this);   //QSqlRelationalTableModel与QSqlTableMobel类似，但提供外键支持
    carModel->setTable(carTable);
    /*carModel的第二个字段（cars中的factory字段）是factory中id字段的外键，但其显示为manufactory字段*/
    carModel->setRelation(2,QSqlRelation(factoryTable,"id","manufactory"));
    carModel->select();        //填充carModel

    factoryModel = new QSqlTableModel(this);
    factoryModel->setTable(factoryTable);
    factoryModel->select();

    QGroupBox *factory = createFactoryGroupBox();
    QGroupBox *cars = createCarGroupBox();
    QGroupBox *details = createDetailsGroupBox();

    uniqueCarId = carModel->rowCount();
    uniqueFactoryId = factoryModel->rowCount();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factory,0,0);
    layout->addWidget(cars,1,0);
    layout->addWidget(details,0,1,2,1);
    layout->setColumnMinimumWidth(0,500);
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
    createMenuBar();
    resize(850,400);
    setWindowTitle(tr("主从视图"));

    bool ok = true;
    bool no = false;
    qDebug()<<QString::number(ok)<<endl<<QString::number(no)<<endl;
}

MainWindow::~MainWindow()
{

}

void MainWindow::addCarSlot()
{
    EditDialog *editDialog = new EditDialog(carModel,factoryModel,carData,file,this);
    int accepted = editDialog->exec();
    if(accepted == 1)
    {
        int lastRow = carModel->rowCount() - 1;
        carView->selectRow(lastRow);
        carView->scrollToBottom();
        showCarDetailsSlot(carModel->index(lastRow,0));
    }

}

void MainWindow::changeFactorySlot(QModelIndex index)
{
    QSqlRecord record = factoryModel->record(index.row());  //取出用户选择的这条汽车记录
    QString factoryId = record.value("id").toString();
    carModel->setFilter("id = '"+ factoryId +"'");    //carModel设置过滤器，使其只显示所选汽车制造商的车型
    showFactoryProfileSlot(index);

}

void MainWindow::delCarSlot()
{
    QModelIndexList selection = carView->selectionModel()->selectedRows(0);
    if(!selection.empty())
    {
        QModelIndex idIndex = selection.at(0);
        int id = idIndex.data().toInt();
        QString name = idIndex.sibling(idIndex.row(),1).data().toString();    //sibling 同级
        QString factory = idIndex.sibling(idIndex.row(),2).data().toString();
        QMessageBox::StandardButton button;
        button = QMessageBox::question(this,tr("删除汽车记录"),
                                       QString(tr("确认删除由'%1'生产的'%2'吗？").arg(factory)
                                               .arg(name)),QMessageBox::Yes | QMessageBox ::No);
        if(button == QMessageBox::Yes)
        {
            removeCarFromFile(id);                   //从XML文件中删除相关内容
            removeCarFromDatabase(idIndex);          //从数据库表中删除相关内容
            decreateCarCount(indexOfFactory(factory));
        }
        else
        {
            QMessageBox::information(this,tr("删除记录"),tr("请选择要删除的记录。"));
        }
     }
}

void MainWindow::showCarDetailsSlot(QModelIndex index)
{
    QSqlRecord record = carModel->record(index.row());
    QString factory = record.value("manufactory").toString();
    QString name = record.value("name").toString();
    QString year = record.value("year").toString();
    QString carId = record.value("carid").toString();
    showFactoryProfileSlot(indexOfFactory(factory));
    titleLabel->setText(tr("品牌：%1(%2)").arg(name).arg(year));
    titleLabel->show();
    QDomNodeList cars = carData.elementsByTagName("car");  //XML文件中搜索匹配的车型
    for(int i = 0; i < cars.count();i++)
    {
        QDomNode car = cars.item(i);
        if(car.toElement().attribute("id") == carId)
        {
            getAttributeList(car.toElement());        //显示匹配的car标签的相关信息
            break;
        }
    }
   if(!attributeList->count() == 0)
        attributeList->show();
}

//在"详细信息"中显示所选汽车制造商的信息
void MainWindow::showFactoryProfileSlot(QModelIndex index)
{
    QSqlRecord record = factoryModel->record(index.row());  //取出所选记录
    QString name = record.value("manufactory").toString();
    int count = carModel->rowCount();
    profileLabel->setText(tr("汽车制造商：%1\n产品数量：%2").arg(name).arg(count));
    profileLabel->show();
    titleLabel->hide();
    attributeList->hide();

}

QGroupBox *MainWindow::createCarGroupBox()
{
    carView = new QTableView;
    carView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    carView->setSortingEnabled(true);
    carView->setSelectionBehavior(QAbstractItemView::SelectRows);
    carView->setSelectionMode(QAbstractItemView::SingleSelection);
    carView->setShowGrid(false);
    carView->verticalHeader()->hide();                              //隐藏列表头(需添加QHeaderView)
    carView->setAlternatingRowColors(true);
    carView->setModel(carModel);
    connect(carView,SIGNAL(clicked(QModelIndex)),this,SLOT(showCarDetailsSlot(QModelIndex)));
    connect(carView,SIGNAL(activated(QModelIndex)),this,SLOT(showCarDetailsSlot(QModelIndex)));
    QGroupBox *box = new QGroupBox("汽车");
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(carView,0,0);
    box->setLayout(layout);
    return box;
}

QGroupBox *MainWindow::createFactoryGroupBox()
{
    factoryView = new QTableView;
    factoryView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止用户编辑
    factoryView->setSortingEnabled(true);                             //排序
    factoryView->setSelectionBehavior(QAbstractItemView::SelectRows);  //选择行为：按行选择
    factoryView->setSelectionMode(QAbstractItemView::SingleSelection);  //选择模式：单项选择
    factoryView->setShowGrid(false);                                    //不显示栅格
    factoryView->setAlternatingRowColors(true);                         //两行之间交替颜色（默认：false）
    factoryView->verticalHeader()->hide();
    factoryView->setModel(factoryModel);
    connect(factoryView,SIGNAL(clicked(QModelIndex)),this,SLOT(changeFactorySlot(QModelIndex)));
    QGroupBox *box = new QGroupBox("汽车制造商");
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factoryView,0,0);
    box->setLayout(layout);
    return box;
}

QGroupBox *MainWindow::createDetailsGroupBox()
{
    profileLabel = new QLabel;
    profileLabel->setWordWrap(true);           //标签文本在必要时被包裹在单词中断处
    profileLabel->setAlignment(Qt::AlignBottom);
    titleLabel = new QLabel;
    titleLabel->setWordWrap(true);
    titleLabel->setAlignment(Qt::AlignBottom);
    attributeList = new QListWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(profileLabel,0,0,1,2);
    layout->addWidget(titleLabel,1,0,1,2);
    layout->addWidget(attributeList,2,0,1,2);
    layout->setRowStretch(2,1);
    QGroupBox *box = new QGroupBox(tr("详细信息"));
    box->setLayout(layout);
    return box;
}

void MainWindow::createMenuBar()
{
    QAction *addAction = new QAction(tr("添加"),this);
    QAction *deleteAction = new QAction(tr("删除"),this);
    QAction *quitAction = new QAction(tr("退出"),this);
    addAction->setShortcut(tr("Ctrl+A"));
    deleteAction->setShortcut(tr("Ctrl+D"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    QMenu *fileMenu = menuBar()->addMenu(tr("操作菜单"));
    fileMenu->addAction(addAction);
    fileMenu->addAction(deleteAction);
    fileMenu->addAction(quitAction);
    connect(addAction,SIGNAL(triggered(bool)),this,SLOT(addCarSlot()));
    connect(deleteAction,SIGNAL(triggered(bool)),this,SLOT(delCarSlot()));
    connect(quitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
}

void MainWindow::decreateCarCount(QModelIndex index)
{
    int row = index.row();
    int count = carModel->rowCount();
    if(count == 0)
    {
        factoryModel->removeRow(row);      //删除对应的汽车制造商
    }
}

void MainWindow::getAttributeList(QDomNode car)
{
    attributeList->clear();
    QDomNodeList attributes = car.childNodes();
    QDomNode node;
    QString attributeNumber;
    for(int j = 0; j<attributes.count();j++)
    {
        node = attributes.item(j);
        attributeNumber = node.toElement().attribute("number");
        QListWidgetItem *item = new QListWidgetItem(attributeNumber);
        QString showText(attributeNumber + ":" + node.toElement().text());
        item->setText(tr("%1").arg(showText));
        attributeList->addItem(item);
    }
}

//通过制造商的名称进行检索，并返回一个匹配的模型索引QModexIndex
QModelIndex MainWindow::indexOfFactory(const QString &factory)
{
    for(int i = 0;i<factoryModel->rowCount();i++)
    {
        QSqlRecord record = factoryModel->record(i);
        if(record.value("manufactory") == factory)
        {
            return factoryModel->index(i,1);
        }
    }
    return QModelIndex();
}

void MainWindow::readCarData()
{
    if(!file->open(QIODevice::ReadOnly))
    {
        return;
    }
    if(!carData.setContent(file))               //carData:QDomDocument
    {
        file->close();
        return;
    }
    file->close();
}


void MainWindow::removeCarFromDatabase(QModelIndex index)
{
    carModel->removeRow(index.row());
}

void MainWindow::removeCarFromFile(int id)
{
    QDomNodeList cars = carData.elementsByTagName("car");
    for(int i = 0; i<cars.count();i++)
    {
        QDomNode node = cars.item(i);
        if(node.toElement().attribute("id").toInt() == id)
        {
            carData.elementsByTagName("archive").item(0).removeChild(node);   //删除子元素
            break;
        }
    }
}













