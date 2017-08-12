#include "baseinfo.h"
#include "QPixmap"

BaseInfo::BaseInfo(QWidget *parent) :QWidget(parent)
{
    //左侧
    userNameLabel = new QLabel(tr("用户名"));
    nameLabel = new QLabel(tr("姓名"));
    sexLabel = new QLabel(tr("性别"));
    departmentLabel = new QLabel(tr("部门"));
    ageLabel = new QLabel(tr("年龄"));
    otherLabel = new QLabel(tr("备注："));
    otherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);   //内凹
    userNameEdit = new QLineEdit;
    nameEdit = new QLineEdit;
    sexComboBox = new QComboBox;
    sexComboBox->addItem(tr("男"));
    sexComboBox->addItem(tr("女"));
    departmentEdit = new QTextEdit;
    ageEdit = new QLineEdit;
    leftLayout = new QGridLayout();
    leftLayout->addWidget(userNameLabel,0,0);
    leftLayout->addWidget(userNameEdit,0,1);
    leftLayout->addWidget(nameLabel,1,0);
    leftLayout->addWidget(nameEdit,1,1);
    leftLayout->addWidget(sexLabel,2,0);
    leftLayout->addWidget(sexComboBox,2,1);
    leftLayout->addWidget(departmentLabel,3,0);
    leftLayout->addWidget(departmentEdit,3,1);
    leftLayout->addWidget(ageLabel,4,0);
    leftLayout->addWidget(ageEdit,4,1);
    leftLayout->addWidget(otherLabel,5,0,1,2);
    leftLayout->setColumnStretch(0,1);
    leftLayout->setColumnStretch(1,1);

    //右侧
    headLabel = new QLabel(tr("头像："));
    headIconLabel = new QLabel();
    QPixmap icon(":/new/src/8cm.jpg");
    headIconLabel->setPixmap(icon);
//    headIconLabel = new QLabel(tr("暂无"));
    updateHeadBtn = new QPushButton(tr("更新"));
    topRightLayout = new QHBoxLayout();
    topRightLayout->setSpacing(20);
    topRightLayout->addWidget(headLabel);
    topRightLayout->addWidget(headIconLabel);
    topRightLayout->addWidget(updateHeadBtn);
    introductionLabel = new QLabel(tr("个人说明"));
    introductionEdit = new QTextEdit();
    rightLayout = new QVBoxLayout();
    rightLayout->setMargin(20);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(introductionLabel);
    rightLayout->addWidget(introductionEdit);

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(leftLayout,0,0);
    mainLayout->addLayout(rightLayout,0,1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


}
