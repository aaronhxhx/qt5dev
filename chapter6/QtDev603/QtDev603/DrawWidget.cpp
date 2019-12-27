#include "DrawWidget.h"

DrawWidget::DrawWidget(QWidget *parent)
	: QWidget(parent)
{
	//设置窗体的背景色
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
	//当前选择的线形是美剧数据的第几个元素
	pen.setStyle((Qt::PenStyle)style);
	pen.setWidth(weight);
	pen.setColor(color);
	//painter对QPainterDevice对象进行重新绘制
	//绘制外部设备时，应该使用bengin(), end()
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
	//判断改变窗体后的长或者宽，大于调整
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

//调用一个新的QPixmap替代原来pix，并更新
void DrawWidget::clear()
{
	QPixmap* clearPix = new QPixmap(size());
	clearPix->fill(Qt::darkBlue);
	pix = clearPix;
	update();
}
