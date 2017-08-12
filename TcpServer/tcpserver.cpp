#include "tcpserver.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

TcpServer::TcpServer(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("TCP Server"));
    contentListWidget = new QListWidget;
    portLabel = new QLabel(tr("端口:"));
    portLineEdit = new QLineEdit;
    createBtn = new QPushButton(tr("创建聊天室"));
    QVBoxLayout *contentLayout = new QVBoxLayout;
    contentLayout->addWidget(contentListWidget);
    QHBoxLayout *portLayout = new QHBoxLayout;
    portLayout->addWidget(portLabel);
    portLayout->addWidget(portLineEdit);
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch(1);
    btnLayout->addWidget(createBtn);
    btnLayout->addStretch(1);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(contentLayout);
    mainLayout->addLayout(portLayout);
    mainLayout->addLayout(btnLayout);

    port = 8010;
    portLineEdit->setText(QString::number(port));
    connect(createBtn,SIGNAL(clicked()),this,SLOT(slotCreateServer()));

}

TcpServer::~TcpServer()
{

}

void TcpServer::slotCreateServer()
{
    server = new Server(this,port);
    connect(server,SIGNAL(signalUpdateServer(QString,int)),this,SLOT(slotUpdateServer(QString,int)));
    createBtn->setEnabled(false);
}

void TcpServer::slotUpdateServer(QString msg, int length)
{
    contentListWidget->addItem(msg.left(length));      //从msg左边读取length长度字符
}
