#include "Qt5Dev401.h"

Qt5Dev401::Qt5Dev401(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("���ֱ�׼�Ի����ʵ��"));
	fileBtn = new QPushButton;                                    //�����ؼ�����ĳ�ʼ��
	fileBtn->setText(tr("�ļ���׼�Ի���ʵ��"));
	fileLineEdit = new QLineEdit;                                 //������ʾѡ����ļ���
	mainLayout = new QGridLayout(this);                           //�������
	mainLayout->addWidget(fileBtn, 0, 0);
	mainLayout->addWidget(fileLineEdit, 0, 1);
	connect(fileBtn, SIGNAL(clicked()), this, SLOT(showFile()));   //�¼�����

	colorBtn = new QPushButton;                                   //���������ؼ��Ķ���
	colorBtn->setText(tr("��ɫ��׼�Ի���ʵ��"));
	colorFrame = new QFrame;
	colorFrame->setFrameShape(QFrame::Box);
	colorFrame->setAutoFillBackground(true);
	mainLayout->addWidget(colorBtn, 1, 0);                        //�������
	mainLayout->addWidget(colorFrame, 1, 1);
	connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor())); //�¼�����

	fontBtn = new QPushButton;                                    //�����ؼ��Ķ���
	fontBtn->setText(tr("�����׼�Ի���ʵ��"));
	fontLineEdit = new QLineEdit;                                 //��ʾ���ĵ��ַ���
	fontLineEdit->setText(tr("Welcome!"));
	mainLayout->addWidget(fontBtn, 2, 0);                         //�������
	mainLayout->addWidget(fontLineEdit, 2, 1);
	connect(fontBtn, SIGNAL(clicked()), this, SLOT(showFont()));	//�¼�����

	inputBtn = new QPushButton;                                   //�����ؼ��Ķ���
	inputBtn->setText(tr("��׼����Ի���ʵ��"));
	mainLayout->addWidget(inputBtn, 3, 0);                        //�������
	connect(inputBtn, &QPushButton::clicked, this, &Qt5Dev401::showInputDlg);//�¼�����

	MsgBtn = new QPushButton;                                    //�����ؼ�����
	MsgBtn->setText(tr("��׼��Ϣ�Ի���ʵ��"));
	mainLayout->addWidget(MsgBtn, 3, 1);
	connect(MsgBtn, SIGNAL(clicked()), this, SLOT(showMsgDlg()));

	CustomBtn = new QPushButton;
	CustomBtn->setText(tr("�û��Զ�����Ϣ�Ի���ʵ��"));
	label = new QLabel;
	label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	mainLayout->addWidget(CustomBtn, 4, 0);
	mainLayout->addWidget(label, 4, 1);
	connect(CustomBtn, SIGNAL(clicked()), this, SLOT(showCustomDlg()));
}

Qt5Dev401::~Qt5Dev401()
{
}

void Qt5Dev401::showFile()
{
	QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/", "C++ files(*.cpp);;C files(*.c);;Head files(*.h)");
	fileLineEdit->setText(s);
}

void Qt5Dev401::showColor()
{
	QColor c = QColorDialog::getColor(Qt::blue);
	if (c.isValid())
	{
		colorFrame->setPalette(QPalette(c));
	}
}

void Qt5Dev401::showFont()
{
	bool ok;
	QFont f = QFontDialog::getFont(&ok);
	if (ok)
	{
		fontLineEdit->setFont(f);
	}
}

void Qt5Dev401::showInputDlg()
{
	InputDlg = new inputDlg();
	InputDlg->show();
}

void Qt5Dev401::showMsgDlg()
{
	msgDlg = new MsgBoxDlg();
	msgDlg->show();
}

void Qt5Dev401::showCustomDlg()
{
	label->setText(tr("Custom Message Box"));
	QMessageBox customMsgBox;
	customMsgBox.setWindowTitle(tr("�û��Զ�����Ϣ��"));	//������Ϣ��ı���
	QPushButton *yesBtn = customMsgBox.addButton(tr("Yes"), QMessageBox::ActionRole);	//(a)
	QPushButton *noBtn = customMsgBox.addButton(tr("No"), QMessageBox::ActionRole);
	QPushButton *cancelBtn = customMsgBox.addButton(QMessageBox::Cancel);
	//(b)
	customMsgBox.setText(tr("����һ���û��Զ�����Ϣ��!"));	//(c)
	customMsgBox.setIconPixmap(QPixmap("Qt.png"));		//(d)
	customMsgBox.exec();                                //��ʾ���Զ�����Ϣ��
	if (customMsgBox.clickedButton() == yesBtn)
		label->setText("Custom Message Box/Yes");
	if (customMsgBox.clickedButton() == noBtn)
		label->setText("Custom Message Box/No");
	if (customMsgBox.clickedButton() == cancelBtn)
		label->setText("Custom Message Box/Cancel");
	return;
}


