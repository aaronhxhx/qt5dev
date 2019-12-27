#include "ShapeWidget.h"

ShapeWidget::ShapeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//新建一个QPixmap对象
	QPixmap pix;
	//加载图片，第一个参数为文件名和路径， 第二个为读取图片的格式， 最后一个参数读取图片的恶的方式
	pix.load(":/ShapeWidget/Resources/image.jpg", 0, Qt::AvoidDither | Qt::ThresholdDither | Qt::ThresholdAlphaDither);
	//主窗体设置的大小和读取图片的大小一致
	resize(pix.size());
	//为调用它的控件增加一个遮罩，遮住所选区域外的部分，时钟看起来是透明的
	//参数可以是QBitmap，QRegion
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

