#include "page.h"

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
Page::Page()
{
    pageName = "default";
}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QString Page::getPageName() { return pageName; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
QDate Page::getDate() { return date; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Page::setPgName(QString nm) { pageName = nm; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
Block* Page::getBlock(int index) {}

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Page::addBlock(short type) {}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Page::removeBlock(int index) {}
