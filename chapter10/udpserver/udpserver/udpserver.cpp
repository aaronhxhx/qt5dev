#include "udpserver.h"


udpserver::udpserver(QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("UDP Server"));
	//��ʼ�������ؼ�
	timerLabel = new QLabel(QStringLiteral("��ʱ����"), this);
	textLineEdit = new QLineEdit(this);
	StartBtn = new QPushButton(QStringLiteral("��ʼ"), this);
	//���ò���
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(timerLabel);
	mainLayout->addWidget(textLineEdit);
	mainLayout->addWidget(StartBtn);

}

udpserver::~udpserver()
{
}
