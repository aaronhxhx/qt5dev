#include "SvgWindow.h"

SvgWindow::SvgWindow(QWidget *parent)
	: QScrollArea(parent)
{
	svgWidget = new SvgWidget;
	setWidget(svgWidget);
}

SvgWindow::~SvgWindow()
{
}

void SvgWindow::setFile(QString fileName)
{
	//将svg文件加载到svgWidget中进行显示
	svgWidget->load(fileName);
	//将其按照Svg图片尺寸显示
	QSvgRenderer* render = svgWidget->renderer();
	svgWidget->resize(render->defaultSize());
}

void SvgWindow::mousePressEvent(QMouseEvent *event)
{
	//按压时，对位置进行初始化
	mousePressPos = event->pos();
	ScrollBarValueOnMousePress.rx() = horizontalScrollBar()->value();
	ScrollBarValueOnMousePress.ry() = verticalScrollBar()->value();
	event->accept();
}

void SvgWindow::mouseMoveEvent(QMouseEvent *event)
{
	//对新位置进行设置
	horizontalScrollBar()->setValue(ScrollBarValueOnMousePress.x() - event->pos().x() + mousePressPos.x());
	verticalScrollBar()->setValue(ScrollBarValueOnMousePress.y() - event->pos().y() + mousePressPos.y());
	horizontalScrollBar()->update();
	verticalScrollBar()->update();
	event->accept();
}

