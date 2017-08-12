#include "tcpclient.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

TcpClient::TcpClient(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("TCP Client"));
    contentListWidget = new QListWidget;
    sendLineEdit = new QLineEdit;
    sendBtn = new QPushButton(tr("发送"));
    userNameLabel = new QLabel(tr("用户名："));
    userNameLineEdit = new QLineEdit;
    serverIPLabel = new QLabel(tr("服务器地址："));
    serverIPLineEdit = new QLineEdit;
    portLabel = new QLabel(tr("端口："));
    portLineEdit = new QLineEdit;
    enterBtn = new QPushButton(tr("进入聊天室"));
    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget(contentListWidget,0,0,1,2);
    topLayout->addWidget(sendLineEdit,1,0);
    topLayout->addWidget(sendBtn,1,1);
    topLayout->addWidget(userNameLabel,2,0);
    topLayout->addWidget(userNameLineEdit,2,1);
    topLayout->addWidget(serverIPLabel,3,0);
    topLayout->addWidget(serverIPLineEdit,3,1);
    topLayout->addWidget(portLabel,4,0);
    topLayout->addWidget(portLineEdit,4,1);
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch(1);
    btnLayout->addWidget(enterBtn);
    btnLayout->addStretch(1);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(btnLayout);
}

TcpClient::~TcpClient()
{

}
