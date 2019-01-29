#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Author: Nicholas Ellis
// Init Date: 01-29-2019
// Last Updated: 01-29-2019
void MainWindow::on_pushButton_3_clicked()
{
    // Print to Console
    qInfo("Clicked NewFile Button");
}
