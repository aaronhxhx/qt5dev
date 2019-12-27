#pragma once

#include <QtWidgets/QWidget>
#include "ui_Palettte.h"
#include "macro.h"
#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>


class Palettte : public QWidget
{
	Q_OBJECT

public:
	Palettte(QWidget *parent = Q_NULLPTR);
	~Palettte();
	void createCtriFrame();
	void createContentFrame();
	void fillCorlorList(QComboBox*);

private slots:
	void ShowWindow();
	void ShowWindowText();
	void ShowButtonText();
	void ShowButton();
	void ShowBase();

private:
	QFrame* ctrlFrame;
	QLabel* windowLabel;
	QComboBox* windowComboBox;
	QLabel* windowTextLabel;
	QComboBox* windowTextComboBox;
	QLabel* buttonLabel;
	QComboBox* buttonComboBox;
	QLabel* buttonTextLabel;
	QComboBox* buttonTextComboBox;
	QLabel* baseLabel;
	QComboBox* baseComboBox;

	QFrame* ContentFrame;
	QLabel* Label1;
	QComboBox* comboBox1;
	QLabel* Label2;
	QLineEdit* lineEdit2;
	QTextEdit* textEdit;
	QPushButton* okBtn;
	QPushButton* cancelBtn;

	Ui::PalettteClass ui;
};
