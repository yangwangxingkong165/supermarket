//#include "widget.h"
#include "login.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("密码");
    bool ok = db.open();
    if (ok){
        QMessageBox::information(nullptr, "infor", "success");
    }
    else {
        QMessageBox::information(nullptr, "infor", "open failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }

    QSqlQuery select;
    select.prepare("SELECT * FROM user");
    select.exec();
    if(!select.next())
    {
        QMessageBox::information(nullptr, "infor", "首次使用，即将新建管理员账户");
        QString id,password;
        bool id_ok,password_ok;
        id=QInputDialog::getText(nullptr,"新建管理员信息","用户名",QLineEdit::Normal,"",&id_ok);
        password=QInputDialog::getText(nullptr,"新建管理员信息","密码",QLineEdit::Normal,"",&password_ok);
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
    l.show();
    return a.exec();
}




// QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
// db.setHostName("127.0.0.1");
// db.setPort(3306);
// db.setDatabaseName("student_sc");
// db.setUserName("root");
// db.setPassword("密码");
// bool ok = db.open();
// if (ok){
//     QMessageBox::information(nullptr, "infor", "success");
// }
// else {
//     QMessageBox::information(nullptr, "infor", "open failed");
//     qDebug()<<"error open database because"<<db.lastError().text();
// }
