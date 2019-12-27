#include "FileView.h"


FileView::FileView(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("file view"));
	fileLineEdit = new QLineEdit(tr("/"));
	fileListWidget = new QListWidget;
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(fileLineEdit);
	mainLayout->addWidget(fileListWidget);
	connect(fileLineEdit, SIGNAL(returnPressed()), this, SLOT(slotShow()));
	//connect(fileLineEdit, &QLineEdit::returnPressed, this, &FileView::slotShow);
	connect(fileListWidget, QOverload<QListWidgetItem*>::of(&QListWidget::itemDoubleClicked), this, &FileView::slotDirShow);

	QString root = "/";
	QDir rootDir(root);
	QStringList string;
	string << "*";
	QFileInfoList list = rootDir.entryInfoList(string);
	showFileInfoList(list);
}

FileView::~FileView()
{
}

void FileView::slotDirShow(QListWidgetItem* item)
{
	QString str = item->text();			//����һ����Ŀ¼��������str��
	QDir dir;							//����һ��QDir����
	dir.setPath(fileLineEdit->text());  //����QDir�����·��Ϊ��ǰĿ¼·��
	dir.cd(str);                        //������һ��Ŀ¼����������QDir�����·��
	fileLineEdit->setText(dir.absolutePath());	//(a)
	//slotShow(dir);						//��ʾ��ǰĿ¼�µ������ļ�
}

void FileView::slotShow()
{
	QStringList string;
	string << "*";
	QDir dir(fileLineEdit->text());
	QFileInfoList list = dir.entryInfoList(string, QDir::AllEntries, QDir::DirsFirst);
	showFileInfoList(list);
}

void FileView::showFileInfoList(QFileInfoList list)
{
	//��տؼ��б�
	fileListWidget->clear();
	for (unsigned int i = 0; i < list.count(); i++)
	{
		QFileInfo tempFileInfo = list.at(i);
		if (tempFileInfo.isDir())
		{
			QIcon icon(":/Resources/dir.png");
			QString fileName = tempFileInfo.fileName();
			QListWidgetItem* temp = new QListWidgetItem(icon, fileName);
			fileListWidget->addItem(temp);
		}
		else if (tempFileInfo.isFile())
		{
			QIcon icon(":Resources/file.png");
			QString fileName = tempFileInfo.fileName();
			QListWidgetItem* temp = new QListWidgetItem(icon, fileName);
			fileListWidget->addItem(temp);
		}
		
	}
}
