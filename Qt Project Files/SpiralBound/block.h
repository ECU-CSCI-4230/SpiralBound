#ifndef BLOCK_H
#define BLOCK_H
#include <qstring.h>

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

        char* toString();

    private:
        QString content;
        short type;
};

#endif // BLOCK_H
