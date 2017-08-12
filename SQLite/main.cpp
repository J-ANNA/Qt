#include <QCoreApplication>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());   //设置中文显示
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");        //以"QSQLITE"为数据类型，在本进程地址空间内创建一个SQL数据库
    db.setHostName("easybook-3313b0");                             //设置数据库主机名
    db.setDatabaseName("qtDB.db");                                 //设置数据库名，它是SOLite在建立内存数据库时唯一可用的名字
    db.setUserName("zhouhejun");                                   //设置数据库用户名
    db.setPassword("123456");                                      //设置数据库密码
    db.open();                                                     //打开连接
    //创建数据库表
    QSqlQuery query;                                               //创建QSqlQuery对象
    bool success = query.exec("create table automobile"
                              "(id int primary key,"               //关键词（primary key）
                              "attribute varchar,"
                              "type varchar,"
                              "kind varchar,"
                              "nation int,"
                              "carnumber int,"
                              "elevaltor int,"
                              "distance int,"
                              "oil int,"
                              "temperature int)");
    if(success)
         qDebug()<<QObject::tr("数据库表创建成功！\n");
    else
        qDebug()<<QObject::tr("数据库表创建失败！\n");

    //查询
    query.exec("select * from automobile");
    QSqlRecord rec = query.record();
    qDebug()<<QObject::tr("automobile表字段数：")<<rec.count();

    //插入记录
    QTime t;
    t.start();
    /*如果要插入多条记录，或者避免将值转换为字符串（即正确地转义），
     则可以首先调用prepare()函数指定一个包含占位符的query,然后绑定要插入的值*/
    query.prepare("insert into automobile values(?,?,?,?,?,?,?,?,?,?)");
    long records = 100;  //向表中插入任意的100条记录
    for(int i = 0; i < records; i++)
    {
        query.bindValue(0,i);
        query.bindValue(1,"四轮");
        query.bindValue(2,"轿车");
        query.bindValue(3,"富康");
        query.bindValue(4,rand()%100);
        query.bindValue(5,rand()%10000);
        query.bindValue(6,rand()%300);
        query.bindValue(7,rand()%200000);
        query.bindValue(8,rand()%52);
        query.bindValue(9,rand()%100);
        success = query.exec();
        if(!success)
        {
            QSqlError lastError = query.lastError();
            qDebug()<<lastError.driverText()<<QString(QObject::tr("插入失败"));
        }
    }
    qDebug()<<QObject::tr("插入%1条记录，耗时：%2 ms").arg(records).arg(t.elapsed());
    //排序
    t.restart();
    success = query.exec("select * from automobile order by id desc");  //降序排列（desc）
    if(success)
        qDebug()<<QObject::tr("排序%1条记录，耗时：%2 ms").arg(records).arg(t.elapsed());
    else
        qDebug()<<QObject::tr("排序失败！");
    //更新记录
    t.restart();
    for(int i = 0; i<records;i++)
    {
        query.clear();
        query.prepare(QString("update automobile set attribute=?,type=?,"
                              "kind=?,nation=?,"
                              "carnumber=?,elevaltor=?,"
                              "distance=?,oil=?,"
                              "temperature=?where id=%1").arg(i));
        query.bindValue(0,"四轮");
        query.bindValue(1,"轿车");
        query.bindValue(3,"富康");
        query.bindValue(4,rand()%100);
        query.bindValue(5,rand()%10000);
        query.bindValue(6,rand()%300);
        query.bindValue(7,rand()%200000);
        query.bindValue(8,rand()%52);
        success = query.exec();
        if(!success)
        {
            QSqlError lastError = query.lastError();
            qDebug()<<lastError.driverText()<<QString(QObject::tr("更新失败"));
        }
    }

    qDebug()<<QObject::tr("更新%1条记录，耗时：%2 ms").arg(records).arg(t.elapsed());
    //删除
    t.restart();
    query.exec("delete from automobile where id = 5");
    qDebug()<<QObject::tr("删除一条记录，耗时%1 ms").arg(t.elapsed());
    query.exec("select oil from automobile where id = 1");
    return a.exec();
}
