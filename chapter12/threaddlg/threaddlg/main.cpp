#include "threadDlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ThreadDlg w;
	w.show();
	return a.exec();
}
