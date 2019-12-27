#include "ShapeWidget.h"

ShapeWidget::ShapeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//�½�һ��QPixmap����
	QPixmap pix;
	//����ͼƬ����һ������Ϊ�ļ�����·���� �ڶ���Ϊ��ȡͼƬ�ĸ�ʽ�� ���һ��������ȡͼƬ�Ķ�ķ�ʽ
	pix.load(":/ShapeWidget/Resources/image.jpg", 0, Qt::AvoidDither | Qt::ThresholdDither | Qt::ThresholdAlphaDither);
	//���������õĴ�С�Ͷ�ȡͼƬ�Ĵ�Сһ��
	resize(pix.size());
	//Ϊ�������Ŀؼ�����һ�����֣���ס��ѡ������Ĳ��֣�ʱ�ӿ�������͸����
	//����������QBitmap��QRegion
	setMask(QBitmap(pix.mask()));

}

ShapeWidget::~ShapeWidget()
{
}

void ShapeWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
	if (event->button() == Qt::RightButton)
	{
		close();
	}
	
}

void ShapeWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		move(event->globalPos() - dragPosition);
		event->accept();
	}

}

void ShapeWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, QPixmap(":/ShapeWidget/Resources/image.jpg"));
}

