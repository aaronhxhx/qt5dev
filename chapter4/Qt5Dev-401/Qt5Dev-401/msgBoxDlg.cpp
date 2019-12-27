#include "msgBoxDlg.h"

MsgBoxDlg::MsgBoxDlg(QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle(tr("标准消息对话框"));
	label = new QLabel(tr("请选择一种消息框"));
	
	questioBtn = new QPushButton(tr("QuestionMsg"));
	informtionBtn = new QPushButton(tr("InformationMsg"));
	warningBtn = new QPushButton(tr("WaringMsg"));
	criticalBtn = new QPushButton(tr("CriticalBtn"));
	aboutQtBtn = new QPushButton(tr("AboutQtBtn"));
	aboutBtn = new QPushButton(tr("AboutBtn"));


	//布局
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(label, 0, 0, 1, 2);
	mainLayout->addWidget(questioBtn, 1, 0);
	mainLayout->addWidget(informtionBtn, 1, 1);
	mainLayout->addWidget(warningBtn, 2, 0);
	mainLayout->addWidget(criticalBtn, 2, 1);
	mainLayout->addWidget(aboutBtn, 3, 0);
	mainLayout->addWidget(aboutQtBtn, 3, 1);

	//事件关联
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
	switch (QMessageBox::question(this, tr("Question消息对话框"),
		tr("修改完成是否保存程序"),
		QMessageBox::Cancel | QMessageBox::Ok, QMessageBox::Ok))
		//最后一个参数是默认按钮， 即消息框出现，默认在那个按钮上面，倒数第二个参数是显示
		//消息框出现的按钮
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
	QMessageBox::information(this, tr("Information 消息框"), tr("消息策划师框"));

	return;
}

void MsgBoxDlg::showWarningMsg()
{
	label->setText("Warning Message Box");
	switch (QMessageBox::warning(this, tr("Warning消息框"), tr("您是否保存修改的信息！"),
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
	QMessageBox::critical(this, tr("Critical消息框"),
		tr("这是一个Critical消息测试框"));
	return;

}

void MsgBoxDlg::showAboutMsg()
{
	label->setText(tr("About Message Box"));
	QMessageBox::about(this, tr("About消息框"), tr("这是一个About消息框测试！"));
	return;

}
	
void MsgBoxDlg::showAboutQtMsg()
{
	label->setText(tr("About Qt Message Box"));
	QMessageBox::aboutQt(this, tr("About Qt消息框"));
	return;
}


