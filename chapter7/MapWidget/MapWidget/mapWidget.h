#pragma once

#include <QGraphicsView>
#include <QPixmap>
#include <QLabel>
#include <QMouseEvent>
#include <QSlider>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>
#include <math.h>

class MapWidget : public QGraphicsView
{
	Q_OBJECT

public:
	MapWidget();
	~MapWidget();
	//读取地图信息
	void readMap();
	//用于实现场景坐标系与地图坐标系之间的映射
	QPointF maptoMap(QPointF);

public slots:
	void slotZoom(int);
protected:
	void drawBackground(QPainter *painter, const QRectF &rect)override;
	void mouseMoveEvent(QMouseEvent *event)override;
private:
	QPixmap map;
	qreal zoom;
	QLabel* viewCoord;
	QLabel* sceneCoord;
	QLabel* mapCoord;
	double x1, y1;
	double x2, y2;

};
