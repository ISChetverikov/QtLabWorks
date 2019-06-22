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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLabWorksClass
{
public:
    QWidget *centralWidget;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtLabWorksClass)
    {
        if (QtLabWorksClass->objectName().isEmpty())
            QtLabWorksClass->setObjectName(QString::fromUtf8("QtLabWorksClass"));
        QtLabWorksClass->resize(207, 209);
        centralWidget = new QWidget(QtLabWorksClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 10, 141, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(7);
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(20, 50, 141, 22));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(7);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 120, 75, 23));
        QtLabWorksClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtLabWorksClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 207, 21));
        QtLabWorksClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtLabWorksClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtLabWorksClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtLabWorksClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtLabWorksClass->setStatusBar(statusBar);

        retranslateUi(QtLabWorksClass);

        QMetaObject::connectSlotsByName(QtLabWorksClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtLabWorksClass)
    {
        QtLabWorksClass->setWindowTitle(QApplication::translate("QtLabWorksClass", "QtLabWorks", nullptr));
        pushButton->setText(QApplication::translate("QtLabWorksClass", "Visualizate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtLabWorksClass: public Ui_QtLabWorksClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLABWORKS_H
