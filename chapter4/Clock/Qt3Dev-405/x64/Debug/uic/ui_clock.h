/********************************************************************************
** Form generated from reading UI file 'clock.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCK_H
#define UI_CLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClockClass
{
public:

    void setupUi(QWidget *ClockClass)
    {
        if (ClockClass->objectName().isEmpty())
            ClockClass->setObjectName(QString::fromUtf8("ClockClass"));
        ClockClass->resize(600, 400);

        retranslateUi(ClockClass);

        QMetaObject::connectSlotsByName(ClockClass);
    } // setupUi

    void retranslateUi(QWidget *ClockClass)
    {
        ClockClass->setWindowTitle(QApplication::translate("ClockClass", "Clock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockClass: public Ui_ClockClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCK_H
