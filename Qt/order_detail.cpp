#include "order_detail.h"
#include "ui_order_detail.h"
#include "widget.h"

order_detail::order_detail(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::order_detail)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&order_detail::on_back);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&order_detail::on_submit);
}

order_detail::~order_detail()
{
    delete ui;
}

void order_detail::receiveData(qint32 data)
{
    receviedata=data;
    on_select_all();
}

void order_detail::save_id(const QString &data)
{
    User_ID=data;
}

void order_detail::on_back()
{
    Widget *page=new Widget;
    page->setReceivedData(User_ID);
    this->close();
    page->show();
}

void order_detail::on_select_all()
{
    QSqlQuery select;
    QStandardItemModel *model = new QStandardItemModel;
    select.prepare("SELECT * FROM order_detail WHERE order_id=?;");
    select.bindValue(0,receviedata);
    select.exec();
    while(select.next())
    {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(select.value(0).toString()));
        items.append(new QStandardItem(select.value(1).toString()));
        items.append(new QStandardItem(select.value(2).toString()));
        items.append(new QStandardItem(select.value(3).toString()));
        items.append(new QStandardItem(select.value(4).toString()));
        model->appendRow(items);
    }
    model->setHeaderData(0,Qt::Horizontal,tr("订单号"));
    model->setHeaderData(1,Qt::Horizontal,tr("商品号"));
    model->setHeaderData(2,Qt::Horizontal,tr("数量"));
    model->setHeaderData(3,Qt::Horizontal,tr("单价"));
    model->setHeaderData(4,Qt::Horizontal,tr("总金额"));
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
}

void order_detail::on_submit()
{
    qint32 orders_id,goods_id,amount;
    double price,sum_price;
    orders_id=receviedata;
    goods_id=ui->spinBox_2->value();
    amount=ui->spinBox_3->value();
    price=ui->doubleSpinBox->value();
    sum_price=amount*price;

    QSqlQuery insert;
    insert.prepare("INSERT INTO order_detail VALUES (?,?,?,?,?)");
    insert.bindValue(0,orders_id);
    insert.bindValue(1,goods_id);
    insert.bindValue(2,amount);
    insert.bindValue(3,price);
    insert.bindValue(4,sum_price);

    QSqlQuery update_orders;
    update_orders.prepare("UPDATE orders SET money_amount=money_amount+? WHERE order_id=?;");
    update_orders.bindValue(0,sum_price);
    update_orders.bindValue(1,orders_id);


    QSqlQuery select_amount;
    select_amount.prepare("SELECT amount FROM goods WHERE goods_id=?;");
    select_amount.bindValue(0,goods_id);
    select_amount.exec();

    if(select_amount.next())
    {
        qint32 now_amount=select_amount.value(0).toInt();
        qint32 need_amount=amount;
        if(now_amount<amount)
        {
            QMessageBox::critical(this,"错误","当前库存不足以完成该订单");
            return;
        }
        update_orders.exec();
        QSqlQuery select;
        select.prepare("SELECT storehouse_id,amount FROM inventory WHERE goods_id=? ORDER BY amount DESC;");
        select.bindValue(0,goods_id);
        select.exec();
        while(select.next())
        {
            qint32 storehouse_id,store_amount;
            storehouse_id=select.value(0).toInt();
            store_amount=select.value(1).toInt();
            if(store_amount>need_amount)
            {
                QSqlQuery update;
                update.prepare("UPDATE inventory SET amount=? WHERE storehouse_id=? AND goods_id=?;");
                update.bindValue(0,store_amount-need_amount);
                update.bindValue(1,storehouse_id);
                update.bindValue(2,goods_id);
                update.exec();
                QSqlQuery update_goods;
                update_goods.prepare("UPDATE goods SET amount=? WHERE goods_id=?;");
                update_goods.bindValue(0,now_amount-amount);
                update_goods.bindValue(1,goods_id);
                update_goods.exec();
                break;
            }
            else if(store_amount==need_amount)
            {
                QSqlQuery delet;
                delet.prepare("DELETE FROM inventory WHERE storehouse_id=? AND goods_id=?;");
                delet.bindValue(0,storehouse_id);
                delet.bindValue(1,goods_id);
                delet.exec();
                QSqlQuery update_goods;
                update_goods.prepare("UPDATE goods SET amount=? WHERE goods_id=?;");
                update_goods.bindValue(0,now_amount-amount);
                update_goods.bindValue(1,goods_id);
                update_goods.exec();
                break;
            }
            else
            {
                QSqlQuery delet;
                delet.prepare("DELETE FROM inventory WHERE storehouse_id=? AND goods_id=?;");
                delet.bindValue(0,storehouse_id);
                delet.bindValue(1,goods_id);
                delet.exec();
                need_amount-=store_amount;
            }
        }
    }
    else
    {
        QMessageBox::critical(this,"错误","当前库存中没有该商品");
        return;
    }

    if(insert.exec())
        QMessageBox::information(this, "infor", "success");
    else
        QMessageBox::information(this, "infor", "open failed");
    on_select_all();
}
