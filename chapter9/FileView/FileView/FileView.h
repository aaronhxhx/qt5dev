#pragma once

#include <QtWidgets/QDialog>
#include "ui_FileView.h"
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDir>
#include <QListWidgetItem>
#include <QFileInfoList>
#include <QStringList>
#include <QIcon>

class FileView : public QDialog
{
	Q_OBJECT

public:
	FileView(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f= 0);
	~FileView();

	void showFileInfoList(QFileInfoList list);

public slots:
	void slotShow(/*QDir dir*/);
	void slotDirShow(QListWidgetItem* item);

private:
	Ui::FileViewClass ui;
	QLineEdit* fileLineEdit;
	QListWidget* fileListWidget;
	QVBoxLayout* mainLayout;
};
