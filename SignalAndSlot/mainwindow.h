#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void signalNone();
    void signalInt(int);
    void signalIntInt(int,int);
private slots:
    void slotNone();
    void slotInt(int);
    void slotIntInt(int,int);
    void slotNoneBtn();
    void slotIntBtn();
    void slotIntIntBtn();
private:
    QPushButton *noneBtn;
    QPushButton *IntBtn;
    QPushButton *IntIntBtn;
    QLineEdit *noneLineEdit;
    QLineEdit *IntLineEdit;
    QLineEdit *IntIntLineEdit;

};

#endif // MAINWINDOW_H
