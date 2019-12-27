#include "ShowWidget.h"

ShowWidget::ShowWidget(QWidget *parent)
	: QWidget(parent)
{
	imageLabel = new QLabel;
	//setScaledContents:此属性保存标签是否将缩放其内容以填充所有可用空间。
	//启用后，标签??会显示一个像素图，它将缩放该像素图以填充可用空间。
	//此属性的默认值为false
	imageLabel->setScaledContents(true);
	text = new QTextEdit;
	
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(imageLabel);
	mainLayout->addWidget(text);
}

ShowWidget::~ShowWidget()
{
}
