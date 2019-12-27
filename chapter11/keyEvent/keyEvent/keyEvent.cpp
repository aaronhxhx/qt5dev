#include "keyEvent.h"

KeyEvent::KeyEvent(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	setWindowTitle(QStringLiteral("�����¼�"));
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
	 	//ָ����ͼ�豸
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
	//��pix�����л��ƿ��ƶ�ͼ��
	painter->begin(pix);
	painter->drawImage(QPoint(startX, startY), image);
	painter->end();

}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
	//�ж����μ�ctrl�Ƿ���
	//Qt::KeyBoardModifier����һϵ�е����η�
	//Qt::NoModitifierû�����μ�		Qt::ShiftModitifier ��shift��������
	//Qt::ControlModify��Ctrl������		Qt::AltModitifier	��alt������
	//Qt::MetaModitifier��meta������	Qt::KeypadModitifier	С���̰�������
	//Qt::GroupSwitchModitifier ModeSwitch������
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
		/* ���ȵ���ͼ�����϶����λ��������Ķ����� */
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
	//���ݵ������ͼ��λ��������pix�л���ͼ��
	//���������ػ�
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