#include "QtDev305.h"

QtDev305::QtDev305(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//����һ��stackedWidget����
	stack = new QStackedWidget(this);

	//�Զ�ջ���ڵ���ʾ�ָ��������
	stack->setFrameStyle(QFrame::Panel | QFrame::Raised);

	//��������ҳ��
	baseInfo = new BaseInfo();
	contact = new Contact();
	detail = new Detail();

	stack->addWidget(baseInfo);
	stack->addWidget(contact);
	stack->addWidget(detail);

	//����������ť
	AmendBtn = new QPushButton(tr("�޸�"));
	CloseBtn = new QPushButton(tr("�ر�"));

	//����
	QHBoxLayout *BtnLayout = new QHBoxLayout();
	BtnLayout->addStretch(1);
	BtnLayout->addWidget(AmendBtn);
	BtnLayout->addWidget(CloseBtn);

	//���岼��
	QVBoxLayout* RightLayout = new QVBoxLayout(this);
	RightLayout->setMargin(15);
	RightLayout->setSpacing(10);
	RightLayout->addWidget(stack);
	RightLayout->addLayout(BtnLayout);
}

QtDev305::~QtDev305()
{

}