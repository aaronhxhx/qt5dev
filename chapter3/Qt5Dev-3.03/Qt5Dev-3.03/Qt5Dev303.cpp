#include "Qt5Dev303.h"

Qt5Dev303::Qt5Dev303(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	setWindowTitle(tr("stackedWidget"));
	list = new QListWidget(this);				//新建一个QListWidget控件对象

	//在新建的QListWidget控件中插入三个条目，作为选择项
	list->insertItem(0, tr("window1"));
	list->insertItem(1, tr("window2"));
	list->insertItem(2, tr("window3"));

	//创建三个QLabel标签控件对象，作为堆栈窗口需要显示的三层窗体
	label1 = new QLabel(tr("window1Test1"));
	label2 = new QLabel(tr("window1Test2"));
	label3 = new QLabel(tr("window1Test3"));

	//新建一个QStackedWidget堆栈窗体对象
	//将创建的三个QLabel标签控件依次插入堆栈窗体中
	stack = new QStackedWidget(this);
	stack->addWidget(label1);
	stack->addWidget(label2);
	stack->addWidget(label3);

	//对整个对话框进行布局
	QHBoxLayout *mainLayout = new QHBoxLayout(this->centralWidget());
	
	mainLayout->setMargin(5);				//设定对话框有（或窗体）的边距为5
	mainLayout->setSpacing(5);				//设定各个控件之间的间距为5
	mainLayout->addWidget(list);
	mainLayout->addWidget(stack, 0, Qt::AlignCenter);
	mainLayout->setStretchFactor(list, 1);
	mainLayout->setStretchFactor(stack, 3);


	connect(list, SIGNAL(currentRowChange(int)), this, SLOT(setCurrentIndex(int)));
}

Qt5Dev303::~Qt5Dev303()
{

}

