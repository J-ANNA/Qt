#include "progressdlg.h"
#include <QFont>

ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    QFont font("ZYSong18030",12);
    setFont(font);
    setWindowTitle(tr("Progress"));
    fileNumLabel = new QLabel(tr("文件数目"));
    fileNumLineEdit = new QLineEdit;
    fileNumLineEdit->setText(tr("100000"));
    progressType = new QLabel(tr("显示类型"));
    comboBox = new QComboBox;
    comboBox->addItem(tr("progressBar"));
    comboBox->addItem(tr("progressDialog"));
    progressBar = new QProgressBar;
    startBtn = new QPushButton(tr("开始"));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileNumLabel,0,0);
    mainLayout->addWidget(fileNumLineEdit,0,1);
    mainLayout->addWidget(progressType,1,0);
    mainLayout->addWidget(comboBox,1,1);
    mainLayout->addWidget(progressBar,2,0,1,2);
    mainLayout->addWidget(startBtn,3,1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(startBtn,SIGNAL(clicked()),this,SLOT(startprogress()));
}

ProgressDlg::~ProgressDlg()
{

}

void ProgressDlg::startprogress()
{
    bool ok;
    int num = fileNumLineEdit->text().toInt(&ok);
    if(comboBox->currentIndex() == 0)
    {
        progressBar->setRange(0,num);
//        progressBar->setInvertedAppearance(true);
//        progressBar->setFormat("%v");
        for(int i = 1;i<num+1;i++)
        {
            progressBar->setValue(i);
        }
    }
    else if(comboBox->currentIndex() == 1)
    {
        QProgressDialog *progressDlg = new QProgressDialog(this);
        progressDlg->setWindowModality(Qt::WindowModal);
        progressDlg->setMinimumDuration(5);
        progressDlg->setWindowTitle(tr("Please Wait"));
        progressDlg->setLabelText(tr("Copying..."));
        progressDlg->setCancelButtonText(tr("Cancel"));
        progressDlg->setRange(0,num);

        for(int i=1;i<num+1;i++)
        {
            progressDlg->setValue(i);
            if(progressDlg->wasCanceled())
            {
                return;
            }
        }
    }
}















