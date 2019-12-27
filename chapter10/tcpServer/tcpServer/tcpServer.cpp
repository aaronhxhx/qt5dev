#include "tcpServer.h"

TcpServer::TcpServer(QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("TCP SERVER"));
	contentListWidget = new QListWidget;
	portLabel = new QLabel(QStringLiteral("�˿ڣ�"));
	portLineEdit = new QLineEdit;
	createBtn = new QPushButton(QStringLiteral("����������"));
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(contentListWidget, 0, 0, 1, 2);
	mainLayout->addWidget(portLabel, 1, 0);
	mainLayout->addWidget(portLineEdit, 1, 1);
	mainLayout->addWidget(createBtn, 2, 0, 1, 2);

	//�źŲ�����
	port = 8010;
	portLineEdit->setText(QString::number(port));
	connect(createBtn, &QPushButton::clicked, this, &TcpServer::slotCreateServer);
	init();

}

TcpServer::~TcpServer()
{
}

void TcpServer::init()
{


}

void TcpServer::slotCreateServer()
{
	//����һ��Server����
	server = new Server(this, port);
	connect(server, &Server::updateServer, this, &TcpServer::updateServer);
	createBtn->setEnabled(false);
}

void TcpServer::updateServer(QString msg, int length)
{
	contentListWidget->addItem(msg.left(length));
}