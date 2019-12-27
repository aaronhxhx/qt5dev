/********************************************************************************
** Form generated from reading UI file 'mouseEvent.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSEEVENT_H
#define UI_MOUSEEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MouseEventClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MouseEventClass)
    {
        if (MouseEventClass->objectName().isEmpty())
            MouseEventClass->setObjectName(QString::fromUtf8("MouseEventClass"));
        MouseEventClass->resize(600, 400);
        menuBar = new QMenuBar(MouseEventClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MouseEventClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MouseEventClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MouseEventClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MouseEventClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MouseEventClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MouseEventClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MouseEventClass->setStatusBar(statusBar);

        retranslateUi(MouseEventClass);

        QMetaObject::connectSlotsByName(MouseEventClass);
    } // setupUi

    void retranslateUi(QMainWindow *MouseEventClass)
    {
        MouseEventClass->setWindowTitle(QApplication::translate("MouseEventClass", "MouseEvent", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MouseEventClass: public Ui_MouseEventClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSEEVENT_H
