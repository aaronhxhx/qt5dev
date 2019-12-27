/********************************************************************************
** Form generated from reading UI file 'Qt5Dev209.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT5DEV209_H
#define UI_QT5DEV209_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt5Dev209Class
{
public:
    QWidget *centralWidget;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt5Dev209Class)
    {
        if (Qt5Dev209Class->objectName().isEmpty())
            Qt5Dev209Class->setObjectName(QString::fromUtf8("Qt5Dev209Class"));
        Qt5Dev209Class->resize(600, 400);
        centralWidget = new QWidget(Qt5Dev209Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(80, 70, 256, 192));
        Qt5Dev209Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qt5Dev209Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        Qt5Dev209Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt5Dev209Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt5Dev209Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qt5Dev209Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt5Dev209Class->setStatusBar(statusBar);

        retranslateUi(Qt5Dev209Class);

        QMetaObject::connectSlotsByName(Qt5Dev209Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qt5Dev209Class)
    {
        Qt5Dev209Class->setWindowTitle(QApplication::translate("Qt5Dev209Class", "Qt5Dev209", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt5Dev209Class: public Ui_Qt5Dev209Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT5DEV209_H
