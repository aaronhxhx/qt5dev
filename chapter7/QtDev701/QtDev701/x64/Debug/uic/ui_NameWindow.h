/********************************************************************************
** Form generated from reading UI file 'NameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMEWINDOW_H
#define UI_NAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NameWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NameWindowClass)
    {
        if (NameWindowClass->objectName().isEmpty())
            NameWindowClass->setObjectName(QString::fromUtf8("NameWindowClass"));
        NameWindowClass->resize(600, 400);
        menuBar = new QMenuBar(NameWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        NameWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NameWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        NameWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NameWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        NameWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NameWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        NameWindowClass->setStatusBar(statusBar);

        retranslateUi(NameWindowClass);

        QMetaObject::connectSlotsByName(NameWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *NameWindowClass)
    {
        NameWindowClass->setWindowTitle(QApplication::translate("NameWindowClass", "NameWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NameWindowClass: public Ui_NameWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMEWINDOW_H
