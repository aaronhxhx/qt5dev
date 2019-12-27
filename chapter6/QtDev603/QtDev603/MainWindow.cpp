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
	styleLabel = new QLabel("���Է��");
	styleComboBox = new QComboBox;
	styleComboBox->addItem(tr("SoldLine"), static_cast<int>(Qt::SolidLine));
	styleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	styleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	styleComboBox->addItem(tr("DushDotLine"), static_cast<int>(Qt::DashDotLine));
	styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));

	//���Ӳۺ���
	connect(styleComboBox, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::ShowStyle);

	//�����߿�ѡ��ؼ�
	widthLabel = new QLabel(tr("�߿�"));
	widthSpinBox = new QSpinBox;
	connect(widthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), drawWidget, &DrawWidget::setWidth);

	//������ɫѡ��ؼ�
	colorBtn = new QToolButton;
	QPixmap pixmap(20, 20);
	pixmap.fill(Qt::blue);
	colorBtn->setIcon(QIcon(pixmap));
	connect(colorBtn, &QToolButton::clicked, this, &MainWindow::ShowColor);

	clearBtn = new QToolButton;
	clearBtn->setText(tr("���"));
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

