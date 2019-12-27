#include "ImgProcessor.h"

ImgProcessor::ImgProcessor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("Easy word"));
	showWidget = new ShowWidget(this);
	//�������Ŀؼ�
	setCentralWidget(showWidget);
	//��ͬ��setCentralWidget(showWidget),��showWidget��Ϊ���Ĳ���
	/*�����˵�����״̬������������*/
	

	//�ڹ�������Ƕ��ؼ�
	//��������
	fontLabel1 = new QLabel(tr("����"));
	fontComboBox = new QFontComboBox;
	//
	fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
	fontLabel2 = new QLabel(tr("�ֺ�"));
	sizeComboBox = new QComboBox;
	QFontDatabase db;
	for (const auto& size : db.standardSizes())
	{
		sizeComboBox->addItem(QString::number(size));
	}

	//
	boldBtn = new QToolButton;
	boldBtn->setIcon(QIcon(":/Resources/bold.png"));
	boldBtn->setCheckable(true);

	italicBtn = new QToolButton;
	italicBtn->setIcon(QIcon(":Resources/italic.png"));
	italicBtn->setCheckable(true);

	underlineBtn = new QToolButton;
	underlineBtn->setIcon(QIcon(":/Resources/underline.png"));
	underlineBtn->setCheckable(true);

	colorBtn = new QToolButton;
	colorBtn->setIcon(QIcon(":/Resources/color.png"));
	colorBtn->setChecked(true);

	//����
	listLabel = new QLabel(tr("����"));
	listComboBox = new QComboBox;
	listComboBox->addItem("Standard");
	listComboBox->addItem("QTextListFormat::ListDisc");
	listComboBox->addItem("QTextListFormat::ListCircle");
	listComboBox->addItem("QTextListFormat::ListSquare");
	listComboBox->addItem("QTextListFormat::ListDecimal");
	listComboBox->addItem("QTextListFormat::ListLowerAlpha");
	listComboBox->addItem("QTextListFormat::ListUpperAlpha");
	listComboBox->addItem("QTextListFormat::ListUpperRaman");
	listComboBox->addItem("QTextListFormat::ListLowerRaman");

	if (img.load(":/Resources/image.png"))
	{
		//��imageLabel�������ͼ��
		showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
	}
	createAction();
	createMenu();
	createToolBar();

	//�źŲ�
	//connect(windowComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Palettte::ShowBase);
	connect(fontComboBox, static_cast<void(QFontComboBox::*)(const QString &)>(&QFontComboBox::activated), this, &ImgProcessor::ShowFontComboBox);
	connect(fontComboBox, QOverload<const QString &>::of(&QFontComboBox::activated), this, &ImgProcessor::ShowFontComboBox);
	connect(sizeComboBox, QOverload<const QString &>::of(&QComboBox::activated), this, &ImgProcessor::ShowSizeSpinBox);
	connect(boldBtn, &QToolButton::clicked, this, &ImgProcessor::ShowBoldBtn);
	connect(italicBtn, &QToolButton::clicked, this, &ImgProcessor::ShowItalicBtn);
	connect(underlineBtn, &QToolButton::clicked, this, &ImgProcessor::ShowUnderLineBtn);
	connect(colorBtn, &QToolButton::clicked, this, &ImgProcessor::ShowColorBtn);
	connect(showWidget->text, &QTextEdit::currentCharFormatChanged, this, &ImgProcessor::ShowCurrentFormatChanged);
	
	//�����źŲ�
	connect(listComboBox, QOverload<int>::of(&QComboBox::activated), this, &ImgProcessor::ShowList);
	connect(showWidget->text->document(), &QTextDocument::undoAvailable, undoAction, &QAction::setEnabled);
	connect(showWidget->text->document(), &QTextDocument::redoAvailable, redoAction, &QAction::setEnabled);
	connect(showWidget->text->document(), &QTextDocument::cursorPositionChanged, this, &ImgProcessor::ShowCursorPositionChanged);
}

