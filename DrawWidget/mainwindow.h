#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "drawwidget.h"
#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QSpinBox>
#include <QToolBar>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createToolBar();

    QLabel *paintNumLabel;
    int paintNum;

public slots:
    void showStyle();
    void showColor();
    void showPaintNum(int);
private:
    DrawWidget *drawWidget;
    QLabel *styleLabel;
    QComboBox *styleComboBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    QPushButton *colorBtn;
    QPushButton *clearBtn;
    QToolBar *toolBar;



};

#endif // MAINWINDOW_H
