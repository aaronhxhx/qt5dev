#include "MyQQExample.h"
#include "driver.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//MyQQExample w;
	Driver driver;
	driver.show();
	//w.show();
	return a.exec();
}
