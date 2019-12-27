#include "ItemWidget.h"

ItemWidget::ItemWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();

}
ItemWidget::~ItemWidget()
{
}
void ItemWidget::init()
{
	angle = 0;
	scaleValue = 5;
	shearValue = 5;
	translateValue = 50;
	QGraphicsScene* scene = new QGraphicsScene;
	//�޶�������ʾ����
	scene->setSceneRect(-200, -200, 400, 400);
	QPixmap* pixmap = new QPixmap(":/Resources/image.png");
	pixItem = new Pixitem(pixmap);
	scene->addItem(pixItem);
	pixItem->setPos(0, 0);
	view = new QGraphicsView;
	view->setScene(scene);
	view->setMinimumSize(400, 400);
	ctrlFrame = new QFrame;
	createControlFrame();

	//�����ڲ���
	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->setMargin(10);
	mainLayout->setSpacing(20);
	mainLayout->addWidget(view);
	mainLayout->addWidget(ctrlFrame);
	setLayout(mainLayout);
	setWindowTitle(QStringLiteral("Graphics Item Transformation"));

}

void ItemWidget::createControlFrame()
{
	//��ת����
	QSlider* rotateSlider = new QSlider;
	rotateSlider->setOrientation(Qt::Horizontal);
	rotateSlider->setRange(0, 360);
	QHBoxLayout* rotateLayout = new QHBoxLayout;
	rotateLayout->addWidget(rotateSlider);
	QGroupBox* rotateGroup = new QGroupBox(QStringLiteral("Rotate"));
	rotateGroup->setLayout(rotateLayout);

	//���ſ���
	QSlider* scaleSlider = new QSlider;
	scaleSlider->setOrientation(Qt::Horizontal);
	scaleSlider->setRange(0, 2 * scaleValue);
	scaleSlider->setValue(scaleValue);
	QHBoxLayout* scaleLayout = new QHBoxLayout;
	scaleLayout->addWidget(scaleSlider);
	QGroupBox* scaleGroup = new QGroupBox(QStringLiteral("Scale"));
	scaleGroup->setLayout(scaleLayout);
	
	//�б����
	QSlider* shearSlider = new QSlider;
	shearSlider->setOrientation(Qt::Horizontal);
	shearSlider->setRange(0, 2 * shearValue);
	shearSlider->setValue(shearValue);
	QHBoxLayout* shearLayout = new QHBoxLayout;
	shearLayout->addWidget(shearSlider);
	QGroupBox* shearGroup = new QGroupBox(QStringLiteral("Shear"));
	shearGroup->setLayout(shearLayout);

	//λ�ƿ���
	QSlider* translateSlider = new QSlider;
	translateSlider->setOrientation(Qt::Horizontal);
	translateSlider->setRange(0, 2 * translateValue);
	translateSlider->setValue(translateValue);
	QHBoxLayout* translateLayout = new QHBoxLayout;
	translateLayout->addWidget(translateSlider);
	QGroupBox* translateGroup = new QGroupBox(QStringLiteral("Translate"));
	translateGroup->setLayout(translateLayout);

	//������岼��
	QVBoxLayout* frameLayout = new QVBoxLayout;
	frameLayout->setMargin(10);
	frameLayout->setSpacing(20);
	frameLayout->addWidget(rotateGroup);
	frameLayout->addWidget(scaleGroup);
	frameLayout->addWidget(shearGroup);
	frameLayout->addWidget(translateGroup);
	ctrlFrame->setLayout(frameLayout);

	connect(rotateSlider, QOverload<int>::of(&QSlider::valueChanged), this, &ItemWidget::slotRotate);
	connect(scaleSlider, QOverload<int>::of(&QSlider::valueChanged), this, &ItemWidget::slotScale);
	connect(shearSlider, QOverload<int>::of(&QSlider::valueChanged), this, &ItemWidget::slotShear);
	connect(translateSlider, QOverload<int>::of(&QSlider::valueChanged), this, &ItemWidget::slotTranslate);
}

void ItemWidget::slotRotate(int value)
{
	view->rotate(value - angle);
	angle = value;
}

void ItemWidget::slotScale(int value)
{
	qreal s;
	if (value > scaleValue)
	{
		s = pow(1.1, (value - scaleValue));
	}
	else
	{
		s = pow(1 / 1.1, (scaleValue - value));
	}
	view->scale(s, s);
	scaleValue = value;
}

void ItemWidget::slotShear(int value)
{
	view->shear((value - shearValue) / 10.0, 0);
	shearValue = value;
}

void ItemWidget::slotTranslate(int value)
{
	view->translate(value - translateValue, value - translateValue);
	translateValue = value;
}
