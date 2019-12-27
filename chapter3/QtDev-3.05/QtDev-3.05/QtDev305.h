#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtDev305.h"
#include "detail.h"
#include "contact.h"
#include "baseInfo.h"
#include <QPushButton>
#include <QStackedWidget>
#include<QFrame>


class QtDev305 : public QWidget
{
	Q_OBJECT

public:
	QtDev305(QWidget *parent = Q_NULLPTR);
	~QtDev305();
	QStackedWidget* stack;
	QPushButton* AmendBtn;
	QPushButton* CloseBtn;
	BaseInfo* baseInfo;
	Contact* contact;
	Detail* detail;

private:
	Ui::QtDev305Class ui;
};
