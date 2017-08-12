#include "drawer.h"

Drawer::Drawer(QWidget *parent)
    : QDialog(parent)
{
    myQQ = new QQ(this);
}

Drawer::~Drawer()
{

}
