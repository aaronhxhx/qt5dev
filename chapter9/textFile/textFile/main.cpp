#include <QtCore/QCoreApplication>
#include <QFile>
#include <QtDebug>
#include <QDir>
#include <QTextStream>
#include "mainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QString path;

	qDebug() << QDir::currentPath();

	QFile data("test.txt");
	if (data.open(QFile::WriteOnly|QFile::Truncate))
	{
		QTextStream out(&data);
		out << QStringLiteral("ÄãºÃ") << qSetFieldWidth(10) << QObject::tr("get")
			<< left << 90 << endl;

		char buffer[2048];
		qint64 lintLen = data.readLine(buffer, sizeof(buffer));

		if (lintLen != -1)
		{
			qDebug() << buffer;
		}
	}
	else
	{
		qDebug() << "open fail 1";
	}
	data.close();
	if (data.open(QIODevice::ReadOnly))
	{
		char buffer[2048];
		qint64 lintLen = data.readLine(buffer, sizeof(buffer));

		if (lintLen != -1)
		{
			qDebug() << buffer;
		}
		else
		{
			qDebug() << "null";
		}
	}
	else
	{
		qDebug() << "open fail";
	}
	data.close();

	mainWindow w;
	w.show();
	return a.exec();
}
