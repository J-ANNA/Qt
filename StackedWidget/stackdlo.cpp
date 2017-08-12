#include "stackdlo.h"
#include "QHBoxLayout"

StackDlo::StackDlo(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("StackedWidget"));
    list = new QListWidget(this);
    list->insertItem(0,tr("window1"));
    list->insertItem(1,tr("window2"));
    list->insertItem(2,tr("window3"));

    label1 = new QLabel(tr("WindowsTest1"));
    label2 = new QLabel(tr("windowtest2"));
    label3 = new QLabel(tr("windowtest3"));
    stack = new QStackedWidget(this);

    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setMargin(5);
    mainLayout->addWidget(list,1);
    mainLayout->addWidget(stack,1,Qt::AlignHCenter);
    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));



}

StackDlo::~StackDlo()
{

}
