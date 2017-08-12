#ifndef DRAWER_H
#define DRAWER_H

#include <QDialog>
#include <qq.h>

class Drawer : public QDialog
{
    Q_OBJECT

public:
    Drawer(QWidget *parent = 0);
    ~Drawer();

private:
    QQ *myQQ;
};

#endif // DRAWER_H
