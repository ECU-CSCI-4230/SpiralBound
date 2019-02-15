#include "mainwindow.h"
#include <QApplication>
#include <thewidgetitem.h>
#include <list>
#include <book.h>
#include <qdebug.h>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
