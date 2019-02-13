#ifndef BLOCK_H
#define BLOCK_H
#include <qstring.h>

class Block
{
    public:
        const short TYPE_TEXT = 0, TYPE_CODE = 1;

        Block();
        short getType();
        QString getContent();
        void setType(short p);
        void setContent(QString con);

    private:
        QString content;
        short type;
};

#endif // BLOCK_H
