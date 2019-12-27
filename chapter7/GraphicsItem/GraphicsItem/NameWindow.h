#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NameWindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenuBar>
#include <QGraphicsEllipseItem>
#include "FlashItem.h"
#include "StartItem.h"

class NameWindow : public QMainWindow
{
	Q_OBJECT

public:
	NameWindow(QWidget *parent = Q_NULLPTR);
	~NameWindow();
	void initScene();
	void createActions();
	void createMenus();

public:
	void slotNew();				//新建一个显示窗体
	void slotClear();			//清除场景中所有图元
	void slotAddEllipseItem();	//
	void slotAddPloygonItem();	//
	void slotAddTextItem();		//
	void slotAddRectItem();		//
	void slotAddAlphaItem();	//
	void slotAddFlashItem();
	void slotAddAnimationItem();

private:
	Ui::NameWindowClass ui;
	QGraphicsScene* scene;
	QAction* newAct;
	QAction* clearAct;
	QAction* exitAct;
	QAction* addEllipseItemAct;
	QAction* addPolygonItemAct;
	QAction* addTextItemAct;
	QAction* addRectItemAct;
	QAction* addAlphaItemAct;
	QAction* addFlashItemAct;
	QAction* addAnimItemAct;
};
