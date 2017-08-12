#include <QString>
#include <QtTest>
#include "area.h"


class AreaTest : public QObject
{
    Q_OBJECT

public:
    AreaTest();

private Q_SLOTS:
    void toArea();          //测试函数名 toArea()
    void toArea_data();     //初始化数据
};

AreaTest::AreaTest()
{
}

void AreaTest::toArea()
{
    //获取数据
    QFETCH(Area,area);
    QFETCH(double,r);                               //r:相应的Area对象中计算圆面积半径的期望值（面积）
    QVERIFY(qAbs(area.CountArea() - r)<0.0000001);
    QVERIFY2(true, "Failure");
}

void AreaTest::toArea_data()
{
    //定义测试数据列
    QTest::addColumn<Area>("area");
    QTest::addColumn<double>("r");
    //建立测试数据
    QTest::newRow("1")<<Area(1)<<3.14;
    QTest::newRow("2")<<Area(2)<<12.56;
    QTest::newRow("3")<<Area(3)<<28.26;
}

QTEST_APPLESS_MAIN(AreaTest)

#include "tst_areatest.moc"
