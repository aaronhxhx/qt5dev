#include "DrawWidget.h"

DrawWidget::DrawWidget(QWidget *parent)
	: QWidget(parent)
{
	//���ô���ı���ɫ
	setAutoFillBackground(true);
	setPalette(QPalette(Qt::darkBlue));
	pix = new QPixmap(size());
	pix->fill(Qt::darkBlue);
	setMinimumSize(600, 400);
}

DrawWidget::~DrawWidget()
{
}

void DrawWidget::mousePressEvent(QMouseEvent * event)
{
	startPos = event->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent * event)
{
	QPainter* painter = new QPainter;
	QPen pen;
	//��ǰѡ����������������ݵĵڼ���Ԫ��
	pen.setStyle((Qt::PenStyle)style);
	pen.setWidth(weight);
	pen.setColor(color);
	//painter��QPainterDevice����������»���
	//�����ⲿ�豸ʱ��Ӧ��ʹ��bengin(), end()
	painter->begin(pix);
	painter->setPen(pen);
	painter->drawLine(startPos, event->pos());
	painter->end();

	startPos = event->pos();
	update();
}

void DrawWidget::paintEvent(QPaintEvent * event)
{
	//QPainter painter(this);
	//painter.drawPixmap(QPoint(0, 0), *pix);
	//or
	QPainter painter;
	painter.begin(this);
	painter.drawPixmap(QPoint(0, 0), *pix);
	painter.end();

}

void DrawWidget::resizeEvent(QResizeEvent * event)
{
	//�жϸı䴰���ĳ����߿����ڵ���
	if (height() > pix->height() || width() > pix->width())
	{
		QPixmap* newPix = new QPixmap(size());
		newPix->fill(Qt::darkBlue);
		QPainter p(newPix);
		p.drawPixmap(QPoint(0, 0), *newPix);
		pix = newPix;
	}
	QWidget::resizeEvent(event);
}

void DrawWidget::setStyle(int s)
{
	style = s;
}

void DrawWidget::setWidth(int w)
{
	weight = w;
}

void DrawWidget::setColor(QColor c)
{
	color = c;
}

//����һ���µ�QPixmap���ԭ��pix��������
void DrawWidget::clear()
{
	QPixmap* clearPix = new QPixmap(size());
	clearPix->fill(Qt::darkBlue);
	pix = clearPix;
	update();
}
