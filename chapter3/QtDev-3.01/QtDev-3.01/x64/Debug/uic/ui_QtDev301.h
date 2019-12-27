/********************************************************************************
** Form generated from reading UI file 'QtDev301.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDEV301_H
#define UI_QTDEV301_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDev301Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtDev301Class)
    {
        if (QtDev301Class->objectName().isEmpty())
            QtDev301Class->setObjectName(QString::fromUtf8("QtDev301Class"));
        QtDev301Class->resize(600, 400);
        menuBar = new QMenuBar(QtDev301Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtDev301Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtDev301Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtDev301Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtDev301Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtDev301Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtDev301Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtDev301Class->setStatusBar(statusBar);

        retranslateUi(QtDev301Class);

        QMetaObject::connectSlotsByName(QtDev301Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtDev301Class)
    {
        QtDev301Class->setWindowTitle(QApplication::translate("QtDev301Class", "QtDev301", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtDev301Class: public Ui_QtDev301Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDEV301_H
