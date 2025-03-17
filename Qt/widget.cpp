#include "widget.h"
#include "ui_widget.h"

#include "goods.h"
#include "purchase.h"
#include "storehouse.h"
#include "orders.h"
#include "order_detail.h"
#include "login.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , orders_dwindow(new order_detail)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&Widget::on_insert_goods);
    QObject::connect(ui->pushButton_6,&QPushButton::clicked,this,&Widget::on_back);
    QObject::connect(ui->pushButton_8,&QPushButton::clicked,this,&Widget::on_select_user);
    QObject::connect(ui->pushButton_9,&QPushButton::clicked,this,&Widget::on_update_user);
    QObject::connect(ui->pushButton_5,&QPushButton::clicked,this,&Widget::on_page_2);
    QObject::connect(ui->pushButton_7,&QPushButton::clicked,this,&Widget::on_delet);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&Widget::on_page_3);
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,this,&Widget::on_create_user);
    QObject::connect(ui->pushButton_4,&QPushButton::clicked,this,&Widget::on_select_price);
    QObject::connect(ui->pushButton_29,&QPushButton::clicked,this,&Widget::on_select_goods_detail);
    QObject::connect(ui->pushButton_32,&QPushButton::clicked,this,&Widget::on_creat_orders);
    QObject::connect(ui->pushButton_33,&QPushButton::clicked,this,&Widget::on_update_orders);
    QObject::connect(ui->pushButton_31,&QPushButton::clicked,this,&Widget::on_select_orders_detail);
    QObject::connect(ui->pushButton_28,&QPushButton::clicked,this,&Widget::on_select_storehouse);
    QObject::connect(ui->pushButton_26,&QPushButton::clicked,this,&Widget::on_select_goods);
    QObject::connect(ui->pushButton_34,&QPushButton::clicked,this,&Widget::on_update_price);
    QObject::connect(ui->pushButton_35,&QPushButton::clicked,this,&Widget::on_update_storehouse);
    QObject::connect(ui->pushButton_27,&QPushButton::clicked,this,&Widget::on_select_purchase);
    QObject::connect(ui->pushButton_30,&QPushButton::clicked,this,&Widget::on_select_orders);
    connect(this,&Widget::sendData,orders_dwindow,&order_detail::receiveData);
    setStyleSheet("border-image:url(:/10002.jpeg)");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::setReceivedData(const QString &data)
{
    receviedata = data;
}

void Widget::receiveData(QString data)
{
    receviedata=data;
}

void Widget::on_insert_goods()
{
    Goods *page=new Goods;
    page->save_id(receviedata);
    this->close();
    page->show();

}

void Widget::on_back()
{
    login *page=new login;
    this->close();
    page->show();
}
void Widget::on_page_2()
{
    purchase *page=new purchase;
    page->save_id(receviedata);
    this->close();
    page->show();
}

void Widget::on_page_3()
{
    storehouse *page=new storehouse;
    page->save_id(receviedata);
    this->close();
    page->show();
}

void Widget::on_select_user()
{
    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM user;"));
    model->setHeaderData(0,Qt::Horizontal,tr("用户名"));
    model->setHeaderData(1,Qt::Horizontal,tr("密码"));
    ui->label_3->setVisible(false);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
}

void Widget::on_update_user()
{
    QString password;
    bool password_ok,second=false;
    password=QInputDialog::getText(this,"请输入密码","密码",QLineEdit::Normal,"",&password_ok);
    if(password_ok)
    {
        QSqlQuery select;
        select.prepare("SELECT user_passsword FROM user WHERE id=?;");
        select.bindValue(0,receviedata);
        select.exec();
        while(select.next())
        {
            if(password!=select.value(0).toString())
            {
                QMessageBox::information(nullptr, "infor", "密码错误，请重试！");
                return;
            }
            else
                second=true;
        }
    }
    if(second==false)
        return;
    QString password_1,password_2;
    bool ok_1,ok_2;
    password_1=QInputDialog::getText(this,"请输入新密码","密码",QLineEdit::Normal,"",&ok_1);
    password_2=QInputDialog::getText(this,"请再次输入新密码","密码",QLineEdit::Normal,"",&ok_2);
    if(ok_1&&ok_2)
    {
        if(password_1==password_2)
        {
            QSqlQuery update;
            update.prepare("UPDATE user SET user_passsword=? WHERE id=?;");
            update.bindValue(0,password_1);
            update.bindValue(1,receviedata);
            if(update.exec())
                QMessageBox::information(nullptr, "infor", "success");
            else
                QMessageBox::information(nullptr, "infor", "failed");

        }
    }


}

