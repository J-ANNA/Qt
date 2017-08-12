#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTcpSocket>
#include <QHostAddress>

class TcpClient : public QDialog
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = 0);
    ~TcpClient();
private:
    QListWidget *contentListWidget;
    QLineEdit *sendLineEdit;
    QPushButton *sendBtn;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QLabel *serverIPLabel;
    QLineEdit *serverIPLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *enterBtn;
};

#endif // TCPCLIENT_H
