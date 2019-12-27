#include "NetworkInfo.h"

NetworkInfo::NetworkInfo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	hostLabel = new QLabel(QStringLiteral("主机名："));
	hostLineEdit = new QLineEdit;
	IPLabel = new QLabel(QStringLiteral("IP 地址："));
	IPLineEdit = new QLineEdit;
	detailBtn = new QPushButton(QStringLiteral("详细"));
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(hostLabel, 0, 0);
	mainLayout->addWidget(hostLineEdit, 0, 1);
	mainLayout->addWidget(IPLabel, 1, 0);
	mainLayout->addWidget(IPLineEdit, 1, 1);
	mainLayout->addWidget(detailBtn, 2, 0, 1, 2);

	getHostInformation();
	connect(detailBtn, &QPushButton::clicked, this, &NetworkInfo::slotDetail);

}

NetworkInfo::~NetworkInfo()
{

}

void NetworkInfo::getHostInformation()
{
	//获得主机名
	QString LocalHostName = QHostInfo::localHostName();
	hostLineEdit->setText(LocalHostName);
	//根据主机名获得相关主机信息
	QHostInfo hostInfo = QHostInfo::fromName(LocalHostName);
	//获得主机IP地址列表
	QList<QHostAddress>listAddress = hostInfo.addresses();
	if (!listAddress.isEmpty())
	{
		IPLineEdit->setText(listAddress.at(1).toString());
	}
}

void NetworkInfo::slotDetail()
{
	QString detail = "";
	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
	for (int i = 0; i < list.count(); i++)
	{
		QNetworkInterface interface = list.at(i);
		detail = detail + QStringLiteral("设备") + interface.name() + '\n';
		detail = detail + QStringLiteral("硬件地址") + interface.hardwareAddress() + '\n';
		QList<QNetworkAddressEntry> entryList = interface.addressEntries();
		for (int j = 0; j < entryList.count(); j++)
		{
			QNetworkAddressEntry entry = entryList.at(j);
			detail = detail + '\t' + QStringLiteral("ip 地址：") + entry.ip().toString() + '\n';
			detail += '\t' + QStringLiteral("子网掩码：") + entry.ip().toString() + '\n';
			detail += '\t' + QStringLiteral("广播地址：") + entry.ip().toString() + '\n';
		}
	}
	QMessageBox::information(this, tr("Detail"), detail);
}