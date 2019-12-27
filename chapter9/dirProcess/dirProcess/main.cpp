//得到一个文件大小
//及其所在目录的路径

#include <QtCore/QCoreApplication>
#include <QStringList>
#include <QDir>
#include <QtDebug>

qint64 read(const QString &path)
{
	QDir dir(path);
	qint64 size = 0;
	foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files))
	{
		size += fileInfo.size();
	}
	foreach(QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
	{
		size += read(path + QDir::separator() + subDir);
	}
	char unit = 'B';
	qint64 cursize = size;
	if (cursize >= 1024)
	{
		cursize /= 1024;
		unit = 'K';
		if (cursize >= 1024)
		{
			cursize /= 1024;
			unit = 'M';
			if (cursize >= 1024)
			{
				cursize /= 1024;
				unit = 'G';
			}
		}
	}
	qDebug() << cursize << unit << "\t" << qPrintable(path) << endl;
	return size;
}


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QStringList args = a.arguments();
	QString path;
	if (args.count() > 1)
	{
		path = args[1];
	}
	else
	{
		path = QDir::currentPath();
	}
	qDebug() << path << endl;
	read(path);
	return a.exec();
}
