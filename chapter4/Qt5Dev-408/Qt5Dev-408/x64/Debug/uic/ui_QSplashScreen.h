/********************************************************************************
** Form generated from reading UI file 'QSplashScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSPLASHSCREEN_H
#define UI_QSPLASHSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSplashScreenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QSplashScreenClass)
    {
        if (QSplashScreenClass->objectName().isEmpty())
            QSplashScreenClass->setObjectName(QString::fromUtf8("QSplashScreenClass"));
        QSplashScreenClass->resize(600, 400);
        menuBar = new QMenuBar(QSplashScreenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QSplashScreenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QSplashScreenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QSplashScreenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QSplashScreenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSplashScreenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QSplashScreenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QSplashScreenClass->setStatusBar(statusBar);

        retranslateUi(QSplashScreenClass);

        QMetaObject::connectSlotsByName(QSplashScreenClass);
    } // setupUi

    void retranslateUi(QMainWindow *QSplashScreenClass)
    {
        QSplashScreenClass->setWindowTitle(QApplication::translate("QSplashScreenClass", "QSplashScreen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSplashScreenClass: public Ui_QSplashScreenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSPLASHSCREEN_H
