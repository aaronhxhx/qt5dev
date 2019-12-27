#include "server.h"

Server::Server(QObject *parent, int port)
	: QTcpServer(parent)
{
	//����ָ���˿ں������ַ
	//QHostAddress::Any�� QHostAddress::LocalHost�� QHostAddress::LocalHostIPv6
	//QHostAddress::Broadcast�㲥��ַ
	bool res = listen(QHostAddress::Any, port);
}

Server::~Server()
{
}

void Server::incomingConnection(qintptr socketDescriptor)
{
	//����һ���µ�TcpClientScoket��ͻ���ͨ��
	TcpClientSocket* tcpClientSocket = new TcpClientSocket(this);
	//����TcpClientSocket��updateClients�ź�
	connect(tcpClientSocket, &TcpClientSocket::updateClients, this, &Server::slotUpdateClients);
	//����TcpClientSocket��disconnected�ź�
	connect(tcpClientSocket, &TcpClientSocket::disconnected, this, &Server::SlotDisconnected);
	//���½�TcpClientSocket�׽���������ָ��Ϊ����socketDescriptor
	tcpClientSocket->setSocketDescriptor(socketDescriptor);
	//��TCP ClientSocket����ͻ����׽����б��Ա����
	tcpClientSocketLsit.append(tcpClientSocket);
}

//������ͻ��˷�������Ϣ���й㲥����֤�����ҵ����пͻ����ܿ��������˵ķ���
void Server::slotUpdateClients(QString msg, int length)
{
	//����updateServer�źţ�֪ͨ������������Ӧ����ʾ״̬
	emit updateServer(msg, length);
	for (int i = 0; i < tcpClientSocketLsit.count(); i++)
	{
		QTcpSocket* item = tcpClientSocketLsit.at(i);
		if (item->write(msg.toLatin1(), length) != length)
		{
			continue;
		}
	}

}

void Server::SlotDisconnected(int descriptor)
{
	for (int i = 0; i < tcpClientSocketLsit.count(); i++)
	{
		QTcpSocket* item = tcpClientSocketLsit.at(i);
		if (item->socketDescriptor() == descriptor)
		{
			tcpClientSocketLsit.removeAt(i);
			return;
		}
	}
	return;
}

