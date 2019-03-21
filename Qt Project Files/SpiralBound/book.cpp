#include "book.h"
#include "section.h"
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

// Author:       Matthew Morgan
// Init date:    02-27-2019
// Last Updated: 02-27-2019
Book::Book(const char* nm, const char* auth) {
    bookName = QString::fromUtf8(nm);
    author = QString::fromUtf8(auth);
    date = QDate::currentDate();
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
// Init date:    02-26-2019
// Last Updated: 02-26-2019
void Book::setDate(QDate dt) { date = dt; }

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
int Book::numSections() {
    return (int)bookList->size();
}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-12-2019
Section* Book::getSection(int index) {
    if (index < 0 || index > (int)bookList->size()-1) { return nullptr; }

    auto it = bookList->begin();
    advance(it, index);
    return *it;
}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Book::removeSection(int index) {
    if (index < 0 || index > (int)bookList->size()-1) { return; }

    auto it = bookList->begin();
    advance(it, index);
    bookList->erase(it);
}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Book::addSection(QString name, QString desc) {
    bookList->push_back(new Section(name));
}

// Author:       Matthew Morgan
// Init date:    02-20-2019
// Last Updated: 02-27-2019
char* Book::toString() {
   char* str = new char[256];
   const char* nm = Util::QtoCString(bookName);
   const char* au = Util::QtoCString(author);
   const char* da = Util::QtoCString(date.toString(Qt::DateFormat::TextDate));

   sprintf(str, "%s\n%s\n%s", nm, au, da);
   return str;
}
