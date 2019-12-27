#include "keyEvent.h"

KeyEvent::KeyEvent(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	setWindowTitle(QStringLiteral("键盘事件"));
	setAutoFillBackground(true);
	QPalette palette = this->palette();
	palette.setColor(QPalette::Window, Qt::white);
	setPalette(palette);
	setMinimumSize(512, 256);
	setMaximumSize(512, 256);
	width = size().width();
	height = size().height();
	pix = new QPixmap(width, height);
	pix->fill(Qt::white);
	int index = image.load(":/Resources/image.png");
	startX = 100;
	startY = 100;
	step = 20;
	drawPix();
	resize(512, 256);
}

void KeyEvent::drawPix()
{
	pix->fill(Qt::white);
	QPainter* painter = new QPainter;
	QPen pen(Qt::DotLine);
	for (int i = step; i < width; i += step)
	{
	 	//指定绘图设备
		painter->begin(pix);
		painter->setPen(pen);
		painter->drawLine(QPoint(i, 0), QPoint(i, height));
		painter->end();
	}
	for (int j = step; j < height; j += step)
	{
		painter->begin(pix);
		painter->setPen(pen);
		painter->drawLine(QPoint(0, j), QPoint(width, j));
		painter->end();
	}
	//在pix对象中绘制可移动图标
	painter->begin(pix);
	painter->drawImage(QPoint(startX, startY), image);
	painter->end();

}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
	//判断修饰键ctrl是否按下
	//Qt::KeyBoardModifier定义一系列的修饰符
	//Qt::NoModitifier没有修饰键		Qt::ShiftModitifier 【shift】键按下
	//Qt::ControlModify【Ctrl】按下		Qt::AltModitifier	【alt】按下
	//Qt::MetaModitifier【meta】按下	Qt::KeypadModitifier	小键盘按键按下
	//Qt::GroupSwitchModitifier ModeSwitch键按下
	if (event->modifiers() == Qt::ControlModifier)
	{
		if (event->key() == Qt::Key_Left)					//(b)
		{
			startX = (startX - 1 < 0) ? startX : startX - 1;
		}
		if (event->key() == Qt::Key_Right)					//(c)
		{
			startX = (startX + 1 + image.width() > width) ? startX : startX + 1;
		}
		if (event->key() == Qt::Key_Up)						//(d)
		{
			startY = (startY - 1 < 0) ? startY : startY - 1;
		}
		if (event->key() == Qt::Key_Down)					//(e)
		{
			startY = (startY + 1 + image.height() > height) ? startY : startY + 1;
		}
	}
	else
	{
		/* 首先调节图标左上顶点的位置至网格的顶点上 */
		startX = startX - startX % step;
		startY = startY - startY % step;
		if (event->key() == Qt::Key_Left)					//(f)
		{
			startX = (startX - step < 0) ? startX : startX - step;
		}
		if (event->key() == Qt::Key_Right)					//(g)
		{
			startX = (startX + step + image.width() > width) ? startX : startX + step;
		}
		if (event->key() == Qt::Key_Up)						//(h)
		{
			startY = (startY - step < 0) ? startY : startY - step;
		}
		if (event->key() == Qt::Key_Down)					//(i)
		{
			startY = (startY + step + image.height() > height) ?
				startY : startY + step;
		}
		if (event->key() == Qt::Key_Home)					//(j)
		{
			startX = 0;
			startY = 0;
		}
		if (event->key() == Qt::Key_End)					//(k)
		{
			startX = width - image.width();
			startY = height - image.height();
		}
	}
	//根据调整后的图标位置重新在pix中绘制图像
	//触发界面重画
	drawPix();
	update();
}

KeyEvent::~KeyEvent()
{

}

void KeyEvent::paintEvent(QPaintEvent *event)
{
	QPainter painter;
	painter.begin(this);
	painter.drawPixmap(QPoint(0, 0), *pix);
	painter.end();
}