#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PaintEx.h"
#include "macro.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QGradient>
#include <QColorDialog>
#include "Paintarea.h"

class PaintEx : public QMainWindow
{
	Q_OBJECT

public:
	PaintEx(QWidget *parent = Q_NULLPTR);
	~PaintEx();

private:
	Ui::PaintExClass ui;
	Paintarea* paintArea;
	QLabel* shapeLabel;
	QComboBox* shapeComboBox;
	QLabel* penWidthLabel;
	QSpinBox* penWidthSpinBox;
	QLabel* penColorLabel;
	QFrame *penColorFrame;
	QPushButton *penColorBtn;
	QLabel *penStyleLabel;
	QComboBox *penStyleComboBox;
	QLabel *penCapLabel;
	QComboBox *penCapComboBox;
	QLabel *penJoinLabel;
	QComboBox *penJoinComboBox;
	QLabel *fillRuleLabel;
	QComboBox *fillRuleComboBox;
	QLabel *spreadLabel;
	QComboBox *spreadComboBox;
	QGradient::Spread spread;					//½¥±ä
	QLabel *brushStyleLabel;
	QComboBox *brushStyleComboBox;
	QLabel *brushColorLabel;
	QFrame *brushColorFrame;
	QPushButton *brushColorBtn;
	QGridLayout *rightLayout;

protected slots:
	void ShowShape(int);
	void ShowPenWidth(int);
	void ShowPenCdolor();
	void ShowPenStyle(int);
	void ShowPenCap(int);
	void ShowPenJion(int);
	void ShowSpreadStyle();
	void ShowFillRule();
	void ShowBrushColor();
	void ShowBrush(int);

};
