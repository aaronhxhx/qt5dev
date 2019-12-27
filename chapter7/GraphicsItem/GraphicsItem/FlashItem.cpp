#include "FlashItem.h"
const qreal adjust = 2;

FlashItem::FlashItem(QObject *parent)
	: QObject(parent)
{
	flash = true;
	setFlag(ItemIsMovable);
	startTimer(1000);
}

FlashItem::~FlashItem()
{
}

QRectF FlashItem::boundingRect()const
{
	//qreal adjust = 2;
	return QRectF(-10 - adjust, -10 - adjust, 43 + adjust, 43 + adjust);
}

void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//闪烁区域部绘制
	painter->setPen(Qt::NoPen);
	//闪烁区域阴影米三年级为深灰色
	painter->setBrush(Qt::darkGray);
	//绘制阴影区
	painter->drawEllipse(-7, -7, 40, 40);
	//闪烁区的椭圆边线颜色为黑色、线宽为0
	painter->setPen(QPen(Qt::black, 0));
	//设置闪烁区，根据设置flash
	painter->setBrush(flash ? (Qt::red) : (Qt::yellow));
	painter->drawEllipse(-10, -10, 40, 40);
}

void FlashItem::timerEvent(QTimerEvent *event)
{
	flash = !flash;
	update();
}
