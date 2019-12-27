#pragma once

#include "Macro.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>


class BaseInfo2 : public QWidget
{
	Q_OBJECT
public:
	explicit BaseInfo2(QWidget *parent = 0);
	~BaseInfo2();
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
