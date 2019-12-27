#pragma once

#include <QTcpServer>
#include <QObject>
#include "tcpClientSocket.h"

class Server : public QTcpServer
{
	Q_OBJECT

public:
	Server(QObject *parent = 0, int port = 0);
	~Server();
	QList<TcpClientSocket*> tcpClientSocketLsit;

signals:
	void updateServer(QString, int);

public slots:
	void slotUpdateClients(QString, int);
	void SlotDisconnected(int);

protected:
	void incomingConnection(qintptr socketDescriptor) override;
};
