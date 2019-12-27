#pragma once

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QGridLayout>
#include "Macro.h"

class Detail : public QWidget
{
	Q_OBJECT

public:
	explicit Detail(QWidget *parent = 0);
	~Detail();

private:
	QLabel* NationalLabel;
	QComboBox* NationalComboBox;
	QLabel* ProvinceLabel;
	QComboBox* ProvinceComboBox;
	QLabel* CityLabel;
	QTextEdit* CityTextEdit;
	QLabel* IntroductLabel;
	QTextEdit* IntroductTextEdit;
	QGridLayout* mainLayout;
};