void Widget::on_select_price()
{
    QStringList items;
    bool choics_ok;
    items<<tr("每天销售额")<<("总销售额");
    QString choice=QInputDialog::getItem(this,"选择查询类型","选择查询类型",items,0,false,&choics_ok);
    if(choics_ok)
    {
        if(choice=="每天销售额")
        {
            QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
            model->setQuery(QString("SELECT * FROM sum_money;"));
            model->setHeaderData(0,Qt::Horizontal,tr("订单日期"));
            model->setHeaderData(1,Qt::Horizontal,tr("总金额"));
            ui->label_3->setVisible(false);
            ui->tableView->setModel(model);
            ui->tableView->verticalHeader()->hide();
        }
        else if(choice=="总销售额")
        {
            QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
            model->setQuery(QString("SELECT sum(money_amount) FROM sum_money;"));
            model->setHeaderData(0,Qt::Horizontal,tr("总金额"));
            ui->label_3->setVisible(false);
            ui->tableView->setModel(model);
            ui->tableView->verticalHeader()->hide();
        }
    }

}

void Widget::on_select_goods_detail()
{
    QStringList items;
    bool choics_ok;
    items<<tr("所有库存")<<tr("商品")<<tr("仓库")<<tr("类型");
    QString choice=QInputDialog::getItem(this,"选择查询类型","选择查询类型",items,0,false,&choics_ok);
    if(choics_ok)
    {
        if(choice=="商品")
        {
            qint32 goods_id;
            bool ok;
            goods_id=QInputDialog::getInt(this,"查询商品库存","商品id",0,0,10000,1,&ok);
            if(ok)
            {
                QSqlQuery select;
                QStandardItemModel *model = new QStandardItemModel;
                select.prepare("SELECT * FROM goods_detail WHERE goods_id=?;");
                select.bindValue(0,goods_id);
                select.exec();
                while(select.next())
                {
                    QList<QStandardItem *> items;
                    items.append(new QStandardItem(select.value(0).toString()));
                    items.append(new QStandardItem(select.value(1).toString()));
                    items.append(new QStandardItem(select.value(2).toString()));
                    items.append(new QStandardItem(select.value(3).toString()));
                    items.append(new QStandardItem(select.value(4).toString()));
                    items.append(new QStandardItem(select.value(5).toString()));
                    items.append(new QStandardItem(select.value(6).toString()));
                    model->appendRow(items);
                }
                model->setHeaderData(0,Qt::Horizontal,tr("商品id"));
                model->setHeaderData(1,Qt::Horizontal,tr("商品名"));
                model->setHeaderData(2,Qt::Horizontal,tr("类型"));
                model->setHeaderData(3,Qt::Horizontal,tr("仓库id"));
                model->setHeaderData(4,Qt::Horizontal,tr("仓库名"));
                model->setHeaderData(5,Qt::Horizontal,tr("仓库地址"));
                model->setHeaderData(6,Qt::Horizontal,tr("库存"));
                ui->label_3->setVisible(false);
                ui->tableView->setModel(model);
                ui->tableView->verticalHeader()->hide();
            }
        }
        else if(choice=="仓库")
        {
            qint32 storehouse_id;
            bool ok;
            storehouse_id=QInputDialog::getInt(this,"查询商品库存","仓库id",0,0,10000,1,&ok);
            if(ok)
            {
                QSqlQuery select;
                QStandardItemModel *model = new QStandardItemModel;
                select.prepare("SELECT * FROM goods_detail WHERE storehouse_id=?;");
                select.bindValue(0,storehouse_id);
                select.exec();
                while(select.next())
                {
                    QList<QStandardItem *> items;
                    items.append(new QStandardItem(select.value(0).toString()));
                    items.append(new QStandardItem(select.value(1).toString()));
                    items.append(new QStandardItem(select.value(2).toString()));
                    items.append(new QStandardItem(select.value(3).toString()));
                    items.append(new QStandardItem(select.value(4).toString()));
                    items.append(new QStandardItem(select.value(5).toString()));
                    items.append(new QStandardItem(select.value(6).toString()));
                    qDebug()<<items;
                    model->appendRow(items);
                }
                model->setHeaderData(0,Qt::Horizontal,tr("商品id"));
                model->setHeaderData(1,Qt::Horizontal,tr("商品名"));
                model->setHeaderData(2,Qt::Horizontal,tr("类型"));
                model->setHeaderData(3,Qt::Horizontal,tr("仓库id"));
                model->setHeaderData(4,Qt::Horizontal,tr("仓库名"));
                model->setHeaderData(5,Qt::Horizontal,tr("仓库地址"));
                model->setHeaderData(6,Qt::Horizontal,tr("库存"));
                ui->label_3->setVisible(false);
                ui->tableView->setModel(model);
                ui->tableView->verticalHeader()->hide();
            }
        }
        else if(choice=="类型")
        {
            QString goods_class;
            bool ok;
            goods_class=QInputDialog::getText(this,"查询商品库存","商品类型",QLineEdit::Normal,"食品",&ok);
            if(ok)
            {
                QSqlQuery select;
                QStandardItemModel *model = new QStandardItemModel;
                select.prepare("SELECT * FROM goods_detail WHERE class=?;");
                select.bindValue(0,goods_class);
                select.exec();
                while(select.next())
                {
                    QList<QStandardItem *> items;
                    items.append(new QStandardItem(select.value(0).toString()));
                    items.append(new QStandardItem(select.value(1).toString()));
                    items.append(new QStandardItem(select.value(2).toString()));
                    items.append(new QStandardItem(select.value(3).toString()));
                    items.append(new QStandardItem(select.value(4).toString()));
                    items.append(new QStandardItem(select.value(5).toString()));
                    items.append(new QStandardItem(select.value(6).toString()));
                    qDebug()<<items;
                    model->appendRow(items);
                }
                model->setHeaderData(0,Qt::Horizontal,tr("商品id"));
                model->setHeaderData(1,Qt::Horizontal,tr("商品名"));
                model->setHeaderData(2,Qt::Horizontal,tr("类型"));
                model->setHeaderData(3,Qt::Horizontal,tr("仓库id"));
                model->setHeaderData(4,Qt::Horizontal,tr("仓库名"));
                model->setHeaderData(5,Qt::Horizontal,tr("仓库地址"));
                model->setHeaderData(6,Qt::Horizontal,tr("库存"));
                ui->label_3->setVisible(false);
                ui->tableView->setModel(model);
                ui->tableView->verticalHeader()->hide();
            }
        }
        else if(choice=="所有库存")
        {
            QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
            model->setQuery(QString("SELECT * FROM goods_detail;"));
            model->setHeaderData(0,Qt::Horizontal,tr("商品id"));
            model->setHeaderData(1,Qt::Horizontal,tr("商品名"));
            model->setHeaderData(2,Qt::Horizontal,tr("类型"));
            model->setHeaderData(3,Qt::Horizontal,tr("仓库id"));
            model->setHeaderData(4,Qt::Horizontal,tr("仓库名"));
            model->setHeaderData(5,Qt::Horizontal,tr("仓库地址"));
            model->setHeaderData(6,Qt::Horizontal,tr("库存"));
            ui->label_3->setVisible(false);
            ui->tableView->setModel(model);
            ui->tableView->verticalHeader()->hide();
        }
    }
}
void Widget::on_creat_orders()
{
    orders *page=new orders;
    page->save_id(receviedata);
    this->close();
    page->show();
}

