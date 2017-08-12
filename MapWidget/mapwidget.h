#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QGraphicsView>
#include <QPixmap>
#include <QLabel>

class MapWidget : public QGraphicsView
{
    Q_OBJECT
public:
    MapWidget();
    void readMap();                    //读取地图信息
    QPointF maptoMap(QPointF);         //用于实现场景坐标系与地图坐标之间的映射，以获得某点的经纬度值

public slots:
    void slotZoom(int);
protected:
    void drawBackground(QPainter *painter,const QRectF &rect);
    void mouseMoveEvent(QMouseEvent *);
private:
    QPixmap map;
    qreal zoom;
    QLabel *viewCoordLabel;
    QLabel *sceneCoordLabel;
    QLabel *mapCoordLabel;
    double x1,y1;
    double x2,y2;


};

#endif // MAPWIDGET_H
