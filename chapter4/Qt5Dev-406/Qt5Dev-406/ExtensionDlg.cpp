#include "ExtensionDlg.h"

ExtensionDlg::ExtensionDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("Extension Dialog"));
	createBaseInfo();
	createDetailInfo();
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(baseWidget);
	mainLayout->addWidget(detailWidget);
	//设置长提大小固定，否则再次点击详细时，回不到初始状态
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	mainLayout->setSpacing(10);

}

void ExtensionDlg::createBaseInfo()
{
	baseWidget = new QWidget;
	QLabel* nameLabel = new QLabel(tr("姓名："));
	QLineEdit* nameLineEdit = new QLineEdit;
	QLabel* sexLabel = new QLabel(tr("性别: "));
	QComboBox* sexComboBox = new QComboBox;
	sexComboBox->insertItem(0, tr("男"));
	sexComboBox->insertItem(1, tr("女"));
	QGridLayout* leftLayout = new QGridLayout;
	leftLayout->addWidget(nameLabel, 0, 0);
	leftLayout->addWidget(nameLineEdit, 0, 1);
	leftLayout->addWidget(sexLabel);
	leftLayout->addWidget(sexComboBox);
	QPushButton* OKBtn = new QPushButton(tr("确定"));
	QPushButton* DetailBtn = new QPushButton(tr("详细"));
	QDialogButtonBox* btnBox = new QDialogButtonBox(Qt::Vertical);
	btnBox->addButton(OKBtn, QDialogButtonBox::ActionRole);
	btnBox->addButton(DetailBtn, QDialogButtonBox::ActionRole);
	QHBoxLayout* mainLayout = new QHBoxLayout(baseWidget);
	mainLayout->addLayout(leftLayout);
	mainLayout->addWidget(btnBox);
	connect(DetailBtn, &QPushButton::clicked, this, &ExtensionDlg::showDetailInfo);


}

void ExtensionDlg::createDetailInfo()
{
	detailWidget = new QWidget;
	QLabel* ageLabel = new QLabel(tr("年龄："));
	QLineEdit* ageLineEdit = new QLineEdit(tr("30"));
	QLabel* departmentLabel = new QLabel(tr("部门："));
	QComboBox* departmentComboBox = new QComboBox;
	departmentComboBox->addItem(tr("部门1"));
	departmentComboBox->addItem(tr("部门2"));
	departmentComboBox->addItem(tr("部门3"));
	departmentComboBox->addItem(tr("部门4"));
	QLabel* emailLabel = new QLabel(tr("email: "));
	QLineEdit* emailLineEdit = new QLineEdit;

	//布局
	QGridLayout* mainLayout = new QGridLayout(detailWidget);
	mainLayout->addWidget(ageLabel, 0, 0);
	mainLayout->addWidget(ageLineEdit, 0, 1);
	mainLayout->addWidget(departmentLabel, 1, 0);
	mainLayout->addWidget(departmentComboBox, 1, 1);
	mainLayout->addWidget(emailLabel, 2, 0);
	mainLayout->addWidget(emailLineEdit, 2, 1);

	//隐藏状态
	detailWidget->hide();
}

void ExtensionDlg::showDetailInfo()
{
	if (detailWidget->isHidden())
	{
		detailWidget->show();
	}
	else
	{
		detailWidget->hide();
	}
}