void Widget::on_update_orders()
{
    qint32 orders_id;
    bool ok;
    orders_id=QInputDialog::getInt(this,"输入要添加的订单号","订单号",0,0,1000,1,&ok);
    if(ok)
    {
        QSqlQuery check;
        check.prepare("SELECT * FROM orders WHERE order_id=?");
        check.bindValue(0,orders_id);
        check.exec();
        if(check.next())
        {
            emit sendData(orders_id);
            orders_dwindow->save_id(receviedata);
            this->close();
            orders_dwindow->show();
        }
        else
        {
            QMessageBox messagebox;
            messagebox.setText("不存在该订单，是否新建订单？");
            messagebox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            messagebox.setDefaultButton(QMessageBox::Ok);
            int ret=messagebox.exec();
            if (ret == QMessageBox::Ok)
            {
                orders *page=new orders;
                page->save_id(receviedata);
                this->close();
                page->show();
            }
            else
                return;
        }
    }
}
void Widget::on_select_orders_detail()
{
    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM order_detail;"));
    model->setHeaderData(0,Qt::Horizontal,tr("订单id"));
    model->setHeaderData(1,Qt::Horizontal,tr("商品id"));
    model->setHeaderData(2,Qt::Horizontal,tr("数量"));
    model->setHeaderData(3,Qt::Horizontal,tr("单价"));
    model->setHeaderData(4,Qt::Horizontal,tr("总金额"));
    ui->label_3->setVisible(false);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
}

