/********************************************************************************
** Form generated from reading UI file 'QtLabWorks.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTLABWORKS_H
#define UI_QTLABWORKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLabWorksClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtLabWorksClass)
    {
        if (QtLabWorksClass->objectName().isEmpty())
            QtLabWorksClass->setObjectName(QString::fromUtf8("QtLabWorksClass"));
        QtLabWorksClass->resize(600, 400);
        menuBar = new QMenuBar(QtLabWorksClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtLabWorksClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtLabWorksClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtLabWorksClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtLabWorksClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtLabWorksClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtLabWorksClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtLabWorksClass->setStatusBar(statusBar);

        retranslateUi(QtLabWorksClass);

        QMetaObject::connectSlotsByName(QtLabWorksClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtLabWorksClass)
    {
        QtLabWorksClass->setWindowTitle(QApplication::translate("QtLabWorksClass", "QtLabWorks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtLabWorksClass: public Ui_QtLabWorksClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLABWORKS_H
