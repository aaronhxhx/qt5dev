#include "SvgWidget.h"

SvgWidget::SvgWidget(QWidget *parent)
	: QSvgWidget(parent)
{
	render = renderer();
}

SvgWidget::~SvgWidget()
{
}

//鼠标响应事件
void SvgWidget::wheelEvent(QWheelEvent *event)
{
	//滚轮每滚动一次，图片大小改变的比例
	const double diff = 0.1;
	//获取图片显示区的尺寸
	QSize size = render->defaultSize();
	int width = size.width();
	int height = size.height();
	//利用QwheelEvent的delta(函数获得滚轮的滚动的距离值
	//
	if (event->delta() > 0)
	{
		//放大处理
		width = int(this->width() + this->width()*diff);
		height = int(this->height() + this->height()*diff);
	}
	else
	{
		//缩小处理
		width = int(this->width() - this->width()*diff);
		height = int(this->height() - this->height()*diff);
	}
	resize(width, height);
}


//