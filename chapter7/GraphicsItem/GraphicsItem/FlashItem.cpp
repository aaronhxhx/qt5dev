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
	//��˸���򲿻���
	painter->setPen(Qt::NoPen);
	//��˸������Ӱ�����꼶Ϊ���ɫ
	painter->setBrush(Qt::darkGray);
	//������Ӱ��
	painter->drawEllipse(-7, -7, 40, 40);
	//��˸������Բ������ɫΪ��ɫ���߿�Ϊ0
	painter->setPen(QPen(Qt::black, 0));
	//������˸������������flash
	painter->setBrush(flash ? (Qt::red) : (Qt::yellow));
	painter->drawEllipse(-10, -10, 40, 40);
}

void FlashItem::timerEvent(QTimerEvent *event)
{
	flash = !flash;
	update();
}
