#ifndef BOOK_H
#define BOOK_H
#include "section.h"
#include "util.h"
#include <QString>
#include <QDate>
#include <list>

using namespace std;

class Book
{
    public:
        /** Book(nm, auth) constructs a new book with the given name and
          * author, setting its creation date to the same day as the
          * instance's construction. */
        Book(QString nm, QString auth);
        Book(const char* nm, const char* auth);

        QString getName();
        QString getAuthor();
        QDate getDate();
        void setAuthor(QString auth);
        void setName(QString name);
        void setDate(QDate dt);

        /** getSection(index) retrieves a section from the list of sections
          * contained in the notebook. */
        Section* getSection(int index);

        /** numSections() returns the number of sections in the notebook. */
        int numSections();

        /** removeSection(index) removes a section from the notebook's list of
          * sections. */
        void removeSection(int index);

        /** addSection(name) adds a section to the notebook with the given name. */
        void addSection(QString name);

        /** toString() converts this book's information to a string of the form
          * <name>\\n<author>\\n<date> */
        char* toString();

        // Author:       Matthew Morgan
        // Init date:    02-25-2019
        // Last updated: 02-27-2019
        static Book* fromString(const char* in) {
            int len = (int)strlen(in),
                nm = Util::find(in, '\n', len),
                au = Util::find(in+nm+1, '\n', len-nm);
            QString qnm = QString::fromUtf8(in, nm),
                    qau = QString::fromUtf8(in+nm+1, au);
            QDate qdt = QDate::fromString(QString::fromUtf8(in+nm+au+2));

            Book* bk = new Book(*(new QString(qnm)), *(new QString(qau)));
            bk->date = *(new QDate(qdt));

            return bk;
        }

        // Author:       Matthew Morgan
        // Init date:    04-05-2019
        // Last updated: 04-05-2019
        /** generateBook(title, user, date) creates a new book with the given name,
          * author, and creation date. */

        static Book* generateBook(QString title, QString user, QString* date = nullptr) {
            Book* bk = new Book(title, user);
            if (date != nullptr)
                bk->setDate(QDate::fromString(*date));
            bk->addSection("Section 01");
            bk->getSection(0)->addPage("Untitled Page");
            return bk;
        }

        void loadSection(Section* sec);
        void loadPage(Section* sec, Page* pg);

    private:
        QString bookName, author;
        QDate date;
        list<Section*>* bookList;
};

#endif // BOOK_H
