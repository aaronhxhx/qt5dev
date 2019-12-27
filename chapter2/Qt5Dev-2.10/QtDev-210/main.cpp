#include "QtDev210.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtDev210 w;
	w.show();
	return a.exec();
}
