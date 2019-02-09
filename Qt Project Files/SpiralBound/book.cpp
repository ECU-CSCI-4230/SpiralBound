#include "book.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutspiralbound.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <qlistwidget.h>
#include <QListWidget>
#include <QListWidget>
#include <thewidgetitem.h>
#include <section.h>
#include <list>
#include <linkedlist.h>

Book::Book(QString nm, QString auth){
  bookName = nm;
  author   = auth;
  date = QDate::currentDate();
   sec = new Section();
  LinkedList<Section>* bookList = new LinkedList<Section>();
}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
QString Book::getBookName(){
    return bookName;
};

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
QString Book::getAuthor(){
    return author;

};

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
QDate Book::getDate(){
    return date;
};

// Author:
// Init date:
// Last Updated:
Section* Book::getSection(int i){

    return bookList->get_index_item(i);

};

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Book:: removeSection(int index){

    Section *s = getSection(index);
    bookList->remove(*s);
};

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Book::addSection(QString name, QString desc){
   Section *s = new Section(name, desc);
   bookList->add(*s);

};

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Book::setBookName(QString nm)
{
    bookName = nm;
};

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Book::setAuthor(QString anm){
    author = anm;
};

// Author:
// Init date:
// Last Updated:
void Book::renameBook(QString nm){
    bookName = nm;
};
