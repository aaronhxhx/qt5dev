#include "QtDev305.h"
#include <QtWidgets/QApplication>
#include <QSplitter>
#include <QListWidget>
#include <QTextCodec>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFont font("AR Pl KaitiM GB", 12);
	a.setFont(font);

	//�½�һ��ˮƽ�ָ�ڶ�����Ϊ�����ֿ�
	QSplitter* splitterMain = new QSplitter(Qt::Horizontal, 0);
	splitterMain->setOpaqueResize(true);				//
	QListWidget* list = new QListWidget(splitterMain);	//
	list->insertItem(0, QObject::tr("������Ϣ"));
	list->insertItem(1, QObject::tr("��ϵ��ʽ"));
	list->insertItem(2, QObject::tr("��ϸ����"));

	QtDev305* content = new QtDev305(splitterMain);
	QObject::connect(list, SIGNAL(currentRowChanged(int)), content->stack, SLOT(setCurrentIndex(int)));

	//���������ֿ�ˮƽ�ָ�ڵı���
	splitterMain->setWindowTitle(QObject::tr("�޸��û�����"));

	//���������ֿ�ˮƽ�ָ�ڵ���С�ߴ�
	splitterMain->setMinimumSize(splitterMain->minimumSize());
	//���������ֿ�ˮƽ�ָ�ڵ����ߴ�
	splitterMain->setMaximumSize(splitterMain->maximumSize());
	//��ʾ������
	splitterMain->show();


	//QtDev305 w;
	//w.show();
	return a.exec();
}
