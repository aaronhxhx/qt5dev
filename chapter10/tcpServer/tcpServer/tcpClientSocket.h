#pragma once

#include <QTcpSocket>
#include <QObject>

class TcpClientSocket : public QTcpSocket
{
	Q_OBJECT

public:
	TcpClientSocket(QObject *parent = 0);
	~TcpClientSocket();

signals:
	void updateClients(QString, int);
	void disconnected(int);

public slots:
	void slotDataReceive();
	void slotDisconnected();
};
