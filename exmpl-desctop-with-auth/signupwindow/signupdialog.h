#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "Config.h"
#include "token.h"
#include <string.h>
#include <iostream>

namespace Ui {
class SignUpDialog;
}

class SignUpDialog : public QDialog, public token::TokenManager
{
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = nullptr);
    ~SignUpDialog();

protected:
    void sendRegistrationRequest(std::string username, std::string password) override;

private slots:
    void on_registerButton_clicked();

private:
    Ui::SignUpDialog *ui;
};

#endif // SIGNUPDIALOG_H
