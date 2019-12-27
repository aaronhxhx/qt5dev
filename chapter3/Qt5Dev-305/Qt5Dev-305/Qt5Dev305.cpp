#include "Qt5Dev305.h"

Qt5Dev305::Qt5Dev305(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//����һ��stackedWidget����
	stack = new QStackedWidget(this);

	//�Զ�ջ���ڵ���ʾ�ָ��������
	stack->setFrameStyle(QFrame::Panel | QFrame::Raised);

	//��������ҳ��
	baseInfo = new BaseInfo2();
	contact = new Contact();
	detail = new Detail();

	stack->addWidget(baseInfo);
	stack->addWidget(contact);
	stack->addWidget(detail);

	//����������ť
	AmendBtn = new QPushButton(tr("�޸�"));
	CloseBtn = new QPushButton(tr("�ر�"));

	//����
	QVBoxLayout *BtnLayout = new QVBoxLayout();
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

Qt5Dev305::~Qt5Dev305()
{

}
