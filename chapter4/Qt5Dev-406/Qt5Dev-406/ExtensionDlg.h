#pragma once

#include <QtWidgets/QWidget>
#include "ui_ExtensionDlg.h"
#include "macro.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>

class ExtensionDlg : public QWidget
{
	Q_OBJECT

public:
	ExtensionDlg(QWidget *parent = Q_NULLPTR);
private:
	void showDetailInfo();

private:
	//ʵ�ֻ����Ի����岿��
	void createBaseInfo();
	//ʵ����չ���岿��
	void createDetailInfo();
	//�����Ի����岿��
	QWidget* baseWidget;
	//��չ���岿��
	QWidget* detailWidget;

private:
	Ui::ExtensionDlgClass ui;
};
