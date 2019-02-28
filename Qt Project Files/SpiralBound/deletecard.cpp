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
