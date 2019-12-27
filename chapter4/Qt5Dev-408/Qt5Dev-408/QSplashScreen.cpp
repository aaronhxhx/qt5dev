#include "SplashScreen.h"

SplashScreen::SplashScreen(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);

	setWindowTitle("Splash Example");
	QTextEdit* edit = new QTextEdit;
	edit->setText("Splash Example");
	setCentralWidget(edit);
	resize(600, 450);
	Sleep(1000);
}

SplashScreen::~SplashScreen()
{
}
