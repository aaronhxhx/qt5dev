#pragma once

#include <QtWidgets/QWidget>
#include "ui_Geometry.h"
#include <QLabel>
#include <QGridLayout>


class Geometry : public QWidget
{
	Q_OBJECT

public:
	Geometry(QWidget *parent = Q_NULLPTR);
	~Geometry();
	void updateLabel();

private:
	QLabel *xLabel;
	QLabel *xValueLabel;
	QLabel *yLabel;
	QLabel *yValueLabel;
	QLabel *FrmLabel;
	QLabel *FrmValueLabel;
	QLabel *posLabel;
	QLabel *posValueLabel;
	QLabel *geoLabel;
	QLabel *geoValueLabel;
	QLabel *widthLabel;
	QLabel *widthValueLabel;
	QLabel *heightLabel;
	QLabel *heightValueLabel;
	QLabel *rectLabel;
	QLabel *rectValueLabel;
	QLabel *sizeLabel;
	QLabel *sizeValueLabel;
	QGridLayout *mainLayout;

protected:
	void moveEvent(QMoveEvent *event)override;
	void resizeEvent(QResizeEvent *event)override;
private:
	Ui::GeometryClass ui;
};
