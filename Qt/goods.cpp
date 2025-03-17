#include "goods.h"
#include "ui_goods.h"
#include "widget.h"

Goods::Goods(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Goods)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&Goods::on_submit);
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,this,&Goods::on_back);
    on_select_all();
}

Goods::~Goods()
{
    delete ui;
}

void Goods::save_id(const QString &data)
{
    User_ID=data;
}
void Goods::on_back()
{
    Widget *page=new Widget;
    page->setReceivedData(User_ID);
    this->close();
    page->show();
}

void Goods::on_select_all()
{
    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM goods;"));
    model->setHeaderData(0,Qt::Horizontal,tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,tr("名字"));
    model->setHeaderData(2,Qt::Horizontal,tr("种类"));
    model->setHeaderData(3,Qt::Horizontal,tr("售价"));
    model->setHeaderData(4,Qt::Horizontal,tr("数量"));
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();

}

void Goods::on_submit()
{
    QString name,goods_class;
    double sale_price;
    qint32 id,amount;
    id=ui->spinBox->value();
    name=ui->lineEdit->text();
    goods_class=ui->lineEdit_2->text();
    sale_price=ui->doubleSpinBox->value();
    amount=0;
    QSqlQuery insert;
    insert.prepare("INSERT INTO goods VALUES (?,?,?,?,?)");
    insert.bindValue(0,id);
    insert.bindValue(1,name);
    insert.bindValue(2,goods_class);
    insert.bindValue(3,sale_price);
    insert.bindValue(4,amount);
    if(insert.exec())
        QMessageBox::information(nullptr, "infor", "success");
    else
        QMessageBox::information(nullptr, "infor", "open failed");
    on_select_all();
}

