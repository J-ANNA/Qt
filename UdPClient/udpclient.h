#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include <QUdpSocket>
#include <QTextEdit>
#include <QPushButton>

class UdpClient : public QDialog
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = 0);
    ~UdpClient();
public slots:
    void slotCloseBtn();
    void slotDataReceived();
private:
    QTextEdit *receivedTextEdit;
    QPushButton *closeBtn;

    int port;
    QUdpSocket *udpSocket;
};

#endif // UDPCLIENT_H
