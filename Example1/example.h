#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QFrame>
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>
#include <QListWidget>
#include <QWidget>
#include <QFrame>

class Example : public QFrame
{
    Q_OBJECT

public:
    Example(QWidget *parent = 0);
    QStackedWidget *stack;
    QPushButton *amendBtn;
    QPushButton *closeBtn;
    BaseInfo *baseInfo;
    Contact *contact;
    Detail *detail;
    QHBoxLayout *btnLayout;
    QVBoxLayout *rightLayout;
    QSplitter *splitterMain;
    QListWidget *list;
    QWidget *rightMainWidget;


    ~Example();
};

#endif // EXAMPLE_H
