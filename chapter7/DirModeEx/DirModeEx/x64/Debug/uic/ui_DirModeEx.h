/********************************************************************************
** Form generated from reading UI file 'DirModeEx.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRMODEEX_H
#define UI_DIRMODEEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DirModeExClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DirModeExClass)
    {
        if (DirModeExClass->objectName().isEmpty())
            DirModeExClass->setObjectName(QString::fromUtf8("DirModeExClass"));
        DirModeExClass->resize(600, 400);
        menuBar = new QMenuBar(DirModeExClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        DirModeExClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DirModeExClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DirModeExClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DirModeExClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DirModeExClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DirModeExClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DirModeExClass->setStatusBar(statusBar);

        retranslateUi(DirModeExClass);

        QMetaObject::connectSlotsByName(DirModeExClass);
    } // setupUi

    void retranslateUi(QMainWindow *DirModeExClass)
    {
        DirModeExClass->setWindowTitle(QApplication::translate("DirModeExClass", "DirModeEx", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DirModeExClass: public Ui_DirModeExClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRMODEEX_H
