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
	//实现基本对话框窗体部分
	void createBaseInfo();
	//实现扩展窗体部分
	void createDetailInfo();
	//基本对话窗体部分
	QWidget* baseWidget;
	//扩展窗体部分
	QWidget* detailWidget;

private:
	Ui::ExtensionDlgClass ui;
};
