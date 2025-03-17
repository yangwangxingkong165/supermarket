#ifndef STOREHOUSE_H
#define STOREHOUSE_H

#include <QWidget>
#include <QWidget>
#include <QSqlDatabase>
#include <QtWidgets/QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql>

namespace Ui {
class storehouse;
}

class storehouse : public QWidget
{
    Q_OBJECT

public:
    explicit storehouse(QWidget *parent = nullptr);
    ~storehouse();
    void save_id(const QString &data);

private slots:
    void on_back();
    void on_select_all();
    void on_submit();

private:
    Ui::storehouse *ui;
    QString User_ID;
};

#endif // STOREHOUSE_H
