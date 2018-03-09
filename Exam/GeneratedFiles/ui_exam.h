/********************************************************************************
** Form generated from reading UI file 'exam.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM_H
#define UI_EXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamClass)
    {
        if (ExamClass->objectName().isEmpty())
            ExamClass->setObjectName(QStringLiteral("ExamClass"));
        ExamClass->resize(600, 400);
        menuBar = new QMenuBar(ExamClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ExamClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ExamClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ExamClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ExamClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ExamClass->setStatusBar(statusBar);

        retranslateUi(ExamClass);

        QMetaObject::connectSlotsByName(ExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamClass)
    {
        ExamClass->setWindowTitle(QApplication::translate("ExamClass", "Exam", 0));
    } // retranslateUi

};

namespace Ui {
    class ExamClass: public Ui_ExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM_H