void Widget::on_select_storehouse()
{
    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM storehouse;"));
    model->setHeaderData(0,Qt::Horizontal,tr("仓库id"));
    model->setHeaderData(1,Qt::Horizontal,tr("仓库名"));
    model->setHeaderData(2,Qt::Horizontal,tr("地址"));
    ui->label_3->setVisible(false);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
}

void Widget::on_select_goods()
{
    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM goods;"));
    model->setHeaderData(0,Qt::Horizontal,tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,tr("名字"));
    model->setHeaderData(2,Qt::Horizontal,tr("种类"));
    model->setHeaderData(3,Qt::Horizontal,tr("售价"));
    model->setHeaderData(4,Qt::Horizontal,tr("数量"));
    ui->label_3->setVisible(false);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
}

void Widget::on_update_price()
{
    qint32 goods_id;
    bool ok_goods;
    goods_id=QInputDialog::getInt(this,"输入要修改的商品id","商品id",0,0,1000,1,&ok_goods);
    if(ok_goods)
    {
        double price_now,price;
        bool ok;
        QSqlQuery select;
        qDebug()<<goods_id;
        select.prepare("SELECT sale_price FROM goods WHERE goods_id=?;");
        select.bindValue(0,goods_id);
        select.exec();
        if(select.next())
        {
            price_now=select.value(0).toDouble();
        }
        else
        {
            QMessageBox::information(nullptr, "infor", "不存在该商品");
            return;
        }
        price=QInputDialog::getDouble(this,"输入修改后的商品销售单价","销售单价",price_now,0,1000,2,&ok);
        if(ok)
        {
            QSqlQuery update;
            update.prepare("UPDATE goods SET sale_price=? WHERE goods_id=?;");
            update.bindValue(0,price);
            update.bindValue(1,goods_id);
            if(update.exec())
                QMessageBox::information(nullptr, "infor", "success");
            else
                QMessageBox::information(nullptr, "infor", "failed");
        }
    }
}

