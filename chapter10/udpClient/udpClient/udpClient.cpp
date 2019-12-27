#include "udpClient.h"

UdpClient::UdpClient(QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("UDP CLient"));
	//初始化控件
	ReceiveTectEdit = new QTextEdit(this);
	closeBtn = new QPushButton(QStringLiteral("close"), this);

	//设置布局
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(ReceiveTectEdit);
	mainLayout->addWidget(closeBtn);

	//初始化参数，信号槽
	port = 5555;
	udpSocket = new QUdpSocket(this);
	connect(closeBtn, &QPushButton::clicked, this, &UdpClient::slotCloseBtnClicked);
	connect(udpSocket, &QUdpSocket::readyRead, this, &UdpClient::slotDataReceived);
	//绑定端口
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
	//判断udp中是否有数据报可读
	while (udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size());

		QString msg = datagram.data();
		ReceiveTectEdit->insertPlainText(QStringLiteral("%1").arg(msg));
	}
}