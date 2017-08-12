#include "mainwindow.h"
#include <QColorDialog>
#include <QIcon>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);
    createToolBar();
    setMinimumSize(600,400);
    showStyle();
    drawWidget->setColor(Qt::blue);
    drawWidget->setWidth(widthSpinBox->value());

}

MainWindow::~MainWindow()
{

}

void MainWindow::createToolBar()
{
    styleLabel = new QLabel(tr("线型风格"));
    styleComboBox = new QComboBox;
    styleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    styleComboBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    connect(styleComboBox,SIGNAL(activated(int)),this,SLOT(showStyle()));
    widthLabel = new QLabel(tr("线宽"));
    widthSpinBox = new QSpinBox;
    widthSpinBox->setRange(0,20);
    widthSpinBox->stepBy(10);
    drawWidget->setWidth(10);
    connect(widthSpinBox,SIGNAL(valueChanged(int)),drawWidget,SLOT(setWidth(int)));
    colorBtn = new QPushButton;
    QPixmap colorPix(20,20);
    colorPix.fill(Qt::blue);
    colorBtn->setIcon(QIcon(colorPix));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));
    clearBtn = new QPushButton(tr("清除"));
    connect(clearBtn,SIGNAL(clicked()),drawWidget,SLOT(clear()));
    toolBar = addToolBar("Tool");
    toolBar->addWidget(styleLabel);
    toolBar->addWidget(styleComboBox);
    toolBar->addWidget(widthLabel);
    toolBar->addWidget(widthSpinBox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);

    paintNumLabel = new QLabel;
    toolBar->addWidget(paintNumLabel);

    connect(drawWidget,SIGNAL(signalPaintNum(int)),this,SLOT(showPaintNum(int)));


}

void MainWindow::showStyle()
{
    drawWidget->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(),Qt::UserRole).toInt());

}

void MainWindow::showColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue),this);
    if(color.isValid())
    {
        drawWidget->setColor(color);
        QPixmap p(20,20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));
    }
}

void MainWindow::showPaintNum(int num)
{
    paintNumLabel->setText(QString::number(num));
}
















