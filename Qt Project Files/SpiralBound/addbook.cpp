#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include <QDateTime>
#include <QDir>
#include <qdebug.h>
#include "util.h"

addbook::addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbook)
{
    ui->setupUi(this);
    ui->lbl_NewDate->setText(QDate::currentDate().toString());
    ui->lineEdit_bookName->setValidator(new QRegExpValidator( QRegExp("^[ A-Za-z0-9_-]+"), this ));
    ui->lineEdit_authorName->setValidator(new QRegExpValidator( QRegExp("^[ A-Za-z0-9_-]+"), this ));
}

addbook::~addbook()
{
    delete ui;
}

// Author:       Ketu Patel, Matthew Morgan
// Init date:    23.03.2019
// Last Updated: 05.04.2019
void addbook::on_buttonBox_accepted()
{
    QString bookNm = ui->lineEdit_bookName->text();
    QString authNm = ui->lineEdit_authorName->text();
    QString date = ui->lbl_NewDate->text();

    // Display a message if a field is empty
    if (bookNm.isEmpty() || authNm.isEmpty()) {
        Util::showError("Error", "Please enter both a notebook title and author!");
        return;
    }

    if (QDir(QDir::homePath() + "/.spiralbound/books/" + bookNm).exists()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Overwrite Confirmation",
                "A notebook with the given name already exists! Overwrite?");

        // Do nothing if overwrite confirmation was not provided
        if (reply == QMessageBox::No) { return; }
    }

    // Send book, author, and date
    emit sendBookData(bookNm, authNm, date);
}
