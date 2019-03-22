#ifndef SECTION_H
#define SECTION_H
#include "page.h"
#include "util.h"
#include <QStringRef>
#include <QColor>
#include <QTextDocument>
#include <list>
#include <qdebug.h>

using namespace std;

class Section
{
    public:
        const QString DEF_COLOR = "#FFFFFF";

        Section(QString sc);
        Section() {
            secName = "Default";
            col = *(new QColor(DEF_COLOR));
            doc = new QTextDocument();
        }

        QString getSecName();
        QColor getColor();
        QTextDocument* getDoc();
        void setDoc(QTextDocument* doc);
        void setColor(QColor c);
        void setName(QString nm);

        /** getPage(index) returns the page at the given index in the list
          * of pages for the section. */
        Page* getPage(int index);

        /** addPage(nm) adds a page with the given name to the list of pages. */
        void addPage(QString nm);

        /** removePage(index) removes the specified page in the list of pages. */
        void removePage(int index);

        /** numPages() returns the number of pages in this section. */
        int numPages();

        /** toString() converts this section's information to a string of the form
          * <name>\\n<color>\\n<desc>. The description cannot supercede 200 chars in length. */
        QString toString();

        // Author:       Matthew Morgan
        // Init date:    02-27-2019
        // Last updated: 03-21-2019
        static Section* fromString(const char* str) {
            int len = strlen(str),
                ind = Util::find(str, '\n', len),
                indCon = Util::find(str+ind+1, '\n', len-ind-1);
            QString nm = QString::fromUtf8(str, ind),
                    col = QString::fromUtf8(str+ind+1, indCon),
                    con = QString::fromUtf8(str+ind+indCon+2);

            Section* sec = new Section(*(new QString(nm)));
            sec->setColor(*(new QColor(col)));
            sec->getDoc()->setPlainText(con);
            return sec;
        }

        void loadPage(Page* pg);

    private:
        QString secName;
        QTextDocument* doc;
        QColor col;
        list<Page*>* pages;
};

#endif // SECTION_H
