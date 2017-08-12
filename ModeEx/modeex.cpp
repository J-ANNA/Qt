#include "modeex.h"

ModeEx::ModeEx(QObject *parent) :QAbstractTableModel(parent)
{
    armyMap[1] = tr("空军");
    armyMap[2] = tr("海军");
    armyMap[3] = tr("陆军");
    armyMap[4] = tr("海军陆战队");
    weaponTypeMap[1] = tr("轰炸机");
    weaponTypeMap[2] = tr("航空母舰");
    weaponTypeMap[3] = tr("直升机");
    weaponTypeMap[4] = tr("两栖攻击舰");
    weaponTypeMap[5] = tr("驱逐舰");
    weaponTypeMap[6] = tr("两栖战车");
    weaponTypeMap[7] = tr("坦克");
    weaponTypeMap[8] = tr("战斗机");
    populateModel();


}
void ModeEx::populateModel()
{
    headerList<<tr("军种")<<tr("种类")<<tr("武器");
    army<<1<<2<<3<<4<<2<<4<<3<<1;
    weaponType<<1<<2<<3<<4<<5<<6<<7<<8;
    weaponList<<tr("B-2")<<tr("尼米兹级")<<tr("阿帕奇")<<tr("黄蜂级")<<tr("阿利伯克级")<<tr("AAAV")<<tr("M1A1")<<tr("F-22");

}

int ModeEx::rowCount(const QModelIndex &parent) const
{
    return army.size();
}

int ModeEx::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant ModeEx::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(role == Qt::DisplayRole)
    {
        switch (index.column()) {
        case 0:
            return armyMap[army[index.row()]];
            break;
        case 1:
            return weaponTypeMap[weaponType[index.row()]];
            break;
        case 2:
            return weaponList[index.row()];
            break;
        default:
            return QVariant();
            break;
        }
    }
    return QVariant();

}

QVariant ModeEx::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        return headerList[section];
    }
    return QAbstractTableModel::headerData(section,orientation,role);
}


