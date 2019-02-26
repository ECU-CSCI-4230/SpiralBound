#ifndef SECTION_H
#define SECTION_H
#include <QStringRef>
#include <page.h>
#include <list>

using namespace std;

class Section
{
    public:
        Section(QString sc, QString ds);
        Section() {
            secName = "Default";
            desc = "Default";
        }

        QString getSecName();
        QString getDesc();
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

    private:
        QString secName;
        QString desc;
        list<Page*>* pages;
};

#endif // SECTION_H
