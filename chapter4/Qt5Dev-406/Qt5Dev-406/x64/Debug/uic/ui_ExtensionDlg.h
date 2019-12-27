/********************************************************************************
** Form generated from reading UI file 'ExtensionDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTENSIONDLG_H
#define UI_EXTENSIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExtensionDlgClass
{
public:

    void setupUi(QWidget *ExtensionDlgClass)
    {
        if (ExtensionDlgClass->objectName().isEmpty())
            ExtensionDlgClass->setObjectName(QString::fromUtf8("ExtensionDlgClass"));
        ExtensionDlgClass->resize(600, 400);

        retranslateUi(ExtensionDlgClass);

        QMetaObject::connectSlotsByName(ExtensionDlgClass);
    } // setupUi

    void retranslateUi(QWidget *ExtensionDlgClass)
    {
        ExtensionDlgClass->setWindowTitle(QApplication::translate("ExtensionDlgClass", "ExtensionDlg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExtensionDlgClass: public Ui_ExtensionDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTENSIONDLG_H
