#include "deletecalendarevent.h"
#include "ui_deletecalendarevent.h"

deletecalendarevent::deletecalendarevent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletecalendarevent)
{
    ui->setupUi(this);
}

deletecalendarevent::~deletecalendarevent()
{
    delete ui;
}

// Author: Nicholas
// Init Date: 05.02.2019
// Last Updated: 07.02.2019
void deletecalendarevent::on_buttonBox_accepted()
{

}

