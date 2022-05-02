#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    base_url=MyUrl::getBase_url();
    objectRest_api_dll=new Rest_api_dll();

}

Login::~Login()
{
    delete ui;
    ui=nullptr;
    delete objectpankkiMain;
    objectpankkiMain=nullptr;
}

void Login::on_btnLogin_clicked()
{
    username=ui->leUsername->text();
    password=ui->lePassword->text();


    QJsonObject jsonObj;
    jsonObj.insert("idKortti",username);
    jsonObj.insert("pin",password);
    connect(objectRest_api_dll,SIGNAL(restApiReady()),this, SLOT(loginSlot()));
    QByteArray webtoken="";
    objectRest_api_dll->interfaceHttpEvent("post",base_url+"/login",webtoken,jsonObj);

}

void Login::loginSlot()
{
   QByteArray response_data=objectRest_api_dll->interfaceReturnValue();
   qDebug()<<response_data;
    if(response_data!="false"){
        token="Bearer "+response_data;
        objectpankkiMain=new pankkiMain(username,token);
        objectpankkiMain->show();
        this->close();
    }
    else{
        ui->leUsername->setText("");
        ui->lePassword->setText("");
    }
}
