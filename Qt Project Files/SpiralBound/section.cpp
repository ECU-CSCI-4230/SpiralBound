#include "section.h"
#include <QPlainTextDocumentLayout>

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 04-05-2019
Section::Section(QString nm)
{
    secName = nm;
    pages = new list<Page*>();
    col = *(new QColor(DEF_COLOR));
    doc = new QTextDocument();
    doc->setDocumentLayout(new QPlainTextDocumentLayout(doc));
    doc->setDefaultFont(QFont("Courier", 10));
}

// Author:       Matthew Morgan
// Init date:    03-20-2019
// Last Updated: 03-20-2019
QTextDocument* Section::getDoc() { return doc; }

// Author:       Matthew Morgan
// Init date:    03-20-2019
// Last Updated: 03-20-2019
void Section::setDoc(QTextDocument* nDoc) { doc = nDoc; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QString Section::getSecName() { return secName; }

// Author:       Matthew Morgan
// Init Date:    03-20-2019
// Last Updated: 03-20-2019
void Section::setColor(QColor color) { col = color; }

// Author:       Matthew Morgan
// Init Date:    03-20-2019
// Last Updated: 03-20-2019
QColor Section::getColor() { return col; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Section::setName(QString nm) { secName = nm; }

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-12-2019
Page* Section::getPage(int index) {
    if (index < 0 || index > (int)pages->size()-1) { return nullptr; }

    auto it = pages->begin();
    advance(it, index);
    return *it;
}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Section::addPage(QString nm) {
    pages->push_back(new Page(nm));
}

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Section::removePage(int index) {
    if (index < 0 || index > (int) pages->size()-1) { return; }

    auto it = pages->begin();
    advance(it, index);
    pages->erase(it);
}

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
int Section::numPages() {
    return (int) pages->size();
}

// Author:       Matthew Morgan
// Init date:    02-20-2019
// Last Updated: 03-21-2019
QString Section::toString() {
    return QString("%1\n%2\n%3").arg(secName, col.name(), doc->toPlainText());
}

// Author:       Matthew Morgan
// Init Date:    03-22-2019
// Last Updated: 03-22-2019
void Section::loadPage(Page* pg) { pages->push_back(pg); }
