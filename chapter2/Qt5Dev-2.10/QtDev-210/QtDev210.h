#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtDev210.h"
#include <QRegExp>
#include <QRegExpValidator>

class QtDev210 : public QMainWindow
{
	Q_OBJECT

public:
	QtDev210(QWidget *parent = Q_NULLPTR);
	~QtDev210();

private slots:
	void on_lineEdit_textChanged();

private:
	Ui::QtDev210Class ui;
};
