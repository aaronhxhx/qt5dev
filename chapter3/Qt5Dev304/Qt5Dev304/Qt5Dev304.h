#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qt5Dev304.h"
#include <Qlabel>
#include <QTextEdit>
#include <QGridLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QFrame>
#include <QTextCodec>


//��ֹ��������
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

class Qt5Dev304 : public QWidget
{
	Q_OBJECT

public:
	Qt5Dev304(QWidget *parent = Q_NULLPTR);
	~Qt5Dev304();

private:

	//���
	QLabel* UserNameLabel;
	QLabel* NameLabel;
	QLabel* SexLabel;
	QLabel* DeparmentLabel;
	QLabel* AgeLabel;
	QLabel* OtherLabel;
	QLineEdit* UserNameLineEdit;
	QLineEdit* NameLinetEdit;
	QComboBox* SexComnoBox;
	QTextEdit* DepartmentTextEdit;
	QLineEdit* AgeLineEdit;
	QGridLayout* LeftLayout;


	//�Ҳ�
	QLabel* HeadLabel;
	QLabel* HeadIconLabel;
	QPushButton* UpdateHeadBtn;
	QHBoxLayout* TopRightLayout;
	QLabel* IntroductionLabel;
	QTextEdit* IntroductionTextEdit;
	QVBoxLayout* RightLayout;

	//�ײ�
	QPushButton* OkBtn;
	QPushButton* CancelBtn;
	QHBoxLayout* ButtonLayout;


private:
	Ui::Qt5Dev304Class ui;

	Q_SLOT void initImg();
};
