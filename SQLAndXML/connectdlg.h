#ifndef CONNECTDLG_H
#define CONNECTDLG_H

#include <QDialog>
#include <QMessageBox>
#include "ui_connectdlg.h"

class QSqlError;

namespace Ui {
class ConnectDlg;
}

class ConnectDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDlg(QWidget *parent = 0);
    ~ConnectDlg();
    QString driverName() const;
    QString databaseName() const;
    QString userName() const;
    QString password() const;
    QString hostName() const;
    int port() const;
    QSqlError addConnection(const QString &driver, const QString &dbName, const QString &host,
                            const QString &user,const QString &password,int port = -1);
    void createDB();
    void addSqliteConnection();
private slots:
    void connectBtnClickedSlot();
    void quitBtnClickSlot(){reject();}
    void driverChanged(const QString &);


private:
    Ui::ConnectDlg *ui;
};

#endif // CONNECTDLG_H
