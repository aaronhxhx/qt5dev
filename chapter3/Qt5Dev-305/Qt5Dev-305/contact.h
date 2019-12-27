#pragma once
#include "Macro.h"
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QCheckBox>

class Contact :public QWidget
{
	Q_OBJECT

public:
	explicit Contact(QWidget* parent = 0);

signals:

public slots:

private:
	QLabel* EmailLabel;
	QLineEdit* EmailLineEdit;
	QLabel* AddrLabel;
	QLineEdit* AddrLineEdit;
	QLabel* CodeLabel;
	QLineEdit* CodeLineEdit;
	QLabel* MoviTelLabel;
	QLineEdit* MoviTelLineEdit;
	QCheckBox* MoviTelCheckBox;
	QLabel* ProTelLabel;
	QLineEdit* ProTelLineEdit;
	QGridLayout* mainLayout;

};