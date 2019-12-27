#pragma once

#include <QtWidgets/QMainWindow>
//#include "ui_TcpClient.h"
#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>
#include <QHostInfo>

class TcpClient : public QDialog
{
	Q_OBJECT

public:
	TcpClient(QWidget *parent = nullptr, Qt::WindowFlags f =0);
	~TcpClient();

private:
	//Ui::TcpClientClass ui;
	QListWidget* contentListWidget;
	QLineEdit* sendLineEdit;
	QPushButton* sendBtn;
	QLabel* userNameLabel;
	QLineEdit* userNameLineEdit;
	QLabel* serverIPLabel;
	QLineEdit* serverIPLineEdit;
	QLabel* portLabel;
	QLineEdit* portLineEdit;
	QPushButton* enterBtn;
	QGridLayout* mainLayout;
	bool status;
	int port;
	QHostAddress* serverIP;
	QString userName;
	QTcpSocket* tcpSocket;

public slots:
	void slotEnter();
	void slotConnected();
	void slotDisconnected();
	void slotDataReceive();
	void slotSend();
};
