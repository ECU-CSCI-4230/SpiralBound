#ifndef PAGE_H
#define PAGE_H
#include <block.h>
#include <iostream>
#include <QString>
#include <QDate>

class Page
{
public:
    Page();
    Page* next();
    QString getPageName();
    QDate getDate();
    Block getBlock();
    void setPgName(QString nm);
    void renamePg(QString nm);
    void addBlock();
    void removeBlock(int i);

private:
    QString pageName;
    QDate date;
    Page *nxt;
    Block *blk;
};

#endif // PAGE_H
