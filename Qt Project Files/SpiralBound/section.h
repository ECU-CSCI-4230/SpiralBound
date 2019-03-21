#ifndef SECTION_H
#define SECTION_H
#include "page.h"
#include "util.h"
#include <QStringRef>
#include <QColor>
#include <QTextDocument>
#include <list>

using namespace std;

class Section
{
    public:
        const QString DEF_COLOR = "#FFFFFF";

        Section(QString sc, QString ds);
        Section() {
            secName = "Default";
            desc = "Default";
            col = *(new QColor(DEF_COLOR));
            doc = new QTextDocument();
        }

        QString getSecName();
        QString getDesc();
        QColor getColor();
        QTextDocument* getDoc();
        void setDoc(QTextDocument* doc);
        void setColor(QColor c);
        void setName(QString nm);
        void setDesc(QString dc);

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
          * <name>\\n<desc>. The description cannot supercede 200 chars in length. */
        char* toString();

        // Author:       Matthew Morgan
        // Init date:    02-27-2019
        // Last updated: 02-27-2019
        static Section* fromString(const char* str) {
            int index = Util::find(str, '\n', strlen(str));
            QString nm = QString::fromUtf8(str, index),
                    ds = QString::fromUtf8(str+index+1);

            Section* sec = new Section(*(new QString(nm)), *(new QString(ds)));
            return sec;
        }

    private:
        QString secName;
        QString desc;
        QTextDocument* doc;
        QColor col;
        list<Page*>* pages;
};

#endif // SECTION_H
