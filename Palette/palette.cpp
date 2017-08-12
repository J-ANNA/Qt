#include "palette.h"
#include <QHBoxLayout>
#include <QStringList>
#include <QString>
#include <QColor>
#include <QPalette>
#include <QPixmap>

Palette::Palette(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(contentFrame);


}

Palette::~Palette()
{

}

void Palette::createCtrlFrame()
{
    ctrlFrame = new QFrame;
    windowLabel = new QLabel(tr("QPalette::Window"));
    windowComboBox = new QComboBox;
    fillColorList(windowComboBox);
    windowTextLabel = new QLabel(tr("Qpalette::WindowText"));
    windowTextComboBox =new QComboBox;
    fillColorList(windowTextComboBox);
    btnLabel = new QLabel(tr("QPalette::Button"));
    btnComboBox = new QComboBox;
    fillColorList(btnComboBox);
    btnTextLabel = new QLabel(tr("QPalette::ButtonText"));
    btnTextComboBox = new QComboBox;
    fillColorList(btnTextComboBox);
    baseLabel = new QLabel(tr("QPalette::Base"));
    baseComboBox = new QComboBox;
    fillColorList(baseComboBox);
    QGridLayout *leftMainLayout = new QGridLayout(ctrlFrame);
    leftMainLayout->setSpacing(20);
    leftMainLayout->setMargin(5);
    leftMainLayout->addWidget(windowLabel,0,0);
    leftMainLayout->addWidget(windowComboBox,0,1);
    leftMainLayout->addWidget(windowTextLabel,1,0);
    leftMainLayout->addWidget(windowTextComboBox,1,1);
    leftMainLayout->addWidget(btnLabel,2,0);
    leftMainLayout->addWidget(btnComboBox,2,1);
    leftMainLayout->addWidget(btnTextLabel,3,0);
    leftMainLayout->addWidget(btnTextComboBox,3,1);
    leftMainLayout->addWidget(baseLabel,4,0);
    leftMainLayout->addWidget(baseComboBox,4,1);

    connect(windowComboBox,SIGNAL(activated(int)),this,SLOT(showWindow()));
    connect(windowTextComboBox,SIGNAL(activated(int)),this,SLOT(showWindowText()));
    connect(btnComboBox,SIGNAL(activated(int)),this,SLOT(showButton()));
    connect(btnTextComboBox,SIGNAL(activated(int)),this,SLOT(showButtonText()));
    connect(baseComboBox,SIGNAL(activated(int)),this,SLOT(showBase()));

}

void Palette::createContentFrame()
{
    contentFrame = new QFrame;
    contentFrame->setAutoFillBackground(true);
    valueLabel = new QLabel(tr("请选择一个值"));
    valueComboBox = new QComboBox;
    strLabel = new QLabel(tr("请输入字符串"));
    strLineEdit = new QLineEdit;
    textEdit = new QTextEdit;
    okBtn = new QPushButton(tr("确认"));
    okBtn->setAutoFillBackground(true);
    cancelBtn = new QPushButton(tr("取消"));
    QGridLayout *rightTopLayout = new QGridLayout;
    rightTopLayout->addWidget(valueLabel,0,0);
    rightTopLayout->addWidget(valueComboBox,0,1);
    rightTopLayout->addWidget(strLabel,1,0);
    rightTopLayout->addWidget(strLineEdit,1,1);
    rightTopLayout->addWidget(textEdit,2,0,1,2);
    QHBoxLayout *rightBottomLayout = new QHBoxLayout;
    rightBottomLayout->addStretch(1);
    rightBottomLayout->addWidget(okBtn);
    rightBottomLayout->addWidget(cancelBtn);
    QVBoxLayout *rightMainLayout = new QVBoxLayout(contentFrame);
    rightMainLayout->addLayout(rightTopLayout);
    rightMainLayout->addLayout(rightBottomLayout);


}

void Palette::showWindow()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Window,color);
    contentFrame->setPalette(p);
    contentFrame->update();

}

void Palette::showWindowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::WindowText,color);
    contentFrame->setPalette(p);
//    contentFrame->update();
}

void Palette::showButton()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[btnComboBox->currentIndex()]);
//    QPalette p = contentFrame->palette();  //???
//    p.setColor(QPalette::Button,color);
//    contentFrame->setPalette(p);
//    contentFrame->update();
    QPalette p = okBtn->palette();
    p.setColor(QPalette::Button,color);
    okBtn->setAutoFillBackground(true);
    okBtn->setPalette(p);
    okBtn->update();
}


void Palette::showButtonText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[btnTextComboBox->currentIndex()]);
//    QPalette p = contentFrame->palette();  //???
//    p.setColor(QPalette::ButtonText,color);
//    contentFrame->setPalette(p);
//    contentFrame->update();

    QPalette p = okBtn->palette();
    p.setColor(QPalette::ButtonText,color);
    okBtn->setPalette(p);
    okBtn->update();

}

void Palette::showBase()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[baseComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();  //???
    p.setColor(QPalette::Base,color);
    contentFrame->setPalette(p);
//    contentFrame->update();
}

void Palette::fillColorList(QComboBox * comboBox)
{
    QStringList colorList = QColor::colorNames();
    QString colorString;
    foreach (colorString, colorList)
    {
        QPixmap pix(QSize(70,20));
        pix.fill(QColor(colorString));
        comboBox->addItem(QIcon(pix),NULL);
        comboBox->setIconSize(QSize(70,20));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }

}
























