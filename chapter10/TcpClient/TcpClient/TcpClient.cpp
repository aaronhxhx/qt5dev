#include "TcpClient.h"


TcpClient::TcpClient(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	//ui.setupUi(this);
	setWindowTitle(QStringLiteral("TCP Client"));
	contentListWidget = new QListWidget;
	sendLineEdit = new QLineEdit;
	sendBtn = new QPushButton(QStringLiteral("����"));
	userNameLabel = new QLabel(QStringLiteral("�û�����"));
	userNameLineEdit = new QLineEdit;
	serverIPLabel = new QLabel(QStringLiteral("��������ַ��"));
	serverIPLineEdit = new QLineEdit;
	portLabel = new QLabel(QStringLiteral("�˿ڣ�"));
	portLineEdit = new QLineEdit;
	enterBtn = new QPushButton(QStringLiteral("���������ң�"));
	
	//����
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(contentListWidget, 0, 0, 1, 2);
	mainLayout->addWidget(sendLineEdit, 1, 0);
	mainLayout->addWidget(sendBtn, 1, 1);
	mainLayout->addWidget(userNameLabel, 2,0);
	mainLayout->addWidget(userNameLineEdit, 2, 1);
	mainLayout->addWidget(serverIPLabel, 3, 0);
	mainLayout->addWidget(serverIPLineEdit, 3, 1);
	mainLayout->addWidget(portLabel, 4, 0);
	mainLayout->addWidget(portLineEdit, 4, 1);
	mainLayout->addWidget(enterBtn, 5, 0, 1, 2);

	//��ʼ��
	status = false;
	port = 8010;
	portLineEdit->setText(QString::number(port));
	serverIP = new QHostAddress();
	connect(enterBtn, &QPushButton::clicked, this, &TcpClient::slotEnter);
	connect(sendBtn, &QPushButton::clicked, this, &TcpClient::slotSend);
	sendBtn->setEnabled(false);
}

TcpClient::~TcpClient()
{
}
void TcpClient::slotEnter()
{
	if (!status)
	{
		//�������Ϸ���У��
		QString ip = serverIPLineEdit->text();
		//�ж�IP��ַ�Ƿ���ȷ����
		if (!serverIP->setAddress(ip))
		{
			QMessageBox::information(this, QStringLiteral("error"), QStringLiteral("server ip address error"));
			return;
		}
		if (userNameLineEdit->text() == "")
		{
			QMessageBox::information(this, QStringLiteral("error"), QStringLiteral("user name is not NULL"));
			return;
		}
		userName = userNameLineEdit->text();
		//chuangjianyige QTcpSocket�����
		tcpSocket = new QTcpSocket(this);
		connect(tcpSocket, &QTcpSocket::connected, this, &TcpClient::slotConnected);
		connect(tcpSocket, &QTcpSocket::disconnected, this, &TcpClient::slotDisconnected);
		connect(tcpSocket, &QTcpSocket::readyRead, this, &TcpClient::slotDataReceive);
		tcpSocket->connectToHost(*serverIP, port);
		status = true;
	}
	else
	{
		int length = 0;
		QString msg = userName + QStringLiteral(":Leave Chat room");
		if ((length = tcpSocket->write(msg.toLatin1(), msg.length())) != msg.length())
		{
			return;
		}
		tcpSocket->disconnectFromHost();
		status = false;
	}
}

void TcpClient::slotConnected()
{
	sendBtn->setEnabled(true);
	enterBtn->setText(QStringLiteral("�뿪"));
	int length = 0;
	QString msg = userName + QStringLiteral(":Enter Chat room");
	if ((length = tcpSocket->write(msg.toLatin1(), msg.length())) != msg.length())
	{
		return;
	}
}

void TcpClient::slotDisconnected()
{
	sendBtn->setEnabled(false);
	enterBtn->setText(QStringLiteral("����������"));
}

void TcpClient::slotDataReceive()
{
	while (tcpSocket->bytesAvailable() > 0)
	{
		QByteArray datagram;
		datagram.resize(tcpSocket->bytesAvailable());
		tcpSocket->read(datagram.data(), datagram.size());
		QString msg = datagram.data();
		contentListWidget->addItem(msg.left(datagram.size()));
	}
}

void TcpClient::slotSend()
{
	if (sendLineEdit->text() == "")
	{
		return;
	}
	QString msg = userName + ":" + sendLineEdit->text();
	tcpSocket->write(msg.toLatin1(), msg.length());
	sendLineEdit->clear();
}
