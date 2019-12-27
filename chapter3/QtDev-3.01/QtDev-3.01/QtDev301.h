#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtDev301.h"
#include <Qfont>
#include <QSplitter>
#include <QTextEdit>
#include <QTextCodec>
#include <QDockWidget>

class QtDev301 : public QMainWindow
{
	Q_OBJECT

public:
	QtDev301(QWidget *parent = Q_NULLPTR);
	~QtDev301();

	void init();

private:
	Ui::QtDev301Class ui;
};
