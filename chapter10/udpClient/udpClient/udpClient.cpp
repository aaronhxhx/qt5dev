#include "udpClient.h"

UdpClient::UdpClient(QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("UDP CLient"));
	//��ʼ���ؼ�
	ReceiveTectEdit = new QTextEdit(this);
	closeBtn = new QPushButton(QStringLiteral("close"), this);

	//���ò���
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(ReceiveTectEdit);
	mainLayout->addWidget(closeBtn);

	//��ʼ���������źŲ�
	port = 5555;
	udpSocket = new QUdpSocket(this);
	connect(closeBtn, &QPushButton::clicked, this, &UdpClient::slotCloseBtnClicked);
	connect(udpSocket, &QUdpSocket::readyRead, this, &UdpClient::slotDataReceived);
	//�󶨶˿�
	bool result = udpSocket->bind(port);
	if (!result)
	{
		QMessageBox::information(this, QStringLiteral("error"), QStringLiteral("udp socket create error!"));
		return;
	}
}

UdpClient::~UdpClient()
{
}

void UdpClient::slotCloseBtnClicked()
{
	close();
}

void UdpClient::slotDataReceived()
{
	//�ж�udp���Ƿ������ݱ��ɶ�
	while (udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size());

		QString msg = datagram.data();
		ReceiveTectEdit->insertPlainText(QStringLiteral("%1").arg(msg));
	}
}