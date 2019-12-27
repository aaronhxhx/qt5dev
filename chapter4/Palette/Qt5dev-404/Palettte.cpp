#include "Palettte.h"

Palettte::Palettte(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	createCtriFrame();
	createContentFrame();
	QHBoxLayout*  mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(ctrlFrame);
	mainLayout->addWidget(ContentFrame);

}

Palettte::~Palettte()
{

}

void Palettte::createCtriFrame()
{
	ctrlFrame = new QFrame;
	//ѡ����ɫ���
	windowLabel = new QLabel(tr("QPalette:: Window: "));
	windowComboBox = new QComboBox;
	//����������벻ͬ����ɫѡ��
	fillCorlorList(windowComboBox);
	//��Ҫָ����������Ϊ����
	void (QComboBox::*fp1)(int) = &QComboBox::activated;
	connect(windowComboBox, fp1, this, &Palettte::ShowWindow);
	connect(windowComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Palettte::ShowWindow);
	//connect(windowComboBox, SIGNAL(activated(int)), this, SLOT(ShowWindow()));

	windowTextLabel = new QLabel(tr("QPalette::WindowText: "));
	windowTextComboBox = new QComboBox;
	fillCorlorList(windowTextComboBox);
	void(QComboBox::*fp2)(int) = &QComboBox::activated;
	connect(windowTextComboBox, fp2, this, &Palettte::ShowWindowText);

	buttonLabel = new QLabel(tr("QPalette::Button: "));
	buttonComboBox = new QComboBox;
	fillCorlorList(buttonComboBox);
	connect(buttonComboBox, SIGNAL(activated(int)), this, SLOT(ShowButton()));
	
	buttonTextLabel = new QLabel(tr("QPalette::ButtonText: "));
	buttonTextComboBox = new QComboBox;
	fillCorlorList(buttonTextComboBox);
	connect(buttonTextComboBox, SIGNAL(activated(int)), this, SLOT(ShowButtonText()));
	
	baseLabel = new QLabel(tr("QPalette::Base: "));
	baseComboBox = new QComboBox;
	fillCorlorList(baseComboBox);
	void (QComboBox::*fp3)(int) = &QComboBox::activated;
	connect(windowComboBox, fp3, this, &Palettte::ShowBase);
	connect(windowComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Palettte::ShowBase);

	QGridLayout* mainLayout = new QGridLayout(ctrlFrame);
	mainLayout->setSpacing(20);
	mainLayout->addWidget(windowLabel, 0, 0);
	mainLayout->addWidget(windowComboBox, 0, 1);
	mainLayout->addWidget(windowTextLabel, 1, 0);
	mainLayout->addWidget(windowTextComboBox, 1, 1);
	mainLayout->addWidget(buttonLabel, 2, 0);
	mainLayout->addWidget(buttonComboBox, 2, 1);
	mainLayout->addWidget(buttonTextLabel, 3, 0);
	mainLayout->addWidget(buttonTextComboBox, 3, 1);
	mainLayout->addWidget(baseLabel, 4, 0);
	mainLayout->addWidget(baseComboBox, 4, 1);

}

void Palettte::createContentFrame()
{
	ContentFrame = new QFrame;

	Label1 = new QLabel(tr("��ѡ������һ��ֵ: "));
	comboBox1 = new QComboBox;

	Label2 = new QLabel(tr("�������ַ���: "));
	lineEdit2 = new QLineEdit;

	textEdit = new QTextEdit;
	QGridLayout* TopLayout = new QGridLayout;
	TopLayout->addWidget(Label1, 0, 0);
	TopLayout->addWidget(comboBox1, 0, 1);
	TopLayout->addWidget(Label2, 1, 0);
	TopLayout->addWidget(lineEdit2, 1, 1);
	TopLayout->addWidget(textEdit, 2, 0, 1, 2);

	okBtn = new QPushButton(tr("ȷ��"));
	cancelBtn = new QPushButton(tr("ȡ��"));
	QHBoxLayout* bottonLayout = new QHBoxLayout;
	bottonLayout->addStretch(1);
	bottonLayout->addWidget(okBtn);
	bottonLayout->addWidget(cancelBtn);

	QVBoxLayout* mainLayout = new QVBoxLayout(ContentFrame);
	mainLayout->addLayout(TopLayout);
	mainLayout->addLayout(bottonLayout);

}

void  Palettte::ShowWindow()
{
	//��ȡ��ǰѡ�����ɫֵ
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[windowComboBox->currentIndex()]);
	//��ȡ�Ҳര���ɫ����Ϣ
	QPalette p = ContentFrame->palette();
	//����contentFrame����window����ɫ��setColo()�ĵ�һ������������ɫ����
	//�ڶ����������þ������ɫֵ
	p.setColor(QPalette::Window, color);
	//���޸ĺ�ĵ�ɫ����ϢӦ�õ�contentFrame�����У�������ʾ
	ContentFrame->setPalette(p);
	ContentFrame->update();
	

}

void Palettte::ShowWindowText()
{
	QStringList colorList = QColor::colorNames();
	QColor color = colorList[windowTextComboBox->currentIndex()];
	QPalette p = ContentFrame->palette();
	p.setColor(QPalette::WindowText, color);
	ContentFrame->setPalette(p);
	ContentFrame->update();
}

void Palettte::ShowButton()
{
	QStringList colorList = QColor::colorNames();
	QColor color = colorList[buttonComboBox->currentIndex()];
	QPalette p = ContentFrame->palette();
	p.setColor(QPalette::Button, color);
	ContentFrame->setPalette(p);
	ContentFrame->update();
}

void Palettte::ShowButtonText()
{
	QStringList colorList = QColor::colorNames();
	QColor color = colorList[buttonTextComboBox->currentIndex()];
	QPalette p = ContentFrame->palette();
	p.setColor(QPalette::ButtonText, color);
	ContentFrame->setPalette(p);
	ContentFrame->update();
}


void Palettte::ShowBase()
{
	QStringList colorList = QColor::colorNames();
	QColor color = colorList[baseComboBox->currentIndex()];
	QPalette p = ContentFrame->palette();
	p.setColor(QPalette::Base, color);
	ContentFrame->setPalette(p);
	ContentFrame->update();
}


void Palettte::fillCorlorList(QComboBox* comboBox)
{
	//��ȡqt���е���ɫ�����б�
	QStringList colorList = QColor::colorNames();
	//QString color;
	for (const auto& color:colorList)
	{
		//�Ƚ�һ��Pixmap������ʾͼ��
		QPixmap pix(QSize(70, 20));
		//Ϊpix��䵱ǰ��������ɫ
		pix.fill(QColor(color));
		//����һ����Ŀ
		comboBox->addItem(QIcon(pix), NULL);
		//����ͼ��ߴ�
		comboBox->setIconSize(QSize(70, 20));
		//������ĳߴ��������Ϊ�������ݴ�С
		comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
	}
}