#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QTableView>
#include <QListWidget>
#include <QLabel>
#include <QFile>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QModelIndex>
#include <QDomNode>
#include <QDomDocument>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &factoryTable,const QString &carTable,QFile *carDetails, QWidget *parent = 0);
    ~MainWindow();
private slots:
    void addCarSlot();
    void changeFactorySlot(QModelIndex index);
    void delCarSlot();
    void showCarDetailsSlot(QModelIndex index);
    void showFactoryProfileSlot(QModelIndex index);
private:
    QGroupBox *createCarGroupBox();
    QGroupBox *createFactoryGroupBox();
    QGroupBox *createDetailsGroupBox();
    void createMenuBar();
    QTableView *carView;
    QTableView *factoryView;
    QListWidget *attributeList;
    QLabel *profileLabel;
    QLabel *titleLabel;

    void decreateCarCount(QModelIndex index);
    void getAttributeList(QDomNode car);
    QModelIndex indexOfFactory(const QString &factory);
    void readCarData();
    void removeCarFromDatabase(QModelIndex index);
    void removeCarFromFile(int id);
    QDomDocument carData;
    QFile *file;
    QSqlRelationalTableModel *carModel;
    QSqlTableModel *factoryModel;



};

#endif // MAINWINDOW_H
