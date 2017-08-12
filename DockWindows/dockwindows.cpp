#include "dockwindows.h"
#include "qtextedit.h"
#include "qdockwidget.h"

DockWindows::DockWindows(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("DockWindows");
    QTextEdit *text = new QTextEdit(this);
    text->setText("MainWindow");
    text->setAlignment(Qt::AlignCenter);
    setCentralWidget(text);
    //停靠窗口1
    QDockWidget *dock = new QDockWidget(tr("DockWindows1"),this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    //停靠窗口2
    dock = new QDockWidget(tr("DockWindows2"),this);
    dock->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    //停靠窗口3
    dock = new QDockWidget(tr("DockWindows3"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    addDockWidget(Qt::RightDockWidgetArea,dock);



}


DockWindows::~DockWindows()
{

}
