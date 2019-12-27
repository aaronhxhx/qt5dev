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
	
	//��������¼�
	void mousePressEvent(QMouseEvent*) override;
	void mouseMoveEvent(QMouseEvent*) override;

public slots:
	//��ʾ��ǰʱ��
	void showTime();

private:
	//����������Ե���ʱ�Ӵ������Ͻǵ�ƫ��ֵ
	QPoint dragPosition;
	//������ʾʱ��ʱ�Ƿ���ʾ":"
	bool showColon;

};
