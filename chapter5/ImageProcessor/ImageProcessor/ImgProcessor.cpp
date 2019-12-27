#include "ImgProcessor.h"

ImgProcessor::ImgProcessor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("Easy word"));
	showWidget = new ShowWidget(this);
	//建立中心控件
	setCentralWidget(showWidget);
	//等同于setCentralWidget(showWidget),将showWidget作为中心部件
	/*创建菜单栏、状态栏、动作函数*/
	

	//在工具栏上嵌入控件
	//设置字体
	fontLabel1 = new QLabel(tr("字体"));
	fontComboBox = new QFontComboBox;
	//
	fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
	fontLabel2 = new QLabel(tr("字号"));
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

	//排序
	listLabel = new QLabel(tr("排序"));
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
		//在imageLabel对象放置图像
		showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
	}
	createAction();
	createMenu();
	createToolBar();

	//信号槽
	//connect(windowComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Palettte::ShowBase);
	connect(fontComboBox, static_cast<void(QFontComboBox::*)(const QString &)>(&QFontComboBox::activated), this, &ImgProcessor::ShowFontComboBox);
	connect(fontComboBox, QOverload<const QString &>::of(&QFontComboBox::activated), this, &ImgProcessor::ShowFontComboBox);
	connect(sizeComboBox, QOverload<const QString &>::of(&QComboBox::activated), this, &ImgProcessor::ShowSizeSpinBox);
	connect(boldBtn, &QToolButton::clicked, this, &ImgProcessor::ShowBoldBtn);
	connect(italicBtn, &QToolButton::clicked, this, &ImgProcessor::ShowItalicBtn);
	connect(underlineBtn, &QToolButton::clicked, this, &ImgProcessor::ShowUnderLineBtn);
	connect(colorBtn, &QToolButton::clicked, this, &ImgProcessor::ShowColorBtn);
	connect(showWidget->text, &QTextEdit::currentCharFormatChanged, this, &ImgProcessor::ShowCurrentFormatChanged);
	
	//排序信号槽
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
	//打开文件动作
	openFileAction = new QAction(QIcon(":/Resources/open.png"), tr("打开"), this);
	//创建打开文件动作，指定此动作使用的额图表、名称以及父窗口
	openFileAction->setShortcut(tr("Ctrl+O"));
	//此动作的组合键为Ctrl+ O
	openFileAction->setStatusTip(tr("打开一个文件"));
	//设定状态栏显示，当光标移动到该处时显示
	connect(openFileAction, &QAction::triggered, this, &ImgProcessor::ShowOpenFile);

	//新建文件动作
	NewFileAction = new QAction(QIcon(":/Resources/new.png"), tr("新建"), this);
	NewFileAction->setShortcut(tr("Ctrl+N"));
	NewFileAction->setStatusTip(tr("新建一个文件"));
	connect(NewFileAction, &QAction::triggered, this, &ImgProcessor::ShowNewFile);
	//退出动作
	exitAction = new QAction(QIcon(":/Resources/exit.png"), tr("退出"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("退出程序"));
	connect(exitAction, &QAction::triggered, this, &ImgProcessor::close);

	//复制动作
	copyAction = new QAction(QIcon(":/Resources/copy.png"), tr("复制"), this);
	copyAction->setShortcut(tr("Ctrl+C"));
	copyAction->setStatusTip(tr("复制文件"));
	connect(copyAction, &QAction::triggered, showWidget->text, &QTextEdit::copy);

	//剪切动作
	cutAction = new QAction(QIcon(":/Resources/cut.png"), tr("剪切"), this);
	cutAction->setShortcut(tr("Ctrl+X"));
	cutAction->setStatusTip(tr("剪切文件"));
	connect(cutAction, &QAction::triggered, showWidget->text, &QTextEdit::cut);

	//粘贴动作
	pasteAction = new QAction(QIcon(":/Resources/paste.png"), tr("粘贴"), this);
	pasteAction->setShortcut(tr("Ctrl+V"));
	pasteAction->setStatusTip(tr("粘贴文件"));
	connect(pasteAction, &QAction::triggered, showWidget->text, &QTextEdit::paste);

	//关于动作
	aboutAction = new QAction(tr("关于"), this);
	connect(aboutAction, &QAction::triggered, this, &QApplication::aboutQt);

	//打印文本
	printTextAction = new QAction(QIcon(":/Resources/printText.png"), tr("打印文本"), this);
	printTextAction->setStatusTip(tr("打印一个文本"));
	connect(printTextAction, &QAction::triggered, this, &ImgProcessor::ShowPrintText);

	//打印图像
	printImageAction = new QAction(QIcon(":/Resources/printImage.png"), tr("打印图像"), this);
	printImageAction->setStatusTip(tr("打印一个图像"));
	connect(printImageAction, &QAction::triggered, this, &ImgProcessor::ShowPrintImage);

	//放大动作
	zoomInAction = new QAction(QIcon(":/Resources/zoomin.png"), tr("放大"), this);
	zoomInAction->setStatusTip(tr("放大图片"));
	connect(zoomInAction, &QAction::triggered, this, &ImgProcessor::ShowZoomIn);

	//缩小动作
	zoomOutAction = new QAction(QIcon(":/Resources/zoomout.png"), tr("缩小"), this);
	zoomOutAction->setStatusTip(tr("缩小图片"));
	connect(zoomOutAction, &QAction::triggered, this, &ImgProcessor::ShowZoonOut);

	//旋转动作90
	rotate90Action = new QAction(QIcon(":/Resources/rotate90.png"), tr("旋转90°"), this);
	rotate90Action->setStatusTip(tr("旋转90°"));
	connect(rotate90Action, &QAction::triggered, this, &ImgProcessor::ShowRotate90);

	//旋转180
	rotate180Action = new QAction(QIcon(":/Resources/rotate180.png"), tr("旋转180°"), this);
	rotate180Action->setStatusTip("旋转180°");
	connect(rotate180Action, &QAction::triggered, this, &ImgProcessor::ShowRotate180);

	//旋转270
	rotate270Action = new QAction(QIcon(":/Resources/rotate270.png"), tr("旋转270°"), this);
	rotate270Action->setStatusTip("旋转270°");
	connect(rotate270Action, &QAction::triggered, this, &ImgProcessor::ShowRotate270);

	//纵向镜像
	mirrorVerticalAction = new QAction(QIcon(":/Resources/mirrorVertical.png"), tr("纵向镜像"), this);
	mirrorVerticalAction->setStatusTip(tr("纵向镜像"));
	connect(mirrorVerticalAction, &QAction::triggered, this, &ImgProcessor::ShowMirrorVertical);

	//水平镜像
	mirrorHorizontalAction = new QAction(QIcon(":/Resources/mirrorHorizontal.png"), tr("水平镜像"), this);
	mirrorHorizontalAction->setStatusTip(tr("水平镜像"));
	connect(mirrorHorizontalAction, &QAction::triggered, this, &ImgProcessor::ShowMirrorHorizontal);

	//排序：左对齐，右对齐，居中和两端对齐
	actGrp = new QActionGroup(this);
	leftAction = new QAction(QIcon(":/Resources/left.png"), tr("左对齐"), actGrp);
	leftAction->setCheckable(true);
	rightAction = new QAction(QIcon(":/Resources/right.png"), tr("右对齐"), actGrp);
	rightAction->setCheckable(true);
	centerAction = new QAction(QIcon(":/Resources/center.png"), tr("居中"), actGrp);
	centerAction->setCheckable(true);
	justifyAction = new QAction(QIcon(":/Resources/justify.png"), tr("两端对齐"), actGrp);
	justifyAction->setCheckable(true);
	connect(actGrp, &QActionGroup::triggered, this, &ImgProcessor::ShowAlignment);

	//实现撤销和恢复动作
	undoAction = new QAction(QIcon(":/Resources/undo.png"), tr("撤销"), this);
	connect(undoAction, &QAction::triggered, showWidget->text, &QTextEdit::undo);
	redoAction = new QAction(QIcon(":/Resources/redo.png"), tr("恢复"), this);
	connect(redoAction, &QAction::triggered, showWidget->text, &QTextEdit::redo);

}

