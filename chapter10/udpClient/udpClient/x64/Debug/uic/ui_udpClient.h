/********************************************************************************
** Form generated from reading UI file 'udpClient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPCLIENT_H
#define UI_UDPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UdpClientClass
{
public:

    void setupUi(QWidget *UdpClientClass)
    {
        if (UdpClientClass->objectName().isEmpty())
            UdpClientClass->setObjectName(QString::fromUtf8("UdpClientClass"));
        UdpClientClass->resize(600, 400);

        retranslateUi(UdpClientClass);

        QMetaObject::connectSlotsByName(UdpClientClass);
    } // setupUi

    void retranslateUi(QWidget *UdpClientClass)
    {
        UdpClientClass->setWindowTitle(QApplication::translate("UdpClientClass", "UdpClient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UdpClientClass: public Ui_UdpClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPCLIENT_H
