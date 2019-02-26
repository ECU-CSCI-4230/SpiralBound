#ifndef BOOK_H
#define BOOK_H
#include <section.h>
#include <list>

using namespace std;

class Book
{
    public:
        /** Book(nm, auth) constructs a new book with the given name and
          * author, setting its creation date to the same day as the
          * instance's construction. */
        Book(QString nm, QString auth);

        QString getName();
        QString getAuthor();
        QDate getDate();
        void setAuthor(QString name);
        void setName(QString name);

        /** getSection(index) retrieves a section from the list of sections
          * contained in the notebook. */
        Section* getSection(int index);

        /** numSections() returns the number of sections in the notebook. */
        int numSections();

        /** removeSection(index) removes a section from the notebook's list of
          * sections. */
        void removeSection(int index);

        /** addSection(name, desc) adds a section to the notebook with the given
          * name and description. */
        void addSection(QString name, QString desc);

        char* toString();

    private:
        QString bookName, author;
        QDate date;
        list<Section*>* bookList;
};

#endif // BOOK_H
