#include "tcpClientSocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent)
	: QTcpSocket(parent)
{
	//readyRead()��QIODevice(������������ĳ�����)��signal����QTcpSocket�̳У�
	//qt��QTcpSocket����ΪreadyRead()�������ݵ�����ʱ�򷢳�
	connect(this, &QTcpSocket::readyRead, this, &TcpClientSocket::slotDataReceive);
	//disconnect()signal�ڶϿ������Ƿ���
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
