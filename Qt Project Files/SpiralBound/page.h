#ifndef PAGE_H
#define PAGE_H
#include "util.h"
#include <iostream>
#include <QString>
#include <QDate>
#include <QTextDocument>
#include <list>

using namespace std;

class Page
{
    public:
        static const char CHAR_BLK = '\254';

        Page();
        Page(QString pg);
        QString getPageName();
        QDate getDate();
        void setPgName(QString nm);
        void setDate(QDate dt);
        void setContent(QTextDocument* qst);
        QTextDocument* getContent();

        /** toString() converts the current page to a string form, where the form
          * of this string is as follows: (where [] is ASCII code \\254)
          * <name>\\n<date>\\n<content>*/
        QString toString();

        // Author:       Matthew Morgan
        // Init date:    02-27-2019
        // Last updated: 03-21-2019
        static Page* fromString(const char* str) {
            int len = (int)strlen(str),
                nm = Util::find(str, '\n', len),
                dt = Util::find(str+nm+1, '\n', len-nm-1);
            QString newName = QString::fromUtf8(str, nm),
                    newDt = QString::fromUtf8(str+nm+1, dt),
                    cont = QString::fromUtf8(str+nm+dt+2, len-nm-dt-2);
            QDate newDate = QDate::fromString(newDt);

            Page* pg = new Page();
            pg->setPgName(*(new QString(newName)));
            pg->setDate(*(new QDate(newDate)));
            pg->setContent(new QTextDocument(cont));

            return pg;
        }

    private:
        QString pageName;
        QTextDocument* content;
        QDate date;
};

#endif // PAGE_H