void Widget::on_update_storehouse()
{
    qint32 storehouse_id;
    bool id_ok;
    storehouse_id=QInputDialog::getInt(this,"请输入要修改的仓库id","仓库id",0,0,1000,1,&id_ok);
    if(id_ok)
    {
        QSqlQuery select;
        QString name_now,address_now;
        select.prepare("SELECT storehouse_name,address FROM storehouse WHERE storehouse_id=?;");
        select.bindValue(0,storehouse_id);
        select.exec();
        if(select.next())
        {
            name_now=select.value(0).toString();
            address_now=select.value(1).toString();
        }
        else
        {
            QMessageBox::information(nullptr, "infor", "不存在该仓库");
            return;
        }
        QString name,address;
        bool name_ok,address_ok;
        name=QInputDialog::getText(this,"修改仓库信息","仓库名",QLineEdit::Normal,name_now,&name_ok);
        address=QInputDialog::getText(this,"修改仓库信息","仓库地址",QLineEdit::Normal,address_now,&address_ok);
        if(name_ok&&address_ok)
        {
            QSqlQuery update;
            update.prepare("UPDATE storehouse SET storehouse_name=?,address=? WHERE storehouse_id=?;");
            update.bindValue(0,name);
            update.bindValue(1,address);
            update.bindValue(2,storehouse_id);
            if(update.exec())
                QMessageBox::information(nullptr, "infor", "success");
            else
                QMessageBox::information(nullptr, "infor", "failed");
        }
    }
}

void Widget::on_select_purchase()
{
    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM purchase;"));
    model->setHeaderData(0,Qt::Horizontal,tr("进货单号"));
    model->setHeaderData(1,Qt::Horizontal,tr("商品id"));
    model->setHeaderData(2,Qt::Horizontal,tr("采购数量"));
    model->setHeaderData(3,Qt::Horizontal,tr("供货商id"));
    model->setHeaderData(4,Qt::Horizontal,tr("采购日期"));
    model->setHeaderData(5,Qt::Horizontal,tr("仓库id"));
    ui->label_3->setVisible(false);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
}

void Widget::on_select_orders()
{
    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM orders;"));
    model->setHeaderData(0,Qt::Horizontal,tr("订单id"));
    model->setHeaderData(1,Qt::Horizontal,tr("订单日期"));
    model->setHeaderData(2,Qt::Horizontal,tr("客户id"));
    model->setHeaderData(3,Qt::Horizontal,tr("收银员id"));
    model->setHeaderData(4,Qt::Horizontal,tr("总金额"));
    ui->label_3->setVisible(false);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
}

void Widget::on_create_user()
{
    QString id,password;
    bool id_ok,password_ok;
    id=QInputDialog::getText(this,"新建管理员信息","用户名",QLineEdit::Normal,"",&id_ok);
    password=QInputDialog::getText(this,"新建管理员信息","密码",QLineEdit::Normal,"",&password_ok);
    if(id_ok&&password_ok)
    {
        QSqlQuery insert;
        insert.prepare("INSERT INTO user VALUE(?,?);");
        insert.bindValue(0,id);
        insert.bindValue(1,password);
        if(insert.exec())
            QMessageBox::information(nullptr, "infor", "success");
        else
            QMessageBox::information(nullptr, "infor", "failed");
    }
}

