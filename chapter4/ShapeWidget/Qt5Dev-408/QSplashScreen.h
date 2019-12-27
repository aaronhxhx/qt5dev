#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QSplashScreen.h"
#include <QTextEdit>
#include <Windows.h>

class QSplashScreen : public QMainWindow
{
	Q_OBJECT

public:
	QSplashScreen(QWidget *parent = Q_NULLPTR);

private:
	Ui::QSplashScreenClass ui;
};
