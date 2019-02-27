#ifndef BLOCK_H
#define BLOCK_H
#include "util.h"
#include <QString>
#include <iostream>

using namespace std;

class Block
{
    public:
        /* TYPE_TEXT and TYPE_CODE are the valid types for a block */
        /* MAX_LENGTH is the maximum length of a single block */
        static const short TYPE_TEXT = 0, TYPE_CODE = 1;
        static const int MAX_LENGTH = 256;

        Block();
        short getType();
        QString getContent();
        void setType(short p);
        void setContent(QString con);

        /** toString() converts this block to a string form, where the form is
          * <type>\\n<content>. The length of this string will not supercede
          * MAX_LENGTH characters. */
        char* toString();

        // Author:       Matthew Morgan
        // Init date:    02-27-2019
        // Last updated: 02-27-2019
        static Block* fromString(const char* str) {
            int index = Util::find(str, '\n', strlen(str));
            QString con = QString::fromUtf8(str+index+1, strlen(str)-index),
                    typ = QString::fromUtf8(str, index);

            sscanf(Util::QtoCString(typ), "%d", &index);

            Block* blk = new Block();
            blk->setContent(Util::QtoCString(con));
            blk->setType((short)index);
            return blk;
        }

    private:
        QString content;
        short type;
};

#endif // BLOCK_H