ImgProcessor::~ImgProcessor()
{
}

void ImgProcessor::createAction()
{
	//���ļ�����
	openFileAction = new QAction(QIcon(":/Resources/open.png"), tr("��"), this);
	//�������ļ�������ָ���˶���ʹ�õĶ�ͼ�������Լ�������
	openFileAction->setShortcut(tr("Ctrl+O"));
	//�˶�������ϼ�ΪCtrl+ O
	openFileAction->setStatusTip(tr("��һ���ļ�"));
	//�趨״̬����ʾ��������ƶ����ô�ʱ��ʾ
	connect(openFileAction, &QAction::triggered, this, &ImgProcessor::ShowOpenFile);

	//�½��ļ�����
	NewFileAction = new QAction(QIcon(":/Resources/new.png"), tr("�½�"), this);
	NewFileAction->setShortcut(tr("Ctrl+N"));
	NewFileAction->setStatusTip(tr("�½�һ���ļ�"));
	connect(NewFileAction, &QAction::triggered, this, &ImgProcessor::ShowNewFile);
	//�˳�����
	exitAction = new QAction(QIcon(":/Resources/exit.png"), tr("�˳�"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("�˳�����"));
	connect(exitAction, &QAction::triggered, this, &ImgProcessor::close);

	//���ƶ���
	copyAction = new QAction(QIcon(":/Resources/copy.png"), tr("����"), this);
	copyAction->setShortcut(tr("Ctrl+C"));
	copyAction->setStatusTip(tr("�����ļ�"));
	connect(copyAction, &QAction::triggered, showWidget->text, &QTextEdit::copy);

	//���ж���
	cutAction = new QAction(QIcon(":/Resources/cut.png"), tr("����"), this);
	cutAction->setShortcut(tr("Ctrl+X"));
	cutAction->setStatusTip(tr("�����ļ�"));
	connect(cutAction, &QAction::triggered, showWidget->text, &QTextEdit::cut);

	//ճ������
	pasteAction = new QAction(QIcon(":/Resources/paste.png"), tr("ճ��"), this);
	pasteAction->setShortcut(tr("Ctrl+V"));
	pasteAction->setStatusTip(tr("ճ���ļ�"));
	connect(pasteAction, &QAction::triggered, showWidget->text, &QTextEdit::paste);

	//���ڶ���
	aboutAction = new QAction(tr("����"), this);
	connect(aboutAction, &QAction::triggered, this, &QApplication::aboutQt);

	//��ӡ�ı�
	printTextAction = new QAction(QIcon(":/Resources/printText.png"), tr("��ӡ�ı�"), this);
	printTextAction->setStatusTip(tr("��ӡһ���ı�"));
	connect(printTextAction, &QAction::triggered, this, &ImgProcessor::ShowPrintText);

	//��ӡͼ��
	printImageAction = new QAction(QIcon(":/Resources/printImage.png"), tr("��ӡͼ��"), this);
	printImageAction->setStatusTip(tr("��ӡһ��ͼ��"));
	connect(printImageAction, &QAction::triggered, this, &ImgProcessor::ShowPrintImage);

	//�Ŵ���
	zoomInAction = new QAction(QIcon(":/Resources/zoomin.png"), tr("�Ŵ�"), this);
	zoomInAction->setStatusTip(tr("�Ŵ�ͼƬ"));
	connect(zoomInAction, &QAction::triggered, this, &ImgProcessor::ShowZoomIn);

	//��С����
	zoomOutAction = new QAction(QIcon(":/Resources/zoomout.png"), tr("��С"), this);
	zoomOutAction->setStatusTip(tr("��СͼƬ"));
	connect(zoomOutAction, &QAction::triggered, this, &ImgProcessor::ShowZoonOut);

	//��ת����90
	rotate90Action = new QAction(QIcon(":/Resources/rotate90.png"), tr("��ת90��"), this);
	rotate90Action->setStatusTip(tr("��ת90��"));
	connect(rotate90Action, &QAction::triggered, this, &ImgProcessor::ShowRotate90);

	//��ת180
	rotate180Action = new QAction(QIcon(":/Resources/rotate180.png"), tr("��ת180��"), this);
	rotate180Action->setStatusTip("��ת180��");
	connect(rotate180Action, &QAction::triggered, this, &ImgProcessor::ShowRotate180);

	//��ת270
	rotate270Action = new QAction(QIcon(":/Resources/rotate270.png"), tr("��ת270��"), this);
	rotate270Action->setStatusTip("��ת270��");
	connect(rotate270Action, &QAction::triggered, this, &ImgProcessor::ShowRotate270);

	//������
	mirrorVerticalAction = new QAction(QIcon(":/Resources/mirrorVertical.png"), tr("������"), this);
	mirrorVerticalAction->setStatusTip(tr("������"));
	connect(mirrorVerticalAction, &QAction::triggered, this, &ImgProcessor::ShowMirrorVertical);

	//ˮƽ����
	mirrorHorizontalAction = new QAction(QIcon(":/Resources/mirrorHorizontal.png"), tr("ˮƽ����"), this);
	mirrorHorizontalAction->setStatusTip(tr("ˮƽ����"));
	connect(mirrorHorizontalAction, &QAction::triggered, this, &ImgProcessor::ShowMirrorHorizontal);

	//��������룬�Ҷ��룬���к����˶���
	actGrp = new QActionGroup(this);
	leftAction = new QAction(QIcon(":/Resources/left.png"), tr("�����"), actGrp);
	leftAction->setCheckable(true);
	rightAction = new QAction(QIcon(":/Resources/right.png"), tr("�Ҷ���"), actGrp);
	rightAction->setCheckable(true);
	centerAction = new QAction(QIcon(":/Resources/center.png"), tr("����"), actGrp);
	centerAction->setCheckable(true);
	justifyAction = new QAction(QIcon(":/Resources/justify.png"), tr("���˶���"), actGrp);
	justifyAction->setCheckable(true);
	connect(actGrp, &QActionGroup::triggered, this, &ImgProcessor::ShowAlignment);

	//ʵ�ֳ����ͻָ�����
	undoAction = new QAction(QIcon(":/Resources/undo.png"), tr("����"), this);
	connect(undoAction, &QAction::triggered, showWidget->text, &QTextEdit::undo);
	redoAction = new QAction(QIcon(":/Resources/redo.png"), tr("�ָ�"), this);
	connect(redoAction, &QAction::triggered, showWidget->text, &QTextEdit::redo);

}

void ImgProcessor::createMenu()
{
	//ֱ�ӵ���QMainWindow��menuBar()��������������ڵ�ָ��
	fileMenu = menuBar()->addMenu(tr("�ļ�"));
	fileMenu->addAction(openFileAction);
	fileMenu->addAction(NewFileAction);
	fileMenu->addAction(printTextAction);
	fileMenu->addAction(printImageAction);
	//���Ų˵�
	zoomMenu = menuBar()->addMenu(tr("�༭"));
	zoomMenu->addAction(copyAction);
	zoomMenu->addAction(cutAction);
	zoomMenu->addAction(pasteAction);
	zoomMenu->addAction(aboutAction);
	//�����ָ�,���һ���ָ���
	zoomMenu->addSeparator();
	zoomMenu->addAction(zoomInAction);
	zoomMenu->addAction(zoomOutAction);

	//��ת�˵�
	rotateMenu = menuBar()->addMenu(tr("��ת"));
	rotateMenu->addAction(rotate90Action);
	rotateMenu->addAction(rotate180Action);
	rotateMenu->addAction(rotate270Action);

	//����˵�
	mirrorMenu = menuBar()->addMenu(tr("����"));
	mirrorMenu->addAction(mirrorHorizontalAction);
	mirrorMenu->addAction(mirrorVerticalAction);

}

void ImgProcessor::createToolBar()
{
	//�ļ�������
	fileTool = addToolBar("File");
	fileTool->addAction(openFileAction);
	fileTool->addAction(NewFileAction);
	fileTool->addAction(pasteAction);
	fileTool->addAction(printTextAction);
	fileTool->addAction(printImageAction);

	//�༭������
	zoomTool = addToolBar("edit");
	zoomTool->addAction(copyAction);
	zoomTool->addAction(cutAction);
	zoomTool->addAction(pasteAction);
	zoomTool->addSeparator();
	zoomTool->addAction(zoomInAction);
	zoomTool->addAction(zoomOutAction);

	//��ת������
	rotateTool = addToolBar("rotate");
	rotateTool->addAction(rotate90Action);
	rotateTool->addAction(rotate180Action);
	rotateTool->addAction(rotate270Action);

	//����������������
	doToolBar = addToolBar("doEdit");
	doToolBar->addAction(undoAction);
	doToolBar->addAction(redoAction);

	//���幤����
	fontToolBar = addToolBar("Font");
	fontToolBar->addWidget(fontLabel1);
	fontToolBar->addWidget(fontComboBox);
	fontToolBar->addWidget(fontLabel2);
	fontToolBar->addWidget(sizeComboBox);
	fontToolBar->addSeparator();
	fontToolBar->addWidget(boldBtn);
	fontToolBar->addWidget(italicBtn);
	fontToolBar->addWidget(underlineBtn);
	fontToolBar->addSeparator();
	fontToolBar->addWidget(colorBtn);

	//���򹤾���
	listToolBar = addToolBar("list");
	listToolBar->addWidget(listLabel);
	listToolBar->addWidget(listComboBox);
	listToolBar->addSeparator();
	listToolBar->addActions(actGrp->actions());

}

void ImgProcessor::ShowNewFile()
{
	ImgProcessor *newImgProcessor = new ImgProcessor;
	newImgProcessor->show();
}

//getOpenFileName(){					//�˺���
//QWidget* parent = 0;					//ָ��������
//const QString& caption = QString;		//������
//const QString& dir=QString;			//ָ��Ĭ��·��
//const QString& filter=QString();		//���ļ����ͽ��й���
//QString* sellectedFilter=0;			//�û�ѡ�������
//Option options=0						
//}

void ImgProcessor::ShowOpenFile()
{
	

	filename = QFileDialog::getOpenFileName(this);
	if (!filename.isEmpty())
	{
		if (showWidget->text->document()->isEmpty())
		{
			loadFile(filename);
		}
		else
		{
			ImgProcessor* newImgProcessor = new ImgProcessor;
			newImgProcessor->show();
			newImgProcessor->loadFile(filename);
		}
	}
}

void ImgProcessor::loadFile(QString fileName)
{
	printf("file name:%s\n", filename.data());
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream textStream(&file);
		while (!textStream.atEnd())
		{
			showWidget->text->append(textStream.readLine());
			printf("read lin \n");
		}
		printf("endl\n");
	}
}

