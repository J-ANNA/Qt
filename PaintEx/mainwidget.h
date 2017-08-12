#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QGridLayout>
#include <QGradient>
#include <QFrame>
#include "paintarea.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
private:
    PaintArea *paintArea;
    QLabel *shapeLabel;
    QComboBox *shapeComboBox;
    QLabel *penColorLabel;
    QFrame *penColorFrame;
    QPushButton *penColorBtn;
    QLabel *penWidthLabel;
    QSpinBox *penWidthSpinBox;
    QLabel *penStyleLabel;
    QComboBox *penStyleComboBox;
    QLabel *penCapLabel;
    QComboBox *penCapComboBox;
    QLabel *penJoinLabel;
    QComboBox *penJoinComboBox;
    QLabel *fillRuleLabel;
    QComboBox *fillRuleComboBox;
    QLabel *spreadLabel;
    QComboBox *spreadComboBox;
    QGradient::Spread spread;
    QLabel *brushColorLabel;
    QFrame *brushColorFrame;
    QPushButton *brushColorBtn;
    QLabel *brushStyleLabel;
    QComboBox *brushStyleComboBox;
    QGridLayout *rightLayout;

private slots:
    void showShape(int);
    void showPenColor();
    void showPenWidth(int);
    void showPenStyle(int);
    void showPenCap(int);
    void showPenJoin(int);
    void showFillRule();
    void showSpreadStyle();
    void showBrushColor();
    void showBrushStyle(int);



};

#endif // MAINWIDGET_H
