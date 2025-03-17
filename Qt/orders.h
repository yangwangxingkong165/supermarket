#ifndef ORDERS_H
#define ORDERS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtWidgets/QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql>
#include <order_detail.h>

namespace Ui {
class orders;
}

class orders : public QWidget
{
    Q_OBJECT

public:
    explicit orders(QWidget *parent = nullptr);
    ~orders();
    void save_id(const QString &data);

signals:
    void sendData(qint32);

private slots:
    void on_back();
    void on_select_all();
    void on_submit();

private:
    Ui::orders *ui;
    order_detail *secondwindow;
    QString User_ID;
};

#endif // ORDERS_H
