#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectLogin=new Login;
    objectSerialPort_dll=new DLLSerialPort;
    objectPinCode=new DLLPinCode;
    objectRest_api_dll=new Rest_api_dll;
    base_url=MyUrl::getBase_url();
    connect(objectSerialPort_dll, SIGNAL(dllSerialPortReady()), this,SLOT(waitForPinCode()));
    connect(this, SIGNAL(pinCodeReceived()),this, SLOT(loginWithPinCode()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectLogin;
    delete objectPinCode;
    delete objectSerialPort_dll;
    delete objectPinCode;
    delete objectRest_api_dll;
    ui=nullptr;
    objectLogin=nullptr;
    objectPinCode=nullptr;
    objectSerialPort_dll=nullptr;
    objectPinCode=nullptr;
    objectRest_api_dll=nullptr;
}


void MainWindow::on_btnLogin_clicked()
{
    objectLogin->show();
}

void MainWindow::waitForPinCode()
{
    idCard=objectSerialPort_dll->interfaceReturnValue();
    qDebug()<<"HERE: "+idCard;

    objectPinCode->openDllDialog();
    pinCode=objectPinCode->returnFromDll();
    qDebug()<<pinCode;
    emit pinCodeReceived();
}

void MainWindow::loginWithPinCode()
{
    qDebug()<<"loginWithPincode";
    qDebug()<<idCard;
    QJsonObject jsonObj;
    jsonObj.insert("username",idCard);
    jsonObj.insert("password",pinCode);
    connect(objectRest_api_dll,SIGNAL(restApiReady()),this, SLOT(loginSlot()));
    QByteArray webtoken="";
    objectRest_api_dll->interfaceHttpEvent("post",base_url+"/login",webtoken,jsonObj);
}

void MainWindow::loginSlot()
{
    qDebug()<<"loginSlot";
    QByteArray response_data=objectRest_api_dll->interfaceReturnValue();
    qDebug()<<response_data;
     if(response_data!="false"){
         token="Bearer "+response_data;
         objectpankkiMain=new pankkiMain(idCard, token);
         objectpankkiMain->show();
         this->close();
     }
     else{

     }
}

void MainWindow::on_btnRestart_clicked()
{
    objectSerialPort_dll->restartSerialReading();
}
