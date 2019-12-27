#pragma once

#include <QtWidgets/QDialog>
#include "ui_QFileInfo.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDateTime>

class FileInfo : public QDialog
{
	Q_OBJECT

public:
	FileInfo(QWidget *parent = nullptr, Qt::WindowFlags f = 0);
	~FileInfo();

public slots:
	void slotFile();
	void slotGet();

private:
	Ui::QFileInfoClass ui;
	QLabel* fileNameLabel;
	QLineEdit* fileNameLineEdit;
	QPushButton* fileButton;
	QLabel* sizeLabel;
	QLineEdit* sizeLineEdit;
	QLabel* createTimeLabel;
	QLineEdit* createTimeLineEdit;
	QLabel* lastModitifiedLabel;
	QLineEdit* lastModitifidiedLineEdit;
	QLabel* lastReadLabel;
	QLineEdit* lastReadLineEdit;
	QLabel* propertyLabel;
	QCheckBox* isDirCheckBox;
	QCheckBox* isFileCheckBox;
	QCheckBox* isSymLinkCheckBox;
	QCheckBox* isHiddenCheckBox;
	QCheckBox* isReadCheckBox;
	QCheckBox* isWriteCheckBox;
	QCheckBox* isExcutableCheckBox;
	QPushButton* getBtn;
};
