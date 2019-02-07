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

// Author: Cam
// Init date: 05.02.2019
// Last Updated: 05.02.2019
bool checkName(QString eventName)
{
    // Make sure eventName is not empty.
    if(eventName.isEmpty())
    {
        return false;
    }
    else
    {
        return true;
    }
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


    // Check list/reorder list with new event


    // Save/update
}
