#include "textFile.h"
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QtDebug>
#include <QTextStream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QFile file(":/Resources/point.txt");
	QFile data(":/Resources/point.txt");
	if (data.open(QIODevice::WriteOnly| QFile::Truncate))
	{
		/*qDebug() << file.fileName();
		char buffer[2048];
		if (lineLen != -1)
		{
			qDebug() << buffer;1
		}
		qint64 lineLen = file.readLine(buffer, sizeof(buffer));*/

		QTextStream out(&data);
		out << QObject::tr("point") << qSetFieldWidth(10) << left << 90 << endl;
	}

	textFile w;
	w.show();
	return a.exec();
}
