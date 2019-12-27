#pragma once

#include "macro.h"
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QImage>
#include <QHBoxLayout>

class ShowWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ShowWidget(QWidget *parent = nullptr);
	~ShowWidget();
	QImage img;
	QLabel *imageLabel;
	QTextEdit* text;
	QHBoxLayout* mainLayout;
signals:

public slots:

private:
	

};
