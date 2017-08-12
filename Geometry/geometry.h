#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class Geometry : public QDialog
{
    Q_OBJECT

public:
    Geometry(QWidget *parent = 0);
    ~Geometry();
    void updateLabel();

private:
    QLabel *xLabel;
    QLabel *xValueLabel;
    QLabel *yLabel;
    QLabel *yValueLabel;
    QLabel *posLabel;
    QLabel *posValueLabel;
    QLabel *frameLabel;
    QLabel *frameValueLabel;
    QLabel *geometryLabel;
    QLabel *geometryValueLabel;
    QLabel *widthLabel;
    QLabel *widthValueLabel;
    QLabel *heightLabel;
    QLabel *heightValueLabel;
    QLabel *rectLabel;
    QLabel *rectValueLabel;
    QLabel *sizeLabel;
    QLabel *sizeValueLabel;
    QPushButton *resizeBtn;

    QGridLayout *mainLayout;

protected:
    void moveEvent(QMoveEvent *);
    void resizeEvent(QResizeEvent *);
private slots:
    void resizeWidget();


};

#endif // GEOMETRY_H
