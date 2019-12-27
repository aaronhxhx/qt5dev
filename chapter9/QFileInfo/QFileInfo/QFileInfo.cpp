#include "QFileInfo.h"

FileInfo::FileInfo(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	ui.setupUi(this);
	fileNameLabel = new QLabel(QStringLiteral("文件名："));
	fileNameLineEdit = new QLineEdit;
	fileButton = new QPushButton(QStringLiteral("文件"));

	sizeLabel = new QLabel(QStringLiteral("大小："));
	sizeLineEdit = new QLineEdit;

	createTimeLabel = new QLabel(QStringLiteral("创建时间: "));
	createTimeLineEdit = new QLineEdit;

	lastModitifiedLabel = new QLabel(QStringLiteral("最后修改时间："));
	lastModitifidiedLineEdit = new QLineEdit;

	lastReadLabel = new QLabel(QStringLiteral("最后访问时间："));
	lastReadLineEdit = new QLineEdit;

	propertyLabel = new QLabel(QStringLiteral("属性"));
	isDirCheckBox = new QCheckBox(QStringLiteral("目录"));
	isFileCheckBox = new QCheckBox(QStringLiteral("文件"));
	isSymLinkCheckBox = new QCheckBox(QStringLiteral("符号连接"));
	isHiddenCheckBox = new QCheckBox(QStringLiteral("隐藏"));
	isReadCheckBox = new QCheckBox(QStringLiteral("读"));
	isWriteCheckBox = new QCheckBox(QStringLiteral("写"));
	isExcutableCheckBox = new QCheckBox(QStringLiteral("执行"));

	getBtn = new QPushButton(QStringLiteral("获得文件信息"));

	//布局
	QGridLayout* gridLayout = new QGridLayout;
	gridLayout->addWidget(fileNameLabel, 0, 0);
	gridLayout->addWidget(fileNameLineEdit, 0, 1);
	gridLayout->addWidget(fileButton, 0, 2);
	gridLayout->addWidget(sizeLabel, 1, 0);
	gridLayout->addWidget(sizeLineEdit, 1, 1, 1, 2);
	gridLayout->addWidget(createTimeLabel, 2, 0);
	gridLayout->addWidget(createTimeLineEdit, 2, 1, 1, 2);
	gridLayout->addWidget(lastModitifiedLabel, 3, 0);
	gridLayout->addWidget(lastModitifidiedLineEdit, 3, 1, 1, 2);
	gridLayout->addWidget(lastReadLabel, 4, 0);
	gridLayout->addWidget(lastReadLineEdit, 4, 1, 1, 2);
	
	QHBoxLayout* propertyLayout = new QHBoxLayout;
	propertyLayout->addWidget(propertyLabel);
	propertyLayout->addStretch();

	QHBoxLayout* checkBoxLayout = new QHBoxLayout;
	checkBoxLayout->addWidget(isDirCheckBox);
	checkBoxLayout->addWidget(isFileCheckBox);
	checkBoxLayout->addWidget(isSymLinkCheckBox);
	checkBoxLayout->addWidget(isHiddenCheckBox);
	checkBoxLayout->addWidget(isReadCheckBox);
	checkBoxLayout->addWidget(isWriteCheckBox);
	checkBoxLayout->addWidget(isExcutableCheckBox);

	QHBoxLayout* getBtnLayout = new QHBoxLayout;
	getBtnLayout->addWidget(getBtn);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addLayout(gridLayout);
	mainLayout->addLayout(propertyLayout);
	mainLayout->addLayout(checkBoxLayout);
	mainLayout->addLayout(getBtnLayout);

	connect(fileButton, &QPushButton::clicked, this, &FileInfo::slotFile);
	connect(getBtn, &QPushButton::clicked, this, &FileInfo::slotGet);


}



void FileInfo::slotFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, "打开", "/", "file(*)");
	fileNameLineEdit->setText(fileName);
}

FileInfo::~FileInfo()
{
}

void FileInfo::slotGet()
{
	QString file = fileNameLineEdit->text();
	QFileInfo info(file);
	qint64 size = info.size();

	QDateTime createdTime = info.created();
	QDateTime modifiedTime = info.lastModified();
	QDateTime readTime = info.lastRead();

	//判断QFileInfo对象的文件类型属性
	bool isDir = info.isDir();
	bool isFile = info.isFile();
	bool isSymLink = info.isSymLink();
	bool isHidden = info.isHidden();
	bool isReadable = info.isReadable();
	bool isWritable = info.isWritable();
	bool isExcutable = info.isExecutable();

	//根据上面的属性更新内容
	sizeLineEdit->setText(QString::number(size));
	createTimeLineEdit->setText(createdTime.toString());
	lastModitifidiedLineEdit->setText(modifiedTime.toString());
	lastReadLineEdit->setText(readTime.toString());
	isDirCheckBox->setCheckState(isDir ? Qt::Checked : Qt::Unchecked);
	isFileCheckBox->setCheckState(isFile ? Qt::Checked : Qt::Unchecked);
	isSymLinkCheckBox->setCheckState(isSymLink ? Qt::Checked : Qt::Unchecked);
	isHiddenCheckBox->setCheckState(isHidden ? Qt::Checked : Qt::Unchecked);
	isReadCheckBox->setCheckState(isReadable ? Qt::Checked : Qt::Unchecked);
	isWriteCheckBox->setCheckState(isWritable ? Qt::Checked : Qt::Unchecked);
	isExcutableCheckBox->setCheckState(isExcutable ? Qt::Checked : Qt::Unchecked);
	
}