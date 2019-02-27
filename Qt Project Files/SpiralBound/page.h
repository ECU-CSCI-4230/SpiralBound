#ifndef PAGE_H
#define PAGE_H
#include "block.h"
#include <iostream>
#include <QString>
#include <QDate>
#include <list>

using namespace std;

class Page
{
    public:
        Page();
        Page(QString pg);
        QString getPageName();
        QDate getDate();
        void setPgName(QString nm);

        /** getBlock(index) gets the block at the specified index in the list
          * of blocks for this page. */
        Block* getBlock(int index);

        /** addBlock(type) adds a new block to the list of blocks for this page
          * with the given type. */
        void addBlock(short type);

        /** removeBlock(index) removes the block at the given position in the list
          * of blocks for the page. */
        void removeBlock(int index);

        /** toString() converts the current page to a string form, where the form
          * of this string is as follows:
          * <name>\\n<date>\\n<block-count>\\n
          * [\\n
          * <block 1 content>\\n
          * ]\\n
          * ...
          * [\\n
          * <block n content>\\n
          * ]\\n */
        char* toString();

        static Page* fromString();

    private:
        QString pageName;
        QDate date;
        list<Block*>* blocks;
};

#endif // PAGE_H