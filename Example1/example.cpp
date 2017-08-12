#include "example.h"


Example::Example(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(900,450);
    setWindowTitle(tr("基本信息填写"));

    list = new QListWidget();
    list->insertItem(0,QObject::tr("基本信息"));
    list->insertItem(1,tr("联系方式"));
    list->insertItem(2,tr("详细资料"));


//    splitterMain->addWidget(rightMainWidget);


    stack = new QStackedWidget();
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
    baseInfo = new BaseInfo();
    contact = new Contact();
    detail = new Detail();
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    amendBtn = new QPushButton(tr("修改"));
    closeBtn = new QPushButton(tr("关闭"));
    btnLayout = new QHBoxLayout();
    btnLayout->addStretch(1);
    btnLayout->addWidget(amendBtn);
    btnLayout->addWidget(closeBtn);

    rightMainWidget = new QWidget();
    rightLayout = new QVBoxLayout(rightMainWidget);
    rightLayout->setMargin(15);
    rightLayout->setSpacing(10);
    rightLayout->addWidget(stack);
    rightLayout->addLayout(btnLayout);

    splitterMain = new QSplitter(Qt::Horizontal,this);
    splitterMain->setOpaqueResize(true);
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->addWidget(list);
    splitterMain->addWidget(rightMainWidget);

    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));

}

Example::~Example()
{

}
