#ifndef BLOCK_H
#define BLOCK_H
#include <qstring.h>

class Block
{
public:
    Block();
    Type getType();
    QString getContent();
    void setType(Type p);
    void setContent(QString con);

private:
    QString content;
    // Type

};

#endif // BLOCK_H
