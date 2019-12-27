#include "QSplashScreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSplashScreen w;
	w.show();
	return a.exec();
}
