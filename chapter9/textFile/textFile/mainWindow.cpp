#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	fileFun();
}

mainWindow::~mainWindow()
{
}
void mainWindow::fileFun()
{
	QFile file("binary.dat");
	
	file.open(QIODevice::WriteOnly | QIODevice::Truncate);

	//
	QDataStream out(&file);
	out << QStringLiteral("������");
	out << QDate::fromString("1996/09/25", "yyyy/MM/dd");
	out << (qint32)24;

	/*���ļ���ȡ����*/
	file.setFileName("binary.dat");
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "error";
		return;
	}
	QDataStream in(&file);
	QString name;
	QDate birthday;
	qint32 age;
	in >> name >> birthday >> age;
	qDebug() << name << birthday << age;
	file.close();
}
