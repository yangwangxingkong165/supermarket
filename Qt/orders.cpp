#include "orders.h"
#include "ui_orders.h"
#include "widget.h"
#include "order_detail.h"

orders::orders(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::orders)
    , secondwindow(new order_detail)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&orders::on_back);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&orders::on_submit);
    connect(this,&orders::sendData,secondwindow,&order_detail::receiveData);
    on_select_all();
}

orders::~orders()
{
    delete ui;
}

void orders::save_id(const QString &data)
{
    User_ID=data;
}

void orders::on_back()
{
    Widget *page=new Widget;
    page->setReceivedData(User_ID);
    this->close();
    page->show();
}

void orders::on_select_all()
{

    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM orders;"));
    model->setHeaderData(0,Qt::Horizontal,tr("订单id"));
    model->setHeaderData(1,Qt::Horizontal,tr("订单日期"));
    model->setHeaderData(2,Qt::Horizontal,tr("客户id"));
    model->setHeaderData(3,Qt::Horizontal,tr("收银员id"));
    model->setHeaderData(4,Qt::Horizontal,tr("总金额"));
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();

}

void orders::on_submit()
{
    qint32 orders_id,customer_id,cashier_id;
    QDate orders_date;
    double money_amount=0;
    orders_id=ui->spinBox->value();
    orders_date=ui->dateEdit_2->date();
    customer_id=ui->spinBox_4->value();
    cashier_id=ui->spinBox_5->value();

    QSqlQuery insert;
    insert.prepare("INSERT INTO orders VALUES (?,?,?,?,?)");
    insert.bindValue(0,orders_id);
    insert.bindValue(1,orders_date);
    insert.bindValue(2,customer_id);
    insert.bindValue(3,cashier_id);
    insert.bindValue(4,money_amount);
    if(insert.exec())
        QMessageBox::information(nullptr, "infor", "success");
    else
        QMessageBox::information(nullptr, "infor", "open failed");
    emit sendData(orders_id);
    secondwindow->save_id(User_ID);
    this->close();
    secondwindow->show();
}

