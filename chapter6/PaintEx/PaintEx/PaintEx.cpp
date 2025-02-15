#include "PaintEx.h"

PaintEx::PaintEx(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	paintArea = new Paintarea;
	shapeLabel = new QLabel(tr("形状："));
	shapeComboBox = new QComboBox;
	shapeComboBox->addItem(tr("Line"), Paintarea::Line);		//(a)
	shapeComboBox->addItem(tr("Rectangle"), Paintarea::Rectangle);
	shapeComboBox->addItem(tr("RoundedRect"), Paintarea::RoundRect);
	shapeComboBox->addItem(tr("Ellipse"), Paintarea::Ellipse);
	shapeComboBox->addItem(tr("Polygon"), Paintarea::Polygon);
	shapeComboBox->addItem(tr("Polyline"), Paintarea::Polyline);
	shapeComboBox->addItem(tr("Points"), Paintarea::Points);
	shapeComboBox->addItem(tr("Arc"), Paintarea::Arc);
	shapeComboBox->addItem(tr("Path"), Paintarea::Path);
	shapeComboBox->addItem(tr("Text"), Paintarea::Text);
	shapeComboBox->addItem(tr("Pixmap"), Paintarea::Pixmap);
	connect(shapeComboBox, QOverload<int>::of(&QComboBox::activated), this, &PaintEx::ShowShape);

	penColorLabel = new QLabel(tr("画笔颜色："));
	penColorFrame = new QFrame;
	penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	penColorFrame->setAutoFillBackground(true);
	penColorFrame->setPalette(QPalette(Qt::blue));
	penColorBtn = new QPushButton(tr("更改"));
	connect(penColorBtn, &QPushButton::clicked, this, &PaintEx::ShowShape);

	penWidthLabel = new QLabel(tr("画笔线宽："));
	penWidthSpinBox = new QSpinBox;
	penWidthSpinBox->setRange(0, 20);
	connect(penWidthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &PaintEx::ShowPenWidth);

	penStyleLabel = new QLabel(tr("画笔风格："));
	penStyleComboBox = new QComboBox;
	penStyleComboBox->addItem(tr("SoldLine"), static_cast<int>(Qt::SolidLine));
	penStyleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	penStyleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	penStyleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
	penStyleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
	penStyleComboBox->addItem(tr("CustomDashLine"), static_cast<int>(Qt::CustomDashLine));
	connect(penStyleComboBox, QOverload<int>::of(&QComboBox::activated), this, &PaintEx::ShowPenStyle);

	penCapLabel = new QLabel(tr("画笔顶帽："));
	penCapComboBox = new QComboBox;
	penCapComboBox->addItem(tr("SquareCap"), Qt::SquareCap);
	penCapComboBox->addItem(tr("FlatCap"), Qt::FlatCap);
	penCapComboBox->addItem(tr("RoundCap"), Qt::RoundCap);
	connect(penCapComboBox, QOverload<int>::of(&QComboBox::activated), this, &PaintEx::ShowPenCap);

	penJoinLabel = new QLabel(tr("画笔连接点："));
	penJoinComboBox = new QComboBox;
	penJoinComboBox->addItem(tr("BevelJoin"), Qt::BevelJoin);
	penJoinComboBox->addItem(tr("MiterJoin"), Qt::MiterJoin);
	penJoinComboBox->addItem(tr("RoundJoin"), Qt::RoundJoin);
	connect(penJoinComboBox, QOverload<int>::of(&QComboBox::activated), this, &PaintEx::ShowPenJion);

	//填充模式选择下拉列表框
	fillRuleLabel = new QLabel(tr("填充模式："));      
	fillRuleComboBox = new QComboBox;
	fillRuleComboBox->addItem(tr("Odd Even"), Qt::OddEvenFill);  //(e)
	fillRuleComboBox->addItem(tr("Winding"), Qt::WindingFill);
	connect(fillRuleComboBox, QOverload<int>::of(&QComboBox::activated), this, &PaintEx::ShowFillRule);

	//铺展效果选择下拉列表框
	spreadLabel = new QLabel(tr("铺展效果："));        
	spreadComboBox = new QComboBox;
	spreadComboBox->addItem(tr("PadSpread"), QGradient::PadSpread);														 //(f)
	spreadComboBox->addItem(tr("RepeatSpread"), QGradient::RepeatSpread);
	spreadComboBox->addItem(tr("ReflectSpread"), QGradient::ReflectSpread);
	connect(spreadComboBox, QOverload<int>::of(&QComboBox::activated), this, &PaintEx::ShowSpreadStyle);

	//画刷颜色选择控件
	brushColorLabel = new QLabel(tr("画刷颜色："));    
	brushColorFrame = new QFrame;
	brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	brushColorFrame->setAutoFillBackground(true);
	brushColorFrame->setPalette(QPalette(Qt::green));
	brushColorBtn = new QPushButton(tr("更改"));
	connect(brushColorBtn, &QPushButton::clicked, this, &PaintEx::ShowBrushColor);

	//画刷风格选择下拉列表框
	brushStyleLabel = new QLabel(tr("画刷风格："));	
	brushStyleComboBox = new QComboBox;
	brushStyleComboBox->addItem(tr("SolidPattern"), static_cast<int>(Qt::SolidPattern));
	brushStyleComboBox->addItem(tr("Dense1Pattern"), static_cast<int>(Qt::Dense1Pattern));
	brushStyleComboBox->addItem(tr("Dense2Pattern"), static_cast<int>(Qt::Dense2Pattern));
	brushStyleComboBox->addItem(tr("Dense3Pattern"), static_cast<int>(Qt::Dense3Pattern));
	brushStyleComboBox->addItem(tr("Dense4Pattern"), static_cast<int>(Qt::Dense4Pattern));
	brushStyleComboBox->addItem(tr("Dense5Pattern"), static_cast<int>(Qt::Dense5Pattern));
	brushStyleComboBox->addItem(tr("Dense6Pattern"), static_cast<int>(Qt::Dense6Pattern));
	brushStyleComboBox->addItem(tr("Dense7Pattern"), static_cast<int>(Qt::Dense7Pattern));
	brushStyleComboBox->addItem(tr("HorPattern"), static_cast<int>(Qt::HorPattern));
	brushStyleComboBox->addItem(tr("VerPattern"), static_cast<int>(Qt::VerPattern));
	brushStyleComboBox->addItem(tr("CrossPattern"), static_cast<int>(Qt::CrossPattern));
	brushStyleComboBox->addItem(tr("BDiagPattern"), static_cast<int>(Qt::BDiagPattern));
	brushStyleComboBox->addItem(tr("FDiagPattern"), static_cast<int>(Qt::FDiagPattern));
	brushStyleComboBox->addItem(tr("DiagCrossPattern"), static_cast<int>(Qt::DiagCrossPattern));
	brushStyleComboBox->addItem(tr("LinearGradientPattern"), static_cast<int>(Qt::LinearGradientPattern));
	brushStyleComboBox->addItem(tr("ConicalGradientPattern"), static_cast<int>(Qt::ConicalGradientPattern));
	brushStyleComboBox->addItem(tr("RadialGradientPattern"), static_cast<int>(Qt::RadialGradientPattern));
	brushStyleComboBox->addItem(tr("TexturePattern"), static_cast<int>(Qt::TexturePattern));
	connect(brushStyleComboBox, QOverload<int>::of(&QComboBox::activated), this,&PaintEx::ShowBrush);

	//控制面板的布局
	rightLayout = new QGridLayout;                   
	rightLayout->addWidget(shapeLabel, 0, 0);
	rightLayout->addWidget(shapeComboBox, 0, 1);
	rightLayout->addWidget(penColorLabel, 1, 0);
	rightLayout->addWidget(penColorFrame, 1, 1);
	rightLayout->addWidget(penColorBtn, 1, 2);
	rightLayout->addWidget(penWidthLabel, 2, 0);
	rightLayout->addWidget(penWidthSpinBox, 2, 1);
	rightLayout->addWidget(penStyleLabel, 3, 0);
	rightLayout->addWidget(penStyleComboBox, 3, 1);
	rightLayout->addWidget(penCapLabel, 4, 0);
	rightLayout->addWidget(penCapComboBox, 4, 1);
	rightLayout->addWidget(penJoinLabel, 5, 0);
	rightLayout->addWidget(penJoinComboBox, 5, 1);
	rightLayout->addWidget(fillRuleLabel, 6, 0);
	rightLayout->addWidget(fillRuleComboBox, 6, 1);
	rightLayout->addWidget(spreadLabel, 7, 0);
	rightLayout->addWidget(spreadComboBox, 7, 1);
	rightLayout->addWidget(brushColorLabel, 8, 0);
	rightLayout->addWidget(brushColorFrame, 8, 1);
	rightLayout->addWidget(brushColorBtn, 8, 2);
	rightLayout->addWidget(brushStyleLabel, 9, 0);
	rightLayout->addWidget(brushStyleComboBox, 9, 1);

	//整体的布局
	QHBoxLayout *mainLayout = new QHBoxLayout(this);  
	mainLayout->addWidget(paintArea);
	mainLayout->addLayout(rightLayout);
	mainLayout->setStretchFactor(paintArea, 1);
	mainLayout->setStretchFactor(rightLayout, 0);

	//显示默认的图形
	ShowShape(shapeComboBox->currentIndex());        
}


PaintEx::~PaintEx()
{
}

void PaintEx::ShowShape(int value)
{
	Paintarea::Shape shape = Paintarea::Shape(shapeComboBox->itemData(value, Qt::UserRole).toInt());
	paintArea->setShape(shape);
}

void PaintEx::ShowPenWidth(int)
{
}

void PaintEx::ShowPenCdolor()
{
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
	penColorFrame->setPalette(QPalette(color));
	int value = penWidthSpinBox->value();

}

void PaintEx::ShowPenStyle(int)
{
}

void PaintEx::ShowPenCap(int)
{
}

void PaintEx::ShowPenJion(int)
{
}

void PaintEx::ShowSpreadStyle()
{
}

void PaintEx::ShowFillRule()
{
}

void PaintEx::ShowBrushColor()
{
}

void PaintEx::ShowBrush(int)
{
}
