#include "Qt5Dev304.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::addLibraryPath("./plugins");//添加库，下面代码是设置字符编码
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	//QTextCodec::setCodecForCString(QTextCodec::codecForName("GBK"));
	//QTextCodec::setCodecForLocale();
	Qt5Dev304 w;
	w.show();
	return a.exec();
}


