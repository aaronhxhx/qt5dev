#include "SVGTest.h"

SVGTest::SVGTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("Svg"));
	createMenu();
	svgWindow = new SvgWindow;
	setCentralWidget(svgWindow);
}

SVGTest::~SVGTest()
{
}

void SVGTest::createMenu()
{
	QMenu* fileMenu = menuBar()->addMenu(QStringLiteral("文件"));
	QAction* openAct = new QAction(QStringLiteral("打开"), this);
	connect(openAct, &QAction::triggered, this, &SVGTest::slotOpenFile);
	fileMenu->addAction(openAct);
}

void SVGTest::slotOpenFile()
{
	QString name = QFileDialog::getOpenFileName(this, "打开", ",");
	svgWindow->setFile(name);
}
