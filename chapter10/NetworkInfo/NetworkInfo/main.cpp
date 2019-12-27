#include "NetworkInfo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NetworkInfo w;
	w.show();
	return a.exec();
}
