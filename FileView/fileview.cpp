#include "fileview.h"
#include <QStringList>
#include <QDebug>

FileView::FileView(QWidget *parent, Qt::WindowFlags f) :QDialog(parent,f)
{
    setWindowTitle(tr("File View"));
    fileLineEdit = new QLineEdit(tr("/"));
    fileListWidget = new QListWidget;
    btn = new QPushButton(tr("按键"));
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(fileLineEdit);
    mainLayout->addWidget(fileListWidget);
    mainLayout->addWidget(btn);
    connect(fileLineEdit,SIGNAL(returnPressed()),this,SLOT(slotShow(QDir)));
    connect(fileListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotDirShow(QListWidgetItem*)));
    connect(btn,SIGNAL(clicked()),this,SLOT(slotShowDeleteFileBox()));
    QString root = "/";
    QDir rootDir(root);
    QStringList string;
    string<<"*";
    QFileInfoList list = rootDir.entryInfoList(string);
    showFileInfoList(list);

    QString str1 = "/storage/emulated/0/";
    QString str2;
    str2 = str1.mid(19);
    qDebug()<<str2;
    if(str2 == "/")
    {
        qDebug()<<"case1"<<endl;
    }

}

void FileView::showFileInfoList(QFileInfoList list)
{
    fileListWidget->clear();
    for(unsigned int i=0;i<list.count();i++)
    {
        QFileInfo tmpFileInfo =list.at(i);
        if(tmpFileInfo.isDir())
        {
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(fileName);
            fileListWidget->addItem(tmp);
        }
        else if(tmpFileInfo.isFile())
        {
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(fileName);
            fileListWidget->addItem(tmp);
        }
    }
}

void FileView::slotShow(QDir dir)
{
    QStringList string;
    string<<"*";
    QFileInfoList list = dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);
    showFileInfoList(list);
}

void FileView::slotDirShow(QListWidgetItem *item)
{
    QString str = item->text();
    QDir dir;
    dir.setPath(fileLineEdit->text());          //设置QDir对象的路径为当前目录路径
    dir.cd(str);                                //根据下一级目录重新设置QDir对象的路径
    fileLineEdit->setText(dir.absolutePath());
    slotShow(dir);
}

void FileView::slotShowDeleteFileBox()
{
    deleteFileBox = new QMessageBox;
    deleteFileBox->setWindowTitle(tr("提示"));
    enterBtn = deleteFileBox->addButton(tr("删除"),QMessageBox::ActionRole);
    cancelBtn = deleteFileBox->addButton(tr("取消"),QMessageBox::ActionRole);
    deleteFileBox->setText(tr("确认删除文件？"));
    deleteFileBox->exec();
}

FileView::~FileView()
{

}


