#include "contact.h"


Contact::Contact(QWidget *parent) : QWidget(parent)
{
    emailLabel = new QLabel(tr("电子邮件"));
    addrLabel = new QLabel(tr("联系地址"));
    codeLabel = new QLabel(tr("邮政编码"));
    moveTelLabel = new QLabel(tr("移动电话"));
    proTelLabel = new QLabel(tr("办公电话"));
    emailEdit = new QLineEdit;
    addrEdit = new QLineEdit;
    codeEdit = new QLineEdit;
    moveTelEdit = new QLineEdit;
    proTelEdit = new QLineEdit;
    moveTelCheckBox = new QCheckBox(tr("接收留言"));
    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(emailLabel,0,0);
    mainLayout->addWidget(addrLabel,1,0);
    mainLayout->addWidget(codeLabel,2,0);
    mainLayout->addWidget(moveTelLabel,3,0);
    mainLayout->addWidget(proTelLabel,4,0);
    mainLayout->addWidget(emailEdit,0,1);
    mainLayout->addWidget(addrEdit,1,1);
    mainLayout->addWidget(codeEdit,2,1);
    mainLayout->addWidget(moveTelEdit,3,1);
    mainLayout->addWidget(proTelEdit,4,1);
    mainLayout->addWidget(moveTelCheckBox,3,2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
