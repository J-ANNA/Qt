#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include <QFileDialog>

class MyFile : public QFileDialog
{
    Q_OBJECT
public:
    MyFile(QWidget *parent = 0);
    ~MyFile();
    void resize(int,int);

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QPushButton *btn;
private slots:
    void slotBtn();
};

#endif // MAINWINDOW_H
