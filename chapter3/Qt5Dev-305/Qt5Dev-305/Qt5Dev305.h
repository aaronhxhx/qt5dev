#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qt5Dev305.h"
#include "detail.h"
#include "contact.h"
#include "baseInfo2.h"
#include <QPushButton>
#include <QStackedWidget>
#include<QFrame>


class Qt5Dev305 : public QWidget
{
	Q_OBJECT

public:
	Qt5Dev305(QWidget *parent = Q_NULLPTR);
	~Qt5Dev305();
	QStackedWidget* stack;
	QPushButton* AmendBtn;
	QPushButton* CloseBtn;
	BaseInfo2* baseInfo;
	Contact* contact;
	Detail* detail;

private:
	Ui::Qt5Dev305Class ui;
};
