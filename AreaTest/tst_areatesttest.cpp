#include <QString>
#include <QtTest>
#include "area.h"

class AreaTestTest : public QObject
{
    Q_OBJECT

public:
    AreaTestTest();

private Q_SLOTS:
    void toAreaText();
};

AreaTestTest::AreaTestTest()
{
}

void AreaTestTest::toAreaText()
{
    Area area(1);
    QVERIFY(qAbs(area.CountArea() - 3.14)<0.0000001);
    QVERIFY2(true, "Failure");   //true验证失败，输出信息"Failure"
}

QTEST_APPLESS_MAIN(AreaTestTest)

#include "tst_areatesttest.moc"
