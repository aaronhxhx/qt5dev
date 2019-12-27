/********************************************************************************
** Form generated from reading UI file 'ImgProcessor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGPROCESSOR_H
#define UI_IMGPROCESSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgProcessorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImgProcessorClass)
    {
        if (ImgProcessorClass->objectName().isEmpty())
            ImgProcessorClass->setObjectName(QString::fromUtf8("ImgProcessorClass"));
        ImgProcessorClass->resize(600, 400);
        menuBar = new QMenuBar(ImgProcessorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ImgProcessorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImgProcessorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImgProcessorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ImgProcessorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ImgProcessorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ImgProcessorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImgProcessorClass->setStatusBar(statusBar);

        retranslateUi(ImgProcessorClass);

        QMetaObject::connectSlotsByName(ImgProcessorClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImgProcessorClass)
    {
        ImgProcessorClass->setWindowTitle(QApplication::translate("ImgProcessorClass", "ImgProcessor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImgProcessorClass: public Ui_ImgProcessorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGPROCESSOR_H
