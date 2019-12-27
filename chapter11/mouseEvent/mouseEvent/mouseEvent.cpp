#include "mouseEvent.h"

MouseEvent::MouseEvent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("����¼�"));
	statusLabel = new QLabel(QStringLiteral("��ǰλ��"));
	statusLabel->setFixedWidth(100);
	
	mousePosLabel = new QLabel(QStringLiteral(""));
	mousePosLabel->setFixedWidth(100);
	statusBar()->addPermanentWidget(statusLabel);
	statusBar()->addPermanentWidget(mousePosLabel);
	//���ô���׷�����
	this->setMouseTracking(true);
	resize(400, 200);
}

MouseEvent::~MouseEvent()
{
}

void MouseEvent::mousePressEvent(QMouseEvent *event)
{
	QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
	if (event->button()== Qt::LeftButton)
	{
		statusBar()->showMessage(QStringLiteral("���: ") + str);
	}
	else if (event->button() == Qt::RightButton)
	{
		statusBar()->showMessage(QStringLiteral("�Ҽ�: ") + str);
	}
	else if (event->button() == Qt::MidButton)
	{
		statusBar()->showMessage(QStringLiteral("�м�: ") + str);
	}
}

void MouseEvent::mouseMoveEvent(QMouseEvent *event)
{
	mousePosLabel->setText("(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")");
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *event)
{
	QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
	statusBar()->showMessage(QStringLiteral("�ͷ���: ") + str, 3000);
}

void MouseEvent::mouseDoubleClickEvent(QMouseEvent *event)
{

}