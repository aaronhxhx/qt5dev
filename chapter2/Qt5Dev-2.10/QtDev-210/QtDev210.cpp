#include "QtDev210.h"

QtDev210::QtDev210(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QRegExp regExp("[A-Za-z][1-9][0-9]{0, 2}");
	ui.lineEdit->setValidator(new QRegExpValidator(regExp, this));				//建立验证器
	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	//connect(ui.lineEdit, SIGNAL(textChanged()), this, SLOT(on_lineEdit_textChanged()));

}

void QtDev210::on_lineEdit_textChanged()
{
	ui.okButton->setEnabled(ui.lineEdit->hasAcceptableInput());
}

QtDev210::~QtDev210()
{
	//delete ui;
}