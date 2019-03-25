#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include <QDateTime>
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

void addbook::on_buttonBox_accepted()
{
    QString bookNm = ui->lineEdit_bookName ->text();
    QString authNm = ui->lineEdit_authorName->text();


    if(!bookNm.isEmpty() && !authNm.isEmpty())
    {
        // Send bookNm and authNm to mainwindow.cpp
        emit sendBookData(bookNm, authNm);
    }

    else //if one of the field is empty, display error message.
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","None of the fields can be empty, please try again.");
        messageBox.setFixedSize(500,200);
    }
}
