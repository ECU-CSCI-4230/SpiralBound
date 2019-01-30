#include "aboutspiralbound.h"
#include "ui_aboutspiralbound.h"

// Constructor
AboutSpiralBound::AboutSpiralBound(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutSpiralBound)
{
    ui->setupUi(this);
}

// Destructor
AboutSpiralBound::~AboutSpiralBound()
{
    delete ui;
}

//-----------------------------------------------------------+
//                       Actions                             |
//-----------------------------------------------------------+

// Author: Nicholas Ellis
// Init date: 29.01.2019
// Last Updated: 29.01.2019
void AboutSpiralBound::on_pushButton_ok_clicked()
{
    close();
}
