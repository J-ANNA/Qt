#ifndef MODEEX_H
#define MODEEX_H

#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include <QString>
#include <QModelIndex>
#include <QVariant>

class ModeEx : public QAbstractTableModel
{
    Q_OBJECT
public:
    ModeEx(QObject *parent=0);

    //虚函数声明
    virtual int rowCount(const QModelIndex &parent=QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
signals:

public slots:

private:
    QVector<short> army;
    QVector<short> weaponType;
    QMap<short,QString> armyMap;
    QMap<short,QString> weaponTypeMap;
    QStringList weaponList;
    QStringList headerList;

    void populateModel();


};

#endif // MODEEX_H
