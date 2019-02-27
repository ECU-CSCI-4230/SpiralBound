#include <QtTest/QtTest>
#include "book.h"
#include "section.h"
#include "page.h"
#include "block.h"
#include "util.h"
#include <QDate>
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

//        static void testBookSave() {}
//        static void testBookLoad() {}
};
