#ifndef BOOK_H
#define BOOK_H
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
#include <linkedlist.h>
class Book
{
public:
    Book(QString nm, QString auth);
    QString getBookName();
    QString getAuthor();
    QDate getDate();
    Section* getSection(int i);
   void removeSection(int index);

    void addSection(QString name, QString desc);
    void setBookName(QString name);
    void setAuthor(QString name);
    void renameBook(QString name);


private:
        QString bookName, author;
        QDate date;
        Section* sec;
        LinkedList<Section>* bookList;

};

#endif // BOOK_H
