#include "NameWindow.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>

NameWindow::NameWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	createActions();
	createMenus();
	scene = new QGraphicsScene;
	initScene();					//初始化场景
	QGraphicsView* view = new QGraphicsView;
	view->setScene(scene);
	view->setMinimumSize(400, 400);
	view->show();
	setCentralWidget(view);
	resize(550, 450);
	setWindowTitle(tr("Graphics Item"));

}


NameWindow::~NameWindow()
{

}

void  NameWindow::createActions()
{
	newAct = new QAction(QStringLiteral("新建"), this);
	clearAct = new QAction(QStringLiteral("清除"), this);
	exitAct = new QAction(QStringLiteral("退出"), this);
	addEllipseItemAct = new QAction(QStringLiteral("加入 椭圆"), this);
	addPolygonItemAct = new QAction(QStringLiteral("加入 多边形"), this);
	addTextItemAct = new QAction(QStringLiteral("加入 文字"), this);
	addRectItemAct = new QAction(QStringLiteral("加入 矩形"), this);
	addAlphaItemAct = new QAction(QStringLiteral("加入 透明图片"), this);
	addFlashItemAct = new QAction(tr("加入闪烁圆"), this);
	addAnimItemAct = new QAction(tr("加入 星星"), this);
	
	connect(newAct, &QAction::triggered, this, &NameWindow::slotNew);
	connect(clearAct, &QAction::triggered, this, &NameWindow::slotClear);
	connect(exitAct, &QAction::triggered, this, &NameWindow::close);
	connect(addEllipseItemAct, &QAction::triggered, this, &NameWindow::slotAddEllipseItem);
	connect(addPolygonItemAct, &QAction::triggered, this, &NameWindow::slotAddPloygonItem);
	connect(addTextItemAct, &QAction::triggered, this, &NameWindow::slotAddTextItem);
	connect(addRectItemAct, &QAction::triggered, this, &NameWindow::slotAddRectItem);
	connect(addAlphaItemAct, &QAction::triggered, this, &NameWindow::slotAddAlphaItem);
	connect(addFlashItemAct, &QAction::triggered, this, &NameWindow::slotAddFlashItem);
	connect(addAnimItemAct, &QAction::triggered, this, &NameWindow::slotAddAnimationItem);


}

void NameWindow::createMenus()
{
	QMenu* fileMenu = menuBar()->addMenu(QStringLiteral("文件"));
	fileMenu->addAction(newAct);
	fileMenu->addAction(clearAct);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAct);
	
	QMenu* itemMenu = menuBar()->addMenu(QStringLiteral("元素"));
	itemMenu->addAction(addEllipseItemAct);
	itemMenu->addAction(addPolygonItemAct);
	itemMenu->addAction(addPolygonItemAct);
	itemMenu->addAction(addRectItemAct);
	itemMenu->addAction(addTextItemAct);
	itemMenu->addAction(addAlphaItemAct);
	itemMenu->addAction(addFlashItemAct);
	itemMenu->addAction(addAnimItemAct);
}

void NameWindow::initScene()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		slotAddEllipseItem();
	}
	for (i = 0; i < 3; i++)
	{
		slotAddPloygonItem();
	}
	for (i = 0; i < 3; i++)
	{
		slotAddRectItem();
	}
	for (i = 0; i < 3; i++)
	{
		slotAddTextItem();
	}
	for (i = 0; i < 3; i++)
	{
		slotAddAlphaItem();
	}
	for (i = 0; i < 3; i++)
	{
		slotAddFlashItem();
	}
	for (i = 0; i < 3; i++)
	{
		slotAddAnimationItem();
	}
}

//新建一个窗体
void NameWindow::slotNew()
{
	slotClear();
	initScene();
	NameWindow* newWin = new NameWindow;
	newWin->show();
}

//清除场景中的所有的图元
void NameWindow::slotClear()
{
	QList<QGraphicsItem*> listItem = scene->items();
	while (!listItem.empty())
	{
		scene->removeItem(listItem.at(0));
		listItem.removeAt(0);
	}
}

//在场景中加入一个椭圆形图元
void NameWindow::slotAddEllipseItem()
{
	QGraphicsEllipseItem* item = new QGraphicsEllipseItem(QRectF(0, 0, 80, 60));
	item->setPen(Qt::NoPen);
	item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	item->setFlag(QGraphicsItem::ItemIsMovable);
	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200,
		(qrand() % int(scene->sceneRect().height())) - 200);

}

void NameWindow::slotAddPloygonItem()
{
	QVector<QPoint> v;
	v << QPoint(30, -15) << QPoint(0, -30) << QPoint(-30, -15)
		<< QPoint(-30, 15) << QPoint(0, 30) << QPoint(30, 15);
	QGraphicsPolygonItem* item = new QGraphicsPolygonItem(QPolygonF(v));
	item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	item->setFlag(QGraphicsItem::ItemIsMovable);
	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200,
		(qrand() % int(scene->sceneRect().height())) - 200);

}

void NameWindow::slotAddTextItem()  		//在场景中加入一个文字图元
{
	QFont font("Times", 16);
	QGraphicsTextItem *item = new QGraphicsTextItem("Hello Qt");
	item->setFont(font);
	item->setFlag(QGraphicsItem::ItemIsMovable);
	item->setDefaultTextColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200,
		(qrand() % int(scene->sceneRect().height())) - 200);
}

void NameWindow::slotAddRectItem()          //在场景中加入一个长方形图元
{
	QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 60, 60));
	QPen pen;
	pen.setWidth(3);
	pen.setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	item->setPen(pen);
	item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	item->setFlag(QGraphicsItem::ItemIsMovable);
	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200,
		(qrand() % int(scene->sceneRect().height())) - 200);
}

void NameWindow::slotAddAlphaItem() 	//在场景中加入一个透明蝴蝶图片
{
	QGraphicsPixmapItem *item =
		scene->addPixmap(QPixmap(":/Resources/image.png"));
	item->setFlag(QGraphicsItem::ItemIsMovable);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200,
		(qrand() % int(scene->sceneRect().height())) - 200);
}

void NameWindow::slotAddFlashItem()  	//在场景中加入一个闪烁图元
{
	FlashItem *item = new FlashItem;
	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200,
		(qrand() % int(scene->sceneRect().height())) - 200);
}
void NameWindow::slotAddAnimationItem() 	//在场景中加入一个动画星星
{
	StartItem *item = new StartItem;
	QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
	anim->setItem(item);
	QTimeLine *timeLine = new QTimeLine(4000);
	timeLine->setCurveShape(QTimeLine::SineCurve);
	timeLine->setLoopCount(0);
	anim->setTimeLine(timeLine);
	int y = (qrand() % 400) - 200;
	for (int i = 0; i < 400; i++)
	{
		anim->setPosAt(i / 400.0, QPointF(i - 200, y));
	}
	timeLine->start();
	scene->addItem(item);
}
