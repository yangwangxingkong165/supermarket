/********************************************************************************
** Form generated from reading UI file 'inventory.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORY_H
#define UI_INVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inventory
{
public:
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;

    void setupUi(QWidget *inventory)
    {
        if (inventory->objectName().isEmpty())
            inventory->setObjectName("inventory");
        inventory->resize(800, 600);
        pushButton = new QPushButton(inventory);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 60, 92, 28));
        tableView = new QTableView(inventory);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 160, 421, 301));
        pushButton_2 = new QPushButton(inventory);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(700, 270, 92, 28));
        label = new QLabel(inventory);
        label->setObjectName("label");
        label->setGeometry(QRect(460, 260, 69, 19));
        label_2 = new QLabel(inventory);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 340, 69, 19));
        spinBox = new QSpinBox(inventory);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(540, 250, 131, 28));
        pushButton_3 = new QPushButton(inventory);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(700, 320, 92, 28));
        label_3 = new QLabel(inventory);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(460, 300, 69, 19));
        spinBox_2 = new QSpinBox(inventory);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(540, 300, 131, 28));
        spinBox_3 = new QSpinBox(inventory);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(540, 340, 131, 28));

        retranslateUi(inventory);

        QMetaObject::connectSlotsByName(inventory);
    } // setupUi

    void retranslateUi(QWidget *inventory)
    {
        inventory->setWindowTitle(QCoreApplication::translate("inventory", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("inventory", "\350\277\224\345\233\236", nullptr));
        pushButton_2->setText(QCoreApplication::translate("inventory", "\346\217\220\344\272\244", nullptr));
        label->setText(QCoreApplication::translate("inventory", "\344\273\223\345\272\223id", nullptr));
        label_2->setText(QCoreApplication::translate("inventory", "\345\272\223\345\255\230", nullptr));
        pushButton_3->setText(QCoreApplication::translate("inventory", "\346\237\245\350\257\242", nullptr));
        label_3->setText(QCoreApplication::translate("inventory", "\345\225\206\345\223\201id", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inventory: public Ui_inventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORY_H
