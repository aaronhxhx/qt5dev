#include "FileView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FileView w;
	w.show();
	return a.exec();
}
