#include "showwidget.h"
#include <QHBoxLayout>

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{
    imgLabel = new QLabel;
//    imgLabel->setScaledContents(true);
    textEdit = new QTextEdit;
    textEdit->setFontUnderline(true);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(imgLabel);
    mainLayout->addWidget(textEdit);

}
