/********************************************************************************
** Form generated from reading UI file 'QFileInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFILEINFO_H
#define UI_QFILEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_QFileInfoClass
{
public:

    void setupUi(QDialog *QFileInfoClass)
    {
        if (QFileInfoClass->objectName().isEmpty())
            QFileInfoClass->setObjectName(QString::fromUtf8("QFileInfoClass"));
        QFileInfoClass->resize(600, 400);

        retranslateUi(QFileInfoClass);

        QMetaObject::connectSlotsByName(QFileInfoClass);
    } // setupUi

    void retranslateUi(QDialog *QFileInfoClass)
    {
        QFileInfoClass->setWindowTitle(QApplication::translate("QFileInfoClass", "QFileInfo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QFileInfoClass: public Ui_QFileInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFILEINFO_H
