#include "ui_mainwindow.h"
#include "mainwindow.h"

#include "signindialog.h"

void MainWindow::checkAuth(){

    hide();

    bool correctedToken = ValidateToken();
    if(!correctedToken){

        SignInDialog *signInDialog = new SignInDialog(this);
        signInDialog->setAttribute(Qt::WA_DeleteOnClose);

        signInDialog->exec();

    }
    else{
        show();
    }

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    checkAuth();

}

MainWindow::~MainWindow(){

    delete ui;

}
