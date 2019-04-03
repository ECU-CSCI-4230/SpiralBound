#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include <QDateTime>
#include <QDir>
#include <qdebug.h>

addbook::addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbook)
{
    ui->setupUi(this);
    ui->label_newbook_date->setText(QDate::currentDate().toString());
    ui->lineEdit_bookName->setValidator(new QRegExpValidator( QRegExp("^[ A-Za-z0-9_-]+"), this ));
    ui->lineEdit_authorName->setValidator(new QRegExpValidator( QRegExp("^[ A-Za-z0-9_-]+"), this ));
}

addbook::~addbook()
{
    delete ui;
}

// Author: Ketu Patel
// Init date:    23.03.2019
// Last Updated: 02.04.2019
void addbook::on_buttonBox_accepted()
{
    QString bookNm = ui->lineEdit_bookName ->text();
    QString authNm = ui->lineEdit_authorName->text();
    QString date = ui->label_newbook_date->text();

    QDir dir(QDir::homePath() + "/.spiralbound/books/" + bookNm);
    if (dir.exists()){

        QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Notebook", "Already exists, Would you like to overwrite it?",
                                        QMessageBox::Yes|QMessageBox::No);
          // Overwrite the notebook
          if (reply == QMessageBox::Yes) {

          } else {

          }
    }

    // Create new notebook, reset calender and flask cards
    else{


    }

    if(!bookNm.isEmpty() && !authNm.isEmpty())
    {
        // Send bookNm and authNm to mainwindow.cpp
        emit sendBookData(bookNm, authNm, date);
    }

    else //if one of the field is empty, display error message.
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","None of the fields can be empty, please try again.");
        messageBox.setFixedSize(500,200);
    }
}
