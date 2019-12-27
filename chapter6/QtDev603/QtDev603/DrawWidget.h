#pragma once

#include <QWidget>
#include "macro.h"
#include <QtGui>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QColor>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPalette>
#include <QPen>

class DrawWidget : public QWidget
{
	Q_OBJECT

public:
	explicit DrawWidget(QWidget *parent = nullptr);
	~DrawWidget();
	void mousePressEvent(QMouseEvent *event)override;
	void mouseMoveEvent(QMouseEvent *event)override;
	void paintEvent(QPaintEvent *event)override;
	void resizeEvent(QResizeEvent *event);

signals:
public slots:
	void setStyle(int);
	void setWidth(int);
	void setColor(QColor);
	void clear();

private:
	QPixmap* pix;
	QPoint startPos;
	QPoint endPos;
	int style;
	int weight;
	QColor color;
};
