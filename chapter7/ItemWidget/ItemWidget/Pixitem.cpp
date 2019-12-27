#include "Pixitem.h"

Pixitem::Pixitem(QPixmap* pixmap)
{
	pix = *pixmap;
}

Pixitem::~Pixitem()
{
}

//����ͼԪ�߽纯��
QRectF Pixitem::boundingRect()const
{
	return QRectF(-2 - pix.width() / 2, -2 - pix.height() / 2, pix.width() + 4, pix.height() + 4);
}

//�ػ溯��
void Pixitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(-pix.width() / 2, -pix.height(), pix);
}