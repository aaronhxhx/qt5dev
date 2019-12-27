#include "DigiClock.h"
#include <QDebug>

//���캯��
DigiClock::DigiClock(QWidget *parent)
	: QLCDNumber(parent)
{
	/*����ʼ�ձ���*/
	//��ɴ��屳������
	QPalette p = palette();
	p.setColor(QPalette::Window, Qt::blue);
	setPalette(p);

	//���ô����ʶ���˴�����Ϊ����Ϊһ��û������ͱ������Ĵ���
	setWindowFlags(Qt::FramelessWindowHint);
	//͸������ʾ���˺�����X11ϵͳ�в������ã���windows�±������в�������
	setWindowOpacity(0.5);

	//�½�һ����ʱ������
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &DigiClock::showTime);

	//��1000����Ϊ����������ʱ��
	timer->start(1000);
	//��ʼʱ����ʾ
	showTime();
	//��ʼ����ʱ����ʾ�ĳߴ�
	resize(150, 60);
	//��ʼ��showColon
	showColon = true;

}

DigiClock::~DigiClock()
{

}

//��ʾʱ��ۺ���
void DigiClock::showTime()
{
	//��ȡ��ǰϵͳʱ�䣬������һ��QTime������
	QTime time = QTime::currentTime();
	//��ȡ��ǰʱ��ת��Ϊ�ַ�������
	QString text = time.toString("hh:mm");
	//���Ƶ���ʱ��ʱ��֮��":"���Թ���
	if (showColon)
	{
		text[2] = ':';
		showColon = false;
	}
	else
	{
		text[2] = ' ';
		showColon = true;
	}
	//��ʾת���õ��ַ���ʱ��
	display(text);
}

//������갴ѹ�¼��ض���
void DigiClock::mousePressEvent(QMouseEvent* event)
{
	//�жϰ�ѹ�����Ƿ�Ϊ��������浱ǰλ����ԭλ�õ�ƫ��ֵ
	if (event->button() == Qt::LeftButton)
	{
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
		qDebug() << "mouse press !";
	}
	if (event->button() == Qt::RightButton)
	{
		close();
	}

}

//�ض�������ƶ��¼�
void DigiClock::mouseMoveEvent(QMouseEvent* event)
{
	//Qt::Left
	if (event->buttons() & Qt::LeftButton)
	{
		move(event->globalPos() - dragPosition);
		event->accept();
		qDebug() << "move mouse! ";
	}
}



