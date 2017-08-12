#include "nerworkinformation.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHostInfo>
#include <QList>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QHostAddress>
#include <QDebug>

NerworkInformation::NerworkInformation(QWidget *parent)
    : QWidget(parent)
{
    hostLabel = new QLabel(tr("主机名："));
    hostLineEdit = new QLineEdit;
    IPLabel = new QLabel(tr("IP 地址："));
    IPLineEdit = new QLineEdit;
    IPLineEdit->setFixedSize(200,20);
    detailBtn = new QPushButton(tr("详细"));
    detailText = new QTextBrowser;
    detailText->hide();
//    detailWidget = new QWidget;
//    detailWidget->hide();
    QGridLayout *basicLayout = new QGridLayout;
    basicLayout->setSizeConstraint(QLayout::SetFixedSize);
    basicLayout->addWidget(hostLabel,0,0);
    basicLayout->addWidget(hostLineEdit,0,1);
    basicLayout->addWidget(IPLabel,1,0);
    basicLayout->addWidget(IPLineEdit,1,1);
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(detailBtn);
    QHBoxLayout *detailLayout = new QHBoxLayout;
    detailLayout->addWidget(detailText);
    QVBoxLayout *mainLaout = new QVBoxLayout(this);
    mainLaout->addLayout(basicLayout);
    mainLaout->addLayout(btnLayout);
    mainLaout->addLayout(detailLayout);
    mainLaout->setSizeConstraint(QLayout::SetFixedSize);
    setWindowTitle(tr("NetworkInformation"));


    getHostInformation();
    connect(detailBtn,SIGNAL(clicked()),this,SLOT(slotShowDetail()));

}

NerworkInformation::~NerworkInformation()
{

}

void NerworkInformation::getHostInformation()
{
    QString localHostName = QHostInfo::localHostName();    //获得主机名
    hostLineEdit->setText(localHostName);
    QHostInfo hostInfo = QHostInfo::fromName(localHostName); //根据主机名获得相关主机信息
    QList<QHostAddress> addressList = hostInfo.addresses();
    if(!addressList.isEmpty())
    {
//        IPLineEdit->setText(addressList.first().toString());
        foreach (QHostAddress HostIp, addressList)
        {
            if(HostIp.protocol() ==QAbstractSocket::IPv4Protocol
                    && HostIp !=QHostAddress(QHostAddress::LocalHost))
            {
                IPLineEdit->setText(HostIp.toString());
                return;
            }
        }
    }
}

void NerworkInformation::slotShowDetail()
{
    QString detail = "";
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach( QNetworkInterface interface,list)
    {
//        QNetworkInterface interface = list.at(i);
        detail = detail + tr("设备:") + interface.name() + "\n";
        detail = detail + tr("硬件地址：") + interface.hardwareAddress() + "\n";
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        foreach(QNetworkAddressEntry entry, entryList)              //建议遍历好，用for()出BUG
        {
            QHostAddress hostAddress = entry.ip();
            if(hostAddress.protocol() == QAbstractSocket::IPv4Protocol &&
                            hostAddress != QHostAddress(QHostAddress::LocalHost))    //选择获取IPv4
            {
                detail = detail + "\t" + tr("IP地址：") + entry.ip().toString() + "\n";
                detail = detail + "\t" + tr("子网掩码：") + entry.netmask().toString() + "\n";
                detail = detail + "\t" + tr("广播地址：") + entry.broadcast().toString() + "\n";
            }
        }

    }

    detailText->setText(detail);
    if(detailText->isHidden())
        detailText->show();
    else
        detailText->hide();
}
