#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include "macro.h"
#include <QMessageBox>

class MsgBoxDlg : public QWidget
{
	Q_OBJECT

public:
	MsgBoxDlg(QWidget *parent = 0);
	~MsgBoxDlg();


private slots:
	void showQuestionMsg();
	void showInformationMsg();
	void showWarningMsg();
	void showCriticalMsg();
	void showAboutMsg();
	void showAboutQtMsg();



private:
	QLabel* label;
	QPushButton* questioBtn;
	QPushButton* informtionBtn;
	QPushButton* criticalBtn;
	QPushButton* warningBtn;
	QPushButton* aboutBtn;
	QPushButton* aboutQtBtn;
	QGridLayout* mainLayout;

};
