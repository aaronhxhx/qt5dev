#include "threadDlg.h"

ThreadDlg::ThreadDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("�߳�"));
	startBtn = new QPushButton(QStringLiteral("��ʼ"));
	stopBtn = new QPushButton(QStringLiteral("ֹͣ"));
	quitBtn = new QPushButton(QStringLiteral("�˳�"));
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
		//����ָ����Ŀ�̱߳����Ӱ�ָ������
		workThread[i] = new WorkThread();
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		//���û����start����
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
