#include "inputdlg.h"
#include <QInputDialog>
#include <QStringList>
#include <QDebug>

InputDlg::InputDlg(QWidget *parent) :QDialog(parent)
{
    setWindowTitle(tr("标准输入对话框实例"));

    nameLabel = new QLabel(tr("姓名："));
    sexLabel = new QLabel(tr("性别："));
    ageLabel = new QLabel(tr("年龄："));
    scorelabel = new QLabel(tr("成绩："));
    nameInputLabel = new QLabel(tr("张三"));
    nameInputLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    sexInputLabel = new QLabel(tr("男"));
    sexInputLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ageInputLabel = new QLabel(tr("21"));
    ageInputLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    scoreInputLabel = new QLabel(tr("80"));
    scoreInputLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    nameBtn = new QPushButton(tr("修改姓名"));
    sexBtn = new QPushButton(tr("修改性别"));
    ageBtn = new QPushButton(tr("修改年龄"));
    scoreBtn = new QPushButton(tr("修改成绩"));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nameLabel,0,0);
    mainLayout->addWidget(nameInputLabel,0,1);
    mainLayout->addWidget(nameBtn,0,2);
    mainLayout->addWidget(sexLabel,1,0);
    mainLayout->addWidget(sexInputLabel,1,1);
    mainLayout->addWidget(sexBtn,1,2);
    mainLayout->addWidget(ageLabel,2,0);
    mainLayout->addWidget(ageInputLabel,2,1);
    mainLayout->addWidget(ageBtn,2,2);
    mainLayout->addWidget(scorelabel,3,0);
    mainLayout->addWidget(scoreInputLabel,3,1);
    mainLayout->addWidget(scoreBtn,3,2);

    connect(nameBtn,SIGNAL(clicked()),this,SLOT(changeName()));
    connect(sexBtn,SIGNAL(clicked()),this,SLOT(changeSex()));
    connect(ageBtn,SIGNAL(clicked()),this,SLOT(changeAge()));
    connect(scoreBtn,SIGNAL(clicked()),this,SLOT(changeScore()));

}

void InputDlg::changeName()  //字符串输入框
{
    bool ok;
    QString text = QInputDialog::getText(this,tr("标准字符串输入对话框"),tr("请输入姓名："),
                                         QLineEdit::Normal,nameInputLabel->text(),&ok);
    if(ok && !text.isEmpty())
    {
        nameInputLabel->setText(text);
    }
}

void InputDlg::changeSex()   //条目输入框
{
    QStringList sexItems;
    sexItems<<tr("男")<<tr("女");
    bool ok;
    QString sexItem = QInputDialog::getItem(this,tr("标准条目选择对话框"),tr("请选择性别："),sexItems,0,false,&ok);
    if(ok && !sexItem.isEmpty())
    {
        sexInputLabel->setText(sexItem);
    }
}

void InputDlg::changeAge()
{
    bool ok;
    int age = QInputDialog::getInt(this,tr("标准int类型输入对话框"),tr("请输入年龄"),ageInputLabel->text().toInt(&ok),
                                   0,100,1,&ok);

    if(ok)
    {
        ageInputLabel->setText(QString(tr("%1")).arg(age));
    }

}

void InputDlg::changeScore()
{
    bool ok;
    double score = QInputDialog::getDouble(this,tr("标准double类型输入对话框"),tr("请输入年龄"),
                                           scoreInputLabel->text().toDouble(&ok),0,100,1,&ok);
    if(ok)
    {
        scoreInputLabel->setText(tr("%1").arg(score));
    }
}





















