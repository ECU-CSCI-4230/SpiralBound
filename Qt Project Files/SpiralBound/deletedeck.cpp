#include "deletedeck.h"
#include "ui_deletedeck.h"

deletedeck::deletedeck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletedeck)
{
    ui->setupUi(this);
}

deletedeck::~deletedeck()
{
    delete ui;
}

// Author: Cam, Nick
// Init Date:    26.03.2019
// Last Updated: 02.04.2019
void deletedeck::on_buttonBox_accepted()
{
    emit sendDeleteData(true);
}

// Author: Cam, Nick
// Init Date:    26.03.2019
// Last Updated: 02.04.2019
void deletedeck::on_buttonBox_rejected()
{
    this->close();
}
