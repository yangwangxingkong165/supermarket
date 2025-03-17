#ifndef PURCHASE_H
#define PURCHASE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtWidgets/QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql>
#include <QInputDialog>

namespace Ui {
class purchase;
}

class purchase : public QWidget
{
    Q_OBJECT

public:
    explicit purchase(QWidget *parent = nullptr);
    ~purchase();
    void save_id(const QString &data);

private slots:
    void on_back();
    void on_select_all();
    void on_submit();
private:
    Ui::purchase *ui;
    QString User_ID;
};

#endif // PURCHASE_H
