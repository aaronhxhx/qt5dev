#pragma once

#include <QtWidgets/QMainWindow>
//#include "ui_QSplashScreen.h"
#include <QTextEdit>
#include <Windows.h>


class SplashScreen : public QMainWindow
{
	Q_OBJECT

public:
	SplashScreen(QWidget *parent = Q_NULLPTR);
	~SplashScreen();

private:
	//Ui::QSplashScreenClass ui;
};
