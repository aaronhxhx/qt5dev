/********************************************************************************
** Form generated from reading UI file 'Qt5Dev303.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT5DEV303_H
#define UI_QT5DEV303_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt5Dev303Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt5Dev303Class)
    {
        if (Qt5Dev303Class->objectName().isEmpty())
            Qt5Dev303Class->setObjectName(QString::fromUtf8("Qt5Dev303Class"));
        Qt5Dev303Class->resize(600, 400);
        menuBar = new QMenuBar(Qt5Dev303Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Qt5Dev303Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt5Dev303Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt5Dev303Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt5Dev303Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Qt5Dev303Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt5Dev303Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt5Dev303Class->setStatusBar(statusBar);

        retranslateUi(Qt5Dev303Class);

        QMetaObject::connectSlotsByName(Qt5Dev303Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qt5Dev303Class)
    {
        Qt5Dev303Class->setWindowTitle(QApplication::translate("Qt5Dev303Class", "Qt5Dev303", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt5Dev303Class: public Ui_Qt5Dev303Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT5DEV303_H
