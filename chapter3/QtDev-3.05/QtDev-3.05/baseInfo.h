#pragma once

#include <QWidget>
#include "Macro.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>


class BaseInfo : public QWidget
{
	Q_OBJECT

public:
	explicit BaseInfo(QWidget *parent = 0);
	~BaseInfo();

private:
	//◊Û≤‡
	QLabel *UserNameLabel;
	QLabel *NameLabel;
	QLabel *SexLabel;
	QLabel *DepartmentLabel;
	QLabel *AgeLabel;
	QLabel *OtherLabel;
	QLineEdit *UserNameLineEdit;
	QLineEdit *NameLineEdit;
	QComboBox *SexComboBox;
	QTextEdit *DepartmentTextEdit;
	QLineEdit *AgeLineEdit;
	QGridLayout *LeftLayout;
	//”“≤‡
	QLabel *HeadLabel;          //”“…œΩ«≤ø∑÷
	QLabel *HeadIconLabel;
	QPushButton *UpdateHeadBtn;
	QHBoxLayout *TopRightLayout;
	QLabel *IntroductionLabel;
	QTextEdit *IntroductionTextEdit;
	QVBoxLayout *RightLayout;
};
