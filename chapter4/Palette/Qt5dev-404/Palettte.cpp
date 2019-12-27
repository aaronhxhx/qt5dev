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
	//选择颜色面板
	windowLabel = new QLabel(tr("QPalette:: Window: "));
	windowComboBox = new QComboBox;
	//向下拉框插入不同的颜色选项
	fillCorlorList(windowComboBox);
	//需要指明参数，因为重载
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

	Label1 = new QLabel(tr("请选择输入一个值: "));
	comboBox1 = new QComboBox;

	Label2 = new QLabel(tr("请输入字符串: "));
	lineEdit2 = new QLineEdit;

	textEdit = new QTextEdit;
	QGridLayout* TopLayout = new QGridLayout;
	TopLayout->addWidget(Label1, 0, 0);
	TopLayout->addWidget(comboBox1, 0, 1);
	TopLayout->addWidget(Label2, 1, 0);
	TopLayout->addWidget(lineEdit2, 1, 1);
	TopLayout->addWidget(textEdit, 2, 0, 1, 2);

	okBtn = new QPushButton(tr("确认"));
	cancelBtn = new QPushButton(tr("取消"));
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
	//获取当前选择的颜色值
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[windowComboBox->currentIndex()]);
	//获取右侧窗体调色板信息
	QPalette p = ContentFrame->palette();
	//设置contentFrame窗体window类颜色，setColo()的第一个参数设置颜色主题
	//第二个参数设置具体的颜色值
	p.setColor(QPalette::Window, color);
	//把修改后的调色板信息应用到contentFrame窗体中，更新显示
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
	//获取qt所有的颜色名称列表
	QStringList colorList = QColor::colorNames();
	//QString color;
	for (const auto& color:colorList)
	{
		//先建一个Pixmap对象显示图标
		QPixmap pix(QSize(70, 20));
		//为pix填充当前遍历的颜色
		pix.fill(QColor(color));
		//插入一个条目
		comboBox->addItem(QIcon(pix), NULL);
		//设置图标尺寸
		comboBox->setIconSize(QSize(70, 20));
		//下拉框的尺寸调整策略为符合内容大小
		comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
	}
}