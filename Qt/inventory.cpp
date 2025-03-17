#include "inventory.h"
#include "ui_inventory.h"
#include "widget.h"

inventory::inventory(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inventory)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&inventory::on_back);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&inventory::on_submit);
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,this,&inventory::on_select_all);
}

inventory::~inventory()
{
    delete ui;
}

void inventory::on_back()
{
    Widget *page=new Widget;
    this->close();
    page->show();
}

void inventory::on_select_all()
{

    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM inventory;"));
    model->setHeaderData(0,Qt::Horizontal,tr("仓库id"));
    model->setHeaderData(1,Qt::Horizontal,tr("商品id"));
    model->setHeaderData(2,Qt::Horizontal,tr("库存"));
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();

}

void inventory::on_submit()
{
    qint32 storehouse_id,goods_id,amount;
    storehouse_id=ui->spinBox->value();
    goods_id=ui->spinBox_2->value();
    amount=ui->spinBox_3->value();

    QSqlQuery insert;
    insert.prepare("INSERT INTO inventory VALUES (?,?,?)");
    insert.bindValue(0,storehouse_id);
    insert.bindValue(1,goods_id);
    insert.bindValue(2,amount);
    if(insert.exec())
        QMessageBox::information(nullptr, "infor", "success");
    else
        QMessageBox::information(nullptr, "infor", "open failed");
}

