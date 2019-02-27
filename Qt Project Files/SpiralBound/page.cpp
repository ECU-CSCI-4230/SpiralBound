#include "page.h"
#include "block.h"
#include "util.h"

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-27-2019
Page::Page()
{
    pageName = "default";
    date = QDate::currentDate();
    blocks = new list<Block*>();
}

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-27-2019
Page::Page(QString pg)
{
    pageName = pg;
    date = QDate::currentDate();
    blocks = new list<Block*>();
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

// Author:       Matthew Morgan
// Init date:    02-27-2019
// Last updated: 02-27-2019
void Page::setDate(QDate dt) { date = dt; }

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
Block* Page::getBlock(int index) {
    if (index < 0 || index > (int)blocks->size()-1) { return nullptr; }

    auto it = blocks->begin();
    advance(it, index);
    return *it;
}

// Author:       Matthew Morgan
// Init date:    02-27-2019
// Last updated: 02-27-2019
int Page::numBlocks() {
    return (int)blocks->size();
}

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Page::addBlock(short type) {
    Block* blk = new Block();
    blk->setType(type);
    blocks->push_back(blk);
}

// Author:       Ketu Patel
// Init date:    02-02-2019
// Last Updated: 02-02-2019
void Page::removeBlock(int index) {
    if (index < 0 || index > (int) blocks->size()-1) { return; }

    auto it = blocks->begin();
    advance(it, index);
    blocks->erase(it);
}

// Author:       Matthew Morgan
// Init date:    02-20-2019
// Last Updated: 02-27-2019
char* Page::toString() {
    // numBlks is the number of blocks in the page
    // str is the entirety of the page's content as a string
    int numBlks = this->blocks->size();
    char* str = new char[256+((Block::MAX_LENGTH+5)*numBlks)];
    const char* nm = Util::QtoCString(pageName);
    const char* dt = Util::QtoCString(date.toString());

    sprintf(str, "%s\n%s\n%d\n", nm, dt, numBlks);

    for(int i=0; i<numBlks; i++) {
        char* blk = this->getBlock(i)->toString();
        strcat(str, "\254");
        strcat(str, blk);
        delete blk;
    }

    return str;
}
