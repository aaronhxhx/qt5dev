#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	drawWidget = new DrawWidget;
	setCentralWidget(drawWidget);
	createToolBar();
	setMinimumSize(600, 400);
	ShowStyle();
	drawWidget->setWidth(widthSpinBox->value());
	drawWidget->setColor(Qt::red);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createToolBar()
{
	QToolBar* toolBar = addToolBar("Tool");
	styleLabel = new QLabel("线性风格：");
	styleComboBox = new QComboBox;
	styleComboBox->addItem(tr("SoldLine"), static_cast<int>(Qt::SolidLine));
	styleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	styleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	styleComboBox->addItem(tr("DushDotLine"), static_cast<int>(Qt::DashDotLine));
	styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));

	//连接槽函数
	connect(styleComboBox, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::ShowStyle);

	//创建线宽选择控件
	widthLabel = new QLabel(tr("线宽："));
	widthSpinBox = new QSpinBox;
	connect(widthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), drawWidget, &DrawWidget::setWidth);

	//创建颜色选择控件
	colorBtn = new QToolButton;
	QPixmap pixmap(20, 20);
	pixmap.fill(Qt::blue);
	colorBtn->setIcon(QIcon(pixmap));
	connect(colorBtn, &QToolButton::clicked, this, &MainWindow::ShowColor);

	clearBtn = new QToolButton;
	clearBtn->setText(tr("清除"));
	connect(clearBtn, &QToolButton::clicked, drawWidget, &DrawWidget::clear);

	toolBar->addWidget(styleLabel);
	toolBar->addWidget(styleComboBox);
	toolBar->addWidget(widthLabel);
	toolBar->addWidget(widthSpinBox);
	toolBar->addWidget(colorBtn);
	toolBar->addWidget(clearBtn);
}

void MainWindow::ShowColor()
{
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue), this);
	if (color.isValid())
	{
		//
		drawWidget->setColor(color);
		QPixmap p(20, 20);
		p.fill(color);
		colorBtn->setIcon(QIcon(p));
	}

}

void MainWindow::ShowStyle()
{
	drawWidget->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(), Qt::UserRole).toInt());
}

