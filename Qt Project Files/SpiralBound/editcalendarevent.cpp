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
// Init Date: 12.02.2019
// Last Updated: 12.02.2019
void editcalendarevent::receiveData(QTableWidgetItem *item)
{
    qDebug() << "editcalendarevent: Item received" << item->text();

    ui->lineEdit_eventName->setText(item->text());
    //TODO: ui->dateTimeEdit->setDateTime()

}

// Author: Nicholas, Cam
// Init Date: 09.02.2019
// Last Updated: 09.02.2019
void editcalendarevent::on_buttonBox_accepted()
{
    // Qstrings
    QString eventName = ui->lineEdit_eventName->text();
    QString eventDateTime = ui->dateTimeEdit->text();

    // print q string to console
    std::cout << eventName.toStdString() << std::endl;
    std::cout << eventDateTime.toStdString() << std::endl;

    if(!eventName.isEmpty())
    {
        // createEvent(eventName, eventDateTime);
    }
    else //if eventName is empty, display warning message.
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Name of event cannot be empty,"
                                            " please try again.");
        messageBox.setFixedSize(500,200);
    }


    // TODO: Edit entry in Event List with new data

}
