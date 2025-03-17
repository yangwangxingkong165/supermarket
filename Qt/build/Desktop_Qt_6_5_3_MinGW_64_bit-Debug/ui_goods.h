/********************************************************************************
** Form generated from reading UI file 'goods.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODS_H
#define UI_GOODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_Goods
{
public:
    QWidget *widget;
    QTableView *tableView;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QWidget *widget1;
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
    QFormLayout *formLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;

    void setupUi(QWidget *Goods)
    {
        if (Goods->objectName().isEmpty())
            Goods->setObjectName("Goods");
        Goods->resize(800, 600);
        Goods->setMinimumSize(QSize(400, 0));
        widget = new QWidget(Goods);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/2.png);}"));
        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 210, 421, 301));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 150, 92, 28));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(8, 70, 791, 71));
        QFont font;
        font.setPointSize(40);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(510, 270, 231, 170));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(widget1);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinBox = new QSpinBox(widget1);
        spinBox->setObjectName("spinBox");

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName("lineEdit");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEdit_2);


        verticalLayout->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(widget1);
        doubleSpinBox->setObjectName("doubleSpinBox");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, doubleSpinBox);


        verticalLayout->addLayout(formLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(widget1);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(Goods);

        QMetaObject::connectSlotsByName(Goods);
    } // setupUi

    void retranslateUi(QWidget *Goods)
    {
        Goods->setWindowTitle(QCoreApplication::translate("Goods", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Goods", "\350\277\224\345\233\236", nullptr));
        label_5->setText(QCoreApplication::translate("Goods", "\345\225\206\345\223\201", nullptr));
        label->setText(QCoreApplication::translate("Goods", "\345\225\206\345\223\201id        ", nullptr));
        label_3->setText(QCoreApplication::translate("Goods", "\345\225\206\345\223\201\345\220\215\347\247\260    ", nullptr));
        label_2->setText(QCoreApplication::translate("Goods", "\347\247\215\347\261\273           ", nullptr));
        label_4->setText(QCoreApplication::translate("Goods", "\351\224\200\345\224\256\345\215\225\344\273\267    ", nullptr));
        pushButton->setText(QCoreApplication::translate("Goods", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Goods: public Ui_Goods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODS_H
