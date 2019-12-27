#include "Palettte.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Palettte w;
	w.show();
	return a.exec();
}
