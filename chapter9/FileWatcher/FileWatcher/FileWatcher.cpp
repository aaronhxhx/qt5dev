#include "FileWatcher.h"

FileWatcher::FileWatcher(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QStringList args = qApp->arguments();
	QString path;
	if (args.count() > 1)
	{
		path = args[1];
	}
	else
	{
		path = QDir::currentPath();
	}
	
	pathLabel = new QLabel(QStringLiteral("监视的目录") + path);
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(pathLabel);
	fsWattcher.addPath(path);
	connect(&fsWattcher, &QFileSystemWatcher::directoryChanged, this, &FileWatcher::slotDirectoryChange);


}

FileWatcher::~FileWatcher()
{
}

void FileWatcher::slotDirectoryChange(QString path)
{
	QMessageBox::information(NULL, QStringLiteral("目录发生改变"), path);
}