void ImgProcessor::createMenu()
{
	//直接调用QMainWindow的menuBar()函数，获得主窗口的指针
	fileMenu = menuBar()->addMenu(tr("文件"));
	fileMenu->addAction(openFileAction);
	fileMenu->addAction(NewFileAction);
	fileMenu->addAction(printTextAction);
	fileMenu->addAction(printImageAction);
	//缩放菜单
	zoomMenu = menuBar()->addMenu(tr("编辑"));
	zoomMenu->addAction(copyAction);
	zoomMenu->addAction(cutAction);
	zoomMenu->addAction(pasteAction);
	zoomMenu->addAction(aboutAction);
	//建立分隔,添加一个分隔符
	zoomMenu->addSeparator();
	zoomMenu->addAction(zoomInAction);
	zoomMenu->addAction(zoomOutAction);

	//旋转菜单
	rotateMenu = menuBar()->addMenu(tr("旋转"));
	rotateMenu->addAction(rotate90Action);
	rotateMenu->addAction(rotate180Action);
	rotateMenu->addAction(rotate270Action);

	//镜像菜单
	mirrorMenu = menuBar()->addMenu(tr("镜像"));
	mirrorMenu->addAction(mirrorHorizontalAction);
	mirrorMenu->addAction(mirrorVerticalAction);

}

