#include "QtDev301.h"
#include <QtWidgets/QApplication>
#include <QDockWidget>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtDev301 w;

	//ָ����ʾ����
	QFont font("ZYSong18030", 12);
	a.setFont(font);

	//���ָ��
	QSplitter* splitterMain = new QSplitter(Qt::Horizontal, 0);								//�½�һ��QSplitter������Ϊ���ָ�ڣ��趨�˷ָ��Ϊˮƽ�ָ��
	QTextEdit* textLeft = new QTextEdit(QObject::tr("left widget"), splitterMain);			//�½�һ��QTextEdit���󣬲�����������ָ����
	textLeft->setAlignment(Qt::AlignCenter);												//�趨TextEdit�����ֶ��뷽ʽ��AlignLeft����룬AlignRight�Ҷ��룬AlignCenter
																							//���ж��룬Alignup���˶��룬AlignButton�׶˶���

	//�ҷָ��
	QSplitter* splitterRight = new QSplitter(Qt::Vertical, splitterMain);					//�½�һ��QSplitter������Ϊ�ҷָ�ڣ���Ϊ��ֱ�ָ����������Ϊ������
	splitterRight->setOpaqueResize(false);													//�趨�ָ�ڷָ�������קʱ�Ƿ�ʵʱ������ʾ��trueΪʵʱ
	QTextEdit* textTop = new QTextEdit(QObject::tr("top widget"), splitterRight);
	textTop->setAlignment(Qt::AlignCenter);

	//���´���
	QTextEdit* textButton = new QTextEdit(QObject::tr("button widget"), splitterRight);
	textButton->setAlignment(Qt::AlignCenter);
	splitterMain->setStretchFactor(1, 1);													//�趨�������ؼ�����һ������ָ���ؼ������ָ������Ű��Ⱥ�Ĳ���˳��
																							//�ڶ�����������0����ʾ�������ؼ�

	//QDockWidget* dock = new QDockWidget();
	//dock->setWidget(splitterMain);
	

	splitterMain->setWindowTitle(QObject::tr("splitter"));
	splitterMain->show();

	w.show();
	return a.exec();
}
