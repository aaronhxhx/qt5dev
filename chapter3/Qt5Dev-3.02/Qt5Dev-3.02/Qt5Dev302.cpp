#include "Qt5Dev302.h"

Qt5Dev302::Qt5Dev302(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("DockWindows"));			//设置主窗口标题栏
	QTextEdit* te = new QTextEdit(this);		//定义一个QTextEdit对象作为主窗口
	te->setText(tr("main window"));
	te->setAlignment(Qt::AlignCenter);
	setCentralWidget(te);						//将此编辑框作为主窗体

	//停靠窗口1
	QDockWidget* dock = new QDockWidget(tr("DockWindow1"), this);
	//可移动
	dock->setFeatures(QDockWidget::DockWidgetMovable);											//设置停靠窗体特性
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);					//设置停靠窗体可停靠的区域

	QTextEdit* te1 = new QTextEdit();
	te1->setText(tr("window1, the dock widget can be moved"));
	dock->setWidget(te1);
	addDockWidget(Qt::RightDockWidgetArea, dock);

	//停靠窗口2
	dock = new QDockWidget(tr("window2"), this);
	dock->setFeatures(QDockWidget::DockWidgetClosable| QDockWidget::DockWidgetFloatable);		//可关闭可浮动

	QTextEdit* te2 = new QTextEdit();
	te2->setText(tr("window2, the dock widget can be moved"));
	dock->setWidget(te2);
	addDockWidget(Qt::RightDockWidgetArea, dock);

	//停靠窗口3
	dock = new QDockWidget(tr("window3"), this);
	dock->setFeatures(QDockWidget::AllDockWidgetFeatures);										//全部特性

	QTextEdit* te3 = new QTextEdit();
	te3->setText(tr("window3, the dock widget can be moved"));
	dock->setWidget(te3);
	addDockWidget(Qt::RightDockWidgetArea, dock);

}	



Qt5Dev302::~Qt5Dev302()
{

}