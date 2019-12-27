#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt5Dev302.h"
#include <QDockWidget>
#include <QTextEdit>


class Qt5Dev302 : public QMainWindow
{
	Q_OBJECT

public:
	Qt5Dev302(QWidget *parent = Q_NULLPTR);
	~Qt5Dev302();
private:
	Ui::Qt5Dev302Class ui;
};
