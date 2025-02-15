#pragma once

#include "macro.h"
#include <QObject>
#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>

class Driver : public QToolBox
{
	Q_OBJECT

public:
	Driver(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~Driver();

private:
	QToolButton *toolBtn1_1;
	QToolButton *toolBtn1_2;
	QToolButton *toolBtn1_3;
	QToolButton *toolBtn1_4;
	QToolButton *toolBtn1_5;
	QToolButton *toolBtn2_1;
	QToolButton *toolBtn2_2;
	QToolButton *toolBtn3_1;
	QToolButton *toolBtn3_2;

};
