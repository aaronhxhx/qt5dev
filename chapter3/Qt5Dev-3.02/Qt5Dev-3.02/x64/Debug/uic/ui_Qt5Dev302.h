/********************************************************************************
** Form generated from reading UI file 'Qt5Dev302.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT5DEV302_H
#define UI_QT5DEV302_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt5Dev302Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt5Dev302Class)
    {
        if (Qt5Dev302Class->objectName().isEmpty())
            Qt5Dev302Class->setObjectName(QString::fromUtf8("Qt5Dev302Class"));
        Qt5Dev302Class->resize(600, 400);
        menuBar = new QMenuBar(Qt5Dev302Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Qt5Dev302Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt5Dev302Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt5Dev302Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt5Dev302Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Qt5Dev302Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt5Dev302Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt5Dev302Class->setStatusBar(statusBar);

        retranslateUi(Qt5Dev302Class);

        QMetaObject::connectSlotsByName(Qt5Dev302Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qt5Dev302Class)
    {
        Qt5Dev302Class->setWindowTitle(QApplication::translate("Qt5Dev302Class", "Qt5Dev302", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt5Dev302Class: public Ui_Qt5Dev302Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT5DEV302_H
