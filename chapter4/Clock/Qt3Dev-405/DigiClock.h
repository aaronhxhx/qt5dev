#pragma once

#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>


class DigiClock : public QLCDNumber
{
	Q_OBJECT

public:
	DigiClock(QWidget *parent  = nullptr);
	~DigiClock();
	
	//重载鼠标事件
	void mousePressEvent(QMouseEvent*) override;
	void mouseMoveEvent(QMouseEvent*) override;

public slots:
	//显示当前时间
	void showTime();

private:
	//保存鼠标点相对电子时钟窗体左上角的偏移值
	QPoint dragPosition;
	//用于显示时间时是否显示":"
	bool showColon;

};
