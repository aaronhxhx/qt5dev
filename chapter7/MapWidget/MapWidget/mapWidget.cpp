#include "mapWidget.h"
const int zoomValue = 50;

MapWidget::MapWidget()
{
	//读取地图
	readMap();
	zoom = zoomValue;
	int width = map.width();
	int height = map.height();
	//新建一个QGraphicsScene对象为主窗体连接一个场景
	QGraphicsScene* scene = new QGraphicsScene(this);
	//限定场景的显示区域为地图大小
	scene->setSceneRect(-width / 2, -height / 2, width, height);
	setScene(scene);
	setCacheMode(CacheBackground);
	//用于地图缩放的滑动条
	QSlider* slider = new QSlider;
	slider->setOrientation(Qt::Vertical);
	slider->setRange(1, 100);
	slider->setTickInterval(10);
	slider->setValue(50);
	connect(slider, QOverload<int>::of(&QSlider::valueChanged), this, &MapWidget::slotZoom);

	QLabel* zoominLabel = new QLabel;
	//setScaledContents:此属性保存标签是否将缩放其内容以填充所有可用空间。
	//启用后，标签​​会显示一个像素图，它将缩放该像素图以填充可用空间。
	//此属性的默认值为false。
	zoominLabel->setScaledContents(true);
	zoominLabel->setPixmap(QPixmap(":/Resources/zoomin.png"));
	QLabel* zoomoutLabel = new QLabel;
	zoomoutLabel->setScaledContents(true);
	zoomoutLabel->setPixmap(QPixmap(":/Resources/zoomout.png"));

	//坐标值显示区
	QLabel* graphicViewLabel = new QLabel(tr("GraphicsView: "));
	viewCoord = new QLabel;
	QLabel* graphicSceneLabel = new QLabel(tr("GraphicScene: "));
	sceneCoord = new QLabel;
	QLabel* mapLabel = new QLabel(tr("map: "));
	mapCoord = new QLabel;

	//坐标布局显示
	QGridLayout* gridLayout = new QGridLayout;
	gridLayout->addWidget(graphicViewLabel, 0, 0);
	gridLayout->addWidget(viewCoord, 0, 1);
	gridLayout->addWidget(graphicSceneLabel, 1, 0);
	gridLayout->addWidget(sceneCoord, 1, 1);
	gridLayout->addWidget(mapLabel, 2, 0);
	gridLayout->addWidget(mapCoord, 2, 1);
	gridLayout->setSizeConstraint(QLayout::SetFixedSize);
	QFrame* coordFrame = new QFrame;
	coordFrame->setLayout(gridLayout);
	
	//缩放控制子布局
	QVBoxLayout* zoomLayout = new QVBoxLayout;
	zoomLayout->addWidget(zoominLabel);
	zoomLayout->addWidget(slider);
	zoomLayout->addWidget(zoomoutLabel);

	//坐标显示区域布局
	QVBoxLayout* coordLayout = new QVBoxLayout;
	coordLayout->addWidget(coordFrame);
	coordLayout->addStretch();

	//主布局
	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(zoomLayout);
	mainLayout->addLayout(coordLayout);
	mainLayout->addStretch();
	mainLayout->setMargin(30);
	mainLayout->setSpacing(10);
	setLayout(mainLayout);
	setWindowTitle("map widget");
	setMinimumSize(600, 400);
}

MapWidget::~MapWidget()
{
}

void MapWidget::readMap()
{
	QString mapName;
	QFile mapFile(":/Resources/maps.txt");
	int ok = mapFile.open(QIODevice::ReadOnly);
	if (ok)
	{
		QTextStream ts(&mapFile);
		if (!ts.atEnd())
		{
			ts >> mapName;
			ts >> x1 >> y1 >> x2 >> y2;
		}
	}
	map.load(QString(":/Resources/%1").arg(mapName));
}

void MapWidget::slotZoom(int value)
{
	qreal s;
	if (value > zoom)
	{
		s = pow(1.01, (value - zoom));
	}
	else
	{
		s = pow(1 / 1.01, (zoom - value));
	}
	scale(s, s);
	zoom = value;
}

void MapWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
	painter->drawPixmap(int(sceneRect().left()),
		int(sceneRect().top()), map);
}

void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
	//QGraphicsView 坐标
	QPoint viewPoint = event->pos();
	viewCoord->setText(QString::number(viewPoint.x()) + ',' + QString::number(viewPoint.y()));
	//QGrapgicscene
	QPointF scenePoint = mapToScene(viewPoint);
	sceneCoord->setText(QString::number(scenePoint.x()) + ',' + QString::number(scenePoint.y()));
	//map Coording
	QPointF latLon = maptoMap(scenePoint);
	mapCoord->setText(QString::number(latLon.x()) + ',' + QString::number(latLon.y()));
}

QPointF MapWidget::maptoMap(QPointF p)
{
	QPointF latLon;
	qreal w = sceneRect().width();
	qreal h = sceneRect().height();
	qreal lon = y1 - ((h / 2 + p.y())*abs(y1 - y2) / h);
	qreal lat = x1 + ((w / 2 + p.x())*abs(x1 - x2) / w);
	latLon.setX(lat);
	latLon.setY(lon);
	return latLon;
}