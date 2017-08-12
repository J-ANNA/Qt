#include "msgboxdlg.h"
#include <QMessageBox>

MsgBoxDlg::MsgBoxDlg(QWidget *parent): QDialog(parent)
{
    setWindowTitle(tr("标准消息对话框实例"));
    label = new QLabel;
    label->setText(tr("请选择一种消息对话框"));
    questionBtn = new QPushButton(tr("QuestionMsg"));
    informationBtn = new QPushButton(tr("InformationMsg"));
    warningBtn = new QPushButton(tr("WarningMsg"));
    criticalBtn = new QPushButton(tr("CtricalMsg"));
    aboutBtn = new QPushButton(tr("AboutMsg"));
    aboutQtBtn = new QPushButton(tr("AboutQtMsg"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);

    connect(questionBtn,SIGNAL(clicked()),this,SLOT(showQuestionMsg()));
    connect(informationBtn,SIGNAL(clicked()),this,SLOT(showInformationMsg()));
    connect(warningBtn,SIGNAL(clicked()),this,SLOT(showWarningMsg()));
    connect(criticalBtn,SIGNAL(clicked()),this,SLOT(showCriticalMsg()));
    connect(aboutBtn,SIGNAL(clicked()),this,SLOT(showAboutMsg()));
    connect(aboutQtBtn,SIGNAL(clicked()),this,SLOT(showAboutQtMsg()));
}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Question Message Box"));
    switch(QMessageBox::question(this,tr("Question消息框"),tr("您现在已经完成修改，是否要结束程序？"),
                                 QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        label->setText("Question button/OK");
        break;
    case QMessageBox::Cancel:
        label->setText("Question button/Cancel");
    default:
        break;

    }
    return;
}

void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this,tr("Information消息框"),tr("Information消息框测试"));
    return;
}

void MsgBoxDlg::showWarningMsg()
{
    label->setText(tr("Warning Message Box"));
    switch(QMessageBox::warning(this,tr("Warning消息框"),tr("您修改的内容尚未保存，是否要保存对文档的修改？"),
                                 QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,QMessageBox::Save))
    {
    case QMessageBox::Save:
        label->setText("Question button/Save");
        break;
    case QMessageBox::Discard:
        label->setText("Question button/Discard");
        break;
    case QMessageBox::Cancel:
        label->setText("Question button/Cancel");
    default:
        break;

    }
    return;
}

void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Cricital Message Box"));
    QMessageBox::critical(this,tr("Cricital消息框"),tr("Cricital消息框测试"));
    return;
}

void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("About Message Box"));
    QMessageBox::about(this,tr("About消息框"),tr("About消息框测试"));
    return;
}

void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("AboutQt Message Box"));
    QMessageBox::aboutQt(this,tr("AboutQt消息框"));
    return;
}
