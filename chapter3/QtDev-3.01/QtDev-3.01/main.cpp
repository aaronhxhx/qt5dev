#include "QtDev301.h"
#include <QtWidgets/QApplication>
#include <QDockWidget>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtDev301 w;

	//指定显示字体
	QFont font("ZYSong18030", 12);
	a.setFont(font);

	//主分割窗口
	QSplitter* splitterMain = new QSplitter(Qt::Horizontal, 0);								//新建一个QSplitter对象作为主分割窗口，设定此分割窗口为水平分割窗口
	QTextEdit* textLeft = new QTextEdit(QObject::tr("left widget"), splitterMain);			//新建一个QTextEdit对象，并将其插入主分割窗口中
	textLeft->setAlignment(Qt::AlignCenter);												//设定TextEdit的文字对齐方式：AlignLeft左对齐，AlignRight右对齐，AlignCenter
																							//居中对齐，Alignup顶端对齐，AlignButton底端对齐

	//右分割窗口
	QSplitter* splitterRight = new QSplitter(Qt::Vertical, splitterMain);					//新建一个QSplitter对象作为右分割窗口，设为垂直分割，以主窗体作为父窗口
	splitterRight->setOpaqueResize(false);													//设定分割窗口分割条在拖拽时是否实时更新显示，true为实时
	QTextEdit* textTop = new QTextEdit(QObject::tr("top widget"), splitterRight);
	textTop->setAlignment(Qt::AlignCenter);

	//右下窗口
	QTextEdit* textButton = new QTextEdit(QObject::tr("button widget"), splitterRight);
	textButton->setAlignment(Qt::AlignCenter);
	splitterMain->setStretchFactor(1, 1);													//设定可伸缩控件，第一个参数指定控件的序号指定（序号按先后的插入顺序，
																							//第二个参数大于0，表示可伸缩控件

	//QDockWidget* dock = new QDockWidget();
	//dock->setWidget(splitterMain);
	

	splitterMain->setWindowTitle(QObject::tr("splitter"));
	splitterMain->show();

	w.show();
	return a.exec();
}
