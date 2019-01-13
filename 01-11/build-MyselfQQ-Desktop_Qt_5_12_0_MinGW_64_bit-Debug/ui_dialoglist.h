/********************************************************************************
** Form generated from reading UI file 'dialoglist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLIST_H
#define UI_DIALOGLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogList
{
public:
    QHBoxLayout *horizontalLayout;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *DialogList)
    {
        if (DialogList->objectName().isEmpty())
            DialogList->setObjectName(QString::fromUtf8("DialogList"));
        DialogList->resize(250, 700);
        horizontalLayout = new QHBoxLayout(DialogList);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(DialogList);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setFocusPolicy(Qt::NoFocus);
        toolBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        toolBox->setLayoutDirection(Qt::LeftToRight);
        toolBox->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 250, 668));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolBox->addItem(page, QString::fromUtf8("\347\276\244\346\210\220\345\221\230"));

        horizontalLayout->addWidget(toolBox);


        retranslateUi(DialogList);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogList);
    } // setupUi

    void retranslateUi(QWidget *DialogList)
    {
        DialogList->setWindowTitle(QApplication::translate("DialogList", "Form", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("DialogList", "\347\276\244\346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogList: public Ui_DialogList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLIST_H
