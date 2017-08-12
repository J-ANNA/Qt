#include "datedelegate.h"
#include <QDateTimeEdit>
#include <QDate>

DateDelegate::DateDelegate(QObject *parent) :QItemDelegate(parent)
{

}

QWidget *DateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDateTimeEdit *timeEditor = new QDateTimeEdit(parent);  //编辑时的输入控件
    timeEditor->setDisplayFormat("yy-MM-dd");    //显示格式
    timeEditor->setCalendarPopup(true);           //日历选择的显示方式：下拉
    timeEditor->installEventFilter(const_cast<DateDelegate*>(this));  //安装事件过滤器，使DateDelegate能够捕获QDateTimeEdit对象的事件
    //const_cast 去掉类型的const 或 volatile 属性
    return timeEditor;
}

void DateDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString dateStr = index.model()->data(index).toString();
    QDate date = QDate::fromString(dateStr,Qt::ISODate);       //将QString类型转化为QDate,QDate类型的日期是以ISO格式保存的
    QDateTimeEdit *timeEditor = static_cast<QDateTimeEdit*>(editor); //将editor转换为QDateTimeEdit对象， 以获得编辑控件的对象指针

}

void DateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateTimeEdit *edit= static_cast<QDateTimeEdit*>(editor);  //获取对象指针
    QDate date = edit->date();                                  //获得编辑控件中的数据更新
    model->setData(index,QVariant(date.toString(Qt::ISODate)));  //调用setData()函数将数据修改更新到Model中
}

void DateDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
