/********************************************************************************
** Form generated from reading UI file 'ProgressDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDLG_H
#define UI_PROGRESSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressDlgClass
{
public:

    void setupUi(QWidget *ProgressDlgClass)
    {
        if (ProgressDlgClass->objectName().isEmpty())
            ProgressDlgClass->setObjectName(QString::fromUtf8("ProgressDlgClass"));
        ProgressDlgClass->resize(600, 400);

        retranslateUi(ProgressDlgClass);

        QMetaObject::connectSlotsByName(ProgressDlgClass);
    } // setupUi

    void retranslateUi(QWidget *ProgressDlgClass)
    {
        ProgressDlgClass->setWindowTitle(QApplication::translate("ProgressDlgClass", "ProgressDlg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressDlgClass: public Ui_ProgressDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDLG_H
