#include "section.h"

Section::Section(QString nm, QString ds)
{
    secName = nm;
    desc= ds;
    Section* next;
}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
QString Section::getSecName()
{
    return secName;
}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
QString Section::getDesc()
{
    return desc;
}

// Author:
// Init date:
// Last Updated:
Page *Section::getPage(Page pg)
{

}

// Author:
// Init date:
// Last Updated:
void Section::addPage(QString nm)
{

}

// Author:
// Init date:
// Last Updated:
void Section::removePage(Page pg)
{

}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Section::renameSec(QString s)
{
    secName = s;
}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Section::setName(QString nm)
{
    secName = nm;
}

// Author: Ketu Patel
// Init date: 02/02/2019
// Last Updated:
void Section::setDesc(QString dc)
{
    desc = dc;
}




