#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mouseEvent.h"
#include <QLabel>
#include <QStatusBar>
#include <QMouseEvent>

class MouseEvent : public QMainWindow
{
	Q_OBJECT

public:
	MouseEvent(QWidget *parent = Q_NULLPTR);
	~MouseEvent();

protected:
	void mouseMoveEvent(QMouseEvent *event)override;
	void mousePressEvent(QMouseEvent *event)override;
	void mouseReleaseEvent(QMouseEvent *event)override;
	void mouseDoubleClickEvent(QMouseEvent *event)override;

private:
	Ui::MouseEventClass ui;
	QLabel* statusLabel;
	QLabel* mousePosLabel;
};
