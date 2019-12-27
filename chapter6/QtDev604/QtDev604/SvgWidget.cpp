#include "SvgWidget.h"

SvgWidget::SvgWidget(QWidget *parent)
	: QSvgWidget(parent)
{
	render = renderer();
}

SvgWidget::~SvgWidget()
{
}

//�����Ӧ�¼�
void SvgWidget::wheelEvent(QWheelEvent *event)
{
	//����ÿ����һ�Σ�ͼƬ��С�ı�ı���
	const double diff = 0.1;
	//��ȡͼƬ��ʾ���ĳߴ�
	QSize size = render->defaultSize();
	int width = size.width();
	int height = size.height();
	//����QwheelEvent��delta(������ù��ֵĹ����ľ���ֵ
	//
	if (event->delta() > 0)
	{
		//�Ŵ���
		width = int(this->width() + this->width()*diff);
		height = int(this->height() + this->height()*diff);
	}
	else
	{
		//��С����
		width = int(this->width() - this->width()*diff);
		height = int(this->height() - this->height()*diff);
	}
	resize(width, height);
}


//