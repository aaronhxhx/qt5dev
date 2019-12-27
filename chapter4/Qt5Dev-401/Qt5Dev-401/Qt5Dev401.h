#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qt5Dev401.h"
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include "inputdlg.h"
#include "msgboxdlg.h"
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
//#include "macro.h"

class Qt5Dev401 : public QWidget
{
	Q_OBJECT

public:
	Qt5Dev401(QWidget *parent = Q_NULLPTR);
	~Qt5Dev401();
private:
	QPushButton *fileBtn;
	QLineEdit *fileLineEdit;
	QGridLayout *mainLayout;
	QPushButton *colorBtn;
	QFrame *colorFrame;
	QPushButton *fontBtn;
	QLineEdit *fontLineEdit;
	QPushButton *inputBtn;
	inputDlg* InputDlg;
	QPushButton  *MsgBtn;
	MsgBoxDlg *msgDlg;
	QPushButton *CustomBtn;
	QLabel *label;
private slots:
	void showFile();
	void showColor();
	void showFont();
	void showInputDlg();
	void showMsgDlg();
	void showCustomDlg();

private:
	Ui::Qt5Dev401Class ui;
};
