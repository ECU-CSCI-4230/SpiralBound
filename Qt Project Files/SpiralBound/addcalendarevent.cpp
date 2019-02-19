#include "addcalendarevent.h"
#include "ui_addcalendarevent.h"
#include "mainwindow.h"
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <QTableWidget>
#include <QDebug>

addcalendarevent::addcalendarevent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcalendarevent)
{
    ui->setupUi(this);
}

addcalendarevent::~addcalendarevent()
{
    delete ui;
}

// Author: Nicholas, Cam, Jamie
// Init date: 05.02.2019
// Last Updated: 12.02.2019
void addcalendarevent::on_buttonBox_accepted()
{
    // Qstrings
    QString eventName = ui->lineEdit_eventName->text();
    QString eventDateTime = ui->dateTimeEdit->text();

    if(!eventName.isEmpty())
    {
        qDebug() << "addcalendarevent: sending name: " << eventName << "and datetime: " << eventDateTime;

        // Send data to mainwindow
        emit sendAddData(eventName, eventDateTime);

    }
    else //if eventName is empty, display warning message.
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Name of event cannot be empty, please try again.");
        messageBox.setFixedSize(500,200);
    }
}
