## Purpose of Testing
**Date**: 21 March 2019

The purpose of this unit test is in regards to issue #22, where the notebook data structure has to be updated. What this means is that the Block portion of the data structure must be removed, and instead the usage of QTextDocuments done for each page in the notebook. Furthermore, description data in the Section class has to be removed, and instead the QTextDocument there used. Updates also needed to be done regarding the presence of QColor variable storage for section entry coloring.

## Testing Artifacts
```
********* Start testing of TestBook *********
Config: Using QtTest library 5.12.0, Qt 5.12.0 (x86_64-little_endian-llp64 shared (dynamic) release build; by GCC 7.3.0)
PASS   : TestBook::initTestCase()
  Searching string for 'a'
  Searching string for 'h' in reverse
  Testing Q->C strings
PASS   : TestBook::testUtil()
  Testing property equivalence
  Testing string conversion for book
PASS   : TestBook::testBookTF()
  Testing property equivalence
  Testing string conversion for section
PASS   : TestBook::testSecTF()
  Block separator is ¼
  Testing property equivalence
  Testing string conversion for page
FAIL!  : TestBook::testPgTF() Compared values are not the same
   Actual   (full)          : 02/27/2019
Wed Feb 27 2019
This is a page's content
It's beautiful
   Expected (pg->toString()): "02/27/2019\nWed Feb 27 2019\n\nThis is a page's content\nIt's beautiful"
release\../unit_book.h(89) : failure location
PASS   : TestBook::cleanupTestCase()
Totals: 5 passed, 1 failed, 0 skipped, 0 blacklisted, 8ms
********* Finished testing of TestBook *********
```

```
********* Start testing of TestBook *********
Config: Using QtTest library 5.12.0, Qt 5.12.0 (x86_64-little_endian-llp64 shared (dynamic) release build; by GCC 7.3.0)
PASS   : TestBook::initTestCase()
  Searching string for 'a'
  Searching string for 'h' in reverse
  Testing Q->C strings
PASS   : TestBook::testUtil()
  Testing property equivalence
  Testing string conversion for book
PASS   : TestBook::testBookTF()
  Testing property equivalence
  Testing string conversion for section
PASS   : TestBook::testSecTF()
  Block separator is ¼
  Testing property equivalence
  Testing string conversion for page
FAIL!  : TestBook::testPgTF() Compared values are not the same
   Actual   (full)          : 02/27/2019
Wed Feb 27 2019
This is a page's content
It's beautiful
   Expected (pg->toString()): "02/27/2019\nWed Feb 27 2019\nThis is a page's content\nIt's beautiful\u0000"
release\../unit_book.h(89) : failure location
PASS   : TestBook::cleanupTestCase()
Totals: 5 passed, 1 failed, 0 skipped, 0 blacklisted, 7ms
********* Finished testing of TestBook *********
```

```
********* Start testing of TestBook *********
Config: Using QtTest library 5.12.0, Qt 5.12.0 (x86_64-little_endian-llp64 shared (dynamic) release build; by GCC 7.3.0)
PASS   : TestBook::initTestCase()
  Searching string for 'a'
  Searching string for 'h' in reverse
  Testing Q->C strings
PASS   : TestBook::testUtil()
  Testing property equivalence
  Testing string conversion for book
PASS   : TestBook::testBookTF()
QDEBUG : TestBook::testSecTF() Color  "#ff00aa"

  Testing property equivalence
  Testing string conversion for section
PASS   : TestBook::testSecTF()
  Block separator is ¼
  Testing property equivalence
  Testing string conversion for page
PASS   : TestBook::testPgTF()
PASS   : TestBook::cleanupTestCase()
Totals: 6 passed, 0 failed, 0 skipped, 0 blacklisted, 12ms
********* Finished testing of TestBook *********
```