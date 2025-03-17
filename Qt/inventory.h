#ifndef INVENTORY_H
#define INVENTORY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtWidgets/QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql>


namespace Ui {
class inventory;
}

class inventory : public QWidget
{
    Q_OBJECT

public:
    explicit inventory(QWidget *parent = nullptr);
    ~inventory();

private slots:
    void on_back();
    void on_select_all();
    void on_submit();

private:
    Ui::inventory *ui;
};

#endif // INVENTORY_H
