#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SVGTest.h"
#include "SvgWindow.h"

class SVGTest : public QMainWindow
{
	Q_OBJECT

public:
	SVGTest(QWidget *parent = Q_NULLPTR);
	~SVGTest();
	void createMenu();

public slots:
	void slotOpenFile();

private:
	Ui::SVGTestClass ui;
	SvgWindow* svgWindow;
};
