#include "storehouse.h"
#include "ui_storehouse.h"
#include "widget.h"

storehouse::storehouse(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::storehouse)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&storehouse::on_back);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&storehouse::on_submit);
    on_select_all();
}

storehouse::~storehouse()
{
    delete ui;
}

void storehouse::save_id(const QString &data)
{
    User_ID=data;
}

void storehouse::on_back()
{
    Widget *page=new Widget;
    page->setReceivedData(User_ID);
    this->close();
    page->show();
}

void storehouse::on_select_all()
{

    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("SELECT * FROM storehouse;"));
    model->setHeaderData(0,Qt::Horizontal,tr("仓库id"));
    model->setHeaderData(1,Qt::Horizontal,tr("仓库名"));
    model->setHeaderData(2,Qt::Horizontal,tr("地址"));
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();

}

void storehouse::on_submit()
{
    qint32 id;
    QString name,address;
    id=ui->spinBox->value();
    name=ui->lineEdit->text();
    address=ui->lineEdit_2->text();

    QSqlQuery insert;
    insert.prepare("INSERT INTO storehouse VALUES (?,?,?)");
    insert.bindValue(0,id);
    insert.bindValue(1,name);
    insert.bindValue(2,address);
    if(insert.exec())
        QMessageBox::information(nullptr, "infor", "success");
    else
        QMessageBox::information(nullptr, "infor", "open failed");
    on_select_all();
}
