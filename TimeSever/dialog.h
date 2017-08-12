#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "timeserver.h"
#include "timethread.h"

class TimeServer;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QLabel *monitorPortLabel;
    QLabel *requestNumlabel;
    QPushButton *quitBtn;
    TimeServer *timeServer;
    int count;
public slots:
    void slotShow();
};

#endif // DIALOG_H
