#include "PaintEx.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PaintEx w;
	w.show();
	return a.exec();
}
