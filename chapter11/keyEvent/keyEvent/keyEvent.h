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
	//ͼ�����϶���λ��
	int startX;
	int startY;
	//�����Ⱥ͸߶�
	int width;
	int height;
	int step;
};
