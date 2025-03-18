#include "signindialog.h"
#include "ui_signindialog.h"
#include "signupdialog.h"

#include <QCloseEvent>
#include <QMessageBox>

#include "Config.h"
#include "token.h"
#include <string.h>
#include <iostream>


void SignInDialog::sendLoginRequest(std::string username, std::string password){


    cpr::Response resp = cpr::Get(
        cpr::Url{"http://localhost:3000/login"},
        cpr::Header{{"username", username}, {"passwd", password}}
    );

    int statusCode = resp.status_code;
    
    if(statusCode != 200){
        
        throw std::runtime_error(
            std::string("auth-servis send response status code ") + 
                        std::to_string(statusCode) + 
                        std::string(resp.raw_header));
    }

    std::cout << "TokenManager message: \n" << "    " <<
                "auth-servis send 200 request status code with: \n" <<
                "        message: " << resp.text << std::endl <<
                "        headers: " << resp.raw_header << std::endl;
    
    
    auto access_t_HeaderValue = resp.header["access-token"];
    auto refresh_t_HeaderValue = resp.header["refresh-token"];
    if(access_t_HeaderValue.empty() || refresh_t_HeaderValue.empty()){
        
        throw std::runtime_error(
            std::string("auth-servis send 200 request status code\n") +
            std::string("BUT don't send 'access-token' or 'refresh-token' header.\n"));
    }

    int updatingConfing = updateAllDataInConfigWithJson(
                            "access-t", 
                            access_t_HeaderValue
                        );
    if(updatingConfing != 0)
        throw std::runtime_error("invalid updating access-token");

    updatingConfing = updateAllDataInConfigWithJson(
                            "refresh-t", 
                            refresh_t_HeaderValue
                        );
    if(updatingConfing != 0)
        throw std::runtime_error("invalid updating refresh-token");
}


SignInDialog::SignInDialog(QWidget *parent): QDialog(parent), ui(new Ui::SignInDialog){

    ui->setupUi(this);

}

SignInDialog::~SignInDialog(){

    delete ui;

}

void SignInDialog::on_goToRegistrationButton_clicked(){

    SignUpDialog *signUpDialog = new SignUpDialog(this);
    signUpDialog->setAttribute(Qt::WA_DeleteOnClose);

    signUpDialog->exec();

}


void SignInDialog::on_signinButton_clicked(){

    std::string username = (ui->usernameEdit->toPlainText()).toStdString();
    std::string password = (ui->passwordEdit->toPlainText()).toStdString();

    std::cout << "Signin button clicked:\n" <<
                 "   username: " << username <<
                 "\n   password: " << password <<
                 std::endl;
    
    QMessageBox messageBox;
    
    try
    {
        sendLoginRequest(username, password);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';

        messageBox.setText(e.what());
        messageBox.exec();
        return;
    }
    close();
    return;

}

