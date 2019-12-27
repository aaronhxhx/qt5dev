#include "NetworkInfo.h"

NetworkInfo::NetworkInfo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	hostLabel = new QLabel(QStringLiteral("��������"));
	hostLineEdit = new QLineEdit;
	IPLabel = new QLabel(QStringLiteral("IP ��ַ��"));
	IPLineEdit = new QLineEdit;
	detailBtn = new QPushButton(QStringLiteral("��ϸ"));
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
	//���������
	QString LocalHostName = QHostInfo::localHostName();
	hostLineEdit->setText(LocalHostName);
	//����������������������Ϣ
	QHostInfo hostInfo = QHostInfo::fromName(LocalHostName);
	//�������IP��ַ�б�
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
		detail = detail + QStringLiteral("�豸") + interface.name() + '\n';
		detail = detail + QStringLiteral("Ӳ����ַ") + interface.hardwareAddress() + '\n';
		QList<QNetworkAddressEntry> entryList = interface.addressEntries();
		for (int j = 0; j < entryList.count(); j++)
		{
			QNetworkAddressEntry entry = entryList.at(j);
			detail = detail + '\t' + QStringLiteral("ip ��ַ��") + entry.ip().toString() + '\n';
			detail += '\t' + QStringLiteral("�������룺") + entry.ip().toString() + '\n';
			detail += '\t' + QStringLiteral("�㲥��ַ��") + entry.ip().toString() + '\n';
		}
	}
	QMessageBox::information(this, tr("Detail"), detail);
}