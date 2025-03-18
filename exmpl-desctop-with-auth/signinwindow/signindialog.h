#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QMessageBox>

#include "Config.h"
#include "token.h"
#include <string.h>
#include <iostream>

namespace Ui {
class SignInDialog;
}

class SignInDialog : public QDialog, public token::TokenManager
{
    Q_OBJECT

public:
    explicit SignInDialog(QWidget *parent = nullptr);
    ~SignInDialog();

protected:
    void sendLoginRequest(std::string username, std::string password) override;

private slots:
    void on_goToRegistrationButton_clicked();

    void on_signinButton_clicked();

private:
    Ui::SignInDialog *ui;
};

#endif // SIGNINDIALOG_H
