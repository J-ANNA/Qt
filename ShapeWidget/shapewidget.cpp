#include "shapewidget.h"
#include <QPixmap>
#include <QBitmap>
#include <QLabel>
#include <QPalette>
#include <QHBoxLayout>

ShapeWidget::ShapeWidget(QWidget *parent)
    : QWidget(parent)
{
//    setAutoFillBackground(true);
//    QPixmap pix;
//    pix.load(":/new/prefix1/picture/8cm.jpg",0,Qt::AvoidDither | Qt::ThresholdDither | Qt::ThresholdAlphaDither);
//    resize(pix.size());
//    setMask(QBitmap(pix.mask()));

    QHBoxLayout *layout = new QHBoxLayout(this);
    QLabel *label = new QLabel;
    label->resize(150,150);
//    label->setScaledContents(true);
    label->setAutoFillBackground(true);
//    QPixmap pix(":/new/prefix1/picture/8cm.jpg");
    QPixmap pix;
    pix.load(":/new/prefix1/picture/8cm.jpg",0);
    QPalette p = label->palette();
    p.setBrush(QPalette::Window,QBrush(pix));
    label->setPalette(p);
//    label->resize(50,50);
    layout->addWidget(label);

//    QFont font = QFont("宋体",20);
//    QLabel *label2 = new QLabel(this);
//    label2->setFont(font);
//    label2->setText(tr("这是一个测试aaaaaaaaaa"));


}

ShapeWidget::~ShapeWidget()
{

}
