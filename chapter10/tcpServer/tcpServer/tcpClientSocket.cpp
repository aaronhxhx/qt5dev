#include "tcpClientSocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent)
	: QTcpSocket(parent)
{
	//readyRead()是QIODevice(所有输入输出的抽象类)的signal，由QTcpSocket继承，
	//qt中QTcpSocket被认为readyRead()再有数据到来的时候发出
	connect(this, &QTcpSocket::readyRead, this, &TcpClientSocket::slotDataReceive);
	//disconnect()signal在断开链接是发出
	connect(this, &QTcpSocket::disconnected, this, &TcpClientSocket::slotDisconnected);

}

TcpClientSocket::~TcpClientSocket()
{
}

void TcpClientSocket::slotDataReceive()
{
	while (bytesAvailable() > 0)
	{
		int length = bytesAvailable();
		char buf[1024];
		read(buf, length);
		QString msg = buf;
		emit updateClients(msg, length);
	}
}

void TcpClientSocket::slotDisconnected()
{
	emit disconnected(this->socketDescriptor());
}
