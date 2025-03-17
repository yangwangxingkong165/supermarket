/********************************************************************************
** Form generated from reading UI file 'storehouse.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREHOUSE_H
#define UI_STOREHOUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_storehouse
{
public:
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QWidget *storehouse)
    {
        if (storehouse->objectName().isEmpty())
            storehouse->setObjectName("storehouse");
        storehouse->resize(800, 600);
        widget = new QWidget(storehouse);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/10002.png);}"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(470, 320, 231, 141));
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

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEdit_2);


        verticalLayout->addLayout(formLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 230, 421, 301));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 60, 801, 81));
        QFont font;
        font.setPointSize(50);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 170, 92, 28));

        retranslateUi(storehouse);

        QMetaObject::connectSlotsByName(storehouse);
    } // setupUi

    void retranslateUi(QWidget *storehouse)
    {
        storehouse->setWindowTitle(QCoreApplication::translate("storehouse", "Form", nullptr));
        label->setText(QCoreApplication::translate("storehouse", "\344\273\223\345\272\223id        ", nullptr));
        label_3->setText(QCoreApplication::translate("storehouse", "\344\273\223\345\272\223\345\220\215        ", nullptr));
        label_2->setText(QCoreApplication::translate("storehouse", "\345\234\260\345\235\200            ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("storehouse", "\346\217\220\344\272\244", nullptr));
        label_4->setText(QCoreApplication::translate("storehouse", "\344\273\223\345\272\223", nullptr));
        pushButton->setText(QCoreApplication::translate("storehouse", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class storehouse: public Ui_storehouse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREHOUSE_H
