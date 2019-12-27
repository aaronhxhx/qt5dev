/********************************************************************************
** Form generated from reading UI file 'FileWatcher.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEWATCHER_H
#define UI_FILEWATCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileWatcherClass
{
public:

    void setupUi(QWidget *FileWatcherClass)
    {
        if (FileWatcherClass->objectName().isEmpty())
            FileWatcherClass->setObjectName(QString::fromUtf8("FileWatcherClass"));
        FileWatcherClass->resize(600, 400);

        retranslateUi(FileWatcherClass);

        QMetaObject::connectSlotsByName(FileWatcherClass);
    } // setupUi

    void retranslateUi(QWidget *FileWatcherClass)
    {
        FileWatcherClass->setWindowTitle(QApplication::translate("FileWatcherClass", "FileWatcher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileWatcherClass: public Ui_FileWatcherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEWATCHER_H
