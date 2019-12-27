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
	//��svg�ļ����ص�svgWidget�н�����ʾ
	svgWidget->load(fileName);
	//���䰴��SvgͼƬ�ߴ���ʾ
	QSvgRenderer* render = svgWidget->renderer();
	svgWidget->resize(render->defaultSize());
}

void SvgWindow::mousePressEvent(QMouseEvent *event)
{
	//��ѹʱ����λ�ý��г�ʼ��
	mousePressPos = event->pos();
	ScrollBarValueOnMousePress.rx() = horizontalScrollBar()->value();
	ScrollBarValueOnMousePress.ry() = verticalScrollBar()->value();
	event->accept();
}

void SvgWindow::mouseMoveEvent(QMouseEvent *event)
{
	//����λ�ý�������
	horizontalScrollBar()->setValue(ScrollBarValueOnMousePress.x() - event->pos().x() + mousePressPos.x());
	verticalScrollBar()->setValue(ScrollBarValueOnMousePress.y() - event->pos().y() + mousePressPos.y());
	horizontalScrollBar()->update();
	verticalScrollBar()->update();
	event->accept();
}

