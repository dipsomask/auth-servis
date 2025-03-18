
#include <QApplication>
#include <QWidget>

#include "mainwindow/mainwindow.h"
#include "signupwindow/signupdialog.h"
#include "signinwindow/signindialog.h"
#include "Config.h"
#include "token.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();

}
