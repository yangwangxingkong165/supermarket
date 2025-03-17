/********************************************************************************
** Form generated from reading UI file 'order_detail.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_DETAIL_H
#define UI_ORDER_DETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_order_detail
{
public:
    QWidget *widget;
    QTableView *tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_3;
    QFormLayout *formLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *order_detail)
    {
        if (order_detail->objectName().isEmpty())
            order_detail->setObjectName("order_detail");
        order_detail->resize(800, 600);
        widget = new QWidget(order_detail);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/10002.png);}"));
        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(50, 230, 421, 301));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(500, 300, 201, 169));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName("spinBox_2");

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_2);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        spinBox_3 = new QSpinBox(layoutWidget);
        spinBox_3->setObjectName("spinBox_3");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox_3);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox->setObjectName("doubleSpinBox");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, doubleSpinBox);


        verticalLayout->addLayout(formLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 180, 92, 28));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 70, 801, 71));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(order_detail);

        QMetaObject::connectSlotsByName(order_detail);
    } // setupUi

    void retranslateUi(QWidget *order_detail)
    {
        order_detail->setWindowTitle(QCoreApplication::translate("order_detail", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("order_detail", "\345\225\206\345\223\201\345\217\267       ", nullptr));
        label_2->setText(QCoreApplication::translate("order_detail", "\346\225\260\351\207\217           ", nullptr));
        label_4->setText(QCoreApplication::translate("order_detail", "\345\215\225\344\273\267           ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("order_detail", "\346\217\220\344\272\244", nullptr));
        pushButton->setText(QCoreApplication::translate("order_detail", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("order_detail", "\350\257\246\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class order_detail: public Ui_order_detail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_DETAIL_H
