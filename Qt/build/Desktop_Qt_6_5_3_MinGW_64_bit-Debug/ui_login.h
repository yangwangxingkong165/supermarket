/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *widget;
    QLabel *label_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QFormLayout *formLayout_4;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(800, 600);
        widget = new QWidget(login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/6.png);}"));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 20, 800, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(40);
        font.setBold(false);
        font.setItalic(false);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 40pt \"\345\256\213\344\275\223\";\n"
"color: rgb(255, 255, 255);\n"
"}"));
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(290, 220, 235, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/9.png")));
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(255, 255, 255);\n"
"	font: 10pt \"\345\256\213\344\275\223\";\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_2);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit);


        verticalLayout->addLayout(formLayout_2);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/10.png")));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{color: rgb(255, 255, 255);\n"
"	font: 10pt \"\345\256\213\344\275\223\";\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_3);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, formLayout_3);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setEchoMode(QLineEdit::Password);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit_2);


        verticalLayout->addLayout(formLayout_4);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 15pt \"\345\256\213\344\275\223\";\n"
"}"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("login", "\350\266\205\345\270\202\345\272\223\345\255\230\345\217\212\346\224\266\351\223\266\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_5->setText(QString());
        label_3->setText(QCoreApplication::translate("login", " \345\257\206\347\240\201 ", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
