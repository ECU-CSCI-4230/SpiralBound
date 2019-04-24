#include "studycard.h"
#include "ui_studycard.h"
#include "mainwindow.h"
#include <iostream>
#include <util.h>

extern int side, index;
extern Deck* copyDeck;

studycard::studycard(QWidget *parent, Deck* deck) :
    QDialog(parent),
    ui(new Ui::studycard)
{
    ui->setupUi(this);

    ui->label_deckName->setText(deck->name);
    ui->textBrowser->setText(deck->front[0]);
    copyDeck = deck;

    if (index == copyDeck->front.length())
    {
        this->close();
    }

    if (index < 0)
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Cannot go past first card in deck.");
        messageBox.setFixedSize(500,200);
        index = 0;
    }
}


studycard::~studycard()
{
    delete ui;
}

void studycard::on_pushButton_flip_clicked()
{
    ui->textBrowser->clear();
    qDebug() << "Side:" << side;

    if(side % 2 == 0){
        ui->textBrowser->setText(copyDeck->back[index]);
        side++;
        qDebug() << "Back of the card. \n";
    }
    else {
        ui->textBrowser->setText(copyDeck->front[index]);
        side++;
        qDebug() << "Front of the card. \n";
    }
}


void studycard::on_pushButton_ok_clicked()
{
    this->close();
}

void studycard::on_pushButton_previous_clicked()
{
    side = 0;
    if (index == 0)
    {
        ui->pushButton_previous->hide();
        ui->textBrowser->clear();
        index--;
        ui->textBrowser->setText(copyDeck->front[index]);
        qDebug() << "Index: " << index;
    }
    else
    {
        ui->pushButton_previous->show();
        ui->textBrowser->clear();
        index--;
        ui->textBrowser->setText(copyDeck->front[index]);
        qDebug() << "Index: " << index;
    }
}

void studycard::on_pushButton_next_clicked()
{
    side = 0;
    if (index == copyDeck->front.length() - 1)
    {
        ui->pushButton_next->hide();
        ui->textBrowser->clear();
        index++;
        ui->textBrowser->setText(copyDeck->front[index]);
        qDebug() << "Index: " << index;
    }
    else
    {
        ui->pushButton_next->show();
        ui->textBrowser->clear();
        index++;
        ui->textBrowser->setText(copyDeck->front[index]);
        qDebug() << "Index: " << index;
    }
}
