#pragma once

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QDate>
#include <QDataStream>

class mainWindow : public QMainWindow
{
	Q_OBJECT

public:
	mainWindow(QWidget *parent = 0);
	~mainWindow();
	void fileFun();
};
