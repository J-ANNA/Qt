#include "widget.h"
#include "QDebug"
#include "QApplication"
#include "QPushButton"
#include "QTime"
#include "QWidget"
#include "QHBoxLayout"
#include "QLabel"
#include "QTreeWidgetItem"
#include "QTreeWidget"
#include "QString"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{


   setMinimumSize(200,120);
   setMaximumSize(800,240);

   treeWidget = new QTreeWidget(this);
   treeWidget->setHeaderLabel("treeList");

   init();
   connect(treeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(treeItemChanged(QTreeWidgetItem*,int)));

   QString str1;
   QString str2;
   str1 = "date";
   str2 = str1;
   qDebug()<<"str1="<<str1<<"str2="<<str2;
   str1[2] = 'd';
   str2[2] = 'e';
   qDebug()<<"str1="<<str1<<"str2="<<str2;


}

Widget::~Widget()
{

}

void Widget::init()
{
    treeWidget->clear();
    QTreeWidgetItem *group1 = new QTreeWidgetItem(treeWidget);
    group1->setText(0,"Group1");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem11 = new QTreeWidgetItem(group1);
    subItem11->setText(0,"subItem11");
    subItem11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem11->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem12 = new QTreeWidgetItem(group1);
    subItem12->setText(0,"subItem12");
    subItem12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem12->setCheckState(0,Qt::Unchecked);

}

void Widget::treeItemChanged(QTreeWidgetItem *item,int column)
{
    QString itemText = item->text(0);
    //选中时
    if(Qt::Checked == item->checkState(0))
    {
        QTreeWidgetItem *parent = item->parent();
        int count = item->childCount();
        if(count > 0)
        {
            for(int i = 0;i<count;i++)
            {
                //子节点也选中
                item->child(i)->setCheckState(0,Qt::Checked);
            }
        }
        else
        {
            //是子节点
            updateParentItem(item);
        }
    }
    else if(Qt::Unchecked == item->checkState(0))
    {
        int count = item->childCount();
        if(count > 0)
        {
            for(int i = 0;i<count;i++)
            {
                //子节点也选中
                item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }
        else
        {
            //是子节点
            updateParentItem(item);
        }
    }
}

void Widget::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent = item->parent();
    if(parent == NULL)
    {
        return;
    }
    //选中子节点个数
    int selectedCount = 0;
    int childCount = parent->childCount();
    for(int i = 0;i<childCount;i++)
    {
        QTreeWidgetItem *childItem = parent->child(i);
        if(childItem->checkState(0)==Qt::Checked)
        {
            selectedCount++;
        }
    }
    if(selectedCount<=0)
    {
        //未选中状态
        parent->setCheckState(0,Qt::Unchecked);
    }
    else if(selectedCount > 0 && selectedCount <childCount)
    {
        //部分选中状态
        parent->setCheckState(0,Qt::PartiallyChecked);
    }
    else if(selectedCount == childCount)
    {
        //全选中状态
        parent->setCheckState(0,Qt::Checked);
        qDebug()<<"allcheck";
    }

}







