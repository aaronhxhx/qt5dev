#include "Qt5Dev304.h"
#include <QTimer>

Qt5Dev304::Qt5Dev304(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("UserInfo"));


	/************ ���  ******************/
	UserNameLabel = new QLabel(tr("�û�����"));
	UserNameLineEdit = new QLineEdit();

	NameLabel = new QLabel(tr("����"));
	NameLinetEdit = new QLineEdit;

	SexLabel = new QLabel(tr("�Ա�"));
	SexComnoBox = new QComboBox;
	SexComnoBox->addItem(tr("��"));
	SexComnoBox->addItem(tr("Ů"));

	DeparmentLabel = new QLabel(tr("����"));
	DepartmentTextEdit = new QTextEdit;

	AgeLabel = new QLabel(tr("����"));
	AgeLineEdit = new QLineEdit;

	//���ÿؼ����setFrameStyle��QFrame�ķ�����������|�趨�ռ������
	//��״��QFrame::Shape(����NoFrame, Panel, Box, HLine, VLine, WinPanel
	//��ӰQFrame::Shadow(����Plain, Raised, Sunlen)����״����Ӱ����趨
	OtherLabel = new QLabel(tr("��ע"));
	OtherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	//��߲���,���򲼾�����ӿؼ�
	LeftLayout = new QGridLayout();				//���������֣�����ָ��������
	LeftLayout->addWidget(UserNameLabel, 0, 0);
	LeftLayout->addWidget(UserNameLineEdit, 0, 1);
	LeftLayout->addWidget(NameLabel, 1, 0);
	LeftLayout->addWidget(NameLinetEdit, 1, 1);
	LeftLayout->addWidget(SexLabel, 2, 0);
	LeftLayout->addWidget(SexComnoBox, 2, 1);
	LeftLayout->addWidget(DeparmentLabel, 3, 0);
	LeftLayout->addWidget(DepartmentTextEdit, 3, 1);
	LeftLayout->addWidget(AgeLabel, 4, 0);
	LeftLayout->addWidget(AgeLineEdit, 4, 1);
	LeftLayout->addWidget(OtherLabel, 5, 0, 1, 2);

	//ָ�����еı����������趨Ϊ1��3
	LeftLayout->setColumnStretch(0, 1);
	LeftLayout->setColumnStretch(1, 3);

	/************** �Ҳ� ************/
	HeadLabel = new QLabel(tr("ͷ��"));
	HeadIconLabel = new QLabel;

	QPixmap icon(":/Qt5Dev304/Resources/headImage.jpg");


	int iconWidth = icon.width() / 10;
	int iconHeiget = icon.height() / 10;
	HeadIconLabel->resize(iconWidth, iconHeiget);
	//QSize imageSize = HeadIconLabel->size();
	icon = icon.scaled(QSize(iconWidth, iconHeiget), Qt::KeepAspectRatio);
	HeadIconLabel->setPixmap(icon);

	UpdateHeadBtn = new QPushButton(tr("����"));

	//���Ϸ�ͼ��ѡ�����򲼾�
	TopRightLayout = new QHBoxLayout();
	TopRightLayout->setSpacing(20);
	TopRightLayout->addWidget(HeadLabel);
	TopRightLayout->addWidget(HeadIconLabel);
	TopRightLayout->addWidget(UpdateHeadBtn);

	IntroductionLabel = new QLabel(tr("���˽���"));
	IntroductionTextEdit = new QTextEdit;

	//����Ҳ಼��
	RightLayout = new QVBoxLayout();
	RightLayout->setMargin(10);
	RightLayout->addLayout(TopRightLayout);
	RightLayout->addWidget(IntroductionLabel);
	RightLayout->addWidget(IntroductionTextEdit);

	/************************************************************************/
	/* �ײ�                                                                     */
	/************************************************************************/

	OkBtn = new QPushButton(tr("ȷ��"));
	CancelBtn = new QPushButton(tr("ȡ��"));

	//����·��İ�ť�Ĳ���
	ButtonLayout = new QHBoxLayout();
	ButtonLayout->addStretch();			//�ڰ�ť֮ǰ���һ��ռλ����������ť�ܹ��Ҷ��룬�ڶԻ���
										//�����ı�ʱ����ť�������ı�
	ButtonLayout->addWidget(OkBtn);
	ButtonLayout->addWidget(CancelBtn);

	/************************************************************************/
	/* ���岼��                                                                     */
	/************************************************************************/

	QGridLayout* mainLayout = new QGridLayout(this);
	//Ҳ���Ե���this->setLayout(mainLayout)ʵ��
	mainLayout->setMargin(15);
	mainLayout->setSpacing(10);
	mainLayout->addLayout(LeftLayout,0,0);
	mainLayout->addLayout(RightLayout, 0, 1);
	mainLayout->addLayout(ButtonLayout, 1, 0, 1, 2);

	mainLayout->setSizeConstraint(QLayout::SetFixedSize);

	//connect(UpdateHeadBtn, &QPushButton::clicked, this, &Qt5Dev304::initImg);
	//QTimer::singleShot(0, this, &Qt5Dev304::initImg);
}

Qt5Dev304::~Qt5Dev304()
{

}

void Qt5Dev304::initImg()
{
	QPixmap icon(":/Qt5Dev304/Resources/headImage.jpg");


	int iconWidth = icon.width() / 40;
	int iconHeiget = icon.height() / 40;
	HeadIconLabel->resize(iconWidth, iconHeiget);
	//QSize imageSize = HeadIconLabel->size();
	icon = icon.scaled(QSize(iconWidth, iconHeiget), Qt::KeepAspectRatio);
	HeadIconLabel->setPixmap(icon);
}