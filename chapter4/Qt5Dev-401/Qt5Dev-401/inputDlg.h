#pragma once

#include <macro.h>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QInputDialog>

class inputDlg : public QWidget
{
	Q_OBJECT

public:
	inputDlg(QWidget *parent = 0);
	~inputDlg();

private slots:
	void ChangeName();
	void ChangeSex();
	void ChangeAge();
	void ChangeScore();
private:
	QLabel *nameLabel1;
	QLabel *sexLabel1;
	QLabel *ageLabel1;
	QLabel *scoreLabel1;
	QLabel *nameLabel2;
	QLabel *sexLabel2;
	QLabel *ageLabel2;
	QLabel *scoreLabel2;
	QPushButton *nameBtn;
	QPushButton *sexBtn;
	QPushButton *ageBtn;
	QPushButton *scoreBtn;
	QGridLayout *mainLayout;

};
