#include "adddeck.h"
#include "ui_adddeck.h"
#include "QMessageBox"

adddeck::adddeck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddeck)
{
    ui->setupUi(this);
}

adddeck::~adddeck()
{
    delete ui;
}


void adddeck::on_buttonBox_accepted()
{
    if (ui->lineEdit_deck->text().isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Name of deck cannot be empty, please try again.");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        emit sendDeckData(ui->lineEdit_deck->text());
    }
}

void adddeck::on_buttonBox_rejected()
{
    this->close();
}
