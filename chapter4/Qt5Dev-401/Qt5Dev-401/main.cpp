#include "Qt5Dev401.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Qt5Dev401 w;
	w.show();
	return a.exec();
}
