#include "Qt5Dev304.h"
#include <QTimer>

Qt5Dev304::Qt5Dev304(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("UserInfo"));


	/************ 左侧  ******************/
	UserNameLabel = new QLabel(tr("用户名："));
	UserNameLineEdit = new QLineEdit();

	NameLabel = new QLabel(tr("姓名"));
	NameLinetEdit = new QLineEdit;

	SexLabel = new QLabel(tr("性别"));
	SexComnoBox = new QComboBox;
	SexComnoBox->addItem(tr("男"));
	SexComnoBox->addItem(tr("女"));

	DeparmentLabel = new QLabel(tr("部门"));
	DepartmentTextEdit = new QTextEdit;

	AgeLabel = new QLabel(tr("年龄"));
	AgeLineEdit = new QLineEdit;

	//设置控件风格，setFrameStyle是QFrame的方法，参数以|设定空间风格面板
	//形状由QFrame::Shape(包括NoFrame, Panel, Box, HLine, VLine, WinPanel
	//阴影QFrame::Shadow(包括Plain, Raised, Sunlen)由形状和阴影配合设定
	OtherLabel = new QLabel(tr("备注"));
	OtherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	//左边布局,并向布局中添加控件
	LeftLayout = new QGridLayout();				//不是著布局，不用指定父窗口
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

	//指定两列的比例，这里设定为1：3
	LeftLayout->setColumnStretch(0, 1);
	LeftLayout->setColumnStretch(1, 3);

	/************** 右侧 ************/
	HeadLabel = new QLabel(tr("头像"));
	HeadIconLabel = new QLabel;

	QPixmap icon(":/Qt5Dev304/Resources/headImage.jpg");


	int iconWidth = icon.width() / 10;
	int iconHeiget = icon.height() / 10;
	HeadIconLabel->resize(iconWidth, iconHeiget);
	//QSize imageSize = HeadIconLabel->size();
	icon = icon.scaled(QSize(iconWidth, iconHeiget), Qt::KeepAspectRatio);
	HeadIconLabel->setPixmap(icon);

	UpdateHeadBtn = new QPushButton(tr("更新"));

	//右上方图像选择区域布局
	TopRightLayout = new QHBoxLayout();
	TopRightLayout->setSpacing(20);
	TopRightLayout->addWidget(HeadLabel);
	TopRightLayout->addWidget(HeadIconLabel);
	TopRightLayout->addWidget(UpdateHeadBtn);

	IntroductionLabel = new QLabel(tr("个人介绍"));
	IntroductionTextEdit = new QTextEdit;

	//完成右侧布局
	RightLayout = new QVBoxLayout();
	RightLayout->setMargin(10);
	RightLayout->addLayout(TopRightLayout);
	RightLayout->addWidget(IntroductionLabel);
	RightLayout->addWidget(IntroductionTextEdit);

	/************************************************************************/
	/* 底部                                                                     */
	/************************************************************************/

	OkBtn = new QPushButton(tr("确定"));
	CancelBtn = new QPushButton(tr("取消"));

	//完成下方的按钮的布局
	ButtonLayout = new QHBoxLayout();
	ButtonLayout->addStretch();			//在按钮之前添加一个占位符，两个按钮能够右对齐，在对话框
										//发生改变时，按钮不发生改变
	ButtonLayout->addWidget(OkBtn);
	ButtonLayout->addWidget(CancelBtn);

	/************************************************************************/
	/* 总体布局                                                                     */
	/************************************************************************/

	QGridLayout* mainLayout = new QGridLayout(this);
	//也可以调用this->setLayout(mainLayout)实现
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