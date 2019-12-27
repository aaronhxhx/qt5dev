#pragma once

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPainter>

class Paintarea : public QWidget
{
	Q_OBJECT

public:
	explicit Paintarea(QWidget *parent = nullptr);
	~Paintarea();
	enum Shape {Line, Rectangle, RoundRect, Ellipse, Polygon, Polyline,
		Points, Arc, Path, Text, Pixmap};
	void setShape(Shape);
	void setPen(QPen);
	void setBrush(QBrush);
	void setFillRule(Qt::FillRule);				//ÃÓ≥‰πÊ‘Ú
	void paintEvent(QPaintEvent *event)override;

signals:

public slots:

private:
	Shape shape;
	QPen pen;
	QBrush brush;
	Qt::FillRule fillRule;

};
