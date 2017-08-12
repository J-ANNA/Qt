#include "connectdlg.h"
#include "ui_connectdlg.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

ConnectDlg::ConnectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);
    QStringList drivers = QSqlDatabase::drivers();
    ui->driverComboBox->addItems(drivers);
    connect(ui->driverComboBox,SIGNAL(currentIndexChanged(const QString &)),
            this,SLOT(driverChanged(const QString &)));
    ui->stateLabel->setText(tr("准备连接数据库"));
    connect(ui->connectBtn,SIGNAL(clicked()),this,SLOT(connectBtnClickedSlot()));

}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}

QString ConnectDlg::driverName() const
{
    return ui->driverComboBox->currentText();
}

QString ConnectDlg::databaseName() const
{
    return ui->dataBaseLineEdit->text();
}

QString ConnectDlg::userName() const
{
    return ui->userNameLineEdit->text();
}

QString ConnectDlg::password() const
{
    return ui->passwordLineEdit->text();
}

QString ConnectDlg::hostName() const
{
    return ui->hostNameLineEdit->text();
}

int ConnectDlg::port() const
{
    return ui->portSpinBox->value();
}

//建立一条数据库连接
QSqlError ConnectDlg::addConnection(const QString &driver, const QString &dbName,
                                    const QString &host, const QString &user, const QString &password, int port)
{
    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    if(db.open(user,password))
    {
        err = db.lastError();
    }
    return err;
}

//创建相关的两张数据库表，并在其中插入适当信息
void ConnectDlg::createDB()
{
    QSqlQuery query;
    /*varchar：长度可变化字符类型，varchar(40),字符数组最大长度为40，当字符串长度小于40时，按实际长度存储*/
    query.exec("create table factory("
               "id int primary key,"
               "manufactory varchar(40),"
               "address varchar(40))");
    query.exec(QObject::tr("insert into factory values(1,'一汽大众','长春')"));
    query.exec(QObject::tr("insert into factory values(2,'二汽神龙','武汉')"));
    query.exec(QObject::tr("insert into factory values(3,'上海大众','上海')"));
    query.exec("create table cars("
               "carid int primary key,"
               "name varchar(50),"
               "factoryid int,"
               "year int,"
               "foreign key(factoryid) references factory)");    //factoryid 是一个外键，参照factory id
    query.exec(QObject::tr("insert into cars values(1,'奥迪A6',1,2005)"));
    query.exec(QObject::tr("insert into cars values(2,'捷达',1,1993)"));
    query.exec(QObject::tr("insert into cars values(3,'宝莱',1,2000)"));
    query.exec(QObject::tr("insert into cars values(4,'毕加索',2,1999)"));
    query.exec(QObject::tr("insert into cars values(5,'富康',2,2004)"));
    query.exec(QObject::tr("insert into cars values(6,'标志307',2,2001)"));
    query.exec(QObject::tr("insert into cars values(7,'桑塔纳',3,1995)"));
    query.exec(QObject::tr("insert into cars values(8,'帕萨特',3,2000)"));

}

void ConnectDlg::addSqliteConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("databasefile");
    if(!db.open())
    {
        ui->stateLabel->setText(db.lastError().text());
        return;
    }
    ui->stateLabel->setText(tr("创建数据库成功！"));

}

void ConnectDlg::connectBtnClickedSlot()
{
    if(ui->driverComboBox->currentText().isEmpty())
    {
        ui->stateLabel->setText(tr("请选择一个数据库驱动！"));
        ui->driverComboBox->setFocus();
    }
    else if(ui->driverComboBox->currentText() == "QSQLITE")
    {
        addSqliteConnection();
        createDB();
        accept();
    }
    else
    {
        QSqlError err = addConnection(driverName(),databaseName(),hostName(),userName(),password(),port());
        if(err.type()!= QSqlError::NoError)
            ui->stateLabel->setText(tr("err.text()"));
        else
            ui->stateLabel->setText(tr("连接数据成功！"));
        //创建数据库表，如已存在则无须执行
        accept();
    }
}

void ConnectDlg::driverChanged(const QString &text)
{
    /*sqlite数据库是一种进程内的本地数据库，无须数据库名、用户名、密码、主机名和端口等特性*/
    if(text == "QSQLITE")
    {
        ui->dataBaseLineEdit->setEnabled(false);
        ui->userNameLineEdit->setEnabled(false);
        ui->passwordLineEdit->setEnabled(false);
        ui->hostNameLineEdit->setEnabled(false);
        ui->portSpinBox->setEnabled(false);
    }
    else
    {
        ui->dataBaseLineEdit->setEnabled(true);
        ui->userNameLineEdit->setEnabled(true);
        ui->passwordLineEdit->setEnabled(true);
        ui->hostNameLineEdit->setEnabled(true);
        ui->portSpinBox->setEnabled(true);
    }
}
