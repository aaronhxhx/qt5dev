#pragma once

#include <QtWidgets/QWidget>
#include "ui_ShapeWidget.h"
#include <QWidget>
#include <QMouseEvent>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>

class ShapeWidget : public QWidget
{
	Q_OBJECT

public:
	ShapeWidget(QWidget *parent = Q_NULLPTR);
	~ShapeWidget();

protected:
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void paintEvent(QPaintEvent *);


private:
	Ui::ShapeWidgetClass ui;
	QPoint dragPosition;
};
