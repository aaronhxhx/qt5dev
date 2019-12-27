#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "macro.h"
#include <QToolBar>
#include <QToolButton>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QColorDialog>
#include "DrawWidget.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	void createToolBar();

public slots:
	void ShowStyle();
	void ShowColor();

private:
	DrawWidget* drawWidget;
	QLabel* styleLabel;
	QComboBox* styleComboBox;
	QLabel* widthLabel;
	QSpinBox* widthSpinBox;
	QToolButton* colorBtn;
	QToolButton* clearBtn;
	Ui::MainWindowClass ui;
};
