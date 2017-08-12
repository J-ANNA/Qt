#include <QString>
#include <QtTest>

class TestQString : public QObject
{
    Q_OBJECT

public:
    TestQString();

private Q_SLOTS:
    void testToLower();
    void testToLower_data();
};

TestQString::TestQString()
{
}

/*每个private slot 都是一个被QTest::qExec()自动调用的测试函数*/
void TestQString::testToLower()
{
    //获得测试数据
    QFETCH(QString,string);
    QFETCH(QString, result);
    //如果两个参数不同，则其值会被分别显示出来
    QCOMPARE(string.toLower(),result);
    QVERIFY2(true, "Failure");
}

/*用于提供测试数据。初始化数据的函数名和测试函数名一样，但增加了后缀"_data()"*/
void TestQString::testToLower_data()
{
    //添加测试的数据列
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");
    //添加测试的数据数据行
    QTest::newRow("lower")<<"hello"<<"hello";
    QTest::newRow("mixed")<<"heLLO"<<"hello";
    QTest::newRow("upper")<<"HELLO"<<"hello";
}

//生成能够独立运行的测试代码
QTEST_APPLESS_MAIN(TestQString)

#include "tst_testqstring.moc"
