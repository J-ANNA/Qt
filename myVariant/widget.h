#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QWidget>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
     ~Widget();
    void init();
    void updateParentItem(QTreeWidgetItem *item);
public slots:
    void treeItemChanged(QTreeWidgetItem *intem,int colmn);

private:
    QTreeWidget *treeWidget;


};

#endif // WIDGET_H
