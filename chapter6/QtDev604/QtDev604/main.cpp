#include "SVGTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SVGTest w;
	w.show();
	return a.exec();
}
