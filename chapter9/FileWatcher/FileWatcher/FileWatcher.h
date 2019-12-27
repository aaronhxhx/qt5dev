#pragma once

#include <QtWidgets/QWidget>
#include "ui_FileWatcher.h"
#include <QLabel>
#include <QFileSystemWatcher>
#include <QVBoxLayout>
#include <QDir>
#include <QMessageBox>
#include <QApplication>

class FileWatcher : public QWidget
{
	Q_OBJECT

public:
	FileWatcher(QWidget *parent = Q_NULLPTR);
	~FileWatcher();

public slots:
	void slotDirectoryChange(QString path);

private:
	Ui::FileWatcherClass ui;
	QLabel* pathLabel;
	QFileSystemWatcher fsWattcher;
};
