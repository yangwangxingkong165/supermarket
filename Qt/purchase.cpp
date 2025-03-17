#include "purchase.h"
#include "ui_purchase.h"
#include "widget.h"

purchase::purchase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::purchase)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&purchase::on_back);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&purchase::on_select_all);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&purchase::on_submit);
    on_select_all();
}

purchase::~purchase()
{
    delete ui;
}

void purchase::save_id(const QString &data)
{
    User_ID=data;
}

void purchase::on_back()
{
    Widget *page=new Widget;
    page->setReceivedData(User_ID);
    this->close();
    page->show();
}

void purchase::on_select_all()
{

    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM purchase;"));
    model->setHeaderData(0,Qt::Horizontal,tr("进货单号"));
    model->setHeaderData(1,Qt::Horizontal,tr("商品id"));
    model->setHeaderData(2,Qt::Horizontal,tr("采购数量"));
    model->setHeaderData(3,Qt::Horizontal,tr("供货商id"));
    model->setHeaderData(4,Qt::Horizontal,tr("采购日期"));
    model->setHeaderData(5,Qt::Horizontal,tr("仓库id"));
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();

}

void purchase::on_submit()
{
    qint32 purchase_id,goods_id,amount,provider_id,storehouse_id;
    QDate pur_date;
    purchase_id=ui->spinBox->value();
    goods_id=ui->spinBox_3->value();
    amount=ui->spinBox_4->value();
    provider_id=ui->spinBox_5->value();
    pur_date=ui->dateEdit->date();
    storehouse_id=ui->spinBox_2->value();

    QSqlQuery insert;
    insert.prepare("INSERT INTO purchase VALUES (?,?,?,?,?,?)");
    insert.bindValue(0,purchase_id);
    insert.bindValue(1,goods_id);
    insert.bindValue(2,amount);
    insert.bindValue(3,provider_id);
    insert.bindValue(4,pur_date);
    insert.bindValue(5,storehouse_id);

    QSqlQuery check_goods;
    check_goods.prepare("SELECT * FROM goods WHERE goods_id=?;");
    check_goods.bindValue(0,goods_id);
    check_goods.exec();
    if(!check_goods.next())
    {
        QString name,goods_class;
        double price;
        bool name_ok,class_ok,price_ok;
        name= QInputDialog::getText(this,tr("该商品首次加入"),tr("商品名"),QLineEdit::Normal,tr(""),&name_ok);
        goods_class= QInputDialog::getText(this,tr("该商品首次加入"),tr("类型"),QLineEdit::Normal,tr(""),&class_ok);
        price=QInputDialog::getDouble(this,tr("该商品首次加入"),tr("销售价格"),QLineEdit::Normal,0,100,2,&price_ok);
        if(name_ok&&class_ok&&price_ok)
        {
            QSqlQuery insert_goods;
            insert_goods.prepare("INSERT INTO goods VALUE (?,?,?,?,0)");
            insert_goods.bindValue(0,goods_id);
            insert_goods.bindValue(1,name);
            insert_goods.bindValue(2,goods_class);
            insert_goods.bindValue(3,price);
            insert_goods.exec();
        }
    }

    QSqlQuery check_storehouse;
    check_storehouse.prepare("SELECT * FROM storehouse WHERE storehouse_id=?;");
    check_storehouse.bindValue(0,storehouse_id);
    check_storehouse.exec();
    if(!check_storehouse.next())
    {
        QString name,address;
        bool name_ok,address_ok;
        name=QInputDialog::getText(this,tr("该仓库首次被加入"),tr("仓库名"),QLineEdit::Normal,tr(""),&name_ok);
        address=QInputDialog::getText(this,tr("该仓库首次被加入"),tr("仓库地址"),QLineEdit::Normal,tr(""),&address_ok);
        if(name_ok&&address_ok)
        {
            QSqlQuery insert;
            insert.prepare("INSERT INTO storehouse VALUE(?,?,?);");
            insert.bindValue(0,storehouse_id);
            insert.bindValue(1,name);
            insert.bindValue(2,address);
            insert.exec();
        }
    }

    QSqlQuery check_inventory;
    check_inventory.prepare("SELECT * FROM inventory WHERE goods_id=? AND storehouse_id=?;");
    check_inventory.bindValue(0,goods_id);
    check_inventory.bindValue(1,storehouse_id);
    check_inventory.exec();
    if(!check_inventory.next())
    {
        QSqlQuery insert_inventory;
        insert_inventory.prepare("INSERT INTO inventory VALUE (?,?,?)");
        insert_inventory.bindValue(0,storehouse_id);
        insert_inventory.bindValue(1,goods_id);
        insert_inventory.bindValue(2,amount);
        insert_inventory.exec();
    }
    else
    {
        QSqlQuery update_inventory;
        update_inventory.prepare("UPDATE inventory SET amount=amount+? WHERE storehouse_id=?;");
        update_inventory.bindValue(0,amount);
        update_inventory.bindValue(1,storehouse_id);
        update_inventory.exec();
    }
    if(insert.exec())
        QMessageBox::information(nullptr, "infor", "success");
    else
        QMessageBox::information(nullptr, "infor", "open failed");
    on_select_all();
}
