#include "driver.h"

Driver::Driver(QWidget *parent, Qt::WindowFlags f): QToolBox(parent, f)
{
	this->setWindowTitle(tr("My QQ"));

	toolBtn1_1 = new QToolButton;
	toolBtn1_1->setText(tr("����"));
	toolBtn1_1->setIcon(QPixmap(":/MyQQExample/Resources/image1.jpg"));
	//���ð�ť��С�����ｫ��ť��С��ͼ��������ͬ
	toolBtn1_1->setIconSize(QPixmap(":/MyQQExample/Resources/image1.jpg").size());
	//������뿪ʱ����ť�Զ��ָ�Ϊ����״̬
	toolBtn1_1->setAutoRaise(true);
	//���ð�ť��ToolButtonStyle����
	toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	//Qt::ToolButtonIconOnly:ֻ��ʾͼ��
	//Qt::ToolButtonTextOnly:ֻ��ʾ����
	//Qt::ToolButtonTextBesideIcon:������ʾ��ͼ���Ա�
	//Qt::ToolButtonTextUnderIcon:������ʾ��ͼ������
	//Qt::ToolButtonFellowStyle����ѭstyle��׼


	toolBtn1_2 = new QToolButton;
	toolBtn1_2->setText(tr("����"));
	toolBtn1_2->setIcon(QPixmap(":/MyQQExample/Resources/image2.jpg"));
	toolBtn1_2->setIconSize(QPixmap(":/MyQQExample/Resources/image2.jpg").size());
	toolBtn1_2->setAutoRaise(true);
	toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn1_3 = new QToolButton;
	toolBtn1_3->setText(tr("����"));
	toolBtn1_3->setIcon(QPixmap(":/MyQQExample/Resources/image3.jpg"));
	toolBtn1_3->setIconSize(QPixmap(":/MyQQExample/Resources/image3.jpg").size());
	toolBtn1_3->setAutoRaise(true);
	toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn1_4 = new QToolButton;
	toolBtn1_4->setText(tr("����"));
	toolBtn1_4->setIcon(QPixmap(":/MyQQExample/Resources/image4.jpg"));
	toolBtn1_4->setIconSize(QPixmap(":/MyQQExample/Resources/image4.jpg").size());
	toolBtn1_4->setAutoRaise(true);
	toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn1_5 = new QToolButton;
	toolBtn1_5->setText(tr("���"));
	toolBtn1_5->setIcon(QPixmap(":/MyQQExample/Resources/image5.jpg"));
	toolBtn1_5->setIconSize(QPixmap(":/MyQQExample/Resources/image5.jpg").size());
	toolBtn1_5->setAutoRaise(true);
	toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	QGroupBox* groupBox1 = new QGroupBox;
	QVBoxLayout* layout1 = new QVBoxLayout(groupBox1);
	layout1->setMargin(10);						//�����и��������ʾ���
	layout1->setAlignment(Qt::AlignCenter);		//�����и��������ʾλ��

	//������м��������ť
	layout1->addWidget(toolBtn1_1);
	layout1->addWidget(toolBtn1_2);
	layout1->addWidget(toolBtn1_3);
	layout1->addWidget(toolBtn1_4);
	layout1->addWidget(toolBtn1_5);

	//����һ��ռλ��
	layout1->addStretch();
	toolBtn2_1 = new QToolButton;
	toolBtn2_1->setText(tr("С��"));
	toolBtn2_1->setIcon(QPixmap(":/MyQQExample/Resources/image1.jpg"));
	toolBtn2_1->setIconSize(QPixmap(":/MyQQExample/Resources/image1.jpg").size());
	toolBtn2_1->setAutoRaise(true);
	toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	toolBtn2_2 = new QToolButton;
	toolBtn2_2->setText(tr("С��"));
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
	toolBtn3_1->setText(tr("С��"));
	toolBtn3_1->setIcon(QPixmap(":/MyQQExample/Resources/image3.jpg"));
	toolBtn3_1->setIconSize(QPixmap(":/MyQQExample/Resources/image3.jpg").size());
	toolBtn3_1->setAutoRaise(true);
	toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	toolBtn3_2 = new QToolButton;
	toolBtn3_2->setText(tr("С��"));
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

	//��׼���õĳ������ToolBox��
	this->addItem((QWidget*)groupBox1, tr("�ҵĺ���"));
	this->addItem((QWidget*)groupBox2, tr("İ����"));
	this->addItem((QWidget*)groupBox3, tr("������"));


}

Driver::~Driver()
{
}
