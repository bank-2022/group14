#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnLogin_clicked()
{
    QString a=ui->lePinCode->text();
    this->setDialogValue(a);
    this->close();
}

QString Dialog::getDialogValue() const
{
    return dialogValue;
}

void Dialog::setDialogValue(const QString &value)
{
    dialogValue = value;
}
