#include "page.h"
#include <QPlainTextDocumentLayout>

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 04-05-2019
Page::Page()
{
    pageName = "default";
    date = QDate::currentDate();
    content = new QTextDocument();
    content->setDocumentLayout(new QPlainTextDocumentLayout(content));
    content->setDefaultFont(QFont("Courier", 10));
}

// Author:       Ketu Patel, Matthew Morgan
// Init date:    02-02-2019
// Last Updated: 04-05-2019
Page::Page(QString pg)
{
    pageName = pg;
    date = QDate::currentDate();
    content = new QTextDocument();
    content->setDocumentLayout(new QPlainTextDocumentLayout(content));
    content->setDefaultFont(QFont("Courier", 10));
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

// Author:       Matthew Morgan
// Init date:    02-20-2019
// Last Updated: 03-21-2019
QString Page::toString() {
    return QString("%1\n%2\n%3").arg(pageName, date.toString(), content->toPlainText());
}

// Author:       Matthew Morgan
// Init date:    03-12-2019
// Last Updated: 03-12-2019
void Page::setContent(QTextDocument* tmp) { content = tmp; }

// Author:       Matthew Morgan
// Init date:    03-12-2019
// Last Updated: 03-12-2019
QTextDocument* Page::getContent() { return content; }
