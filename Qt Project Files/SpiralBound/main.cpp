#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // Windows Program Icon
    w.setWindowIcon(QIcon("icon.ico"));
    w.show();
    return a.exec();
}
