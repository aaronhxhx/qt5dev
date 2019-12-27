/********************************************************************************
** Form generated from reading UI file 'NetworkInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKINFO_H
#define UI_NETWORKINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkInfoClass
{
public:

    void setupUi(QWidget *NetworkInfoClass)
    {
        if (NetworkInfoClass->objectName().isEmpty())
            NetworkInfoClass->setObjectName(QString::fromUtf8("NetworkInfoClass"));
        NetworkInfoClass->resize(600, 400);

        retranslateUi(NetworkInfoClass);

        QMetaObject::connectSlotsByName(NetworkInfoClass);
    } // setupUi

    void retranslateUi(QWidget *NetworkInfoClass)
    {
        NetworkInfoClass->setWindowTitle(QApplication::translate("NetworkInfoClass", "NetworkInfo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkInfoClass: public Ui_NetworkInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKINFO_H
