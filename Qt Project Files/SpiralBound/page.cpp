#include "page.h"

Page::Page()
{
    pageName = "default";

}

// Author:
// Init date:
// Last Updated:
Page* next(){

}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
QString Page::getPageName()
{
    return pageName;
}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
QDate Page::getDate()
{
    return date;
}

// Author:
// Init date:
// Last Updated:
Block Page::getBlock()
{

}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Page::setPgName(QString nm)
{
    pageName = nm;
}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Page::renamePg(QString nm)
{
    pageName = nm;
}

// Author:
// Init date:
// Last Updated:
void Page::addBlock()
{

}

// Author:
// Init date:
// Last Updated:
void Page::removeBlock(int i)
{

}