void ImgProcessor::ShowPrintText()
{
	QPrinter printer;
	//����һ����ӡ�����󣬲���Ϊprinter
	QPrintDialog printDialog(&printer, this);
	//�ж��û�����Ƿ�����ӡ��ť������ͨ������QPrintDialog����
	if (printDialog.exec())
	{
		//���QTextEdit�����ĵ�
		QTextDocument* doc = showWidget->text->document();
		doc->print(&printer);
	}

}

void ImgProcessor::ShowPrintImage()
{
	QPrinter printer;
	QPrintDialog printDialog(&printer, this);
	if (printDialog.exec())
	{
		//����һ����ͼ����
		QPainter painter(&printer);
		//���һ��QPainter�������ͼ��������
		QRect rect = painter.viewport();
		//���ͼƬ�ߴ�
		QSize size = img.size();
		//����ͼ�α�����С������ͼ��������
		size.scale(rect.size(), Qt::KeepAspectRatio);
		painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
		//����QPaiter���ڵĴ�СΪͼ��Ĵ�С
		painter.setWindow(img.rect());
		painter.drawImage(0, 0, img);	
	}
}

//���ź���
void ImgProcessor::ShowZoomIn()
{
	if (img.isNull())						//��Ч���ж�
	{
		return;
	}
	QMatrix matrix;							//����һ��QMatrix���ʵ��
	//����Ϊ���ڵ�x�� y��ԭֵ�ı�ֵ
	matrix.scale(2, 2);
	img = img.transformed(matrix);
	//������ʾͼ��
	showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));

}

