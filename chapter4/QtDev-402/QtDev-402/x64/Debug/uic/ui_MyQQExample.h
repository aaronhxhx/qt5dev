/********************************************************************************
** Form generated from reading UI file 'MyQQExample.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQQEXAMPLE_H
#define UI_MYQQEXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyQQExampleClass
{
public:

    void setupUi(QWidget *MyQQExampleClass)
    {
        if (MyQQExampleClass->objectName().isEmpty())
            MyQQExampleClass->setObjectName(QString::fromUtf8("MyQQExampleClass"));
        MyQQExampleClass->resize(600, 400);

        retranslateUi(MyQQExampleClass);

        QMetaObject::connectSlotsByName(MyQQExampleClass);
    } // setupUi

    void retranslateUi(QWidget *MyQQExampleClass)
    {
        MyQQExampleClass->setWindowTitle(QApplication::translate("MyQQExampleClass", "MyQQExample", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyQQExampleClass: public Ui_MyQQExampleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQQEXAMPLE_H
