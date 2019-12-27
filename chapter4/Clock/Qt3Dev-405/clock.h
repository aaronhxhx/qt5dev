#pragma once

#include <QtWidgets/QWidget>
#include "ui_clock.h"

class Clock : public QWidget
{
	Q_OBJECT

public:
	Clock(QWidget *parent = Q_NULLPTR);

private:
	Ui::ClockClass ui;
};
