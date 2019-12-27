#include "Butterfly.h"
#include <math.h>
const double PI = 3.1415926;

Butterfly::Butterfly(QObject *parent)
	: QObject(parent)
{
	up = true;
	pix_up.load(":/Resources/up.png");
	pix_down.load(":/Resources/down.png");
	startTimer(10);	//启动定时器，为100毫秒
}

Butterfly::~Butterfly()
{

}

QRectF Butterfly::boundingRect()const
{
	qreal adjust = 2;
	return QRectF(-pix_up.width() / 2 - adjust, -pix_up.height() - adjust,
		pix_up.width() + adjust * 2, pix_up.height() + adjust * 2);
}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	if (up)
	{
		painter->drawPixmap(boundingRect().topLeft(), pix_up);
		up = !up;
	}
	else
	{
		painter->drawPixmap(boundingRect().topLeft(), pix_down);
		up = !up;
	}
}

void Butterfly::timeEvent(QTimerEvent*)
{
	//边界控制
	//右边界
	qreal edgeRight = scene()->sceneRect().right() + boundingRect().width() / 2;
	//左边界
	qreal edgeTop = scene()->sceneRect().top() + boundingRect().height() / 2;
	//下边界
	qreal edgeDown = scene()->sceneRect().bottom() + boundingRect().height() / 2;
	//越过右边界,回到左边界
	if (pos().x() >= edgeRight)
	{
		setPos(scene()->sceneRect().left(), pos().y());
	}
	//
	if (pos().y() >= edgeTop)
	{
		setPos(pos().x(), scene()->sceneRect().bottom());
	}
	if (pos().y() <= edgeDown)
	{
		setPos(pos().x(), scene()->sceneRect().top());
	}
	//angle += (qrand() % 10) / 20.0;
	//qreal dx = fabs(sin(angle*PI)*10.0);
	//qreal dy = (qrand() % 20) - 10.0;
	////坐标系映射转换，
	//setPos(mapToParent(dx, dy));
	angle += (qrand() % 10) / 20.0;
	qreal dx = fabs(sin(angle*PI)*10.0);
	qreal dy = (qrand() % 20) - 10.0;
	setPos(mapToParent(dx, dy));
}
