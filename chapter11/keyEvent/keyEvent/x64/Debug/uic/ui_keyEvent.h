/********************************************************************************
** Form generated from reading UI file 'keyEvent.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYEVENT_H
#define UI_KEYEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyEventClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KeyEventClass)
    {
        if (KeyEventClass->objectName().isEmpty())
            KeyEventClass->setObjectName(QString::fromUtf8("KeyEventClass"));
        KeyEventClass->resize(600, 400);
        menuBar = new QMenuBar(KeyEventClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        KeyEventClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KeyEventClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        KeyEventClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(KeyEventClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        KeyEventClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(KeyEventClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        KeyEventClass->setStatusBar(statusBar);

        retranslateUi(KeyEventClass);

        QMetaObject::connectSlotsByName(KeyEventClass);
    } // setupUi

    void retranslateUi(QMainWindow *KeyEventClass)
    {
        KeyEventClass->setWindowTitle(QApplication::translate("KeyEventClass", "KeyEvent", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KeyEventClass: public Ui_KeyEventClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYEVENT_H
