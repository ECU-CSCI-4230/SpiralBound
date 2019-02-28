#include "editcalendarevent.h"
#include "ui_editcalendarevent.h"
#include "mainwindow.h"
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <QListWidget>
#include <QtDebug>
#include <QItemSelectionModel>

editcalendarevent::editcalendarevent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcalendarevent)
{
    ui->setupUi(this);
}

editcalendarevent::~editcalendarevent()
{
    delete ui;
}


// Author: Nicholas
// Init Date: 21.02.2019
// Last Updated: 21.02.2019
void editcalendarevent::receiveEditData(QString date, QString name, QString time)
{
    // Prefill line edit boxes with selected data
    ui->lineEdit_eventName->setText(name);
    ui->dateTimeEdit->setDate(QDate::fromString(date,"MM/dd/yyyy"));
    ui->dateTimeEdit->setTime(QTime::fromString(time,"hh:mm AP"));
}


// Author: Nicholas, Cam
// Init Date: 09.02.2019
// Last Updated: 21.02.2019
void editcalendarevent::on_buttonBox_accepted()
{
    QString name = ui->lineEdit_eventName->text();
    QString dateTime = ui->dateTimeEdit->text();

    if(!name.isEmpty())
    {
        // Send name and dateTime to mainwindow.cpp
        emit sendEditData(name, dateTime);
    }
    else //if eventName is empty, display warning message.
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Name of event cannot be empty, please try again.");
        messageBox.setFixedSize(500,200);
    }
}
