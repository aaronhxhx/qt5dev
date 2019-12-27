#include "DigiClock.h"
#include <QDebug>

//构造函数
DigiClock::DigiClock(QWidget *parent)
	: QLCDNumber(parent)
{
	/*设置始终背景*/
	//完成窗体背景设置
	QPalette p = palette();
	p.setColor(QPalette::Window, Qt::blue);
	setPalette(p);

	//设置窗体标识，此处设置为窗体为一个没有面板框和标题栏的窗体
	setWindowFlags(Qt::FramelessWindowHint);
	//透明度显示，此函数在X11系统中不起作用，在windows下编译运行才起作用
	setWindowOpacity(0.5);

	//新建一个定时器对象
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &DigiClock::showTime);

	//以1000毫秒为周期启动定时器
	timer->start(1000);
	//初始时间显示
	showTime();
	//初始电子时钟显示的尺寸
	resize(150, 60);
	//初始化showColon
	showColon = true;

}

DigiClock::~DigiClock()
{

}

//显示时间槽函数
void DigiClock::showTime()
{
	//获取当前系统时间，保存在一个QTime对象当中
	QTime time = QTime::currentTime();
	//获取当前时间转换为字符串类型
	QString text = time.toString("hh:mm");
	//控制电子时钟时分之间":"闪显功能
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
	//显示转换好的字符串时间
	display(text);
}

//定义鼠标按压事件重定义
void DigiClock::mousePressEvent(QMouseEvent* event)
{
	//判断按压鼠标键是否为左键，保存当前位置与原位置的偏移值
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

//重定义鼠标移动事件
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



