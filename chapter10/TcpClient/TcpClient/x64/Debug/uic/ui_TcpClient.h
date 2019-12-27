/********************************************************************************
** Form generated from reading UI file 'TcpClient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClientClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TcpClientClass)
    {
        if (TcpClientClass->objectName().isEmpty())
            TcpClientClass->setObjectName(QString::fromUtf8("TcpClientClass"));
        TcpClientClass->resize(600, 400);
        menuBar = new QMenuBar(TcpClientClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TcpClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TcpClientClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TcpClientClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TcpClientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TcpClientClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TcpClientClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TcpClientClass->setStatusBar(statusBar);

        retranslateUi(TcpClientClass);

        QMetaObject::connectSlotsByName(TcpClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *TcpClientClass)
    {
        TcpClientClass->setWindowTitle(QApplication::translate("TcpClientClass", "TcpClient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClientClass: public Ui_TcpClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
