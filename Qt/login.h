#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlQuery>
#include <widget.h>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

signals:
    void sendData(QString);

private slots:
    void on_login();

private:
    Ui::login *ui;
    Widget *widget_window;
};

#endif // LOGIN_H
