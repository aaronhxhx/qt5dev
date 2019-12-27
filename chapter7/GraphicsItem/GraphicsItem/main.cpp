#include "NameWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NameWindow w;
	w.show();
	return a.exec();
}
