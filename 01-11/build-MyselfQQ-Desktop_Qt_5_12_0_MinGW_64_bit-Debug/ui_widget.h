/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowserMsg;
    QFrame *frame1;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBox;
    QComboBox *comboBoxFontSize;
    QToolButton *toolButtonBold;
    QToolButton *toolButtonItalic;
    QToolButton *toolButtonUnderline;
    QToolButton *toolButtonColor;
    QToolButton *toolButtonSave;
    QToolButton *toolButtonClear;
    QFrame *frame2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditMsg;
    QFrame *frame3;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidgetusr;
    QFrame *frame4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSend;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelUserNum;
    QPushButton *pushButtonExit;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(730, 450);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(widget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowserMsg = new QTextBrowser(frame);
        textBrowserMsg->setObjectName(QString::fromUtf8("textBrowserMsg"));

        horizontalLayout_2->addWidget(textBrowserMsg);


        verticalLayout->addWidget(frame);

        frame1 = new QFrame(widget_2);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setFrameShape(QFrame::Box);
        horizontalLayout = new QHBoxLayout(frame1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        fontComboBox = new QFontComboBox(frame1);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout->addWidget(fontComboBox);

        comboBoxFontSize = new QComboBox(frame1);
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->addItem(QString());
        comboBoxFontSize->setObjectName(QString::fromUtf8("comboBoxFontSize"));

        horizontalLayout->addWidget(comboBoxFontSize);

        toolButtonBold = new QToolButton(frame1);
        toolButtonBold->setObjectName(QString::fromUtf8("toolButtonBold"));
        toolButtonBold->setMinimumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonBold->setIcon(icon);
        toolButtonBold->setIconSize(QSize(26, 26));
        toolButtonBold->setCheckable(true);

        horizontalLayout->addWidget(toolButtonBold);

        toolButtonItalic = new QToolButton(frame1);
        toolButtonItalic->setObjectName(QString::fromUtf8("toolButtonItalic"));
        toolButtonItalic->setMinimumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonItalic->setIcon(icon1);
        toolButtonItalic->setIconSize(QSize(26, 26));
        toolButtonItalic->setCheckable(true);

        horizontalLayout->addWidget(toolButtonItalic);

        toolButtonUnderline = new QToolButton(frame1);
        toolButtonUnderline->setObjectName(QString::fromUtf8("toolButtonUnderline"));
        toolButtonUnderline->setMinimumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonUnderline->setIcon(icon2);
        toolButtonUnderline->setIconSize(QSize(26, 26));
        toolButtonUnderline->setCheckable(true);

        horizontalLayout->addWidget(toolButtonUnderline);

        toolButtonColor = new QToolButton(frame1);
        toolButtonColor->setObjectName(QString::fromUtf8("toolButtonColor"));
        toolButtonColor->setMinimumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/qq.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonColor->setIcon(icon3);
        toolButtonColor->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(toolButtonColor);

        toolButtonSave = new QToolButton(frame1);
        toolButtonSave->setObjectName(QString::fromUtf8("toolButtonSave"));
        toolButtonSave->setMinimumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonSave->setIcon(icon4);
        toolButtonSave->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(toolButtonSave);

        toolButtonClear = new QToolButton(frame1);
        toolButtonClear->setObjectName(QString::fromUtf8("toolButtonClear"));
        toolButtonClear->setMinimumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonClear->setIcon(icon5);
        toolButtonClear->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(toolButtonClear);


        verticalLayout->addWidget(frame1);

        frame2 = new QFrame(widget_2);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        frame2->setMaximumSize(QSize(16777215, 100));
        frame2->setFrameShape(QFrame::Box);
        verticalLayout_2 = new QVBoxLayout(frame2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEditMsg = new QTextEdit(frame2);
        textEditMsg->setObjectName(QString::fromUtf8("textEditMsg"));
        textEditMsg->setMaximumSize(QSize(16777215, 100));

        verticalLayout_2->addWidget(textEditMsg);


        verticalLayout->addWidget(frame2);


        horizontalLayout_4->addWidget(widget_2);

        frame3 = new QFrame(widget_3);
        frame3->setObjectName(QString::fromUtf8("frame3"));
        frame3->setMaximumSize(QSize(180, 16777215));
        frame3->setFrameShape(QFrame::Box);
        horizontalLayout_3 = new QHBoxLayout(frame3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidgetusr = new QTableWidget(frame3);
        if (tableWidgetusr->columnCount() < 1)
            tableWidgetusr->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetusr->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetusr->setObjectName(QString::fromUtf8("tableWidgetusr"));
        tableWidgetusr->setMaximumSize(QSize(180, 16777215));
        tableWidgetusr->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetusr->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetusr->setShowGrid(false);

        horizontalLayout_3->addWidget(tableWidgetusr);


        horizontalLayout_4->addWidget(frame3);


        verticalLayout_3->addWidget(widget_3);

        frame4 = new QFrame(Widget);
        frame4->setObjectName(QString::fromUtf8("frame4"));
        frame4->setFrameShape(QFrame::Box);
        horizontalLayout_5 = new QHBoxLayout(frame4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(46, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButtonSend = new QPushButton(frame4);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        horizontalLayout_5->addWidget(pushButtonSend);

        horizontalSpacer_2 = new QSpacerItem(46, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        labelUserNum = new QLabel(frame4);
        labelUserNum->setObjectName(QString::fromUtf8("labelUserNum"));

        horizontalLayout_5->addWidget(labelUserNum);

        pushButtonExit = new QPushButton(frame4);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));

        horizontalLayout_5->addWidget(pushButtonExit);

        horizontalSpacer_3 = new QSpacerItem(46, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(frame4);


        retranslateUi(Widget);

        comboBoxFontSize->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        comboBoxFontSize->setItemText(0, QApplication::translate("Widget", "8", nullptr));
        comboBoxFontSize->setItemText(1, QApplication::translate("Widget", "9", nullptr));
        comboBoxFontSize->setItemText(2, QApplication::translate("Widget", "10", nullptr));
        comboBoxFontSize->setItemText(3, QApplication::translate("Widget", "11", nullptr));
        comboBoxFontSize->setItemText(4, QApplication::translate("Widget", "12", nullptr));
        comboBoxFontSize->setItemText(5, QApplication::translate("Widget", "13", nullptr));
        comboBoxFontSize->setItemText(6, QApplication::translate("Widget", "14", nullptr));
        comboBoxFontSize->setItemText(7, QApplication::translate("Widget", "15", nullptr));
        comboBoxFontSize->setItemText(8, QApplication::translate("Widget", "16", nullptr));
        comboBoxFontSize->setItemText(9, QApplication::translate("Widget", "17", nullptr));
        comboBoxFontSize->setItemText(10, QApplication::translate("Widget", "18", nullptr));
        comboBoxFontSize->setItemText(11, QApplication::translate("Widget", "19", nullptr));
        comboBoxFontSize->setItemText(12, QApplication::translate("Widget", "20", nullptr));
        comboBoxFontSize->setItemText(13, QApplication::translate("Widget", "21", nullptr));
        comboBoxFontSize->setItemText(14, QApplication::translate("Widget", "22", nullptr));

#ifndef QT_NO_TOOLTIP
        toolButtonBold->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonBold->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonItalic->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonItalic->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonUnderline->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonUnderline->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonColor->setToolTip(QApplication::translate("Widget", "\346\233\264\346\224\271\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonColor->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonSave->setToolTip(QApplication::translate("Widget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonSave->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonClear->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonClear->setText(QApplication::translate("Widget", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetusr->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        pushButtonSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        labelUserNum->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\347\224\250\346\210\267:  0\344\272\272", nullptr));
        pushButtonExit->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
