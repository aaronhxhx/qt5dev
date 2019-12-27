#include "mouseEvent.h"

MouseEvent::MouseEvent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("鼠标事件"));
	statusLabel = new QLabel(QStringLiteral("当前位置"));
	statusLabel->setFixedWidth(100);
	
	mousePosLabel = new QLabel(QStringLiteral(""));
	mousePosLabel->setFixedWidth(100);
	statusBar()->addPermanentWidget(statusLabel);
	statusBar()->addPermanentWidget(mousePosLabel);
	//设置窗体追踪鼠标
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
		statusBar()->showMessage(QStringLiteral("左键: ") + str);
	}
	else if (event->button() == Qt::RightButton)
	{
		statusBar()->showMessage(QStringLiteral("右键: ") + str);
	}
	else if (event->button() == Qt::MidButton)
	{
		statusBar()->showMessage(QStringLiteral("中键: ") + str);
	}
}

void MouseEvent::mouseMoveEvent(QMouseEvent *event)
{
	mousePosLabel->setText("(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")");
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *event)
{
	QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
	statusBar()->showMessage(QStringLiteral("释放在: ") + str, 3000);
}

void MouseEvent::mouseDoubleClickEvent(QMouseEvent *event)
{

}