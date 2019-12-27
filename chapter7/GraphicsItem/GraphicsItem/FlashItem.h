#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class FlashItem : public QObject, public QGraphicsItem
{
	Q_OBJECT

public:
	explicit FlashItem(QObject *parent = nullptr);
	~FlashItem();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
	void timerEvent(QTimerEvent *event)override;

private:
	bool flash;
	QTimer* timer;

public slots:
};
