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

    /*if (deckList.empty())
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","No Decks Exist.");
        messageBox.setFixedSize(500,200);
        this->close();
    }*/
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
    // Deck name
    // QString deckName = ui->lineEdit_deck->text();
    // QString front = ui->textEdit_front->toPlainText();
    // QString back = ui->textEdit_back->toPlainText();

    // Send data to mainwindow.cpp
    // emit sendCardData(deckName, front, back);

}
