#ifndef PAGE_H
#define PAGE_H
#include "block.h"
#include "util.h"
#include <iostream>
#include <QString>
#include <QDate>
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
        int numBlocks();

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
          * of this string is as follows: (where [] is ASCII code \\254)
          * <name>\\n<date>\\n<block-count>\\n
          * []<block 1 content>[]<block n content> */
        char* toString();

        // Author:       Matthew Morgan
        // Init date:    02-27-2019
        // Last updated: 02-27-2019
        static Page* fromString(const char* str) {
            int len = strlen(str),
                nm = Util::find(str, '\n', len),
                dt = Util::find(str+nm+1, '\n', len-nm-1),
                blk = Util::find(str+nm+dt+2, '\n', len-nm-dt-2);
            QString newName = QString::fromUtf8(str, nm),
                    newDt = QString::fromUtf8(str+nm+1, dt),
                    newBlk = QString::fromUtf8(str+nm+dt+2, blk);
            QDate newDate = QDate::fromString(newDt);

            // Get starting point for blocks
            int cnt, offset = nm+dt+blk+4;
            sscanf(newBlk.toStdString().c_str(), "%d", &cnt);

            Page* pg = new Page();
            pg->setPgName(*(new QString(newName)));
            pg->setDate(*(new QDate(newDate)));

            // Read in blocks
            for(int i=0; i<cnt; i++) {
                int end = Util::find(str+offset, CHAR_BLK, len);
                QString cBlk = QString::fromUtf8(str+offset, end);
                pg->blocks->push_back(Block::fromString(cBlk.toStdString().c_str()));
                offset += end+1;
            }

            return pg;
        }

    private:
        QString pageName;
        QDate date;
        list<Block*>* blocks;
};

#endif // PAGE_H
