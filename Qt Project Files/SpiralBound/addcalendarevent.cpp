#include "addcalendarevent.h"
#include "ui_addcalendarevent.h"
#include <QTextStream>
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
// Last Updated: 05.02.2019
bool checkTime(QString eventTime)
{
    // if empty
    if(!eventTime.isEmpty())
    {
        // length
        if(eventTime.length() == 5)
        {
            // collon
            if(eventTime.at(2) == ":")
            {
                // ##:##
                if(eventTime.at(0).isDigit() && eventTime.at(1).isDigit() &&
                        eventTime.at(3).isDigit() && eventTime.at(4).isDigit())
                {
                    return true;
                }
            }
        }
    }

    return false;
}

// Author: Nicholas, Cam, Jamie
// Init date: 05.02.2019
// Last Updated: 05.02.2019
bool checkDate(QString eventDate)
{
    // if empty
    if(!eventDate.isEmpty())
    {
        // length
        if(eventDate.length() == 10)
        {
            // slashes
            if(eventDate.at(2) == "/" && eventDate.at(5) == "/")
            {
                // ##/##/####
                if(eventDate.at(0).isDigit() && eventDate.at(1).isDigit() &&
                        eventDate.at(3).isDigit() && eventDate.at(4).isDigit() &&
                            eventDate.at(6).isDigit() && eventDate.at(7).isDigit() &&
                                eventDate.at(8).isDigit() && eventDate.at(9).isDigit())
                {
                    return true;
                }
            }
        }
    }

    return false;

}

// Author: Nicholas, Cam, Jamie
// Init date: 05.02.2019
// Last Updated: 05.02.2019
void addcalendarevent::on_buttonBox_accepted()
{
    // Qstrings
    QString eventName = ui->lineEdit_eventName->text();
    QString eventDate = ui->lineEdit_eventDate->text();
    QString eventTime = ui->lineEdit_eventTime->text();

    // print q string to console
    std::cout << eventName.toStdString() << std::endl;
    std::cout << eventDate.toStdString() << std::endl;
    std::cout << eventTime.toStdString() << std::endl;

    // Check Date and Time
    if(checkDate(eventDate) == true)
    {
        qInfo("checkDate works");
    }

    if(checkTime(eventTime) == true)
    {
        qInfo("checkTime works");
    }

    // Concat. 3 strings together

    // Check list/reorder list with new event

    // Save/update
}
