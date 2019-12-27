#include "ShowWidget.h"

ShowWidget::ShowWidget(QWidget *parent)
	: QWidget(parent)
{
	imageLabel = new QLabel;
	//setScaledContents:�����Ա����ǩ�Ƿ�������������������п��ÿռ䡣
	//���ú󣬱�ǩ??����ʾһ������ͼ���������Ÿ�����ͼ�������ÿռ䡣
	//�����Ե�Ĭ��ֵΪfalse
	imageLabel->setScaledContents(true);
	text = new QTextEdit;
	
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(imageLabel);
	mainLayout->addWidget(text);
}

ShowWidget::~ShowWidget()
{
}
