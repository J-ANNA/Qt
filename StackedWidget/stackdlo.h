#ifndef STACKDLO_H
#define STACKDLO_H

#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QMainWindow>

class StackDlo : public QDialog
{
    Q_OBJECT

public:
    StackDlo(QWidget *parent = 0);
    ~StackDlo();
private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

};

#endif // STACKDLO_H
