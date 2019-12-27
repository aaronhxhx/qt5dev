/********************************************************************************
** Form generated from reading UI file 'textFile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTFILE_H
#define UI_TEXTFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textFileClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *textFileClass)
    {
        if (textFileClass->objectName().isEmpty())
            textFileClass->setObjectName(QString::fromUtf8("textFileClass"));
        textFileClass->resize(600, 400);
        menuBar = new QMenuBar(textFileClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        textFileClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(textFileClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        textFileClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(textFileClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textFileClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(textFileClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        textFileClass->setStatusBar(statusBar);

        retranslateUi(textFileClass);

        QMetaObject::connectSlotsByName(textFileClass);
    } // setupUi

    void retranslateUi(QMainWindow *textFileClass)
    {
        textFileClass->setWindowTitle(QApplication::translate("textFileClass", "textFile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textFileClass: public Ui_textFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTFILE_H
