#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NameWindow.h"

class NameWindow : public QMainWindow
{
	Q_OBJECT

public:
	NameWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::NameWindowClass ui;
};
