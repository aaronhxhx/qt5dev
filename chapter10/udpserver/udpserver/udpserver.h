#pragma once

#include <QtWidgets/QWidget>
#include "ui_udpserver.h"
#include <QUdpSocket>
#include <Qtimer>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class udpserver : public QWidget
{
	Q_OBJECT

public:
	udpserver(QWidget *parent = nullptr, Qt::WindowFlags f =0);
	~udpserver();

private:
	Ui::udpserverClass ui;
	QLabel* timerLabel;
	QLineEdit* textLineEdit;
	QPushButton* StartBtn;
	QVBoxLayout* mainLayout;
};
