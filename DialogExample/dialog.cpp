#include "dialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QDebug>
#include <QMessageBox>
#include<qmath.h>

//class MyMessageBox : public QMessageBox
//{
//    protected:
//    void showEvent(QShowEvent* event)
//    {
//        QMessageBox::showEvent(event);

//        QWidget  *textField = findChild<QWidget*>("qt_msgbox_label");

//        if(textField  != NULL)

//        {

//              textField ->setMinimumSize(640, 480);
//        }
//        //setFixedSize(640, 480);

//        QMessageBox::showEvent(event);
//    }
//};

MyMessageBox::MyMessageBox(QWidget *parent) : QMessageBox(parent)
{

}

MyMessageBox::~MyMessageBox()
{

}

void MyMessageBox::showEvent(QShowEvent *event)
{
    QWidget  *textField = findChild<QWidget*>("qt_msgbox_label");

    if(textField  != NULL)
    {
          textField ->setMinimumSize(640, 480);
    }
}


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("各种标准对话框的实例"));
    fileBtn = new QPushButton(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit;
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));

    colorBtn = new QPushButton(tr("颜色标准对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));

    fontBtn = new QPushButton(tr("字体标准对话框实例"));
    fontLineEdit = new QLineEdit(tr("Hello World"));
    mainLayout->addWidget(fontBtn,2,0);
    mainLayout->addWidget(fontLineEdit,2,1);
    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));

    inputDlg = new InputDlg(this);
    inputBtn = new QPushButton(tr("标准输入对话框实例"));
    mainLayout->addWidget(inputBtn,3,0);
    connect(inputBtn,SIGNAL(clicked()),this,SLOT(showInputDlg()));

    msgBoxDlg = new MsgBoxDlg(this);
    msgBoxBtn = new QPushButton(tr("标准消息框实例"));
    mainLayout->addWidget(msgBoxBtn,3,1);
    connect(msgBoxBtn,SIGNAL(clicked()),this,SLOT(showMsgBoxDlg()));

//    customDlg = new CustomDlg(this);
    customDlgBtn = new QPushButton(tr("用户自定义"));
    mainLayout->addWidget(customDlgBtn,4,0);
    connect(customDlgBtn,SIGNAL(clicked()),this,SLOT(showCustomDlg()));



}


Dialog::~Dialog()
{

}


void Dialog::showFile()
{
//    QString s = QFileDialog::getOpenFileName(this,"Open file dialog","/",
//                                             "C++ file(*.cpp)::C file(*.c)::Head file(*.h)");
//    fileLineEdit->setText(s);
    MyMessageBox box;
    box.warning(this,tr("info"),tr("resize"));
//    QMessageBox::warning(this,tr("info"),tr("resize"));


}

void Dialog::showColor()
{
    QColor c = QColorDialog::getColor();
    if(c.isValid())
    {
        colorFrame->setPalette(QPalette(c));
    }
}

void Dialog::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if(ok)
    {
        fontLineEdit->setFont(f);
    }
}

void Dialog::showInputDlg()
{
//    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgBoxDlg()
{
    msgBoxDlg->show();
}

void Dialog::showCustomDlg()
{
    customMsg = new QMessageBox;
    customMsg->setWindowTitle(tr("用户自定义消息框"));
    yesBtn = customMsg->addButton(tr("Yes"),QMessageBox::ActionRole);
    noBtn = customMsg->addButton(tr("No"),QMessageBox::ActionRole);
    cancel = customMsg->addButton(QMessageBox::Cancel);
    customMsg->setText(tr("这是一个用户自定义消息框"));
    customMsg->exec();
    if(customMsg->clickedButton()==yesBtn)
    {
      qDebug()<<"YES";
    }


}
















