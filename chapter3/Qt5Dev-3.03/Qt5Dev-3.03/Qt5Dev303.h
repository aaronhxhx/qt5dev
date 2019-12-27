#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt5Dev303.h"
#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>


class Qt5Dev303 : public QMainWindow
{
	Q_OBJECT

public:
	Qt5Dev303(QWidget *parent = Q_NULLPTR);
	~Qt5Dev303();

private:
	QListWidget* list;
	QStackedWidget* stack;
	QLabel* label1;
	QLabel* label2;
	QLabel* label3;

private:
	Ui::Qt5Dev303Class ui;
};
