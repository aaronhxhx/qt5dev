#include "QtDev305.h"

QtDev305::QtDev305(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//创建一个stackedWidget对象
	stack = new QStackedWidget(this);

	//对堆栈窗口的显示分割进行设置
	stack->setFrameStyle(QFrame::Panel | QFrame::Raised);

	//插入三个页面
	baseInfo = new BaseInfo();
	contact = new Contact();
	detail = new Detail();

	stack->addWidget(baseInfo);
	stack->addWidget(contact);
	stack->addWidget(detail);

	//创建两个按钮
	AmendBtn = new QPushButton(tr("修改"));
	CloseBtn = new QPushButton(tr("关闭"));

	//布局
	QHBoxLayout *BtnLayout = new QHBoxLayout();
	BtnLayout->addStretch(1);
	BtnLayout->addWidget(AmendBtn);
	BtnLayout->addWidget(CloseBtn);

	//整体布局
	QVBoxLayout* RightLayout = new QVBoxLayout(this);
	RightLayout->setMargin(15);
	RightLayout->setSpacing(10);
	RightLayout->addWidget(stack);
	RightLayout->addLayout(BtnLayout);
}

QtDev305::~QtDev305()
{

}