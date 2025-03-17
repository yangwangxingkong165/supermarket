/********************************************************************************
** Form generated from reading UI file 'purchase.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASE_H
#define UI_PURCHASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_purchase
{
public:
    QWidget *widget;
    QTableView *tableView;
    QPushButton *pushButton;
    QLabel *label_55;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox_3;
    QFormLayout *formLayout_6;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QSpinBox *spinBox_4;
    QFormLayout *formLayout_4;
    QLabel *label_4;
    QSpinBox *spinBox_5;
    QFormLayout *formLayout_5;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QPushButton *pushButton_2;

    void setupUi(QWidget *purchase)
    {
        if (purchase->objectName().isEmpty())
            purchase->setObjectName("purchase");
        purchase->resize(800, 600);
        widget = new QWidget(purchase);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/2.png);}"));
        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(80, 220, 421, 301));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 180, 92, 28));
        label_55 = new QLabel(widget);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(0, 50, 801, 121));
        QFont font;
        font.setPointSize(40);
        label_55->setFont(font);
        label_55->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(530, 260, 197, 230));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName("spinBox");

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBox_3 = new QSpinBox(layoutWidget);
        spinBox_3->setObjectName("spinBox_3");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox_3);


        verticalLayout->addLayout(formLayout_2);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName("formLayout_6");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_6);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName("spinBox_2");

        formLayout_6->setWidget(0, QFormLayout::FieldRole, spinBox_2);


        verticalLayout->addLayout(formLayout_6);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        spinBox_4 = new QSpinBox(layoutWidget);
        spinBox_4->setObjectName("spinBox_4");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBox_4);


        verticalLayout->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_4);

        spinBox_5 = new QSpinBox(layoutWidget);
        spinBox_5->setObjectName("spinBox_5");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, spinBox_5);


        verticalLayout->addLayout(formLayout_4);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName("formLayout_5");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_5);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName("dateEdit");

        formLayout_5->setWidget(0, QFormLayout::FieldRole, dateEdit);


        verticalLayout->addLayout(formLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);


        retranslateUi(purchase);

        QMetaObject::connectSlotsByName(purchase);
    } // setupUi

    void retranslateUi(QWidget *purchase)
    {
        purchase->setWindowTitle(QCoreApplication::translate("purchase", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("purchase", "\350\277\224\345\233\236", nullptr));
        label_55->setText(QCoreApplication::translate("purchase", "\350\277\233\350\264\247", nullptr));
        label->setText(QCoreApplication::translate("purchase", "\350\277\233\350\264\247\345\215\225\345\217\267   ", nullptr));
        label_3->setText(QCoreApplication::translate("purchase", "\345\225\206\345\223\201id       ", nullptr));
        label_6->setText(QCoreApplication::translate("purchase", "\344\273\223\345\272\223id       ", nullptr));
        label_2->setText(QCoreApplication::translate("purchase", "\351\207\207\350\264\255\346\225\260\351\207\217   ", nullptr));
        label_4->setText(QCoreApplication::translate("purchase", "\344\276\233\350\264\247\345\225\206id   ", nullptr));
        label_5->setText(QCoreApplication::translate("purchase", "\351\207\207\350\264\255\346\227\245\346\234\237   ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("purchase", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class purchase: public Ui_purchase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASE_H
