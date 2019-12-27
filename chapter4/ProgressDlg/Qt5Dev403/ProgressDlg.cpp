#include "ProgressDlg.h"

ProgressDlg::ProgressDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QFont font("ZYSong18030", 12);
	setFont(font);
	setWindowTitle(tr("�ļ���Ŀ"));

	fileNum = new QLabel(tr("�ļ���Ŀ��"));
	fileNumLineEdit = new QLineEdit(tr("1000000"));

	ProgressType = new QLabel(tr("��ʾ���ͣ�"));
	 
	comboBox = new QComboBox;
	comboBox->addItem(tr("progressNar"));
	comboBox->addItem(tr("progressDialog"));

	progressBar = new QProgressBar;
	startBtn = new QPushButton(tr("��ʼ"));
	
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
	//��ȡ��ǰ��������ʽ��ʾ����
	int num = fileNumLineEdit->text().toInt(&ok);

	//���ý������ķ�ʽ��ʾ����
	if (comboBox->currentIndex() == 0)
	{
		//���ý������Ĳ�����Χ��0����Ҫ���Ƶ��ļ���Ŀ
		progressBar->setRange(0, num);
		for (int i = 1; i < num; ++i)
		{
			//ģ���ļ���ֵ���̣���������ҪΪ��Ҫ���Ƶ��ļ�����Ŀ
			progressBar->setValue(i);
		}
	}
	//���þ��ȶԻ�����ʾ����
	else if(comboBox->currentIndex() == 1)
	{
		//����һ�����ȶԻ���
		QProgressDialog* ProgressDialog = new QProgressDialog(this);
		QFont  font("ZYSong18030", 12);
		ProgressDialog->setFont(font);
		//���ò���ģ̬��ʽ��ʾ����ʾ��������ͬʱ���������ڽ�����Ӧ�����ź�
		ProgressDialog->setWindowModality(Qt::WindowModal);
		//���ý��ȶԻ��������Ҫ�ȴ���ʱ�䣬Ĭ��Ϊ4s
		ProgressDialog->setMinimumDuration(5);
		//���ý��ȶԻ���Ĵ������
		ProgressDialog->setWindowTitle(tr("Please wait"));
		//���ý��ȶԻ������ʾ������Ϣ
		ProgressDialog->setLabelText(tr("Copying..."));
		//���ý��ȶԻ����ȡ����ť
		ProgressDialog->setCancelButtonText(tr("Cannel"));
		//���ý������Ĳ�����Χ
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
