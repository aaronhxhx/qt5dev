#pragma once

#include <QtWidgets/QWidget>
#include "ui_NetworkInfo.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QHostInfo>
#include <QNetworkInterface>

class NetworkInfo : public QWidget
{
	Q_OBJECT

public:
	NetworkInfo(QWidget *parent = Q_NULLPTR);
	~NetworkInfo();
	void getHostInformation();

public slots:
	void slotDetail();

private:
	Ui::NetworkInfoClass ui;
	QLabel* hostLabel;
	QLineEdit* hostLineEdit;
	QLabel* IPLabel;
	QLineEdit* IPLineEdit;
	QPushButton* detailBtn;
	QGridLayout* mainLayout;

};
