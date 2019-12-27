#include "DirModeEx.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QDirModel>
#include <QTreeView>
#include <QTableView>
#include <QListView>
#include <QSplitter>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QDirModel model;
	//新建三宗不同的对象
	QTreeView tree;
	QListView list;
	QTableView table;
	tree.setModel(&model);
	list.setModel(&model);
	table.setModel(&model);
	tree.setSelectionMode(QAbstractItemView::MultiSelection);
	list.setSelectionMode(tree.selectionMode());
	table.setSelectionMode(tree.selectionMode());
	QObject::connect(&tree, &QTreeView::doubleClicked, &list, &QListView::setRootIndex);
	QObject::connect(&tree, &QTreeView::doubleClicked, &table, &QTableView::setRootIndex);
	
	QSplitter *splitter = new QSplitter;
	splitter->addWidget(&tree);
	splitter->addWidget(&list);
	splitter->addWidget(&table);
	splitter->setWindowTitle(QObject::tr("Model/View"));
	splitter->show();





	//DirModeEx w;
	//w.show();
	return a.exec();
}
