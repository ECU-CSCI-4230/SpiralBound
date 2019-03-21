#include <QtTest/QtTest>
#include "../book.h"
#include "../section.h"
#include "../page.h"
#include "../util.h"
#include <QDate>
#include <QString>
#include <iostream>

using namespace std;

class TestBook: public QObject {
    Q_OBJECT
    private slots:
        // Author:       Matthew Morgan
        // Init date:    02-25-2019
        // Last updated: 02-27-2019
        /** testUtil() tests that utility functions work. */
        static void testUtil() {
            cout << "  Searching string for 'a'" << endl;
            int index = Util::find("Matthew", 'a', 7);
            QCOMPARE(index, 1);

            cout << "  Searching string for 'h' in reverse" << endl;
            index = Util::findr("Matthew", 'h', 7);
            QCOMPARE(index, 4);

            cout << "  Testing Q->C strings" << endl;
            QCOMPARE(Util::QtoCString(QString::fromUtf8("LOL")), "LOL");
        }

        // Author:       Matthew Morgan
        // Init date:    02-25-2019
        // Last updated: 02-27-2019
        /** testBookTF() tests the Book classes toString() and fromString() ops. */
        static void testBookTF() {
            const char* nm = "Sample";
            const char* au = "Matthew Morgan";
            const char* dt = "Tue Jun 18 2019";

            Book* bk = Book::fromString("Sample\nMatthew Morgan\nTue Jun 18 2019");

            cout << "  Testing property equivalence" << endl;
            QCOMPARE(nm, bk->getName().toStdString().c_str());
            QCOMPARE(au, bk->getAuthor().toStdString().c_str());
            QCOMPARE(dt, bk->getDate().toString().toStdString().c_str());

            cout << "  Testing string conversion for book" << endl;
            char* bkStr = bk->toString();
            QCOMPARE(bkStr, "Sample\nMatthew Morgan\nTue Jun 18 2019");
        }

        // Author:       Matthew Morgan
        // Init date:    02-27-2019
        // Last updated: 03-21-2019
        /** testSecTF() tests the toString() and fromString() ops for Sections. */
        static void testSecTF() {
            const char* nm = "CSCI-4230";
			const char* col = "#ff00aa";
            const char* ds = "This is for Software Engineering II";

            Section* sec = Section::fromString("CSCI-4230\n#ff00aa\nThis is for Software Engineering II");

            cout << "  Testing property equivalence" << endl;
            QCOMPARE(nm, sec->getSecName());
            QCOMPARE(ds, sec->getDoc()->toPlainText());
			QCOMPARE(col, sec->getColor().name().toLower().toStdString().c_str());

            cout << "  Testing string conversion for section" << endl;
            QString scStr = sec->toString();
            QCOMPARE(scStr, "CSCI-4230\n#ff00aa\nThis is for Software Engineering II");
        }

        // Author:       Matthew Morgan
        // Init date:    02-27-2019
        // Last updated: 03-21-2019
        static void testPgTF() {
            const char* nm = "02/27/2019";
            const char* dt = "Wed Feb 27 2019";
            const char* full = "02/27/2019\nWed Feb 27 2019\nThis is a page's content\nIt's beautiful";
			QString cont = "This is a page's content\nIt's beautiful";

            cout << "  Block separator is " << Page::CHAR_BLK << endl;
            Page* pg = Page::fromString(full);

            cout << "  Testing property equivalence" << endl;
            QCOMPARE(nm, pg->getPageName().toStdString().c_str());
            QCOMPARE(dt, pg->getDate().toString().toStdString().c_str());

            cout << "  Testing string conversion for page" << endl;
            QCOMPARE(full, pg->toString());
        }

//        static void testBookSave() {}
//        static void testBookLoad() {}
};