void ImgProcessor::createToolBar()
{
	//文件工具条
	fileTool = addToolBar("File");
	fileTool->addAction(openFileAction);
	fileTool->addAction(NewFileAction);
	fileTool->addAction(pasteAction);
	fileTool->addAction(printTextAction);
	fileTool->addAction(printImageAction);

	//编辑工具条
	zoomTool = addToolBar("edit");
	zoomTool->addAction(copyAction);
	zoomTool->addAction(cutAction);
	zoomTool->addAction(pasteAction);
	zoomTool->addSeparator();
	zoomTool->addAction(zoomInAction);
	zoomTool->addAction(zoomOutAction);

	//旋转工具条
	rotateTool = addToolBar("rotate");
	rotateTool->addAction(rotate90Action);
	rotateTool->addAction(rotate180Action);
	rotateTool->addAction(rotate270Action);

	//撤销和重做工具条
	doToolBar = addToolBar("doEdit");
	doToolBar->addAction(undoAction);
	doToolBar->addAction(redoAction);

	//字体工具条
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

	//排序工具条
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

//getOpenFileName(){					//此函数
//QWidget* parent = 0;					//指定父窗口
//const QString& caption = QString;		//标题名
//const QString& dir=QString;			//指定默认路径
//const QString& filter=QString();		//对文件类型进行过滤
//QString* sellectedFilter=0;			//用户选择过滤器
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
	//创建一个打印机对象，参数为printer
	QPrintDialog printDialog(&printer, this);
	//判断用户点击是否点击打印按钮，可以通过创建QPrintDialog对象
	if (printDialog.exec())
	{
		//获得QTextEdit对象文档
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
		//创建一个绘图对象
		QPainter painter(&printer);
		//获得一个QPainter对象的视图矩形区域
		QRect rect = painter.viewport();
		//获得图片尺寸
		QSize size = img.size();
		//按照图形比例大小重设视图矩形区域
		size.scale(rect.size(), Qt::KeepAspectRatio);
		painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
		//重设QPaiter窗口的大小为图像的大小
		painter.setWindow(img.rect());
		painter.drawImage(0, 0, img);	
	}
}

//缩放函数
void ImgProcessor::ShowZoomIn()
{
	if (img.isNull())						//有效性判断
	{
		return;
	}
	QMatrix matrix;							//声明一个QMatrix类的实例
	//参数为现在的x， y与原值的比值
	matrix.scale(2, 2);
	img = img.transformed(matrix);
	//重设显示图形
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

//旋转功能
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

//镜像功能
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

//设置字体
void ImgProcessor::ShowFontComboBox(QString comboStr)
{
	//创建一个QtextCharFormat对象
	QTextCharFormat fmt;
	//悬着的字体名称设置给QTextCharFormat对象
	fmt.setFontFamily(comboStr);
	//将新格式应用到光标选区内的字符
	mergeFormat(fmt);
}

void ImgProcessor::mergeFormat(QTextCharFormat format)
{
	//获得编辑框中的光标
	QTextCursor cursor = showWidget->text->textCursor();
	//若光标没有高亮选区，则将光标所在出的词作为选区，由前后空格或者标点区分
	if (!cursor.hasSelection())
	{
		cursor.select(QTextCursor::WordUnderCursor);
	}
	//将参数的format所表示的格式应用到挂光标所在的字符
	cursor.mergeCharFormat(format);
	//调用QTextEditde mergeCurrentCharFormat()函数将格式应用到选区内的所有字符
	showWidget->text->mergeCurrentCharFormat(format);
}

//设置字号
void ImgProcessor::ShowSizeSpinBox(QString spinValue)
{
	QTextCharFormat fmt;
	fmt.setFontPointSize(spinValue.toFloat());
	showWidget->text->mergeCurrentCharFormat(fmt);
}

//设置字体加粗
void ImgProcessor::ShowBoldBtn()
{
	QTextCharFormat fmt;
	fmt.setFontWeight(boldBtn->isChecked() ? QFont::Bold : QFont::Normal);
	showWidget->text->mergeCurrentCharFormat(fmt);
}

//设置文字斜体
void ImgProcessor::ShowItalicBtn()
{
	QTextCharFormat fmt;
	fmt.setFontItalic(italicBtn->isChecked());
	showWidget->text->mergeCurrentCharFormat(fmt);
}

//设置文字下划线
void ImgProcessor::ShowUnderLineBtn()
{
	QTextCharFormat fmt;
	fmt.setFontUnderline(underlineBtn->isChecked());
	showWidget->text->mergeCurrentCharFormat(fmt);

}

//设置字体颜色
void ImgProcessor::ShowColorBtn()
{
	//使用了标准颜色对话框，当单机标准颜色对话框选择颜色
	QColor  color = QColorDialog::getColor(Qt::red, this);
	if (color.isValid())
	{
		QTextCharFormat fmt;
		fmt.setForeground(color);
		showWidget->text->mergeCurrentCharFormat(fmt);
	}	
}

//设置字符格式
void ImgProcessor::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
	fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
	sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.FontPointSize)));
	boldBtn->setChecked(fmt.font().bold());
	italicBtn->setChecked(fmt.fontItalic());
	underlineBtn->setChecked(fmt.fontUnderline());

}

//设置排版,实现段落对齐
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

//响应文本中光标位置处，发生的信号改变
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

//实现文本排序
void ImgProcessor::ShowList(int index)
{
	//获得编辑框的QTextCursor对象指针
	QTextCursor cursor = showWidget->text->textCursor();
	if (index != 0)
	{
		//从下拉框中选择确定QTextListFormat的style属性值
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
		//设置缩进, beginEditBlock() 和 endEditBlock()通常成对出现
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