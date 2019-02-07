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
