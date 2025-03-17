/********************************************************************************
** Form generated from reading UI file 'orders.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERS_H
#define UI_ORDERS_H

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

class Ui_orders
{
public:
    QWidget *widget;
    QPushButton *pushButton;
    QTableView *tableView;
    QLabel *label_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QDateEdit *dateEdit_2;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QSpinBox *spinBox_4;
    QFormLayout *formLayout_4;
    QLabel *label_4;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_2;

    void setupUi(QWidget *orders)
    {
        if (orders->objectName().isEmpty())
            orders->setObjectName("orders");
        orders->resize(800, 600);
        widget = new QWidget(orders);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/10002.png);}"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 170, 92, 28));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(90, 220, 421, 301));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 40, 791, 91));
        QFont font;
        font.setPointSize(40);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(530, 280, 197, 164));
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

        dateEdit_2 = new QDateEdit(layoutWidget);
        dateEdit_2->setObjectName("dateEdit_2");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, dateEdit_2);


        verticalLayout->addLayout(formLayout_2);

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


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);


        retranslateUi(orders);

        QMetaObject::connectSlotsByName(orders);
    } // setupUi

    void retranslateUi(QWidget *orders)
    {
        orders->setWindowTitle(QCoreApplication::translate("orders", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("orders", "\350\277\224\345\233\236", nullptr));
        label_5->setText(QCoreApplication::translate("orders", "\350\256\242\345\215\225", nullptr));
        label->setText(QCoreApplication::translate("orders", "\350\256\242\345\215\225\345\217\267       ", nullptr));
        label_3->setText(QCoreApplication::translate("orders", "\350\256\242\345\215\225\346\227\245\346\234\237   ", nullptr));
        label_2->setText(QCoreApplication::translate("orders", "\345\256\242\346\210\267id       ", nullptr));
        label_4->setText(QCoreApplication::translate("orders", "\346\224\266\351\223\266\345\221\230id   ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("orders", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orders: public Ui_orders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERS_H
