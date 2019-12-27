/********************************************************************************
** Form generated from reading UI file 'QtDev210.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDEV210_H
#define UI_QTDEV210_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDev210Class
{
public:
    QWidget *GoToCell_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtDev210Class)
    {
        if (QtDev210Class->objectName().isEmpty())
            QtDev210Class->setObjectName(QString::fromUtf8("QtDev210Class"));
        QtDev210Class->resize(314, 150);
        GoToCell_2 = new QWidget(QtDev210Class);
        GoToCell_2->setObjectName(QString::fromUtf8("GoToCell_2"));
        verticalLayout = new QVBoxLayout(GoToCell_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(GoToCell_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(GoToCell_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okButton = new QPushButton(GoToCell_2);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setEnabled(false);
        okButton->setAutoDefault(true);

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(GoToCell_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(true);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_3);

        QtDev210Class->setCentralWidget(GoToCell_2);
        menuBar = new QMenuBar(QtDev210Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 314, 26));
        QtDev210Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtDev210Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtDev210Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtDev210Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtDev210Class->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEdit, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(QtDev210Class);

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(QtDev210Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtDev210Class)
    {
        QtDev210Class->setWindowTitle(QApplication::translate("QtDev210Class", "Go To Cell", nullptr));
        label->setText(QApplication::translate("QtDev210Class", "&Cell Location", nullptr));
        okButton->setText(QApplication::translate("QtDev210Class", "OK", nullptr));
        cancelButton->setText(QApplication::translate("QtDev210Class", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtDev210Class: public Ui_QtDev210Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDEV210_H
