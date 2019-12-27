/********************************************************************************
** Form generated from reading UI file 'tcpServer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServerClass
{
public:

    void setupUi(QWidget *TcpServerClass)
    {
        if (TcpServerClass->objectName().isEmpty())
            TcpServerClass->setObjectName(QString::fromUtf8("TcpServerClass"));
        TcpServerClass->resize(600, 400);

        retranslateUi(TcpServerClass);

        QMetaObject::connectSlotsByName(TcpServerClass);
    } // setupUi

    void retranslateUi(QWidget *TcpServerClass)
    {
        TcpServerClass->setWindowTitle(QApplication::translate("TcpServerClass", "TcpServer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServerClass: public Ui_TcpServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
