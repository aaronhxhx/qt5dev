#include "QtDev305.h"
#include <QtWidgets/QApplication>
#include <QSplitter>
#include <QListWidget>
#include <QTextCodec>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFont font("AR Pl KaitiM GB", 12);
	a.setFont(font);

	//新建一个水平分割窗口对象，作为主布局框
	QSplitter* splitterMain = new QSplitter(Qt::Horizontal, 0);
	splitterMain->setOpaqueResize(true);				//
	QListWidget* list = new QListWidget(splitterMain);	//
	list->insertItem(0, QObject::tr("基本信息"));
	list->insertItem(1, QObject::tr("联系方式"));
	list->insertItem(2, QObject::tr("详细资料"));

	QtDev305* content = new QtDev305(splitterMain);
	QObject::connect(list, SIGNAL(currentRowChanged(int)), content->stack, SLOT(setCurrentIndex(int)));

	//设置主布局框即水平分割窗口的标题
	splitterMain->setWindowTitle(QObject::tr("修改用户资料"));

	//设置主布局框即水平分割窗口的最小尺寸
	splitterMain->setMinimumSize(splitterMain->minimumSize());
	//设置主布局框即水平分割窗口的最大尺寸
	splitterMain->setMaximumSize(splitterMain->maximumSize());
	//显示主布局
	splitterMain->show();


	//QtDev305 w;
	//w.show();
	return a.exec();
}
