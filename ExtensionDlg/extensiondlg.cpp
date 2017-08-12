#include "extensiondlg.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QDialogButtonBox>

ExtensionDlg::ExtensionDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Extension Dialog"));
    createBaseInfo();
    createDetailInfo();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(baseWidget);
    mainLayout->addWidget(detailWidget);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->setSpacing(10);


}

ExtensionDlg::~ExtensionDlg()
{

}

void ExtensionDlg::createBaseInfo()
{
    baseWidget = new QWidget;
    QLabel *nameLabel = new QLabel(tr("姓名："));
    QLineEdit *nameLineEdit = new QLineEdit;
    QLabel *sexLabel = new QLabel(tr("性别："));
    QComboBox *sexComboBox = new QComboBox;
    sexComboBox->insertItem(0,tr("女"));
    sexComboBox->insertItem(1,tr("男"));
    sexComboBox->addItem(tr("中"));
    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(nameLabel,0,0);
    leftLayout->addWidget(nameLineEdit,0,1);
    leftLayout->addWidget(sexLabel,1,0);
    leftLayout->addWidget(sexComboBox,1,1);

    QPushButton *okBtn = new QPushButton(tr("确定"));
    QPushButton *detailBtn = new QPushButton(tr("详细"));
    QDialogButtonBox *btnBox = new QDialogButtonBox(Qt::Vertical);
    btnBox->addButton(okBtn,QDialogButtonBox::ActionRole);
    btnBox->addButton(detailBtn,QDialogButtonBox::ActionRole);
    QHBoxLayout *mainLayout = new QHBoxLayout(baseWidget);
    mainLayout->addStretch(1);
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(btnBox);
    connect(detailBtn,SIGNAL(clicked(bool)),this,SLOT(showDetailInfo()));

}

void ExtensionDlg::createDetailInfo()
{
    detailWidget = new QWidget;
    QLabel *ageLabel = new QLabel(tr("年龄"));
    QLineEdit *ageLineEdit = new QLineEdit;
    QLabel *departnentLabel = new QLabel(tr("部门"));
    QComboBox *departmentComboBox = new QComboBox;
    departmentComboBox->insertItem(0,tr("部门1"));
    departmentComboBox->insertItem(1,tr("部门2"));
    departmentComboBox->insertItem(2,tr("部门3"));
    QLabel *emailLabel = new QLabel(tr("email:"));
    QLineEdit *emailLineEdit = new QLineEdit;
    QGridLayout *detailLayout = new QGridLayout(detailWidget);
    detailLayout->addWidget(ageLabel,0,0);
    detailLayout->addWidget(ageLineEdit,0,1);
    detailLayout->addWidget(departnentLabel,1,0);
    detailLayout->addWidget(departmentComboBox,1,1);
    detailLayout->addWidget(emailLabel,2,0);
    detailLayout->addWidget(emailLineEdit,2,1);
    detailWidget->hide();

}

void ExtensionDlg::showDetailInfo()
{
    if(detailWidget->isHidden())
    {
        detailWidget->show();
    }
    else {
        detailWidget->hide();
    }
}























