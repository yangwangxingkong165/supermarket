#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtWidgets/QMessageBox>
#include <QSqlError>
#include <QInputDialog>
#include <QStandardItemModel>
#include <QDialog>
#include <order_detail.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void setReceivedData(const QString &data);
signals:
    void sendData(qint32);

public slots:
    void receiveData(QString);

private slots:
    void on_page_3();
    void on_page_2();
    void on_select_goods_detail();
    void on_creat_orders();
    void on_update_orders();
    void on_select_orders_detail();
    void on_select_storehouse();
    void on_select_goods();
    void on_update_price();
    void on_update_storehouse();
    void on_select_purchase();
    void on_select_orders();
    void on_select_price();
    void on_insert_goods();
    void on_back();
    void on_create_user();
    void on_delet();
    void on_select_user();
    void on_update_user();
private:
    Ui::Widget *ui;
    order_detail *orders_dwindow;
    QString receviedata;
};


#endif // WIDGET_H
