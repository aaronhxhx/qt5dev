#include "SplashScreen.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QPixmap pixmap(":/QSplashScreen/Resources/image.jpg");
	pixmap = pixmap.scaled(QSize(40, 40));
	QSplashScreen splash(pixmap);
	splash.show();
	a.processEvents();
	SplashScreen w;
	w.show();
	splash.finish(&w);

	return a.exec();
}
