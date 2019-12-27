#include "QFileInfo.h"

FileInfo::FileInfo(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	ui.setupUi(this);
	fileNameLabel = new QLabel(QStringLiteral("�ļ�����"));
	fileNameLineEdit = new QLineEdit;
	fileButton = new QPushButton(QStringLiteral("�ļ�"));

	sizeLabel = new QLabel(QStringLiteral("��С��"));
	sizeLineEdit = new QLineEdit;

	createTimeLabel = new QLabel(QStringLiteral("����ʱ��: "));
	createTimeLineEdit = new QLineEdit;

	lastModitifiedLabel = new QLabel(QStringLiteral("����޸�ʱ�䣺"));
	lastModitifidiedLineEdit = new QLineEdit;

	lastReadLabel = new QLabel(QStringLiteral("������ʱ�䣺"));
	lastReadLineEdit = new QLineEdit;

	propertyLabel = new QLabel(QStringLiteral("����"));
	isDirCheckBox = new QCheckBox(QStringLiteral("Ŀ¼"));
	isFileCheckBox = new QCheckBox(QStringLiteral("�ļ�"));
	isSymLinkCheckBox = new QCheckBox(QStringLiteral("��������"));
	isHiddenCheckBox = new QCheckBox(QStringLiteral("����"));
	isReadCheckBox = new QCheckBox(QStringLiteral("��"));
	isWriteCheckBox = new QCheckBox(QStringLiteral("д"));
	isExcutableCheckBox = new QCheckBox(QStringLiteral("ִ��"));

	getBtn = new QPushButton(QStringLiteral("����ļ���Ϣ"));

	//����
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
	QString fileName = QFileDialog::getOpenFileName(this, "��", "/", "file(*)");
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

	//�ж�QFileInfo������ļ���������
	bool isDir = info.isDir();
	bool isFile = info.isFile();
	bool isSymLink = info.isSymLink();
	bool isHidden = info.isHidden();
	bool isReadable = info.isReadable();
	bool isWritable = info.isWritable();
	bool isExcutable = info.isExecutable();

	//������������Ը�������
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