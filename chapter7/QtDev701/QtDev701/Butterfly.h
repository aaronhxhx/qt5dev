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
	//��ʱ��ʵ�ֶ�QGraphicItem�����ػ�
	void timeEvent(QTimerEvent*);
	//ΪͼԴ�޶�����Χ�����м̳�QGraphicsItem���Զ���ͼԪ������ʵ�ִ˺���
	QRectF boundingRect()const;

signals:
public slots:

protected:
	//�ػغ���
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)override;
private:
	bool up;			//���ڱ�ʶ��������λ��
	QPixmap pix_up;		//��ʶ��������ͼƬ
	QPixmap pix_down;
	qreal angle;
};
