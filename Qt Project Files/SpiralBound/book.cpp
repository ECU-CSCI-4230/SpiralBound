#include "book.h"
#include <section.h>
#include <list>

using namespace std;

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-12-2019
Book::Book(QString nm, QString auth) {
    bookName = nm;
    author   = auth;
    date     = QDate::currentDate();
    bookList = new list<Section*>();
}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QString Book::getName() { return bookName; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QString Book::getAuthor() { return author; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QDate Book::getDate() { return date; }


// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Book::setAuthor(QString anm) { author = anm; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Book::setName(QString nm){ bookName = nm; };

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
int Book::numSections() {}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-12-2019
Section* Book::getSection(int index) {}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Book:: removeSection(int index) {}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Book::addSection(QString name, QString desc) {}
