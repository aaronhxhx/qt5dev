#pragma once

#include <QtWidgets/QWidget>
#include "ui_udpClient.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>
#include <QMessageBox>
#include <QHostAddress>

class UdpClient : public QWidget
{
	Q_OBJECT

public:
	UdpClient(QWidget *parent = nullptr, Qt::WindowFlags f = 0);
	~UdpClient();

public slots:
	void slotCloseBtnClicked();
	void slotDataReceived();
private:
	Ui::UdpClientClass ui;
	QTextEdit* ReceiveTectEdit;
	QPushButton* closeBtn;
	QVBoxLayout* mainLayout;
	QUdpSocket* udpSocket;
	int port;

};
