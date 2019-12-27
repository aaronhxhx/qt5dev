#pragma once

#include <QSvgWidget>
#include <QtSvg>
#include <QSvgRenderer>

class SvgWidget : public QSvgWidget
{
	Q_OBJECT

public:
	SvgWidget(QWidget *parent =  nullptr);
	~SvgWidget();
	void wheelEvent(QWheelEvent *event)override;

private:
	QSvgRenderer* render;

};
