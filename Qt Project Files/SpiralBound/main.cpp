#include "mainwindow.h"
#include <QApplication>
#include <thewidgetitem.h>
#include <list>
#include <book.h>
#include <qdebug.h>

using namespace std;

int main(int argc, char *argv[])
{
    // Sets fonts, windows, etc. to a consistent size across platforms
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
