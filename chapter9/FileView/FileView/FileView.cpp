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
	QString str = item->text();			//将下一级的目录名保存在str中
	QDir dir;							//定义一个QDir对象
	dir.setPath(fileLineEdit->text());  //设置QDir对象的路径为当前目录路径
	dir.cd(str);                        //根据下一级目录名重新设置QDir对象的路径
	fileLineEdit->setText(dir.absolutePath());	//(a)
	//slotShow(dir);						//显示当前目录下的所有文件
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
	//清空控件列表
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
