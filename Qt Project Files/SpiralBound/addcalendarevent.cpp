#include "addcalendarevent.h"
#include "ui_addcalendarevent.h"
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <string.h>
#include <stdlib.h>

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

    // print q string to console
    std::cout << eventName.toStdString() << std::endl;
    std::cout << eventDateTime.toStdString() << std::endl;

    if(!eventName.isEmpty())
    {
        createEvent(eventName, eventDateTime);
    }
    else //if eventName is empty, display warning message.
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Name of event cannot be empty,"
                                            " please try again.");
        messageBox.setFixedSize(500,200);
    }

    // TODO: Check list/reorder list with new event
    // TODO: Save/update
}
