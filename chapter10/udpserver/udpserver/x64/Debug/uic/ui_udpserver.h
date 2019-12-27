/********************************************************************************
** Form generated from reading UI file 'udpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPSERVER_H
#define UI_UDPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_udpserverClass
{
public:

    void setupUi(QWidget *udpserverClass)
    {
        if (udpserverClass->objectName().isEmpty())
            udpserverClass->setObjectName(QString::fromUtf8("udpserverClass"));
        udpserverClass->resize(600, 400);

        retranslateUi(udpserverClass);

        QMetaObject::connectSlotsByName(udpserverClass);
    } // setupUi

    void retranslateUi(QWidget *udpserverClass)
    {
        udpserverClass->setWindowTitle(QApplication::translate("udpserverClass", "udpserver", nullptr));
    } // retranslateUi

};

namespace Ui {
    class udpserverClass: public Ui_udpserverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPSERVER_H
