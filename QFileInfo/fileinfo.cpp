#include "fileinfo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDateTime>
#include <QGridLayout>
#include <QFileInfo>

FileInfo::FileInfo(QWidget *parent)
    : QDialog(parent)
{
    createInterface();
    setWindowTitle(tr("File Information View"));
}

FileInfo::~FileInfo()
{

}

void FileInfo::createInterface()
{
    fileNameLabel = new QLabel(tr("文件名"));
    fileNameLineEdit = new QLineEdit;
    fileNameBtn = new QPushButton(tr("文件"));
    connect(fileNameBtn,SIGNAL(clicked()),this,SLOT(slotFile()));
    sizeLabel = new QLabel(tr("大小"));
    sizeLineEdit = new QLineEdit;
    createTimeLabel = new QLabel(tr("创建时间"));
    createTimeLineEdit = new QLineEdit;
    lastModifiedLabel = new QLabel(tr("最后修改时间"));
    lastModifiedLineEdit = new QLineEdit;
    lastReadLabel = new QLabel(tr("最后访问时间"));
    lastReadLineEdit = new QLineEdit;
    propertyLabel = new QLabel(tr("属性："));
    isDirCheckBox = new QCheckBox(tr("目录"));
    isFileCheckBox = new QCheckBox(tr("文件"));
    isSymLinkCheckBox = new QCheckBox(tr("符号链接"));
    isHiddenCheckBox = new QCheckBox(tr("隐藏"));
    isReadableCheckBox = new QCheckBox(tr("读"));
    isWritableCheckBox = new QCheckBox(tr("写"));
    isExecutableCheckBox = new QCheckBox(tr("执行"));
    getBtn = new QPushButton(tr("获取文件信息"));
    connect(getBtn,SIGNAL(clicked()),this,SLOT(slotGet()));
    QGridLayout *infoLayout = new QGridLayout;
    infoLayout->addWidget(fileNameLabel,0,0);
    infoLayout->addWidget(fileNameLineEdit,0,1);
    infoLayout->addWidget(fileNameBtn,0,2);
    infoLayout->addWidget(sizeLabel,1,0);
    infoLayout->addWidget(sizeLineEdit,1,1,1,2);
    infoLayout->addWidget(createTimeLabel,2,0);
    infoLayout->addWidget(createTimeLineEdit,2,1,1,2);
    infoLayout->addWidget(lastModifiedLabel,3,0);
    infoLayout->addWidget(lastModifiedLineEdit,3,1,1,2);
    infoLayout->addWidget(lastReadLabel,4,0);
    infoLayout->addWidget(lastReadLineEdit,4,1,1,2);
    QHBoxLayout *proLayout = new QHBoxLayout;
    proLayout->addWidget(propertyLabel);
    proLayout->addStretch();
    QHBoxLayout *checkBoxLayout = new QHBoxLayout;
    checkBoxLayout->addWidget(isDirCheckBox);
    checkBoxLayout->addWidget(isFileCheckBox);
    checkBoxLayout->addWidget(isSymLinkCheckBox);
    checkBoxLayout->addWidget(isHiddenCheckBox);
    checkBoxLayout->addWidget(isReadableCheckBox);
    checkBoxLayout->addWidget(isWritableCheckBox);
    checkBoxLayout->addWidget(isExecutableCheckBox);
    QHBoxLayout *getBtnLayout = new QHBoxLayout;
    getBtnLayout->addWidget(getBtn);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(infoLayout);
    mainLayout->addLayout(proLayout);
    mainLayout->addLayout(checkBoxLayout);
    mainLayout->addLayout(getBtnLayout);

}

void FileInfo::slotFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,"打开","/","files(*)");
    fileNameLineEdit->setText(fileName);
}

void FileInfo::slotGet()
{
    QString file = fileNameLineEdit->text();
    QFileInfo info(file);
    qint64 size = info.size();
    QDateTime created = info.created();
    QDateTime lastModified = info.lastModified();
    QDateTime lastRead = info.lastRead();
    bool isDir = info.isDir();
    bool isFile = info.isFile();
    bool isSymLink = info.isSymLink();
    bool isHidden = info.isHidden();
    bool isReadable = info.isReadable();
    bool isWritable = info.isWritable();
    bool isExecutable = info.isExecutable();

    sizeLineEdit->setText(QString::number(size));
    createTimeLineEdit->setText(created.toString());
    lastModifiedLineEdit->setText(lastModified.toString());
    lastReadLineEdit->setText(lastRead.toString());
    isDirCheckBox->setCheckState(isDir? Qt::Checked : Qt::Unchecked);
    isFileCheckBox->setCheckState(isFile? Qt::Checked : Qt::Unchecked);
    isSymLinkCheckBox->setCheckState(isSymLink? Qt::Checked : Qt::Unchecked);
    isHiddenCheckBox->setCheckState(isHidden? Qt::Checked : Qt::Unchecked);
    isReadableCheckBox->setCheckState(isReadable? Qt::Checked : Qt::Unchecked);
    isWritableCheckBox->setCheckState(isWritable? Qt::Checked : Qt::Unchecked);
    isExecutableCheckBox->setCheckState(isExecutable? Qt::Checked : Qt::Unchecked);
}