void Widget::on_delet()
{
    QString password;
    bool password_ok,second=false;
    password=QInputDialog::getText(this,"请再次输入密码","密码",QLineEdit::Normal,"",&password_ok);
    if(password_ok)
    {
        QSqlQuery select;
        select.prepare("SELECT user_passsword FROM user WHERE id=?;");
        select.bindValue(0,receviedata);
        select.exec();
        while(select.next())
        {
            if(password!=select.value(0).toString())
            {
                QMessageBox::information(nullptr, "infor", "密码错误，请重试！");
                return;
            }
            else
                second=true;
        }
    }
    if(second==false)
        return;
    QStringList items;
    bool choics_ok;
    items<<tr("管理员账号")<<tr("仓库")<<tr("商品")<<tr("进货信息")<<tr("订单信息");
    QString choice=QInputDialog::getItem(this,"选择删除内容","选择删除内容",items,0,false,&choics_ok);
    if(choics_ok)
    {
        if(choice=="管理员账号")
        {
            QString id;
            bool ok;
            id=QInputDialog::getText(this,"要删除的管理员用户名","用户名",QLineEdit::Normal,"",&ok);
            if(ok)
            {
                QSqlQuery delet;
                delet.prepare("DELETE FROM user WHERE id=?;");
                delet.bindValue(0,id);
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "确定","是否确定删除该用户？",QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    if(delet.exec())
                        QMessageBox::information(nullptr, "infor", "success");
                    else
                        QMessageBox::information(nullptr, "infor", "failed");
                }
            }
        }
        else if(choice=="仓库")
        {
            QString id;
            bool ok;
            id=QInputDialog::getText(this,"要删除的仓库id","仓库id",QLineEdit::Normal,"",&ok);
            if(ok)
            {
                QSqlQuery delet_storehouse,delet_inventory,select_goods;
                delet_storehouse.prepare("DELETE FROM storehouse WHERE storehouse_id=?;");
                delet_storehouse.bindValue(0,id);
                delet_inventory.prepare("DELETE FROM inventory WHERE storehouse_id=?;");
                delet_inventory.bindValue(0,id);
                select_goods.prepare("SELECT goods_id,amount FROM inventory WHERE storehouse_id=?;");
                select_goods.bindValue(0,id);
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "确定","是否确定删除该仓库（一并删除该仓库内所有库存信息）？",QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    select_goods.exec();
                    while(select_goods.next())
                    {
                        qint32 goods_id,amount;
                        goods_id=select_goods.value(0).toInt();
                        amount=select_goods.value(1).toInt();
                        QSqlQuery update;
                        update.prepare("UPDATE goods SET amount=amount-? WHERE goods_id=?;");
                        update.bindValue(0,amount);
                        update.bindValue(1,goods_id);
                        update.exec();
                    }
                    if(delet_storehouse.exec()&&delet_inventory.exec())
                        QMessageBox::information(nullptr, "infor", "success");
                    else
                        QMessageBox::information(nullptr, "infor", "failed");
                }
            }
        }
        else if(choice=="商品")
        {
            QString id;
            bool ok;
            id=QInputDialog::getText(this,"要删除的商品id","商品id",QLineEdit::Normal,"",&ok);
            if(ok)
            {
                QSqlQuery delet_goods,delet_inventory;
                delet_goods.prepare("DELETE FROM goods WHERE goods_id=?;");
                delet_goods.bindValue(0,id);
                delet_inventory.prepare("DELETE FROM inventory WHERE goods_id=?;");
                delet_inventory.bindValue(0,id);
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "确定","是否确定删除该仓库（一并删除该商品的所有库存信息）？",QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    if(delet_goods.exec()&&delet_inventory.exec())
                        QMessageBox::information(nullptr, "infor", "success");
                    else
                        QMessageBox::information(nullptr, "infor", "failed");
                }
            }
        }
        else if(choice=="进货信息")
        {
            QString id;
            bool ok;
            id=QInputDialog::getText(this,"要删除的进货单号","进货单号",QLineEdit::Normal,"",&ok);
            if(ok)
            {
                QSqlQuery delet;
                delet.prepare("DELETE FROM purchase WHERE purchase_id=?;");
                delet.bindValue(0,id);
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "确定","是否确定删除该记录？",QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    if(delet.exec())
                        QMessageBox::information(nullptr, "infor", "success");
                    else
                        QMessageBox::information(nullptr, "infor", "failed");
                }
            }
        }
        else if(choice=="订单信息")
        {
            QString id;
            bool ok;
            id=QInputDialog::getText(this,"要删除的订单号","订单号",QLineEdit::Normal,"",&ok);
            if(ok)
            {
                QSqlQuery delet_orders,delet_detail;
                delet_orders.prepare("DELETE FROM orders WHERE order_id=?;");
                delet_orders.bindValue(0,id);
                delet_detail.prepare("DELETE FROM order_detail WHERE order_id=?;");
                delet_detail.bindValue(0,id);
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "确定","是否确定删除该订单及其详单？",QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    if(delet_orders.exec()&&delet_detail.exec())
                        QMessageBox::information(nullptr, "infor", "success");
                    else
                        QMessageBox::information(nullptr, "infor", "failed");
                }
            }
        }
    }
}
