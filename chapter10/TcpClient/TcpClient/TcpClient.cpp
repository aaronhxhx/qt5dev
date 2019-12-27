#include "TcpClient.h"


TcpClient::TcpClient(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	//ui.setupUi(this);
	setWindowTitle(QStringLiteral("TCP Client"));
	contentListWidget = new QListWidget;
	sendLineEdit = new QLineEdit;
	sendBtn = new QPushButton(QStringLiteral("发送"));
	userNameLabel = new QLabel(QStringLiteral("用户名："));
	userNameLineEdit = new QLineEdit;
	serverIPLabel = new QLabel(QStringLiteral("服务器地址："));
	serverIPLineEdit = new QLineEdit;
	portLabel = new QLabel(QStringLiteral("端口："));
	portLineEdit = new QLineEdit;
	enterBtn = new QPushButton(QStringLiteral("进入聊天室："));
	
	//布局
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

	//初始化
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
		//完成输入合法性校验
		QString ip = serverIPLineEdit->text();
		//判断IP地址是否正确解析
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
		//chuangjianyige QTcpSocket类对象
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
	enterBtn->setText(QStringLiteral("离开"));
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
	enterBtn->setText(QStringLiteral("进入聊天室"));
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
