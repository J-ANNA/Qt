#ifndef THREADDLOG_H
#define THREADDLOG_H

#include <QDialog>
#include <QPushButton>
#include "workthread.h"
#include <QThread>

#define MAXSIZE 5

class ThreadDlog : public QDialog
{
    Q_OBJECT

public:
    ThreadDlog(QWidget *parent = 0);
    ~ThreadDlog();
private:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *exitBtn;
    WorkThread *workThread[MAXSIZE];
private slots:
    void slotStart();
    void slotStop();


};

#endif // THREADDLOG_H
