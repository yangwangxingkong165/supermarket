#ifndef GOODS_H
#define GOODS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtWidgets/QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql>

namespace Ui {
class Goods;
}

class Goods : public QWidget
{
    Q_OBJECT

public:
    explicit Goods(QWidget *parent = nullptr);
    ~Goods();
    void save_id(const QString &data);


private slots:
    void on_select_all();
    void on_submit();
    void on_back();
private:
    Ui::Goods *ui;
    QString User_ID;
};

#endif // GOODS_H
