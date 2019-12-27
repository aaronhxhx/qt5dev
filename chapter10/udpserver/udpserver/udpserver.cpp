#include "udpserver.h"


udpserver::udpserver(QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("UDP Server"));
	//初始化各个控件
	timerLabel = new QLabel(QStringLiteral("计时器："), this);
	textLineEdit = new QLineEdit(this);
	StartBtn = new QPushButton(QStringLiteral("开始"), this);
	//设置布局
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(timerLabel);
	mainLayout->addWidget(textLineEdit);
	mainLayout->addWidget(StartBtn);

}

udpserver::~udpserver()
{
}
