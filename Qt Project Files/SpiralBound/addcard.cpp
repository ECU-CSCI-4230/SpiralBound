#include "addcard.h"
#include "ui_addcard.h"
#include "mainwindow.h"
#include "util.h"
#include <QtDebug>

addcard::addcard(QWidget *parent, list<Deck*> deckList) :
    QDialog(parent),
    ui(new Ui::addcard)
{
    ui->setupUi(this);

    QStringList list;

    // Populate comboBox
    for(Deck* deck : deckList)
    {
        list.append(deck->name);
    }

    for (int i = 0; i < list.length(); i++)
    {
        ui->comboBox_deck->addItem(list[i]);
    }
}

addcard::~addcard()
{
    delete ui;
}

void addcard::on_buttonBox_accepted()
{
    // LEGACY CODE
    // Deck name
    // QString deckName = ui->lineEdit_deck->text();
    // QString front = ui->textEdit_front->toPlainText();
    // QString back = ui->textEdit_back->toPlainText();

    // Send data to mainwindow.cpp
    // emit sendCardData(deckName, front, back);

    if (ui->textEdit_front->toPlainText().isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Front of card cannot be blank.");
        messageBox.setFixedSize(500,200);
        this->close();
    }
    else
    {
        QString deckName = ui->comboBox_deck->currentText();
        QString front = ui->textEdit_front->toPlainText();
        QString back = ui->textEdit_back->toPlainText();

        emit sendCardData(deckName, front, back);
    }
}

// Author:       Cam
// Init Date:    09.04.2019
// Last Updated: 09.04.2019
void addcard::on_buttonBox_rejected()
{
    this->close();
}
