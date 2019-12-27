#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt5Dev209.h"
#include <QTreeWidgetItem>

class Qt5Dev209 : public QMainWindow
{
	Q_OBJECT

public:
	Qt5Dev209(QWidget *parent = Q_NULLPTR);
	void init();
	void updateParentItem(QTreeWidgetItem * item);

public slots:
	void treeItemChanged(QTreeWidgetItem* item, int column);

private:
	Ui::Qt5Dev209Class ui;
};
