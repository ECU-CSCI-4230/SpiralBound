#include "addcard.h"
#include "ui_addcard.h"
#include "mainwindow.h"
#include <QtDebug>

addcard::addcard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcard)
{
    ui->setupUi(this);
}

addcard::~addcard()
{
    delete ui;
}

void addcard::on_buttonBox_accepted()
{
    // Deck name
    QString deckName = ui->lineEdit_deck->text();
    QString front = ui->textEdit_front->toPlainText();
    QString back = ui->textEdit_back->toPlainText();

    // Send data to mainwindow.cpp
    emit sendCardData(deckName, front, back);

}
