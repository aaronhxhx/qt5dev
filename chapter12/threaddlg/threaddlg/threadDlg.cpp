#include "threadDlg.h"

ThreadDlg::ThreadDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("线程"));
	startBtn = new QPushButton(QStringLiteral("开始"));
	stopBtn = new QPushButton(QStringLiteral("停止"));
	quitBtn = new QPushButton(QStringLiteral("退出"));
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(startBtn);
	mainLayout->addWidget(stopBtn);
	mainLayout->addWidget(quitBtn);

	connect(startBtn, &QPushButton::clicked, this, &ThreadDlg::slotStart);
	connect(stopBtn, &QPushButton::clicked, this, &ThreadDlg::slotStop);
	connect(quitBtn, &QPushButton::clicked, this, &QWidget::close);
}

ThreadDlg::~ThreadDlg()
{
}

void ThreadDlg::slotStart()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		//创建指定数目线程保存子啊指针数组
		workThread[i] = new WorkThread();
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		//调用基类的start函数
		workThread[i]->start();
	}
	startBtn->setEnabled(false);
	stopBtn->setEnabled(true);
}

void ThreadDlg::slotStop()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		workThread[i]->terminate();
		workThread[i]->wait();
	}
	startBtn->setEnabled(true);
	stopBtn->setEnabled(false);
}
