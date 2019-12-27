/********************************************************************************
** Form generated from reading UI file 'SVGTest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SVGTEST_H
#define UI_SVGTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SVGTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SVGTestClass)
    {
        if (SVGTestClass->objectName().isEmpty())
            SVGTestClass->setObjectName(QString::fromUtf8("SVGTestClass"));
        SVGTestClass->resize(600, 400);
        menuBar = new QMenuBar(SVGTestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        SVGTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SVGTestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SVGTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SVGTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SVGTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SVGTestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SVGTestClass->setStatusBar(statusBar);

        retranslateUi(SVGTestClass);

        QMetaObject::connectSlotsByName(SVGTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *SVGTestClass)
    {
        SVGTestClass->setWindowTitle(QApplication::translate("SVGTestClass", "SVGTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SVGTestClass: public Ui_SVGTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SVGTEST_H
