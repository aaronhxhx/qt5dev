#pragma once

#include <QtWidgets/QMainWindow>
//#include "ui_keyEvent.h"
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>

class KeyEvent : public QMainWindow
{
	Q_OBJECT

public:
	KeyEvent(QWidget *parent = Q_NULLPTR);
	~KeyEvent();

	void drawPix();
	void keyPressEvent(QKeyEvent *event)override;
	void paintEvent(QPaintEvent *event);
private:
	//Ui::KeyEventClass ui;
	QPixmap* pix;
	QImage image;
	//图标左上定点位置
	int startX;
	int startY;
	//界面宽度和高度
	int width;
	int height;
	int step;
};
