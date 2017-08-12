#include "geometry.h"
#include <QString>

Geometry::Geometry(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Geometry"));
    xLabel = new QLabel(tr("x():"));
    xValueLabel = new QLabel;
    yLabel = new QLabel(tr("y():"));
    yValueLabel = new QLabel;
    posLabel = new QLabel(tr("pos():"));
    posValueLabel = new QLabel;
    frameLabel = new QLabel(tr("Frame():"));
    frameValueLabel = new QLabel;
    geometryLabel = new QLabel(tr("geometry():"));
    geometryValueLabel = new QLabel;
    widthLabel = new QLabel(tr("width():"));
    widthValueLabel = new QLabel;
    heightLabel = new QLabel(tr("height():"));
    heightValueLabel = new QLabel;
    rectLabel = new QLabel(tr("rect():"));
    rectValueLabel = new QLabel;
    sizeLabel = new QLabel(tr("size():"));
    sizeValueLabel = new QLabel;
    resizeBtn = new QPushButton(tr("重置大小"));
    connect(resizeBtn,SIGNAL(clicked()),this,SLOT(resizeWidget()));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(xLabel,0,0);
    mainLayout->addWidget(xValueLabel,0,1);
    mainLayout->addWidget(yLabel,1,0);
    mainLayout->addWidget(yValueLabel,1,1);
    mainLayout->addWidget(posLabel,2,0);
    mainLayout->addWidget(posValueLabel,2,1);
    mainLayout->addWidget(frameLabel,3,0);
    mainLayout->addWidget(frameValueLabel,3,1);
    mainLayout->addWidget(geometryLabel,4,0);
    mainLayout->addWidget(geometryValueLabel,4,1);
    mainLayout->addWidget(widthLabel,5,0);
    mainLayout->addWidget(widthValueLabel,5,1);
    mainLayout->addWidget(heightLabel,6,0);
    mainLayout->addWidget(heightValueLabel,6,1);
    mainLayout->addWidget(rectLabel,7,0);
    mainLayout->addWidget(rectValueLabel,7,1);
    mainLayout->addWidget(sizeLabel,8,0);
    mainLayout->addWidget(sizeValueLabel,8,1);
    mainLayout->addWidget(resizeBtn,9,1);
    updateLabel();
}

Geometry::~Geometry()
{

}

void Geometry::updateLabel()
{
    QString xStr;
    xValueLabel->setText(xStr.setNum(x()));
    QString yStr;
    yValueLabel->setText(yStr.setNum(y()));
    QString posStr;
    QString tempPosStr1,tempPosStr2;
    posStr = tempPosStr1.setNum(pos().x())+","+tempPosStr2.setNum(pos().y());
    posValueLabel->setText(posStr);
    QString frameStr;
    QString tempFrameStr1,tempFrameStr2,tempFrameStr3,tempFrameStr4;
    frameStr = tempFrameStr1.setNum(frameGeometry().x())+","+tempFrameStr2.setNum(frameGeometry().y())
            +","+tempFrameStr3.setNum(frameGeometry().width())+","+tempFrameStr4.setNum(frameGeometry().height());
    frameValueLabel->setText(frameStr);
    QString geometryStr;
    QString tempGeometryStr1,tempGeometryStr2,tempGeometryStr3,tempGeometryStr4;
    geometryStr = tempGeometryStr1.setNum(geometry().x())+","+tempGeometryStr2.setNum(geometry().y())
            +","+tempGeometryStr3.setNum(geometry().width())+","+tempGeometryStr4.setNum(geometry().height());
    geometryValueLabel->setText(geometryStr);
    QString widthStr;
    widthValueLabel->setText(widthStr.setNum(width()));
    QString heightStr;
    heightValueLabel->setText(heightStr.setNum(height()));
    QString rectStr;
    QString tempRectStr1,tempRectStr2,tempRectStr3,tempRectStr4;
    rectStr = tempRectStr1.setNum(rect().x()) + "," + tempRectStr2.setNum(rect().y())
              + "," + tempRectStr3.setNum(rect().width()) + "," + tempRectStr4.setNum(rect().height());
    rectValueLabel->setText(rectStr);
    QString sizeStr;
    QString tempSizeStr1,tempSizeStr2;
    sizeStr = tempSizeStr1.setNum(size().width()) + "," + tempSizeStr2.setNum(size().height());
    sizeValueLabel->setText(sizeStr);

}

void Geometry::moveEvent(QMoveEvent *)
{
    updateLabel();
}

void Geometry::resizeEvent(QResizeEvent *)
{
    updateLabel();
}

void Geometry::resizeWidget()
{
    resize(400,300);
}
