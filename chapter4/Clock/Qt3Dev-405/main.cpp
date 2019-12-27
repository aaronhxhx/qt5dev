#include "clock.h"
#include "DigiClock.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DigiClock w;
	w.show();
	return a.exec();
}
