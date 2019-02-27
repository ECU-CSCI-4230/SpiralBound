#include "section.h"
#include "util.h"

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-12-2019
Section::Section(QString nm, QString ds)
{
    secName = nm;
    desc = ds;
    pages = new list<Page*>();
}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QString Section::getSecName() { return secName; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QString Section::getDesc() { return desc; }

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
