#include "Qt5Dev304.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::addLibraryPath("./plugins");//��ӿ⣬��������������ַ�����
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	//QTextCodec::setCodecForCString(QTextCodec::codecForName("GBK"));
	//QTextCodec::setCodecForLocale();
	Qt5Dev304 w;
	w.show();
	return a.exec();
}


