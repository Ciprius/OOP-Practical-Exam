/********************************************************************************
** Form generated from reading UI file 'controller.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controller
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *textEdit;
    QLabel *label_3;
    QLineEdit *answerEdit;
    QLabel *label_4;
    QLineEdit *scoreEdit;
    QPushButton *addButton;
    QPushButton *answerButton;

    void setupUi(QWidget *Controller)
    {
        if (Controller->objectName().isEmpty())
            Controller->setObjectName(QStringLiteral("Controller"));
        Controller->resize(305, 566);
        gridLayout_2 = new QGridLayout(Controller);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget = new QListWidget(Controller);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        label = new QLabel(Controller);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        idEdit = new QLineEdit(Controller);
        idEdit->setObjectName(QStringLiteral("idEdit"));

        gridLayout->addWidget(idEdit, 1, 1, 1, 1);

        label_2 = new QLabel(Controller);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        textEdit = new QLineEdit(Controller);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 2, 1, 1, 1);

        label_3 = new QLabel(Controller);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        answerEdit = new QLineEdit(Controller);
        answerEdit->setObjectName(QStringLiteral("answerEdit"));

        gridLayout->addWidget(answerEdit, 3, 1, 1, 1);

        label_4 = new QLabel(Controller);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        scoreEdit = new QLineEdit(Controller);
        scoreEdit->setObjectName(QStringLiteral("scoreEdit"));

        gridLayout->addWidget(scoreEdit, 4, 1, 1, 1);

        addButton = new QPushButton(Controller);
        addButton->setObjectName(QStringLiteral("addButton"));

        gridLayout->addWidget(addButton, 5, 0, 1, 1);

        answerButton = new QPushButton(Controller);
        answerButton->setObjectName(QStringLiteral("answerButton"));

        gridLayout->addWidget(answerButton, 5, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Controller);

        QMetaObject::connectSlotsByName(Controller);
    } // setupUi

    void retranslateUi(QWidget *Controller)
    {
        Controller->setWindowTitle(QApplication::translate("Controller", "Controller", 0));
        label->setText(QApplication::translate("Controller", "q id:", 0));
        label_2->setText(QApplication::translate("Controller", "Text:", 0));
        label_3->setText(QApplication::translate("Controller", "Answer:", 0));
        label_4->setText(QApplication::translate("Controller", "Score:", 0));
        addButton->setText(QApplication::translate("Controller", "ADD", 0));
        answerButton->setText(QApplication::translate("Controller", "ANSWER", 0));
    } // retranslateUi

};

namespace Ui {
    class Controller: public Ui_Controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_H
