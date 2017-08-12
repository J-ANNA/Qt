#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H

#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QRegion>
#include <QMouseEvent>
#include <QList>

class HistogramView : public QAbstractItemView
{
    Q_OBJECT
public:
    HistogramView(QWidget *parent=0);

    //虚函数声明  根据实际需要选择性实现，但必须都声明
    QRect visualRect(const QModelIndex &index) const;
    void scrollTo(const QModelIndex &index, ScrollHint hint);
    //检查当前点在那个区域
    QModelIndex indexAt(const QPoint &point) const;
    //为selections赋初值
    void setSelectionModel(QItemSelectionModel *selectionModel);
    //返回指定index的数据项所占用的区域
    QRegion itemRegion(QModelIndex index);
    //绘制柱状图
    void paintEvent(QPaintEvent *);
    //在调用setSelection()函数时确定鼠标单击点是否在某个数据项的区域内，并设置选择项
    void mousePressEvent(QMouseEvent *);
protected slots:
//      完成当数据项发生变化时调用update()函数，重绘绘图设备即可工作。此函数是将其它View中的操作引起的是
//      数据项变化反映到自身View的显示中
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    //当Model中的数据更改时，调用绘图设备的update()函数进行更新，反映数据的变化
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);
protected:
    //虚函数声明
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
    int horizontalOffset() const;
    int verticalOffset() const;
    bool isIndexHidden(const QModelIndex &index) const;
    //完成选择项的设置工作
    void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags flags);
    QRegion visualRegionForSelection(const QItemSelection &selection) const;
private:
    QItemSelectionModel *selections;
    QList<QRegion> MRegionList;
    QList<QRegion> FRegionList;
    QList<QRegion> SRegionList;

};







#endif // HISTOGRAMVIEW_H
