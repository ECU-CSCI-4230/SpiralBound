#include "page.h"
#include "block.h"

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
Page::Page(QString pg)
{
    pageName = pg;
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
Block* Page::getBlock(int index) {

    if (index < 0 || index > (int)blocks->size()-1) { return nullptr; }

    auto it = blocks->begin();
    advance(it, index);
    return *it;
}

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 02-12-2019
void Page::addBlock(short type) {
    blocks->push_back(new Block());

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
// Last Updated: 02-25-2019
char* Page::toString() {
    // numBlks is the number of blocks in the page
    // str is the entirety of the page's content as a string
    int numBlks = this->blocks->size();
    char* str = new char[(Block::MAX_LENGTH+10) * numBlks];
    const char* nm = this->pageName.toStdString().c_str();
    const char* dt = this->date.toString().toStdString().c_str();

    sprintf(str, "%s\n%s\n%d\n", nm, dt, numBlks);

    for(int i=0; i<numBlks; i++) {
        char* blk = this->getBlock(i)->toString();
        strcat(str, "[\n");
        strcat(str, blk);
        strcat(str, "\n]\n");
        delete blk;
    }

    return str;
}
