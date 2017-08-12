#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "server.h"

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = 0);
    ~TcpServer();

public slots:
    void slotCreateServer();
    void slotUpdateServer(QString,int);

private:
    QListWidget *contentListWidget;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *createBtn;

    int port;
    Server *server;

};

#endif // TCPSERVER_H
