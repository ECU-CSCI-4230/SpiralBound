#include "studycard.h"
#include "ui_studycard.h"
#include "mainwindow.h"
#include <iostream>
#include <util.h>

int x = 0;
Deck* newDeck = nullptr;

studycard::studycard(QWidget *parent, Deck* deck) :
    QDialog(parent),
    ui(new Ui::studycard)
{
    ui->setupUi(this);

    ui->label_deckName->setText(deck->name);
    ui->textBrowser->setText(deck->front[0]);
    newDeck = deck;
}


studycard::~studycard()
{
    delete ui;
}

void studycard::on_pushButton_flip_clicked()
{
    if(x % 2 == 0){
        ui->textBrowser->setText(newDeck->back[0]);
        x++;
        cout << "Back of the card.";
    }
    else {
        ui->textBrowser->setText(newDeck->front[0]);
        cout << "Front of the card.";
    }

}

