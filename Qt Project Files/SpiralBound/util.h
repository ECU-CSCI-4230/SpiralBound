#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include <QTreeWidget>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <iostream>

using namespace std;

class Util {
    public:
        // Author:       Matthew Morgan
        // Init date:    02-23-2019
        // Last updated: 02-25-2019
        /** find(str, c, strlen) searches for a character, c, in the string str, and
          * returns the first index that it encounters the character at. If there is
          * no occurence found, -1 is returned. strlen is the length of the string
          * being searched. */

        static int find(const char* str, char c, int strlen) {
            for(int i=0; i<strlen; i++)
                if (str[i] == c) { return i; }
            return -1;
        }

        // Author:       Matthew Morgan
        // Init date:    02-23-2019
        // Last updated: 02-25-2019
        /** findr(str, c, strlen) searches for a character, c, from the end of the
          * string str, and returns the first index it encounters the character at.
          * If there is no occurence, then -1 is returned. strlen is the length of
          * the string, and in turn the starting position to search from. */

        static int findr(const char* str, char c, int strlen) {
            for(int i=strlen-1; i>0; i--)
                if (str[i] == c) { return i; }
            return -1;
        }

        // Author:       Matthew Morgan
        // Init date:    02-27-2019
        // Last updated: 02-27-2019
        /** QtoCString(qstr) converts the QString qstr into a c-string (null-terminated)
          * and returns a pointer to that string. */

        static char* QtoCString(QString qstr) {
            char* str = new char[qstr.length()+1];
            strcpy(str, qstr.toStdString().c_str());
            return str;
        }


        // Author:       Matthew Morgan
        // Init Date:    03-20-2019
        // Last Updated: 03-20-2019
        /** getSectionPage(tree, item) gets the index of the item in the given tree widget.
          * If the item is a page, then the page's index is also fetched. Index 0 of the
          * returned result is the section index, and 1 is the page index. If either value
          * is a -1, then the index was not found. */

        static int* getSectionPage(QTreeWidget* tree, QTreeWidgetItem* item) {
            int* dat = new int[2];
            bool isSec = (item->childCount() > 0);
            int top = tree->topLevelItemCount();

            dat[0] = -1; dat[1] = -1;

            if (isSec) {
                // Is a section - find the index of the section
                for(int i=0; i<top; i++)
                    if (tree->topLevelItem(i) == item) { dat[0] = i; break; }
            }
            else {
                // Not a section - get the parent (the section TWI), find it's index
                // and fetch the page's index
                QTreeWidgetItem* sec = item->parent();

                for(int i=0; i<top; i++)
                    if (tree->topLevelItem(i) == sec) { dat[0] = i; break; }

                dat[1] = sec->indexOfChild(item);
            }

            return dat;
        }

        // Author:       Matthew Morgan
        // Init Date:    03-21-2019
        // Last Updated: 03-21-2019
        /** showError(title, msg) shows an error prompt with the given title and message
          * to the screen. */
        static void showError(QString title, QString message) {
            QMessageBox msg;
            msg.critical(nullptr, title, message);
            msg.setFixedSize(500, 200);
        }

        // Author:       Matthew Morgan
        // Init Date:    03-22-2019
        // Last Updated: 03-22-2019
        /** showMessage(title, msg) shows a message to the user in an information box. */
        static void showMessage(QString title, QString message) {
            QMessageBox msg;
            msg.information(nullptr, title, message);
            msg.setFixedSize(500, 200);
        }

        // Author:       Matthew Morgan
        // Init Date:    03-22-2019
        // Last Updated: 03-22-2019
        /** confirm(title, msg) shows a confirmation prompt to the user, and returns whether
          * or not they click 'yes'. (True for yes, False for no) */
        static bool confirm(QString title, QString message) {
            return QMessageBox::question(nullptr, title, message) == QMessageBox::Yes;
        }

        // Author:       Matthew Morgan
        // Init Date:    03-22-2019
        // Last Updated: 03-22-2019
        /** copyDirectory(from, into) is a wrapper for the private copyDirectory(from, into),
          * accepting directories as strings and setting up QDir instances for copying files. */
        static void copyDirectory(QString from, QString into) {
            QDir fr = QDir(from), to = QDir(into);
            fr.setFilter(QDir::NoDotAndDotDot|QDir::AllEntries);
            copyDirectory(fr, to);
        }

    private:
        // Author:       Matthew Morgan
        // Init Date:    03-22-2019
        // Last Updated: 03-22-2019
        /** copyDirectory(from, into) copies the files and directories in 'from' to the directory
          * 'into', recursively calling itself on subdirectories. */
        static void copyDirectory(QDir from, QDir into) {
            if (!into.exists()) { into.mkpath(into.path()); }

            for(QString fil : from.entryList()) {
                QString oldName = from.path() + "/" + fil,
                        newName = into.path() + "/" + fil;
                QFile* f = new QFile(oldName);
                QFileInfo info = QFileInfo(oldName);

                if (info.isDir())
                    copyDirectory(oldName, newName);
                else
                    f->copy(newName);

                delete f;
            }
        }
};

// Deck structure
struct Deck {
    QString name;
    QStringList front, back;

    Deck() {
        name = "";
        front = QStringList();
        back = QStringList();
    }
};

// Calendar structure
struct Event {
    QString name, date, time;
    Event() {
        name = "";
        date = "";
        time = "";
    }
};

#endif // UTIL_H
