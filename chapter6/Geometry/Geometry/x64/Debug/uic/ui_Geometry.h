/********************************************************************************
** Form generated from reading UI file 'Geometry.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEOMETRY_H
#define UI_GEOMETRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeometryClass
{
public:

    void setupUi(QWidget *GeometryClass)
    {
        if (GeometryClass->objectName().isEmpty())
            GeometryClass->setObjectName(QString::fromUtf8("GeometryClass"));
        GeometryClass->resize(600, 400);

        retranslateUi(GeometryClass);

        QMetaObject::connectSlotsByName(GeometryClass);
    } // setupUi

    void retranslateUi(QWidget *GeometryClass)
    {
        GeometryClass->setWindowTitle(QApplication::translate("GeometryClass", "Geometry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeometryClass: public Ui_GeometryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEOMETRY_H
