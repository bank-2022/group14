#include "pankkimain.h"
#include "ui_pankkimain.h"

pankkiMain::pankkiMain(QString stuUsername, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pankkiMain)
{
    ui->setupUi(this);
    ui->labelUsername->setText("idKortti = "+stuUsername);
    username=stuUsername;
    webtoken=token;
    objectRest_api_dll=new Rest_api_dll();
}

pankkiMain::~pankkiMain()
{
    delete ui;
}

void pankkiMain::on_saldoButton_clicked()
{
    QString site_url=MyUrl::getBase_url()+"/tili/"+username;

    connect(objectRest_api_dll,SIGNAL(restApiReady()),this, SLOT(saldoSlot()));
    objectRest_api_dll->interfaceHttpEvent("get",site_url,webtoken);

}

void pankkiMain::saldoSlot()
{
    response_data=objectRest_api_dll->interfaceReturnValue();
    qDebug()<<"DATA="+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        saldo+=json_obj["idTili"].toString()+"Tilin saldo on  "+QString::number(json_obj["Saldo"].toInt())+" euroa. \r";
    }
    qDebug()<<saldo;
    ui->textGrades->setText(saldo);
}

void pankkiMain::on_tilitapahtumatbtn_clicked()
{
    QString site_url=MyUrl::getBase_url()+"/tilitapahtumat/"+username;

    connect(objectRest_api_dll,SIGNAL(restApiReady()),this, SLOT(tilitapahtumatSlot()));
    objectRest_api_dll->interfaceHttpEvent("get",site_url,webtoken);
}

void pankkiMain::tilitapahtumatSlot()
{
    response_data=objectRest_api_dll->interfaceReturnValue();
    qDebug()<<"DATA="+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString tilitapahtumat;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        tilitapahtumat+="idTilitapahtumat : "+QString::number((json_obj["idTilitapahtumat"].toInt()))+" \r Paivamaara : "+json_obj["Paivamaara"].toString()+" \r Tapahtuma : "+json_obj["Tapahtuma"].toString()+" \r Summa : "+QString::number(json_obj["Summa"].toInt())+" \r idKortti : "+QString::number(json_obj["idKortti"].toInt())+" \r idTili : "+QString::number(json_obj["idTili"].toInt())+" \r";
    }

    qDebug()<<tilitapahtumat;

    ui->textGrades->setText(tilitapahtumat);
}


void pankkiMain::on_pushButton_clicked()
{
    qDebug()<<"Nosto ikkuna aukeaa";
    //nosto *objectNosto;
    //objectNosto=new nosto(username,webtoken,saldo,tilitiedot);
    //objectNosto->exec();
}

