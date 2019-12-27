#include "msgBoxDlg.h"

MsgBoxDlg::MsgBoxDlg(QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle(tr("��׼��Ϣ�Ի���"));
	label = new QLabel(tr("��ѡ��һ����Ϣ��"));
	
	questioBtn = new QPushButton(tr("QuestionMsg"));
	informtionBtn = new QPushButton(tr("InformationMsg"));
	warningBtn = new QPushButton(tr("WaringMsg"));
	criticalBtn = new QPushButton(tr("CriticalBtn"));
	aboutQtBtn = new QPushButton(tr("AboutQtBtn"));
	aboutBtn = new QPushButton(tr("AboutBtn"));


	//����
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(label, 0, 0, 1, 2);
	mainLayout->addWidget(questioBtn, 1, 0);
	mainLayout->addWidget(informtionBtn, 1, 1);
	mainLayout->addWidget(warningBtn, 2, 0);
	mainLayout->addWidget(criticalBtn, 2, 1);
	mainLayout->addWidget(aboutBtn, 3, 0);
	mainLayout->addWidget(aboutQtBtn, 3, 1);

	//�¼�����
	connect(questioBtn, &QPushButton::clicked, this, &MsgBoxDlg::showQuestionMsg);
	connect(informtionBtn, &QPushButton::clicked, this, &MsgBoxDlg::showInformationMsg);
	connect(warningBtn, &QPushButton::clicked, this, &MsgBoxDlg::showInformationMsg);
	connect(criticalBtn, &QPushButton::clicked, this, &MsgBoxDlg::showCriticalMsg);
	connect(aboutQtBtn, &QPushButton::clicked, this, &MsgBoxDlg::showAboutQtMsg);
	connect(aboutBtn, &QPushButton::clicked, this, &MsgBoxDlg::showAboutMsg);

}

MsgBoxDlg::~MsgBoxDlg()
{
}

void MsgBoxDlg::showQuestionMsg()
{
	label->setText(tr("Question Message Box"));
	switch (QMessageBox::question(this, tr("Question��Ϣ�Ի���"),
		tr("�޸�����Ƿ񱣴����"),
		QMessageBox::Cancel | QMessageBox::Ok, QMessageBox::Ok))
		//���һ��������Ĭ�ϰ�ť�� ����Ϣ����֣�Ĭ�����Ǹ���ť���棬�����ڶ�����������ʾ
		//��Ϣ����ֵİ�ť
	{
	case QMessageBox::Ok:
		label->setText("Question Button/Ok");
		break;

	case QMessageBox::Cancel:
		label->setText("Question Button/Cannel");
		break;

	default:
		break;
	}
	return;
}

void MsgBoxDlg::showInformationMsg()
{
	label->setText(tr("Information Message Box"));
	QMessageBox::information(this, tr("Information ��Ϣ��"), tr("��Ϣ�߻�ʦ��"));

	return;
}

void MsgBoxDlg::showWarningMsg()
{
	label->setText("Warning Message Box");
	switch (QMessageBox::warning(this, tr("Warning��Ϣ��"), tr("���Ƿ񱣴��޸ĵ���Ϣ��"),
		QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
		QMessageBox::Save))
	{
	case QMessageBox::Save:
		label->setText(tr("warning button/Save"));
		break;

	case QMessageBox::Discard:
		label->setText(tr("warning button/Discard"));
		break;
	default:
		break;
	}
	return;
}

void MsgBoxDlg::showCriticalMsg()
{
	label->setText(tr("Critical Message Box"));
	QMessageBox::critical(this, tr("Critical��Ϣ��"),
		tr("����һ��Critical��Ϣ���Կ�"));
	return;

}

void MsgBoxDlg::showAboutMsg()
{
	label->setText(tr("About Message Box"));
	QMessageBox::about(this, tr("About��Ϣ��"), tr("����һ��About��Ϣ����ԣ�"));
	return;

}
	
void MsgBoxDlg::showAboutQtMsg()
{
	label->setText(tr("About Qt Message Box"));
	QMessageBox::aboutQt(this, tr("About Qt��Ϣ��"));
	return;
}


