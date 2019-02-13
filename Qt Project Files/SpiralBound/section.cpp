#include "section.h"

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
Page* Section::getPage(int index) {}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Section::addPage(QString nm) {}

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Section::removePage(int index) {}

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
int Section::numPages() {}
