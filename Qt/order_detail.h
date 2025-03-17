#ifndef ORDER_DETAIL_H
#define ORDER_DETAIL_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtWidgets/QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql>

namespace Ui {
class order_detail;
}

class order_detail : public QWidget
{
    Q_OBJECT

public:
    explicit order_detail(QWidget *parent = nullptr);
    ~order_detail();
    void save_id(const QString &data);

public slots:
    void receiveData(qint32);

private slots:
    void on_back();
    void on_select_all();
    void on_submit();

private:
    Ui::order_detail *ui;
    qint32 receviedata;
    QString User_ID;
};

#endif // ORDER_DETAIL_H
