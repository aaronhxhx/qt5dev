#include "ItemWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ItemWidget w;
	w.show();
	return a.exec();
}
