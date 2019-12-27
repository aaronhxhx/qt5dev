#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyQQExample.h"

class MyQQExample : public QWidget
{
	Q_OBJECT

public:
	MyQQExample(QWidget *parent = Q_NULLPTR);

private:
	Ui::MyQQExampleClass ui;
};
