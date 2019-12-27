#include "server.h"

Server::Server(QObject *parent, int port)
	: QTcpServer(parent)
{
	//监听指定端口号任意地址
	//QHostAddress::Any， QHostAddress::LocalHost， QHostAddress::LocalHostIPv6
	//QHostAddress::Broadcast广播地址
	bool res = listen(QHostAddress::Any, port);
}

Server::~Server()
{
}

void Server::incomingConnection(qintptr socketDescriptor)
{
	//创建一个新的TcpClientScoket与客户端通信
	TcpClientSocket* tcpClientSocket = new TcpClientSocket(this);
	//连接TcpClientSocket的updateClients信号
	connect(tcpClientSocket, &TcpClientSocket::updateClients, this, &Server::slotUpdateClients);
	//连接TcpClientSocket的disconnected信号
	connect(tcpClientSocket, &TcpClientSocket::disconnected, this, &Server::SlotDisconnected);
	//将新建TcpClientSocket套接字描述符指定为参数socketDescriptor
	tcpClientSocket->setSocketDescriptor(socketDescriptor);
	//将TCP ClientSocket加入客户端套接字列表以便管理
	tcpClientSocketLsit.append(tcpClientSocket);
}

//将任意客户端发来的信息进行广播，保证聊天室的所有客户均能看到其他人的发言
void Server::slotUpdateClients(QString msg, int length)
{
	//发出updateServer信号，通知服务器跟新相应的显示状态
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

