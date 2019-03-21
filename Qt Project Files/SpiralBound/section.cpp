#include "section.h"
#include "util.h"

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 03-20-2019
Section::Section(QString nm, QString ds)
{
    secName = nm;
    desc = ds;
    pages = new list<Page*>();
    col = *(new QColor(DEF_COLOR));
    doc = new QTextDocument();
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

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QString Section::getDesc() { return desc; }

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

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Section::setDesc(QString dc) { desc = dc; }

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
// Last Updated: 02-27-2019
char* Section::toString() {
    char* str = new char[256];
    const char* nm = Util::QtoCString(secName);
    const char* dsc = Util::QtoCString(desc);

    sprintf(str, "%s\n%s", nm, dsc);
    return str;
}
