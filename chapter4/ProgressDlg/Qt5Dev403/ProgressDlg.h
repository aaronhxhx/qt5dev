#pragma once

#include <QtWidgets/QWidget>
#include "ui_ProgressDlg.h"
#include "macro.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QProgressBar>
#include <QProgressDialog>
#include <QFont>

class ProgressDlg : public QWidget
{
	Q_OBJECT

public:
	ProgressDlg(QWidget *parent = Q_NULLPTR);
	~ProgressDlg();

private slots:
	void startProgress();

private:
	Ui::ProgressDlgClass ui;
	QLabel* fileNum;
	QLineEdit* fileNumLineEdit;
	QLabel* ProgressType;
	QComboBox* comboBox;
	QProgressBar* progressBar;
	QPushButton* startBtn;
	QGridLayout* mainLayout;
};
