#include "studycard.h"
#include "ui_studycard.h"
#include "mainwindow.h"
#include <iostream>
#include <util.h>

extern int side, index;
extern Deck* copyDeck;


/*
 * Constructor
*/
studycard::studycard(QWidget *parent, Deck* deck) :
    QDialog(parent),
    ui(new Ui::studycard)
{
    ui->setupUi(this);

    ui->label_deckName->setText(deck->name);
    ui->textBrowser->setText(deck->front[0]);
    ui->pushButton_previous->setEnabled(false);
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

/*
 * Destructor
*/
studycard::~studycard()
{
    delete ui;
}

/*
 * on_pushButton_flip_clicked() will "flip" the card from front to back,
 * or from back to front.
*/
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

/*
 * on_pushButton_ok_clicked() will close the window when the user
 * clicks "Ok" button. This will usually signify the user being
 * finished with studying.
*/
void studycard::on_pushButton_ok_clicked()
{
    this->close();
}

/*
 * on_pushButton_previous_clicked() will go back one card.
 * If the deck being studied is at index 0, then the button
 * will not be available to push.
*/
void studycard::on_pushButton_previous_clicked()
{
    side = 0;
    index--;
    if (index == 0)
    {
        ui->pushButton_next->setEnabled(true);
        ui->pushButton_previous->setEnabled(false);
    }
    else
    {
        ui->pushButton_next->setEnabled(true);
        ui->pushButton_previous->setEnabled(true);
    }
    ui->textBrowser->clear();
    ui->textBrowser->setText(copyDeck->front[index]);
    qDebug() << "Index: " << index;
}

/*
 * on_pushButton_next_clicked() will go to the next card in the
 * index. If the deck is at the end of the deck, then the button
 * will not be available to be clicked.
*/
void studycard::on_pushButton_next_clicked()
{
    side = 0;
    index++;
    if (index == copyDeck->front.length() - 1)
    {
        ui->pushButton_next->setEnabled(false);
        ui->pushButton_previous->setEnabled(true);
    }
    else
    {
        ui->pushButton_next->setEnabled(true);
        ui->pushButton_previous->setEnabled(true);
    }
    ui->textBrowser->clear();
    ui->textBrowser->setText(copyDeck->front[index]);
    qDebug() << "Index: " << index;
}
