#include "mainwidget.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QSlider>
#include <QGroupBox>
#include <math.h>
#include <QWidget>


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    angle = 0;
    scaleValue = 5;
    shearValue = 5;
    translateValue =50;
    pixmap = new QPixmap;
    pixmap->load(":/new/picture/down.png");
    pixItem = new PixItem(pixmap);
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    scene->addItem(pixItem);
    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
//    QFrame *viewFrame = new QFrame;
//    QHBoxLayout *viewLayout = new QHBoxLayout;
//    viewLayout->addWidget(view);
//    viewFrame->setLayout(viewLayout);
    ctrlFrame = new QFrame;
    createControlFrame();
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin(10);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(view);
    mainLayout->addWidget(ctrlFrame);
    setLayout(mainLayout);
    setWindowTitle(tr("Graphics Item Transformation"));


}

MainWidget::~MainWidget()
{

}

void MainWidget::createControlFrame()
{
    //旋转控制
    QSlider *rotateSlider = new QSlider;
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setRange(0,360);
    QHBoxLayout *rotateLayout = new QHBoxLayout;
    rotateLayout->addWidget(rotateSlider);
    QGroupBox *rotateGroupBox = new QGroupBox(tr("Rotate"));
    rotateGroupBox->setLayout(rotateLayout);
    //缩放控制
    QSlider *scaleSlider = new QSlider;
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0,2*scaleValue);
    scaleSlider->setValue(scaleValue);
    QHBoxLayout *scaleLayout = new QHBoxLayout;
    scaleLayout->addWidget(scaleSlider);
    QGroupBox *scaleGroupBox = new QGroupBox(tr("Scale"));
    scaleGroupBox->setLayout(scaleLayout);
    //切变控制
    QSlider *shearSlider = new QSlider;
    shearSlider->setOrientation(Qt::Horizontal);
    shearSlider->setRange(0,2*shearValue);
    shearSlider->setValue(shearValue);
    QHBoxLayout *shearLayout = new QHBoxLayout;
    shearLayout->addWidget(shearSlider);
    QGroupBox *shearGroupBox = new QGroupBox(tr("Shear"));
    shearGroupBox->setLayout(shearLayout);
    //位移控制
    QSlider *translateSlider = new QSlider;
    translateSlider->setOrientation(Qt::Horizontal);
    translateSlider->setRange(0,2*translateValue);
    translateSlider->setValue(translateValue);
    QHBoxLayout *translateLayout = new QHBoxLayout;
    translateLayout->addWidget(translateSlider);
    QGroupBox *translateGroupBox = new QGroupBox(tr("Translate"));
    translateGroupBox->setLayout(translateLayout);
    QVBoxLayout *ctrlLayout = new QVBoxLayout;
    ctrlLayout->setMargin(10);
    ctrlLayout->setSpacing(20);
    ctrlLayout->addWidget(rotateGroupBox);
    ctrlLayout->addWidget(scaleGroupBox);
    ctrlLayout->addWidget(shearGroupBox);
    ctrlLayout->addWidget(translateGroupBox);
    ctrlFrame->setLayout(ctrlLayout);

    connect(rotateSlider,SIGNAL(valueChanged(int)),this,SLOT(slotRotate(int)));
    connect(scaleSlider,SIGNAL(valueChanged(int)),this,SLOT(slotScale(int)));
    connect(shearSlider,SIGNAL(valueChanged(int)),this,SLOT(slotShear(int)));
    connect(translateSlider,SIGNAL(valueChanged(int)),this,SLOT(slotTranslate(int)));

}

void MainWidget::slotRotate(int value)
{
    view->rotate(value - angle);
    angle = value;
}

void MainWidget::slotScale(int value)
{
    qreal s;
    if(value>scaleValue)
    {
        s = pow(1.1,(value - scaleValue));
    }
    else
    {
        s = pow(1/1.1,(scaleValue - value));
    }
    view->scale(s,s);
    scaleValue = value;
}

void MainWidget::slotShear(int value)
{
    view->shear((value - shearValue)/10.0,0);
    shearValue = value;
}

void MainWidget::slotTranslate(int value)
{
//    view->translate(value - translateValue,value - translateValue);
//    translateValue = value;
    pixItem->setPos(value - translateValue + pixItem->pos().x(),value - translateValue + pixItem->pos().y());
    translateValue = value;

}

















