/********************************************************************************
** Form generated from reading UI file 'FileView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEVIEW_H
#define UI_FILEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_FileViewClass
{
public:

    void setupUi(QDialog *FileViewClass)
    {
        if (FileViewClass->objectName().isEmpty())
            FileViewClass->setObjectName(QString::fromUtf8("FileViewClass"));
        FileViewClass->resize(600, 400);

        retranslateUi(FileViewClass);

        QMetaObject::connectSlotsByName(FileViewClass);
    } // setupUi

    void retranslateUi(QDialog *FileViewClass)
    {
        FileViewClass->setWindowTitle(QApplication::translate("FileViewClass", "FileView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileViewClass: public Ui_FileViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEVIEW_H
