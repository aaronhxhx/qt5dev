#pragma once

#include <QGraphicsItem>
#include <QPainter>

class StartItem : public QGraphicsItem
{
	//Q_OBJECT

public:
	StartItem();
	~StartItem();
	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)override;

private:
	QPixmap pix;
};
