#include "addcard.h"
#include "ui_addcard.h"

addcard::addcard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcard)
{
    ui->setupUi(this);
}

addcard::~addcard()
{
    delete ui;
}
