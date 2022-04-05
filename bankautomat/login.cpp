#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_returnButton_clicked()
{
        close();
}


void Login::on_loginButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("Salasana123");
    db.setDatabaseName("banksimul");

    if(db.open()) {
        QMessageBox::information(this,"Connection", "Database connected!");
    }
    else{
        QMessageBox::information(this, "Not Connected", "Database is not connected");

    }

}

