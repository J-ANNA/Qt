#include "eventfilter.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMatrix>

EventFilter::EventFilter(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("事件过滤"));
    leftLabel = new QLabel;
    leftImg.load(":/pic/up.png");
    leftLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    leftLabel->setPixmap(QPixmap::fromImage(leftImg));
    midLabel = new QLabel;
    midImg.load(":/pic/up.png");
    midLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    midLabel->setPixmap(QPixmap::fromImage(midImg));
    rightLabel = new QLabel;
    rightImg.load(":/pic/up.png");
    rightLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    rightLabel->setPixmap(QPixmap::fromImage(rightImg));
    stateLabel = new QLabel(tr("鼠标按下标志"));
    stateLabel->setAlignment(Qt::AlignHCenter);
    QHBoxLayout *imgLayout = new QHBoxLayout;
    imgLayout->addWidget(leftLabel);
    imgLayout->addWidget(midLabel);
    imgLayout->addWidget(rightLabel);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(imgLayout);
    mainLayout->addWidget(stateLabel);
    leftLabel->installEventFilter(this);            //为label安装事件过滤器,指定整个窗体为监视的对象
    midLabel->installEventFilter(this);
    rightLabel->installEventFilter(this);
//    rightLabel->removeEventFilter(this);          //解除已安装的事件过滤器




}

EventFilter::~EventFilter()
{

}

bool EventFilter::eventFilter(QObject *watched, QEvent *event)       //事件监视函数
{
    if(watched==leftLabel)                                            //首先判断当前发生事件的对象
    {
        if(event->type()==QEvent::MouseButtonPress)                //判断发生的事件类型
        {
            QMouseEvent *mouseEvent = (QMouseEvent *)event;           //将event转换为鼠标事件
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                stateLabel->setText(tr("左键按下左边的图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                stateLabel->setText(tr("中键按下左边的图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                stateLabel->setText(tr("右键按下左边的图片"));
            }
            QMatrix matrix;
            matrix.scale(1.3,1.3);
            QImage tmpImg = leftImg.transformed(matrix);
            leftLabel->setPixmap(QPixmap::fromImage(tmpImg));
        }
        else if(event->type()==QEvent::MouseButtonRelease)
        {
            stateLabel->setText(tr("鼠标释放左边的图片"));
            leftLabel->setPixmap(QPixmap::fromImage(leftImg));
        }
    }
    if(watched==midLabel)                                            //首先判断当前发生事件的对象
    {
        if(event->type()==QEvent::MouseButtonPress)                //判断发生的事件类型
        {
            QMouseEvent *mouseEvent = (QMouseEvent *)event;           //将event转换为鼠标事件
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                stateLabel->setText(tr("左键按下中间的图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                stateLabel->setText(tr("中键按下中间的图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                stateLabel->setText(tr("右键按下中间的图片"));
            }
            QMatrix matrix;
            matrix.scale(1.3,1.3);
            QImage tmpImg = midImg.transformed(matrix);
            midLabel->setPixmap(QPixmap::fromImage(tmpImg));
        }
        else if(event->type()==QEvent::MouseButtonRelease)
        {
            stateLabel->setText(tr("鼠标释放中间的图片"));
            midLabel->setPixmap(QPixmap::fromImage(midImg));
        }
    }

    if(watched==rightLabel)                                            //首先判断当前发生事件的对象
    {
        if(event->type()==QEvent::MouseButtonPress)                //判断发生的事件类型
        {
            QMouseEvent *mouseEvent = (QMouseEvent *)event;           //将event转换为鼠标事件
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                stateLabel->setText(tr("左键按下右边的图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                stateLabel->setText(tr("中键按下右边的图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                stateLabel->setText(tr("右键按下右边的图片"));
            }
            QMatrix matrix;
            matrix.scale(1.3,1.3);
            QImage tmpImg = rightImg.transformed(matrix);
            rightLabel->setPixmap(QPixmap::fromImage(tmpImg));
        }
        else if(event->type()==QEvent::MouseButtonRelease)
        {
            stateLabel->setText(tr("鼠标释放右边的图片"));
            rightLabel->setPixmap(QPixmap::fromImage(rightImg));
        }
    }

    return QDialog::eventFilter(watched,event);            //将事件交给上层对话框
}












