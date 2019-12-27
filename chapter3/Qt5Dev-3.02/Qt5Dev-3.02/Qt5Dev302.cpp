#include "Qt5Dev302.h"

Qt5Dev302::Qt5Dev302(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("DockWindows"));			//���������ڱ�����
	QTextEdit* te = new QTextEdit(this);		//����һ��QTextEdit������Ϊ������
	te->setText(tr("main window"));
	te->setAlignment(Qt::AlignCenter);
	setCentralWidget(te);						//���˱༭����Ϊ������

	//ͣ������1
	QDockWidget* dock = new QDockWidget(tr("DockWindow1"), this);
	//���ƶ�
	dock->setFeatures(QDockWidget::DockWidgetMovable);											//����ͣ����������
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);					//����ͣ�������ͣ��������

	QTextEdit* te1 = new QTextEdit();
	te1->setText(tr("window1, the dock widget can be moved"));
	dock->setWidget(te1);
	addDockWidget(Qt::RightDockWidgetArea, dock);

	//ͣ������2
	dock = new QDockWidget(tr("window2"), this);
	dock->setFeatures(QDockWidget::DockWidgetClosable| QDockWidget::DockWidgetFloatable);		//�ɹرտɸ���

	QTextEdit* te2 = new QTextEdit();
	te2->setText(tr("window2, the dock widget can be moved"));
	dock->setWidget(te2);
	addDockWidget(Qt::RightDockWidgetArea, dock);

	//ͣ������3
	dock = new QDockWidget(tr("window3"), this);
	dock->setFeatures(QDockWidget::AllDockWidgetFeatures);										//ȫ������

	QTextEdit* te3 = new QTextEdit();
	te3->setText(tr("window3, the dock widget can be moved"));
	dock->setWidget(te3);
	addDockWidget(Qt::RightDockWidgetArea, dock);

}	



Qt5Dev302::~Qt5Dev302()
{

}