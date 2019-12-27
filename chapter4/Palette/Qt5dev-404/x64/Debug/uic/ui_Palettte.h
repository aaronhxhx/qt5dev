/********************************************************************************
** Form generated from reading UI file 'Palettte.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PALETTTE_H
#define UI_PALETTTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PalettteClass
{
public:

    void setupUi(QWidget *PalettteClass)
    {
        if (PalettteClass->objectName().isEmpty())
            PalettteClass->setObjectName(QString::fromUtf8("PalettteClass"));
        PalettteClass->resize(600, 400);

        retranslateUi(PalettteClass);

        QMetaObject::connectSlotsByName(PalettteClass);
    } // setupUi

    void retranslateUi(QWidget *PalettteClass)
    {
        PalettteClass->setWindowTitle(QApplication::translate("PalettteClass", "Palettte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PalettteClass: public Ui_PalettteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PALETTTE_H
