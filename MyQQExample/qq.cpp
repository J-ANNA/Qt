#include "qq.h"

QQ::QQ(QWidget *parent, Qt::WindowFlags f) :QToolBox(parent,f)
{
    setWindowTitle(tr("My QQ"));
    toolBtn1_1 = new QToolButton;
    toolBtn1_1->setText(tr("张三"));
    toolBtn1_1->setAutoRaise(true);
    toolBtn1_2 = new QToolButton;
    toolBtn1_2->setText(tr("李四"));
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_3 = new QToolButton;
    toolBtn1_3->setText(tr("王五"));
    toolBtn1_3->setAutoRaise(true);
    groupBox1 = new QGroupBox;
    layout1 = new QVBoxLayout(groupBox1);
    layout1->setMargin(10);
    layout1->setAlignment(Qt::AlignCenter);
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addStretch();


    toolBtn2_1 = new QToolButton;
    toolBtn2_1->setText(tr("张三"));
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_2 = new QToolButton;
    toolBtn2_2->setText(tr("李四"));
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_3 = new QToolButton;
    toolBtn2_3->setText(tr("王五"));
    toolBtn2_3->setAutoRaise(true);
    groupBox2 = new QGroupBox;
    layout2 = new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);
    layout2->addWidget(toolBtn2_3);

    toolBtn3_1 = new QToolButton;
    toolBtn3_1->setText(tr("张三"));
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_2 = new QToolButton;
    toolBtn3_2->setText(tr("李四"));
    toolBtn3_2->setAutoRaise(true);
    groupBox3 = new QGroupBox;
    layout3 = new QVBoxLayout(groupBox3);
    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(toolBtn3_2);

    this->addItem((QWidget*)groupBox1,tr("我的好友"));
    this->addItem((QWidget*)groupBox2,tr("陌生人"));
    this->addItem((QWidget*)groupBox3,tr("黑名单"));
}
