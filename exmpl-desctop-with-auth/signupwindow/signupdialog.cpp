#include "signupdialog.h"
#include "ui_signupdialog.h"


void SignUpDialog::sendRegistrationRequest(std::string username, std::string password){


    cpr::Response resp = cpr::Post(
        cpr::Url{"http://localhost:3000/registration"},
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

}


SignUpDialog::SignUpDialog(QWidget *parent): QDialog(parent), ui(new Ui::SignUpDialog){

    ui->setupUi(this);

}

SignUpDialog::~SignUpDialog(){

    delete ui;

}

void SignUpDialog::on_registerButton_clicked(){

    std::string username = (ui->usernameEdit->toPlainText()).toStdString();
    std::string password = (ui->passwordEdit->toPlainText()).toStdString();

    std::cout << "Register button clicked:\n" <<
                 "   username: " << username <<
                 "\n   password: " << password <<
                 std::endl;
    
    QMessageBox messageBox;
    
    try
    {
        sendRegistrationRequest(username, password);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';

        messageBox.setText(e.what());
        messageBox.exec();
        return;
    }
    
    messageBox.setText("You registered successfuly.");
    messageBox.exec();

    close();

    return;

}

