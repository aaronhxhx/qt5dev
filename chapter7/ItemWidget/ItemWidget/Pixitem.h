#pragma once

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class Pixitem : public QGraphicsItem
{

public:
	Pixitem(QPixmap* pixmap);
	~Pixitem();
	QRectF boundingRect()const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)override;

private:
	QPixmap pix;
};
