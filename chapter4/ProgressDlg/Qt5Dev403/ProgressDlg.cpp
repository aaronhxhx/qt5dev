#include "ProgressDlg.h"

ProgressDlg::ProgressDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QFont font("ZYSong18030", 12);
	setFont(font);
	setWindowTitle(tr("文件数目"));

	fileNum = new QLabel(tr("文件数目："));
	fileNumLineEdit = new QLineEdit(tr("1000000"));

	ProgressType = new QLabel(tr("显示类型："));
	 
	comboBox = new QComboBox;
	comboBox->addItem(tr("progressNar"));
	comboBox->addItem(tr("progressDialog"));

	progressBar = new QProgressBar;
	startBtn = new QPushButton(tr("开始"));
	
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(fileNum, 0, 0);
	mainLayout->addWidget(fileNumLineEdit, 0, 1);
	mainLayout->addWidget(ProgressType, 1, 0);
	mainLayout->addWidget(comboBox, 1, 1);
	mainLayout->addWidget(progressBar, 2, 0, 1, 2);
	mainLayout->addWidget(startBtn, 3, 1);
	mainLayout->setMargin(15);
	mainLayout->setSpacing(10);

	connect(startBtn, &QPushButton::clicked, this, &ProgressDlg::startProgress);
}

void ProgressDlg::startProgress()
{
	bool ok;
	//获取当前进度条方式显示进度
	int num = fileNumLineEdit->text().toInt(&ok);

	//采用进度条的方式显示进度
	if (comboBox->currentIndex() == 0)
	{
		//设置进度条的步长范围从0到需要复制的文件数目
		progressBar->setRange(0, num);
		for (int i = 1; i < num; ++i)
		{
			//模拟文件赋值过程，进度条需要为需要复制的文件总数目
			progressBar->setValue(i);
		}
	}
	//采用精度对话框显示进度
	else if(comboBox->currentIndex() == 1)
	{
		//创建一个进度对话框
		QProgressDialog* ProgressDialog = new QProgressDialog(this);
		QFont  font("ZYSong18030", 12);
		ProgressDialog->setFont(font);
		//设置采用模态方式显示，显示进度条的同时，其他窗口将不响应输入信号
		ProgressDialog->setWindowModality(Qt::WindowModal);
		//设置进度对话框出现需要等待的时间，默认为4s
		ProgressDialog->setMinimumDuration(5);
		//设置进度对话框的窗体标题
		ProgressDialog->setWindowTitle(tr("Please wait"));
		//设置进度对话框的显示文字信息
		ProgressDialog->setLabelText(tr("Copying..."));
		//设置进度对话框的取消按钮
		ProgressDialog->setCancelButtonText(tr("Cannel"));
		//设置进度条的不仅范围
		ProgressDialog->setRange(0, num);
		for (int i = 1; i < num; ++i)
		{
			ProgressDialog->setValue(i);
			if (ProgressDialog->wasCanceled())
			{
				return;
			}
		}

	}
}

ProgressDlg::~ProgressDlg()
{
}
