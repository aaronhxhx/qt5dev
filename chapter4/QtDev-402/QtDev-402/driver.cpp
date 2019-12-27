#include "driver.h"

Driver::Driver(QWidget *parent, Qt::WindowFlags f): QToolBox(parent, f)
{
	this->setWindowTitle(tr("My QQ"));

	toolBtn1_1 = new QToolButton;
	toolBtn1_1->setText(tr("黄鑫"));
	toolBtn1_1->setIcon(QPixmap(":/MyQQExample/Resources/image1.jpg"));
	//设置按钮大小，这里将按钮大小于图标设置相同
	toolBtn1_1->setIconSize(QPixmap(":/MyQQExample/Resources/image1.jpg").size());
	//但鼠标离开时，按钮自动恢复为弹起状态
	toolBtn1_1->setAutoRaise(true);
	//设置按钮的ToolButtonStyle属性
	toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	//Qt::ToolButtonIconOnly:只显示图标
	//Qt::ToolButtonTextOnly:只显示文字
	//Qt::ToolButtonTextBesideIcon:文字显示在图标旁边
	//Qt::ToolButtonTextUnderIcon:文字显示在图标下面
	//Qt::ToolButtonFellowStyle：遵循style标准


	toolBtn1_2 = new QToolButton;
	toolBtn1_2->setText(tr("张三"));
	toolBtn1_2->setIcon(QPixmap(":/MyQQExample/Resources/image2.jpg"));
	toolBtn1_2->setIconSize(QPixmap(":/MyQQExample/Resources/image2.jpg").size());
	toolBtn1_2->setAutoRaise(true);
	toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn1_3 = new QToolButton;
	toolBtn1_3->setText(tr("李四"));
	toolBtn1_3->setIcon(QPixmap(":/MyQQExample/Resources/image3.jpg"));
	toolBtn1_3->setIconSize(QPixmap(":/MyQQExample/Resources/image3.jpg").size());
	toolBtn1_3->setAutoRaise(true);
	toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn1_4 = new QToolButton;
	toolBtn1_4->setText(tr("王五"));
	toolBtn1_4->setIcon(QPixmap(":/MyQQExample/Resources/image4.jpg"));
	toolBtn1_4->setIconSize(QPixmap(":/MyQQExample/Resources/image4.jpg").size());
	toolBtn1_4->setAutoRaise(true);
	toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn1_5 = new QToolButton;
	toolBtn1_5->setText(tr("李二"));
	toolBtn1_5->setIcon(QPixmap(":/MyQQExample/Resources/image5.jpg"));
	toolBtn1_5->setIconSize(QPixmap(":/MyQQExample/Resources/image5.jpg").size());
	toolBtn1_5->setAutoRaise(true);
	toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	QGroupBox* groupBox1 = new QGroupBox;
	QVBoxLayout* layout1 = new QVBoxLayout(groupBox1);
	layout1->setMargin(10);						//布局中各窗体的显示间距
	layout1->setAlignment(Qt::AlignCenter);		//布局中各窗体的显示位置

	//向抽屉中加入各个按钮
	layout1->addWidget(toolBtn1_1);
	layout1->addWidget(toolBtn1_2);
	layout1->addWidget(toolBtn1_3);
	layout1->addWidget(toolBtn1_4);
	layout1->addWidget(toolBtn1_5);

	//插入一个占位符
	layout1->addStretch();
	toolBtn2_1 = new QToolButton;
	toolBtn2_1->setText(tr("小王"));
	toolBtn2_1->setIcon(QPixmap(":/MyQQExample/Resources/image1.jpg"));
	toolBtn2_1->setIconSize(QPixmap(":/MyQQExample/Resources/image1.jpg").size());
	toolBtn2_1->setAutoRaise(true);
	toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	toolBtn2_2 = new QToolButton;
	toolBtn2_2->setText(tr("小张"));
	toolBtn2_2->setIcon(QPixmap(":/MyQQExample/Resources/image2.jpg"));
	toolBtn2_2->setIconSize(QPixmap(":/MyQQExample/Resources/image2.jpg").size());
	toolBtn2_2->setAutoRaise(true);
	toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	QGroupBox *groupBox2 = new QGroupBox;
	QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
	layout2->setMargin(10);
	layout2->setAlignment(Qt::AlignHCenter);
	layout2->addWidget(toolBtn2_1);
	layout2->addWidget(toolBtn2_2);
	toolBtn3_1 = new QToolButton;
	toolBtn3_1->setText(tr("小陈"));
	toolBtn3_1->setIcon(QPixmap(":/MyQQExample/Resources/image3.jpg"));
	toolBtn3_1->setIconSize(QPixmap(":/MyQQExample/Resources/image3.jpg").size());
	toolBtn3_1->setAutoRaise(true);
	toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	toolBtn3_2 = new QToolButton;
	toolBtn3_2->setText(tr("小李"));
	toolBtn3_2->setIcon(QPixmap(":/MyQQExample/Resources/image4.jpg"));
	toolBtn3_2->setIconSize(QPixmap(":/MyQQExample/Resources/image4.jpg").size());
	toolBtn3_2->setAutoRaise(true);
	toolBtn3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	QGroupBox *groupBox3 = new QGroupBox;
	QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
	layout3->setMargin(10);
	layout3->setAlignment(Qt::AlignHCenter);
	layout3->addWidget(toolBtn3_1);
	layout3->addWidget(toolBtn3_2);

	//将准备好的抽屉插入ToolBox中
	this->addItem((QWidget*)groupBox1, tr("我的好友"));
	this->addItem((QWidget*)groupBox2, tr("陌生人"));
	this->addItem((QWidget*)groupBox3, tr("黑名单"));


}

Driver::~Driver()
{
}
