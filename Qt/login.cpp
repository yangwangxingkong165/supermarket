#include "login.h"
#include "ui_login.h"
#include "widget.h"
login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
    , widget_window(new Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&login::on_login);
    connect(this,&login::sendData,widget_window,&Widget::receiveData);
}

login::~login()
{
    delete ui;
}

void login::on_login()
{
    QString id,password;
    id=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    QSqlQuery select;
    select.prepare("SELECT user_passsword FROM user WHERE id=?;");
    select.bindValue(0,id);
    select.exec();
    if(select.next())
    {
        if(password==select.value(0))
        {
            emit sendData(id);
            this->close();
            widget_window->show();
        }
        else
        {
            QMessageBox::critical(this,"错误","密码错误，请重试！");
        }
    }
    else
    {
        QMessageBox::critical(this,"错误","不存在该用户！");
    }

}
