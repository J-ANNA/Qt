#include "mapwidget.h"
#include <QSlider>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>
#include <qmap.h>
#include <QFrame>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QPoint>
#include <QMouseEvent>

MapWidget::MapWidget()
{
    readMap();
    zoom = 50;
    int width = map.width();
    int height = map.height();
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(-width/2,-height/2,width,height);
    setScene(scene);
    setCacheMode(CacheBackground);

    //用于地图缩放的滑动条
    QSlider *slider = new QSlider;
    slider->setOrientation(Qt::Vertical);
    slider->setRange(1,100);
    slider->setTickInterval(10);
    slider->setValue(50);
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(slotZoom(int)));
    QLabel *zoomInLabel = new QLabel(tr("放大"));
    zoomInLabel->setScaledContents(true);
    QLabel *zoomOutLabel = new QLabel(tr("缩小"));
    zoomOutLabel->setScaledContents(true);
    QLabel *viewStrLabel = new QLabel(tr("GraphicsView:"));
    viewCoordLabel = new QLabel;
    QLabel *sceneStrLabel = new QLabel(tr("GraphicsScene:"));
    sceneCoordLabel = new QLabel;
    QLabel *mapStrLabel = new QLabel(tr("map:"));
    mapCoordLabel = new QLabel;
    QGridLayout *coordLayout = new QGridLayout;
    coordLayout->addWidget(viewStrLabel,0,0);
    coordLayout->addWidget(viewCoordLabel,0,1);
    coordLayout->addWidget(sceneStrLabel,1,0);
    coordLayout->addWidget(sceneCoordLabel,1,1);
    coordLayout->addWidget(mapStrLabel,2,0);
    coordLayout->addWidget(mapCoordLabel,2,1);
    coordLayout->setSizeConstraint(QLayout::SetFixedSize);
    QFrame *coordFrame = new QFrame;
    coordFrame->setLayout(coordLayout);
    QVBoxLayout *mainCoordLayout = new QVBoxLayout;
    mainCoordLayout->addWidget(coordFrame);
    mainCoordLayout->addStretch();
    QVBoxLayout *zoomLayout = new QVBoxLayout;
    zoomLayout->addWidget(zoomInLabel);
    zoomLayout->addWidget(slider);
    zoomLayout->addWidget(zoomOutLabel);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(zoomLayout);
    mainLayout->addLayout(mainCoordLayout);
    mainLayout->addStretch();
    mainLayout->setMargin(30);
    mainLayout->setSpacing(10);
    setLayout(mainLayout);
    setWindowTitle(tr("Map Widget"));
    setMinimumSize(600,400);


}

void MapWidget::readMap()
{
    QString mapName;
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,"打开","/");
    QFile mapFile(fileName);
    int ok = mapFile.open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream ts(&mapFile);
        if(!ts.atEnd())
        {
            ts>>mapName;
            ts>>x1>>y1>>x2>>y2;
        }
    }
    map.load(mapName);
}

QPointF MapWidget::maptoMap(QPointF p)
{
    QPointF latLon;
    qreal w = sceneRect().width();
    qreal h = sceneRect().height();
    qreal lon = y1 - ((h/2+p.y())*abs(y1-y2)/h);
    qreal lat = x1 -((w/2+p.x())*abs(x1-x2)/h);
    latLon.setX(lat);
    latLon.setY(lon);
    return latLon;
}

void MapWidget::slotZoom(int value)
{
    qreal s;
    if(value>zoom)
    {
        s=pow(1.01,(value-zoom));           //1.01的(value-zoom)次方
    }
    else
    {
        s = pow(1/1.01,(zoom-value));
    }
    scale(s,s);                      //横向、纵向缩放s倍，
    zoom = value;
}

void MapWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->drawPixmap(int(sceneRect().left()),int(sceneRect().top()),map);
}

void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
    //QGraphicsView坐标
    QPoint viewPoint = event->pos();
    viewCoordLabel->setText(QString::number(viewPoint.x())+","+QString::number(viewPoint.y()));
    //QGraphicsScene坐标
    QPointF scenePoint = mapToScene(viewPoint);
    sceneCoordLabel->setText(QString::number(scenePoint.x())+","+QString::number(scenePoint.y()));
    //地图坐标值（经纬度值）
    QPointF latLon = maptoMap(scenePoint);
   mapCoordLabel->setText(QString::number(latLon.x())+","+QString::number(latLon.y()));
}
















