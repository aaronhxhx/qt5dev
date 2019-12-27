/********************************************************************************
** Form generated from reading UI file 'threadDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADDLG_H
#define UI_THREADDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ThreadDlgClass
{
public:

    void setupUi(QDialog *ThreadDlgClass)
    {
        if (ThreadDlgClass->objectName().isEmpty())
            ThreadDlgClass->setObjectName(QString::fromUtf8("ThreadDlgClass"));
        ThreadDlgClass->resize(600, 400);

        retranslateUi(ThreadDlgClass);

        QMetaObject::connectSlotsByName(ThreadDlgClass);
    } // setupUi

    void retranslateUi(QDialog *ThreadDlgClass)
    {
        ThreadDlgClass->setWindowTitle(QApplication::translate("ThreadDlgClass", "ThreadDlg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThreadDlgClass: public Ui_ThreadDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADDLG_H
