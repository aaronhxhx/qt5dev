#pragma once

#include <QtWidgets/QDialog>
#include "ui_threadDlg.h"
#include <QPushButton>
#include <QThread>
#include <QHBoxLayout>
#include "WorkThread.h"


#define MAXSIZE 4							//定义线程的数目


class ThreadDlg : public QDialog
{
	Q_OBJECT

public:
	ThreadDlg(QWidget *parent = Q_NULLPTR);
	~ThreadDlg();

public slots:
	void slotStart();
	void slotStop();

private:
	Ui::ThreadDlgClass ui;
	QPushButton* startBtn;
	QPushButton* stopBtn;
	QPushButton* quitBtn;
	WorkThread* workThread[MAXSIZE];
};