void ImgProcessor::ShowZoonOut()
{
	if (img.isNull())
	{
		return;
	}
	QMatrix matrix;
	matrix.scale(0.5, 0.5);
	img = img.transformed(matrix);
	showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

//��ת����
void ImgProcessor::ShowRotate90() 
{
	if (img.isNull())
	{
		return;
	}
	QMatrix matrix;
	matrix.rotate(90);
	img = img.transformed(matrix);
	showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowRotate270()
{
	if (img.isNull())
	{
		return;
	}
	QMatrix matrix;
	matrix.rotate(270);
	img = img.transformed(matrix);
	showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowRotate180()
{
	if (img.isNull())
	{
		return;
	}
	QMatrix matrix;
	matrix.rotate(180);
	img = img.transformed(matrix);
	showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

//������
void ImgProcessor::ShowMirrorHorizontal()
{
	
	if (img.isNull())
	{
		return;
	}
	img = img.mirrored(true, false);
	showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowMirrorVertical()
{

	if (img.isNull())
	{
		return;
	}
	img = img.mirrored(false, true);
	showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

//��������
void ImgProcessor::ShowFontComboBox(QString comboStr)
{
	//����һ��QtextCharFormat����
	QTextCharFormat fmt;
	//���ŵ������������ø�QTextCharFormat����
	fmt.setFontFamily(comboStr);
	//���¸�ʽӦ�õ����ѡ���ڵ��ַ�
	mergeFormat(fmt);
}

void ImgProcessor::mergeFormat(QTextCharFormat format)
{
	//��ñ༭���еĹ��
	QTextCursor cursor = showWidget->text->textCursor();
	//�����û�и���ѡ�����򽫹�����ڳ��Ĵ���Ϊѡ������ǰ��ո���߱������
	if (!cursor.hasSelection())
	{
		cursor.select(QTextCursor::WordUnderCursor);
	}
	//��������format����ʾ�ĸ�ʽӦ�õ��ҹ�����ڵ��ַ�
	cursor.mergeCharFormat(format);
	//����QTextEditde mergeCurrentCharFormat()��������ʽӦ�õ�ѡ���ڵ������ַ�
	showWidget->text->mergeCurrentCharFormat(format);
}

//�����ֺ�
void ImgProcessor::ShowSizeSpinBox(QString spinValue)
{
	QTextCharFormat fmt;
	fmt.setFontPointSize(spinValue.toFloat());
	showWidget->text->mergeCurrentCharFormat(fmt);
}

//��������Ӵ�
void ImgProcessor::ShowBoldBtn()
{
	QTextCharFormat fmt;
	fmt.setFontWeight(boldBtn->isChecked() ? QFont::Bold : QFont::Normal);
	showWidget->text->mergeCurrentCharFormat(fmt);
}

//��������б��
void ImgProcessor::ShowItalicBtn()
{
	QTextCharFormat fmt;
	fmt.setFontItalic(italicBtn->isChecked());
	showWidget->text->mergeCurrentCharFormat(fmt);
}

//���������»���
void ImgProcessor::ShowUnderLineBtn()
{
	QTextCharFormat fmt;
	fmt.setFontUnderline(underlineBtn->isChecked());
	showWidget->text->mergeCurrentCharFormat(fmt);

}

//����������ɫ
void ImgProcessor::ShowColorBtn()
{
	//ʹ���˱�׼��ɫ�Ի��򣬵�������׼��ɫ�Ի���ѡ����ɫ
	QColor  color = QColorDialog::getColor(Qt::red, this);
	if (color.isValid())
	{
		QTextCharFormat fmt;
		fmt.setForeground(color);
		showWidget->text->mergeCurrentCharFormat(fmt);
	}	
}

//�����ַ���ʽ
void ImgProcessor::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
	fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
	sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.FontPointSize)));
	boldBtn->setChecked(fmt.font().bold());
	italicBtn->setChecked(fmt.fontItalic());
	underlineBtn->setChecked(fmt.fontUnderline());

}

//�����Ű�,ʵ�ֶ������
void ImgProcessor::ShowAlignment(QAction *act)
{
	if (act == leftAction)
	{
		showWidget->text->setAlignment(Qt::AlignLeft);
	}
	if (act == rightAction)
	{
		showWidget->text->setAlignment(Qt::AlignRight);
	}
	if (act == centerAction)
	{
		showWidget->text->setAlignment(Qt::AlignCenter);
	}
	if (act == justifyAction)
	{
		showWidget->text->setAlignment(Qt::AlignJustify);
	}
}

//��Ӧ�ı��й��λ�ô����������źŸı�
void ImgProcessor::ShowCursorPositionChanged()
{
	if (showWidget->text->alignment() == Qt::AlignLeft)
	{
		leftAction->setChecked(true);
	}
	if (showWidget->text->alignment() == Qt::AlignRight)
	{
		rightAction->setChecked(true);
	}
	if (showWidget->text->alignment() == Qt::AlignCenter)
	{
		centerAction->setChecked(true);
	}
	if (showWidget->text->alignment() == Qt::AlignJustify)
	{
		justifyAction->setChecked(true);
	}
}

//ʵ���ı�����
void ImgProcessor::ShowList(int index)
{
	//��ñ༭���QTextCursor����ָ��
	QTextCursor cursor = showWidget->text->textCursor();
	if (index != 0)
	{
		//����������ѡ��ȷ��QTextListFormat��style����ֵ
		QTextListFormat::Style style = QTextListFormat::ListDisc;
		switch (index)
		{
		default:
		case 1:
			style = QTextListFormat::ListDisc;
			break;
		case 2:
			style = QTextListFormat::ListCircle;
			break;
		case 3:
			style = QTextListFormat::ListSquare;
			break;
		case 4:
			style = QTextListFormat::ListDecimal;
			break;
		case 5:
			style = QTextListFormat::ListLowerAlpha;
			break;
		case 6:
			style = QTextListFormat::ListUpperAlpha;
		case 7:
			style = QTextListFormat::ListLowerRoman;
			break;
		case 8:
			style = QTextListFormat::ListUpperRoman;
			break;
		}
		//��������, beginEditBlock() �� endEditBlock()ͨ���ɶԳ���
		cursor.beginEditBlock();
		QTextBlockFormat blockFmt = cursor.blockFormat();
		QTextListFormat listFmt;
		if (cursor.currentList())
		{
			listFmt = cursor.currentList()->format();
		}
		else
		{
			listFmt.setIndent(blockFmt.indent() + 1);
			blockFmt.setIndent(0);
			cursor.setBlockFormat(blockFmt);
		}
		listFmt.setStyle(style);
		cursor.createList(listFmt);
		cursor.endEditBlock();
	}
	else
	{
		QTextBlockFormat bfmt;
		bfmt.setObjectIndex(-1);
		cursor.mergeBlockFormat(bfmt);
	}
}