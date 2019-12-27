/********************************************************************************
** Form generated from reading UI file 'ShapeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPEWIDGET_H
#define UI_SHAPEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShapeWidgetClass
{
public:

    void setupUi(QWidget *ShapeWidgetClass)
    {
        if (ShapeWidgetClass->objectName().isEmpty())
            ShapeWidgetClass->setObjectName(QString::fromUtf8("ShapeWidgetClass"));
        ShapeWidgetClass->resize(600, 400);

        retranslateUi(ShapeWidgetClass);

        QMetaObject::connectSlotsByName(ShapeWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ShapeWidgetClass)
    {
        ShapeWidgetClass->setWindowTitle(QApplication::translate("ShapeWidgetClass", "ShapeWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShapeWidgetClass: public Ui_ShapeWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPEWIDGET_H
