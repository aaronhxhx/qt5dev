#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class Butterfly : public QObject, public QGraphicsItem
{
	Q_OBJECT

public:
	explicit Butterfly(QObject *parent = nullptr);
	~Butterfly();
	//定时器实现对QGraphicItem进行重绘
	void timeEvent(QTimerEvent*);
	//为图源限定区域范围，所有继承QGraphicsItem的自定义图元都必须实现此函数
	QRectF boundingRect()const;

signals:
public slots:

protected:
	//重回函数
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)override;
private:
	bool up;			//用于标识蝴蝶翅膀的位置
	QPixmap pix_up;		//标识两幅蝴蝶图片
	QPixmap pix_down;
	qreal angle;
};
