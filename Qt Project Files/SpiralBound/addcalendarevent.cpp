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

// Author: Cam
// Init Date: 07.02.2019
// Last Updated: 07.02.2019
void createEvent(QString name, QString eDT) // int pri
{
    QString eventName = name;
    QString eventDate = eDT.mid(0, 10);
    QString eventTime = eDT.right(8);
    // int  priority = pri;

    // Testing/Debugging
    std::cout << "This is the name: ";
    std::cout << eventName.toStdString() << std::endl;
    std::cout << "This is the new date: ";
    std::cout << eventDate.toStdString() << std::endl;
    std::cout << "This is the new time: ";
    std::cout << eventTime.toStdString() << std::endl;

    // TODO: Send proper variable names to Event.cpp
    //       to create new Event.


}

// Author: Nicholas, Cam, Jamie
// Init date: 05.02.2019
// Last Updated: 05.02.2019
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
