#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QDialog>
#include <QLabel>
#include <QImage>
#include <QEvent>

class EventFilter : public QDialog
{
    Q_OBJECT

public:
    EventFilter(QWidget *parent = 0);
    ~EventFilter();
public slots:
    bool eventFilter(QObject *, QEvent *);            //QObject的事件监视函数
private:
    QLabel *leftLabel;
    QLabel *midLabel;
    QLabel *rightLabel;
    QLabel *stateLabel;
    QImage leftImg;
    QImage midImg;
    QImage rightImg;

};

#endif // EVENTFILTER_H
