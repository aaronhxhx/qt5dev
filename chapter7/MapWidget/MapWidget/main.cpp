#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include "mapWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//MainWindow w;
	//w.show();
	QFont font("ARPL KaitiM GB", 12);
	font.setBold(true);
	a.setFont(font);
	MapWidget mapWidget;
	mapWidget.show();
	return a.exec();
}
