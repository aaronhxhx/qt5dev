#pragma once

#include <QtWidgets/QWidget>
#include "ui_ItemWidget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFrame>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QGroupBox>
#include "Pixitem.h"


class ItemWidget : public QWidget
{
	Q_OBJECT

public:
	ItemWidget(QWidget *parent = Q_NULLPTR);
	~ItemWidget();
	void init();
	void createControlFrame();
	
public slots:
	void slotRotate(int);
	void slotScale(int);
	void slotShear(int);
	void slotTranslate(int);
private:
	Ui::ItemWidgetClass ui;
	int angle;
	qreal scaleValue;
	qreal shearValue;
	qreal translateValue;
	QGraphicsView* view;
	QFrame* ctrlFrame;
	Pixitem* pixItem;
};
