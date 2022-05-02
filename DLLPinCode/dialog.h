#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QString getDialogValue() const;
    void setDialogValue(const QString &value);

private slots:
    void on_btnLogin_clicked();

private:
    Ui::Dialog *ui;
    QString dialogValue;
};

#endif // DIALOG_H
