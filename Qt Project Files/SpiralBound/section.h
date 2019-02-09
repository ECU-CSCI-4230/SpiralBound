#ifndef SECTION_H
#define SECTION_H
#include <QStringRef>
#include <linkedlist.h>
#include <page.h>

class Section
{
public:
    Section(QString sc, QString ds);
    Section * next(){
        return nxt;
    }

     Section(){
         secName = "Default";
         desc = "Default";
        }

    QString getSecName();
    QString getDesc();
    Page* getPage(Page pg);
    void addPage(QString nm);
    void removePage(Page pg);
    void renameSec(QString s);
    void setName(QString nm);
    void setDesc(QString dc);


private:
    QString secName;
    QString desc;
    Section* nxt;
    Page* pge;

};

#endif // SECTION_H
