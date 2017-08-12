#ifndef QQ_H
#define QQ_H

#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>

class QQ : public QToolBox
{
    Q_OBJECT
public:
    QQ(QWidget *parent=0,Qt::WindowFlags f=0);
private:
    QToolButton *toolBtn1_1;
    QToolButton *toolBtn1_2;
    QToolButton *toolBtn1_3;
    QToolButton *toolBtn2_1;
    QToolButton *toolBtn2_2;
    QToolButton *toolBtn2_3;
    QToolButton *toolBtn3_1;
    QToolButton *toolBtn3_2;

    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QGroupBox *groupBox3;

    QVBoxLayout *layout1;
    QVBoxLayout *layout2;
    QVBoxLayout *layout3;

};

#endif // QQ_H
