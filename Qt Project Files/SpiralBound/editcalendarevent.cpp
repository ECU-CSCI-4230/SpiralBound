#include "editcalendarevent.h"
#include "ui_editcalendarevent.h"

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
