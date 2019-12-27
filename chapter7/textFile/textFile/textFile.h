#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_textFile.h"

class textFile : public QMainWindow
{
	Q_OBJECT

public:
	textFile(QWidget *parent = Q_NULLPTR);

private:
	Ui::textFileClass ui;
};
