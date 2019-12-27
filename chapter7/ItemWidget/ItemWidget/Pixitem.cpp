#include "Pixitem.h"

Pixitem::Pixitem(QPixmap* pixmap)
{
	pix = *pixmap;
}

Pixitem::~Pixitem()
{
}

//定义图元边界函数
QRectF Pixitem::boundingRect()const
{
	return QRectF(-2 - pix.width() / 2, -2 - pix.height() / 2, pix.width() + 4, pix.height() + 4);
}

//重绘函数
void Pixitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(-pix.width() / 2, -pix.height(), pix);
}