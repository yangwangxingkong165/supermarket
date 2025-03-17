/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_31;
    QPushButton *pushButton_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QPushButton *pushButton_2;
    QPushButton *pushButton_34;
    QPushButton *pushButton;
    QPushButton *pushButton_35;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(957, 600);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 957, 600));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/10002.png);}\n"
"#QPushButton{font: 9pt \"\345\256\213\344\275\223\";}\n"
""));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 70, 901, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_26 = new QPushButton(layoutWidget);
        pushButton_26->setObjectName("pushButton_26");

        horizontalLayout_3->addWidget(pushButton_26);

        pushButton_27 = new QPushButton(layoutWidget);
        pushButton_27->setObjectName("pushButton_27");

        horizontalLayout_3->addWidget(pushButton_27);

        pushButton_28 = new QPushButton(layoutWidget);
        pushButton_28->setObjectName("pushButton_28");

        horizontalLayout_3->addWidget(pushButton_28);

        pushButton_29 = new QPushButton(layoutWidget);
        pushButton_29->setObjectName("pushButton_29");

        horizontalLayout_3->addWidget(pushButton_29);

        pushButton_30 = new QPushButton(layoutWidget);
        pushButton_30->setObjectName("pushButton_30");

        horizontalLayout_3->addWidget(pushButton_30);

        pushButton_31 = new QPushButton(layoutWidget);
        pushButton_31->setObjectName("pushButton_31");

        horizontalLayout_3->addWidget(pushButton_31);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_3->addWidget(pushButton_4);

        layoutWidget_2 = new QWidget(widget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(780, 150, 146, 380));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(layoutWidget_2);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_32 = new QPushButton(layoutWidget_2);
        pushButton_32->setObjectName("pushButton_32");

        verticalLayout_3->addWidget(pushButton_32);

        pushButton_33 = new QPushButton(layoutWidget_2);
        pushButton_33->setObjectName("pushButton_33");

        verticalLayout_3->addWidget(pushButton_33);

        pushButton_2 = new QPushButton(layoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_34 = new QPushButton(layoutWidget_2);
        pushButton_34->setObjectName("pushButton_34");

        verticalLayout_3->addWidget(pushButton_34);

        pushButton = new QPushButton(layoutWidget_2);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);

        pushButton_35 = new QPushButton(layoutWidget_2);
        pushButton_35->setObjectName("pushButton_35");

        verticalLayout_3->addWidget(pushButton_35);

        pushButton_8 = new QPushButton(layoutWidget_2);
        pushButton_8->setObjectName("pushButton_8");

        verticalLayout_3->addWidget(pushButton_8);

        pushButton_3 = new QPushButton(layoutWidget_2);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_9 = new QPushButton(layoutWidget_2);
        pushButton_9->setObjectName("pushButton_9");

        verticalLayout_3->addWidget(pushButton_9);

        pushButton_7 = new QPushButton(layoutWidget_2);
        pushButton_7->setObjectName("pushButton_7");

        verticalLayout_3->addWidget(pushButton_7);

        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 110, 761, 471));
        tableView->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 957, 60));
        label->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/11.png);}"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/11.png")));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 0, 60, 60));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/4.png")));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 110, 761, 471));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/5.png")));
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 30, 122, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_26->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        pushButton_27->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\350\277\233\350\264\247\344\277\241\346\201\257", nullptr));
        pushButton_28->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\344\273\223\345\272\223\344\277\241\346\201\257", nullptr));
        pushButton_29->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\345\225\206\345\223\201\345\272\223\345\255\230", nullptr));
        pushButton_30->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\346\211\200\346\234\211\350\256\242\345\215\225", nullptr));
        pushButton_31->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\346\211\200\346\234\211\350\257\246\345\215\225", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\344\270\200\345\244\251\351\224\200\345\224\256\351\242\235", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "\350\277\233\350\264\247", nullptr));
        pushButton_32->setText(QCoreApplication::translate("Widget", "\346\226\260\345\273\272\350\256\242\345\215\225", nullptr));
        pushButton_33->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\350\207\263\350\256\242\345\215\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        pushButton_34->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271\345\225\206\345\223\201\351\224\200\345\224\256\345\215\225\344\273\267", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\344\273\223\345\272\223\344\277\241\346\201\257", nullptr));
        pushButton_35->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271\344\273\223\345\272\223\344\277\241\346\201\257", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\347\216\260\346\234\211\347\256\241\347\220\206\345\221\230\350\264\246\345\217\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\347\256\241\347\220\206\345\221\230\350\264\246\345\217\267", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
