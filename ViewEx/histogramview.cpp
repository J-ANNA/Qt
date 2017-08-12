#include "histogramview.h"
#include <QPainter>


HistogramView::HistogramView(QWidget *parent) :QAbstractItemView(parent)
{

}

QRect HistogramView::visualRect(const QModelIndex &index) const
{

}

void HistogramView::scrollTo(const QModelIndex &index, QAbstractItemView::ScrollHint hint)
{

}

QModelIndex HistogramView::indexAt(const QPoint &point) const
{
    QPoint newPoint(point.x(),point.y());
    QRegion region;
    //男列
    foreach (region, MRegionList)
    {
        if(region.contains(newPoint))
        {
            int row = MRegionList.indexOf(region);
            QModelIndex index = model()->index(row,1,rootIndex());
            return index;
        }
    }
    //女列
    foreach (region, FRegionList)
    {
        if(region.contains(newPoint))
        {
            int row = FRegionList.indexOf(region);
            QModelIndex index = model()->index(row,2,rootIndex());
            return index;
        }
    }
    //退休列
    foreach (region, SRegionList)
    {
        if(region.contains(newPoint))
        {
            int row = SRegionList.indexOf(region);
            QModelIndex index = model()->index(row,3,rootIndex());
            return index;
        }
    }
    return QModelIndex();
}

void HistogramView::setSelectionModel(QItemSelectionModel *selectionModel)
{
    selections = selectionModel;
}

QRegion HistogramView::itemRegion(QModelIndex index)
{
    QRegion region;
    if(index.column() == 1)
    {
        region = MRegionList[index.row()];
    }
    else if(index.column() == 2)
    {
        region = FRegionList[index.row()];
    }
    else if(index.column() == 3)
    {
        region = SRegionList[index.row()];
    }
    return region;
}

//paintEvent()函数具体完成柱状统计图绘制的工作
void HistogramView::paintEvent(QPaintEvent *event)
{
    QPainter painter(viewport());
    painter.setPen(Qt::black);
    int x0=40;
    int y0=250;
    //Y坐标
    painter.drawLine(x0,y0,40,30);
    painter.drawLine(38,32,40,30);
    painter.drawLine(40,30,42,32);
    painter.drawText(20,30,tr("人数"));
//    for(int i=1;i<5;i++)
//    {
//        painter.drawLine(-1,-i*50,1,-i*50);
//        painter.drawText(-20,-i*50,tr("%1").arg(i*5));
//    }
    for(int i=1;i<5;i++)
    {
        painter.drawLine(x0,y0-i*50,x0+2,y0-i*50);
        painter.drawText(x0-20,y0-i*50,tr("%1").arg(i*5));
    }
    //X坐标
    painter.drawLine(x0,y0,540,250);
    painter.drawLine(538,248,540,250);
    painter.drawLine(540,250,538,252);
    painter.drawText(540,250,tr("部门"));
    int posD=x0+20;
    int row;
    for(row=0;row<model()->rowCount(rootIndex());row++)
    {
        QModelIndex index =model()->index(row,0,rootIndex());
        QString dep = model()->data(index).toString();
        painter.drawText(posD,y0+20,dep);
        posD += 50;
    }
    //男
    int posM = x0 +20;
    for(row=0;row<model()->rowCount(rootIndex());row++)
    {
        QModelIndex index = model()->index(row,1,rootIndex());
        int male = model()->data(index).toDouble();
        int width =10;
        if(selections->isSelected(index))
        {
            painter.setBrush(QBrush(Qt::blue,Qt::Dense3Pattern));
        }
        else
        {
            painter.setBrush(Qt::blue);
        }
        painter.drawRect(QRect(posM,y0-male*10,width,male*10));
        QRegion regionM(posM,y0-male*10,width,male*10);
        MRegionList<<regionM;
        posM +=50;
    }

    //女
    int posF = x0 +30;
    for(row=0;row<model()->rowCount(rootIndex());row++)
    {
        QModelIndex index = model()->index(row,2,rootIndex());
        int female = model()->data(index).toDouble();
        int width =10;
        if(selections->isSelected(index))
        {
            painter.setBrush(QBrush(Qt::red,Qt::Dense3Pattern));
        }
        else
        {
            painter.setBrush(Qt::red);
        }
        painter.drawRect(QRect(posF,y0-female*10,width,female*10));
        QRegion regionF(posF,y0-female*10,width,female*10);
        FRegionList<<regionF;
        posF +=50;
    }

    //退休
    int posS = x0 +40;
    for(row=0;row<model()->rowCount(rootIndex());row++)
    {
        QModelIndex index = model()->index(row,3,rootIndex());
        int retire = model()->data(index).toDouble();
        int width =10;
        if(selections->isSelected(index))
        {
            painter.setBrush(QBrush(Qt::green,Qt::Dense3Pattern));
        }
        else
        {
            painter.setBrush(Qt::green);
        }
        painter.drawRect(QRect(posS,y0-retire*10,width,retire*10));
        QRegion regionS(posS,y0-retire*10,width,retire*10);
        SRegionList<<regionS;
        posS +=50;
    }

}

void HistogramView::mousePressEvent(QMouseEvent *event)
{
    QAbstractItemView::mousePressEvent(event);
    setSelection(QRect(event->pos().x(),event->pos().y(),1,1), QItemSelectionModel::SelectCurrent);
}

void HistogramView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    viewport()->update();
}

void HistogramView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    QAbstractItemView::dataChanged(topLeft,bottomRight);
    viewport()->update();
}

QModelIndex HistogramView::moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{

}

int HistogramView::horizontalOffset() const
{

}

int HistogramView::verticalOffset() const
{

}

bool HistogramView::isIndexHidden(const QModelIndex &index) const
{

}

void HistogramView::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags flags)
{
    int rows = model()->rowCount(rootIndex());
    int columns = model()->columnCount(rootIndex());
    QModelIndex selectedIndex;
    for(int row=0;row<rows;++row)
    {
        for(int column=1;column<columns;++column)
        {
            QModelIndex index = model()->index(row,column,rootIndex());
            QRegion region =itemRegion(index);
            if(!region.intersected(rect).isEmpty())
            {
                selectedIndex = index;
            }
        }
    }
    if(selectedIndex.isValid())
    {
        selections->select(selectedIndex,flags);        //必须调用
    }
    else
    {
        QModelIndex noIndex;
        selections->select(noIndex,flags);
    }
}

QRegion HistogramView::visualRegionForSelection(const QItemSelection &selection) const
{

}



























