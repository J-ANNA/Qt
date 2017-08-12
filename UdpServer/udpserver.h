#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QUdpSocket>
#include <QTimer>

class UdpServer : public QDialog
{
    Q_OBJECT

public:
    UdpServer(QWidget *parent = 0);
    ~UdpServer();
public slots:
    void slotStartBtn();
    void slotTimeout();
private:
    QLabel *timeLabel;
    QLineEdit *textLineEdit;
    QPushButton *startBtn;

    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;


};

#endif // UDPSERVER_H
