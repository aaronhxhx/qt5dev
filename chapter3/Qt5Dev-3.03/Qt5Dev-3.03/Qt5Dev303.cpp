#include "Qt5Dev303.h"

Qt5Dev303::Qt5Dev303(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	setWindowTitle(tr("stackedWidget"));
	list = new QListWidget(this);				//�½�һ��QListWidget�ؼ�����

	//���½���QListWidget�ؼ��в���������Ŀ����Ϊѡ����
	list->insertItem(0, tr("window1"));
	list->insertItem(1, tr("window2"));
	list->insertItem(2, tr("window3"));

	//��������QLabel��ǩ�ؼ�������Ϊ��ջ������Ҫ��ʾ�����㴰��
	label1 = new QLabel(tr("window1Test1"));
	label2 = new QLabel(tr("window1Test2"));
	label3 = new QLabel(tr("window1Test3"));

	//�½�һ��QStackedWidget��ջ�������
	//������������QLabel��ǩ�ؼ����β����ջ������
	stack = new QStackedWidget(this);
	stack->addWidget(label1);
	stack->addWidget(label2);
	stack->addWidget(label3);

	//�������Ի�����в���
	QHBoxLayout *mainLayout = new QHBoxLayout(this->centralWidget());
	
	mainLayout->setMargin(5);				//�趨�Ի����У����壩�ı߾�Ϊ5
	mainLayout->setSpacing(5);				//�趨�����ؼ�֮��ļ��Ϊ5
	mainLayout->addWidget(list);
	mainLayout->addWidget(stack, 0, Qt::AlignCenter);
	mainLayout->setStretchFactor(list, 1);
	mainLayout->setStretchFactor(stack, 3);


	connect(list, SIGNAL(currentRowChange(int)), this, SLOT(setCurrentIndex(int)));
}

Qt5Dev303::~Qt5Dev303()
{

}

