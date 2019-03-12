#include "deletecard.h"
#include "ui_deletecard.h"

deletecard::deletecard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletecard)
{
    ui->setupUi(this);
}

deletecard::~deletecard()
{
    delete ui;
}

// Author: Jamie
// Init Date: 12.03.2019
// Last Updated: 12.03.2019
void deletecard::on_buttonBox_accepted()
{
    // Send data to mainwindow
    emit sendDeleteData(true);
}
