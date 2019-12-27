#pragma once

#include <QScrollArea>
#include "SvgWidget.h"

class SvgWindow : public QScrollArea
{
	Q_OBJECT

public:
	SvgWindow(QWidget *parent = nullptr);
	~SvgWindow();
	void setFile(QString);
	void mousePressEvent(QMouseEvent *)override;
	void mouseMoveEvent(QMouseEvent *)override;
private:
	SvgWidget* svgWidget;
	QPoint mousePressPos;
	QPoint ScrollBarValueOnMousePress;

};
