#pragma once

#include <QtWidgets/QWidget>
#include "ui_tcpServer.h"
#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QTcpSocket>
#include "server.h"

class TcpServer : public QWidget
{
	Q_OBJECT

public:
	TcpServer(QWidget *parent = nullptr, Qt::WindowFlags f = 0);
	~TcpServer();
	void init();

private:
	QListWidget* contentListWidget;
	QLabel* portLabel;
	QLineEdit* portLineEdit;
	QPushButton* createBtn;
	QGridLayout* mainLayout;
	int port;
	Server* server;

public slots:
	void slotCreateServer();
	void updateServer(QString, int);

private:
	Ui::TcpServerClass ui;
};
