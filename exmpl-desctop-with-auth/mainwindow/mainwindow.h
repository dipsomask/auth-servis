#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "Config.h"
#include "token.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public token::TokenManager
{
    Q_OBJECT

public:
    void checkAuth();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#include "ui_mainwindow.h"

#endif // MAINWINDOW_H
